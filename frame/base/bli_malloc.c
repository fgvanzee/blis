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
      derived from this software without specific prior written permission.

   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
   "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
   A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
   HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
   SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
   LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
   DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
   THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
   (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
   OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

*/

#include "blis.h"

// -----------------------------------------------------------------------------

void* bli_malloc_pool( size_t size )
{
	const malloc_ft malloc_fp  = BLIS_MALLOC_POOL;
	const size_t    align_size = BLIS_POOL_ADDR_ALIGN_SIZE;

	return bli_malloc_align( malloc_fp, size, align_size );
}

void bli_free_pool( void* p )
{
	bli_free_align( BLIS_FREE_POOL, p );
}

// -----------------------------------------------------------------------------

void* bli_malloc_user( size_t size )
{
	const malloc_ft malloc_fp  = BLIS_MALLOC_USER;
	const size_t    align_size = BLIS_HEAP_ADDR_ALIGN_SIZE;

	return bli_malloc_align( malloc_fp, size, align_size );
}

void bli_free_user( void* p )
{
	bli_free_align( BLIS_FREE_USER, p );
}

// -----------------------------------------------------------------------------

void* bli_malloc_intl( size_t size )
{
	const malloc_ft malloc_fp = BLIS_MALLOC_INTL;

	return bli_malloc_noalign( malloc_fp, size );
}

void* bli_calloc_intl( size_t size )
{
	void* p = bli_malloc_intl( size );

	memset( p, 0, size );

	return p;
}

void bli_free_intl( void* p )
{
	bli_free_noalign( BLIS_FREE_INTL, p );
}

// -----------------------------------------------------------------------------

void* bli_malloc_align
     (
       malloc_ft f,
       size_t    size,
       size_t    align_size
     )
{
	const size_t ptr_size     = sizeof( void* );
	size_t       align_offset = 0;
	void*        p_orig;
	int8_t*      p_byte;
	void**       p_addr;

	// Check parameters.
	if ( bli_error_checking_is_enabled() )
		bli_malloc_align_check( f, size, align_size );

	// Return early if zero bytes were requested.
	if ( size == 0 ) return NULL;

	// Add the alignment size and the size of a pointer to the number
	// of bytes to allocate.
	size += align_size + ptr_size;

	// Call the allocation function.
	p_orig = f( size );

	// If NULL was returned, something is probably very wrong.
	if ( p_orig == NULL ) bli_abort();

	// Advance the pointer by one pointer element.
	p_byte = p_orig;
	p_byte += ptr_size;

	// Compute the offset to the desired alignment.
	if ( bli_is_unaligned_to( ( siz_t )p_byte, ( siz_t )align_size ) )
	{
		align_offset = align_size -
		               bli_offset_past_alignment( ( siz_t )p_byte,
		                                          ( siz_t )align_size );
	}

	// Advance the pointer using the difference between the alignment
	// size and the alignment offset.
	p_byte += align_offset;

	// Compute the address of the pointer element just before the start
	// of the aligned address, and store the original address there.
	p_addr = ( void** )(p_byte - ptr_size);
	*p_addr = p_orig;

	// Return the aligned pointer.
	return p_byte;
}

void bli_free_align
     (
       free_ft f,
       void*   p
     )
{
	const size_t ptr_size = sizeof( void* );
	void*        p_orig;
	int8_t*      p_byte;
	void**       p_addr;

	// If the pointer to free is NULL, it was obviously not aligned and
	// does not need to be freed.
	if ( p == NULL ) return;

	// Since the bli_malloc_pool() function returned the aligned pointer,
	// we have to first recover the original pointer before we can free
	// the memory.

	// Start by casting the pointer to a byte pointer.
	p_byte = p;

	// Compute the address of the pointer element just before the start
	// of the aligned address, and recover the original address.
	p_addr = ( void** )( p_byte - ptr_size );
	p_orig = *p_addr;

	// Free the original pointer.
	f( p_orig );
}

// -----------------------------------------------------------------------------

void* bli_malloc_noalign
     (
       malloc_ft f,
       size_t    size
     )
{
	return f( size );
}

void bli_free_noalign
     (
       free_ft f,
       void*   p
     )
{
	f( p );
}

// -----------------------------------------------------------------------------

void bli_malloc_align_check 
     (
       malloc_ft f,
       size_t    size,
       size_t    align_size
     )
{
	err_t e_val;

	// Check for valid alignment.

	e_val = bli_check_alignment_is_power_of_two( align_size );
	bli_check_error_code( e_val );

	e_val = bli_check_alignment_is_mult_of_ptr_size( align_size );
	bli_check_error_code( e_val );
}


