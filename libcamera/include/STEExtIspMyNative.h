 /*
 * Copyright (C) ST-Ericsson SA 2011. All rights reserved.
 *
 * Class to manage interaction with the  native window
 *
 * This code is ST-Ericsson proprietary and confidential.
 * Any use of the code for whatever purpose is subject to
 * specific written permission of ST-Ericsson SA.
 */

#include "STENativeWindow.h"

namespace android {

#define YUV_CAMERA_PREVIEW_BUFFER_COUNT 2


class NBuffer
{
public:
    NBuffer(buffer_handle_t& aBufHandle,
            MMNativeBuffer* aMMNativeBuffer = NULL,
            camera_memory_t* aClientMemory = NULL)
            : mBufHandle(aBufHandle),
            mMMNativeBuffer(aMMNativeBuffer),
            mClientMemory(aClientMemory) {
    }

    ~NBuffer() {
        DBGT_ASSERT(mMMNativeBuffer == NULL, "mMMNativeBuffer Not Destroyed");
        mMMNativeBuffer = NULL;
        mClientMemory->release(mClientMemory);
        mClientMemory = NULL;
    }

    buffer_handle_t& getBufferHandle() {
        return mBufHandle;
    }
    MMNativeBuffer* getMMNativeBuffer() {
        return mMMNativeBuffer;
    }
    void setMMNativeBuffer(MMNativeBuffer* aMMNativeBuffer) {
        bool condition = (aMMNativeBuffer != NULL) && (NULL != mMMNativeBuffer);
        DBGT_ASSERT(!condition, "Prevoius buffer not destroyed");
        mMMNativeBuffer = aMMNativeBuffer;
    }
    camera_memory_t* getCameraMemory() {
        return mClientMemory;
    }
    void setClientMemory(camera_memory_t* aClientMemory) {
        if(NULL != mClientMemory) {
            mClientMemory->release(mClientMemory);
        }
        mClientMemory = aClientMemory;
    }


private:
    buffer_handle_t& mBufHandle;
    MMNativeBuffer* mMMNativeBuffer;
    camera_memory_t* mClientMemory;

    NBuffer();
    NBuffer(const NBuffer&);
    NBuffer &operator=(const NBuffer &);
};


#undef _CNAME_
#define _CNAME_ MyNativeWindow
class MyNativeWindow
{
public:
    MyNativeWindow(PFMMCreateNativeBuffer aCreate, PFMMDestroyNativeBuffer aDestroy);
    ~MyNativeWindow() {
        deinit();
    }
    int init(
            preview_stream_ops_t *aWindow,
            camera_request_memory aRequestMemoryFunc,
            int width, int height,
            int pixelFormat, int usage);

    preview_stream_ops_t* getNativeWindow() {
        Mutex::Autolock autoLock(mLock);
        if(!mIsInitialized) return NULL;
        return getNativeWindow_l();
    }
    // a return of -1 indicates failure in the following APIs
    int setCrop(int left, int top, int right, int bottom) {
        Mutex::Autolock autoLock(mLock);
        if(!mIsInitialized) return INVALID_OPERATION;

        return mSTENativeWindow->setCrop(left, top, right, bottom);
    }
    int deinit() {
        Mutex::Autolock autoLock(mLock);
        return deinit_l();
    }

    NBuffer* dequeueNBuffer(void) {

        Mutex::Autolock autoLock(mLock);
        if(!mIsInitialized) return NULL;
        // Get one native buffer from display framework.
        buffer_handle_t* buf;
        int err = mSTENativeWindow->dequeueBuffer(
                           &buf, NULL);
        if ((OK != err) || (NULL == buf)) {
            return NULL;
        }
        err = mSTENativeWindow->lockBuffer(*buf);
        if (OK != err ) {
            returnBuffer_l(*buf);
            return NULL;
        }
        return findNBuffer_l(buf);

    }

