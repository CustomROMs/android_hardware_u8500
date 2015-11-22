/*
 * Copyright (C) ST-Ericsson SA 2010. All rights reserved.
 * This code is ST-Ericsson proprietary and confidential.
 * Any use of the code for whatever purpose is subject to
 * specific written permission of ST-Ericsson SA.
 */

#ifndef _STECAMPERFTIMER_H_
#define _STECAMPERFTIMER_H_

/*
 * Includes
 */
#include <utils/Timers.h>
#include <stdint.h>
#include <sys/types.h>
#include <sys/time.h>

namespace android {
 /*
  * Time the duration of something.
  *
  * Includes some timeval manipulation functions.
  */
 class DurationTimer {
 public:
     DurationTimer() {}
     ~DurationTimer() {}
 
     // Start the timer.
     void start();
     // Stop the timer.
     void stop();
     // Get the duration in microseconds.
     long long durationUsecs() const;
 
     // Subtract two timevals.  Returns the difference (ptv1-ptv2) in
     // microseconds.
     static long long subtractTimevals(const struct timeval* ptv1,
         const struct timeval* ptv2);
 
     // Add the specified amount of time to the timeval.
     static void addToTimeval(struct timeval* ptv, long usec);
 
 private:
     struct timeval  mStartWhen;
     struct timeval  mStopWhen;
 }; 

class MPerfTimer
    {
     public:
         /* Performance time */
         typedef int64_t Time;

         /* String lenght for time */
         enum
         {
             ETimePrintWidth = 10,
             ETimeStrLen = ETimePrintWidth + 5 /**< For [us]\0 */
         };

    public:
        /* DTOR */
        virtual ~MPerfTimer() {};

        /* Init */
        virtual void init() = 0;

        /* Elapsed time in microseconds */
        virtual Time elapsedTime() = 0;

        /* Get tsring for Time */
        static inline void getStr(const Time& aTime, char* aStr);
    };

/**< DuratiomTimer based perf timer */
class DurationTimerPerfTimer : public MPerfTimer
    {
    public:
        /* Init, from MPerfTimer */
        virtual void init();

        /* Elapsed time, from MPerfTimer */
        virtual Time elapsedTime();

    private:
        DurationTimer mTimer; /**< Duration Timer */
        Time mTotalTimeFromInit; /**< Total time from init */
    };

/**< systemTime based perf timer */
class SystemTimePerfTimer : public MPerfTimer
    {
    public:
        /* Init, from MPerfTimer */
        virtual void init();

        /* Elapsed time, from MPerfTimer */
        virtual Time elapsedTime();

    private:
        nsecs_t mInitTime; /**< Init Time */
    };

#include "STECamPerfTimer.inl"

} //namespace android

#endif //_STECAMPERFTIMER_H_

// end of file STECamPerfTimer.h
