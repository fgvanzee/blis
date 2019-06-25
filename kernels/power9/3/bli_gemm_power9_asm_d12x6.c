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

#define XLC 0 

#define VSZEROOUT \
 "xxlxor           %%vs0, %%vs0, %%vs0              \n\t" \
 "xxlxor           %%vs1, %%vs1, %%vs1              \n\t" \
 "xxlxor           %%vs2, %%vs2, %%vs2              \n\t" \
 "xxlxor           %%vs3, %%vs3, %%vs3              \n\t" \
 "xxlxor           %%vs4, %%vs4, %%vs4              \n\t" \
 "xxlxor           %%vs5, %%vs5, %%vs5              \n\t" \
 "xxlxor           %%vs6, %%vs6, %%vs6              \n\t" \
 "xxlxor           %%vs7, %%vs7, %%vs7              \n\t" \
 "xxlxor           %%vs8, %%vs8, %%vs8              \n\t" \
 "xxlxor           %%vs9, %%vs9, %%vs9              \n\t" \
 "xxlxor           %%vs10, %%vs10, %%vs10           \n\t" \
 "xxlxor           %%vs11, %%vs11, %%vs11           \n\t" \
 "xxlxor           %%vs12, %%vs12, %%vs12           \n\t" \
 "xxlxor           %%vs13, %%vs13, %%vs13           \n\t" \
 "xxlxor           %%vs14, %%vs14, %%vs14           \n\t" \
 "xxlxor           %%vs15, %%vs15, %%vs15           \n\t" \
 "xxlxor           %%vs16, %%vs16, %%vs16           \n\t" \
 "xxlxor           %%vs17, %%vs17, %%vs17           \n\t" \
 "xxlxor           %%vs18, %%vs18, %%vs18           \n\t" \
 "xxlxor           %%vs19, %%vs19, %%vs19           \n\t" \
 "xxlxor           %%vs20, %%vs20, %%vs20           \n\t" \
 "xxlxor           %%vs21, %%vs21, %%vs21           \n\t" \
 "xxlxor           %%vs22, %%vs22, %%vs22           \n\t" \
 "xxlxor           %%vs23, %%vs23, %%vs23           \n\t" \
 "xxlxor           %%vs24, %%vs24, %%vs24           \n\t" \
 "xxlxor           %%vs25, %%vs25, %%vs25           \n\t" \
 "xxlxor           %%vs26, %%vs26, %%vs26           \n\t" \
 "xxlxor           %%vs27, %%vs27, %%vs27           \n\t" \
 "xxlxor           %%vs28, %%vs28, %%vs28           \n\t" \
 "xxlxor           %%vs29, %%vs29, %%vs29           \n\t" \
 "xxlxor           %%vs30, %%vs30, %%vs30           \n\t" \
 "xxlxor           %%vs31, %%vs31, %%vs31           \n\t" \
 "xxlxor           %%vs32, %%vs32, %%vs32           \n\t" \
 "xxlxor           %%vs33, %%vs33, %%vs33           \n\t" \
 "xxlxor           %%vs34, %%vs34, %%vs34           \n\t" \
 "xxlxor           %%vs35, %%vs35, %%vs35           \n\t" \
 "xxlxor           %%vs36, %%vs36, %%vs36           \n\t" \
 "xxlxor           %%vs37, %%vs37, %%vs37           \n\t" \
 "xxlxor           %%vs38, %%vs38, %%vs38           \n\t" \
 "xxlxor           %%vs39, %%vs39, %%vs39           \n\t" \
 "xxlxor           %%vs40, %%vs40, %%vs40           \n\t" \
 "xxlxor           %%vs41, %%vs41, %%vs41           \n\t" \
 "xxlxor           %%vs42, %%vs42, %%vs42           \n\t" \
 "xxlxor           %%vs43, %%vs43, %%vs43           \n\t" \
 "xxlxor           %%vs44, %%vs44, %%vs44           \n\t" \
 "xxlxor           %%vs45, %%vs45, %%vs45           \n\t" \
 "xxlxor           %%vs46, %%vs46, %%vs46           \n\t" \
 "xxlxor           %%vs47, %%vs47, %%vs47           \n\t" \
 "xxlxor           %%vs48, %%vs48, %%vs48           \n\t" \
 "xxlxor           %%vs49, %%vs49, %%vs49           \n\t" \
 "xxlxor           %%vs50, %%vs50, %%vs50           \n\t" \
 "xxlxor           %%vs51, %%vs51, %%vs51           \n\t" \
 "xxlxor           %%vs52, %%vs52, %%vs52           \n\t" \
 "xxlxor           %%vs53, %%vs53, %%vs53           \n\t" \
 "xxlxor           %%vs59, %%vs59, %%vs59           \n\t"    

#define PRELOADA \
  "lxv           %%vs36, 0(%%r7)                  \n\t" \
  "lxv           %%vs37, 16(%%r7)                 \n\t" \
  "lxv           %%vs38, 32(%%r7)                 \n\t" \
  "lxv           %%vs39, 48(%%r7)                 \n\t" \
  "lxv           %%vs40, 64(%%r7)                 \n\t" \
  "lxv           %%vs41, 80(%%r7)                 \n\t" \
  "lxv           %%vs42, 96(%%r7)                 \n\t" \
  "lxv           %%vs43, 112(%%r7)                \n\t" \
  "lxv           %%vs44, 128(%%r7)                \n\t" \
  "lxv           %%vs45, 144(%%r7)                \n\t" \
  "lxv           %%vs46, 160(%%r7)                \n\t" \

#define PRELOADB1 \
  "lxvdsx       %%vs48, %%r22, %%r8               \n\t" \
	"lxvdsx       %%vs49, %%r23, %%r8               \n\t" \
	"lxvdsx       %%vs50, %%r24, %%r8               \n\t" \
	"lxvdsx       %%vs51, %%r25, %%r8               \n\t" \
	"lxvdsx       %%vs52, %%r26, %%r8               \n\t" \
	"lxvdsx       %%vs53, %%r27, %%r8               \n\t"

#define PRELOADB2 \
  "lxvdsx       %%vs54, %%r22, %%r28              \n\t" \
  "lxvdsx       %%vs55, %%r23, %%r28              \n\t" \
 	"lxvdsx       %%vs56, %%r24, %%r28              \n\t" \
  "lxvdsx       %%vs57, %%r25, %%r28              \n\t" \
  "lxvdsx       %%vs58, %%r26, %%r28              \n\t" 

