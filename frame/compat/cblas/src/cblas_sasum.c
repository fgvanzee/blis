#include "bli_config.h"
#include "bli_config_macro_defs.h"
#include "bli_system.h"
#include "bli_type_defs.h"
#include "bli_cblas.h"
#ifdef BLIS_ENABLE_CBLAS
/*
 * cblas_sasum.c
 *
 * The program is a C interface to sasum.
 * It calls the fortran wrapper before calling sasum.
 *
 * Written by Keita Teranishi.  2/11/1998
 *
 */
#include "cblas.h"
#include "cblas_f77.h"
float cblas_sasum( const int N, const float *X, const int incX) 
{
   float asum;
#ifdef F77_INT
   F77_INT F77_N=N, F77_incX=incX;
#else 
   #define F77_N N
   #define F77_incX incX
#endif
   F77_sasum_sub( &F77_N, X, &F77_incX, &asum);
   return asum;
}
#endif
