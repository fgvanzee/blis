/*

   BLIS   
   An object-based framework for developing high-performance BLAS-like
   libraries.

   Copyright (C) 2014, The University of Texas at Austin

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are
   met:
    - Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    - Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
    - Neither the name of The University of Texas at Austin nor the names
      of its contributors may be used to endorse or promote products
      derived derived from this software without specific prior written permission.

   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
   "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
   A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
   HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
   SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
   LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
   DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
   THEORY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
   (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
   OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

*/

#include "blis.h"
#include <immintrin.h> 

typedef union
{
	__m256d v;
	double  d[4];
} v4df_t;

typedef union
{
	__m256 v;
	float  f[8];
} v8ff_t;

void bli_sdotxv_opt_var1(
			  conj_t           conjx,
			  conj_t           conjy,
			  dim_t            n,
			  float* restrict alpha,
			  float* restrict x, inc_t incx,
			  float* restrict y, inc_t incy,
			  float* restrict beta,
			  float* restrict rho
			)
{
	float*  restrict alpha_cast = alpha;
	float*  restrict x_cast   = x;
	float*  restrict y_cast   = y;
	float*  restrict beta_cast = beta;
	float*  restrict rho_cast = rho;

	float*  restrict x1;
	float*  restrict y1;
	gint_t            i;
	float             rho1;
	float             dotxy;
	v8ff_t            rho0v, rho1v, rho2v, rho3v;
	v8ff_t            x0v, x1v, x2v, x3v;
	v8ff_t            y0v, y1v, y2v, y3v;
	gint_t            n_run, n_pre, n_left;

	const dim_t       n_elem_per_reg = 8;
	const dim_t       n_iter_unroll  = 4;

	bool_t            use_ref = FALSE;

	// If there is anything that would interfere with our use of aligned
	// vector loads/stores, call the reference implementation.
	if ( incx != 1 || incy != 1 )
	{
		use_ref = TRUE;
	}

	n_pre = 0;
	if ( bli_is_unaligned_to( x, 32 ) ||
	     bli_is_unaligned_to( y, 32 ) )
	{
		guint_t x_offset = bli_offset_from_alignment( x, 32 );
		guint_t y_offset = bli_offset_from_alignment( y, 32 );

		if ( x_offset % 4 != 0 ||
		     x_offset != y_offset )
		{
			use_ref = TRUE;
		}
		else
		{
			n_pre = ( 32 - x_offset ) / 4;
		}
	}

	// Call the reference implementation if needed.
	if ( use_ref == TRUE )
	{
		BLIS_SDOTXV_KERNEL_REF( conjx,
		                        conjy,
		                        n,
		                        alpha,
		                        x, incx,
		                        y, incy,
		                        beta,
		                        rho );
		return;
	}

	if ( PASTEMAC(d,eq0)( *beta_cast ) ) {
		PASTEMAC(d,set0s)( rho1 );
	} else {
		rho1 = *rho_cast * *beta_cast;
	}

	// If the vector lengths are zero, set rho and return.
	if ( bli_zero_dim1( n ) )
	{
		PASTEMAC(d,copys)( rho1, *rho_cast );
		return;
	}

	x1 = x_cast;
	y1 = y_cast;

	n_run       = ( n - n_pre ) / ( n_elem_per_reg * n_iter_unroll );
	n_left      = ( n - n_pre ) % ( n_elem_per_reg * n_iter_unroll );

	PASTEMAC(s,set0s)( dotxy );

	while ( n_pre-- > 0 )
	{
		dotxy += *(x1++) * *(y1++);
	}

	rho0v.v = _mm256_setzero_ps();
	rho1v.v = _mm256_setzero_ps();
	rho2v.v = _mm256_setzero_ps();
	rho3v.v = _mm256_setzero_ps();
	x0v.v = _mm256_setzero_ps();
	x1v.v = _mm256_setzero_ps();
	x2v.v = _mm256_setzero_ps();
	x3v.v = _mm256_setzero_ps();
	y0v.v = _mm256_setzero_ps();
	y1v.v = _mm256_setzero_ps();
	y2v.v = _mm256_setzero_ps();
	y3v.v = _mm256_setzero_ps();

	for ( i = 0; i < n_run; i++ )
	{
		x0v.v = _mm256_load_ps( ( float* )(x1 + 0*n_elem_per_reg) );
		x1v.v = _mm256_load_ps( ( float* )(x1 + 1*n_elem_per_reg) );
		x2v.v = _mm256_load_ps( ( float* )(x1 + 2*n_elem_per_reg) );
		x3v.v = _mm256_load_ps( ( float* )(x1 + 3*n_elem_per_reg) );

		y0v.v = _mm256_load_ps( ( float* )(y1 + 0*n_elem_per_reg) );
		y1v.v = _mm256_load_ps( ( float* )(y1 + 1*n_elem_per_reg) );
		y2v.v = _mm256_load_ps( ( float* )(y1 + 2*n_elem_per_reg) );
		y3v.v = _mm256_load_ps( ( float* )(y1 + 3*n_elem_per_reg) );

		rho0v.v += x0v.v * y0v.v;
		rho1v.v += x1v.v * y1v.v;
		rho2v.v += x2v.v * y2v.v;
		rho3v.v += x3v.v * y3v.v;

		x1 += n_iter_unroll * n_elem_per_reg;
		y1 += n_iter_unroll * n_elem_per_reg;
	}

	rho0v.v += rho2v.v;
	rho1v.v += rho3v.v;
	rho0v.v += rho1v.v;

	dotxy += rho0v.f[0] + rho0v.f[1] + rho0v.f[2] + rho0v.f[3] + \
	         rho0v.f[4] + rho0v.f[5] + rho0v.f[6] + rho0v.f[7];

	while ( n_left-- > 0 )
	{
		dotxy += *(x1++) * *(y1++);
	}
	rho1 += *alpha_cast * dotxy;

	PASTEMAC(s,copys)( rho1, *rho_cast );
}


