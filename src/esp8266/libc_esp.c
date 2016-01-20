#if defined(ARDUINO_ARCH_ESP8266)

#include <stddef.h>
#include <stdarg.h>
#include <stdio.h>

#include "ets_sys.h"
#include "os_type.h"
#include "osapi.h"
#include "mem.h"

int fprintf(FILE* file, const char* format, ...) {
    // if(file != stderr || file != stdout) {
    //     return -1;
    // }
    int ret;
    va_list arglist;
    va_start(arglist, format);
    ret = ets_vprintf(format, arglist);
    va_end(arglist);
    return ret;
}

int sscanf(const char* source, const char* format, ...) {
    int ret = -1;
    return ret;
}

double difftime(time_t end, time_t beginning) {
    return -1;
}

#endif