//load B at the end
#define LOADANDUPDATE2 \
  "                                               \n\t" \
  "xvmaddadp        %%vs0, %%vs36, %%vs48         \n\t" \
  "xvmaddadp        %%vs1, %%vs37, %%vs48         \n\t" \
  "xvmaddadp        %%vs2, %%vs38, %%vs48         \n\t" \
  "xvmaddadp        %%vs3, %%vs39, %%vs48         \n\t" \
  "                                               \n\t" \
  "lxvdsx       %%vs59, %%r22, %%r8               \n\t" \
  "                                               \n\t" \
  "xvmaddadp        %%vs4, %%vs40, %%vs48         \n\t" \
  "xvmaddadp        %%vs5, %%vs41, %%vs48         \n\t" \
  "xvmaddadp        %%vs6, %%vs36, %%vs49         \n\t" \
  "xvmaddadp        %%vs12, %%vs36, %%vs50        \n\t" \
  "                                               \n\t" \
  "lxv           %%vs47, 0(%%r7)                  \n\t" \
  "                                               \n\t" \
  "xvmaddadp        %%vs18, %%vs36, %%vs51        \n\t" \
  "xvmaddadp        %%vs24, %%vs36, %%vs52        \n\t" \
  "xvmaddadp        %%vs30, %%vs36, %%vs53        \n\t" \
  "xvmaddadp        %%vs7, %%vs37, %%vs49         \n\t" \
  "                                               \n\t" \
  "lxvdsx       %%vs48, %%r23, %%r8               \n\t" \
  "                                               \n\t" \
  "xvmaddadp        %%vs8, %%vs38, %%vs49         \n\t" \
  "xvmaddadp        %%vs9, %%vs39, %%vs49         \n\t" \
  "xvmaddadp        %%vs10, %%vs40, %%vs49        \n\t" \
  "                                               \n\t" \
  "lxv          %%vs36, 16(%%r7)                  \n\t" \
  "                                               \n\t" \
  "xvmaddadp        %%vs11, %%vs41, %%vs49        \n\t" \
  "xvmaddadp        %%vs13, %%vs37, %%vs50        \n\t" \
  "xvmaddadp        %%vs19, %%vs37, %%vs51        \n\t" \
  "                                               \n\t" \
  "lxvdsx       %%vs49, %%r24, %%r8               \n\t" \
  "                                               \n\t" \
  "xvmaddadp        %%vs25, %%vs37, %%vs52        \n\t" \
  "xvmaddadp        %%vs31, %%vs37, %%vs53        \n\t" \
  "xvmaddadp        %%vs14, %%vs38, %%vs50        \n\t" \
  "                                               \n\t" \
  "lxv          %%vs37, 32(%%r7)                  \n\t" \
  "                                               \n\t" \
  "xvmaddadp        %%vs15, %%vs39, %%vs50        \n\t" \
  "xvmaddadp        %%vs16, %%vs40, %%vs50        \n\t" \
  "xvmaddadp        %%vs17, %%vs41, %%vs50        \n\t" \
  "xvmaddadp        %%vs20, %%vs38, %%vs51        \n\t" \
  "                                               \n\t" \
  "lxvdsx       %%vs50, %%r25, %%r8               \n\t" \
  "                                               \n\t" \
  "xvmaddadp        %%vs26, %%vs38, %%vs52        \n\t" \
  "xvmaddadp        %%vs32, %%vs38, %%vs53        \n\t" \
  "xvmaddadp        %%vs21, %%vs39, %%vs51        \n\t" \
  "                                               \n\t" \
  "lxv          %%vs38, 48(%%r7)                  \n\t" \
  "                                               \n\t" \
  "xvmaddadp        %%vs22, %%vs40, %%vs51        \n\t" \
  "xvmaddadp        %%vs23, %%vs41, %%vs51        \n\t" \
  "xvmaddadp        %%vs27, %%vs39, %%vs52        \n\t" \
  "                                               \n\t" \
  "lxvdsx       %%vs51, %%r26, %%r8               \n\t" \
  "                                               \n\t" \
  "xvmaddadp        %%vs33, %%vs39, %%vs53        \n\t" \
  "xvmaddadp        %%vs28, %%vs40, %%vs52        \n\t" \
  "xvmaddadp        %%vs29, %%vs41, %%vs52        \n\t" \
  "                                               \n\t" \
  "lxv          %%vs39, 64(%%r7)                  \n\t" \
  "                                               \n\t" \
  "xvmaddadp        %%vs34, %%vs40, %%vs53        \n\t" \
  "xvmaddadp        %%vs35, %%vs41, %%vs53        \n\t" \
  "xvmaddadp        %%vs0, %%vs42, %%vs54         \n\t" \
  "                                               \n\t" \
  "lxvdsx       %%vs52, %%r27, %%r8               \n\t" \
  "                                               \n\t" \
  "xvmaddadp        %%vs1, %%vs43, %%vs54         \n\t" \
  "xvmaddadp        %%vs2, %%vs44, %%vs54         \n\t" \
  "xvmaddadp        %%vs3, %%vs45, %%vs54         \n\t" \
  "                                               \n\t" \
  "lxv          %%vs40, 80(%%r7)                  \n\t" \
  "                                               \n\t" \
  "xvmaddadp        %%vs4, %%vs46, %%vs54         \n\t" \
  "xvmaddadp        %%vs5, %%vs47, %%vs54         \n\t" \
  "xvmaddadp        %%vs6, %%vs42, %%vs55         \n\t" \
  "                                               \n\t" \
  "lxvdsx       %%vs53, %%r22, %%r28              \n\t" \
  "                                               \n\t" \
  "xvmaddadp        %%vs12, %%vs42, %%vs56        \n\t" \
  "xvmaddadp        %%vs18, %%vs42, %%vs57        \n\t" \
  "xvmaddadp        %%vs24, %%vs42, %%vs58        \n\t" \
  "                                               \n\t" \
  "lxv          %%vs41, 96(%%r7)                  \n\t" \
  "                                               \n\t" \
  "xvmaddadp        %%vs30, %%vs42, %%vs59        \n\t" \
  "xvmaddadp        %%vs7, %%vs43, %%vs55         \n\t" \
  "xvmaddadp        %%vs8, %%vs44, %%vs55         \n\t" \
  "                                               \n\t" \
  "lxvdsx       %%vs54, %%r23, %%r28              \n\t" \
  "                                               \n\t" \
  "xvmaddadp        %%vs9, %%vs45, %%vs55         \n\t" \
  "xvmaddadp        %%vs10, %%vs46, %%vs55        \n\t" \
  "xvmaddadp        %%vs11, %%vs47, %%vs55        \n\t" \
  "                                               \n\t" \
  "lxv          %%vs42, 112(%%r7)                 \n\t" \
  "                                               \n\t" \
  "xvmaddadp        %%vs13, %%vs43, %%vs56        \n\t" \
  "xvmaddadp        %%vs19, %%vs43, %%vs57        \n\t" \
  "xvmaddadp        %%vs25, %%vs43, %%vs58        \n\t" \
  "                                               \n\t" \
  "lxvdsx       %%vs55, %%r24, %%r28              \n\t" \
  "                                               \n\t" \
  "xvmaddadp        %%vs31, %%vs43, %%vs59        \n\t" \
  "xvmaddadp        %%vs14, %%vs44, %%vs56        \n\t" \
  "xvmaddadp        %%vs15, %%vs45, %%vs56        \n\t" \
  "                                               \n\t" \
  "lxv          %%vs43, 128(%%r7)                 \n\t" \
  "                                               \n\t" \
  "xvmaddadp        %%vs16, %%vs46, %%vs56        \n\t" \
  "xvmaddadp        %%vs17, %%vs47, %%vs56        \n\t" \
  "xvmaddadp        %%vs20, %%vs44, %%vs57        \n\t" \
  "                                               \n\t" \
  "lxvdsx       %%vs56, %%r25, %%r28              \n\t" \
  "                                               \n\t" \
  "xvmaddadp        %%vs26, %%vs44, %%vs58        \n\t" \
  "xvmaddadp        %%vs32, %%vs44, %%vs59        \n\t" \
  "xvmaddadp        %%vs21, %%vs45, %%vs57        \n\t" \
  "                                               \n\t" \
  "lxv          %%vs44, 144(%%r7)                 \n\t" \
  "                                               \n\t" \
  "xvmaddadp        %%vs22, %%vs46, %%vs57        \n\t" \
  "xvmaddadp        %%vs23, %%vs47, %%vs57        \n\t" \
  "xvmaddadp        %%vs27, %%vs45, %%vs58        \n\t" \
  "                                               \n\t" \
  "lxvdsx       %%vs57, %%r26, %%r28              \n\t" \
  "                                               \n\t" \
  "xvmaddadp        %%vs33, %%vs45, %%vs59        \n\t" \
  "xvmaddadp        %%vs28, %%vs46, %%vs58        \n\t" \
  "xvmaddadp        %%vs29, %%vs47, %%vs58        \n\t" \
  "                                               \n\t" \
  "lxv          %%vs45, 160(%%r7)                 \n\t" \
  "                                               \n\t" \
  "xvmaddadp        %%vs34, %%vs46, %%vs59        \n\t" \
  "xvmaddadp        %%vs35, %%vs47, %%vs59        \n\t" \
  "                                               \n\t" \
  "lxvdsx       %%vs58, %%r27, %%r28              \n\t" \
  "lxv          %%vs46, 176(%%r7)                 \n\t" \
  "                                               \n\t" \
  "addi             %%r7, %%r7, 192               \n\t" \
  "addi             %%r8, %%r8, 96                \n\t" \
  "addi             %%r28, %%r28, 96              \n\t"



