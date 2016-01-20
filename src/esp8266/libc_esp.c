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

#include <ctype.h>

#define _CTYPE_DATA_0_127 \
    _C,    _C,    _C,    _C,    _C,    _C,    _C,    _C, \
    _C,    _C|_S, _C|_S, _C|_S,    _C|_S,    _C|_S,    _C,    _C, \
    _C,    _C,    _C,    _C,    _C,    _C,    _C,    _C, \
    _C,    _C,    _C,    _C,    _C,    _C,    _C,    _C, \
    _S|_B,    _P,    _P,    _P,    _P,    _P,    _P,    _P, \
    _P,    _P,    _P,    _P,    _P,    _P,    _P,    _P, \
    _N,    _N,    _N,    _N,    _N,    _N,    _N,    _N, \
    _N,    _N,    _P,    _P,    _P,    _P,    _P,    _P, \
    _P,    _U|_X,    _U|_X,    _U|_X,    _U|_X,    _U|_X,    _U|_X,    _U, \
    _U,    _U,    _U,    _U,    _U,    _U,    _U,    _U, \
    _U,    _U,    _U,    _U,    _U,    _U,    _U,    _U, \
    _U,    _U,    _U,    _P,    _P,    _P,    _P,    _P, \
    _P,    _L|_X,    _L|_X,    _L|_X,    _L|_X,    _L|_X,    _L|_X,    _L, \
    _L,    _L,    _L,    _L,    _L,    _L,    _L,    _L, \
    _L,    _L,    _L,    _L,    _L,    _L,    _L,    _L, \
    _L,    _L,    _L,    _P,    _P,    _P,    _P,    _C

#define _CTYPE_DATA_128_255 \
    0,    0,    0,    0,    0,    0,    0,    0, \
    0,    0,    0,    0,    0,    0,    0,    0, \
    0,    0,    0,    0,    0,    0,    0,    0, \
    0,    0,    0,    0,    0,    0,    0,    0, \
    0,    0,    0,    0,    0,    0,    0,    0, \
    0,    0,    0,    0,    0,    0,    0,    0, \
    0,    0,    0,    0,    0,    0,    0,    0, \
    0,    0,    0,    0,    0,    0,    0,    0, \
    0,    0,    0,    0,    0,    0,    0,    0, \
    0,    0,    0,    0,    0,    0,    0,    0, \
    0,    0,    0,    0,    0,    0,    0,    0, \
    0,    0,    0,    0,    0,    0,    0,    0, \
    0,    0,    0,    0,    0,    0,    0,    0, \
    0,    0,    0,    0,    0,    0,    0,    0, \
    0,    0,    0,    0,    0,    0,    0,    0, \
    0,    0,    0,    0,    0,    0,    0,    0

#if (defined(__GNUC__) && !defined(__CHAR_UNSIGNED__) && !defined(COMPACT_CTYPE)) || defined (__CYGWIN__)
#define ALLOW_NEGATIVE_CTYPE_INDEX
#endif

#if defined(_MB_CAPABLE)
#if defined(_MB_EXTENDED_CHARSETS_ISO)
#include "ctype_iso.h"
#endif
#if defined(_MB_EXTENDED_CHARSETS_WINDOWS)
#include "ctype_cp.h"
#endif
#endif

#if defined(ALLOW_NEGATIVE_CTYPE_INDEX)
/* No static const on Cygwin since it's referenced and potentially overwritten
   for compatibility with older applications. */
#ifndef __CYGWIN__
static _CONST
#endif
char _ctype_b[128 + 256] = {
    _CTYPE_DATA_128_255,
    _CTYPE_DATA_0_127,
    _CTYPE_DATA_128_255
};

#ifndef _MB_CAPABLE
_CONST
#endif
char __EXPORT *__ctype_ptr__ = (char *) _ctype_b + 127;

#  ifdef __CYGWIN__

__asm__ ("                    \n\
        .data                    \n\
    .globl  __ctype_            \n\
    .set    __ctype_,__ctype_b+127        \n\
    .text                                   \n\
");

#  else /* !__CYGWIN__ */

_CONST char _ctype_[1 + 256] = {
    0,
    _CTYPE_DATA_0_127,
    _CTYPE_DATA_128_255
};
#  endif /* !__CYGWIN__ */

#else    /* !defined(ALLOW_NEGATIVE_CTYPE_INDEX) */

_CONST char _ctype_[1 + 256] = {
    0,
    _CTYPE_DATA_0_127,
    _CTYPE_DATA_128_255
};

#ifndef _MB_CAPABLE
_CONST
#endif
char *__ctype_ptr__ = (char *) _ctype_;

#endif

#if defined(_MB_CAPABLE)
/* Cygwin has its own implementation which additionally maintains backward
   compatibility with applications built under older Cygwin releases. */
#ifndef __CYGWIN__
// this function is used by locale.c
extern void __set_ctype (const char *charset);
void
__set_ctype (const char *charset)
{
#if defined(_MB_EXTENDED_CHARSETS_ISO) || defined(_MB_EXTENDED_CHARSETS_WINDOWS)
  int idx;
#endif

  switch (*charset)
    {
#if defined(_MB_EXTENDED_CHARSETS_ISO)
    case 'I':
      idx = __iso_8859_index (charset + 9);
      /* The ctype table has a leading ISO-8859-1 element so we have to add
     1 to the index returned by __iso_8859_index.  If __iso_8859_index
     returns < 0, it's ISO-8859-1. */
      if (idx < 0)
        idx = 0;
      else
        ++idx;
#  if defined(ALLOW_NEGATIVE_CTYPE_INDEX)
      __ctype_ptr__ = (char *) (__ctype_iso[idx] + 127);
#  else
      __ctype_ptr__ = (char *) __ctype_iso[idx];
#  endif
      return;
#endif
#if defined(_MB_EXTENDED_CHARSETS_WINDOWS)
    case 'C':
      idx = __cp_index (charset + 2);
      if (idx < 0)
        break;
#  if defined(ALLOW_NEGATIVE_CTYPE_INDEX)
      __ctype_ptr__ = (char *) (__ctype_cp[idx] + 127);
#  else
      __ctype_ptr__ = (char *) __ctype_cp[idx];
#  endif
      return;
#endif
    default:
      break;
    }
#  if defined(ALLOW_NEGATIVE_CTYPE_INDEX)
  __ctype_ptr__ = (char *) _ctype_b + 127;
#  else
  __ctype_ptr__ = (char *) _ctype_;
#  endif
}
#endif /* !__CYGWIN__ */
#endif /* _MB_CAPABLE */