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
    - Neither the name(s) of the copyright holder(s) nor the names of its
      contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.

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
#include "bli_pwr9_asm_macros_18x4.h"


void bli_dgemm_power9_asm_18x4
     (
       dim_t               k0,
       double*    restrict alpha,
       double*    restrict a,
       double*    restrict b,
       double*    restrict beta,
       double*    restrict c, inc_t rs_c0, inc_t cs_c0,
       auxinfo_t* restrict data,
       cntx_t*    restrict cntx
     )
{
	//void*   a_next = bli_auxinfo_next_a( data );
	//void*   b_next = bli_auxinfo_next_b( data );

	// Typecast local copies of integers in case dim_t and inc_t are a
	// different size than is expected by load instructions.

	uint64_t k_iter = k0 / 2;
	uint64_t k_left = k0 % 2;
  uint64_t rs_c   = rs_c0;
	uint64_t cs_c   = cs_c0;


	__asm__ volatile
	(
	  "                                               \n\t"
  	"                                               \n\t"
    "                                               \n\t"
    "                                               \n\t"
    "ld               %%r9, %7                      \n\t" // load rs_c
  	"ld               %%r10, %8                     \n\t" // load cs_c
    "                                               \n\t"
  	"ld               %%r17, %0                     \n\t" // load k_iter
  	"ld               %%r18, %1                     \n\t" // load k_left
  	"                                               \n\t"
  	"                                               \n\t"
  	"slwi             %%r10, %%r10, 3               \n\t" // mul by size of elem
  	"slwi             %%r9, %%r9, 3                 \n\t" // mul by size of elem
  	"                                               \n\t"
  	"                                               \n\t"
  	"ld               %%r8, %3                      \n\t" // load ptr of B
  	"ld               %%r7, %2                      \n\t" // load ptr of A
  	"ld               %%r16, %6                     \n\t" // load ptr for C
  	"                                               \n\t"
  	"                                               \n\t"
  	"                                               \n\t"
    DPRELOAD_A_B
  	"                                               \n\t"
    "addi             %%r8, %%r8, 32                \n\t" 
    "addi             %%r7, %%r7, 144               \n\t"
  	"                                               \n\t"
    ZERO_OUT_VREG                                                 // Zero out vec regs
  	"                                               \n\t"
  	"                                               \n\t"
  	"                                               \n\t"
  	"                                               \n\t"
    "                                               \n\t"
  	"                                               \n\t"
    "cmpwi            %%r0, %%r17, 0                \n\t"
  	"beq              %%r0, DPRELOOPKLEFT_1         \n\t"
  	"mtctr            %%r17                         \n\t"
  	"                                               \n\t"
  	"                                               \n\t" 
  	"                                               \n\t"
  	"                                               \n\t"
    "                                               \n\t"
  	"                                               \n\t"
  	"DLOOPKITER_16:                                 \n\t" // Begin k_iter loop
    "                                               \n\t"
    "                                               \n\t"
    "                                               \n\t"
    DLOAD_UPDATE_16
  	"                                               \n\t"
    "                                               \n\t"
    "                                               \n\t"
  	"bdnz             DLOOPKITER_16                 \n\t"
    "                                               \n\t"
  	"                                               \n\t"
    "                                               \n\t"
  	"                                               \n\t"
    "                                               \n\t"
  	"                                               \n\t"
    "                                               \n\t"
  	"                                               \n\t"
    "                                               \n\t"
  	"                                               \n\t"
    "                                               \n\t"
  	"                                               \n\t"
    "                                               \n\t"
  	"                                               \n\t"
    "                                               \n\t"
  	"                                               \n\t"
    "DPRELOOPKLEFT_1:                               \n\t"
  	"                                               \n\t"
  	"cmpwi            %%r0, %%r18, 0                \n\t"
  	"beq              %%r0, DPOSTACCUM              \n\t"
  	"mtctr            %%r18                         \n\t"
  	"                                               \n\t"
  	"DLOOPKLEFT_1:                                  \n\t" // EDGE LOOP
    "                                               \n\t"
    DLOAD_UPDATE_1
    "                                               \n\t"
  	"bdnz             DLOOPKLEFT_1                  \n\t"
  	"                                               \n\t"
    "                                               \n\t"
  	"                                               \n\t"
    "                                               \n\t"
  	"                                               \n\t"
  	"                                               \n\t"
    "                                               \n\t"
  	"                                               \n\t"
  	"                                               \n\t"
    "                                               \n\t"
  	"                                               \n\t"
    "                                               \n\t"
  	"                                               \n\t"
  	"                                               \n\t"
    "                                               \n\t"
  	"                                               \n\t"
  	"                                               \n\t"
  	"                                               \n\t"
    "                                               \n\t"
  	"                                               \n\t"
  	"                                               \n\t"
  	"                                               \n\t"
  	"DPOSTACCUM:                                    \n\t"
  	"                                               \n\t"
  	"ld               %%r0, %4                      \n\t" // load ptr for alpha
  	"ld               %%r28, %5                     \n\t" // load ptr for beta
    "ld               %%r26, 0(%%r28)               \n\t" // load val of beta
  	"                                               \n\t"
  	"lxvdsx           %%vs60, 0, %%r0               \n\t" // splat alpha
  	"lxvdsx           %%vs59, 0, %%r28              \n\t" // splat beta
    "                                               \n\t"
    "                                               \n\t"
    "add              %%r17, %%r16, %%r10           \n\t" // c + cs_c
  	"add              %%r18, %%r17, %%r10           \n\t" // c + cs_c * 2 
  	"add              %%r19, %%r18, %%r10           \n\t" // c + cs_c * 3
    "                                               \n\t"
    "                                               \n\t"
    DSCALE_ALPHA
  	"                                               \n\t"
  	"                                               \n\t"
  	"                                               \n\t"
  	"cmpdi            %%r0, %%r26, 0                \n\t"
  	"beq              %%r0, DBETAZERO               \n\t" // jump to BZ case if beta = 0
  	"                                               \n\t"
  	"                                               \n\t"
    "                                               \n\t"
    "                                               \n\t"
  	"cmpwi            %%r0, %%r9, 8                 \n\t"
  	"beq              %%r0, DCOLSTOREDBNZ           \n\t" // jump to COLstore case, if rs_c = 8
  	"                                               \n\t"
  	"                                               \n\t"
    "                                               \n\t"
  	"                                               \n\t"
    "                                               \n\t"
  	"                                               \n\t"
    "                                               \n\t"
  	"                                               \n\t"
  	"                                               \n\t"
  	"                                               \n\t"
    "                                               \n\t"
  	"                                               \n\t"
    "                                               \n\t"
  	"                                               \n\t"
    "                                               \n\t"
  	"                                               \n\t"
  	"                                               \n\t"
  	"                                               \n\t"
    "                                               \n\t"
  	"                                               \n\t"
    "                                               \n\t"
  	"                                               \n\t"
    "                                               \n\t"
  	"                                               \n\t"
  	"                                               \n\t"
  	"                                               \n\t"
    "                                               \n\t"
  	"                                               \n\t"
    "                                               \n\t"
  	"                                               \n\t"
    "                                               \n\t"
  	"                                               \n\t"
  	"                                               \n\t"
  	"                                               \n\t"
  	"DGENSTOREDBNZ:                                 \n\t"
    "                                               \n\t"
    #if 0
  	"                                               \n\t"
    "                                               \n\t"
  	"                                               \n\t"
    "                                               \n\t"
  	"                                               \n\t"
    "ld               %%r22, %6                     \n\t" // load ptr for C (used as offset)
  	"                                               \n\t" // create offset regs
  	"slwi            %%r12, %%r9, 1                 \n\t"
  	"add             %%r23, %%r22, %%r12            \n\t" // c + rs_c * 2
  	"add             %%r24, %%r23, %%r12            \n\t" // c + rs_c * 4
  	"add             %%r25, %%r24, %%r12            \n\t" // c + rs_c * 6 
  	"add             %%r26, %%r25, %%r12            \n\t" // c + rs_c * 8
  	"add             %%r27, %%r26, %%r12            \n\t" // c + rs_c * 10
    "add             %%r28, %%r27, %%r12            \n\t" // c + rs_c * 12
    "add             %%r29, %%r28, %%r12            \n\t" // c + rs_c * 14
  	"                                               \n\t"
    DGEN_LOAD_SCALE                                  // (1) load, scale, increment offsets
  	"                                              	\n\t"
    "xxpermdi     %%vs40, %%vs8, %%vs0, 1           \n\t" // permute
    "xxpermdi     %%vs41, %%vs9, %%vs1, 1           \n\t"
    "xxpermdi     %%vs42, %%vs10, %%vs2, 1          \n\t"
    "xxpermdi     %%vs43, %%vs11, %%vs3, 1          \n\t"
    "xxpermdi     %%vs44, %%vs12, %%vs4, 1          \n\t"
    "xxpermdi     %%vs45, %%vs13, %%vs5, 1          \n\t"
    "xxpermdi     %%vs46, %%vs14, %%vs6, 1          \n\t"
    "xxpermdi     %%vs47, %%vs15, %%vs7, 1          \n\t"
    "                                              	\n\t" 
	  DGEN_ADD_STORE                                          // add and store
    DGEN_NEXT_COL_C 
  	"                                               \n\t"
  	"                                               \n\t"
    DGEN_LOAD_SCALE                                  // (2) load, scale, increment offsets
  	"                                               \n\t"
    "                                               \n\t"
  	"xxpermdi     %%vs40, %%vs0, %%vs8, 1           \n\t" // permute
    "xxpermdi     %%vs41, %%vs1, %%vs9, 1           \n\t"
    "xxpermdi     %%vs42, %%vs2, %%vs10, 1          \n\t"
    "xxpermdi     %%vs43, %%vs3, %%vs11, 1          \n\t"
    "xxpermdi     %%vs44, %%vs4, %%vs12, 1          \n\t"
    "xxpermdi     %%vs45, %%vs5, %%vs13, 1          \n\t"
    "xxpermdi     %%vs46, %%vs6, %%vs14, 1          \n\t"
    "xxpermdi     %%vs47, %%vs7, %%vs15, 1          \n\t"
    "                                              	\n\t" 
	  DGEN_ADD_STORE                                          // add and store
  	DGEN_NEXT_COL_C
    "                                               \n\t"
  	"                                               \n\t"
    DGEN_LOAD_SCALE                                  // (3) load, scale, increment offsets
  	"                                               \n\t"
  	"xxpermdi     %%vs40, %%vs24, %%vs16, 1         \n\t" // permute
    "xxpermdi     %%vs41, %%vs25, %%vs17, 1         \n\t"
    "xxpermdi     %%vs42, %%vs26, %%vs18, 1         \n\t"
    "xxpermdi     %%vs43, %%vs27, %%vs19, 1         \n\t"
    "xxpermdi     %%vs44, %%vs28, %%vs20, 1         \n\t"
    "xxpermdi     %%vs45, %%vs29, %%vs21, 1         \n\t"
    "xxpermdi     %%vs46, %%vs30, %%vs22, 1         \n\t"
    "xxpermdi     %%vs47, %%vs31, %%vs23, 1         \n\t"
    "                                              	\n\t" 
	  DGEN_ADD_STORE                                          // add and store
  	DGEN_NEXT_COL_C
    "                                               \n\t"
  	"                                          	    \n\t"
    DGEN_LOAD_SCALE                                  // (4) load, scale, increment offsets
  	"                                               \n\t"
    "xxpermdi     %%vs40, %%vs16, %%vs24, 1         \n\t" // permute
    "xxpermdi     %%vs41, %%vs17, %%vs25, 1         \n\t"
    "xxpermdi     %%vs42, %%vs18, %%vs26, 1         \n\t"
    "xxpermdi     %%vs43, %%vs19, %%vs27, 1         \n\t"
    "xxpermdi     %%vs44, %%vs20, %%vs28, 1         \n\t"
    "xxpermdi     %%vs45, %%vs21, %%vs29, 1         \n\t"
    "xxpermdi     %%vs46, %%vs22, %%vs30, 1         \n\t"
    "xxpermdi     %%vs47, %%vs23, %%vs31, 1         \n\t" 
    "                                              	\n\t"
	  DGEN_ADD_STORE                                          // add and store
  	"                                              	\n\t"
  	"                                              	\n\t"
    "                                               \n\t"
  	"                                               \n\t"
    "                                               \n\t"
  	"                                               \n\t"
    #endif
  	"b                DDONE                       	\n\t"
  	"                                              	\n\t"
    "                                               \n\t"
  	"                                               \n\t"
    "                                               \n\t"
  	"                                               \n\t"
    "                                               \n\t"
  	"                                               \n\t"
    "                                               \n\t"
  	"                                               \n\t"
    "                                               \n\t"
  	"                                               \n\t"
    "                                               \n\t"
  	"                                               \n\t"
  	"                                               \n\t"
  	"                                               \n\t"
    "                                               \n\t"
  	"                                               \n\t"
    "                                               \n\t"
  	"                                               \n\t"
  	"                                              	\n\t"
    "                                               \n\t"
  	"                                               \n\t"
    "                                               \n\t"
  	"                                               \n\t"
    "                                               \n\t"
  	"                                               \n\t"
    "                                               \n\t"
  	"                                               \n\t"
    "                                               \n\t"
  	"                                               \n\t"
    "                                               \n\t"
  	"                                               \n\t"
  	"DCOLSTOREDBNZ:                                	\n\t"
    "                                               \n\t"
  	"                                              	\n\t"
    "                                               \n\t"
  	"DADDTOC:                                      	\n\t" // L.S.P.A.S.
  	"                                              	\n\t"
    "            	                                  \n\t"
    "                                               \n\t"
    "                                               \n\t"
    "                                               \n\t"
    "            	                                  \n\t"
    "lxv              %%vs36, 0(%%r16)              \n\t" // load (1)
    "lxv              %%vs37, 16(%%r16)             \n\t" 
    "lxv              %%vs38, 32(%%r16)             \n\t" 
    "lxv              %%vs39, 48(%%r16)             \n\t" 
    "lxv              %%vs40, 64(%%r16)             \n\t" 
    "lxv              %%vs41, 80(%%r16)             \n\t" 
    "lxv              %%vs42, 96(%%r16)             \n\t" 
    "lxv              %%vs43, 112(%%r16)            \n\t"
    "lxv              %%vs44, 128(%%r16)            \n\t"
    "                                               \n\t" 
    "                                               \n\t"
    DCOL_SCALE_BETA                                       // scale (1)
  	"            	                                  \n\t"
    "                                               \n\t"
    "xxpermdi         %%vs48, %%vs9,  %%vs0, 1   	  \n\t" // permute (1)
    "xxpermdi         %%vs49, %%vs10, %%vs1, 1   	  \n\t"
    "xxpermdi         %%vs50, %%vs11, %%vs2, 1   	  \n\t"
    "xxpermdi         %%vs51, %%vs12, %%vs3, 1   	  \n\t"
    "xxpermdi         %%vs52, %%vs13, %%vs4, 1   	  \n\t"
    "xxpermdi         %%vs53, %%vs14, %%vs5, 1   	  \n\t"
    "xxpermdi         %%vs54, %%vs15, %%vs6, 1   	  \n\t"
    "xxpermdi         %%vs55, %%vs16, %%vs7, 1   	  \n\t"
    "xxpermdi         %%vs56, %%vs17, %%vs8, 1   	  \n\t"
    "            	                                  \n\t"
    DCOL_ADD_TO_C
    "            	                                  \n\t"
    "stxv              %%vs48, 0(%%r16)             \n\t" // store (1)
    "stxv              %%vs49, 16(%%r16)            \n\t" 
    "stxv              %%vs50, 32(%%r16)            \n\t" 
    "stxv              %%vs51, 48(%%r16)            \n\t" 
    "stxv              %%vs52, 64(%%r16)            \n\t" 
    "stxv              %%vs53, 80(%%r16)            \n\t" 
    "stxv              %%vs54, 96(%%r16)            \n\t" 
    "stxv              %%vs55, 112(%%r16)           \n\t"
    "stxv              %%vs56, 128(%%r16)           \n\t"
    "                                               \n\t"
    "            	                                  \n\t"
    "                                               \n\t"
    "                                               \n\t"
    "                                               \n\t"
    "                                               \n\t"
    "                                               \n\t"
    "lxv              %%vs36, 0(%%r17)              \n\t" // load (2)
    "lxv              %%vs37, 16(%%r17)             \n\t" 
    "lxv              %%vs38, 32(%%r17)             \n\t" 
    "lxv              %%vs39, 48(%%r17)             \n\t" 
    "lxv              %%vs40, 64(%%r17)             \n\t" 
    "lxv              %%vs41, 80(%%r17)             \n\t" 
    "lxv              %%vs42, 96(%%r17)             \n\t" 
    "lxv              %%vs43, 112(%%r17)            \n\t"
    "lxv              %%vs44, 128(%%r17)            \n\t"
    "                                               \n\t" 
    "                                               \n\t"
    DCOL_SCALE_BETA                                       // scale (2)
  	"            	                                  \n\t"
    "                                               \n\t"
    "xxpermdi         %%vs48, %%vs0, %%vs9,  1   	  \n\t" // permute (2)
    "xxpermdi         %%vs49, %%vs1, %%vs10, 1   	  \n\t"
    "xxpermdi         %%vs50, %%vs2, %%vs11, 1   	  \n\t"
    "xxpermdi         %%vs51, %%vs3, %%vs12, 1   	  \n\t"
    "xxpermdi         %%vs52, %%vs4, %%vs13, 1   	  \n\t"
    "xxpermdi         %%vs53, %%vs5, %%vs14, 1   	  \n\t"
    "xxpermdi         %%vs54, %%vs6, %%vs15, 1   	  \n\t"
    "xxpermdi         %%vs55, %%vs7, %%vs16, 1   	  \n\t"
    "xxpermdi         %%vs56, %%vs8, %%vs17, 1   	  \n\t"
    "            	                                  \n\t"
    DCOL_ADD_TO_C
    "            	                                  \n\t"
    "stxv              %%vs48, 0(%%r17)             \n\t" // store (2)
    "stxv              %%vs49, 16(%%r17)            \n\t" 
    "stxv              %%vs50, 32(%%r17)            \n\t" 
    "stxv              %%vs51, 48(%%r17)            \n\t" 
    "stxv              %%vs52, 64(%%r17)            \n\t" 
    "stxv              %%vs53, 80(%%r17)            \n\t" 
    "stxv              %%vs54, 96(%%r17)            \n\t" 
    "stxv              %%vs55, 112(%%r17)           \n\t"
    "stxv              %%vs56, 128(%%r17)           \n\t"
    "                                               \n\t"
  	"                                               \n\t"
    "                                               \n\t"
    "                                               \n\t"
    "                                               \n\t"
    "                                               \n\t"
    "                                               \n\t"
  	"                                               \n\t"
    "lxv              %%vs36, 0(%%r18)              \n\t" // load (3)
    "lxv              %%vs37, 16(%%r18)             \n\t" 
    "lxv              %%vs38, 32(%%r18)             \n\t" 
    "lxv              %%vs39, 48(%%r18)             \n\t" 
    "lxv              %%vs40, 64(%%r18)             \n\t" 
    "lxv              %%vs41, 80(%%r18)             \n\t" 
    "lxv              %%vs42, 96(%%r18)             \n\t" 
    "lxv              %%vs43, 112(%%r18)            \n\t"
    "lxv              %%vs44, 128(%%r18)            \n\t"
    "                                               \n\t" 
    "                                               \n\t"
    DCOL_SCALE_BETA                                       // scale (3)
  	"            	                                  \n\t"
    "                                               \n\t"
    "xxpermdi         %%vs48, %%vs27, %%vs18, 1   	\n\t" // permute (3)
    "xxpermdi         %%vs49, %%vs28, %%vs19, 1   	\n\t"
    "xxpermdi         %%vs50, %%vs29, %%vs20, 1   	\n\t"
    "xxpermdi         %%vs51, %%vs30, %%vs21, 1   	\n\t"
    "xxpermdi         %%vs52, %%vs31, %%vs22, 1   	\n\t"
    "xxpermdi         %%vs53, %%vs32, %%vs23, 1   	\n\t"
    "xxpermdi         %%vs54, %%vs33, %%vs24, 1   	\n\t"
    "xxpermdi         %%vs55, %%vs34, %%vs25, 1   	\n\t"
    "xxpermdi         %%vs56, %%vs35, %%vs26, 1   	\n\t"
    "            	                                  \n\t"
    DCOL_ADD_TO_C
    "            	                                  \n\t"
    "stxv              %%vs48, 0(%%r18)             \n\t" // store (3)
    "stxv              %%vs49, 16(%%r18)            \n\t" 
    "stxv              %%vs50, 32(%%r18)            \n\t" 
    "stxv              %%vs51, 48(%%r18)            \n\t" 
    "stxv              %%vs52, 64(%%r18)            \n\t" 
    "stxv              %%vs53, 80(%%r18)            \n\t" 
    "stxv              %%vs54, 96(%%r18)            \n\t" 
    "stxv              %%vs55, 112(%%r18)           \n\t"
    "stxv              %%vs56, 128(%%r18)           \n\t"
  	"                                               \n\t"
    "                                               \n\t"
    "                                               \n\t"
    "                                               \n\t"
    "                                               \n\t"
    "                                               \n\t"
    "                                               \n\t"
  	"                                               \n\t"
    "lxv              %%vs36, 0(%%r19)              \n\t" // load (4)
    "lxv              %%vs37, 16(%%r19)             \n\t" 
    "lxv              %%vs38, 32(%%r19)             \n\t" 
    "lxv              %%vs39, 48(%%r19)             \n\t" 
    "lxv              %%vs40, 64(%%r19)             \n\t" 
    "lxv              %%vs41, 80(%%r19)             \n\t" 
    "lxv              %%vs42, 96(%%r19)             \n\t" 
    "lxv              %%vs43, 112(%%r19)            \n\t"
    "lxv              %%vs44, 128(%%r19)            \n\t"
    "                                               \n\t" 
    "                                               \n\t"
    DCOL_SCALE_BETA                                       // scale (4)
  	"            	                                  \n\t"
    "                                               \n\t"
    "xxpermdi         %%vs48, %%vs18, %%vs27, 1   	\n\t" // permute (4)
    "xxpermdi         %%vs49, %%vs19, %%vs28, 1   	\n\t"
    "xxpermdi         %%vs50, %%vs20, %%vs29, 1   	\n\t"
    "xxpermdi         %%vs51, %%vs21, %%vs30, 1   	\n\t"
    "xxpermdi         %%vs52, %%vs22, %%vs31, 1   	\n\t"
    "xxpermdi         %%vs53, %%vs23, %%vs32, 1   	\n\t"
    "xxpermdi         %%vs54, %%vs24, %%vs33, 1   	\n\t"
    "xxpermdi         %%vs55, %%vs25, %%vs34, 1   	\n\t"
    "xxpermdi         %%vs56, %%vs26, %%vs35, 1   	\n\t"
    "            	                                  \n\t"
    DCOL_ADD_TO_C
    "            	                                  \n\t"
    "stxv              %%vs48, 0(%%r19)             \n\t" // store (4)
    "stxv              %%vs49, 16(%%r19)            \n\t" 
    "stxv              %%vs50, 32(%%r19)            \n\t" 
    "stxv              %%vs51, 48(%%r19)            \n\t" 
    "stxv              %%vs52, 64(%%r19)            \n\t" 
    "stxv              %%vs53, 80(%%r19)            \n\t" 
    "stxv              %%vs54, 96(%%r19)            \n\t" 
    "stxv              %%vs55, 112(%%r19)           \n\t"
    "stxv              %%vs56, 128(%%r19)           \n\t"
    "                                               \n\t"
    "                                               \n\t"
    "                                               \n\t"
    "                                               \n\t"
    "                                               \n\t"
    "                                               \n\t"
    "                                               \n\t"
  	"b                DDONE                         \n\t"
  	"                                               \n\t"
    "                                               \n\t"
  	"                                               \n\t"
    "                                               \n\t"
  	"                                               \n\t"
    "                                               \n\t"
  	"                                               \n\t"
    "                                               \n\t"
  	"                                               \n\t"
    "                                               \n\t"
  	"                                               \n\t"
    "                                               \n\t"
  	"                                               \n\t"
    "                                               \n\t"
  	"                                               \n\t"
    "                                               \n\t"
  	"                                               \n\t"
    "                                               \n\t"
    "                                               \n\t"
  	"                                               \n\t"
    "                                               \n\t"
  	"                                               \n\t"
    "                                               \n\t"
  	"                                               \n\t"
  	"                                               \n\t"
  	"                                               \n\t"
  	"                                               \n\t"
    "                                               \n\t"
  	"                                               \n\t"
    "                                               \n\t"
  	"                                               \n\t"
    "                                               \n\t"
  	"                                               \n\t"
  	"                                               \n\t"
  	"                                               \n\t"
  	"                                               \n\t"
  	"                                               \n\t"
  	"DBETAZERO:                                     \n\t" // beta=0 case
  	"                                               \n\t"
    "                                               \n\t"
    "                                               \n\t"
    "                                               \n\t"
    "                                               \n\t" 
    "                                               \n\t"
    "                                               \n\t"
    "                                               \n\t"
  	"cmpwi            %%r0, %%r9, 8                 \n\t" // if rs_c == 8,
  	"beq              DCOLSTORED                    \n\t" // C is col stored
  	"                                               \n\t"
    "                                               \n\t"
  	"                                               \n\t"
    "                                               \n\t"
  	"                                               \n\t"
    "                                               \n\t"
  	"                                               \n\t"
  	"                                               \n\t"
  	"                                               \n\t"
    "                                               \n\t"
  	"                                               \n\t"
    "                                               \n\t"
  	"                                               \n\t"
    "                                               \n\t"
  	"                                               \n\t"
  	"                                               \n\t"
  	"                                               \n\t"
    "                                               \n\t"
  	"                                               \n\t"
    "                                               \n\t"
  	"                                               \n\t"
    "                                               \n\t"
  	"                                               \n\t"
  	"                                               \n\t"
  	"                                               \n\t"
  	"DGENSTORED:                                    \n\t"
    #if 0
  	"                                               \n\t"
    "ld              %%r22, %6                      \n\t" // load c
  	"slwi            %%r12, %%r9, 1                 \n\t"
  	"add             %%r23, %%r22, %%r12            \n\t" // c + rs_c * 2
  	"add             %%r24, %%r23, %%r12            \n\t" // c + rs_c * 4
  	"add             %%r25, %%r24, %%r12            \n\t" // c + rs_c * 6 
  	"add             %%r26, %%r25, %%r12            \n\t" // c + rs_c * 8
  	"add             %%r27, %%r26, %%r12            \n\t" // c + rs_c * 10
    "add             %%r28, %%r27, %%r12            \n\t" // c + rs_c * 12
    "add             %%r29, %%r28, %%r12            \n\t" // c + rs_c * 14
  	"                                               \n\t"
  	"                                               \n\t"
    "stxsdx          %%vs32, %%r9, %%r22            \n\t"   
    "stxsdx          %%vs33, %%r9, %%r23            \n\t"  
    "stxsdx          %%vs34, %%r9, %%r24            \n\t"   
    "stxsdx          %%vs35, %%r9, %%r25            \n\t"   
    "stxsdx          %%vs36, %%r9, %%r26            \n\t"   
    "stxsdx          %%vs37, %%r9, %%r27            \n\t"   
    "stxsdx          %%vs38, %%r9, %%r28            \n\t"   
    "stxsdx          %%vs39, %%r9, %%r29            \n\t"
    "xxswapd         %%vs32, %%vs32		              \n\t"
    "xxswapd         %%vs33, %%vs33		              \n\t"
    "xxswapd         %%vs34, %%vs34		              \n\t"
    "xxswapd         %%vs35, %%vs35		              \n\t"
    "xxswapd         %%vs36, %%vs36		              \n\t"
    "xxswapd         %%vs37, %%vs37		              \n\t"
    "xxswapd         %%vs38, %%vs38		              \n\t" 
    "xxswapd         %%vs39, %%vs39		              \n\t"
    "stxsdx          %%vs32, 0, %%r22               \n\t"
    "stxsdx          %%vs33, 0, %%r23               \n\t"
    "stxsdx          %%vs34, 0, %%r24               \n\t"
    "stxsdx          %%vs35, 0, %%r25               \n\t"
    "stxsdx          %%vs36, 0, %%r26               \n\t"
    "stxsdx          %%vs37, 0, %%r27               \n\t"
    "stxsdx          %%vs38, 0, %%r28               \n\t" 
    "stxsdx          %%vs39, 0, %%r29               \n\t" 
    "                                               \n\t"
    DGEN_NEXT_COL_C 
    "                                               \n\t"
    "stxsdx          %%vs40, %%r9, %%r22            \n\t"  
    "stxsdx          %%vs41, %%r9, %%r23            \n\t"  
    "stxsdx          %%vs42, %%r9, %%r24            \n\t"   
    "stxsdx          %%vs43, %%r9, %%r25            \n\t"   
    "stxsdx          %%vs44, %%r9, %%r26            \n\t"   
    "stxsdx          %%vs45, %%r9, %%r27            \n\t"   
    "stxsdx          %%vs46, %%r9, %%r28            \n\t"   
    "stxsdx          %%vs47, %%r9, %%r29            \n\t"
    "xxswapd         %%vs40, %%vs40		              \n\t"
    "xxswapd         %%vs41, %%vs41		              \n\t"
    "xxswapd         %%vs42, %%vs42		              \n\t"
    "xxswapd         %%vs43, %%vs43		              \n\t"
    "xxswapd         %%vs44, %%vs44		              \n\t"
    "xxswapd         %%vs45, %%vs45		              \n\t"
    "xxswapd         %%vs46, %%vs46		              \n\t" 
    "xxswapd         %%vs47, %%vs47		              \n\t"
    "stxsdx          %%vs40, 0, %%r22               \n\t"
    "stxsdx          %%vs41, 0, %%r23               \n\t"
    "stxsdx          %%vs42, 0, %%r24               \n\t"
    "stxsdx          %%vs43, 0, %%r25               \n\t"
    "stxsdx          %%vs44, 0, %%r26               \n\t"
    "stxsdx          %%vs45, 0, %%r27               \n\t"
    "stxsdx          %%vs46, 0, %%r28               \n\t" 
    "stxsdx          %%vs47, 0, %%r29               \n\t" 
    "                                               \n\t"
    DGEN_NEXT_COL_C 
    "                                               \n\t"
    "stxsdx          %%vs48, %%r9, %%r22            \n\t"   
    "stxsdx          %%vs49, %%r9, %%r23            \n\t"   
    "stxsdx          %%vs50, %%r9, %%r24            \n\t"   
    "stxsdx          %%vs51, %%r9, %%r25            \n\t"   
    "stxsdx          %%vs52, %%r9, %%r26            \n\t"   
    "stxsdx          %%vs53, %%r9, %%r27            \n\t"   
    "stxsdx          %%vs54, %%r9, %%r28            \n\t"   
    "stxsdx          %%vs55, %%r9, %%r29            \n\t"
    "xxswapd         %%vs48, %%vs48		              \n\t"
    "xxswapd         %%vs49, %%vs49		              \n\t"
    "xxswapd         %%vs50, %%vs50		              \n\t"
    "xxswapd         %%vs51, %%vs51		              \n\t"
    "xxswapd         %%vs52, %%vs52		              \n\t"
    "xxswapd         %%vs53, %%vs53		              \n\t"
    "xxswapd         %%vs54, %%vs54		              \n\t" 
    "xxswapd         %%vs55, %%vs55		              \n\t"
    "stxsdx          %%vs48, 0, %%r22               \n\t"
    "stxsdx          %%vs49, 0, %%r23               \n\t"
    "stxsdx          %%vs50, 0, %%r24               \n\t"
    "stxsdx          %%vs51, 0, %%r25               \n\t"
    "stxsdx          %%vs52, 0, %%r26               \n\t"
    "stxsdx          %%vs53, 0, %%r27               \n\t"
    "stxsdx          %%vs54, 0, %%r28               \n\t" 
    "stxsdx          %%vs55, 0, %%r29               \n\t" 
    "                                               \n\t"
    DGEN_NEXT_COL_C 
    "                                               \n\t"
    "stxsdx          %%vs56, %%r9, %%r22            \n\t"   
    "stxsdx          %%vs57, %%r9, %%r23            \n\t"   
    "stxsdx          %%vs58, %%r9, %%r24            \n\t" 
    "stxsdx          %%vs59, %%r9, %%r25            \n\t"   
    "stxsdx          %%vs60, %%r9, %%r26            \n\t"   
    "stxsdx          %%vs61, %%r9, %%r27            \n\t"  
    "stxsdx          %%vs62, %%r9, %%r28            \n\t"   
    "stxsdx          %%vs63, %%r9, %%r29            \n\t"
    "xxswapd         %%vs56, %%vs56		              \n\t"
    "xxswapd         %%vs57, %%vs57		              \n\t" 
    "xxswapd         %%vs58, %%vs58		              \n\t"
    "xxswapd         %%vs59, %%vs59		              \n\t"
    "xxswapd         %%vs60, %%vs60		              \n\t"
    "xxswapd         %%vs61, %%vs61		              \n\t"
    "xxswapd         %%vs62, %%vs62		              \n\t"
    "xxswapd         %%vs63, %%vs63		              \n\t"
    "stxsdx          %%vs56, 0, %%r22               \n\t"
    "stxsdx          %%vs57, 0, %%r23               \n\t"
    "stxsdx          %%vs58, 0, %%r24               \n\t" 
    "stxsdx          %%vs59, 0, %%r25               \n\t"
    "stxsdx          %%vs60, 0, %%r26               \n\t"
    "stxsdx          %%vs61, 0, %%r27               \n\t"
    "stxsdx          %%vs62, 0, %%r28               \n\t" 
    "stxsdx          %%vs63, 0, %%r29               \n\t" 
  	"                                               \n\t"
    #endif
  	"b               DDONE                          \n\t"
  	"                                               \n\t"
    "                                               \n\t"
  	"                                               \n\t"
    "                                               \n\t"
  	"                                               \n\t"
    "                                               \n\t"
  	"                                               \n\t"
    "                                               \n\t"
  	"                                               \n\t"
    "                                               \n\t"
  	"                                               \n\t"
    "                                               \n\t"
  	"                                               \n\t"
    "                                               \n\t"
  	"                                               \n\t"
    "                                               \n\t"
  	"                                               \n\t"
    "                                               \n\t"
  	"                                               \n\t"
    "                                               \n\t"
  	"                                               \n\t"
    "                                               \n\t"
  	"                                               \n\t"
    "                                               \n\t"
  	"                                               \n\t"
    "                                               \n\t"
  	"                                               \n\t"
    "                                               \n\t"
  	"                                               \n\t"
  	"DCOLSTORED:                                    \n\t"
  	"                                               \n\t"
  	"                                               \n\t"
    "                                               \n\t"
    "            	                                  \n\t"
    "                                               \n\t"
    "xxpermdi         %%vs48, %%vs9,  %%vs0, 1   	  \n\t" // permute (1)
    "xxpermdi         %%vs49, %%vs10, %%vs1, 1   	  \n\t"
    "xxpermdi         %%vs50, %%vs11, %%vs2, 1   	  \n\t"
    "xxpermdi         %%vs51, %%vs12, %%vs3, 1   	  \n\t"
    "xxpermdi         %%vs52, %%vs13, %%vs4, 1   	  \n\t"
    "xxpermdi         %%vs53, %%vs14, %%vs5, 1   	  \n\t"
    "xxpermdi         %%vs54, %%vs15, %%vs6, 1   	  \n\t"
    "xxpermdi         %%vs55, %%vs16, %%vs7, 1   	  \n\t"
    "xxpermdi         %%vs56, %%vs17, %%vs8, 1   	  \n\t"
    "            	                                  \n\t"
    "            	                                  \n\t"
    "stxv              %%vs48, 0(%%r16)             \n\t" // store (1)
    "stxv              %%vs49, 16(%%r16)            \n\t" 
    "stxv              %%vs50, 32(%%r16)            \n\t" 
    "stxv              %%vs51, 48(%%r16)            \n\t" 
    "stxv              %%vs52, 64(%%r16)            \n\t" 
    "stxv              %%vs53, 80(%%r16)            \n\t" 
    "stxv              %%vs54, 96(%%r16)            \n\t" 
    "stxv              %%vs55, 112(%%r16)           \n\t"
    "stxv              %%vs56, 128(%%r16)           \n\t"
    "                                               \n\t"
    "            	                                  \n\t"
  	"            	                                  \n\t"
    "                                               \n\t"
    "xxpermdi         %%vs48, %%vs0, %%vs9,  1   	  \n\t" // permute (2)
    "xxpermdi         %%vs49, %%vs1, %%vs10, 1   	  \n\t"
    "xxpermdi         %%vs50, %%vs2, %%vs11, 1   	  \n\t"
    "xxpermdi         %%vs51, %%vs3, %%vs12, 1   	  \n\t"
    "xxpermdi         %%vs52, %%vs4, %%vs13, 1   	  \n\t"
    "xxpermdi         %%vs53, %%vs5, %%vs14, 1   	  \n\t"
    "xxpermdi         %%vs54, %%vs6, %%vs15, 1   	  \n\t"
    "xxpermdi         %%vs55, %%vs7, %%vs16, 1   	  \n\t"
    "xxpermdi         %%vs56, %%vs8, %%vs17, 1   	  \n\t"
    "            	                                  \n\t"
    "            	                                  \n\t"
    "stxv              %%vs48, 0(%%r17)             \n\t" // store (2)
    "stxv              %%vs49, 16(%%r17)            \n\t" 
    "stxv              %%vs50, 32(%%r17)            \n\t" 
    "stxv              %%vs51, 48(%%r17)            \n\t" 
    "stxv              %%vs52, 64(%%r17)            \n\t" 
    "stxv              %%vs53, 80(%%r17)            \n\t" 
    "stxv              %%vs54, 96(%%r17)            \n\t" 
    "stxv              %%vs55, 112(%%r17)           \n\t"
    "stxv              %%vs56, 128(%%r17)           \n\t"
    "                                               \n\t"
  	"                                               \n\t"
  	"            	                                  \n\t"
    "                                               \n\t"
    "xxpermdi         %%vs48, %%vs27, %%vs18, 1   	\n\t" // permute (3)
    "xxpermdi         %%vs49, %%vs28, %%vs19, 1   	\n\t"
    "xxpermdi         %%vs50, %%vs29, %%vs20, 1   	\n\t"
    "xxpermdi         %%vs51, %%vs30, %%vs21, 1   	\n\t"
    "xxpermdi         %%vs52, %%vs31, %%vs22, 1   	\n\t"
    "xxpermdi         %%vs53, %%vs32, %%vs23, 1   	\n\t"
    "xxpermdi         %%vs54, %%vs33, %%vs24, 1   	\n\t"
    "xxpermdi         %%vs55, %%vs34, %%vs25, 1   	\n\t"
    "xxpermdi         %%vs56, %%vs35, %%vs26, 1   	\n\t"
    "            	                                  \n\t"
    "            	                                  \n\t"
    "stxv              %%vs48, 0(%%r18)             \n\t" // store (3)
    "stxv              %%vs49, 16(%%r18)            \n\t" 
    "stxv              %%vs50, 32(%%r18)            \n\t" 
    "stxv              %%vs51, 48(%%r18)            \n\t" 
    "stxv              %%vs52, 64(%%r18)            \n\t" 
    "stxv              %%vs53, 80(%%r18)            \n\t" 
    "stxv              %%vs54, 96(%%r18)            \n\t" 
    "stxv              %%vs55, 112(%%r18)           \n\t"
    "stxv              %%vs56, 128(%%r18)           \n\t"
  	"                                               \n\t"
  	"            	                                  \n\t"
    "                                               \n\t"
    "xxpermdi         %%vs48, %%vs18, %%vs27, 1   	\n\t" // permute (4)
    "xxpermdi         %%vs49, %%vs19, %%vs28, 1   	\n\t"
    "xxpermdi         %%vs50, %%vs20, %%vs29, 1   	\n\t"
    "xxpermdi         %%vs51, %%vs21, %%vs30, 1   	\n\t"
    "xxpermdi         %%vs52, %%vs22, %%vs31, 1   	\n\t"
    "xxpermdi         %%vs53, %%vs23, %%vs32, 1   	\n\t"
    "xxpermdi         %%vs54, %%vs24, %%vs33, 1   	\n\t"
    "xxpermdi         %%vs55, %%vs25, %%vs34, 1   	\n\t"
    "xxpermdi         %%vs56, %%vs26, %%vs35, 1   	\n\t"
    "            	                                  \n\t"
    "            	                                  \n\t"
    "stxv              %%vs48, 0(%%r19)             \n\t" // store (4)
    "stxv              %%vs49, 16(%%r19)            \n\t" 
    "stxv              %%vs50, 32(%%r19)            \n\t" 
    "stxv              %%vs51, 48(%%r19)            \n\t" 
    "stxv              %%vs52, 64(%%r19)            \n\t" 
    "stxv              %%vs53, 80(%%r19)            \n\t" 
    "stxv              %%vs54, 96(%%r19)            \n\t" 
    "stxv              %%vs55, 112(%%r19)           \n\t"
    "stxv              %%vs56, 128(%%r19)           \n\t"
  	"                                               \n\t"
  	"DDONE:                                         \n\t"  
  	"                                               \n\t"
	: // output operands (none)
	: // input operands
	  "m" (k_iter), // 0
	  "m" (k_left), // 1
	  "m" (a),      // 2
	  "m" (b),      // 3
	  "m" (alpha),  // 4
	  "m" (beta),   // 5
	  "m" (c),      // 6
	  "m" (rs_c),   // 7
	  "m" (cs_c)    // 8
    /*,   
	  "m" (b_next), // 9
	  "m" (a_next)*/  // 10
	: // register clobber list
  /* unclobberable regs: r2, r3, r4, r5, r6, r13, r14, r15, r30, r31 */
  "r0",  "r7", "r8", "r9",
  "r10", "r12","r16", "r17", "r18", "r19", 
  "r20", "r21", "r22", "r23", "r24", "r25", "r26", "r27", "r28", "r29"

  #if XLC
  ,"f0", "f1", "f2", "f3", "f4", "f5", "f6", "f7", "f8", "f9"
  , "f10", "f11", "f12", "f13", "f14", "f15", "f16", "f17", "f18", "f19"
  , "f20" ,"f21", "f22", "f23", "f24", "f25", "f26", "f27", "f28", "f29"
  , "f30" ,"f31"
  , "v0", "v1", "v2", "v3", "v4", "v5", "v6", "v7", "v8", "v9"
  , "v10", "v11", "v12", "v13", "v14", "v15", "v16", "v17", "v18", "v19"
  , "v20", "v21", "v22", "v23", "v24", "v25", "v26", "v27", "v28", "v29"
  , "v30", "v31"
  #else
  , "vs0", "vs1", "vs2", "vs3", "vs4", "vs5", "vs6", "vs7", "vs8", "vs9"
  , "vs10", "vs11", "vs12", "vs13", "vs14", "vs15", "vs16", "vs17", "vs18", "vs19"
  , "vs20", "vs21", "vs22", "vs23", "vs24", "vs25", "vs26", "vs27", "vs28", "vs29"
  , "vs30", "vs31", "vs32", "vs33", "vs34", "vs35", "vs36", "vs37", "vs38", "vs39"
  , "vs40", "vs41", "vs42", "vs43", "vs44", "vs45", "vs46", "vs47", "vs48", "vs49"
  , "vs50", "vs51", "vs52", "vs53", "vs54", "vs55", "vs56", "vs57", "vs58", "vs58"
  , "vs60", "vs61", "vs62", "vs63"
  #endif
  );

  
}