    int renderNBuffer(NBuffer& aNBuffer) {
        Mutex::Autolock autoLock(mLock);
        if(!mIsInitialized) return INVALID_OPERATION;

        return mSTENativeWindow->enqueueBuffer(aNBuffer.getBufferHandle());
    }
    int returnNBuffer(NBuffer& aNBuffer) {

        Mutex::Autolock autoLock(mLock);
        if(!mIsInitialized) return INVALID_OPERATION;

        return returnNBuffer_l(aNBuffer);
    }

    int getWindowWidth() {
        return mWindowWidth;
    }

    int getWindowHeight() {
        return mWindowHeight;
    }

private:
    Mutex mLock;
    bool mIsInitialized;
    STENativeWindow* mSTENativeWindow;
    int mTotalNumOfNativeBuff;
    NBuffer** mNBuffers;
    PFMMCreateNativeBuffer mCreate;
    PFMMDestroyNativeBuffer mDestroy;
    camera_request_memory mRequestMemoryFunc;
    static const int kPreviewBufferCount = YUV_CAMERA_PREVIEW_BUFFER_COUNT;

    int mWindowWidth;
    int mWindowHeight;
    int mPreviewColorFormat;    //format define in /system/core/include/system/graphics.h

    int fetchNBufferFromNativeWindow_l(void);
    int setupNBuffersForPreview_l(void);
    int lockNBuffer(NBuffer& aNBuffer);

    preview_stream_ops_t* getNativeWindow_l() {
        if (NULL == mSTENativeWindow) return NULL;
        return mSTENativeWindow->getNativeWindow();
    }
    int returnNBuffer_l(NBuffer& aNBuffer) {

        return returnBuffer_l(aNBuffer.getBufferHandle());
    }
    int returnAllNBuffers_l(void) {
        for (int i = (mTotalNumOfNativeBuff-1); i >= 0; i--) {
            returnNBuffer_l(*mNBuffers[i]);
        }
        return OK;
    }
    int returnBuffer_l(buffer_handle_t& aBuffer) {
        return mSTENativeWindow->cancelBuffer(aBuffer);
    }

    int clearAllBufferHandles() {
        for (int i = 0; i < mTotalNumOfNativeBuff; i++) {
            if (mNBuffers[i]->getMMNativeBuffer() != NULL) {
                mDestroy(mNBuffers[i]->getMMNativeBuffer());
                mNBuffers[i]->setMMNativeBuffer(NULL);
            }
        }
        return OK;
    }

    int getPreviewFrameSize(void) {
        int size = 0;   //size without alignment
        switch(mPreviewColorFormat) {
            case HAL_PIXEL_FORMAT_RGB_565:
                size = mWindowWidth * mWindowHeight * 2;
                break;
            case HAL_PIXEL_FORMAT_YCbCr_420_SP:
                size = (mWindowWidth * mWindowHeight * 3) >> 1;
                break;
        }
        return size;
    }

    int deinit_l() {
        if (!mIsInitialized) return OK;
        clearAllBufferHandles();

        if( NULL != mNBuffers) {
            for (int i = 0; i < mTotalNumOfNativeBuff; i++) {
                if (mNBuffers[i]) {
                    delete mNBuffers[i];
                }
            }
            delete []mNBuffers;
            mNBuffers = NULL;
        }
        if (NULL != mSTENativeWindow) {
            delete mSTENativeWindow;
            mSTENativeWindow = NULL;
        }
        mTotalNumOfNativeBuff = 0;
        mIsInitialized = false;
        mWindowWidth = -1;
        mWindowHeight = -1;
        return OK;
    }

    NBuffer* findNBuffer_l(buffer_handle_t* aBuffer) {
        for (int i = 0; i < mTotalNumOfNativeBuff; i++) {
            if (&(mNBuffers[i]->getBufferHandle()) == aBuffer) {
                return mNBuffers[i];
            }
        }
        return NULL;
    }

    MyNativeWindow();
    MyNativeWindow(const MyNativeWindow&);
    MyNativeWindow &operator=(const MyNativeWindow &);

};

}; // namespace android
