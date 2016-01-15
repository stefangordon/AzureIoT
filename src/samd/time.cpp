// Copyright (c) Arduino. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for full license information.
#if defined(ARDUINO_ARCH_SAMD)
#include <time.h>
#include <sys/time.h>
#include "samd/util/NTPClient.h"
#include <RTCZero.h>

RTCZero rtc;

extern "C" {
    int _gettimeofday(struct timeval* tp, void* /*tzvp*/)
    {
        tp->tv_sec = rtc.getEpoch();
        tp->tv_usec = 0;

        return 0;
    }

    int timeInit()
    {
        configTime(0, 0, "0.pool.ntp.org", "1.pool.ntp.org", "2.pool.ntp.org")
        time_t epochTime = (time_t)-1;
        NTPClient ntpClient;

        ntpClient.begin();
        while (true) {
            epochTime = ntpClient.getEpochTime("0.pool.ntp.org");

            if (epochTime == (time_t)-1) {
                LogError("Fetching NTP epoch time failed!\n");
                delay(5000);
            } else {
                LogInfo("Fetched NTP epoch time is: %lu\n", epochTime);
                break;
            }
        }
        ntpClient.end();


        struct timeval tv;
        tv.tv_sec = epochTime;
        tv.tv_usec = 0;

        rtc.begin();
        rtc.setEpoch(tp->tv_sec);

        return 0;
    }
}
#endif