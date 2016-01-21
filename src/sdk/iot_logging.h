// Copyright (c) Microsoft. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#ifndef LOGGING_H
#define LOGGING_H
#include <stdio.h>
#include "agenttime.h"
#include <pgmspace.h>

#define STRINGIFY(a) (#a)

#define LogUsage (void)printf


#define LogInfo(...) (void)printf("Info: " __VA_ARGS__)

#define LogError(FORMAT) (void)printf(PSTR(FORMAT))
#define LogError(FORMAT, ...) //(void)printf(PSTR(FORMAT), __VA_ARGS__)

#endif /* LOGGING_H */