//load B at the end
#define LOADANDUPDATE1 \
  "                                               \n\t" \
  "addi             %%r8, %%r8, 48                \n\t" \
  "                                               \n\t" \
  "lxv           %%vs36, 0(%%r7)                  \n\t" \
  "lxv           %%vs37, 16(%%r7)                 \n\t" \
  "lxv           %%vs38, 32(%%r7)                 \n\t" \
  "lxv           %%vs39, 48(%%r7)                 \n\t" \
  "lxv           %%vs40, 64(%%r7)                 \n\t" \
  "lxv           %%vs41, 80(%%r7)                 \n\t" \
  "                                               \n\t" \
  "                                               \n\t" \
  "xvmaddadp        %%vs0, %%vs36, %%vs48         \n\t" \
  "xvmaddadp        %%vs1, %%vs37, %%vs48         \n\t" \
  "xvmaddadp        %%vs2, %%vs38, %%vs48         \n\t" \
  "xvmaddadp        %%vs3, %%vs39, %%vs48         \n\t" \
  "xvmaddadp        %%vs4, %%vs40, %%vs48         \n\t" \
  "xvmaddadp        %%vs5, %%vs41, %%vs48         \n\t" \
  "                                               \n\t" \
  "lxvdsx       %%vs48, %%r22, %%r8               \n\t" \
  "                                               \n\t" \
  "xvmaddadp        %%vs6, %%vs36, %%vs49         \n\t" \
  "xvmaddadp        %%vs7, %%vs37, %%vs49         \n\t" \
  "xvmaddadp        %%vs8, %%vs38, %%vs49         \n\t" \
  "xvmaddadp        %%vs9, %%vs39, %%vs49         \n\t" \
  "xvmaddadp        %%vs10, %%vs40, %%vs49        \n\t" \
  "xvmaddadp        %%vs11, %%vs41, %%vs49        \n\t" \
  "                                               \n\t" \
  "lxvdsx       %%vs49, %%r23, %%r8               \n\t" \
  "                                               \n\t" \
  "xvmaddadp        %%vs12, %%vs36, %%vs50        \n\t" \
  "xvmaddadp        %%vs13, %%vs37, %%vs50        \n\t" \
  "xvmaddadp        %%vs14, %%vs38, %%vs50        \n\t" \
  "xvmaddadp        %%vs15, %%vs39, %%vs50        \n\t" \
  "xvmaddadp        %%vs16, %%vs40, %%vs50        \n\t" \
  "xvmaddadp        %%vs17, %%vs41, %%vs50        \n\t" \
  "                                               \n\t" \
  "lxvdsx       %%vs50, %%r24, %%r8               \n\t" \
  "                                               \n\t" \
  "xvmaddadp        %%vs18, %%vs36, %%vs51        \n\t" \
  "xvmaddadp        %%vs19, %%vs37, %%vs51        \n\t" \
  "xvmaddadp        %%vs20, %%vs38, %%vs51        \n\t" \
  "xvmaddadp        %%vs21, %%vs39, %%vs51        \n\t" \
  "xvmaddadp        %%vs22, %%vs40, %%vs51        \n\t" \
  "xvmaddadp        %%vs23, %%vs41, %%vs51        \n\t" \
  "                                               \n\t" \
  "addi             %%r7, %%r7, 96                \n\t" \
  "lxvdsx       %%vs51, %%r25, %%r8               \n\t" \
  "                                               \n\t" \
  "xvmaddadp        %%vs24, %%vs36, %%vs52        \n\t" \
  "xvmaddadp        %%vs25, %%vs37, %%vs52        \n\t" \
  "xvmaddadp        %%vs26, %%vs38, %%vs52        \n\t" \
  "xvmaddadp        %%vs27, %%vs39, %%vs52        \n\t" \
  "xvmaddadp        %%vs28, %%vs40, %%vs52        \n\t" \
  "xvmaddadp        %%vs29, %%vs41, %%vs52        \n\t" \
  "                                               \n\t" \
  "lxvdsx       %%vs52, %%r26, %%r8               \n\t" \
  "                                               \n\t" \
  "xvmaddadp        %%vs30, %%vs36, %%vs53        \n\t" \
  "xvmaddadp        %%vs31, %%vs37, %%vs53        \n\t" \
  "xvmaddadp        %%vs32, %%vs38, %%vs53        \n\t" \
  "xvmaddadp        %%vs33, %%vs39, %%vs53        \n\t" \
  "xvmaddadp        %%vs34, %%vs40, %%vs53        \n\t" \
  "xvmaddadp        %%vs35, %%vs41, %%vs53        \n\t" \
  "                                               \n\t" \
  "                                               \n\t" \
  "lxvdsx       %%vs53, %%r27, %%r8               \n\t" \
  "                                               \n\t" \


