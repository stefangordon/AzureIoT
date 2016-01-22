// Copyright (c) Arduino. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#if defined(ARDUINO_ARCH_ESP8266)
#include "esp8266/libc_esp.h"
#endif

#include "sdk/lock.h"
#include "sdk/threadapi.h"
#include "sdk/serializer.h"

#include "sdk/iothub_client_ll.h"
#include "sdk/iothub_message.h"
#include "sdk/iothubtransporthttp.h"

#include "sdk/iot_logging.h"

