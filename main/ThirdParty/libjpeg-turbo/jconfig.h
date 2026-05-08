/* Version ID for the JPEG library.
 * Might be useful for tests like "#if JPEG_LIB_VERSION >= 60".
 */


#include <stdlib.h>
#include <stdio.h>

#ifndef EINVAL
#define EINVAL -1
#endif




#ifndef FILE
  #define FILE int
#endif

/* remove unused stdio functions */
#ifndef fread
#define fread( a, b, c, d ) 0
#endif
#ifndef fwrite
#define fwrite( a, b, c, d ) 0
#endif
#ifndef fprintf
#define fprintf( a, b, c )
#endif
#ifndef fflush
#define fflush( a )
#endif
#ifndef ferror
#define ferror( a )
#endif
#ifndef exit
#define exit( a )
#endif


#define NO_PUTENV
#define NO_GETENV


#define JPEG_LIB_VERSION  62

/* libjpeg-turbo version */
#define LIBJPEG_TURBO_VERSION  2.1.3

/* libjpeg-turbo version in integer form */
#define LIBJPEG_TURBO_VERSION_NUMBER  2001003

/* Support arithmetic encoding */
#define C_ARITH_CODING_SUPPORTED 0

/* Support arithmetic decoding */
#define D_ARITH_CODING_SUPPORTED 1

/* Support in-memory source/destination managers */
#define MEM_SRCDST_SUPPORTED 1

/* Use accelerated SIMD routines. */
#define WITH_SIMD 1

/*
 * Define BITS_IN_JSAMPLE as either
 *   8   for 8-bit sample values (the usual setting)
 *   12  for 12-bit sample values
 * Only 8 and 12 are legal data precisions for lossy JPEG according to the
 * JPEG standard, and the IJG code does not support anything else!
 * We do not support run-time selection of data precision, sorry.
 */

#define BITS_IN_JSAMPLE  8      /* use 8 or 12 */

/* Define if your (broken) compiler shifts signed values as if they were
   unsigned. */
/* #undef RIGHT_SHIFT_IS_UNSIGNED */