#define SCALEBYALPHA \
 "xvmuldp          %%vs0, %%vs0, %%vs48   	 \n\t" \
 "xvmuldp          %%vs1, %%vs1, %%vs48   	 \n\t" \
 "xvmuldp          %%vs2, %%vs2, %%vs48   	 \n\t" \
 "xvmuldp          %%vs3, %%vs3, %%vs48   	 \n\t" \
 "xvmuldp          %%vs4, %%vs4, %%vs48   	 \n\t" \
 "xvmuldp          %%vs5, %%vs5, %%vs48   	 \n\t" \
 "xvmuldp          %%vs6, %%vs6, %%vs48   	 \n\t" \
 "xvmuldp          %%vs7, %%vs7, %%vs48   	 \n\t" \
 "xvmuldp          %%vs8, %%vs8, %%vs48   	 \n\t" \
 "xvmuldp          %%vs9, %%vs9, %%vs48   	 \n\t" \
 "xvmuldp          %%vs10, %%vs10, %%vs48   	 \n\t" \
 "xvmuldp          %%vs11, %%vs11, %%vs48   	 \n\t" \
 "xvmuldp          %%vs12, %%vs12, %%vs48   	 \n\t" \
 "xvmuldp          %%vs13, %%vs13, %%vs48   	 \n\t" \
 "xvmuldp          %%vs14, %%vs14, %%vs48   	 \n\t" \
 "xvmuldp          %%vs15, %%vs15, %%vs48   	 \n\t" \
 "xvmuldp          %%vs16, %%vs16, %%vs48   	 \n\t" \
 "xvmuldp          %%vs17, %%vs17, %%vs48   	 \n\t" \
 "xvmuldp          %%vs18, %%vs18, %%vs48   	 \n\t" \
 "xvmuldp          %%vs19, %%vs19, %%vs48   	 \n\t" \
 "xvmuldp          %%vs20, %%vs20, %%vs48   	 \n\t" \
 "xvmuldp          %%vs21, %%vs21, %%vs48   	 \n\t" \
 "xvmuldp          %%vs22, %%vs22, %%vs48   	 \n\t" \
 "xvmuldp          %%vs23, %%vs23, %%vs48   	 \n\t" \
 "xvmuldp          %%vs24, %%vs24, %%vs48   	 \n\t" \
 "xvmuldp          %%vs25, %%vs25, %%vs48   	 \n\t" \
 "xvmuldp          %%vs26, %%vs26, %%vs48   	 \n\t" \
 "xvmuldp          %%vs27, %%vs27, %%vs48   	 \n\t" \
 "xvmuldp          %%vs28, %%vs28, %%vs48   	 \n\t" \
 "xvmuldp          %%vs29, %%vs29, %%vs48   	 \n\t" \
 "xvmuldp          %%vs30, %%vs30, %%vs48   	 \n\t" \
 "xvmuldp          %%vs31, %%vs31, %%vs48   	 \n\t" \
 "xvmuldp          %%vs32, %%vs32, %%vs48   	 \n\t" \
 "xvmuldp          %%vs33, %%vs33, %%vs48   	 \n\t" \
 "xvmuldp          %%vs34, %%vs34, %%vs48   	 \n\t" \
 "xvmuldp          %%vs35, %%vs35, %%vs48   	 \n\t" 

#define SCALECOL_CMATRIX \
 "xvmuldp          %%vs36, %%vs36, %%vs59   	 \n\t" \
 "xvmuldp          %%vs37, %%vs37, %%vs59   	 \n\t" \
 "xvmuldp          %%vs38, %%vs38, %%vs59   	 \n\t" \
 "xvmuldp          %%vs39, %%vs39, %%vs59   	 \n\t" \
 "xvmuldp          %%vs40, %%vs40, %%vs59   	 \n\t" \
 "xvmuldp          %%vs41, %%vs41, %%vs59   	 \n\t" \
 "xvmuldp          %%vs42, %%vs42, %%vs59   	 \n\t" \
 "xvmuldp          %%vs43, %%vs43, %%vs59   	 \n\t" \
 "xvmuldp          %%vs44, %%vs44, %%vs59   	 \n\t" \
 "xvmuldp          %%vs45, %%vs45, %%vs59   	 \n\t" \
 "xvmuldp          %%vs46, %%vs46, %%vs59   	 \n\t" \
 "xvmuldp          %%vs47, %%vs47, %%vs59   	 \n\t" \
 "xvmuldp          %%vs48, %%vs48, %%vs59   	 \n\t" \
 "xvmuldp          %%vs49, %%vs49, %%vs59   	 \n\t" \
 "xvmuldp          %%vs50, %%vs50, %%vs59   	 \n\t" \
 "xvmuldp          %%vs51, %%vs51, %%vs59   	 \n\t" \
 "xvmuldp          %%vs52, %%vs52, %%vs59   	 \n\t" \
 "xvmuldp          %%vs53, %%vs53, %%vs59   	 \n\t" \
 
#define LOADCOL_CMATRIX \
  "lxv              %%vs36, 0(%%r22)           \n\t" \
  "lxv              %%vs37, 16(%%r22)          \n\t" \
  "lxv              %%vs38, 32(%%r22)          \n\t" \
  "lxv              %%vs39, 48(%%r22)          \n\t" \
  "lxv              %%vs40, 64(%%r22)          \n\t" \
  "lxv              %%vs41, 80(%%r22)          \n\t" \
  "lxv              %%vs42, 0(%%r23)           \n\t" \
  "lxv              %%vs43, 16(%%r23)          \n\t" \
  "lxv              %%vs44, 32(%%r23)          \n\t" \
  "lxv              %%vs45, 48(%%r23)          \n\t" \
  "lxv              %%vs46, 64(%%r23)          \n\t" \
  "lxv              %%vs47, 80(%%r23)          \n\t" \
  "lxv              %%vs48, 0(%%r24)           \n\t" \
  "lxv              %%vs49, 16(%%r24)          \n\t" \
  "lxv              %%vs50, 32(%%r24)          \n\t" \
  "lxv              %%vs51, 48(%%r24)          \n\t" \
  "lxv              %%vs52, 64(%%r24)          \n\t" \
  "lxv              %%vs53, 80(%%r24)          \n\t"

#define SCALEGEN_CMATRIX \
  "xvmuldp          %%vs36, %%vs36, %%vs59   	 \n\t" \
  "xvmuldp          %%vs37, %%vs37, %%vs59   	 \n\t" \
  "xvmuldp          %%vs38, %%vs38, %%vs59   	 \n\t" \
  "xvmuldp          %%vs39, %%vs39, %%vs59   	 \n\t" \
  "xvmuldp          %%vs40, %%vs40, %%vs59   	 \n\t" \
  "xvmuldp          %%vs41, %%vs41, %%vs59   	 \n\t"

#define LOADGEN_CMATRIX \
  "lxsdx	   %%vs36, %%r9, %%r22             \n\t" \
  "lxsdx       %%vs37, 0, %%r22                \n\t" \
  "xxpermdi    %%vs36, %%vs36, %%vs37, 0       \n\t" \
  "lxsdx	   %%vs37, %%r9, %%r23             \n\t" \
  "lxsdx       %%vs38, 0, %%r23                \n\t" \
  "xxpermdi    %%vs37, %%vs37, %%vs38, 0       \n\t" \
  "lxsdx	   %%vs38, %%r9, %%r24             \n\t" \
  "lxsdx       %%vs39, 0, %%r24                \n\t" \
  "xxpermdi    %%vs38, %%vs38, %%vs39, 0       \n\t" \
  "lxsdx	   %%vs39, %%r9, %%r25             \n\t" \
  "lxsdx       %%vs40, 0, %%r25                \n\t" \
  "xxpermdi    %%vs39, %%vs39, %%vs40, 0       \n\t" \
  "lxsdx	   %%vs40, %%r9, %%r26             \n\t" \
  "lxsdx       %%vs41, 0, %%r26                \n\t" \
  "xxpermdi    %%vs40, %%vs40, %%vs41, 0       \n\t" \
  "lxsdx	   %%vs41, %%r9, %%r27             \n\t" \
  "lxsdx       %%vs42, 0, %%r27                \n\t" \
  "xxpermdi    %%vs41, %%vs41, %%vs42, 0       \n\t"