void bli_ddotxv_opt_var1(
			  conj_t           conjx,
			  conj_t           conjy,
			  dim_t            n,
			  double* restrict alpha,
			  double* restrict x, inc_t incx,
			  double* restrict y, inc_t incy,
			  double* restrict beta,
			  double* restrict rho
			)
{
	double*  restrict alpha_cast = alpha;
	double*  restrict x_cast   = x;
	double*  restrict y_cast   = y;
	double*  restrict beta_cast = beta;
	double*  restrict rho_cast = rho;

	double*  restrict x1;
	double*  restrict y1;
	gint_t            i;
	double            rho1;
	double            dotxy;
	v4df_t            rho0v, rho1v, rho2v, rho3v;
	v4df_t            x0v, x1v, x2v, x3v;
	v4df_t            y0v, y1v, y2v, y3v;
	gint_t            n_run, n_pre, n_left;

	const dim_t       n_elem_per_reg = 4;
	const dim_t       n_iter_unroll  = 4;

	bool_t            use_ref = FALSE;

	// If there is anything that would interfere with our use of aligned
	// vector loads/stores, call the reference implementation.
	if ( incx != 1 || incy != 1 )
	{
		use_ref = TRUE;
	}

	n_pre = 0;
	if ( bli_is_unaligned_to( x, 32 ) ||
	     bli_is_unaligned_to( y, 32 ) )
	{
		guint_t x_offset = bli_offset_from_alignment( x, 32 );
		guint_t y_offset = bli_offset_from_alignment( y, 32 );

		if ( x_offset % 8 != 0 ||
		     x_offset != y_offset )
		{
			use_ref = TRUE;
		}
		else
		{
			n_pre = ( 32 - x_offset ) / 8;
		}
	}


	// Call the reference implementation if needed.
	if ( use_ref == TRUE )
	{
		BLIS_DDOTXV_KERNEL_REF( conjx,
		                        conjy,
		                        n,
		                        alpha,
		                        x, incx,
		                        y, incy,
		                        beta,
		                        rho );
		return;
	}

	if ( PASTEMAC(d,eq0)( *beta_cast ) ) {
		PASTEMAC(d,set0s)( rho1 );
	} else {
		rho1 = *rho_cast * *beta_cast;
	}

	// If the vector lengths are zero, set rho and return.
	if ( bli_zero_dim1( n ) )
	{
		PASTEMAC(d,copys)( rho1, *rho_cast );
		return;
	}

	x1 = x_cast;
	y1 = y_cast;

	n_run       = ( n - n_pre ) / ( n_elem_per_reg * n_iter_unroll );
	n_left      = ( n - n_pre ) % ( n_elem_per_reg * n_iter_unroll );

	PASTEMAC(d,set0s)( dotxy );

	while ( n_pre-- > 0 )
	{
		dotxy += *(x1++) * *(y1++);
	}

	rho0v.v = _mm256_setzero_pd();
	rho1v.v = _mm256_setzero_pd();
	rho2v.v = _mm256_setzero_pd();
	rho3v.v = _mm256_setzero_pd();
	x0v.v = _mm256_setzero_pd();
	x1v.v = _mm256_setzero_pd();
	x2v.v = _mm256_setzero_pd();
	x3v.v = _mm256_setzero_pd();
	y0v.v = _mm256_setzero_pd();
	y1v.v = _mm256_setzero_pd();
	y2v.v = _mm256_setzero_pd();
	y3v.v = _mm256_setzero_pd();

	for ( i = 0; i < n_run; i++ )
	{
		x0v.v = _mm256_load_pd( ( double* )(x1 + 0*n_elem_per_reg) );
		x1v.v = _mm256_load_pd( ( double* )(x1 + 1*n_elem_per_reg) );
		x2v.v = _mm256_load_pd( ( double* )(x1 + 2*n_elem_per_reg) );
		x3v.v = _mm256_load_pd( ( double* )(x1 + 3*n_elem_per_reg) );

		y0v.v = _mm256_load_pd( ( double* )(y1 + 0*n_elem_per_reg) );
		y1v.v = _mm256_load_pd( ( double* )(y1 + 1*n_elem_per_reg) );
		y2v.v = _mm256_load_pd( ( double* )(y1 + 2*n_elem_per_reg) );
		y3v.v = _mm256_load_pd( ( double* )(y1 + 3*n_elem_per_reg) );

		rho0v.v += x0v.v * y0v.v;
		rho1v.v += x1v.v * y1v.v;
		rho2v.v += x2v.v * y2v.v;
		rho3v.v += x3v.v * y3v.v;

		x1 += n_iter_unroll * n_elem_per_reg;
		y1 += n_iter_unroll * n_elem_per_reg;
	}

	rho0v.v += rho2v.v;
	rho1v.v += rho3v.v;
	rho0v.v += rho1v.v;

	dotxy += rho0v.d[0] + rho0v.d[1] + rho0v.d[2] + rho0v.d[3];

	while ( n_left-- > 0 )
	{
		dotxy += *(x1++) * *(y1++);
	}
	rho1 += *alpha_cast * dotxy;

	PASTEMAC(d,copys)( rho1, *rho_cast );
}
