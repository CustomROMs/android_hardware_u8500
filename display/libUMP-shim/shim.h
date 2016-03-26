/*
 * Copyright (C) 2016 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef SHIM_H
#define SHIM_H

#define REAL_LIB_NAME                           "/system/lib/libUMP-old.so"

#define LOAD_SYMBOL(shim_symbol, real_symbol)				 \
	shim_symbol = dlsym(realLibHandle, real_symbol);		 \
	if (!shim_symbol) { 						 \
                RLOGE("Failed to find the real %s\n", real_symbol);	 \
                goto out_fail;						 \
        }

#define  WRAP_FUNCTION(type, name, args_declare, args_return, real_function)  \
	type name args_declare { 					      \
		return real_function args_return;			      \
	}

#define  WRAP_VOID_FUNCTION(name, args_declare, args_return, real_function)   \
	void name args_declare { 					      \
		real_function args_return;				      \
	}

#endif