#define GEN_NEXT_COL_CMATRIX \
  "add             %%r22, %%r22, %%r10             \n\t" \
  "add             %%r23, %%r23, %%r10             \n\t" \
  "add             %%r24, %%r24, %%r10             \n\t" \
  "add             %%r25, %%r25, %%r10             \n\t" \
  "add             %%r26, %%r26, %%r10             \n\t" \
  "add             %%r27, %%r27, %%r10             \n\t"

#define GENLOAD_SCALE_UPDATE \
  LOADGEN_CMATRIX   \
  GEN_NEXT_COL_CMATRIX \
  SCALEGEN_CMATRIX

#define COLSTORE_CMATRIX \
  "stxv              %%vs0, 0(%%r16)            \n\t" \
  "stxv              %%vs1, 16(%%r16)           \n\t" \
  "stxv              %%vs2, 32(%%r16)           \n\t" \
  "stxv              %%vs3, 48(%%r16)           \n\t" \
  "stxv              %%vs4, 64(%%r16)           \n\t" \
  "stxv              %%vs5, 80(%%r16)           \n\t" \
  "stxv              %%vs6, 0(%%r17)            \n\t" \
  "stxv              %%vs7, 16(%%r17)           \n\t" \
  "stxv              %%vs8, 32(%%r17)           \n\t" \
  "stxv              %%vs9, 48(%%r17)           \n\t" \
  "stxv              %%vs10, 64(%%r17)          \n\t" \
  "stxv              %%vs11, 80(%%r17)          \n\t" \
  "stxv              %%vs12, 0(%%r18)           \n\t" \
  "stxv              %%vs13, 16(%%r18)          \n\t" \
  "stxv              %%vs14, 32(%%r18)          \n\t" \
  "stxv              %%vs15, 48(%%r18)          \n\t" \
  "stxv              %%vs16, 64(%%r18)          \n\t" \
  "stxv              %%vs17, 80(%%r18)          \n\t" \
  "stxv              %%vs18, 0(%%r19)           \n\t" \
  "stxv              %%vs19, 16(%%r19)          \n\t" \
  "stxv              %%vs20, 32(%%r19)          \n\t" \
  "stxv              %%vs21, 48(%%r19)          \n\t" \
  "stxv              %%vs22, 64(%%r19)          \n\t" \
  "stxv              %%vs23, 80(%%r19)          \n\t" \
  "stxv              %%vs24, 0(%%r20)           \n\t" \
  "stxv              %%vs25, 16(%%r20)          \n\t" \
  "stxv              %%vs26, 32(%%r20)          \n\t" \
  "stxv              %%vs27, 48(%%r20)          \n\t" \
  "stxv              %%vs28, 64(%%r20)          \n\t" \
  "stxv              %%vs29, 80(%%r20)          \n\t" \
  "stxv              %%vs30, 0(%%r21)           \n\t" \
  "stxv              %%vs31, 16(%%r21)          \n\t" \
  "stxv              %%vs32, 32(%%r21)          \n\t" \
  "stxv              %%vs33, 48(%%r21)          \n\t" \
  "stxv              %%vs34, 64(%%r21)          \n\t" \
  "stxv              %%vs35, 80(%%r21)          \n\t"



