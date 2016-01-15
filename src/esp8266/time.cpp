// Copyright (c) Arduino. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#include <time.h>
#include <sys/time.h>

extern "C" {
    int _gettimeofday(struct timeval* tp, void* /*tzvp*/)
    {
        //clock_gettime(NULL, tp);
        
        return 0;
    }

    int timeinit()
    {
      //  configTime(0, 0, "0.pool.ntp.org", "1.pool.ntp.org", "2.pool.ntp.org");
       // ensureBootTimeIsSet();
    }
}