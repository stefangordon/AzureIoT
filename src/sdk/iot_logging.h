// Copyright (c) Microsoft. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#ifndef LOGGING_H
#define LOGGING_H

// Arduino requires external definitions for LogUsage, LogInfo, and LogError
// due to platform differences in output implementations
#ifdef ARDUINO

#include "arduino_logging.h"

#else /* !ARDUINO */

#include <stdio.h>
#include "agenttime.h"

#define STRINGIFY(a) (#a)

#define LogUsage (void)printf


#define LogInfo(...) (void)printf("Info: " __VA_ARGS__)

#if defined _MSC_VER
#define LogError(FORMAT, ...) { time_t t = time(NULL); (void)fprintf(stderr,"Error: Time:%.24s File:%s Func:%s Line:%d " FORMAT, ctime(&t), __FILE__, __FUNCDNAME__, __LINE__, __VA_ARGS__); }
#else
#define LogError(FORMAT, ...) { time_t t = time(NULL); (void)fprintf(stderr,"Error: Time:%.24s File:%s Func:%s Line:%d " FORMAT, ctime(&t), __FILE__, __func__, __LINE__, ##__VA_ARGS__); }
#endif

#endif /* !ARDUINO */
#endif /* LOGGING_H */