void bli_dgemm_power9_asm_12x6
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
  #if 1
	uint64_t k_iter = k0 / 8;
	uint64_t k_left = k0 % 8;
  #else
  uint64_t k_iter = 0;
	uint64_t k_left = k0;
  #endif
  uint64_t rs_c   = rs_c0;
	uint64_t cs_c   = cs_c0;

  // printf("rs_c0 = %ld | cs_c0 = %ld | alpha = %lf | beta = %lf\n",
  //    rs_c0, cs_c0, *alpha, *beta);

  // if(rs_c0 != 1)
  // {
  //   
  //   bli_check_error_code(BLIS_NOT_YET_IMPLEMENTED);
  // }

	__asm__ volatile
	(
	"                                               \n\t"
  	"ld               %%r10, %8                     \n\t" // load cs_c
  	"ld               %%r9, %7                      \n\t" // load rs_c
  	"                                               \n\t"
  	"                                               \n\t" // Offsets for B
  	"li               %%r22,0                       \n\t" // 0
  	"li               %%r23,8                       \n\t" // 1
  	"li               %%r24,16                      \n\t" // 2
  	"li               %%r25,24                      \n\t" // 3
  	"li               %%r26,32                      \n\t" // 4
  	"li               %%r27,40                      \n\t" // 5
  	"                                               \n\t"
  	"ld               %%r17, %0                      \n\t" // load k_iter
  	"ld               %%r18, %1                     \n\t" // load k_left
  	"                                               \n\t"
  	"                                               \n\t"
  	"slwi             %%r10, %%r10, 3               \n\t" // mul by size of elem
  	"slwi             %%r9, %%r9, 3                 \n\t" // mul by size of elem
  	"                                               \n\t"
  	"ld               %%r7, %2                      \n\t" // load ptr of A
  	"ld               %%r8, %3                      \n\t" // load ptr of B
  	"ld               %%r16, %6                     \n\t" // load ptr for C
  	"                                               \n\t"
VSZEROOUT                                               // Zero out vec regs
    "addi             %%r28, %%r8, 48               \n\t"
  	"                                               \n\t"
PRELOADB1
  	"                                               \n\t"
  	"                                               \n\t"
  	"cmpwi            %%r0, %%r17, 0                \n\t"
  	"beq              %%r0, DPRELOOPKLEFT           \n\t"
  	"mtctr            %%r17                         \n\t"
  	"                                               \n\t"
PRELOADA
PRELOADB2
    "addi             %%r7, %%r7, 176               \n\t"
    "addi             %%r8, %%r8, 88                \n\t"
    "addi             %%r28, %%r28, 88              \n\t"
  	"                                               \n\t" // k_iter loop does A*B 
  	"DLOOPKITER:                                    \n\t" // Begin k_iter loop
  	"                                               \n\t"
LOADANDUPDATE2
LOADANDUPDATE2
LOADANDUPDATE2
LOADANDUPDATE2
  	"                                               \n\t"
  	"bdnz             DLOOPKITER                    \n\t"
    "                                               \n\t"
    "addi             %%r8, %%r8, -40               \n\t"
  	"                                               \n\t"
  	"DPRELOOPKLEFT:                                 \n\t"
  	"                                               \n\t"
  	"cmpwi            %%r0, %%r18, 0                \n\t"
  	"beq              %%r0, DPOSTACCUM              \n\t"
  	"mtctr            %%r18                         \n\t"
  	"                                               \n\t"
  	"DLOOPKLEFT:                                    \n\t" // EDGE LOOP
  LOADANDUPDATE1
  	"bdnz             DLOOPKLEFT                    \n\t"
  	"                                               \n\t"
  	"DPOSTACCUM:                                    \n\t"
  	"                                               \n\t"
  	"ld               %%r0, %4                      \n\t" // load ptr for alpha
  	"ld               %%r28, %5                     \n\t" // load ptr for beta
  	"                                               \n\t"
  	"lxvdsx           %%vs48, 0, %%r0               \n\t" // splat alpha
  	"lxvdsx           %%vs59, 0, %%r28              \n\t" // splat beta
  	"                                               \n\t"
  SCALEBYALPHA
  	"                                               \n\t"
  	"                                               \n\t"
  	"                                               \n\t"
  	"cmpwi            %%r0, %%r28, 0                \n\t"
  	"beq              %%r0, DBETAZERO               \n\t" // jump to BZ case if beta = 0
  	"                                               \n\t"
  	"ld               %%r22, %6                     \n\t" // load ptr for C (used as offset)
  	"                                               \n\t"
  	"cmpwi            %%r0, %%r9, 8                 \n\t"
  	"beq              DCOLSTOREDBNZ                 \n\t" // jump to COLstore case, if rs_c = 8
  	"                                               \n\t"
  	"                                               \n\t"
  	"DGENSTOREDBNZ:                                 \n\t"
  	"                                               \n\t" // create offset regs
  	"slwi            %%r12, %%r9, 1                 \n\t"
  	"add             %%r23, %%r22, %%r12            \n\t" // c + rs_c * 2
  	"add             %%r24, %%r23, %%r12            	\n\t" // c + rs_c * 4
  	"add             %%r25, %%r24, %%r12            	\n\t" // c + rs_c * 6 
  	"add             %%r26, %%r25, %%r12            	\n\t" // c + rs_c * 8
  	"add             %%r27, %%r26, %%r12            	\n\t" // c + rs_c * 10
  	"                                               	\n\t"
  GENLOAD_SCALE_UPDATE                                  // (1) load, scale, and move offsets of C
  	"                                              	    \n\t"
	"xvadddp          %%vs0, %%vs0, %%vs36   		  	\n\t" 
  	"xvadddp          %%vs1, %%vs1, %%vs37   		  	\n\t" 
  	"xvadddp          %%vs2, %%vs2, %%vs38   		  	\n\t" 
  	"xvadddp          %%vs3, %%vs3, %%vs39		   	  	\n\t" 
  	"xvadddp          %%vs4, %%vs4, %%vs40   	  		\n\t" 
  	"xvadddp          %%vs5, %%vs5, %%vs41   	  		\n\t"
  	"                                               	\n\t"
  	"                                               	\n\t"
  GENLOAD_SCALE_UPDATE                                  // (2) load, scale, and move offsets of C
  	"                                                   \n\t"
  	"xvadddp          %%vs6, %%vs6, %%vs36              \n\t" 
  	"xvadddp          %%vs7, %%vs7, %%vs37              \n\t" 
  	"xvadddp          %%vs8, %%vs8, %%vs38              \n\t" 
  	"xvadddp          %%vs9, %%vs9, %%vs39              \n\t" 
  	"xvadddp          %%vs10, %%vs10, %%vs40            \n\t" 
  	"xvadddp          %%vs11, %%vs11, %%vs41            \n\t"
  	"                                                   \n\t"
  	"                                                   \n\t"
  GENLOAD_SCALE_UPDATE                                  // (3) load, scale, and move offsets of C
  	"                                                   \n\t"
  	"xvadddp          %%vs12, %%vs12, %%vs36            \n\t"
  	"xvadddp          %%vs13, %%vs13, %%vs37            \n\t"
  	"xvadddp          %%vs14, %%vs14, %%vs38            \n\t"
  	"xvadddp          %%vs15, %%vs15, %%vs39            \n\t"
  	"xvadddp          %%vs16, %%vs16, %%vs40            \n\t"
  	"xvadddp          %%vs17, %%vs17, %%vs41            \n\t"
  	"                                                   \n\t"
  	"                                          	        \n\t"
  GENLOAD_SCALE_UPDATE                                  // (4) load, scale, and move offsets of C
  	"                                               	\n\t"
  	"xvadddp          %%vs18, %%vs18, %%vs36        	\n\t"
  	"xvadddp          %%vs19, %%vs19, %%vs37        	\n\t"
  	"xvadddp          %%vs20, %%vs20, %%vs38        	\n\t"
  	"xvadddp          %%vs21, %%vs21, %%vs39        	\n\t"
  	"xvadddp          %%vs22, %%vs22, %%vs40        	\n\t"
  	"xvadddp          %%vs23, %%vs23, %%vs41        	\n\t"
  	"                                               	\n\t"
  	"                                               	\n\t"
  GENLOAD_SCALE_UPDATE                                  // (5) load, scale, and move offsets of C
  	"                                               	\n\t"
  	"xvadddp          %%vs24, %%vs24, %%vs36        	\n\t"
  	"xvadddp          %%vs25, %%vs25, %%vs37        	\n\t"
  	"xvadddp          %%vs26, %%vs26, %%vs38        	\n\t"
  	"xvadddp          %%vs27, %%vs27, %%vs39        	\n\t"
  	"xvadddp          %%vs28, %%vs28, %%vs40        	\n\t"
  	"xvadddp          %%vs29, %%vs29, %%vs41        	\n\t"
  	"                                               	\n\t"
  	"                                               	\n\t"
  GENLOAD_SCALE_UPDATE                                  // (6) load, scale, and move offsets of C
  	"                                               	\n\t"
  	"xvadddp          %%vs30, %%vs30, %%vs36        	\n\t"
  	"xvadddp          %%vs31, %%vs31, %%vs37        	\n\t"
  	"xvadddp          %%vs32, %%vs32, %%vs38        	\n\t"
  	"xvadddp          %%vs33, %%vs33, %%vs39        	\n\t"
  	"xvadddp          %%vs34, %%vs34, %%vs40        	\n\t"
  	"xvadddp          %%vs35, %%vs35, %%vs41        	\n\t"
  	"                                               	\n\t"
  	"b                DGENSTORED                    	\n\t"
  	"                                               	\n\t"
  	"                                               	\n\t"
  	"DCOLSTOREDBNZ:                                 	\n\t"
  	"                                               	\n\t"
  	"add              %%r23, %%r22, %%r10            	\n\t" // c + cs_c
  	"add              %%r24, %%r23, %%r10            	\n\t" // c + cs_c * 2
  	"                                               	\n\t"
  	"DADDTOC:                                       	\n\t" // C = beta*C + alpha*(AB)
  	"                                               	\n\t"
 LOADCOL_CMATRIX
  	"add             %%r22, %%r24, %%r10             	\n\t" // c + cs_c * 3
  	"add             %%r23, %%r22, %%r10             	\n\t" // c + cs_c * 4
  	"add             %%r24, %%r23, %%r10             	\n\t" // c + cs_c * 5
 SCALECOL_CMATRIX
  	"            	                                   \n\t"
  	"xvadddp          %%vs0, %%vs0, %%vs36   	       \n\t" // Begin adding to C
  	"xvadddp          %%vs1, %%vs1, %%vs37   	       \n\t" 
  	"xvadddp          %%vs2, %%vs2, %%vs38   	       \n\t" 
  	"xvadddp          %%vs3, %%vs3, %%vs39   	       \n\t" 
  	"xvadddp          %%vs4, %%vs4, %%vs40   	       \n\t" 
  	"xvadddp          %%vs5, %%vs5, %%vs41   	       \n\t" 
  	"xvadddp          %%vs6, %%vs6, %%vs42   	       \n\t" 
  	"xvadddp          %%vs7, %%vs7, %%vs43     	       \n\t" 
  	"xvadddp          %%vs8, %%vs8, %%vs44    	       \n\t" 
  	"xvadddp          %%vs9, %%vs9, %%vs45   	       \n\t" 
  	"xvadddp          %%vs10, %%vs10, %%vs46   	   	   \n\t" 
  	"xvadddp          %%vs11, %%vs11, %%vs47   	       \n\t" 
  	"xvadddp          %%vs12, %%vs12, %%vs48   	       \n\t" 
  	"xvadddp          %%vs13, %%vs13, %%vs49   	       \n\t" 
  	"xvadddp          %%vs14, %%vs14, %%vs50   	       \n\t" 
  	"xvadddp          %%vs15, %%vs15, %%vs51   	       \n\t" 
  	"xvadddp          %%vs16, %%vs16, %%vs52   	       \n\t" 
  	"xvadddp          %%vs17, %%vs17, %%vs53   	       \n\t" 
  	"                                                  \n\t"
  LOADCOL_CMATRIX
  SCALECOL_CMATRIX
  	"                                                 \n\t"
  	"xvadddp          %%vs18, %%vs18, %%vs36   	      \n\t" 
  	"xvadddp          %%vs19, %%vs19, %%vs37   	      \n\t" 
  	"xvadddp          %%vs20, %%vs20, %%vs38   	      \n\t" 
  	"xvadddp          %%vs21, %%vs21, %%vs39   	      \n\t" 
  	"xvadddp          %%vs22, %%vs22, %%vs40   	      \n\t" 
  	"xvadddp          %%vs23, %%vs23, %%vs41   	      \n\t" 
  	"xvadddp          %%vs24, %%vs24, %%vs42   	      \n\t" 
  	"xvadddp          %%vs25, %%vs25, %%vs43   	      \n\t" 
  	"xvadddp          %%vs26, %%vs26, %%vs44          \n\t" 
  	"xvadddp          %%vs27, %%vs27, %%vs45   	      \n\t" 
  	"xvadddp          %%vs28, %%vs28, %%vs46   	      \n\t" 
  	"xvadddp          %%vs29, %%vs29, %%vs47   	      \n\t" 
  	"xvadddp          %%vs30, %%vs30, %%vs48   	      \n\t" 
  	"xvadddp          %%vs31, %%vs31, %%vs49   	      \n\t" 
  	"xvadddp          %%vs32, %%vs32, %%vs50   	      \n\t" 
  	"xvadddp          %%vs33, %%vs33, %%vs51   	      \n\t" 
  	"xvadddp          %%vs34, %%vs34, %%vs52   	      \n\t" 
  	"xvadddp          %%vs35, %%vs35, %%vs53   	      \n\t"
  	"                                                 \n\t"
  	"b                DCOLSTORED                      \n\t"
  	"                                                 \n\t"
  	"                                                 \n\t"
  	"                                                 \n\t"
  	"                                                 \n\t"
  	"                                                 \n\t"
  	"DBETAZERO:                                       \n\t" // beta=0 case
  	"                                                 \n\t" 
  	"cmpwi            %%r0, %%r9, 8                   \n\t" // if rs_c == 8,
  	"beq              DCOLSTORED                      \n\t" // C is col stored
  	"                                                 \n\t"
  	"DGENSTORED:                                      \n\t"
  	"                                                 \n\t"
  	"ld              %%r22, %6                        \n\t" // load c
  	"slwi            %%r12, %%r9, 1                   \n\t"
  	"add             %%r23, %%r22, %%r12              \n\t" // c + rs_c * 2
  	"add             %%r24, %%r23, %%r12              \n\t" // c + rs_c * 4
  	"add             %%r25, %%r24, %%r12              \n\t" // c + rs_c * 6 
  	"add             %%r26, %%r25, %%r12              \n\t" // c + rs_c * 8
  	"add             %%r27, %%r26, %%r12              \n\t" // c + rs_c * 10
  	"                                                 \n\t"
  	"                                                 \n\t"
  	"stxsdx          %%vs0, %%r9, %%r22               \n\t" 
  	"xxswapd         %%vs0, %%vs0		              \n\t" 
  	"stxsdx          %%vs0, 0, %%r22                  \n\t" 
  	"stxsdx          %%vs1, %%r9, %%r23               \n\t" 
  	"xxswapd         %%vs1, %%vs1		              \n\t" 
  	"stxsdx          %%vs1, 0, %%r23                  \n\t" 
  	"stxsdx          %%vs2, %%r9, %%r24               \n\t" 
  	"xxswapd         %%vs2, %%vs2		              \n\t" 
  	"stxsdx          %%vs2, 0, %%r24                  \n\t" 
  	"stxsdx          %%vs3, %%r9, %%r25               \n\t" 
  	"xxswapd         %%vs3, %%vs3		              \n\t" 
  	"stxsdx          %%vs3, 0, %%r25                  \n\t" 
  	"stxsdx          %%vs4, %%r9, %%r26               \n\t" 
  	"xxswapd         %%vs4, %%vs4		              \n\t" 
  	"stxsdx          %%vs4, 0, %%r26                  \n\t" 
  	"stxsdx          %%vs5, %%r9, %%r27               \n\t" 
  	"xxswapd         %%vs5, %%vs5		              \n\t" 
  	"stxsdx          %%vs5, 0, %%r27                  \n\t" 
  	"                                                 \n\t"
 GEN_NEXT_COL_CMATRIX 
  	"                                               \n\t"
  	"stxsdx          %%vs6, %%r9, %%r22             \n\t" 
  	"xxswapd         %%vs6, %%vs6		              \n\t" 
  	"stxsdx          %%vs6, 0, %%r22                \n\t" 
  	"stxsdx          %%vs7, %%r9, %%r23             \n\t" 
  	"xxswapd         %%vs7, %%vs7		              \n\t" 
  	"stxsdx          %%vs7, 0, %%r23                \n\t" 
  	"stxsdx          %%vs8, %%r9, %%r24             \n\t" 
  	"xxswapd         %%vs8, %%vs8		              \n\t" 
  	"stxsdx          %%vs8, 0, %%r24                \n\t" 
  	"stxsdx          %%vs9, %%r9, %%r25             \n\t" 
  	"xxswapd         %%vs9, %%vs9		              \n\t" 
  	"stxsdx          %%vs9, 0, %%r25                \n\t" 
  	"stxsdx          %%vs10, %%r9, %%r26            \n\t" 
  	"xxswapd         %%vs10, %%vs10		          \n\t" 
  	"stxsdx          %%vs10, 0, %%r26               \n\t" 
 	"stxsdx          %%vs11, %%r9, %%r27            \n\t" 
  	"xxswapd         %%vs11, %%vs11		          \n\t" 
  	"stxsdx          %%vs11, 0, %%r27               \n\t" 
  	"                                               \n\t"
 GEN_NEXT_COL_CMATRIX 
  	"                                               \n\t"
  	"stxsdx          %%vs12, %%r9, %%r22            \n\t" 
  	"xxswapd         %%vs12, %%vs12		          \n\t" 
  	"stxsdx          %%vs12, 0, %%r22               \n\t" 
  	"stxsdx          %%vs13, %%r9, %%r23            \n\t" 
  	"xxswapd         %%vs13, %%vs13		          \n\t" 
  	"stxsdx          %%vs13, 0, %%r23               \n\t" 
  	"stxsdx          %%vs14, %%r9, %%r24            \n\t" 
  	"xxswapd         %%vs14, %%vs14		          \n\t" 
  	"stxsdx          %%vs14, 0, %%r24               \n\t" 
  	"stxsdx          %%vs15, %%r9, %%r25            \n\t" 
  	"xxswapd         %%vs15, %%vs15		          \n\t" 
  	"stxsdx          %%vs15, 0, %%r25               \n\t" 
  	"stxsdx          %%vs16, %%r9, %%r26            \n\t" 
  	"xxswapd         %%vs16, %%vs16		          \n\t" 
  	"stxsdx          %%vs16, 0, %%r26               \n\t" 
  	"stxsdx          %%vs17, %%r9, %%r27            \n\t" 
  	"xxswapd         %%vs17, %%vs17		          \n\t" 
  	"stxsdx          %%vs17, 0, %%r27               \n\t" 
  	"                                               \n\t"
 GEN_NEXT_COL_CMATRIX 
  	"                                               \n\t"
  	"stxsdx          %%vs18, %%r9, %%r22            \n\t" 
  	"xxswapd         %%vs18, %%vs18		          \n\t" 
  	"stxsdx          %%vs18, 0, %%r22               \n\t" 
  	"stxsdx          %%vs19, %%r9, %%r23            \n\t" 
  	"xxswapd         %%vs19, %%vs19		          \n\t" 
  	"stxsdx          %%vs19, 0, %%r23               \n\t" 
  	"stxsdx          %%vs20, %%r9, %%r24            \n\t" 
  	"xxswapd         %%vs20, %%vs20		          \n\t" 
  	"stxsdx          %%vs20, 0, %%r24               \n\t" 
  	"stxsdx          %%vs21, %%r9, %%r25            \n\t" 
  	"xxswapd         %%vs21, %%vs21		          \n\t" 
  	"stxsdx          %%vs21, 0, %%r25               \n\t" 
  	"stxsdx          %%vs22, %%r9, %%r26            \n\t" 
  	"xxswapd         %%vs22, %%vs22		          \n\t" 
  	"stxsdx          %%vs22, 0, %%r26               \n\t" 
  	"stxsdx          %%vs23, %%r9, %%r27            \n\t" 
  	"xxswapd         %%vs23, %%vs23		          \n\t" 
  	"stxsdx          %%vs23, 0, %%r27               \n\t" 
  	"                                               \n\t"
 GEN_NEXT_COL_CMATRIX 
  	"                                               \n\t"
  	"stxsdx          %%vs24, %%r9, %%r22            \n\t" 
  	"xxswapd         %%vs24, %%vs24		          \n\t" 
  	"stxsdx          %%vs24, 0, %%r22               \n\t" 
  	"stxsdx          %%vs25, %%r9, %%r23            \n\t" 
  	"xxswapd         %%vs25, %%vs25		          \n\t" 
  	"stxsdx          %%vs25, 0, %%r23               \n\t" 
  	"stxsdx          %%vs26, %%r9, %%r24            \n\t" 
  	"xxswapd         %%vs26, %%vs26		          \n\t" 
  	"stxsdx          %%vs26, 0, %%r24               \n\t" 
  	"stxsdx          %%vs27, %%r9, %%r25            \n\t" 
  	"xxswapd         %%vs27, %%vs27		          \n\t" 
  	"stxsdx          %%vs27, 0, %%r25               \n\t" 
  	"stxsdx          %%vs28, %%r9, %%r26            \n\t" 
  	"xxswapd         %%vs28, %%vs28	              \n\t" 
  	"stxsdx          %%vs28, 0, %%r26               \n\t" 
  	"stxsdx          %%vs29, %%r9, %%r27            \n\t" 
  	"xxswapd         %%vs29, %%vs29		          \n\t" 
  	"stxsdx          %%vs29, 0, %%r27               \n\t" 
  	"                                               \n\t"
 GEN_NEXT_COL_CMATRIX 
  	"                                               \n\t"
  	"stxsdx          %%vs30, %%r9, %%r22            \n\t" 
  	"xxswapd         %%vs30, %%vs30		          \n\t" 
  	"stxsdx          %%vs30, 0, %%r22               \n\t" 
  	"stxsdx          %%vs31, %%r9, %%r23            \n\t" 
  	"xxswapd         %%vs31, %%vs31		          \n\t" 
  	"stxsdx          %%vs31, 0, %%r23               \n\t" 
  	"stxsdx          %%vs32, %%r9, %%r24            \n\t" 
  	"xxswapd         %%vs32, %%vs32		          \n\t" 
  	"stxsdx          %%vs32, 0, %%r24               \n\t" 
  	"stxsdx          %%vs33, %%r9, %%r25            \n\t" 
  	"xxswapd         %%vs33, %%vs33		          \n\t" 
  	"stxsdx          %%vs33, 0, %%r25               \n\t" 
  	"stxsdx          %%vs34, %%r9, %%r26            \n\t" 
  	"xxswapd         %%vs34, %%vs34	              \n\t" 
  	"stxsdx          %%vs34, 0, %%r26               \n\t" 
  	"stxsdx          %%vs35, %%r9, %%r27            \n\t" 
  	"xxswapd         %%vs35, %%vs35		          \n\t" 
  	"stxsdx          %%vs35, 0, %%r27               \n\t"
  	"                                               \n\t"
  	"b               DDONE                          \n\t"
  	"                                               \n\t"
  	"DCOLSTORED:                                    \n\t"
  	"                                               \n\t" // create offset regs
  	"add              %%r17, %%r16, %%r10           \n\t" // c + cs_c
  	"add              %%r18, %%r17, %%r10           \n\t" // c + cs_c * 2 
  	"add              %%r19, %%r18, %%r10           \n\t" // c + cs_c * 3
  	"add              %%r20, %%r19, %%r10           \n\t" // c + cs_c * 4
  	"add              %%r21, %%r20, %%r10           \n\t" // c + cs_c * 5
  	"                                               \n\t"
 COLSTORE_CMATRIX
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
	  "m" (cs_c)/*,   // 8
	  "m" (b_next), // 9
	  "m" (a_next)*/  // 10
	: // register clobber list
  /* unclobberable regs: r2, r3, r4, r5, r6, r13, r14, r15, r30, r31 */
  "r0",  "r7", "r8", "r9",
  "r10", "r12","r16", "r17", "r18", "r19", 
  "r20", "r21", "r22", "r23", "r24", "r25", "r26", "r27", "r28"

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
  , "vs50", "vs51", "vs52", "vs53"
  

  #endif
  );
}
