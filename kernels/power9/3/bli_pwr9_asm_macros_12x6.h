
/*

################################################################################
################################################################################

    MACROS FOR 12x6

vector reg map

		C
------------------
 0  6 12 18 24 30
 1  7 13 19 25 31
 2  8 14 20 26 32
 3  9 15 21 27 33
 4 10 16 22 28 34
 5 11 17 23 29 35

################################################################################
################################################################################

*/


#define ZERO_OUT_VREG \
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
"xxlxor           %%vs35, %%vs35, %%vs35           \n\t" 

#define PRELOAD \
"lxv           %%vs36, 0(%%r7)                  \n\t" \
"lxv           %%vs37, 16(%%r7)                 \n\t" \
"lxv           %%vs38, 32(%%r7)                 \n\t" \
"lxv           %%vs39, 48(%%r7)                 \n\t" \
"lxv           %%vs40, 64(%%r7)                 \n\t" \
"lxv           %%vs41, 80(%%r7)                 \n\t" \
"                                               \n\t" \
"lxv           %%vs48, 0(%%r8)                  \n\t" \
"lxv           %%vs49, 16(%%r8)                 \n\t" \
"lxv           %%vs50, 32(%%r8)                 \n\t" \
"lxv           %%vs51, 48(%%r8)                 \n\t" \
"lxv           %%vs52, 64(%%r8)  	  	          \n\t" \
"lxv           %%vs53, 80(%%r8)	              \n\t"

 
#define A_B_PRODUCT_16 \
"                                               \n\t" \
"lxv       %%vs42, 0(%%r7)                      \n\t" \
"lxv       %%vs43, 16(%%r7)                     \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs0, %%vs36, %%vs48         \n\t" \
"xvmaddadp        %%vs1, %%vs37, %%vs48         \n\t" \
"xvmaddadp        %%vs2, %%vs38, %%vs48         \n\t" \
"xvmaddadp        %%vs3, %%vs39, %%vs48         \n\t" \
"xvmaddadp        %%vs4, %%vs40, %%vs48         \n\t" \
"xvmaddadp        %%vs5, %%vs41, %%vs48         \n\t" \
"                                               \n\t" \
"lxv       %%vs54, 0(%%r8)                      \n\t" \
"lxv       %%vs55, 16(%%r8)                     \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs6, %%vs36, %%vs49         \n\t" \
"xvmaddadp        %%vs7, %%vs37, %%vs49         \n\t" \
"xvmaddadp        %%vs8, %%vs38, %%vs49         \n\t" \
"xvmaddadp        %%vs9, %%vs39, %%vs49         \n\t" \
"xvmaddadp        %%vs10, %%vs40, %%vs49        \n\t" \
"xvmaddadp        %%vs11, %%vs41, %%vs49        \n\t" \
"                                               \n\t" \
"lxv       %%vs44, 32(%%r7)                     \n\t" \
"lxv       %%vs45, 48(%%r7)                     \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs12, %%vs36, %%vs50        \n\t" \
"xvmaddadp        %%vs13, %%vs37, %%vs50        \n\t" \
"xvmaddadp        %%vs14, %%vs38, %%vs50        \n\t" \
"xvmaddadp        %%vs15, %%vs39, %%vs50        \n\t" \
"xvmaddadp        %%vs16, %%vs40, %%vs50        \n\t" \
"xvmaddadp        %%vs17, %%vs41, %%vs50        \n\t" \
"                                               \n\t" \
"lxv       %%vs56, 32(%%r8)                     \n\t" \
"lxv       %%vs57, 48(%%r8)                     \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs18, %%vs36, %%vs51        \n\t" \
"xvmaddadp        %%vs19, %%vs37, %%vs51        \n\t" \
"xvmaddadp        %%vs20, %%vs38, %%vs51        \n\t" \
"xvmaddadp        %%vs21, %%vs39, %%vs51        \n\t" \
"xvmaddadp        %%vs22, %%vs40, %%vs51        \n\t" \
"xvmaddadp        %%vs23, %%vs41, %%vs51        \n\t" \
"                                               \n\t" \
"lxv       %%vs46, 64(%%r7)                     \n\t" \
"lxv       %%vs47, 80(%%r7)                     \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs24, %%vs36, %%vs52        \n\t" \
"xvmaddadp        %%vs25, %%vs37, %%vs52        \n\t" \
"xvmaddadp        %%vs26, %%vs38, %%vs52        \n\t" \
"xvmaddadp        %%vs27, %%vs39, %%vs52        \n\t" \
"xvmaddadp        %%vs28, %%vs40, %%vs52        \n\t" \
"xvmaddadp        %%vs29, %%vs41, %%vs52        \n\t" \
"                                               \n\t" \
"lxv       %%vs58, 64(%%r8)                     \n\t" \
"lxv       %%vs59, 80(%%r8)                     \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs30, %%vs36, %%vs53        \n\t" \
"xvmaddadp        %%vs31, %%vs37, %%vs53        \n\t" \
"xvmaddadp        %%vs32, %%vs38, %%vs53        \n\t" \
"xvmaddadp        %%vs33, %%vs39, %%vs53        \n\t" \
"xvmaddadp        %%vs34, %%vs40, %%vs53        \n\t" \
"xvmaddadp        %%vs35, %%vs41, %%vs53        \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"lxv       %%vs36, 96(%%r7)                     \n\t" \
"lxv       %%vs37, 112(%%r7)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs0, %%vs42, %%vs54         \n\t" \
"xvmaddadp        %%vs1, %%vs43, %%vs54         \n\t" \
"xvmaddadp        %%vs2, %%vs44, %%vs54         \n\t" \
"xvmaddadp        %%vs3, %%vs45, %%vs54         \n\t" \
"xvmaddadp        %%vs4, %%vs46, %%vs54         \n\t" \
"xvmaddadp        %%vs5, %%vs47, %%vs54         \n\t" \
"                                               \n\t" \
"lxv       %%vs48, 96(%%r8)                     \n\t" \
"lxv       %%vs49, 112(%%r8)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs6, %%vs42, %%vs55         \n\t" \
"xvmaddadp        %%vs7, %%vs43, %%vs55         \n\t" \
"xvmaddadp        %%vs8, %%vs44, %%vs55         \n\t" \
"xvmaddadp        %%vs9, %%vs45, %%vs55         \n\t" \
"xvmaddadp        %%vs10, %%vs46, %%vs55        \n\t" \
"xvmaddadp        %%vs11, %%vs47, %%vs55        \n\t" \
"                                               \n\t" \
"lxv       %%vs38, 128(%%r7)                    \n\t" \
"lxv       %%vs39, 144(%%r7)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs12, %%vs42, %%vs56        \n\t" \
"xvmaddadp        %%vs13, %%vs43, %%vs56        \n\t" \
"xvmaddadp        %%vs14, %%vs44, %%vs56        \n\t" \
"xvmaddadp        %%vs15, %%vs45, %%vs56        \n\t" \
"xvmaddadp        %%vs16, %%vs46, %%vs56        \n\t" \
"xvmaddadp        %%vs17, %%vs47, %%vs56        \n\t" \
"                                               \n\t" \
"lxv       %%vs50, 128(%%r8)                    \n\t" \
"lxv       %%vs51, 144(%%r8)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs18, %%vs42, %%vs57        \n\t" \
"xvmaddadp        %%vs19, %%vs43, %%vs57        \n\t" \
"xvmaddadp        %%vs20, %%vs44, %%vs57        \n\t" \
"xvmaddadp        %%vs21, %%vs45, %%vs57        \n\t" \
"xvmaddadp        %%vs22, %%vs46, %%vs57        \n\t" \
"xvmaddadp        %%vs23, %%vs47, %%vs57        \n\t" \
"                                               \n\t" \
"lxv       %%vs40, 160(%%r7)                    \n\t" \
"lxv       %%vs41, 176(%%r7)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs24, %%vs42, %%vs58        \n\t" \
"xvmaddadp        %%vs25, %%vs43, %%vs58        \n\t" \
"xvmaddadp        %%vs26, %%vs44, %%vs58        \n\t" \
"xvmaddadp        %%vs27, %%vs45, %%vs58        \n\t" \
"xvmaddadp        %%vs28, %%vs46, %%vs58        \n\t" \
"xvmaddadp        %%vs29, %%vs47, %%vs58        \n\t" \
"                                               \n\t" \
"lxv       %%vs52, 160(%%r8)                    \n\t" \
"lxv       %%vs53, 176(%%r8)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs30, %%vs42, %%vs59        \n\t" \
"xvmaddadp        %%vs31, %%vs43, %%vs59        \n\t" \
"xvmaddadp        %%vs32, %%vs44, %%vs59        \n\t" \
"xvmaddadp        %%vs33, %%vs45, %%vs59        \n\t" \
"xvmaddadp        %%vs34, %%vs46, %%vs59        \n\t" \
"xvmaddadp        %%vs35, %%vs47, %%vs59        \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"lxv       %%vs42, 192(%%r7)                    \n\t" \
"lxv       %%vs43, 208(%%r7)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs0, %%vs36, %%vs48         \n\t" \
"xvmaddadp        %%vs1, %%vs37, %%vs48         \n\t" \
"xvmaddadp        %%vs2, %%vs38, %%vs48         \n\t" \
"xvmaddadp        %%vs3, %%vs39, %%vs48         \n\t" \
"xvmaddadp        %%vs4, %%vs40, %%vs48         \n\t" \
"xvmaddadp        %%vs5, %%vs41, %%vs48         \n\t" \
"                                               \n\t" \
"lxv       %%vs54, 192(%%r8)                    \n\t" \
"lxv       %%vs55, 208(%%r8)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs6, %%vs36, %%vs49         \n\t" \
"xvmaddadp        %%vs7, %%vs37, %%vs49         \n\t" \
"xvmaddadp        %%vs8, %%vs38, %%vs49         \n\t" \
"xvmaddadp        %%vs9, %%vs39, %%vs49         \n\t" \
"xvmaddadp        %%vs10, %%vs40, %%vs49        \n\t" \
"xvmaddadp        %%vs11, %%vs41, %%vs49        \n\t" \
"                                               \n\t" \
"lxv       %%vs44, 224(%%r7)                    \n\t" \
"lxv       %%vs45, 240(%%r7)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs12, %%vs36, %%vs50        \n\t" \
"xvmaddadp        %%vs13, %%vs37, %%vs50        \n\t" \
"xvmaddadp        %%vs14, %%vs38, %%vs50        \n\t" \
"xvmaddadp        %%vs15, %%vs39, %%vs50        \n\t" \
"xvmaddadp        %%vs16, %%vs40, %%vs50        \n\t" \
"xvmaddadp        %%vs17, %%vs41, %%vs50        \n\t" \
"                                               \n\t" \
"lxv       %%vs56, 224(%%r8)                    \n\t" \
"lxv       %%vs57, 240(%%r8)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs18, %%vs36, %%vs51        \n\t" \
"xvmaddadp        %%vs19, %%vs37, %%vs51        \n\t" \
"xvmaddadp        %%vs20, %%vs38, %%vs51        \n\t" \
"xvmaddadp        %%vs21, %%vs39, %%vs51        \n\t" \
"xvmaddadp        %%vs22, %%vs40, %%vs51        \n\t" \
"xvmaddadp        %%vs23, %%vs41, %%vs51        \n\t" \
"                                               \n\t" \
"lxv       %%vs46, 256(%%r7)                    \n\t" \
"lxv       %%vs47, 272(%%r7)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs24, %%vs36, %%vs52        \n\t" \
"xvmaddadp        %%vs25, %%vs37, %%vs52        \n\t" \
"xvmaddadp        %%vs26, %%vs38, %%vs52        \n\t" \
"xvmaddadp        %%vs27, %%vs39, %%vs52        \n\t" \
"xvmaddadp        %%vs28, %%vs40, %%vs52        \n\t" \
"xvmaddadp        %%vs29, %%vs41, %%vs52        \n\t" \
"                                               \n\t" \
"lxv       %%vs58, 256(%%r8)                    \n\t" \
"lxv       %%vs59, 272(%%r8)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs30, %%vs36, %%vs53        \n\t" \
"xvmaddadp        %%vs31, %%vs37, %%vs53        \n\t" \
"xvmaddadp        %%vs32, %%vs38, %%vs53        \n\t" \
"xvmaddadp        %%vs33, %%vs39, %%vs53        \n\t" \
"xvmaddadp        %%vs34, %%vs40, %%vs53        \n\t" \
"xvmaddadp        %%vs35, %%vs41, %%vs53        \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"lxv       %%vs36, 288(%%r7)                    \n\t" \
"lxv       %%vs37, 304(%%r7)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs0, %%vs42, %%vs54         \n\t" \
"xvmaddadp        %%vs1, %%vs43, %%vs54         \n\t" \
"xvmaddadp        %%vs2, %%vs44, %%vs54         \n\t" \
"xvmaddadp        %%vs3, %%vs45, %%vs54         \n\t" \
"xvmaddadp        %%vs4, %%vs46, %%vs54         \n\t" \
"xvmaddadp        %%vs5, %%vs47, %%vs54         \n\t" \
"                                               \n\t" \
"lxv       %%vs48, 288(%%r8)                    \n\t" \
"lxv       %%vs49, 304(%%r8)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs6, %%vs42, %%vs55         \n\t" \
"xvmaddadp        %%vs7, %%vs43, %%vs55         \n\t" \
"xvmaddadp        %%vs8, %%vs44, %%vs55         \n\t" \
"xvmaddadp        %%vs9, %%vs45, %%vs55         \n\t" \
"xvmaddadp        %%vs10, %%vs46, %%vs55        \n\t" \
"xvmaddadp        %%vs11, %%vs47, %%vs55        \n\t" \
"                                               \n\t" \
"lxv       %%vs38, 320(%%r7)                    \n\t" \
"lxv       %%vs39, 336(%%r7)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs12, %%vs42, %%vs56        \n\t" \
"xvmaddadp        %%vs13, %%vs43, %%vs56        \n\t" \
"xvmaddadp        %%vs14, %%vs44, %%vs56        \n\t" \
"xvmaddadp        %%vs15, %%vs45, %%vs56        \n\t" \
"xvmaddadp        %%vs16, %%vs46, %%vs56        \n\t" \
"xvmaddadp        %%vs17, %%vs47, %%vs56        \n\t" \
"                                               \n\t" \
"lxv       %%vs50, 320(%%r8)                    \n\t" \
"lxv       %%vs51, 336(%%r8)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs18, %%vs42, %%vs57        \n\t" \
"xvmaddadp        %%vs19, %%vs43, %%vs57        \n\t" \
"xvmaddadp        %%vs20, %%vs44, %%vs57        \n\t" \
"xvmaddadp        %%vs21, %%vs45, %%vs57        \n\t" \
"xvmaddadp        %%vs22, %%vs46, %%vs57        \n\t" \
"xvmaddadp        %%vs23, %%vs47, %%vs57        \n\t" \
"                                               \n\t" \
"lxv       %%vs40, 352(%%r7)                    \n\t" \
"lxv       %%vs41, 368(%%r7)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs24, %%vs42, %%vs58        \n\t" \
"xvmaddadp        %%vs25, %%vs43, %%vs58        \n\t" \
"xvmaddadp        %%vs26, %%vs44, %%vs58        \n\t" \
"xvmaddadp        %%vs27, %%vs45, %%vs58        \n\t" \
"xvmaddadp        %%vs28, %%vs46, %%vs58        \n\t" \
"xvmaddadp        %%vs29, %%vs47, %%vs58        \n\t" \
"                                               \n\t" \
"lxv       %%vs52, 352(%%r8)                    \n\t" \
"lxv       %%vs53, 368(%%r8)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs30, %%vs42, %%vs59        \n\t" \
"xvmaddadp        %%vs31, %%vs43, %%vs59        \n\t" \
"xvmaddadp        %%vs32, %%vs44, %%vs59        \n\t" \
"xvmaddadp        %%vs33, %%vs45, %%vs59        \n\t" \
"xvmaddadp        %%vs34, %%vs46, %%vs59        \n\t" \
"xvmaddadp        %%vs35, %%vs47, %%vs59        \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"lxv       %%vs42, 384(%%r7)                    \n\t" \
"lxv       %%vs43, 400(%%r7)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs0, %%vs36, %%vs48         \n\t" \
"xvmaddadp        %%vs1, %%vs37, %%vs48         \n\t" \
"xvmaddadp        %%vs2, %%vs38, %%vs48         \n\t" \
"xvmaddadp        %%vs3, %%vs39, %%vs48         \n\t" \
"xvmaddadp        %%vs4, %%vs40, %%vs48         \n\t" \
"xvmaddadp        %%vs5, %%vs41, %%vs48         \n\t" \
"                                               \n\t" \
"lxv       %%vs54, 384(%%r8)                    \n\t" \
"lxv       %%vs55, 400(%%r8)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs6, %%vs36, %%vs49         \n\t" \
"xvmaddadp        %%vs7, %%vs37, %%vs49         \n\t" \
"xvmaddadp        %%vs8, %%vs38, %%vs49         \n\t" \
"xvmaddadp        %%vs9, %%vs39, %%vs49         \n\t" \
"xvmaddadp        %%vs10, %%vs40, %%vs49        \n\t" \
"xvmaddadp        %%vs11, %%vs41, %%vs49        \n\t" \
"                                               \n\t" \
"lxv       %%vs44, 416(%%r7)                    \n\t" \
"lxv       %%vs45, 432(%%r7)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs12, %%vs36, %%vs50        \n\t" \
"xvmaddadp        %%vs13, %%vs37, %%vs50        \n\t" \
"xvmaddadp        %%vs14, %%vs38, %%vs50        \n\t" \
"xvmaddadp        %%vs15, %%vs39, %%vs50        \n\t" \
"xvmaddadp        %%vs16, %%vs40, %%vs50        \n\t" \
"xvmaddadp        %%vs17, %%vs41, %%vs50        \n\t" \
"                                               \n\t" \
"lxv       %%vs56, 416(%%r8)                    \n\t" \
"lxv       %%vs57, 432(%%r8)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs18, %%vs36, %%vs51        \n\t" \
"xvmaddadp        %%vs19, %%vs37, %%vs51        \n\t" \
"xvmaddadp        %%vs20, %%vs38, %%vs51        \n\t" \
"xvmaddadp        %%vs21, %%vs39, %%vs51        \n\t" \
"xvmaddadp        %%vs22, %%vs40, %%vs51        \n\t" \
"xvmaddadp        %%vs23, %%vs41, %%vs51        \n\t" \
"                                               \n\t" \
"lxv       %%vs46, 448(%%r7)                    \n\t" \
"lxv       %%vs47, 464(%%r7)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs24, %%vs36, %%vs52        \n\t" \
"xvmaddadp        %%vs25, %%vs37, %%vs52        \n\t" \
"xvmaddadp        %%vs26, %%vs38, %%vs52        \n\t" \
"xvmaddadp        %%vs27, %%vs39, %%vs52        \n\t" \
"xvmaddadp        %%vs28, %%vs40, %%vs52        \n\t" \
"xvmaddadp        %%vs29, %%vs41, %%vs52        \n\t" \
"                                               \n\t" \
"lxv       %%vs58, 448(%%r8)                    \n\t" \
"lxv       %%vs59, 464(%%r8)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs30, %%vs36, %%vs53        \n\t" \
"xvmaddadp        %%vs31, %%vs37, %%vs53        \n\t" \
"xvmaddadp        %%vs32, %%vs38, %%vs53        \n\t" \
"xvmaddadp        %%vs33, %%vs39, %%vs53        \n\t" \
"xvmaddadp        %%vs34, %%vs40, %%vs53        \n\t" \
"xvmaddadp        %%vs35, %%vs41, %%vs53        \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"lxv       %%vs36, 480(%%r7)                    \n\t" \
"lxv       %%vs37, 496(%%r7)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs0, %%vs42, %%vs54         \n\t" \
"xvmaddadp        %%vs1, %%vs43, %%vs54         \n\t" \
"xvmaddadp        %%vs2, %%vs44, %%vs54         \n\t" \
"xvmaddadp        %%vs3, %%vs45, %%vs54         \n\t" \
"xvmaddadp        %%vs4, %%vs46, %%vs54         \n\t" \
"xvmaddadp        %%vs5, %%vs47, %%vs54         \n\t" \
"                                               \n\t" \
"lxv       %%vs48, 480(%%r8)                    \n\t" \
"lxv       %%vs49, 496(%%r8)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs6, %%vs42, %%vs55         \n\t" \
"xvmaddadp        %%vs7, %%vs43, %%vs55         \n\t" \
"xvmaddadp        %%vs8, %%vs44, %%vs55         \n\t" \
"xvmaddadp        %%vs9, %%vs45, %%vs55         \n\t" \
"xvmaddadp        %%vs10, %%vs46, %%vs55        \n\t" \
"xvmaddadp        %%vs11, %%vs47, %%vs55        \n\t" \
"                                               \n\t" \
"lxv       %%vs38, 512(%%r7)                    \n\t" \
"lxv       %%vs39, 528(%%r7)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs12, %%vs42, %%vs56        \n\t" \
"xvmaddadp        %%vs13, %%vs43, %%vs56        \n\t" \
"xvmaddadp        %%vs14, %%vs44, %%vs56        \n\t" \
"xvmaddadp        %%vs15, %%vs45, %%vs56        \n\t" \
"xvmaddadp        %%vs16, %%vs46, %%vs56        \n\t" \
"xvmaddadp        %%vs17, %%vs47, %%vs56        \n\t" \
"                                               \n\t" \
"lxv       %%vs50, 512(%%r8)                    \n\t" \
"lxv       %%vs51, 528(%%r8)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs18, %%vs42, %%vs57        \n\t" \
"xvmaddadp        %%vs19, %%vs43, %%vs57        \n\t" \
"xvmaddadp        %%vs20, %%vs44, %%vs57        \n\t" \
"xvmaddadp        %%vs21, %%vs45, %%vs57        \n\t" \
"xvmaddadp        %%vs22, %%vs46, %%vs57        \n\t" \
"xvmaddadp        %%vs23, %%vs47, %%vs57        \n\t" \
"                                               \n\t" \
"lxv       %%vs40, 544(%%r7)                    \n\t" \
"lxv       %%vs41, 560(%%r7)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs24, %%vs42, %%vs58        \n\t" \
"xvmaddadp        %%vs25, %%vs43, %%vs58        \n\t" \
"xvmaddadp        %%vs26, %%vs44, %%vs58        \n\t" \
"xvmaddadp        %%vs27, %%vs45, %%vs58        \n\t" \
"xvmaddadp        %%vs28, %%vs46, %%vs58        \n\t" \
"xvmaddadp        %%vs29, %%vs47, %%vs58        \n\t" \
"                                               \n\t" \
"lxv       %%vs52, 544(%%r8)                    \n\t" \
"lxv       %%vs53, 560(%%r8)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs30, %%vs42, %%vs59        \n\t" \
"xvmaddadp        %%vs31, %%vs43, %%vs59        \n\t" \
"xvmaddadp        %%vs32, %%vs44, %%vs59        \n\t" \
"xvmaddadp        %%vs33, %%vs45, %%vs59        \n\t" \
"xvmaddadp        %%vs34, %%vs46, %%vs59        \n\t" \
"xvmaddadp        %%vs35, %%vs47, %%vs59        \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"lxv       %%vs42, 576(%%r7)                    \n\t" \
"lxv       %%vs43, 592(%%r7)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs0, %%vs36, %%vs48         \n\t" \
"xvmaddadp        %%vs1, %%vs37, %%vs48         \n\t" \
"xvmaddadp        %%vs2, %%vs38, %%vs48         \n\t" \
"xvmaddadp        %%vs3, %%vs39, %%vs48         \n\t" \
"xvmaddadp        %%vs4, %%vs40, %%vs48         \n\t" \
"xvmaddadp        %%vs5, %%vs41, %%vs48         \n\t" \
"                                               \n\t" \
"lxv       %%vs54, 576(%%r8)                    \n\t" \
"lxv       %%vs55, 592(%%r8)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs6, %%vs36, %%vs49         \n\t" \
"xvmaddadp        %%vs7, %%vs37, %%vs49         \n\t" \
"xvmaddadp        %%vs8, %%vs38, %%vs49         \n\t" \
"xvmaddadp        %%vs9, %%vs39, %%vs49         \n\t" \
"xvmaddadp        %%vs10, %%vs40, %%vs49        \n\t" \
"xvmaddadp        %%vs11, %%vs41, %%vs49        \n\t" \
"                                               \n\t" \
"lxv       %%vs44, 608(%%r7)                    \n\t" \
"lxv       %%vs45, 624(%%r7)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs12, %%vs36, %%vs50        \n\t" \
"xvmaddadp        %%vs13, %%vs37, %%vs50        \n\t" \
"xvmaddadp        %%vs14, %%vs38, %%vs50        \n\t" \
"xvmaddadp        %%vs15, %%vs39, %%vs50        \n\t" \
"xvmaddadp        %%vs16, %%vs40, %%vs50        \n\t" \
"xvmaddadp        %%vs17, %%vs41, %%vs50        \n\t" \
"                                               \n\t" \
"lxv       %%vs56, 608(%%r8)                    \n\t" \
"lxv       %%vs57, 624(%%r8)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs18, %%vs36, %%vs51        \n\t" \
"xvmaddadp        %%vs19, %%vs37, %%vs51        \n\t" \
"xvmaddadp        %%vs20, %%vs38, %%vs51        \n\t" \
"xvmaddadp        %%vs21, %%vs39, %%vs51        \n\t" \
"xvmaddadp        %%vs22, %%vs40, %%vs51        \n\t" \
"xvmaddadp        %%vs23, %%vs41, %%vs51        \n\t" \
"                                               \n\t" \
"lxv       %%vs46, 640(%%r7)                    \n\t" \
"lxv       %%vs47, 656(%%r7)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs24, %%vs36, %%vs52        \n\t" \
"xvmaddadp        %%vs25, %%vs37, %%vs52        \n\t" \
"xvmaddadp        %%vs26, %%vs38, %%vs52        \n\t" \
"xvmaddadp        %%vs27, %%vs39, %%vs52        \n\t" \
"xvmaddadp        %%vs28, %%vs40, %%vs52        \n\t" \
"xvmaddadp        %%vs29, %%vs41, %%vs52        \n\t" \
"                                               \n\t" \
"lxv       %%vs58, 640(%%r8)                    \n\t" \
"lxv       %%vs59, 656(%%r8)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs30, %%vs36, %%vs53        \n\t" \
"xvmaddadp        %%vs31, %%vs37, %%vs53        \n\t" \
"xvmaddadp        %%vs32, %%vs38, %%vs53        \n\t" \
"xvmaddadp        %%vs33, %%vs39, %%vs53        \n\t" \
"xvmaddadp        %%vs34, %%vs40, %%vs53        \n\t" \
"xvmaddadp        %%vs35, %%vs41, %%vs53        \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"lxv       %%vs36, 672(%%r7)                    \n\t" \
"lxv       %%vs37, 688(%%r7)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs0, %%vs42, %%vs54         \n\t" \
"xvmaddadp        %%vs1, %%vs43, %%vs54         \n\t" \
"xvmaddadp        %%vs2, %%vs44, %%vs54         \n\t" \
"xvmaddadp        %%vs3, %%vs45, %%vs54         \n\t" \
"xvmaddadp        %%vs4, %%vs46, %%vs54         \n\t" \
"xvmaddadp        %%vs5, %%vs47, %%vs54         \n\t" \
"                                               \n\t" \
"lxv       %%vs48, 672(%%r8)                    \n\t" \
"lxv       %%vs49, 688(%%r8)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs6, %%vs42, %%vs55         \n\t" \
"xvmaddadp        %%vs7, %%vs43, %%vs55         \n\t" \
"xvmaddadp        %%vs8, %%vs44, %%vs55         \n\t" \
"xvmaddadp        %%vs9, %%vs45, %%vs55         \n\t" \
"xvmaddadp        %%vs10, %%vs46, %%vs55        \n\t" \
"xvmaddadp        %%vs11, %%vs47, %%vs55        \n\t" \
"                                               \n\t" \
"lxv       %%vs38, 704(%%r7)                    \n\t" \
"lxv       %%vs39, 720(%%r7)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs12, %%vs42, %%vs56        \n\t" \
"xvmaddadp        %%vs13, %%vs43, %%vs56        \n\t" \
"xvmaddadp        %%vs14, %%vs44, %%vs56        \n\t" \
"xvmaddadp        %%vs15, %%vs45, %%vs56        \n\t" \
"xvmaddadp        %%vs16, %%vs46, %%vs56        \n\t" \
"xvmaddadp        %%vs17, %%vs47, %%vs56        \n\t" \
"                                               \n\t" \
"lxv       %%vs50, 704(%%r8)                    \n\t" \
"lxv       %%vs51, 720(%%r8)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs18, %%vs42, %%vs57        \n\t" \
"xvmaddadp        %%vs19, %%vs43, %%vs57        \n\t" \
"xvmaddadp        %%vs20, %%vs44, %%vs57        \n\t" \
"xvmaddadp        %%vs21, %%vs45, %%vs57        \n\t" \
"xvmaddadp        %%vs22, %%vs46, %%vs57        \n\t" \
"xvmaddadp        %%vs23, %%vs47, %%vs57        \n\t" \
"                                               \n\t" \
"lxv       %%vs40, 736(%%r7)                    \n\t" \
"lxv       %%vs41, 752(%%r7)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs24, %%vs42, %%vs58        \n\t" \
"xvmaddadp        %%vs25, %%vs43, %%vs58        \n\t" \
"xvmaddadp        %%vs26, %%vs44, %%vs58        \n\t" \
"xvmaddadp        %%vs27, %%vs45, %%vs58        \n\t" \
"xvmaddadp        %%vs28, %%vs46, %%vs58        \n\t" \
"xvmaddadp        %%vs29, %%vs47, %%vs58        \n\t" \
"                                               \n\t" \
"lxv       %%vs52, 736(%%r8)                    \n\t" \
"lxv       %%vs53, 752(%%r8)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs30, %%vs42, %%vs59        \n\t" \
"xvmaddadp        %%vs31, %%vs43, %%vs59        \n\t" \
"xvmaddadp        %%vs32, %%vs44, %%vs59        \n\t" \
"xvmaddadp        %%vs33, %%vs45, %%vs59        \n\t" \
"xvmaddadp        %%vs34, %%vs46, %%vs59        \n\t" \
"xvmaddadp        %%vs35, %%vs47, %%vs59        \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"lxv       %%vs42, 768(%%r7)                    \n\t" \
"lxv       %%vs43, 784(%%r7)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs0, %%vs36, %%vs48         \n\t" \
"xvmaddadp        %%vs1, %%vs37, %%vs48         \n\t" \
"xvmaddadp        %%vs2, %%vs38, %%vs48         \n\t" \
"xvmaddadp        %%vs3, %%vs39, %%vs48         \n\t" \
"xvmaddadp        %%vs4, %%vs40, %%vs48         \n\t" \
"xvmaddadp        %%vs5, %%vs41, %%vs48         \n\t" \
"                                               \n\t" \
"lxv       %%vs54, 768(%%r8)                    \n\t" \
"lxv       %%vs55, 784(%%r8)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs6, %%vs36, %%vs49         \n\t" \
"xvmaddadp        %%vs7, %%vs37, %%vs49         \n\t" \
"xvmaddadp        %%vs8, %%vs38, %%vs49         \n\t" \
"xvmaddadp        %%vs9, %%vs39, %%vs49         \n\t" \
"xvmaddadp        %%vs10, %%vs40, %%vs49        \n\t" \
"xvmaddadp        %%vs11, %%vs41, %%vs49        \n\t" \
"                                               \n\t" \
"lxv       %%vs44, 800(%%r7)                    \n\t" \
"lxv       %%vs45, 816(%%r7)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs12, %%vs36, %%vs50        \n\t" \
"xvmaddadp        %%vs13, %%vs37, %%vs50        \n\t" \
"xvmaddadp        %%vs14, %%vs38, %%vs50        \n\t" \
"xvmaddadp        %%vs15, %%vs39, %%vs50        \n\t" \
"xvmaddadp        %%vs16, %%vs40, %%vs50        \n\t" \
"xvmaddadp        %%vs17, %%vs41, %%vs50        \n\t" \
"                                               \n\t" \
"lxv       %%vs56, 800(%%r8)                    \n\t" \
"lxv       %%vs57, 816(%%r8)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs18, %%vs36, %%vs51        \n\t" \
"xvmaddadp        %%vs19, %%vs37, %%vs51        \n\t" \
"xvmaddadp        %%vs20, %%vs38, %%vs51        \n\t" \
"xvmaddadp        %%vs21, %%vs39, %%vs51        \n\t" \
"xvmaddadp        %%vs22, %%vs40, %%vs51        \n\t" \
"xvmaddadp        %%vs23, %%vs41, %%vs51        \n\t" \
"                                               \n\t" \
"lxv       %%vs46, 832(%%r7)                    \n\t" \
"lxv       %%vs47, 848(%%r7)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs24, %%vs36, %%vs52        \n\t" \
"xvmaddadp        %%vs25, %%vs37, %%vs52        \n\t" \
"xvmaddadp        %%vs26, %%vs38, %%vs52        \n\t" \
"xvmaddadp        %%vs27, %%vs39, %%vs52        \n\t" \
"xvmaddadp        %%vs28, %%vs40, %%vs52        \n\t" \
"xvmaddadp        %%vs29, %%vs41, %%vs52        \n\t" \
"                                               \n\t" \
"lxv       %%vs58, 832(%%r8)                    \n\t" \
"lxv       %%vs59, 848(%%r8)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs30, %%vs36, %%vs53        \n\t" \
"xvmaddadp        %%vs31, %%vs37, %%vs53        \n\t" \
"xvmaddadp        %%vs32, %%vs38, %%vs53        \n\t" \
"xvmaddadp        %%vs33, %%vs39, %%vs53        \n\t" \
"xvmaddadp        %%vs34, %%vs40, %%vs53        \n\t" \
"xvmaddadp        %%vs35, %%vs41, %%vs53        \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"lxv       %%vs36, 864(%%r7)                    \n\t" \
"lxv       %%vs37, 880(%%r7)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs0, %%vs42, %%vs54         \n\t" \
"xvmaddadp        %%vs1, %%vs43, %%vs54         \n\t" \
"xvmaddadp        %%vs2, %%vs44, %%vs54         \n\t" \
"xvmaddadp        %%vs3, %%vs45, %%vs54         \n\t" \
"xvmaddadp        %%vs4, %%vs46, %%vs54         \n\t" \
"xvmaddadp        %%vs5, %%vs47, %%vs54         \n\t" \
"                                               \n\t" \
"lxv       %%vs48, 864(%%r8)                    \n\t" \
"lxv       %%vs49, 880(%%r8)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs6, %%vs42, %%vs55         \n\t" \
"xvmaddadp        %%vs7, %%vs43, %%vs55         \n\t" \
"xvmaddadp        %%vs8, %%vs44, %%vs55         \n\t" \
"xvmaddadp        %%vs9, %%vs45, %%vs55         \n\t" \
"xvmaddadp        %%vs10, %%vs46, %%vs55        \n\t" \
"xvmaddadp        %%vs11, %%vs47, %%vs55        \n\t" \
"                                               \n\t" \
"lxv       %%vs38, 896(%%r7)                    \n\t" \
"lxv       %%vs39, 912(%%r7)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs12, %%vs42, %%vs56        \n\t" \
"xvmaddadp        %%vs13, %%vs43, %%vs56        \n\t" \
"xvmaddadp        %%vs14, %%vs44, %%vs56        \n\t" \
"xvmaddadp        %%vs15, %%vs45, %%vs56        \n\t" \
"xvmaddadp        %%vs16, %%vs46, %%vs56        \n\t" \
"xvmaddadp        %%vs17, %%vs47, %%vs56        \n\t" \
"                                               \n\t" \
"lxv       %%vs50, 896(%%r8)                    \n\t" \
"lxv       %%vs51, 912(%%r8)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs18, %%vs42, %%vs57        \n\t" \
"xvmaddadp        %%vs19, %%vs43, %%vs57        \n\t" \
"xvmaddadp        %%vs20, %%vs44, %%vs57        \n\t" \
"xvmaddadp        %%vs21, %%vs45, %%vs57        \n\t" \
"xvmaddadp        %%vs22, %%vs46, %%vs57        \n\t" \
"xvmaddadp        %%vs23, %%vs47, %%vs57        \n\t" \
"                                               \n\t" \
"lxv       %%vs40, 928(%%r7)                    \n\t" \
"lxv       %%vs41, 944(%%r7)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs24, %%vs42, %%vs58        \n\t" \
"xvmaddadp        %%vs25, %%vs43, %%vs58        \n\t" \
"xvmaddadp        %%vs26, %%vs44, %%vs58        \n\t" \
"xvmaddadp        %%vs27, %%vs45, %%vs58        \n\t" \
"xvmaddadp        %%vs28, %%vs46, %%vs58        \n\t" \
"xvmaddadp        %%vs29, %%vs47, %%vs58        \n\t" \
"                                               \n\t" \
"lxv       %%vs52, 928(%%r8)                    \n\t" \
"lxv       %%vs53, 944(%%r8)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs30, %%vs42, %%vs59        \n\t" \
"xvmaddadp        %%vs31, %%vs43, %%vs59        \n\t" \
"xvmaddadp        %%vs32, %%vs44, %%vs59        \n\t" \
"xvmaddadp        %%vs33, %%vs45, %%vs59        \n\t" \
"xvmaddadp        %%vs34, %%vs46, %%vs59        \n\t" \
"xvmaddadp        %%vs35, %%vs47, %%vs59        \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"lxv       %%vs42, 960(%%r7)                    \n\t" \
"lxv       %%vs43, 976(%%r7)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs0, %%vs36, %%vs48         \n\t" \
"xvmaddadp        %%vs1, %%vs37, %%vs48         \n\t" \
"xvmaddadp        %%vs2, %%vs38, %%vs48         \n\t" \
"xvmaddadp        %%vs3, %%vs39, %%vs48         \n\t" \
"xvmaddadp        %%vs4, %%vs40, %%vs48         \n\t" \
"xvmaddadp        %%vs5, %%vs41, %%vs48         \n\t" \
"                                               \n\t" \
"lxv       %%vs54, 960(%%r8)                    \n\t" \
"lxv       %%vs55, 976(%%r8)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs6, %%vs36, %%vs49         \n\t" \
"xvmaddadp        %%vs7, %%vs37, %%vs49         \n\t" \
"xvmaddadp        %%vs8, %%vs38, %%vs49         \n\t" \
"xvmaddadp        %%vs9, %%vs39, %%vs49         \n\t" \
"xvmaddadp        %%vs10, %%vs40, %%vs49        \n\t" \
"xvmaddadp        %%vs11, %%vs41, %%vs49        \n\t" \
"                                               \n\t" \
"lxv       %%vs44, 992(%%r7)                    \n\t" \
"lxv       %%vs45, 1008(%%r7)                   \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs12, %%vs36, %%vs50        \n\t" \
"xvmaddadp        %%vs13, %%vs37, %%vs50        \n\t" \
"xvmaddadp        %%vs14, %%vs38, %%vs50        \n\t" \
"xvmaddadp        %%vs15, %%vs39, %%vs50        \n\t" \
"xvmaddadp        %%vs16, %%vs40, %%vs50        \n\t" \
"xvmaddadp        %%vs17, %%vs41, %%vs50        \n\t" \
"                                               \n\t" \
"lxv       %%vs56, 992(%%r8)                    \n\t" \
"lxv       %%vs57, 1008(%%r8)                   \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs18, %%vs36, %%vs51        \n\t" \
"xvmaddadp        %%vs19, %%vs37, %%vs51        \n\t" \
"xvmaddadp        %%vs20, %%vs38, %%vs51        \n\t" \
"xvmaddadp        %%vs21, %%vs39, %%vs51        \n\t" \
"xvmaddadp        %%vs22, %%vs40, %%vs51        \n\t" \
"xvmaddadp        %%vs23, %%vs41, %%vs51        \n\t" \
"                                               \n\t" \
"lxv       %%vs46, 1024(%%r7)                   \n\t" \
"lxv       %%vs47, 1040(%%r7)                   \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs24, %%vs36, %%vs52        \n\t" \
"xvmaddadp        %%vs25, %%vs37, %%vs52        \n\t" \
"xvmaddadp        %%vs26, %%vs38, %%vs52        \n\t" \
"xvmaddadp        %%vs27, %%vs39, %%vs52        \n\t" \
"xvmaddadp        %%vs28, %%vs40, %%vs52        \n\t" \
"xvmaddadp        %%vs29, %%vs41, %%vs52        \n\t" \
"                                               \n\t" \
"lxv       %%vs58, 1024(%%r8)                   \n\t" \
"lxv       %%vs59, 1040(%%r8)                   \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs30, %%vs36, %%vs53        \n\t" \
"xvmaddadp        %%vs31, %%vs37, %%vs53        \n\t" \
"xvmaddadp        %%vs32, %%vs38, %%vs53        \n\t" \
"xvmaddadp        %%vs33, %%vs39, %%vs53        \n\t" \
"xvmaddadp        %%vs34, %%vs40, %%vs53        \n\t" \
"xvmaddadp        %%vs35, %%vs41, %%vs53        \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"lxv       %%vs36, 1056(%%r7)                   \n\t" \
"lxv       %%vs37, 1072(%%r7)                   \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs0, %%vs42, %%vs54         \n\t" \
"xvmaddadp        %%vs1, %%vs43, %%vs54         \n\t" \
"xvmaddadp        %%vs2, %%vs44, %%vs54         \n\t" \
"xvmaddadp        %%vs3, %%vs45, %%vs54         \n\t" \
"xvmaddadp        %%vs4, %%vs46, %%vs54         \n\t" \
"xvmaddadp        %%vs5, %%vs47, %%vs54         \n\t" \
"                                               \n\t" \
"lxv       %%vs48, 1056(%%r8)                   \n\t" \
"lxv       %%vs49, 1072(%%r8)                   \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs6, %%vs42, %%vs55         \n\t" \
"xvmaddadp        %%vs7, %%vs43, %%vs55         \n\t" \
"xvmaddadp        %%vs8, %%vs44, %%vs55         \n\t" \
"xvmaddadp        %%vs9, %%vs45, %%vs55         \n\t" \
"xvmaddadp        %%vs10, %%vs46, %%vs55        \n\t" \
"xvmaddadp        %%vs11, %%vs47, %%vs55        \n\t" \
"                                               \n\t" \
"lxv       %%vs38, 1088(%%r7)                   \n\t" \
"lxv       %%vs39, 1104(%%r7)                   \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs12, %%vs42, %%vs56        \n\t" \
"xvmaddadp        %%vs13, %%vs43, %%vs56        \n\t" \
"xvmaddadp        %%vs14, %%vs44, %%vs56        \n\t" \
"xvmaddadp        %%vs15, %%vs45, %%vs56        \n\t" \
"xvmaddadp        %%vs16, %%vs46, %%vs56        \n\t" \
"xvmaddadp        %%vs17, %%vs47, %%vs56        \n\t" \
"                                               \n\t" \
"lxv       %%vs50, 1088(%%r8)                   \n\t" \
"lxv       %%vs51, 1104(%%r8)                   \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs18, %%vs42, %%vs57        \n\t" \
"xvmaddadp        %%vs19, %%vs43, %%vs57        \n\t" \
"xvmaddadp        %%vs20, %%vs44, %%vs57        \n\t" \
"xvmaddadp        %%vs21, %%vs45, %%vs57        \n\t" \
"xvmaddadp        %%vs22, %%vs46, %%vs57        \n\t" \
"xvmaddadp        %%vs23, %%vs47, %%vs57        \n\t" \
"                                               \n\t" \
"lxv       %%vs40, 1120(%%r7)                   \n\t" \
"lxv       %%vs41, 1136(%%r7)                   \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs24, %%vs42, %%vs58        \n\t" \
"xvmaddadp        %%vs25, %%vs43, %%vs58        \n\t" \
"xvmaddadp        %%vs26, %%vs44, %%vs58        \n\t" \
"xvmaddadp        %%vs27, %%vs45, %%vs58        \n\t" \
"xvmaddadp        %%vs28, %%vs46, %%vs58        \n\t" \
"xvmaddadp        %%vs29, %%vs47, %%vs58        \n\t" \
"                                               \n\t" \
"lxv       %%vs52, 1120(%%r8)                   \n\t" \
"lxv       %%vs53, 1136(%%r8)                   \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs30, %%vs42, %%vs59        \n\t" \
"xvmaddadp        %%vs31, %%vs43, %%vs59        \n\t" \
"xvmaddadp        %%vs32, %%vs44, %%vs59        \n\t" \
"xvmaddadp        %%vs33, %%vs45, %%vs59        \n\t" \
"xvmaddadp        %%vs34, %%vs46, %%vs59        \n\t" \
"xvmaddadp        %%vs35, %%vs47, %%vs59        \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"lxv       %%vs42, 1152(%%r7)                   \n\t" \
"lxv       %%vs43, 1168(%%r7)                   \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs0, %%vs36, %%vs48         \n\t" \
"xvmaddadp        %%vs1, %%vs37, %%vs48         \n\t" \
"xvmaddadp        %%vs2, %%vs38, %%vs48         \n\t" \
"xvmaddadp        %%vs3, %%vs39, %%vs48         \n\t" \
"xvmaddadp        %%vs4, %%vs40, %%vs48         \n\t" \
"xvmaddadp        %%vs5, %%vs41, %%vs48         \n\t" \
"                                               \n\t" \
"lxv       %%vs54, 1152(%%r8)                   \n\t" \
"lxv       %%vs55, 1168(%%r8)                   \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs6, %%vs36, %%vs49         \n\t" \
"xvmaddadp        %%vs7, %%vs37, %%vs49         \n\t" \
"xvmaddadp        %%vs8, %%vs38, %%vs49         \n\t" \
"xvmaddadp        %%vs9, %%vs39, %%vs49         \n\t" \
"xvmaddadp        %%vs10, %%vs40, %%vs49        \n\t" \
"xvmaddadp        %%vs11, %%vs41, %%vs49        \n\t" \
"                                               \n\t" \
"lxv       %%vs44, 1184(%%r7)                   \n\t" \
"lxv       %%vs45, 1200(%%r7)                   \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs12, %%vs36, %%vs50        \n\t" \
"xvmaddadp        %%vs13, %%vs37, %%vs50        \n\t" \
"xvmaddadp        %%vs14, %%vs38, %%vs50        \n\t" \
"xvmaddadp        %%vs15, %%vs39, %%vs50        \n\t" \
"xvmaddadp        %%vs16, %%vs40, %%vs50        \n\t" \
"xvmaddadp        %%vs17, %%vs41, %%vs50        \n\t" \
"                                               \n\t" \
"lxv       %%vs56, 1184(%%r8)                   \n\t" \
"lxv       %%vs57, 1200(%%r8)                   \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs18, %%vs36, %%vs51        \n\t" \
"xvmaddadp        %%vs19, %%vs37, %%vs51        \n\t" \
"xvmaddadp        %%vs20, %%vs38, %%vs51        \n\t" \
"xvmaddadp        %%vs21, %%vs39, %%vs51        \n\t" \
"xvmaddadp        %%vs22, %%vs40, %%vs51        \n\t" \
"xvmaddadp        %%vs23, %%vs41, %%vs51        \n\t" \
"                                               \n\t" \
"lxv       %%vs46, 1216(%%r7)                   \n\t" \
"lxv       %%vs47, 1232(%%r7)                   \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs24, %%vs36, %%vs52        \n\t" \
"xvmaddadp        %%vs25, %%vs37, %%vs52        \n\t" \
"xvmaddadp        %%vs26, %%vs38, %%vs52        \n\t" \
"xvmaddadp        %%vs27, %%vs39, %%vs52        \n\t" \
"xvmaddadp        %%vs28, %%vs40, %%vs52        \n\t" \
"xvmaddadp        %%vs29, %%vs41, %%vs52        \n\t" \
"                                               \n\t" \
"lxv       %%vs58, 1216(%%r8)                   \n\t" \
"lxv       %%vs59, 1232(%%r8)                   \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs30, %%vs36, %%vs53        \n\t" \
"xvmaddadp        %%vs31, %%vs37, %%vs53        \n\t" \
"xvmaddadp        %%vs32, %%vs38, %%vs53        \n\t" \
"xvmaddadp        %%vs33, %%vs39, %%vs53        \n\t" \
"xvmaddadp        %%vs34, %%vs40, %%vs53        \n\t" \
"xvmaddadp        %%vs35, %%vs41, %%vs53        \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"lxv       %%vs36, 1248(%%r7)                   \n\t" \
"lxv       %%vs37, 1264(%%r7)                   \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs0, %%vs42, %%vs54         \n\t" \
"xvmaddadp        %%vs1, %%vs43, %%vs54         \n\t" \
"xvmaddadp        %%vs2, %%vs44, %%vs54         \n\t" \
"xvmaddadp        %%vs3, %%vs45, %%vs54         \n\t" \
"xvmaddadp        %%vs4, %%vs46, %%vs54         \n\t" \
"xvmaddadp        %%vs5, %%vs47, %%vs54         \n\t" \
"                                               \n\t" \
"lxv       %%vs48, 1248(%%r8)                   \n\t" \
"lxv       %%vs49, 1264(%%r8)                   \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs6, %%vs42, %%vs55         \n\t" \
"xvmaddadp        %%vs7, %%vs43, %%vs55         \n\t" \
"xvmaddadp        %%vs8, %%vs44, %%vs55         \n\t" \
"xvmaddadp        %%vs9, %%vs45, %%vs55         \n\t" \
"xvmaddadp        %%vs10, %%vs46, %%vs55        \n\t" \
"xvmaddadp        %%vs11, %%vs47, %%vs55        \n\t" \
"                                               \n\t" \
"lxv       %%vs38, 1280(%%r7)                   \n\t" \
"lxv       %%vs39, 1296(%%r7)                   \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs12, %%vs42, %%vs56        \n\t" \
"xvmaddadp        %%vs13, %%vs43, %%vs56        \n\t" \
"xvmaddadp        %%vs14, %%vs44, %%vs56        \n\t" \
"xvmaddadp        %%vs15, %%vs45, %%vs56        \n\t" \
"xvmaddadp        %%vs16, %%vs46, %%vs56        \n\t" \
"xvmaddadp        %%vs17, %%vs47, %%vs56        \n\t" \
"                                               \n\t" \
"lxv       %%vs50, 1280(%%r8)                   \n\t" \
"lxv       %%vs51, 1296(%%r8)                   \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs18, %%vs42, %%vs57        \n\t" \
"xvmaddadp        %%vs19, %%vs43, %%vs57        \n\t" \
"xvmaddadp        %%vs20, %%vs44, %%vs57        \n\t" \
"xvmaddadp        %%vs21, %%vs45, %%vs57        \n\t" \
"xvmaddadp        %%vs22, %%vs46, %%vs57        \n\t" \
"xvmaddadp        %%vs23, %%vs47, %%vs57        \n\t" \
"                                               \n\t" \
"lxv       %%vs40, 1312(%%r7)                   \n\t" \
"lxv       %%vs41, 1328(%%r7)                   \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs24, %%vs42, %%vs58        \n\t" \
"xvmaddadp        %%vs25, %%vs43, %%vs58        \n\t" \
"xvmaddadp        %%vs26, %%vs44, %%vs58        \n\t" \
"xvmaddadp        %%vs27, %%vs45, %%vs58        \n\t" \
"xvmaddadp        %%vs28, %%vs46, %%vs58        \n\t" \
"xvmaddadp        %%vs29, %%vs47, %%vs58        \n\t" \
"                                               \n\t" \
"lxv       %%vs52, 1312(%%r8)                   \n\t" \
"lxv       %%vs53, 1328(%%r8)                   \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs30, %%vs42, %%vs59        \n\t" \
"xvmaddadp        %%vs31, %%vs43, %%vs59        \n\t" \
"xvmaddadp        %%vs32, %%vs44, %%vs59        \n\t" \
"xvmaddadp        %%vs33, %%vs45, %%vs59        \n\t" \
"xvmaddadp        %%vs34, %%vs46, %%vs59        \n\t" \
"xvmaddadp        %%vs35, %%vs47, %%vs59        \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"lxv       %%vs42, 1344(%%r7)                   \n\t" \
"lxv       %%vs43, 1360(%%r7)                   \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs0, %%vs36, %%vs48         \n\t" \
"xvmaddadp        %%vs1, %%vs37, %%vs48         \n\t" \
"xvmaddadp        %%vs2, %%vs38, %%vs48         \n\t" \
"xvmaddadp        %%vs3, %%vs39, %%vs48         \n\t" \
"xvmaddadp        %%vs4, %%vs40, %%vs48         \n\t" \
"xvmaddadp        %%vs5, %%vs41, %%vs48         \n\t" \
"                                               \n\t" \
"lxv       %%vs54, 1344(%%r8)                   \n\t" \
"lxv       %%vs55, 1360(%%r8)                   \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs6, %%vs36, %%vs49         \n\t" \
"xvmaddadp        %%vs7, %%vs37, %%vs49         \n\t" \
"xvmaddadp        %%vs8, %%vs38, %%vs49         \n\t" \
"xvmaddadp        %%vs9, %%vs39, %%vs49         \n\t" \
"xvmaddadp        %%vs10, %%vs40, %%vs49        \n\t" \
"xvmaddadp        %%vs11, %%vs41, %%vs49        \n\t" \
"                                               \n\t" \
"lxv       %%vs44, 1376(%%r7)                   \n\t" \
"lxv       %%vs45, 1392(%%r7)                   \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs12, %%vs36, %%vs50        \n\t" \
"xvmaddadp        %%vs13, %%vs37, %%vs50        \n\t" \
"xvmaddadp        %%vs14, %%vs38, %%vs50        \n\t" \
"xvmaddadp        %%vs15, %%vs39, %%vs50        \n\t" \
"xvmaddadp        %%vs16, %%vs40, %%vs50        \n\t" \
"xvmaddadp        %%vs17, %%vs41, %%vs50        \n\t" \
"                                               \n\t" \
"lxv       %%vs56, 1376(%%r8)                   \n\t" \
"lxv       %%vs57, 1392(%%r8)                   \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs18, %%vs36, %%vs51        \n\t" \
"xvmaddadp        %%vs19, %%vs37, %%vs51        \n\t" \
"xvmaddadp        %%vs20, %%vs38, %%vs51        \n\t" \
"xvmaddadp        %%vs21, %%vs39, %%vs51        \n\t" \
"xvmaddadp        %%vs22, %%vs40, %%vs51        \n\t" \
"xvmaddadp        %%vs23, %%vs41, %%vs51        \n\t" \
"                                               \n\t" \
"lxv       %%vs46, 1408(%%r7)                   \n\t" \
"lxv       %%vs47, 1424(%%r7)                   \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs24, %%vs36, %%vs52        \n\t" \
"xvmaddadp        %%vs25, %%vs37, %%vs52        \n\t" \
"xvmaddadp        %%vs26, %%vs38, %%vs52        \n\t" \
"xvmaddadp        %%vs27, %%vs39, %%vs52        \n\t" \
"xvmaddadp        %%vs28, %%vs40, %%vs52        \n\t" \
"xvmaddadp        %%vs29, %%vs41, %%vs52        \n\t" \
"                                               \n\t" \
"lxv       %%vs58, 1408(%%r8)                   \n\t" \
"lxv       %%vs59, 1424(%%r8)                   \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs30, %%vs36, %%vs53        \n\t" \
"xvmaddadp        %%vs31, %%vs37, %%vs53        \n\t" \
"xvmaddadp        %%vs32, %%vs38, %%vs53        \n\t" \
"xvmaddadp        %%vs33, %%vs39, %%vs53        \n\t" \
"xvmaddadp        %%vs34, %%vs40, %%vs53        \n\t" \
"xvmaddadp        %%vs35, %%vs41, %%vs53        \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs0, %%vs42, %%vs54         \n\t" \
"xvmaddadp        %%vs1, %%vs43, %%vs54         \n\t" \
"xvmaddadp        %%vs2, %%vs44, %%vs54         \n\t" \
"xvmaddadp        %%vs3, %%vs45, %%vs54         \n\t" \
"xvmaddadp        %%vs4, %%vs46, %%vs54         \n\t" \
"xvmaddadp        %%vs5, %%vs47, %%vs54         \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs6, %%vs42, %%vs55         \n\t" \
"xvmaddadp        %%vs7, %%vs43, %%vs55         \n\t" \
"xvmaddadp        %%vs8, %%vs44, %%vs55         \n\t" \
"xvmaddadp        %%vs9, %%vs45, %%vs55         \n\t" \
"xvmaddadp        %%vs10, %%vs46, %%vs55        \n\t" \
"xvmaddadp        %%vs11, %%vs47, %%vs55        \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs12, %%vs42, %%vs56        \n\t" \
"xvmaddadp        %%vs13, %%vs43, %%vs56        \n\t" \
"xvmaddadp        %%vs14, %%vs44, %%vs56        \n\t" \
"xvmaddadp        %%vs15, %%vs45, %%vs56        \n\t" \
"xvmaddadp        %%vs16, %%vs46, %%vs56        \n\t" \
"xvmaddadp        %%vs17, %%vs47, %%vs56        \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs18, %%vs42, %%vs57        \n\t" \
"xvmaddadp        %%vs19, %%vs43, %%vs57        \n\t" \
"xvmaddadp        %%vs20, %%vs44, %%vs57        \n\t" \
"xvmaddadp        %%vs21, %%vs45, %%vs57        \n\t" \
"xvmaddadp        %%vs22, %%vs46, %%vs57        \n\t" \
"xvmaddadp        %%vs23, %%vs47, %%vs57        \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs24, %%vs42, %%vs58        \n\t" \
"xvmaddadp        %%vs25, %%vs43, %%vs58        \n\t" \
"xvmaddadp        %%vs26, %%vs44, %%vs58        \n\t" \
"xvmaddadp        %%vs27, %%vs45, %%vs58        \n\t" \
"xvmaddadp        %%vs28, %%vs46, %%vs58        \n\t" \
"xvmaddadp        %%vs29, %%vs47, %%vs58        \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs30, %%vs42, %%vs59        \n\t" \
"xvmaddadp        %%vs31, %%vs43, %%vs59        \n\t" \
"xvmaddadp        %%vs32, %%vs44, %%vs59        \n\t" \
"xvmaddadp        %%vs33, %%vs45, %%vs59        \n\t" \
"xvmaddadp        %%vs34, %%vs46, %%vs59        \n\t" \
"xvmaddadp        %%vs35, %%vs47, %%vs59        \n\t" \
"                                               \n\t" \
"lxv       %%vs36, 1440(%%r7)                   \n\t" \
"lxv       %%vs37, 1456(%%r7)                   \n\t" \
"                                               \n\t" \
"lxv       %%vs48, 1440(%%r8)                   \n\t" \
"lxv       %%vs49, 1456(%%r8)                   \n\t" \
"                                               \n\t" \
"lxv       %%vs38, 1472(%%r7)                   \n\t" \
"lxv       %%vs39, 1488(%%r7)                   \n\t" \
"                                               \n\t" \
"lxv       %%vs50, 1472(%%r8)                   \n\t" \
"lxv       %%vs51, 1488(%%r8)                   \n\t" \
"                                               \n\t" \
"lxv       %%vs40, 1504(%%r7)                   \n\t" \
"lxv       %%vs41, 1520(%%r7)                   \n\t" \
"                                               \n\t" \
"lxv       %%vs52, 1504(%%r8)                   \n\t" \
"lxv       %%vs53, 1520(%%r8)                   \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"addi             %%r8, %%r8, 1536              \n\t" \
"addi             %%r7, %%r7, 1536              \n\t" 

#define A_B_PRODUCT_16_mod \
"lxv       %%vs42, 0(%%r7)                      \n\t" \
"lxv       %%vs43, 16(%%r7)                     \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs0, %%vs36, %%vs48         \n\t" \
"xvmaddadp        %%vs1, %%vs37, %%vs48         \n\t" \
"xvmaddadp        %%vs2, %%vs38, %%vs48         \n\t" \
"xvmaddadp        %%vs3, %%vs39, %%vs48         \n\t" \
"xvmaddadp        %%vs4, %%vs40, %%vs48         \n\t" \
"xvmaddadp        %%vs5, %%vs41, %%vs48         \n\t" \
"                                               \n\t" \
"lxv       %%vs54, 0(%%r8)                      \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs6, %%vs36, %%vs49         \n\t" \
"xvmaddadp        %%vs7, %%vs37, %%vs49         \n\t" \
"xvmaddadp        %%vs8, %%vs38, %%vs49         \n\t" \
"lxv       %%vs55, 16(%%r8)                     \n\t" \
"xvmaddadp        %%vs9, %%vs39, %%vs49         \n\t" \
"xvmaddadp        %%vs10, %%vs40, %%vs49        \n\t" \
"xvmaddadp        %%vs11, %%vs41, %%vs49        \n\t" \
"                                               \n\t" \
"lxv       %%vs44, 32(%%r7)                     \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs12, %%vs36, %%vs50        \n\t" \
"xvmaddadp        %%vs13, %%vs37, %%vs50        \n\t" \
"xvmaddadp        %%vs14, %%vs38, %%vs50        \n\t" \
"lxv       %%vs45, 48(%%r7)                     \n\t" \
"xvmaddadp        %%vs15, %%vs39, %%vs50        \n\t" \
"xvmaddadp        %%vs16, %%vs40, %%vs50        \n\t" \
"xvmaddadp        %%vs17, %%vs41, %%vs50        \n\t" \
"                                               \n\t" \
"lxv       %%vs56, 32(%%r8)                     \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs18, %%vs36, %%vs51        \n\t" \
"xvmaddadp        %%vs19, %%vs37, %%vs51        \n\t" \
"xvmaddadp        %%vs20, %%vs38, %%vs51        \n\t" \
"lxv       %%vs57, 48(%%r8)                     \n\t" \
"xvmaddadp        %%vs21, %%vs39, %%vs51        \n\t" \
"xvmaddadp        %%vs22, %%vs40, %%vs51        \n\t" \
"xvmaddadp        %%vs23, %%vs41, %%vs51        \n\t" \
"                                               \n\t" \
"lxv       %%vs46, 64(%%r7)                     \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs24, %%vs36, %%vs52        \n\t" \
"xvmaddadp        %%vs25, %%vs37, %%vs52        \n\t" \
"xvmaddadp        %%vs26, %%vs38, %%vs52        \n\t" \
"lxv       %%vs47, 80(%%r7)                     \n\t" \
"xvmaddadp        %%vs27, %%vs39, %%vs52        \n\t" \
"xvmaddadp        %%vs28, %%vs40, %%vs52        \n\t" \
"xvmaddadp        %%vs29, %%vs41, %%vs52        \n\t" \
"                                               \n\t" \
"lxv       %%vs58, 64(%%r8)                     \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs30, %%vs36, %%vs53        \n\t" \
"xvmaddadp        %%vs31, %%vs37, %%vs53        \n\t" \
"xvmaddadp        %%vs32, %%vs38, %%vs53        \n\t" \
"lxv       %%vs59, 80(%%r8)                     \n\t" \
"xvmaddadp        %%vs33, %%vs39, %%vs53        \n\t" \
"xvmaddadp        %%vs34, %%vs40, %%vs53        \n\t" \
"xvmaddadp        %%vs35, %%vs41, %%vs53        \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"lxv       %%vs36, 96(%%r7)                     \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs0, %%vs42, %%vs54         \n\t" \
"xvmaddadp        %%vs1, %%vs43, %%vs54         \n\t" \
"xvmaddadp        %%vs2, %%vs44, %%vs54         \n\t" \
"lxv       %%vs37, 112(%%r7)                    \n\t" \
"xvmaddadp        %%vs3, %%vs45, %%vs54         \n\t" \
"xvmaddadp        %%vs4, %%vs46, %%vs54         \n\t" \
"xvmaddadp        %%vs5, %%vs47, %%vs54         \n\t" \
"                                               \n\t" \
"lxv       %%vs48, 96(%%r8)                     \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs6, %%vs42, %%vs55         \n\t" \
"xvmaddadp        %%vs7, %%vs43, %%vs55         \n\t" \
"xvmaddadp        %%vs8, %%vs44, %%vs55         \n\t" \
"lxv       %%vs49, 112(%%r8)                    \n\t" \
"xvmaddadp        %%vs9, %%vs45, %%vs55         \n\t" \
"xvmaddadp        %%vs10, %%vs46, %%vs55        \n\t" \
"xvmaddadp        %%vs11, %%vs47, %%vs55        \n\t" \
"                                               \n\t" \
"lxv       %%vs38, 128(%%r7)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs12, %%vs42, %%vs56        \n\t" \
"xvmaddadp        %%vs13, %%vs43, %%vs56        \n\t" \
"xvmaddadp        %%vs14, %%vs44, %%vs56        \n\t" \
"lxv       %%vs39, 144(%%r7)                    \n\t" \
"xvmaddadp        %%vs15, %%vs45, %%vs56        \n\t" \
"xvmaddadp        %%vs16, %%vs46, %%vs56        \n\t" \
"xvmaddadp        %%vs17, %%vs47, %%vs56        \n\t" \
"                                               \n\t" \
"lxv       %%vs50, 128(%%r8)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs18, %%vs42, %%vs57        \n\t" \
"xvmaddadp        %%vs19, %%vs43, %%vs57        \n\t" \
"xvmaddadp        %%vs20, %%vs44, %%vs57        \n\t" \
"lxv       %%vs51, 144(%%r8)                    \n\t" \
"xvmaddadp        %%vs21, %%vs45, %%vs57        \n\t" \
"xvmaddadp        %%vs22, %%vs46, %%vs57        \n\t" \
"xvmaddadp        %%vs23, %%vs47, %%vs57        \n\t" \
"                                               \n\t" \
"lxv       %%vs40, 160(%%r7)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs24, %%vs42, %%vs58        \n\t" \
"xvmaddadp        %%vs25, %%vs43, %%vs58        \n\t" \
"xvmaddadp        %%vs26, %%vs44, %%vs58        \n\t" \
"lxv       %%vs41, 176(%%r7)                    \n\t" \
"xvmaddadp        %%vs27, %%vs45, %%vs58        \n\t" \
"xvmaddadp        %%vs28, %%vs46, %%vs58        \n\t" \
"xvmaddadp        %%vs29, %%vs47, %%vs58        \n\t" \
"                                               \n\t" \
"lxv       %%vs52, 160(%%r8)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs30, %%vs42, %%vs59        \n\t" \
"xvmaddadp        %%vs31, %%vs43, %%vs59        \n\t" \
"xvmaddadp        %%vs32, %%vs44, %%vs59        \n\t" \
"lxv       %%vs53, 176(%%r8)                    \n\t" \
"xvmaddadp        %%vs33, %%vs45, %%vs59        \n\t" \
"xvmaddadp        %%vs34, %%vs46, %%vs59        \n\t" \
"xvmaddadp        %%vs35, %%vs47, %%vs59        \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"lxv       %%vs42, 192(%%r7)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs0, %%vs36, %%vs48         \n\t" \
"xvmaddadp        %%vs1, %%vs37, %%vs48         \n\t" \
"xvmaddadp        %%vs2, %%vs38, %%vs48         \n\t" \
"lxv       %%vs43, 208(%%r7)                    \n\t" \
"xvmaddadp        %%vs3, %%vs39, %%vs48         \n\t" \
"xvmaddadp        %%vs4, %%vs40, %%vs48         \n\t" \
"xvmaddadp        %%vs5, %%vs41, %%vs48         \n\t" \
"                                               \n\t" \
"lxv       %%vs54, 192(%%r8)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs6, %%vs36, %%vs49         \n\t" \
"xvmaddadp        %%vs7, %%vs37, %%vs49         \n\t" \
"xvmaddadp        %%vs8, %%vs38, %%vs49         \n\t" \
"lxv       %%vs55, 208(%%r8)                    \n\t" \
"xvmaddadp        %%vs9, %%vs39, %%vs49         \n\t" \
"xvmaddadp        %%vs10, %%vs40, %%vs49        \n\t" \
"xvmaddadp        %%vs11, %%vs41, %%vs49        \n\t" \
"                                               \n\t" \
"lxv       %%vs44, 224(%%r7)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs12, %%vs36, %%vs50        \n\t" \
"xvmaddadp        %%vs13, %%vs37, %%vs50        \n\t" \
"xvmaddadp        %%vs14, %%vs38, %%vs50        \n\t" \
"lxv       %%vs45, 240(%%r7)                    \n\t" \
"xvmaddadp        %%vs15, %%vs39, %%vs50        \n\t" \
"xvmaddadp        %%vs16, %%vs40, %%vs50        \n\t" \
"xvmaddadp        %%vs17, %%vs41, %%vs50        \n\t" \
"                                               \n\t" \
"lxv       %%vs56, 224(%%r8)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs18, %%vs36, %%vs51        \n\t" \
"xvmaddadp        %%vs19, %%vs37, %%vs51        \n\t" \
"xvmaddadp        %%vs20, %%vs38, %%vs51        \n\t" \
"lxv       %%vs57, 240(%%r8)                    \n\t" \
"xvmaddadp        %%vs21, %%vs39, %%vs51        \n\t" \
"xvmaddadp        %%vs22, %%vs40, %%vs51        \n\t" \
"xvmaddadp        %%vs23, %%vs41, %%vs51        \n\t" \
"                                               \n\t" \
"lxv       %%vs46, 256(%%r7)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs24, %%vs36, %%vs52        \n\t" \
"xvmaddadp        %%vs25, %%vs37, %%vs52        \n\t" \
"xvmaddadp        %%vs26, %%vs38, %%vs52        \n\t" \
"lxv       %%vs47, 272(%%r7)                    \n\t" \
"xvmaddadp        %%vs27, %%vs39, %%vs52        \n\t" \
"xvmaddadp        %%vs28, %%vs40, %%vs52        \n\t" \
"xvmaddadp        %%vs29, %%vs41, %%vs52        \n\t" \
"                                               \n\t" \
"lxv       %%vs58, 256(%%r8)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs30, %%vs36, %%vs53        \n\t" \
"xvmaddadp        %%vs31, %%vs37, %%vs53        \n\t" \
"xvmaddadp        %%vs32, %%vs38, %%vs53        \n\t" \
"lxv       %%vs59, 272(%%r8)                    \n\t" \
"xvmaddadp        %%vs33, %%vs39, %%vs53        \n\t" \
"xvmaddadp        %%vs34, %%vs40, %%vs53        \n\t" \
"xvmaddadp        %%vs35, %%vs41, %%vs53        \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"lxv       %%vs36, 288(%%r7)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs0, %%vs42, %%vs54         \n\t" \
"xvmaddadp        %%vs1, %%vs43, %%vs54         \n\t" \
"xvmaddadp        %%vs2, %%vs44, %%vs54         \n\t" \
"lxv       %%vs37, 304(%%r7)                    \n\t" \
"xvmaddadp        %%vs3, %%vs45, %%vs54         \n\t" \
"xvmaddadp        %%vs4, %%vs46, %%vs54         \n\t" \
"xvmaddadp        %%vs5, %%vs47, %%vs54         \n\t" \
"                                               \n\t" \
"lxv       %%vs48, 288(%%r8)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs6, %%vs42, %%vs55         \n\t" \
"xvmaddadp        %%vs7, %%vs43, %%vs55         \n\t" \
"xvmaddadp        %%vs8, %%vs44, %%vs55         \n\t" \
"lxv       %%vs49, 304(%%r8)                    \n\t" \
"xvmaddadp        %%vs9, %%vs45, %%vs55         \n\t" \
"xvmaddadp        %%vs10, %%vs46, %%vs55        \n\t" \
"xvmaddadp        %%vs11, %%vs47, %%vs55        \n\t" \
"                                               \n\t" \
"lxv       %%vs38, 320(%%r7)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs12, %%vs42, %%vs56        \n\t" \
"xvmaddadp        %%vs13, %%vs43, %%vs56        \n\t" \
"xvmaddadp        %%vs14, %%vs44, %%vs56        \n\t" \
"lxv       %%vs39, 336(%%r7)                    \n\t" \
"xvmaddadp        %%vs15, %%vs45, %%vs56        \n\t" \
"xvmaddadp        %%vs16, %%vs46, %%vs56        \n\t" \
"xvmaddadp        %%vs17, %%vs47, %%vs56        \n\t" \
"                                               \n\t" \
"lxv       %%vs50, 320(%%r8)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs18, %%vs42, %%vs57        \n\t" \
"xvmaddadp        %%vs19, %%vs43, %%vs57        \n\t" \
"xvmaddadp        %%vs20, %%vs44, %%vs57        \n\t" \
"lxv       %%vs51, 336(%%r8)                    \n\t" \
"xvmaddadp        %%vs21, %%vs45, %%vs57        \n\t" \
"xvmaddadp        %%vs22, %%vs46, %%vs57        \n\t" \
"xvmaddadp        %%vs23, %%vs47, %%vs57        \n\t" \
"                                               \n\t" \
"lxv       %%vs40, 352(%%r7)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs24, %%vs42, %%vs58        \n\t" \
"xvmaddadp        %%vs25, %%vs43, %%vs58        \n\t" \
"xvmaddadp        %%vs26, %%vs44, %%vs58        \n\t" \
"lxv       %%vs41, 368(%%r7)                    \n\t" \
"xvmaddadp        %%vs27, %%vs45, %%vs58        \n\t" \
"xvmaddadp        %%vs28, %%vs46, %%vs58        \n\t" \
"xvmaddadp        %%vs29, %%vs47, %%vs58        \n\t" \
"                                               \n\t" \
"lxv       %%vs52, 352(%%r8)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs30, %%vs42, %%vs59        \n\t" \
"xvmaddadp        %%vs31, %%vs43, %%vs59        \n\t" \
"xvmaddadp        %%vs32, %%vs44, %%vs59        \n\t" \
"lxv       %%vs53, 368(%%r8)                    \n\t" \
"xvmaddadp        %%vs33, %%vs45, %%vs59        \n\t" \
"xvmaddadp        %%vs34, %%vs46, %%vs59        \n\t" \
"xvmaddadp        %%vs35, %%vs47, %%vs59        \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"lxv       %%vs42, 384(%%r7)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs0, %%vs36, %%vs48         \n\t" \
"xvmaddadp        %%vs1, %%vs37, %%vs48         \n\t" \
"xvmaddadp        %%vs2, %%vs38, %%vs48         \n\t" \
"lxv       %%vs43, 400(%%r7)                    \n\t" \
"xvmaddadp        %%vs3, %%vs39, %%vs48         \n\t" \
"xvmaddadp        %%vs4, %%vs40, %%vs48         \n\t" \
"xvmaddadp        %%vs5, %%vs41, %%vs48         \n\t" \
"                                               \n\t" \
"lxv       %%vs54, 384(%%r8)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs6, %%vs36, %%vs49         \n\t" \
"xvmaddadp        %%vs7, %%vs37, %%vs49         \n\t" \
"xvmaddadp        %%vs8, %%vs38, %%vs49         \n\t" \
"lxv       %%vs55, 400(%%r8)                    \n\t" \
"xvmaddadp        %%vs9, %%vs39, %%vs49         \n\t" \
"xvmaddadp        %%vs10, %%vs40, %%vs49        \n\t" \
"xvmaddadp        %%vs11, %%vs41, %%vs49        \n\t" \
"                                               \n\t" \
"lxv       %%vs44, 416(%%r7)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs12, %%vs36, %%vs50        \n\t" \
"xvmaddadp        %%vs13, %%vs37, %%vs50        \n\t" \
"xvmaddadp        %%vs14, %%vs38, %%vs50        \n\t" \
"lxv       %%vs45, 432(%%r7)                    \n\t" \
"xvmaddadp        %%vs15, %%vs39, %%vs50        \n\t" \
"xvmaddadp        %%vs16, %%vs40, %%vs50        \n\t" \
"xvmaddadp        %%vs17, %%vs41, %%vs50        \n\t" \
"                                               \n\t" \
"lxv       %%vs56, 416(%%r8)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs18, %%vs36, %%vs51        \n\t" \
"xvmaddadp        %%vs19, %%vs37, %%vs51        \n\t" \
"xvmaddadp        %%vs20, %%vs38, %%vs51        \n\t" \
"lxv       %%vs57, 432(%%r8)                    \n\t" \
"xvmaddadp        %%vs21, %%vs39, %%vs51        \n\t" \
"xvmaddadp        %%vs22, %%vs40, %%vs51        \n\t" \
"xvmaddadp        %%vs23, %%vs41, %%vs51        \n\t" \
"                                               \n\t" \
"lxv       %%vs46, 448(%%r7)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs24, %%vs36, %%vs52        \n\t" \
"xvmaddadp        %%vs25, %%vs37, %%vs52        \n\t" \
"xvmaddadp        %%vs26, %%vs38, %%vs52        \n\t" \
"lxv       %%vs47, 464(%%r7)                    \n\t" \
"xvmaddadp        %%vs27, %%vs39, %%vs52        \n\t" \
"xvmaddadp        %%vs28, %%vs40, %%vs52        \n\t" \
"xvmaddadp        %%vs29, %%vs41, %%vs52        \n\t" \
"                                               \n\t" \
"lxv       %%vs58, 448(%%r8)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs30, %%vs36, %%vs53        \n\t" \
"xvmaddadp        %%vs31, %%vs37, %%vs53        \n\t" \
"xvmaddadp        %%vs32, %%vs38, %%vs53        \n\t" \
"lxv       %%vs59, 464(%%r8)                    \n\t" \
"xvmaddadp        %%vs33, %%vs39, %%vs53        \n\t" \
"xvmaddadp        %%vs34, %%vs40, %%vs53        \n\t" \
"xvmaddadp        %%vs35, %%vs41, %%vs53        \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"lxv       %%vs36, 480(%%r7)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs0, %%vs42, %%vs54         \n\t" \
"xvmaddadp        %%vs1, %%vs43, %%vs54         \n\t" \
"xvmaddadp        %%vs2, %%vs44, %%vs54         \n\t" \
"lxv       %%vs37, 496(%%r7)                    \n\t" \
"xvmaddadp        %%vs3, %%vs45, %%vs54         \n\t" \
"xvmaddadp        %%vs4, %%vs46, %%vs54         \n\t" \
"xvmaddadp        %%vs5, %%vs47, %%vs54         \n\t" \
"                                               \n\t" \
"lxv       %%vs48, 480(%%r8)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs6, %%vs42, %%vs55         \n\t" \
"xvmaddadp        %%vs7, %%vs43, %%vs55         \n\t" \
"xvmaddadp        %%vs8, %%vs44, %%vs55         \n\t" \
"lxv       %%vs49, 496(%%r8)                    \n\t" \
"xvmaddadp        %%vs9, %%vs45, %%vs55         \n\t" \
"xvmaddadp        %%vs10, %%vs46, %%vs55        \n\t" \
"xvmaddadp        %%vs11, %%vs47, %%vs55        \n\t" \
"                                               \n\t" \
"lxv       %%vs38, 512(%%r7)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs12, %%vs42, %%vs56        \n\t" \
"xvmaddadp        %%vs13, %%vs43, %%vs56        \n\t" \
"xvmaddadp        %%vs14, %%vs44, %%vs56        \n\t" \
"lxv       %%vs39, 528(%%r7)                    \n\t" \
"xvmaddadp        %%vs15, %%vs45, %%vs56        \n\t" \
"xvmaddadp        %%vs16, %%vs46, %%vs56        \n\t" \
"xvmaddadp        %%vs17, %%vs47, %%vs56        \n\t" \
"                                               \n\t" \
"lxv       %%vs50, 512(%%r8)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs18, %%vs42, %%vs57        \n\t" \
"xvmaddadp        %%vs19, %%vs43, %%vs57        \n\t" \
"xvmaddadp        %%vs20, %%vs44, %%vs57        \n\t" \
"lxv       %%vs51, 528(%%r8)                    \n\t" \
"xvmaddadp        %%vs21, %%vs45, %%vs57        \n\t" \
"xvmaddadp        %%vs22, %%vs46, %%vs57        \n\t" \
"xvmaddadp        %%vs23, %%vs47, %%vs57        \n\t" \
"                                               \n\t" \
"lxv       %%vs40, 544(%%r7)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs24, %%vs42, %%vs58        \n\t" \
"xvmaddadp        %%vs25, %%vs43, %%vs58        \n\t" \
"xvmaddadp        %%vs26, %%vs44, %%vs58        \n\t" \
"lxv       %%vs41, 560(%%r7)                    \n\t" \
"xvmaddadp        %%vs27, %%vs45, %%vs58        \n\t" \
"xvmaddadp        %%vs28, %%vs46, %%vs58        \n\t" \
"xvmaddadp        %%vs29, %%vs47, %%vs58        \n\t" \
"                                               \n\t" \
"lxv       %%vs52, 544(%%r8)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs30, %%vs42, %%vs59        \n\t" \
"xvmaddadp        %%vs31, %%vs43, %%vs59        \n\t" \
"xvmaddadp        %%vs32, %%vs44, %%vs59        \n\t" \
"lxv       %%vs53, 560(%%r8)                    \n\t" \
"xvmaddadp        %%vs33, %%vs45, %%vs59        \n\t" \
"xvmaddadp        %%vs34, %%vs46, %%vs59        \n\t" \
"xvmaddadp        %%vs35, %%vs47, %%vs59        \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"lxv       %%vs42, 576(%%r7)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs0, %%vs36, %%vs48         \n\t" \
"xvmaddadp        %%vs1, %%vs37, %%vs48         \n\t" \
"xvmaddadp        %%vs2, %%vs38, %%vs48         \n\t" \
"lxv       %%vs43, 592(%%r7)                    \n\t" \
"xvmaddadp        %%vs3, %%vs39, %%vs48         \n\t" \
"xvmaddadp        %%vs4, %%vs40, %%vs48         \n\t" \
"xvmaddadp        %%vs5, %%vs41, %%vs48         \n\t" \
"                                               \n\t" \
"lxv       %%vs54, 576(%%r8)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs6, %%vs36, %%vs49         \n\t" \
"xvmaddadp        %%vs7, %%vs37, %%vs49         \n\t" \
"xvmaddadp        %%vs8, %%vs38, %%vs49         \n\t" \
"lxv       %%vs55, 592(%%r8)                    \n\t" \
"xvmaddadp        %%vs9, %%vs39, %%vs49         \n\t" \
"xvmaddadp        %%vs10, %%vs40, %%vs49        \n\t" \
"xvmaddadp        %%vs11, %%vs41, %%vs49        \n\t" \
"                                               \n\t" \
"lxv       %%vs44, 608(%%r7)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs12, %%vs36, %%vs50        \n\t" \
"xvmaddadp        %%vs13, %%vs37, %%vs50        \n\t" \
"xvmaddadp        %%vs14, %%vs38, %%vs50        \n\t" \
"lxv       %%vs45, 624(%%r7)                    \n\t" \
"xvmaddadp        %%vs15, %%vs39, %%vs50        \n\t" \
"xvmaddadp        %%vs16, %%vs40, %%vs50        \n\t" \
"xvmaddadp        %%vs17, %%vs41, %%vs50        \n\t" \
"                                               \n\t" \
"lxv       %%vs56, 608(%%r8)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs18, %%vs36, %%vs51        \n\t" \
"xvmaddadp        %%vs19, %%vs37, %%vs51        \n\t" \
"xvmaddadp        %%vs20, %%vs38, %%vs51        \n\t" \
"lxv       %%vs57, 624(%%r8)                    \n\t" \
"xvmaddadp        %%vs21, %%vs39, %%vs51        \n\t" \
"xvmaddadp        %%vs22, %%vs40, %%vs51        \n\t" \
"xvmaddadp        %%vs23, %%vs41, %%vs51        \n\t" \
"                                               \n\t" \
"lxv       %%vs46, 640(%%r7)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs24, %%vs36, %%vs52        \n\t" \
"xvmaddadp        %%vs25, %%vs37, %%vs52        \n\t" \
"xvmaddadp        %%vs26, %%vs38, %%vs52        \n\t" \
"lxv       %%vs47, 656(%%r7)                    \n\t" \
"xvmaddadp        %%vs27, %%vs39, %%vs52        \n\t" \
"xvmaddadp        %%vs28, %%vs40, %%vs52        \n\t" \
"xvmaddadp        %%vs29, %%vs41, %%vs52        \n\t" \
"                                               \n\t" \
"lxv       %%vs58, 640(%%r8)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs30, %%vs36, %%vs53        \n\t" \
"xvmaddadp        %%vs31, %%vs37, %%vs53        \n\t" \
"xvmaddadp        %%vs32, %%vs38, %%vs53        \n\t" \
"lxv       %%vs59, 656(%%r8)                    \n\t" \
"xvmaddadp        %%vs33, %%vs39, %%vs53        \n\t" \
"xvmaddadp        %%vs34, %%vs40, %%vs53        \n\t" \
"xvmaddadp        %%vs35, %%vs41, %%vs53        \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"lxv       %%vs36, 672(%%r7)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs0, %%vs42, %%vs54         \n\t" \
"xvmaddadp        %%vs1, %%vs43, %%vs54         \n\t" \
"xvmaddadp        %%vs2, %%vs44, %%vs54         \n\t" \
"lxv       %%vs37, 688(%%r7)                    \n\t" \
"xvmaddadp        %%vs3, %%vs45, %%vs54         \n\t" \
"xvmaddadp        %%vs4, %%vs46, %%vs54         \n\t" \
"xvmaddadp        %%vs5, %%vs47, %%vs54         \n\t" \
"                                               \n\t" \
"lxv       %%vs48, 672(%%r8)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs6, %%vs42, %%vs55         \n\t" \
"xvmaddadp        %%vs7, %%vs43, %%vs55         \n\t" \
"xvmaddadp        %%vs8, %%vs44, %%vs55         \n\t" \
"lxv       %%vs49, 688(%%r8)                    \n\t" \
"xvmaddadp        %%vs9, %%vs45, %%vs55         \n\t" \
"xvmaddadp        %%vs10, %%vs46, %%vs55        \n\t" \
"xvmaddadp        %%vs11, %%vs47, %%vs55        \n\t" \
"                                               \n\t" \
"lxv       %%vs38, 704(%%r7)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs12, %%vs42, %%vs56        \n\t" \
"xvmaddadp        %%vs13, %%vs43, %%vs56        \n\t" \
"xvmaddadp        %%vs14, %%vs44, %%vs56        \n\t" \
"lxv       %%vs39, 720(%%r7)                    \n\t" \
"xvmaddadp        %%vs15, %%vs45, %%vs56        \n\t" \
"xvmaddadp        %%vs16, %%vs46, %%vs56        \n\t" \
"xvmaddadp        %%vs17, %%vs47, %%vs56        \n\t" \
"                                               \n\t" \
"lxv       %%vs50, 704(%%r8)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs18, %%vs42, %%vs57        \n\t" \
"xvmaddadp        %%vs19, %%vs43, %%vs57        \n\t" \
"xvmaddadp        %%vs20, %%vs44, %%vs57        \n\t" \
"lxv       %%vs51, 720(%%r8)                    \n\t" \
"xvmaddadp        %%vs21, %%vs45, %%vs57        \n\t" \
"xvmaddadp        %%vs22, %%vs46, %%vs57        \n\t" \
"xvmaddadp        %%vs23, %%vs47, %%vs57        \n\t" \
"                                               \n\t" \
"lxv       %%vs40, 736(%%r7)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs24, %%vs42, %%vs58        \n\t" \
"xvmaddadp        %%vs25, %%vs43, %%vs58        \n\t" \
"xvmaddadp        %%vs26, %%vs44, %%vs58        \n\t" \
"lxv       %%vs41, 752(%%r7)                    \n\t" \
"xvmaddadp        %%vs27, %%vs45, %%vs58        \n\t" \
"xvmaddadp        %%vs28, %%vs46, %%vs58        \n\t" \
"xvmaddadp        %%vs29, %%vs47, %%vs58        \n\t" \
"                                               \n\t" \
"lxv       %%vs52, 736(%%r8)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs30, %%vs42, %%vs59        \n\t" \
"xvmaddadp        %%vs31, %%vs43, %%vs59        \n\t" \
"xvmaddadp        %%vs32, %%vs44, %%vs59        \n\t" \
"lxv       %%vs53, 752(%%r8)                    \n\t" \
"xvmaddadp        %%vs33, %%vs45, %%vs59        \n\t" \
"xvmaddadp        %%vs34, %%vs46, %%vs59        \n\t" \
"xvmaddadp        %%vs35, %%vs47, %%vs59        \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"lxv       %%vs42, 768(%%r7)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs0, %%vs36, %%vs48         \n\t" \
"xvmaddadp        %%vs1, %%vs37, %%vs48         \n\t" \
"xvmaddadp        %%vs2, %%vs38, %%vs48         \n\t" \
"lxv       %%vs43, 784(%%r7)                    \n\t" \
"xvmaddadp        %%vs3, %%vs39, %%vs48         \n\t" \
"xvmaddadp        %%vs4, %%vs40, %%vs48         \n\t" \
"xvmaddadp        %%vs5, %%vs41, %%vs48         \n\t" \
"                                               \n\t" \
"lxv       %%vs54, 768(%%r8)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs6, %%vs36, %%vs49         \n\t" \
"xvmaddadp        %%vs7, %%vs37, %%vs49         \n\t" \
"xvmaddadp        %%vs8, %%vs38, %%vs49         \n\t" \
"lxv       %%vs55, 784(%%r8)                    \n\t" \
"xvmaddadp        %%vs9, %%vs39, %%vs49         \n\t" \
"xvmaddadp        %%vs10, %%vs40, %%vs49        \n\t" \
"xvmaddadp        %%vs11, %%vs41, %%vs49        \n\t" \
"                                               \n\t" \
"lxv       %%vs44, 800(%%r7)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs12, %%vs36, %%vs50        \n\t" \
"xvmaddadp        %%vs13, %%vs37, %%vs50        \n\t" \
"xvmaddadp        %%vs14, %%vs38, %%vs50        \n\t" \
"lxv       %%vs45, 816(%%r7)                    \n\t" \
"xvmaddadp        %%vs15, %%vs39, %%vs50        \n\t" \
"xvmaddadp        %%vs16, %%vs40, %%vs50        \n\t" \
"xvmaddadp        %%vs17, %%vs41, %%vs50        \n\t" \
"                                               \n\t" \
"lxv       %%vs56, 800(%%r8)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs18, %%vs36, %%vs51        \n\t" \
"xvmaddadp        %%vs19, %%vs37, %%vs51        \n\t" \
"xvmaddadp        %%vs20, %%vs38, %%vs51        \n\t" \
"lxv       %%vs57, 816(%%r8)                    \n\t" \
"xvmaddadp        %%vs21, %%vs39, %%vs51        \n\t" \
"xvmaddadp        %%vs22, %%vs40, %%vs51        \n\t" \
"xvmaddadp        %%vs23, %%vs41, %%vs51        \n\t" \
"                                               \n\t" \
"lxv       %%vs46, 832(%%r7)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs24, %%vs36, %%vs52        \n\t" \
"xvmaddadp        %%vs25, %%vs37, %%vs52        \n\t" \
"xvmaddadp        %%vs26, %%vs38, %%vs52        \n\t" \
"lxv       %%vs47, 848(%%r7)                    \n\t" \
"xvmaddadp        %%vs27, %%vs39, %%vs52        \n\t" \
"xvmaddadp        %%vs28, %%vs40, %%vs52        \n\t" \
"xvmaddadp        %%vs29, %%vs41, %%vs52        \n\t" \
"                                               \n\t" \
"lxv       %%vs58, 832(%%r8)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs30, %%vs36, %%vs53        \n\t" \
"xvmaddadp        %%vs31, %%vs37, %%vs53        \n\t" \
"xvmaddadp        %%vs32, %%vs38, %%vs53        \n\t" \
"lxv       %%vs59, 848(%%r8)                    \n\t" \
"xvmaddadp        %%vs33, %%vs39, %%vs53        \n\t" \
"xvmaddadp        %%vs34, %%vs40, %%vs53        \n\t" \
"xvmaddadp        %%vs35, %%vs41, %%vs53        \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"lxv       %%vs36, 864(%%r7)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs0, %%vs42, %%vs54         \n\t" \
"xvmaddadp        %%vs1, %%vs43, %%vs54         \n\t" \
"xvmaddadp        %%vs2, %%vs44, %%vs54         \n\t" \
"lxv       %%vs37, 880(%%r7)                    \n\t" \
"xvmaddadp        %%vs3, %%vs45, %%vs54         \n\t" \
"xvmaddadp        %%vs4, %%vs46, %%vs54         \n\t" \
"xvmaddadp        %%vs5, %%vs47, %%vs54         \n\t" \
"                                               \n\t" \
"lxv       %%vs48, 864(%%r8)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs6, %%vs42, %%vs55         \n\t" \
"xvmaddadp        %%vs7, %%vs43, %%vs55         \n\t" \
"xvmaddadp        %%vs8, %%vs44, %%vs55         \n\t" \
"lxv       %%vs49, 880(%%r8)                    \n\t" \
"xvmaddadp        %%vs9, %%vs45, %%vs55         \n\t" \
"xvmaddadp        %%vs10, %%vs46, %%vs55        \n\t" \
"xvmaddadp        %%vs11, %%vs47, %%vs55        \n\t" \
"                                               \n\t" \
"lxv       %%vs38, 896(%%r7)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs12, %%vs42, %%vs56        \n\t" \
"xvmaddadp        %%vs13, %%vs43, %%vs56        \n\t" \
"xvmaddadp        %%vs14, %%vs44, %%vs56        \n\t" \
"lxv       %%vs39, 912(%%r7)                    \n\t" \
"xvmaddadp        %%vs15, %%vs45, %%vs56        \n\t" \
"xvmaddadp        %%vs16, %%vs46, %%vs56        \n\t" \
"xvmaddadp        %%vs17, %%vs47, %%vs56        \n\t" \
"                                               \n\t" \
"lxv       %%vs50, 896(%%r8)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs18, %%vs42, %%vs57        \n\t" \
"xvmaddadp        %%vs19, %%vs43, %%vs57        \n\t" \
"xvmaddadp        %%vs20, %%vs44, %%vs57        \n\t" \
"lxv       %%vs51, 912(%%r8)                    \n\t" \
"xvmaddadp        %%vs21, %%vs45, %%vs57        \n\t" \
"xvmaddadp        %%vs22, %%vs46, %%vs57        \n\t" \
"xvmaddadp        %%vs23, %%vs47, %%vs57        \n\t" \
"                                               \n\t" \
"lxv       %%vs40, 928(%%r7)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs24, %%vs42, %%vs58        \n\t" \
"xvmaddadp        %%vs25, %%vs43, %%vs58        \n\t" \
"xvmaddadp        %%vs26, %%vs44, %%vs58        \n\t" \
"lxv       %%vs41, 944(%%r7)                    \n\t" \
"xvmaddadp        %%vs27, %%vs45, %%vs58        \n\t" \
"xvmaddadp        %%vs28, %%vs46, %%vs58        \n\t" \
"xvmaddadp        %%vs29, %%vs47, %%vs58        \n\t" \
"                                               \n\t" \
"lxv       %%vs52, 928(%%r8)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs30, %%vs42, %%vs59        \n\t" \
"xvmaddadp        %%vs31, %%vs43, %%vs59        \n\t" \
"xvmaddadp        %%vs32, %%vs44, %%vs59        \n\t" \
"lxv       %%vs53, 944(%%r8)                    \n\t" \
"xvmaddadp        %%vs33, %%vs45, %%vs59        \n\t" \
"xvmaddadp        %%vs34, %%vs46, %%vs59        \n\t" \
"xvmaddadp        %%vs35, %%vs47, %%vs59        \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"lxv       %%vs42, 960(%%r7)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs0, %%vs36, %%vs48         \n\t" \
"xvmaddadp        %%vs1, %%vs37, %%vs48         \n\t" \
"xvmaddadp        %%vs2, %%vs38, %%vs48         \n\t" \
"lxv       %%vs43, 976(%%r7)                    \n\t" \
"xvmaddadp        %%vs3, %%vs39, %%vs48         \n\t" \
"xvmaddadp        %%vs4, %%vs40, %%vs48         \n\t" \
"xvmaddadp        %%vs5, %%vs41, %%vs48         \n\t" \
"                                               \n\t" \
"lxv       %%vs54, 960(%%r8)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs6, %%vs36, %%vs49         \n\t" \
"xvmaddadp        %%vs7, %%vs37, %%vs49         \n\t" \
"xvmaddadp        %%vs8, %%vs38, %%vs49         \n\t" \
"lxv       %%vs55, 976(%%r8)                    \n\t" \
"xvmaddadp        %%vs9, %%vs39, %%vs49         \n\t" \
"xvmaddadp        %%vs10, %%vs40, %%vs49        \n\t" \
"xvmaddadp        %%vs11, %%vs41, %%vs49        \n\t" \
"                                               \n\t" \
"lxv       %%vs44, 992(%%r7)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs12, %%vs36, %%vs50        \n\t" \
"xvmaddadp        %%vs13, %%vs37, %%vs50        \n\t" \
"xvmaddadp        %%vs14, %%vs38, %%vs50        \n\t" \
"lxv       %%vs45, 1008(%%r7)                   \n\t" \
"xvmaddadp        %%vs15, %%vs39, %%vs50        \n\t" \
"xvmaddadp        %%vs16, %%vs40, %%vs50        \n\t" \
"xvmaddadp        %%vs17, %%vs41, %%vs50        \n\t" \
"                                               \n\t" \
"lxv       %%vs56, 992(%%r8)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs18, %%vs36, %%vs51        \n\t" \
"xvmaddadp        %%vs19, %%vs37, %%vs51        \n\t" \
"xvmaddadp        %%vs20, %%vs38, %%vs51        \n\t" \
"lxv       %%vs57, 1008(%%r8)                   \n\t" \
"xvmaddadp        %%vs21, %%vs39, %%vs51        \n\t" \
"xvmaddadp        %%vs22, %%vs40, %%vs51        \n\t" \
"xvmaddadp        %%vs23, %%vs41, %%vs51        \n\t" \
"                                               \n\t" \
"lxv       %%vs46, 1024(%%r7)                   \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs24, %%vs36, %%vs52        \n\t" \
"xvmaddadp        %%vs25, %%vs37, %%vs52        \n\t" \
"xvmaddadp        %%vs26, %%vs38, %%vs52        \n\t" \
"lxv       %%vs47, 1040(%%r7)                   \n\t" \
"xvmaddadp        %%vs27, %%vs39, %%vs52        \n\t" \
"xvmaddadp        %%vs28, %%vs40, %%vs52        \n\t" \
"xvmaddadp        %%vs29, %%vs41, %%vs52        \n\t" \
"                                               \n\t" \
"lxv       %%vs58, 1024(%%r8)                   \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs30, %%vs36, %%vs53        \n\t" \
"xvmaddadp        %%vs31, %%vs37, %%vs53        \n\t" \
"xvmaddadp        %%vs32, %%vs38, %%vs53        \n\t" \
"lxv       %%vs59, 1040(%%r8)                   \n\t" \
"xvmaddadp        %%vs33, %%vs39, %%vs53        \n\t" \
"xvmaddadp        %%vs34, %%vs40, %%vs53        \n\t" \
"xvmaddadp        %%vs35, %%vs41, %%vs53        \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"lxv       %%vs36, 1056(%%r7)                   \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs0, %%vs42, %%vs54         \n\t" \
"xvmaddadp        %%vs1, %%vs43, %%vs54         \n\t" \
"xvmaddadp        %%vs2, %%vs44, %%vs54         \n\t" \
"lxv       %%vs37, 1072(%%r7)                   \n\t" \
"xvmaddadp        %%vs3, %%vs45, %%vs54         \n\t" \
"xvmaddadp        %%vs4, %%vs46, %%vs54         \n\t" \
"xvmaddadp        %%vs5, %%vs47, %%vs54         \n\t" \
"                                               \n\t" \
"lxv       %%vs48, 1056(%%r8)                   \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs6, %%vs42, %%vs55         \n\t" \
"xvmaddadp        %%vs7, %%vs43, %%vs55         \n\t" \
"xvmaddadp        %%vs8, %%vs44, %%vs55         \n\t" \
"lxv       %%vs49, 1072(%%r8)                   \n\t" \
"xvmaddadp        %%vs9, %%vs45, %%vs55         \n\t" \
"xvmaddadp        %%vs10, %%vs46, %%vs55        \n\t" \
"xvmaddadp        %%vs11, %%vs47, %%vs55        \n\t" \
"                                               \n\t" \
"lxv       %%vs38, 1088(%%r7)                   \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs12, %%vs42, %%vs56        \n\t" \
"xvmaddadp        %%vs13, %%vs43, %%vs56        \n\t" \
"xvmaddadp        %%vs14, %%vs44, %%vs56        \n\t" \
"lxv       %%vs39, 1104(%%r7)                   \n\t" \
"xvmaddadp        %%vs15, %%vs45, %%vs56        \n\t" \
"xvmaddadp        %%vs16, %%vs46, %%vs56        \n\t" \
"xvmaddadp        %%vs17, %%vs47, %%vs56        \n\t" \
"                                               \n\t" \
"lxv       %%vs50, 1088(%%r8)                   \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs18, %%vs42, %%vs57        \n\t" \
"xvmaddadp        %%vs19, %%vs43, %%vs57        \n\t" \
"xvmaddadp        %%vs20, %%vs44, %%vs57        \n\t" \
"lxv       %%vs51, 1104(%%r8)                   \n\t" \
"xvmaddadp        %%vs21, %%vs45, %%vs57        \n\t" \
"xvmaddadp        %%vs22, %%vs46, %%vs57        \n\t" \
"xvmaddadp        %%vs23, %%vs47, %%vs57        \n\t" \
"                                               \n\t" \
"lxv       %%vs40, 1120(%%r7)                   \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs24, %%vs42, %%vs58        \n\t" \
"xvmaddadp        %%vs25, %%vs43, %%vs58        \n\t" \
"xvmaddadp        %%vs26, %%vs44, %%vs58        \n\t" \
"lxv       %%vs41, 1136(%%r7)                   \n\t" \
"xvmaddadp        %%vs27, %%vs45, %%vs58        \n\t" \
"xvmaddadp        %%vs28, %%vs46, %%vs58        \n\t" \
"xvmaddadp        %%vs29, %%vs47, %%vs58        \n\t" \
"                                               \n\t" \
"lxv       %%vs52, 1120(%%r8)                   \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs30, %%vs42, %%vs59        \n\t" \
"xvmaddadp        %%vs31, %%vs43, %%vs59        \n\t" \
"xvmaddadp        %%vs32, %%vs44, %%vs59        \n\t" \
"lxv       %%vs53, 1136(%%r8)                   \n\t" \
"xvmaddadp        %%vs33, %%vs45, %%vs59        \n\t" \
"xvmaddadp        %%vs34, %%vs46, %%vs59        \n\t" \
"xvmaddadp        %%vs35, %%vs47, %%vs59        \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"lxv       %%vs42, 1152(%%r7)                   \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs0, %%vs36, %%vs48         \n\t" \
"xvmaddadp        %%vs1, %%vs37, %%vs48         \n\t" \
"xvmaddadp        %%vs2, %%vs38, %%vs48         \n\t" \
"lxv       %%vs43, 1168(%%r7)                   \n\t" \
"xvmaddadp        %%vs3, %%vs39, %%vs48         \n\t" \
"xvmaddadp        %%vs4, %%vs40, %%vs48         \n\t" \
"xvmaddadp        %%vs5, %%vs41, %%vs48         \n\t" \
"                                               \n\t" \
"lxv       %%vs54, 1152(%%r8)                   \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs6, %%vs36, %%vs49         \n\t" \
"xvmaddadp        %%vs7, %%vs37, %%vs49         \n\t" \
"xvmaddadp        %%vs8, %%vs38, %%vs49         \n\t" \
"lxv       %%vs55, 1168(%%r8)                   \n\t" \
"xvmaddadp        %%vs9, %%vs39, %%vs49         \n\t" \
"xvmaddadp        %%vs10, %%vs40, %%vs49        \n\t" \
"xvmaddadp        %%vs11, %%vs41, %%vs49        \n\t" \
"                                               \n\t" \
"lxv       %%vs44, 1184(%%r7)                   \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs12, %%vs36, %%vs50        \n\t" \
"xvmaddadp        %%vs13, %%vs37, %%vs50        \n\t" \
"xvmaddadp        %%vs14, %%vs38, %%vs50        \n\t" \
"lxv       %%vs45, 1200(%%r7)                   \n\t" \
"xvmaddadp        %%vs15, %%vs39, %%vs50        \n\t" \
"xvmaddadp        %%vs16, %%vs40, %%vs50        \n\t" \
"xvmaddadp        %%vs17, %%vs41, %%vs50        \n\t" \
"                                               \n\t" \
"lxv       %%vs56, 1184(%%r8)                   \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs18, %%vs36, %%vs51        \n\t" \
"xvmaddadp        %%vs19, %%vs37, %%vs51        \n\t" \
"xvmaddadp        %%vs20, %%vs38, %%vs51        \n\t" \
"lxv       %%vs57, 1200(%%r8)                   \n\t" \
"xvmaddadp        %%vs21, %%vs39, %%vs51        \n\t" \
"xvmaddadp        %%vs22, %%vs40, %%vs51        \n\t" \
"xvmaddadp        %%vs23, %%vs41, %%vs51        \n\t" \
"                                               \n\t" \
"lxv       %%vs46, 1216(%%r7)                   \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs24, %%vs36, %%vs52        \n\t" \
"xvmaddadp        %%vs25, %%vs37, %%vs52        \n\t" \
"xvmaddadp        %%vs26, %%vs38, %%vs52        \n\t" \
"lxv       %%vs47, 1232(%%r7)                   \n\t" \
"xvmaddadp        %%vs27, %%vs39, %%vs52        \n\t" \
"xvmaddadp        %%vs28, %%vs40, %%vs52        \n\t" \
"xvmaddadp        %%vs29, %%vs41, %%vs52        \n\t" \
"                                               \n\t" \
"lxv       %%vs58, 1216(%%r8)                   \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs30, %%vs36, %%vs53        \n\t" \
"xvmaddadp        %%vs31, %%vs37, %%vs53        \n\t" \
"xvmaddadp        %%vs32, %%vs38, %%vs53        \n\t" \
"lxv       %%vs59, 1232(%%r8)                   \n\t" \
"xvmaddadp        %%vs33, %%vs39, %%vs53        \n\t" \
"xvmaddadp        %%vs34, %%vs40, %%vs53        \n\t" \
"xvmaddadp        %%vs35, %%vs41, %%vs53        \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"lxv       %%vs36, 1248(%%r7)                   \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs0, %%vs42, %%vs54         \n\t" \
"xvmaddadp        %%vs1, %%vs43, %%vs54         \n\t" \
"xvmaddadp        %%vs2, %%vs44, %%vs54         \n\t" \
"lxv       %%vs37, 1264(%%r7)                   \n\t" \
"xvmaddadp        %%vs3, %%vs45, %%vs54         \n\t" \
"xvmaddadp        %%vs4, %%vs46, %%vs54         \n\t" \
"xvmaddadp        %%vs5, %%vs47, %%vs54         \n\t" \
"                                               \n\t" \
"lxv       %%vs48, 1248(%%r8)                   \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs6, %%vs42, %%vs55         \n\t" \
"xvmaddadp        %%vs7, %%vs43, %%vs55         \n\t" \
"xvmaddadp        %%vs8, %%vs44, %%vs55         \n\t" \
"lxv       %%vs49, 1264(%%r8)                   \n\t" \
"xvmaddadp        %%vs9, %%vs45, %%vs55         \n\t" \
"xvmaddadp        %%vs10, %%vs46, %%vs55        \n\t" \
"xvmaddadp        %%vs11, %%vs47, %%vs55        \n\t" \
"                                               \n\t" \
"lxv       %%vs38, 1280(%%r7)                   \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs12, %%vs42, %%vs56        \n\t" \
"xvmaddadp        %%vs13, %%vs43, %%vs56        \n\t" \
"xvmaddadp        %%vs14, %%vs44, %%vs56        \n\t" \
"lxv       %%vs39, 1296(%%r7)                   \n\t" \
"xvmaddadp        %%vs15, %%vs45, %%vs56        \n\t" \
"xvmaddadp        %%vs16, %%vs46, %%vs56        \n\t" \
"xvmaddadp        %%vs17, %%vs47, %%vs56        \n\t" \
"                                               \n\t" \
"lxv       %%vs50, 1280(%%r8)                   \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs18, %%vs42, %%vs57        \n\t" \
"xvmaddadp        %%vs19, %%vs43, %%vs57        \n\t" \
"xvmaddadp        %%vs20, %%vs44, %%vs57        \n\t" \
"lxv       %%vs51, 1296(%%r8)                   \n\t" \
"xvmaddadp        %%vs21, %%vs45, %%vs57        \n\t" \
"xvmaddadp        %%vs22, %%vs46, %%vs57        \n\t" \
"xvmaddadp        %%vs23, %%vs47, %%vs57        \n\t" \
"                                               \n\t" \
"lxv       %%vs40, 1312(%%r7)                   \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs24, %%vs42, %%vs58        \n\t" \
"xvmaddadp        %%vs25, %%vs43, %%vs58        \n\t" \
"xvmaddadp        %%vs26, %%vs44, %%vs58        \n\t" \
"lxv       %%vs41, 1328(%%r7)                   \n\t" \
"xvmaddadp        %%vs27, %%vs45, %%vs58        \n\t" \
"xvmaddadp        %%vs28, %%vs46, %%vs58        \n\t" \
"xvmaddadp        %%vs29, %%vs47, %%vs58        \n\t" \
"                                               \n\t" \
"lxv       %%vs52, 1312(%%r8)                   \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs30, %%vs42, %%vs59        \n\t" \
"xvmaddadp        %%vs31, %%vs43, %%vs59        \n\t" \
"xvmaddadp        %%vs32, %%vs44, %%vs59        \n\t" \
"lxv       %%vs53, 1328(%%r8)                   \n\t" \
"xvmaddadp        %%vs33, %%vs45, %%vs59        \n\t" \
"xvmaddadp        %%vs34, %%vs46, %%vs59        \n\t" \
"xvmaddadp        %%vs35, %%vs47, %%vs59        \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"lxv       %%vs42, 1344(%%r7)                   \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs0, %%vs36, %%vs48         \n\t" \
"xvmaddadp        %%vs1, %%vs37, %%vs48         \n\t" \
"xvmaddadp        %%vs2, %%vs38, %%vs48         \n\t" \
"lxv       %%vs43, 1360(%%r7)                   \n\t" \
"xvmaddadp        %%vs3, %%vs39, %%vs48         \n\t" \
"xvmaddadp        %%vs4, %%vs40, %%vs48         \n\t" \
"xvmaddadp        %%vs5, %%vs41, %%vs48         \n\t" \
"                                               \n\t" \
"lxv       %%vs54, 1344(%%r8)                   \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs6, %%vs36, %%vs49         \n\t" \
"xvmaddadp        %%vs7, %%vs37, %%vs49         \n\t" \
"xvmaddadp        %%vs8, %%vs38, %%vs49         \n\t" \
"lxv       %%vs55, 1360(%%r8)                   \n\t" \
"xvmaddadp        %%vs9, %%vs39, %%vs49         \n\t" \
"xvmaddadp        %%vs10, %%vs40, %%vs49        \n\t" \
"xvmaddadp        %%vs11, %%vs41, %%vs49        \n\t" \
"                                               \n\t" \
"lxv       %%vs44, 1376(%%r7)                   \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs12, %%vs36, %%vs50        \n\t" \
"xvmaddadp        %%vs13, %%vs37, %%vs50        \n\t" \
"xvmaddadp        %%vs14, %%vs38, %%vs50        \n\t" \
"lxv       %%vs45, 1392(%%r7)                   \n\t" \
"xvmaddadp        %%vs15, %%vs39, %%vs50        \n\t" \
"xvmaddadp        %%vs16, %%vs40, %%vs50        \n\t" \
"xvmaddadp        %%vs17, %%vs41, %%vs50        \n\t" \
"                                               \n\t" \
"lxv       %%vs56, 1376(%%r8)                   \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs18, %%vs36, %%vs51        \n\t" \
"xvmaddadp        %%vs19, %%vs37, %%vs51        \n\t" \
"xvmaddadp        %%vs20, %%vs38, %%vs51        \n\t" \
"lxv       %%vs57, 1392(%%r8)                   \n\t" \
"xvmaddadp        %%vs21, %%vs39, %%vs51        \n\t" \
"xvmaddadp        %%vs22, %%vs40, %%vs51        \n\t" \
"xvmaddadp        %%vs23, %%vs41, %%vs51        \n\t" \
"                                               \n\t" \
"lxv       %%vs46, 1408(%%r7)                   \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs24, %%vs36, %%vs52        \n\t" \
"xvmaddadp        %%vs25, %%vs37, %%vs52        \n\t" \
"xvmaddadp        %%vs26, %%vs38, %%vs52        \n\t" \
"lxv       %%vs47, 1424(%%r7)                   \n\t" \
"xvmaddadp        %%vs27, %%vs39, %%vs52        \n\t" \
"xvmaddadp        %%vs28, %%vs40, %%vs52        \n\t" \
"xvmaddadp        %%vs29, %%vs41, %%vs52        \n\t" \
"                                               \n\t" \
"lxv       %%vs58, 1408(%%r8)                   \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs30, %%vs36, %%vs53        \n\t" \
"xvmaddadp        %%vs31, %%vs37, %%vs53        \n\t" \
"xvmaddadp        %%vs32, %%vs38, %%vs53        \n\t" \
"lxv       %%vs59, 1424(%%r8)                   \n\t" \
"xvmaddadp        %%vs33, %%vs39, %%vs53        \n\t" \
"xvmaddadp        %%vs34, %%vs40, %%vs53        \n\t" \
"xvmaddadp        %%vs35, %%vs41, %%vs53        \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs0, %%vs42, %%vs54         \n\t" \
"xvmaddadp        %%vs1, %%vs43, %%vs54         \n\t" \
"xvmaddadp        %%vs2, %%vs44, %%vs54         \n\t" \
"xvmaddadp        %%vs3, %%vs45, %%vs54         \n\t" \
"xvmaddadp        %%vs4, %%vs46, %%vs54         \n\t" \
"xvmaddadp        %%vs5, %%vs47, %%vs54         \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs6, %%vs42, %%vs55         \n\t" \
"xvmaddadp        %%vs7, %%vs43, %%vs55         \n\t" \
"xvmaddadp        %%vs8, %%vs44, %%vs55         \n\t" \
"xvmaddadp        %%vs9, %%vs45, %%vs55         \n\t" \
"xvmaddadp        %%vs10, %%vs46, %%vs55        \n\t" \
"xvmaddadp        %%vs11, %%vs47, %%vs55        \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs12, %%vs42, %%vs56        \n\t" \
"xvmaddadp        %%vs13, %%vs43, %%vs56        \n\t" \
"xvmaddadp        %%vs14, %%vs44, %%vs56        \n\t" \
"xvmaddadp        %%vs15, %%vs45, %%vs56        \n\t" \
"xvmaddadp        %%vs16, %%vs46, %%vs56        \n\t" \
"xvmaddadp        %%vs17, %%vs47, %%vs56        \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs18, %%vs42, %%vs57        \n\t" \
"xvmaddadp        %%vs19, %%vs43, %%vs57        \n\t" \
"xvmaddadp        %%vs20, %%vs44, %%vs57        \n\t" \
"xvmaddadp        %%vs21, %%vs45, %%vs57        \n\t" \
"xvmaddadp        %%vs22, %%vs46, %%vs57        \n\t" \
"xvmaddadp        %%vs23, %%vs47, %%vs57        \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs24, %%vs42, %%vs58        \n\t" \
"xvmaddadp        %%vs25, %%vs43, %%vs58        \n\t" \
"xvmaddadp        %%vs26, %%vs44, %%vs58        \n\t" \
"xvmaddadp        %%vs27, %%vs45, %%vs58        \n\t" \
"xvmaddadp        %%vs28, %%vs46, %%vs58        \n\t" \
"xvmaddadp        %%vs29, %%vs47, %%vs58        \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs30, %%vs42, %%vs59        \n\t" \
"xvmaddadp        %%vs31, %%vs43, %%vs59        \n\t" \
"xvmaddadp        %%vs32, %%vs44, %%vs59        \n\t" \
"xvmaddadp        %%vs33, %%vs45, %%vs59        \n\t" \
"xvmaddadp        %%vs34, %%vs46, %%vs59        \n\t" \
"xvmaddadp        %%vs35, %%vs47, %%vs59        \n\t" \
"                                               \n\t" \
"lxv       %%vs36, 1440(%%r7)                   \n\t" \
"lxv       %%vs37, 1456(%%r7)                   \n\t" \
"                                               \n\t" \
"lxv       %%vs48, 1440(%%r8)                   \n\t" \
"lxv       %%vs49, 1456(%%r8)                   \n\t" \
"                                               \n\t" \
"lxv       %%vs38, 1472(%%r7)                   \n\t" \
"lxv       %%vs39, 1488(%%r7)                   \n\t" \
"                                               \n\t" \
"lxv       %%vs50, 1472(%%r8)                   \n\t" \
"lxv       %%vs51, 1488(%%r8)                   \n\t" \
"                                               \n\t" \
"lxv       %%vs40, 1504(%%r7)                   \n\t" \
"lxv       %%vs41, 1520(%%r7)                   \n\t" \
"                                               \n\t" \
"lxv       %%vs52, 1504(%%r8)                   \n\t" \
"lxv       %%vs53, 1520(%%r8)                   \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"addi             %%r8, %%r8, 1536              \n\t" \
"addi             %%r7, %%r7, 1536              \n\t"\





#define A_B_PRODUCT_12 \
"                                               \n\t" \
"lxv       %%vs42, 0(%%r7)                    \n\t" \
"lxv       %%vs43, 16(%%r7)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs0, %%vs36, %%vs48        \n\t" \
"xvmaddadp        %%vs1, %%vs37, %%vs48        \n\t" \
"xvmaddadp        %%vs2, %%vs38, %%vs48        \n\t" \
"xvmaddadp        %%vs3, %%vs39, %%vs48        \n\t" \
"xvmaddadp        %%vs4, %%vs40, %%vs48        \n\t" \
"xvmaddadp        %%vs5, %%vs41, %%vs48        \n\t" \
"                                               \n\t" \
"lxv       %%vs54, 0(%%r8)                    \n\t" \
"lxv       %%vs55, 16(%%r8)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs6, %%vs36, %%vs49        \n\t" \
"xvmaddadp        %%vs7, %%vs37, %%vs49        \n\t" \
"xvmaddadp        %%vs8, %%vs38, %%vs49        \n\t" \
"xvmaddadp        %%vs9, %%vs39, %%vs49        \n\t" \
"xvmaddadp        %%vs10, %%vs40, %%vs49        \n\t" \
"xvmaddadp        %%vs11, %%vs41, %%vs49        \n\t" \
"                                               \n\t" \
"lxv       %%vs44, 32(%%r7)                    \n\t" \
"lxv       %%vs45, 48(%%r7)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs12, %%vs36, %%vs50        \n\t" \
"xvmaddadp        %%vs13, %%vs37, %%vs50        \n\t" \
"xvmaddadp        %%vs14, %%vs38, %%vs50        \n\t" \
"xvmaddadp        %%vs15, %%vs39, %%vs50        \n\t" \
"xvmaddadp        %%vs16, %%vs40, %%vs50        \n\t" \
"xvmaddadp        %%vs17, %%vs41, %%vs50        \n\t" \
"                                               \n\t" \
"lxv       %%vs56, 32(%%r8)                    \n\t" \
"lxv       %%vs57, 48(%%r8)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs18, %%vs36, %%vs51        \n\t" \
"xvmaddadp        %%vs19, %%vs37, %%vs51        \n\t" \
"xvmaddadp        %%vs20, %%vs38, %%vs51        \n\t" \
"xvmaddadp        %%vs21, %%vs39, %%vs51        \n\t" \
"xvmaddadp        %%vs22, %%vs40, %%vs51        \n\t" \
"xvmaddadp        %%vs23, %%vs41, %%vs51        \n\t" \
"                                               \n\t" \
"lxv       %%vs46, 64(%%r7)                    \n\t" \
"lxv       %%vs47, 80(%%r7)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs24, %%vs36, %%vs52        \n\t" \
"xvmaddadp        %%vs25, %%vs37, %%vs52        \n\t" \
"xvmaddadp        %%vs26, %%vs38, %%vs52        \n\t" \
"xvmaddadp        %%vs27, %%vs39, %%vs52        \n\t" \
"xvmaddadp        %%vs28, %%vs40, %%vs52        \n\t" \
"xvmaddadp        %%vs29, %%vs41, %%vs52        \n\t" \
"                                               \n\t" \
"lxv       %%vs58, 64(%%r8)                    \n\t" \
"lxv       %%vs59, 80(%%r8)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs30, %%vs36, %%vs53        \n\t" \
"xvmaddadp        %%vs31, %%vs37, %%vs53        \n\t" \
"xvmaddadp        %%vs32, %%vs38, %%vs53        \n\t" \
"xvmaddadp        %%vs33, %%vs39, %%vs53        \n\t" \
"xvmaddadp        %%vs34, %%vs40, %%vs53        \n\t" \
"xvmaddadp        %%vs35, %%vs41, %%vs53        \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"lxv       %%vs36, 96(%%r7)                    \n\t" \
"lxv       %%vs37, 112(%%r7)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs0, %%vs42, %%vs54        \n\t" \
"xvmaddadp        %%vs1, %%vs43, %%vs54        \n\t" \
"xvmaddadp        %%vs2, %%vs44, %%vs54        \n\t" \
"xvmaddadp        %%vs3, %%vs45, %%vs54        \n\t" \
"xvmaddadp        %%vs4, %%vs46, %%vs54        \n\t" \
"xvmaddadp        %%vs5, %%vs47, %%vs54        \n\t" \
"                                               \n\t" \
"lxv       %%vs48, 96(%%r8)                    \n\t" \
"lxv       %%vs49, 112(%%r8)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs6, %%vs42, %%vs55        \n\t" \
"xvmaddadp        %%vs7, %%vs43, %%vs55        \n\t" \
"xvmaddadp        %%vs8, %%vs44, %%vs55        \n\t" \
"xvmaddadp        %%vs9, %%vs45, %%vs55        \n\t" \
"xvmaddadp        %%vs10, %%vs46, %%vs55        \n\t" \
"xvmaddadp        %%vs11, %%vs47, %%vs55        \n\t" \
"                                               \n\t" \
"lxv       %%vs38, 128(%%r7)                    \n\t" \
"lxv       %%vs39, 144(%%r7)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs12, %%vs42, %%vs56        \n\t" \
"xvmaddadp        %%vs13, %%vs43, %%vs56        \n\t" \
"xvmaddadp        %%vs14, %%vs44, %%vs56        \n\t" \
"xvmaddadp        %%vs15, %%vs45, %%vs56        \n\t" \
"xvmaddadp        %%vs16, %%vs46, %%vs56        \n\t" \
"xvmaddadp        %%vs17, %%vs47, %%vs56        \n\t" \
"                                               \n\t" \
"lxv       %%vs50, 128(%%r8)                    \n\t" \
"lxv       %%vs51, 144(%%r8)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs18, %%vs42, %%vs57        \n\t" \
"xvmaddadp        %%vs19, %%vs43, %%vs57        \n\t" \
"xvmaddadp        %%vs20, %%vs44, %%vs57        \n\t" \
"xvmaddadp        %%vs21, %%vs45, %%vs57        \n\t" \
"xvmaddadp        %%vs22, %%vs46, %%vs57        \n\t" \
"xvmaddadp        %%vs23, %%vs47, %%vs57        \n\t" \
"                                               \n\t" \
"lxv       %%vs40, 160(%%r7)                    \n\t" \
"lxv       %%vs41, 176(%%r7)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs24, %%vs42, %%vs58        \n\t" \
"xvmaddadp        %%vs25, %%vs43, %%vs58        \n\t" \
"xvmaddadp        %%vs26, %%vs44, %%vs58        \n\t" \
"xvmaddadp        %%vs27, %%vs45, %%vs58        \n\t" \
"xvmaddadp        %%vs28, %%vs46, %%vs58        \n\t" \
"xvmaddadp        %%vs29, %%vs47, %%vs58        \n\t" \
"                                               \n\t" \
"lxv       %%vs52, 160(%%r8)                    \n\t" \
"lxv       %%vs53, 176(%%r8)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs30, %%vs42, %%vs59        \n\t" \
"xvmaddadp        %%vs31, %%vs43, %%vs59        \n\t" \
"xvmaddadp        %%vs32, %%vs44, %%vs59        \n\t" \
"xvmaddadp        %%vs33, %%vs45, %%vs59        \n\t" \
"xvmaddadp        %%vs34, %%vs46, %%vs59        \n\t" \
"xvmaddadp        %%vs35, %%vs47, %%vs59        \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"lxv       %%vs42, 192(%%r7)                    \n\t" \
"lxv       %%vs43, 208(%%r7)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs0, %%vs36, %%vs48        \n\t" \
"xvmaddadp        %%vs1, %%vs37, %%vs48        \n\t" \
"xvmaddadp        %%vs2, %%vs38, %%vs48        \n\t" \
"xvmaddadp        %%vs3, %%vs39, %%vs48        \n\t" \
"xvmaddadp        %%vs4, %%vs40, %%vs48        \n\t" \
"xvmaddadp        %%vs5, %%vs41, %%vs48        \n\t" \
"                                               \n\t" \
"lxv       %%vs54, 192(%%r8)                    \n\t" \
"lxv       %%vs55, 208(%%r8)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs6, %%vs36, %%vs49        \n\t" \
"xvmaddadp        %%vs7, %%vs37, %%vs49        \n\t" \
"xvmaddadp        %%vs8, %%vs38, %%vs49        \n\t" \
"xvmaddadp        %%vs9, %%vs39, %%vs49        \n\t" \
"xvmaddadp        %%vs10, %%vs40, %%vs49        \n\t" \
"xvmaddadp        %%vs11, %%vs41, %%vs49        \n\t" \
"                                               \n\t" \
"lxv       %%vs44, 224(%%r7)                    \n\t" \
"lxv       %%vs45, 240(%%r7)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs12, %%vs36, %%vs50        \n\t" \
"xvmaddadp        %%vs13, %%vs37, %%vs50        \n\t" \
"xvmaddadp        %%vs14, %%vs38, %%vs50        \n\t" \
"xvmaddadp        %%vs15, %%vs39, %%vs50        \n\t" \
"xvmaddadp        %%vs16, %%vs40, %%vs50        \n\t" \
"xvmaddadp        %%vs17, %%vs41, %%vs50        \n\t" \
"                                               \n\t" \
"lxv       %%vs56, 224(%%r8)                    \n\t" \
"lxv       %%vs57, 240(%%r8)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs18, %%vs36, %%vs51        \n\t" \
"xvmaddadp        %%vs19, %%vs37, %%vs51        \n\t" \
"xvmaddadp        %%vs20, %%vs38, %%vs51        \n\t" \
"xvmaddadp        %%vs21, %%vs39, %%vs51        \n\t" \
"xvmaddadp        %%vs22, %%vs40, %%vs51        \n\t" \
"xvmaddadp        %%vs23, %%vs41, %%vs51        \n\t" \
"                                               \n\t" \
"lxv       %%vs46, 256(%%r7)                    \n\t" \
"lxv       %%vs47, 272(%%r7)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs24, %%vs36, %%vs52        \n\t" \
"xvmaddadp        %%vs25, %%vs37, %%vs52        \n\t" \
"xvmaddadp        %%vs26, %%vs38, %%vs52        \n\t" \
"xvmaddadp        %%vs27, %%vs39, %%vs52        \n\t" \
"xvmaddadp        %%vs28, %%vs40, %%vs52        \n\t" \
"xvmaddadp        %%vs29, %%vs41, %%vs52        \n\t" \
"                                               \n\t" \
"lxv       %%vs58, 256(%%r8)                    \n\t" \
"lxv       %%vs59, 272(%%r8)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs30, %%vs36, %%vs53        \n\t" \
"xvmaddadp        %%vs31, %%vs37, %%vs53        \n\t" \
"xvmaddadp        %%vs32, %%vs38, %%vs53        \n\t" \
"xvmaddadp        %%vs33, %%vs39, %%vs53        \n\t" \
"xvmaddadp        %%vs34, %%vs40, %%vs53        \n\t" \
"xvmaddadp        %%vs35, %%vs41, %%vs53        \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"lxv       %%vs36, 288(%%r7)                    \n\t" \
"lxv       %%vs37, 304(%%r7)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs0, %%vs42, %%vs54        \n\t" \
"xvmaddadp        %%vs1, %%vs43, %%vs54        \n\t" \
"xvmaddadp        %%vs2, %%vs44, %%vs54        \n\t" \
"xvmaddadp        %%vs3, %%vs45, %%vs54        \n\t" \
"xvmaddadp        %%vs4, %%vs46, %%vs54        \n\t" \
"xvmaddadp        %%vs5, %%vs47, %%vs54        \n\t" \
"                                               \n\t" \
"lxv       %%vs48, 288(%%r8)                    \n\t" \
"lxv       %%vs49, 304(%%r8)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs6, %%vs42, %%vs55        \n\t" \
"xvmaddadp        %%vs7, %%vs43, %%vs55        \n\t" \
"xvmaddadp        %%vs8, %%vs44, %%vs55        \n\t" \
"xvmaddadp        %%vs9, %%vs45, %%vs55        \n\t" \
"xvmaddadp        %%vs10, %%vs46, %%vs55        \n\t" \
"xvmaddadp        %%vs11, %%vs47, %%vs55        \n\t" \
"                                               \n\t" \
"lxv       %%vs38, 320(%%r7)                    \n\t" \
"lxv       %%vs39, 336(%%r7)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs12, %%vs42, %%vs56        \n\t" \
"xvmaddadp        %%vs13, %%vs43, %%vs56        \n\t" \
"xvmaddadp        %%vs14, %%vs44, %%vs56        \n\t" \
"xvmaddadp        %%vs15, %%vs45, %%vs56        \n\t" \
"xvmaddadp        %%vs16, %%vs46, %%vs56        \n\t" \
"xvmaddadp        %%vs17, %%vs47, %%vs56        \n\t" \
"                                               \n\t" \
"lxv       %%vs50, 320(%%r8)                    \n\t" \
"lxv       %%vs51, 336(%%r8)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs18, %%vs42, %%vs57        \n\t" \
"xvmaddadp        %%vs19, %%vs43, %%vs57        \n\t" \
"xvmaddadp        %%vs20, %%vs44, %%vs57        \n\t" \
"xvmaddadp        %%vs21, %%vs45, %%vs57        \n\t" \
"xvmaddadp        %%vs22, %%vs46, %%vs57        \n\t" \
"xvmaddadp        %%vs23, %%vs47, %%vs57        \n\t" \
"                                               \n\t" \
"lxv       %%vs40, 352(%%r7)                    \n\t" \
"lxv       %%vs41, 368(%%r7)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs24, %%vs42, %%vs58        \n\t" \
"xvmaddadp        %%vs25, %%vs43, %%vs58        \n\t" \
"xvmaddadp        %%vs26, %%vs44, %%vs58        \n\t" \
"xvmaddadp        %%vs27, %%vs45, %%vs58        \n\t" \
"xvmaddadp        %%vs28, %%vs46, %%vs58        \n\t" \
"xvmaddadp        %%vs29, %%vs47, %%vs58        \n\t" \
"                                               \n\t" \
"lxv       %%vs52, 352(%%r8)                    \n\t" \
"lxv       %%vs53, 368(%%r8)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs30, %%vs42, %%vs59        \n\t" \
"xvmaddadp        %%vs31, %%vs43, %%vs59        \n\t" \
"xvmaddadp        %%vs32, %%vs44, %%vs59        \n\t" \
"xvmaddadp        %%vs33, %%vs45, %%vs59        \n\t" \
"xvmaddadp        %%vs34, %%vs46, %%vs59        \n\t" \
"xvmaddadp        %%vs35, %%vs47, %%vs59        \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"lxv       %%vs42, 384(%%r7)                    \n\t" \
"lxv       %%vs43, 400(%%r7)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs0, %%vs36, %%vs48        \n\t" \
"xvmaddadp        %%vs1, %%vs37, %%vs48        \n\t" \
"xvmaddadp        %%vs2, %%vs38, %%vs48        \n\t" \
"xvmaddadp        %%vs3, %%vs39, %%vs48        \n\t" \
"xvmaddadp        %%vs4, %%vs40, %%vs48        \n\t" \
"xvmaddadp        %%vs5, %%vs41, %%vs48        \n\t" \
"                                               \n\t" \
"lxv       %%vs54, 384(%%r8)                    \n\t" \
"lxv       %%vs55, 400(%%r8)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs6, %%vs36, %%vs49        \n\t" \
"xvmaddadp        %%vs7, %%vs37, %%vs49        \n\t" \
"xvmaddadp        %%vs8, %%vs38, %%vs49        \n\t" \
"xvmaddadp        %%vs9, %%vs39, %%vs49        \n\t" \
"xvmaddadp        %%vs10, %%vs40, %%vs49        \n\t" \
"xvmaddadp        %%vs11, %%vs41, %%vs49        \n\t" \
"                                               \n\t" \
"lxv       %%vs44, 416(%%r7)                    \n\t" \
"lxv       %%vs45, 432(%%r7)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs12, %%vs36, %%vs50        \n\t" \
"xvmaddadp        %%vs13, %%vs37, %%vs50        \n\t" \
"xvmaddadp        %%vs14, %%vs38, %%vs50        \n\t" \
"xvmaddadp        %%vs15, %%vs39, %%vs50        \n\t" \
"xvmaddadp        %%vs16, %%vs40, %%vs50        \n\t" \
"xvmaddadp        %%vs17, %%vs41, %%vs50        \n\t" \
"                                               \n\t" \
"lxv       %%vs56, 416(%%r8)                    \n\t" \
"lxv       %%vs57, 432(%%r8)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs18, %%vs36, %%vs51        \n\t" \
"xvmaddadp        %%vs19, %%vs37, %%vs51        \n\t" \
"xvmaddadp        %%vs20, %%vs38, %%vs51        \n\t" \
"xvmaddadp        %%vs21, %%vs39, %%vs51        \n\t" \
"xvmaddadp        %%vs22, %%vs40, %%vs51        \n\t" \
"xvmaddadp        %%vs23, %%vs41, %%vs51        \n\t" \
"                                               \n\t" \
"lxv       %%vs46, 448(%%r7)                    \n\t" \
"lxv       %%vs47, 464(%%r7)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs24, %%vs36, %%vs52        \n\t" \
"xvmaddadp        %%vs25, %%vs37, %%vs52        \n\t" \
"xvmaddadp        %%vs26, %%vs38, %%vs52        \n\t" \
"xvmaddadp        %%vs27, %%vs39, %%vs52        \n\t" \
"xvmaddadp        %%vs28, %%vs40, %%vs52        \n\t" \
"xvmaddadp        %%vs29, %%vs41, %%vs52        \n\t" \
"                                               \n\t" \
"lxv       %%vs58, 448(%%r8)                    \n\t" \
"lxv       %%vs59, 464(%%r8)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs30, %%vs36, %%vs53        \n\t" \
"xvmaddadp        %%vs31, %%vs37, %%vs53        \n\t" \
"xvmaddadp        %%vs32, %%vs38, %%vs53        \n\t" \
"xvmaddadp        %%vs33, %%vs39, %%vs53        \n\t" \
"xvmaddadp        %%vs34, %%vs40, %%vs53        \n\t" \
"xvmaddadp        %%vs35, %%vs41, %%vs53        \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"lxv       %%vs36, 480(%%r7)                    \n\t" \
"lxv       %%vs37, 496(%%r7)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs0, %%vs42, %%vs54        \n\t" \
"xvmaddadp        %%vs1, %%vs43, %%vs54        \n\t" \
"xvmaddadp        %%vs2, %%vs44, %%vs54        \n\t" \
"xvmaddadp        %%vs3, %%vs45, %%vs54        \n\t" \
"xvmaddadp        %%vs4, %%vs46, %%vs54        \n\t" \
"xvmaddadp        %%vs5, %%vs47, %%vs54        \n\t" \
"                                               \n\t" \
"lxv       %%vs48, 480(%%r8)                    \n\t" \
"lxv       %%vs49, 496(%%r8)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs6, %%vs42, %%vs55        \n\t" \
"xvmaddadp        %%vs7, %%vs43, %%vs55        \n\t" \
"xvmaddadp        %%vs8, %%vs44, %%vs55        \n\t" \
"xvmaddadp        %%vs9, %%vs45, %%vs55        \n\t" \
"xvmaddadp        %%vs10, %%vs46, %%vs55        \n\t" \
"xvmaddadp        %%vs11, %%vs47, %%vs55        \n\t" \
"                                               \n\t" \
"lxv       %%vs38, 512(%%r7)                    \n\t" \
"lxv       %%vs39, 528(%%r7)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs12, %%vs42, %%vs56        \n\t" \
"xvmaddadp        %%vs13, %%vs43, %%vs56        \n\t" \
"xvmaddadp        %%vs14, %%vs44, %%vs56        \n\t" \
"xvmaddadp        %%vs15, %%vs45, %%vs56        \n\t" \
"xvmaddadp        %%vs16, %%vs46, %%vs56        \n\t" \
"xvmaddadp        %%vs17, %%vs47, %%vs56        \n\t" \
"                                               \n\t" \
"lxv       %%vs50, 512(%%r8)                    \n\t" \
"lxv       %%vs51, 528(%%r8)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs18, %%vs42, %%vs57        \n\t" \
"xvmaddadp        %%vs19, %%vs43, %%vs57        \n\t" \
"xvmaddadp        %%vs20, %%vs44, %%vs57        \n\t" \
"xvmaddadp        %%vs21, %%vs45, %%vs57        \n\t" \
"xvmaddadp        %%vs22, %%vs46, %%vs57        \n\t" \
"xvmaddadp        %%vs23, %%vs47, %%vs57        \n\t" \
"                                               \n\t" \
"lxv       %%vs40, 544(%%r7)                    \n\t" \
"lxv       %%vs41, 560(%%r7)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs24, %%vs42, %%vs58        \n\t" \
"xvmaddadp        %%vs25, %%vs43, %%vs58        \n\t" \
"xvmaddadp        %%vs26, %%vs44, %%vs58        \n\t" \
"xvmaddadp        %%vs27, %%vs45, %%vs58        \n\t" \
"xvmaddadp        %%vs28, %%vs46, %%vs58        \n\t" \
"xvmaddadp        %%vs29, %%vs47, %%vs58        \n\t" \
"                                               \n\t" \
"lxv       %%vs52, 544(%%r8)                    \n\t" \
"lxv       %%vs53, 560(%%r8)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs30, %%vs42, %%vs59        \n\t" \
"xvmaddadp        %%vs31, %%vs43, %%vs59        \n\t" \
"xvmaddadp        %%vs32, %%vs44, %%vs59        \n\t" \
"xvmaddadp        %%vs33, %%vs45, %%vs59        \n\t" \
"xvmaddadp        %%vs34, %%vs46, %%vs59        \n\t" \
"xvmaddadp        %%vs35, %%vs47, %%vs59        \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"lxv       %%vs42, 576(%%r7)                    \n\t" \
"lxv       %%vs43, 592(%%r7)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs0, %%vs36, %%vs48        \n\t" \
"xvmaddadp        %%vs1, %%vs37, %%vs48        \n\t" \
"xvmaddadp        %%vs2, %%vs38, %%vs48        \n\t" \
"xvmaddadp        %%vs3, %%vs39, %%vs48        \n\t" \
"xvmaddadp        %%vs4, %%vs40, %%vs48        \n\t" \
"xvmaddadp        %%vs5, %%vs41, %%vs48        \n\t" \
"                                               \n\t" \
"lxv       %%vs54, 576(%%r8)                    \n\t" \
"lxv       %%vs55, 592(%%r8)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs6, %%vs36, %%vs49        \n\t" \
"xvmaddadp        %%vs7, %%vs37, %%vs49        \n\t" \
"xvmaddadp        %%vs8, %%vs38, %%vs49        \n\t" \
"xvmaddadp        %%vs9, %%vs39, %%vs49        \n\t" \
"xvmaddadp        %%vs10, %%vs40, %%vs49        \n\t" \
"xvmaddadp        %%vs11, %%vs41, %%vs49        \n\t" \
"                                               \n\t" \
"lxv       %%vs44, 608(%%r7)                    \n\t" \
"lxv       %%vs45, 624(%%r7)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs12, %%vs36, %%vs50        \n\t" \
"xvmaddadp        %%vs13, %%vs37, %%vs50        \n\t" \
"xvmaddadp        %%vs14, %%vs38, %%vs50        \n\t" \
"xvmaddadp        %%vs15, %%vs39, %%vs50        \n\t" \
"xvmaddadp        %%vs16, %%vs40, %%vs50        \n\t" \
"xvmaddadp        %%vs17, %%vs41, %%vs50        \n\t" \
"                                               \n\t" \
"lxv       %%vs56, 608(%%r8)                    \n\t" \
"lxv       %%vs57, 624(%%r8)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs18, %%vs36, %%vs51        \n\t" \
"xvmaddadp        %%vs19, %%vs37, %%vs51        \n\t" \
"xvmaddadp        %%vs20, %%vs38, %%vs51        \n\t" \
"xvmaddadp        %%vs21, %%vs39, %%vs51        \n\t" \
"xvmaddadp        %%vs22, %%vs40, %%vs51        \n\t" \
"xvmaddadp        %%vs23, %%vs41, %%vs51        \n\t" \
"                                               \n\t" \
"lxv       %%vs46, 640(%%r7)                    \n\t" \
"lxv       %%vs47, 656(%%r7)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs24, %%vs36, %%vs52        \n\t" \
"xvmaddadp        %%vs25, %%vs37, %%vs52        \n\t" \
"xvmaddadp        %%vs26, %%vs38, %%vs52        \n\t" \
"xvmaddadp        %%vs27, %%vs39, %%vs52        \n\t" \
"xvmaddadp        %%vs28, %%vs40, %%vs52        \n\t" \
"xvmaddadp        %%vs29, %%vs41, %%vs52        \n\t" \
"                                               \n\t" \
"lxv       %%vs58, 640(%%r8)                    \n\t" \
"lxv       %%vs59, 656(%%r8)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs30, %%vs36, %%vs53        \n\t" \
"xvmaddadp        %%vs31, %%vs37, %%vs53        \n\t" \
"xvmaddadp        %%vs32, %%vs38, %%vs53        \n\t" \
"xvmaddadp        %%vs33, %%vs39, %%vs53        \n\t" \
"xvmaddadp        %%vs34, %%vs40, %%vs53        \n\t" \
"xvmaddadp        %%vs35, %%vs41, %%vs53        \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"lxv       %%vs36, 672(%%r7)                    \n\t" \
"lxv       %%vs37, 688(%%r7)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs0, %%vs42, %%vs54        \n\t" \
"xvmaddadp        %%vs1, %%vs43, %%vs54        \n\t" \
"xvmaddadp        %%vs2, %%vs44, %%vs54        \n\t" \
"xvmaddadp        %%vs3, %%vs45, %%vs54        \n\t" \
"xvmaddadp        %%vs4, %%vs46, %%vs54        \n\t" \
"xvmaddadp        %%vs5, %%vs47, %%vs54        \n\t" \
"                                               \n\t" \
"lxv       %%vs48, 672(%%r8)                    \n\t" \
"lxv       %%vs49, 688(%%r8)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs6, %%vs42, %%vs55        \n\t" \
"xvmaddadp        %%vs7, %%vs43, %%vs55        \n\t" \
"xvmaddadp        %%vs8, %%vs44, %%vs55        \n\t" \
"xvmaddadp        %%vs9, %%vs45, %%vs55        \n\t" \
"xvmaddadp        %%vs10, %%vs46, %%vs55        \n\t" \
"xvmaddadp        %%vs11, %%vs47, %%vs55        \n\t" \
"                                               \n\t" \
"lxv       %%vs38, 704(%%r7)                    \n\t" \
"lxv       %%vs39, 720(%%r7)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs12, %%vs42, %%vs56        \n\t" \
"xvmaddadp        %%vs13, %%vs43, %%vs56        \n\t" \
"xvmaddadp        %%vs14, %%vs44, %%vs56        \n\t" \
"xvmaddadp        %%vs15, %%vs45, %%vs56        \n\t" \
"xvmaddadp        %%vs16, %%vs46, %%vs56        \n\t" \
"xvmaddadp        %%vs17, %%vs47, %%vs56        \n\t" \
"                                               \n\t" \
"lxv       %%vs50, 704(%%r8)                    \n\t" \
"lxv       %%vs51, 720(%%r8)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs18, %%vs42, %%vs57        \n\t" \
"xvmaddadp        %%vs19, %%vs43, %%vs57        \n\t" \
"xvmaddadp        %%vs20, %%vs44, %%vs57        \n\t" \
"xvmaddadp        %%vs21, %%vs45, %%vs57        \n\t" \
"xvmaddadp        %%vs22, %%vs46, %%vs57        \n\t" \
"xvmaddadp        %%vs23, %%vs47, %%vs57        \n\t" \
"                                               \n\t" \
"lxv       %%vs40, 736(%%r7)                    \n\t" \
"lxv       %%vs41, 752(%%r7)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs24, %%vs42, %%vs58        \n\t" \
"xvmaddadp        %%vs25, %%vs43, %%vs58        \n\t" \
"xvmaddadp        %%vs26, %%vs44, %%vs58        \n\t" \
"xvmaddadp        %%vs27, %%vs45, %%vs58        \n\t" \
"xvmaddadp        %%vs28, %%vs46, %%vs58        \n\t" \
"xvmaddadp        %%vs29, %%vs47, %%vs58        \n\t" \
"                                               \n\t" \
"lxv       %%vs52, 736(%%r8)                    \n\t" \
"lxv       %%vs53, 752(%%r8)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs30, %%vs42, %%vs59        \n\t" \
"xvmaddadp        %%vs31, %%vs43, %%vs59        \n\t" \
"xvmaddadp        %%vs32, %%vs44, %%vs59        \n\t" \
"xvmaddadp        %%vs33, %%vs45, %%vs59        \n\t" \
"xvmaddadp        %%vs34, %%vs46, %%vs59        \n\t" \
"xvmaddadp        %%vs35, %%vs47, %%vs59        \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"lxv       %%vs42, 768(%%r7)                    \n\t" \
"lxv       %%vs43, 784(%%r7)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs0, %%vs36, %%vs48        \n\t" \
"xvmaddadp        %%vs1, %%vs37, %%vs48        \n\t" \
"xvmaddadp        %%vs2, %%vs38, %%vs48        \n\t" \
"xvmaddadp        %%vs3, %%vs39, %%vs48        \n\t" \
"xvmaddadp        %%vs4, %%vs40, %%vs48        \n\t" \
"xvmaddadp        %%vs5, %%vs41, %%vs48        \n\t" \
"                                               \n\t" \
"lxv       %%vs54, 768(%%r8)                    \n\t" \
"lxv       %%vs55, 784(%%r8)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs6, %%vs36, %%vs49        \n\t" \
"xvmaddadp        %%vs7, %%vs37, %%vs49        \n\t" \
"xvmaddadp        %%vs8, %%vs38, %%vs49        \n\t" \
"xvmaddadp        %%vs9, %%vs39, %%vs49        \n\t" \
"xvmaddadp        %%vs10, %%vs40, %%vs49        \n\t" \
"xvmaddadp        %%vs11, %%vs41, %%vs49        \n\t" \
"                                               \n\t" \
"lxv       %%vs44, 800(%%r7)                    \n\t" \
"lxv       %%vs45, 816(%%r7)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs12, %%vs36, %%vs50        \n\t" \
"xvmaddadp        %%vs13, %%vs37, %%vs50        \n\t" \
"xvmaddadp        %%vs14, %%vs38, %%vs50        \n\t" \
"xvmaddadp        %%vs15, %%vs39, %%vs50        \n\t" \
"xvmaddadp        %%vs16, %%vs40, %%vs50        \n\t" \
"xvmaddadp        %%vs17, %%vs41, %%vs50        \n\t" \
"                                               \n\t" \
"lxv       %%vs56, 800(%%r8)                    \n\t" \
"lxv       %%vs57, 816(%%r8)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs18, %%vs36, %%vs51        \n\t" \
"xvmaddadp        %%vs19, %%vs37, %%vs51        \n\t" \
"xvmaddadp        %%vs20, %%vs38, %%vs51        \n\t" \
"xvmaddadp        %%vs21, %%vs39, %%vs51        \n\t" \
"xvmaddadp        %%vs22, %%vs40, %%vs51        \n\t" \
"xvmaddadp        %%vs23, %%vs41, %%vs51        \n\t" \
"                                               \n\t" \
"lxv       %%vs46, 832(%%r7)                    \n\t" \
"lxv       %%vs47, 848(%%r7)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs24, %%vs36, %%vs52        \n\t" \
"xvmaddadp        %%vs25, %%vs37, %%vs52        \n\t" \
"xvmaddadp        %%vs26, %%vs38, %%vs52        \n\t" \
"xvmaddadp        %%vs27, %%vs39, %%vs52        \n\t" \
"xvmaddadp        %%vs28, %%vs40, %%vs52        \n\t" \
"xvmaddadp        %%vs29, %%vs41, %%vs52        \n\t" \
"                                               \n\t" \
"lxv       %%vs58, 832(%%r8)                    \n\t" \
"lxv       %%vs59, 848(%%r8)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs30, %%vs36, %%vs53        \n\t" \
"xvmaddadp        %%vs31, %%vs37, %%vs53        \n\t" \
"xvmaddadp        %%vs32, %%vs38, %%vs53        \n\t" \
"xvmaddadp        %%vs33, %%vs39, %%vs53        \n\t" \
"xvmaddadp        %%vs34, %%vs40, %%vs53        \n\t" \
"xvmaddadp        %%vs35, %%vs41, %%vs53        \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"lxv       %%vs36, 864(%%r7)                    \n\t" \
"lxv       %%vs37, 880(%%r7)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs0, %%vs42, %%vs54        \n\t" \
"xvmaddadp        %%vs1, %%vs43, %%vs54        \n\t" \
"xvmaddadp        %%vs2, %%vs44, %%vs54        \n\t" \
"xvmaddadp        %%vs3, %%vs45, %%vs54        \n\t" \
"xvmaddadp        %%vs4, %%vs46, %%vs54        \n\t" \
"xvmaddadp        %%vs5, %%vs47, %%vs54        \n\t" \
"                                               \n\t" \
"lxv       %%vs48, 864(%%r8)                    \n\t" \
"lxv       %%vs49, 880(%%r8)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs6, %%vs42, %%vs55        \n\t" \
"xvmaddadp        %%vs7, %%vs43, %%vs55        \n\t" \
"xvmaddadp        %%vs8, %%vs44, %%vs55        \n\t" \
"xvmaddadp        %%vs9, %%vs45, %%vs55        \n\t" \
"xvmaddadp        %%vs10, %%vs46, %%vs55        \n\t" \
"xvmaddadp        %%vs11, %%vs47, %%vs55        \n\t" \
"                                               \n\t" \
"lxv       %%vs38, 896(%%r7)                    \n\t" \
"lxv       %%vs39, 912(%%r7)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs12, %%vs42, %%vs56        \n\t" \
"xvmaddadp        %%vs13, %%vs43, %%vs56        \n\t" \
"xvmaddadp        %%vs14, %%vs44, %%vs56        \n\t" \
"xvmaddadp        %%vs15, %%vs45, %%vs56        \n\t" \
"xvmaddadp        %%vs16, %%vs46, %%vs56        \n\t" \
"xvmaddadp        %%vs17, %%vs47, %%vs56        \n\t" \
"                                               \n\t" \
"lxv       %%vs50, 896(%%r8)                    \n\t" \
"lxv       %%vs51, 912(%%r8)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs18, %%vs42, %%vs57        \n\t" \
"xvmaddadp        %%vs19, %%vs43, %%vs57        \n\t" \
"xvmaddadp        %%vs20, %%vs44, %%vs57        \n\t" \
"xvmaddadp        %%vs21, %%vs45, %%vs57        \n\t" \
"xvmaddadp        %%vs22, %%vs46, %%vs57        \n\t" \
"xvmaddadp        %%vs23, %%vs47, %%vs57        \n\t" \
"                                               \n\t" \
"lxv       %%vs40, 928(%%r7)                    \n\t" \
"lxv       %%vs41, 944(%%r7)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs24, %%vs42, %%vs58        \n\t" \
"xvmaddadp        %%vs25, %%vs43, %%vs58        \n\t" \
"xvmaddadp        %%vs26, %%vs44, %%vs58        \n\t" \
"xvmaddadp        %%vs27, %%vs45, %%vs58        \n\t" \
"xvmaddadp        %%vs28, %%vs46, %%vs58        \n\t" \
"xvmaddadp        %%vs29, %%vs47, %%vs58        \n\t" \
"                                               \n\t" \
"lxv       %%vs52, 928(%%r8)                    \n\t" \
"lxv       %%vs53, 944(%%r8)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs30, %%vs42, %%vs59        \n\t" \
"xvmaddadp        %%vs31, %%vs43, %%vs59        \n\t" \
"xvmaddadp        %%vs32, %%vs44, %%vs59        \n\t" \
"xvmaddadp        %%vs33, %%vs45, %%vs59        \n\t" \
"xvmaddadp        %%vs34, %%vs46, %%vs59        \n\t" \
"xvmaddadp        %%vs35, %%vs47, %%vs59        \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"lxv       %%vs42, 960(%%r7)                    \n\t" \
"lxv       %%vs43, 976(%%r7)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs0, %%vs36, %%vs48        \n\t" \
"xvmaddadp        %%vs1, %%vs37, %%vs48        \n\t" \
"xvmaddadp        %%vs2, %%vs38, %%vs48        \n\t" \
"xvmaddadp        %%vs3, %%vs39, %%vs48        \n\t" \
"xvmaddadp        %%vs4, %%vs40, %%vs48        \n\t" \
"xvmaddadp        %%vs5, %%vs41, %%vs48        \n\t" \
"                                               \n\t" \
"lxv       %%vs54, 960(%%r8)                    \n\t" \
"lxv       %%vs55, 976(%%r8)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs6, %%vs36, %%vs49        \n\t" \
"xvmaddadp        %%vs7, %%vs37, %%vs49        \n\t" \
"xvmaddadp        %%vs8, %%vs38, %%vs49        \n\t" \
"xvmaddadp        %%vs9, %%vs39, %%vs49        \n\t" \
"xvmaddadp        %%vs10, %%vs40, %%vs49        \n\t" \
"xvmaddadp        %%vs11, %%vs41, %%vs49        \n\t" \
"                                               \n\t" \
"lxv       %%vs44, 992(%%r7)                    \n\t" \
"lxv       %%vs45, 1008(%%r7)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs12, %%vs36, %%vs50        \n\t" \
"xvmaddadp        %%vs13, %%vs37, %%vs50        \n\t" \
"xvmaddadp        %%vs14, %%vs38, %%vs50        \n\t" \
"xvmaddadp        %%vs15, %%vs39, %%vs50        \n\t" \
"xvmaddadp        %%vs16, %%vs40, %%vs50        \n\t" \
"xvmaddadp        %%vs17, %%vs41, %%vs50        \n\t" \
"                                               \n\t" \
"lxv       %%vs56, 992(%%r8)                    \n\t" \
"lxv       %%vs57, 1008(%%r8)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs18, %%vs36, %%vs51        \n\t" \
"xvmaddadp        %%vs19, %%vs37, %%vs51        \n\t" \
"xvmaddadp        %%vs20, %%vs38, %%vs51        \n\t" \
"xvmaddadp        %%vs21, %%vs39, %%vs51        \n\t" \
"xvmaddadp        %%vs22, %%vs40, %%vs51        \n\t" \
"xvmaddadp        %%vs23, %%vs41, %%vs51        \n\t" \
"                                               \n\t" \
"lxv       %%vs46, 1024(%%r7)                    \n\t" \
"lxv       %%vs47, 1040(%%r7)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs24, %%vs36, %%vs52        \n\t" \
"xvmaddadp        %%vs25, %%vs37, %%vs52        \n\t" \
"xvmaddadp        %%vs26, %%vs38, %%vs52        \n\t" \
"xvmaddadp        %%vs27, %%vs39, %%vs52        \n\t" \
"xvmaddadp        %%vs28, %%vs40, %%vs52        \n\t" \
"xvmaddadp        %%vs29, %%vs41, %%vs52        \n\t" \
"                                               \n\t" \
"lxv       %%vs58, 1024(%%r8)                    \n\t" \
"lxv       %%vs59, 1040(%%r8)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs30, %%vs36, %%vs53        \n\t" \
"xvmaddadp        %%vs31, %%vs37, %%vs53        \n\t" \
"xvmaddadp        %%vs32, %%vs38, %%vs53        \n\t" \
"xvmaddadp        %%vs33, %%vs39, %%vs53        \n\t" \
"xvmaddadp        %%vs34, %%vs40, %%vs53        \n\t" \
"xvmaddadp        %%vs35, %%vs41, %%vs53        \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs0, %%vs42, %%vs54        \n\t" \
"xvmaddadp        %%vs1, %%vs43, %%vs54        \n\t" \
"xvmaddadp        %%vs2, %%vs44, %%vs54        \n\t" \
"xvmaddadp        %%vs3, %%vs45, %%vs54        \n\t" \
"xvmaddadp        %%vs4, %%vs46, %%vs54        \n\t" \
"xvmaddadp        %%vs5, %%vs47, %%vs54        \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs6, %%vs42, %%vs55        \n\t" \
"xvmaddadp        %%vs7, %%vs43, %%vs55        \n\t" \
"xvmaddadp        %%vs8, %%vs44, %%vs55        \n\t" \
"xvmaddadp        %%vs9, %%vs45, %%vs55        \n\t" \
"xvmaddadp        %%vs10, %%vs46, %%vs55        \n\t" \
"xvmaddadp        %%vs11, %%vs47, %%vs55        \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs12, %%vs42, %%vs56        \n\t" \
"xvmaddadp        %%vs13, %%vs43, %%vs56        \n\t" \
"xvmaddadp        %%vs14, %%vs44, %%vs56        \n\t" \
"xvmaddadp        %%vs15, %%vs45, %%vs56        \n\t" \
"xvmaddadp        %%vs16, %%vs46, %%vs56        \n\t" \
"xvmaddadp        %%vs17, %%vs47, %%vs56        \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs18, %%vs42, %%vs57        \n\t" \
"xvmaddadp        %%vs19, %%vs43, %%vs57        \n\t" \
"xvmaddadp        %%vs20, %%vs44, %%vs57        \n\t" \
"xvmaddadp        %%vs21, %%vs45, %%vs57        \n\t" \
"xvmaddadp        %%vs22, %%vs46, %%vs57        \n\t" \
"xvmaddadp        %%vs23, %%vs47, %%vs57        \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs24, %%vs42, %%vs58        \n\t" \
"xvmaddadp        %%vs25, %%vs43, %%vs58        \n\t" \
"xvmaddadp        %%vs26, %%vs44, %%vs58        \n\t" \
"xvmaddadp        %%vs27, %%vs45, %%vs58        \n\t" \
"xvmaddadp        %%vs28, %%vs46, %%vs58        \n\t" \
"xvmaddadp        %%vs29, %%vs47, %%vs58        \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs30, %%vs42, %%vs59        \n\t" \
"xvmaddadp        %%vs31, %%vs43, %%vs59        \n\t" \
"xvmaddadp        %%vs32, %%vs44, %%vs59        \n\t" \
"xvmaddadp        %%vs33, %%vs45, %%vs59        \n\t" \
"xvmaddadp        %%vs34, %%vs46, %%vs59        \n\t" \
"xvmaddadp        %%vs35, %%vs47, %%vs59        \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"lxv       %%vs36, 1056(%%r7)                    \n\t" \
"lxv       %%vs37, 1072(%%r7)                    \n\t" \
"                                               \n\t" \
"lxv       %%vs48, 1056(%%r8)                    \n\t" \
"lxv       %%vs49, 1072(%%r8)                    \n\t" \
"                                               \n\t" \
"lxv       %%vs38, 1088(%%r7)                    \n\t" \
"lxv       %%vs39, 1104(%%r7)                    \n\t" \
"                                               \n\t" \
"lxv       %%vs50, 1088(%%r8)                    \n\t" \
"lxv       %%vs51, 1104(%%r8)                    \n\t" \
"                                               \n\t" \
"lxv       %%vs40, 1120(%%r7)                    \n\t" \
"lxv       %%vs41, 1136(%%r7)                    \n\t" \
"                                               \n\t" \
"lxv       %%vs52, 1120(%%r8)                    \n\t" \
"lxv       %%vs53, 1136(%%r8)                    \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"addi             %%r8, %%r8, 1152               \n\t" \
"addi             %%r7, %%r7, 1152               \n\t" 

#define A_B_PRODUCT_6 \
"                                               \n\t" \
"lxv       %%vs42, 0(%%r7)                    \n\t" \
"lxv       %%vs43, 16(%%r7)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs0, %%vs36, %%vs48        \n\t" \
"xvmaddadp        %%vs1, %%vs37, %%vs48        \n\t" \
"xvmaddadp        %%vs2, %%vs38, %%vs48        \n\t" \
"xvmaddadp        %%vs3, %%vs39, %%vs48        \n\t" \
"xvmaddadp        %%vs4, %%vs40, %%vs48        \n\t" \
"xvmaddadp        %%vs5, %%vs41, %%vs48        \n\t" \
"                                               \n\t" \
"lxv       %%vs54, 0(%%r8)                    \n\t" \
"lxv       %%vs55, 16(%%r8)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs6, %%vs36, %%vs49        \n\t" \
"xvmaddadp        %%vs7, %%vs37, %%vs49        \n\t" \
"xvmaddadp        %%vs8, %%vs38, %%vs49        \n\t" \
"xvmaddadp        %%vs9, %%vs39, %%vs49        \n\t" \
"xvmaddadp        %%vs10, %%vs40, %%vs49        \n\t" \
"xvmaddadp        %%vs11, %%vs41, %%vs49        \n\t" \
"                                               \n\t" \
"lxv       %%vs44, 32(%%r7)                    \n\t" \
"lxv       %%vs45, 48(%%r7)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs12, %%vs36, %%vs50        \n\t" \
"xvmaddadp        %%vs13, %%vs37, %%vs50        \n\t" \
"xvmaddadp        %%vs14, %%vs38, %%vs50        \n\t" \
"xvmaddadp        %%vs15, %%vs39, %%vs50        \n\t" \
"xvmaddadp        %%vs16, %%vs40, %%vs50        \n\t" \
"xvmaddadp        %%vs17, %%vs41, %%vs50        \n\t" \
"                                               \n\t" \
"lxv       %%vs56, 32(%%r8)                    \n\t" \
"lxv       %%vs57, 48(%%r8)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs18, %%vs36, %%vs51        \n\t" \
"xvmaddadp        %%vs19, %%vs37, %%vs51        \n\t" \
"xvmaddadp        %%vs20, %%vs38, %%vs51        \n\t" \
"xvmaddadp        %%vs21, %%vs39, %%vs51        \n\t" \
"xvmaddadp        %%vs22, %%vs40, %%vs51        \n\t" \
"xvmaddadp        %%vs23, %%vs41, %%vs51        \n\t" \
"                                               \n\t" \
"lxv       %%vs46, 64(%%r7)                    \n\t" \
"lxv       %%vs47, 80(%%r7)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs24, %%vs36, %%vs52        \n\t" \
"xvmaddadp        %%vs25, %%vs37, %%vs52        \n\t" \
"xvmaddadp        %%vs26, %%vs38, %%vs52        \n\t" \
"xvmaddadp        %%vs27, %%vs39, %%vs52        \n\t" \
"xvmaddadp        %%vs28, %%vs40, %%vs52        \n\t" \
"xvmaddadp        %%vs29, %%vs41, %%vs52        \n\t" \
"                                               \n\t" \
"lxv       %%vs58, 64(%%r8)                    \n\t" \
"lxv       %%vs59, 80(%%r8)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs30, %%vs36, %%vs53        \n\t" \
"xvmaddadp        %%vs31, %%vs37, %%vs53        \n\t" \
"xvmaddadp        %%vs32, %%vs38, %%vs53        \n\t" \
"xvmaddadp        %%vs33, %%vs39, %%vs53        \n\t" \
"xvmaddadp        %%vs34, %%vs40, %%vs53        \n\t" \
"xvmaddadp        %%vs35, %%vs41, %%vs53        \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"lxv       %%vs36, 96(%%r7)                    \n\t" \
"lxv       %%vs37, 112(%%r7)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs0, %%vs42, %%vs54        \n\t" \
"xvmaddadp        %%vs1, %%vs43, %%vs54        \n\t" \
"xvmaddadp        %%vs2, %%vs44, %%vs54        \n\t" \
"xvmaddadp        %%vs3, %%vs45, %%vs54        \n\t" \
"xvmaddadp        %%vs4, %%vs46, %%vs54        \n\t" \
"xvmaddadp        %%vs5, %%vs47, %%vs54        \n\t" \
"                                               \n\t" \
"lxv       %%vs48, 96(%%r8)                    \n\t" \
"lxv       %%vs49, 112(%%r8)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs6, %%vs42, %%vs55        \n\t" \
"xvmaddadp        %%vs7, %%vs43, %%vs55        \n\t" \
"xvmaddadp        %%vs8, %%vs44, %%vs55        \n\t" \
"xvmaddadp        %%vs9, %%vs45, %%vs55        \n\t" \
"xvmaddadp        %%vs10, %%vs46, %%vs55        \n\t" \
"xvmaddadp        %%vs11, %%vs47, %%vs55        \n\t" \
"                                               \n\t" \
"lxv       %%vs38, 128(%%r7)                    \n\t" \
"lxv       %%vs39, 144(%%r7)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs12, %%vs42, %%vs56        \n\t" \
"xvmaddadp        %%vs13, %%vs43, %%vs56        \n\t" \
"xvmaddadp        %%vs14, %%vs44, %%vs56        \n\t" \
"xvmaddadp        %%vs15, %%vs45, %%vs56        \n\t" \
"xvmaddadp        %%vs16, %%vs46, %%vs56        \n\t" \
"xvmaddadp        %%vs17, %%vs47, %%vs56        \n\t" \
"                                               \n\t" \
"lxv       %%vs50, 128(%%r8)                    \n\t" \
"lxv       %%vs51, 144(%%r8)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs18, %%vs42, %%vs57        \n\t" \
"xvmaddadp        %%vs19, %%vs43, %%vs57        \n\t" \
"xvmaddadp        %%vs20, %%vs44, %%vs57        \n\t" \
"xvmaddadp        %%vs21, %%vs45, %%vs57        \n\t" \
"xvmaddadp        %%vs22, %%vs46, %%vs57        \n\t" \
"xvmaddadp        %%vs23, %%vs47, %%vs57        \n\t" \
"                                               \n\t" \
"lxv       %%vs40, 160(%%r7)                    \n\t" \
"lxv       %%vs41, 176(%%r7)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs24, %%vs42, %%vs58        \n\t" \
"xvmaddadp        %%vs25, %%vs43, %%vs58        \n\t" \
"xvmaddadp        %%vs26, %%vs44, %%vs58        \n\t" \
"xvmaddadp        %%vs27, %%vs45, %%vs58        \n\t" \
"xvmaddadp        %%vs28, %%vs46, %%vs58        \n\t" \
"xvmaddadp        %%vs29, %%vs47, %%vs58        \n\t" \
"                                               \n\t" \
"lxv       %%vs52, 160(%%r8)                    \n\t" \
"lxv       %%vs53, 176(%%r8)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs30, %%vs42, %%vs59        \n\t" \
"xvmaddadp        %%vs31, %%vs43, %%vs59        \n\t" \
"xvmaddadp        %%vs32, %%vs44, %%vs59        \n\t" \
"xvmaddadp        %%vs33, %%vs45, %%vs59        \n\t" \
"xvmaddadp        %%vs34, %%vs46, %%vs59        \n\t" \
"xvmaddadp        %%vs35, %%vs47, %%vs59        \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"lxv       %%vs42, 192(%%r7)                    \n\t" \
"lxv       %%vs43, 208(%%r7)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs0, %%vs36, %%vs48        \n\t" \
"xvmaddadp        %%vs1, %%vs37, %%vs48        \n\t" \
"xvmaddadp        %%vs2, %%vs38, %%vs48        \n\t" \
"xvmaddadp        %%vs3, %%vs39, %%vs48        \n\t" \
"xvmaddadp        %%vs4, %%vs40, %%vs48        \n\t" \
"xvmaddadp        %%vs5, %%vs41, %%vs48        \n\t" \
"                                               \n\t" \
"lxv       %%vs54, 192(%%r8)                    \n\t" \
"lxv       %%vs55, 208(%%r8)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs6, %%vs36, %%vs49        \n\t" \
"xvmaddadp        %%vs7, %%vs37, %%vs49        \n\t" \
"xvmaddadp        %%vs8, %%vs38, %%vs49        \n\t" \
"xvmaddadp        %%vs9, %%vs39, %%vs49        \n\t" \
"xvmaddadp        %%vs10, %%vs40, %%vs49        \n\t" \
"xvmaddadp        %%vs11, %%vs41, %%vs49        \n\t" \
"                                               \n\t" \
"lxv       %%vs44, 224(%%r7)                    \n\t" \
"lxv       %%vs45, 240(%%r7)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs12, %%vs36, %%vs50        \n\t" \
"xvmaddadp        %%vs13, %%vs37, %%vs50        \n\t" \
"xvmaddadp        %%vs14, %%vs38, %%vs50        \n\t" \
"xvmaddadp        %%vs15, %%vs39, %%vs50        \n\t" \
"xvmaddadp        %%vs16, %%vs40, %%vs50        \n\t" \
"xvmaddadp        %%vs17, %%vs41, %%vs50        \n\t" \
"                                               \n\t" \
"lxv       %%vs56, 224(%%r8)                    \n\t" \
"lxv       %%vs57, 240(%%r8)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs18, %%vs36, %%vs51        \n\t" \
"xvmaddadp        %%vs19, %%vs37, %%vs51        \n\t" \
"xvmaddadp        %%vs20, %%vs38, %%vs51        \n\t" \
"xvmaddadp        %%vs21, %%vs39, %%vs51        \n\t" \
"xvmaddadp        %%vs22, %%vs40, %%vs51        \n\t" \
"xvmaddadp        %%vs23, %%vs41, %%vs51        \n\t" \
"                                               \n\t" \
"lxv       %%vs46, 256(%%r7)                    \n\t" \
"lxv       %%vs47, 272(%%r7)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs24, %%vs36, %%vs52        \n\t" \
"xvmaddadp        %%vs25, %%vs37, %%vs52        \n\t" \
"xvmaddadp        %%vs26, %%vs38, %%vs52        \n\t" \
"xvmaddadp        %%vs27, %%vs39, %%vs52        \n\t" \
"xvmaddadp        %%vs28, %%vs40, %%vs52        \n\t" \
"xvmaddadp        %%vs29, %%vs41, %%vs52        \n\t" \
"                                               \n\t" \
"lxv       %%vs58, 256(%%r8)                    \n\t" \
"lxv       %%vs59, 272(%%r8)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs30, %%vs36, %%vs53        \n\t" \
"xvmaddadp        %%vs31, %%vs37, %%vs53        \n\t" \
"xvmaddadp        %%vs32, %%vs38, %%vs53        \n\t" \
"xvmaddadp        %%vs33, %%vs39, %%vs53        \n\t" \
"xvmaddadp        %%vs34, %%vs40, %%vs53        \n\t" \
"xvmaddadp        %%vs35, %%vs41, %%vs53        \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"lxv       %%vs36, 288(%%r7)                    \n\t" \
"lxv       %%vs37, 304(%%r7)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs0, %%vs42, %%vs54        \n\t" \
"xvmaddadp        %%vs1, %%vs43, %%vs54        \n\t" \
"xvmaddadp        %%vs2, %%vs44, %%vs54        \n\t" \
"xvmaddadp        %%vs3, %%vs45, %%vs54        \n\t" \
"xvmaddadp        %%vs4, %%vs46, %%vs54        \n\t" \
"xvmaddadp        %%vs5, %%vs47, %%vs54        \n\t" \
"                                               \n\t" \
"lxv       %%vs48, 288(%%r8)                    \n\t" \
"lxv       %%vs49, 304(%%r8)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs6, %%vs42, %%vs55        \n\t" \
"xvmaddadp        %%vs7, %%vs43, %%vs55        \n\t" \
"xvmaddadp        %%vs8, %%vs44, %%vs55        \n\t" \
"xvmaddadp        %%vs9, %%vs45, %%vs55        \n\t" \
"xvmaddadp        %%vs10, %%vs46, %%vs55        \n\t" \
"xvmaddadp        %%vs11, %%vs47, %%vs55        \n\t" \
"                                               \n\t" \
"lxv       %%vs38, 320(%%r7)                    \n\t" \
"lxv       %%vs39, 336(%%r7)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs12, %%vs42, %%vs56        \n\t" \
"xvmaddadp        %%vs13, %%vs43, %%vs56        \n\t" \
"xvmaddadp        %%vs14, %%vs44, %%vs56        \n\t" \
"xvmaddadp        %%vs15, %%vs45, %%vs56        \n\t" \
"xvmaddadp        %%vs16, %%vs46, %%vs56        \n\t" \
"xvmaddadp        %%vs17, %%vs47, %%vs56        \n\t" \
"                                               \n\t" \
"lxv       %%vs50, 320(%%r8)                    \n\t" \
"lxv       %%vs51, 336(%%r8)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs18, %%vs42, %%vs57        \n\t" \
"xvmaddadp        %%vs19, %%vs43, %%vs57        \n\t" \
"xvmaddadp        %%vs20, %%vs44, %%vs57        \n\t" \
"xvmaddadp        %%vs21, %%vs45, %%vs57        \n\t" \
"xvmaddadp        %%vs22, %%vs46, %%vs57        \n\t" \
"xvmaddadp        %%vs23, %%vs47, %%vs57        \n\t" \
"                                               \n\t" \
"lxv       %%vs40, 352(%%r7)                    \n\t" \
"lxv       %%vs41, 368(%%r7)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs24, %%vs42, %%vs58        \n\t" \
"xvmaddadp        %%vs25, %%vs43, %%vs58        \n\t" \
"xvmaddadp        %%vs26, %%vs44, %%vs58        \n\t" \
"xvmaddadp        %%vs27, %%vs45, %%vs58        \n\t" \
"xvmaddadp        %%vs28, %%vs46, %%vs58        \n\t" \
"xvmaddadp        %%vs29, %%vs47, %%vs58        \n\t" \
"                                               \n\t" \
"lxv       %%vs52, 352(%%r8)                    \n\t" \
"lxv       %%vs53, 368(%%r8)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs30, %%vs42, %%vs59        \n\t" \
"xvmaddadp        %%vs31, %%vs43, %%vs59        \n\t" \
"xvmaddadp        %%vs32, %%vs44, %%vs59        \n\t" \
"xvmaddadp        %%vs33, %%vs45, %%vs59        \n\t" \
"xvmaddadp        %%vs34, %%vs46, %%vs59        \n\t" \
"xvmaddadp        %%vs35, %%vs47, %%vs59        \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"lxv       %%vs42, 384(%%r7)                    \n\t" \
"lxv       %%vs43, 400(%%r7)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs0, %%vs36, %%vs48        \n\t" \
"xvmaddadp        %%vs1, %%vs37, %%vs48        \n\t" \
"xvmaddadp        %%vs2, %%vs38, %%vs48        \n\t" \
"xvmaddadp        %%vs3, %%vs39, %%vs48        \n\t" \
"xvmaddadp        %%vs4, %%vs40, %%vs48        \n\t" \
"xvmaddadp        %%vs5, %%vs41, %%vs48        \n\t" \
"                                               \n\t" \
"lxv       %%vs54, 384(%%r8)                    \n\t" \
"lxv       %%vs55, 400(%%r8)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs6, %%vs36, %%vs49        \n\t" \
"xvmaddadp        %%vs7, %%vs37, %%vs49        \n\t" \
"xvmaddadp        %%vs8, %%vs38, %%vs49        \n\t" \
"xvmaddadp        %%vs9, %%vs39, %%vs49        \n\t" \
"xvmaddadp        %%vs10, %%vs40, %%vs49        \n\t" \
"xvmaddadp        %%vs11, %%vs41, %%vs49        \n\t" \
"                                               \n\t" \
"lxv       %%vs44, 416(%%r7)                    \n\t" \
"lxv       %%vs45, 432(%%r7)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs12, %%vs36, %%vs50        \n\t" \
"xvmaddadp        %%vs13, %%vs37, %%vs50        \n\t" \
"xvmaddadp        %%vs14, %%vs38, %%vs50        \n\t" \
"xvmaddadp        %%vs15, %%vs39, %%vs50        \n\t" \
"xvmaddadp        %%vs16, %%vs40, %%vs50        \n\t" \
"xvmaddadp        %%vs17, %%vs41, %%vs50        \n\t" \
"                                               \n\t" \
"lxv       %%vs56, 416(%%r8)                    \n\t" \
"lxv       %%vs57, 432(%%r8)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs18, %%vs36, %%vs51        \n\t" \
"xvmaddadp        %%vs19, %%vs37, %%vs51        \n\t" \
"xvmaddadp        %%vs20, %%vs38, %%vs51        \n\t" \
"xvmaddadp        %%vs21, %%vs39, %%vs51        \n\t" \
"xvmaddadp        %%vs22, %%vs40, %%vs51        \n\t" \
"xvmaddadp        %%vs23, %%vs41, %%vs51        \n\t" \
"                                               \n\t" \
"lxv       %%vs46, 448(%%r7)                    \n\t" \
"lxv       %%vs47, 464(%%r7)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs24, %%vs36, %%vs52        \n\t" \
"xvmaddadp        %%vs25, %%vs37, %%vs52        \n\t" \
"xvmaddadp        %%vs26, %%vs38, %%vs52        \n\t" \
"xvmaddadp        %%vs27, %%vs39, %%vs52        \n\t" \
"xvmaddadp        %%vs28, %%vs40, %%vs52        \n\t" \
"xvmaddadp        %%vs29, %%vs41, %%vs52        \n\t" \
"                                               \n\t" \
"lxv       %%vs58, 448(%%r8)                    \n\t" \
"lxv       %%vs59, 464(%%r8)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs30, %%vs36, %%vs53        \n\t" \
"xvmaddadp        %%vs31, %%vs37, %%vs53        \n\t" \
"xvmaddadp        %%vs32, %%vs38, %%vs53        \n\t" \
"xvmaddadp        %%vs33, %%vs39, %%vs53        \n\t" \
"xvmaddadp        %%vs34, %%vs40, %%vs53        \n\t" \
"xvmaddadp        %%vs35, %%vs41, %%vs53        \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"lxv       %%vs36, 480(%%r7)                    \n\t" \
"lxv       %%vs37, 496(%%r7)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs0, %%vs42, %%vs54        \n\t" \
"xvmaddadp        %%vs1, %%vs43, %%vs54        \n\t" \
"xvmaddadp        %%vs2, %%vs44, %%vs54        \n\t" \
"xvmaddadp        %%vs3, %%vs45, %%vs54        \n\t" \
"xvmaddadp        %%vs4, %%vs46, %%vs54        \n\t" \
"xvmaddadp        %%vs5, %%vs47, %%vs54        \n\t" \
"                                               \n\t" \
"lxv       %%vs48, 480(%%r8)                    \n\t" \
"lxv       %%vs49, 496(%%r8)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs6, %%vs42, %%vs55        \n\t" \
"xvmaddadp        %%vs7, %%vs43, %%vs55        \n\t" \
"xvmaddadp        %%vs8, %%vs44, %%vs55        \n\t" \
"xvmaddadp        %%vs9, %%vs45, %%vs55        \n\t" \
"xvmaddadp        %%vs10, %%vs46, %%vs55        \n\t" \
"xvmaddadp        %%vs11, %%vs47, %%vs55        \n\t" \
"                                               \n\t" \
"lxv       %%vs38, 512(%%r7)                    \n\t" \
"lxv       %%vs39, 528(%%r7)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs12, %%vs42, %%vs56        \n\t" \
"xvmaddadp        %%vs13, %%vs43, %%vs56        \n\t" \
"xvmaddadp        %%vs14, %%vs44, %%vs56        \n\t" \
"xvmaddadp        %%vs15, %%vs45, %%vs56        \n\t" \
"xvmaddadp        %%vs16, %%vs46, %%vs56        \n\t" \
"xvmaddadp        %%vs17, %%vs47, %%vs56        \n\t" \
"                                               \n\t" \
"lxv       %%vs50, 512(%%r8)                    \n\t" \
"lxv       %%vs51, 528(%%r8)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs18, %%vs42, %%vs57        \n\t" \
"xvmaddadp        %%vs19, %%vs43, %%vs57        \n\t" \
"xvmaddadp        %%vs20, %%vs44, %%vs57        \n\t" \
"xvmaddadp        %%vs21, %%vs45, %%vs57        \n\t" \
"xvmaddadp        %%vs22, %%vs46, %%vs57        \n\t" \
"xvmaddadp        %%vs23, %%vs47, %%vs57        \n\t" \
"                                               \n\t" \
"lxv       %%vs40, 544(%%r7)                    \n\t" \
"lxv       %%vs41, 560(%%r7)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs24, %%vs42, %%vs58        \n\t" \
"xvmaddadp        %%vs25, %%vs43, %%vs58        \n\t" \
"xvmaddadp        %%vs26, %%vs44, %%vs58        \n\t" \
"xvmaddadp        %%vs27, %%vs45, %%vs58        \n\t" \
"xvmaddadp        %%vs28, %%vs46, %%vs58        \n\t" \
"xvmaddadp        %%vs29, %%vs47, %%vs58        \n\t" \
"                                               \n\t" \
"lxv       %%vs52, 544(%%r8)                    \n\t" \
"lxv       %%vs53, 560(%%r8)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs30, %%vs42, %%vs59        \n\t" \
"xvmaddadp        %%vs31, %%vs43, %%vs59        \n\t" \
"xvmaddadp        %%vs32, %%vs44, %%vs59        \n\t" \
"xvmaddadp        %%vs33, %%vs45, %%vs59        \n\t" \
"xvmaddadp        %%vs34, %%vs46, %%vs59        \n\t" \
"xvmaddadp        %%vs35, %%vs47, %%vs59        \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"addi             %%r8, %%r8, 576               \n\t" \
"addi             %%r7, %%r7, 576               \n\t" 




#define A_B_PRODUCT_2 \
"                                               \n\t" \
"lxv       %%vs42, 0(%%r7)                    \n\t" \
"lxv       %%vs43, 16(%%r7)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs0, %%vs36, %%vs48        \n\t" \
"xvmaddadp        %%vs1, %%vs37, %%vs48        \n\t" \
"xvmaddadp        %%vs2, %%vs38, %%vs48        \n\t" \
"xvmaddadp        %%vs3, %%vs39, %%vs48        \n\t" \
"xvmaddadp        %%vs4, %%vs40, %%vs48        \n\t" \
"xvmaddadp        %%vs5, %%vs41, %%vs48        \n\t" \
"                                               \n\t" \
"lxv       %%vs54, 0(%%r8)                    \n\t" \
"lxv       %%vs55, 16(%%r8)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs6, %%vs36, %%vs49        \n\t" \
"xvmaddadp        %%vs7, %%vs37, %%vs49        \n\t" \
"xvmaddadp        %%vs8, %%vs38, %%vs49        \n\t" \
"xvmaddadp        %%vs9, %%vs39, %%vs49        \n\t" \
"xvmaddadp        %%vs10, %%vs40, %%vs49        \n\t" \
"xvmaddadp        %%vs11, %%vs41, %%vs49        \n\t" \
"                                               \n\t" \
"lxv       %%vs44, 32(%%r7)                    \n\t" \
"lxv       %%vs45, 48(%%r7)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs12, %%vs36, %%vs50        \n\t" \
"xvmaddadp        %%vs13, %%vs37, %%vs50        \n\t" \
"xvmaddadp        %%vs14, %%vs38, %%vs50        \n\t" \
"xvmaddadp        %%vs15, %%vs39, %%vs50        \n\t" \
"xvmaddadp        %%vs16, %%vs40, %%vs50        \n\t" \
"xvmaddadp        %%vs17, %%vs41, %%vs50        \n\t" \
"                                               \n\t" \
"lxv       %%vs56, 32(%%r8)                    \n\t" \
"lxv       %%vs57, 48(%%r8)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs18, %%vs36, %%vs51        \n\t" \
"xvmaddadp        %%vs19, %%vs37, %%vs51        \n\t" \
"xvmaddadp        %%vs20, %%vs38, %%vs51        \n\t" \
"xvmaddadp        %%vs21, %%vs39, %%vs51        \n\t" \
"xvmaddadp        %%vs22, %%vs40, %%vs51        \n\t" \
"xvmaddadp        %%vs23, %%vs41, %%vs51        \n\t" \
"                                               \n\t" \
"lxv       %%vs46, 64(%%r7)                    \n\t" \
"lxv       %%vs47, 80(%%r7)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs24, %%vs36, %%vs52        \n\t" \
"xvmaddadp        %%vs25, %%vs37, %%vs52        \n\t" \
"xvmaddadp        %%vs26, %%vs38, %%vs52        \n\t" \
"xvmaddadp        %%vs27, %%vs39, %%vs52        \n\t" \
"xvmaddadp        %%vs28, %%vs40, %%vs52        \n\t" \
"xvmaddadp        %%vs29, %%vs41, %%vs52        \n\t" \
"                                               \n\t" \
"lxv       %%vs58, 64(%%r8)                    \n\t" \
"lxv       %%vs59, 80(%%r8)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs30, %%vs36, %%vs53        \n\t" \
"xvmaddadp        %%vs31, %%vs37, %%vs53        \n\t" \
"xvmaddadp        %%vs32, %%vs38, %%vs53        \n\t" \
"xvmaddadp        %%vs33, %%vs39, %%vs53        \n\t" \
"xvmaddadp        %%vs34, %%vs40, %%vs53        \n\t" \
"xvmaddadp        %%vs35, %%vs41, %%vs53        \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"lxv       %%vs36, 96(%%r7)                    \n\t" \
"lxv       %%vs37, 112(%%r7)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs0, %%vs42, %%vs54        \n\t" \
"xvmaddadp        %%vs1, %%vs43, %%vs54        \n\t" \
"xvmaddadp        %%vs2, %%vs44, %%vs54        \n\t" \
"xvmaddadp        %%vs3, %%vs45, %%vs54        \n\t" \
"xvmaddadp        %%vs4, %%vs46, %%vs54        \n\t" \
"xvmaddadp        %%vs5, %%vs47, %%vs54        \n\t" \
"                                               \n\t" \
"lxv       %%vs48, 96(%%r8)                    \n\t" \
"lxv       %%vs49, 112(%%r8)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs6, %%vs42, %%vs55        \n\t" \
"xvmaddadp        %%vs7, %%vs43, %%vs55        \n\t" \
"xvmaddadp        %%vs8, %%vs44, %%vs55        \n\t" \
"xvmaddadp        %%vs9, %%vs45, %%vs55        \n\t" \
"xvmaddadp        %%vs10, %%vs46, %%vs55        \n\t" \
"xvmaddadp        %%vs11, %%vs47, %%vs55        \n\t" \
"                                               \n\t" \
"lxv       %%vs38, 128(%%r7)                    \n\t" \
"lxv       %%vs39, 144(%%r7)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs12, %%vs42, %%vs56        \n\t" \
"xvmaddadp        %%vs13, %%vs43, %%vs56        \n\t" \
"xvmaddadp        %%vs14, %%vs44, %%vs56        \n\t" \
"xvmaddadp        %%vs15, %%vs45, %%vs56        \n\t" \
"xvmaddadp        %%vs16, %%vs46, %%vs56        \n\t" \
"xvmaddadp        %%vs17, %%vs47, %%vs56        \n\t" \
"                                               \n\t" \
"lxv       %%vs50, 128(%%r8)                    \n\t" \
"lxv       %%vs51, 144(%%r8)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs18, %%vs42, %%vs57        \n\t" \
"xvmaddadp        %%vs19, %%vs43, %%vs57        \n\t" \
"xvmaddadp        %%vs20, %%vs44, %%vs57        \n\t" \
"xvmaddadp        %%vs21, %%vs45, %%vs57        \n\t" \
"xvmaddadp        %%vs22, %%vs46, %%vs57        \n\t" \
"xvmaddadp        %%vs23, %%vs47, %%vs57        \n\t" \
"                                               \n\t" \
"lxv       %%vs40, 160(%%r7)                    \n\t" \
"lxv       %%vs41, 176(%%r7)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs24, %%vs42, %%vs58        \n\t" \
"xvmaddadp        %%vs25, %%vs43, %%vs58        \n\t" \
"xvmaddadp        %%vs26, %%vs44, %%vs58        \n\t" \
"xvmaddadp        %%vs27, %%vs45, %%vs58        \n\t" \
"xvmaddadp        %%vs28, %%vs46, %%vs58        \n\t" \
"xvmaddadp        %%vs29, %%vs47, %%vs58        \n\t" \
"                                               \n\t" \
"lxv       %%vs52, 160(%%r8)                    \n\t" \
"lxv       %%vs53, 176(%%r8)                    \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs30, %%vs42, %%vs59        \n\t" \
"xvmaddadp        %%vs31, %%vs43, %%vs59        \n\t" \
"xvmaddadp        %%vs32, %%vs44, %%vs59        \n\t" \
"xvmaddadp        %%vs33, %%vs45, %%vs59        \n\t" \
"xvmaddadp        %%vs34, %%vs46, %%vs59        \n\t" \
"xvmaddadp        %%vs35, %%vs47, %%vs59        \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"addi             %%r8, %%r8, 192               \n\t" \
"addi             %%r7, %%r7, 192               \n\t" 



#define A_B_PRODUCT_1 \
"                                               \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs0, %%vs36, %%vs48         \n\t" \
"xvmaddadp        %%vs1, %%vs37, %%vs48         \n\t" \
"xvmaddadp        %%vs2, %%vs38, %%vs48         \n\t" \
"xvmaddadp        %%vs3, %%vs39, %%vs48         \n\t" \
"xvmaddadp        %%vs4, %%vs40, %%vs48         \n\t" \
"xvmaddadp        %%vs5, %%vs41, %%vs48         \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs6, %%vs36, %%vs49         \n\t" \
"xvmaddadp        %%vs7, %%vs37, %%vs49         \n\t" \
"xvmaddadp        %%vs8, %%vs38, %%vs49         \n\t" \
"xvmaddadp        %%vs9, %%vs39, %%vs49         \n\t" \
"xvmaddadp        %%vs10, %%vs40, %%vs49        \n\t" \
"xvmaddadp        %%vs11, %%vs41, %%vs49        \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs12, %%vs36, %%vs50        \n\t" \
"xvmaddadp        %%vs13, %%vs37, %%vs50        \n\t" \
"xvmaddadp        %%vs14, %%vs38, %%vs50        \n\t" \
"xvmaddadp        %%vs15, %%vs39, %%vs50        \n\t" \
"xvmaddadp        %%vs16, %%vs40, %%vs50        \n\t" \
"xvmaddadp        %%vs17, %%vs41, %%vs50        \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs18, %%vs36, %%vs51        \n\t" \
"xvmaddadp        %%vs19, %%vs37, %%vs51        \n\t" \
"xvmaddadp        %%vs20, %%vs38, %%vs51        \n\t" \
"xvmaddadp        %%vs21, %%vs39, %%vs51        \n\t" \
"xvmaddadp        %%vs22, %%vs40, %%vs51        \n\t" \
"xvmaddadp        %%vs23, %%vs41, %%vs51        \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs24, %%vs36, %%vs52        \n\t" \
"xvmaddadp        %%vs25, %%vs37, %%vs52        \n\t" \
"xvmaddadp        %%vs26, %%vs38, %%vs52        \n\t" \
"xvmaddadp        %%vs27, %%vs39, %%vs52        \n\t" \
"xvmaddadp        %%vs28, %%vs40, %%vs52        \n\t" \
"xvmaddadp        %%vs29, %%vs41, %%vs52        \n\t" \
"                                               \n\t" \
"                                               \n\t" \
"xvmaddadp        %%vs30, %%vs36, %%vs53        \n\t" \
"xvmaddadp        %%vs31, %%vs37, %%vs53        \n\t" \
"xvmaddadp        %%vs32, %%vs38, %%vs53        \n\t" \
"xvmaddadp        %%vs33, %%vs39, %%vs53        \n\t" \
"xvmaddadp        %%vs34, %%vs40, %%vs53        \n\t" \
"xvmaddadp        %%vs35, %%vs41, %%vs53        \n\t" \
"                                               \n\t" \
"lxv             %%vs48, 0(%%r8)                \n\t" \
"lxv             %%vs49, 16(%%r8)               \n\t" \
"lxv             %%vs50, 32(%%r8)               \n\t" \
"lxv             %%vs51, 48(%%r8)               \n\t" \
"lxv             %%vs52, 64(%%r8)               \n\t" \
"lxv             %%vs53, 80(%%r8)               \n\t" \
"                                               \n\t" \
"lxv             %%vs36, 0(%%r7)                \n\t" \
"lxv             %%vs37, 16(%%r7)               \n\t" \
"lxv             %%vs38, 32(%%r7)               \n\t" \
"lxv             %%vs39, 48(%%r7)               \n\t" \
"lxv             %%vs40, 64(%%r7)               \n\t" \
"lxv             %%vs41, 80(%%r7)               \n\t" \
"                                               \n\t" \
"addi             %%r8, %%r8, 96                \n\t" \
"addi             %%r7, %%r7, 96                \n\t" \


#define SCALE_ALPHA \
"xvmuldp          %%vs0,  %%vs0,  %%vs62   	 \n\t" \
"xvmuldp          %%vs1,  %%vs1,  %%vs62   	 \n\t" \
"xvmuldp          %%vs2,  %%vs2,  %%vs62   	 \n\t" \
"xvmuldp          %%vs3,  %%vs3,  %%vs62   	 \n\t" \
"xvmuldp          %%vs4,  %%vs4,  %%vs62   	 \n\t" \
"xvmuldp          %%vs5,  %%vs5,  %%vs62   	 \n\t" \
"xvmuldp          %%vs6,  %%vs6,  %%vs62   	 \n\t" \
"xvmuldp          %%vs7,  %%vs7,  %%vs62   	 \n\t" \
"xvmuldp          %%vs8,  %%vs8,  %%vs62   	 \n\t" \
"xvmuldp          %%vs9,  %%vs9,  %%vs62   	 \n\t" \
"xvmuldp          %%vs10, %%vs10, %%vs62   	 \n\t" \
"xvmuldp          %%vs11, %%vs11, %%vs62   	 \n\t" \
"xvmuldp          %%vs12, %%vs12, %%vs62   	 \n\t" \
"xvmuldp          %%vs13, %%vs13, %%vs62   	 \n\t" \
"xvmuldp          %%vs14, %%vs14, %%vs62   	 \n\t" \
"xvmuldp          %%vs15, %%vs15, %%vs62   	 \n\t" \
"xvmuldp          %%vs16, %%vs16, %%vs62   	 \n\t" \
"xvmuldp          %%vs17, %%vs17, %%vs62   	 \n\t" \
"xvmuldp          %%vs18, %%vs18, %%vs62   	 \n\t" \
"xvmuldp          %%vs19, %%vs19, %%vs62   	 \n\t" \
"xvmuldp          %%vs20, %%vs20, %%vs62   	 \n\t" \
"xvmuldp          %%vs21, %%vs21, %%vs62   	 \n\t" \
"xvmuldp          %%vs22, %%vs22, %%vs62   	 \n\t" \
"xvmuldp          %%vs23, %%vs23, %%vs62   	 \n\t" \
"xvmuldp          %%vs24, %%vs24, %%vs62   	 \n\t" \
"xvmuldp          %%vs25, %%vs25, %%vs62   	 \n\t" \
"xvmuldp          %%vs26, %%vs26, %%vs62   	 \n\t" \
"xvmuldp          %%vs27, %%vs27, %%vs62   	 \n\t" \
"xvmuldp          %%vs28, %%vs28, %%vs62   	 \n\t" \
"xvmuldp          %%vs29, %%vs29, %%vs62   	 \n\t" \
"xvmuldp          %%vs30, %%vs30, %%vs62   	 \n\t" \
"xvmuldp          %%vs31, %%vs31, %%vs62   	 \n\t" \
"xvmuldp          %%vs32, %%vs32, %%vs62   	 \n\t" \
"xvmuldp          %%vs33, %%vs33, %%vs62   	 \n\t" \
"xvmuldp          %%vs34, %%vs34, %%vs62   	 \n\t" \
"xvmuldp          %%vs35, %%vs35, %%vs62   	 \n\t" 

#define DCOL_SCALE_BETA \
"xvmuldp          %%vs36, %%vs36, %%vs63   	 \n\t" \
"xvmuldp          %%vs37, %%vs37, %%vs63   	 \n\t" \
"xvmuldp          %%vs38, %%vs38, %%vs63   	 \n\t" \
"xvmuldp          %%vs39, %%vs39, %%vs63   	 \n\t" \
"xvmuldp          %%vs40, %%vs40, %%vs63   	 \n\t" \
"xvmuldp          %%vs41, %%vs41, %%vs63   	 \n\t" \
"xvmuldp          %%vs42, %%vs42, %%vs63   	 \n\t" \
"xvmuldp          %%vs43, %%vs43, %%vs63   	 \n\t" \
"xvmuldp          %%vs44, %%vs44, %%vs63   	 \n\t" \
"xvmuldp          %%vs45, %%vs45, %%vs63   	 \n\t" \
"xvmuldp          %%vs46, %%vs46, %%vs63   	 \n\t" \
"xvmuldp          %%vs47, %%vs47, %%vs63   	 \n\t" \
"xvmuldp          %%vs48, %%vs48, %%vs63   	 \n\t" \
"xvmuldp          %%vs49, %%vs49, %%vs63   	 \n\t" \
"xvmuldp          %%vs50, %%vs50, %%vs63   	 \n\t" \
"xvmuldp          %%vs51, %%vs51, %%vs63   	 \n\t" \
"xvmuldp          %%vs52, %%vs52, %%vs63   	 \n\t" \
"xvmuldp          %%vs53, %%vs53, %%vs63   	 \n\t" \

#define DGEN_SCALE_BETA \
"xvmuldp          %%vs36, %%vs36, %%vs63   	 \n\t" \
"xvmuldp          %%vs37, %%vs37, %%vs63   	 \n\t" \
"xvmuldp          %%vs38, %%vs38, %%vs63   	 \n\t" \
"xvmuldp          %%vs39, %%vs39, %%vs63   	 \n\t" \
"xvmuldp          %%vs40, %%vs40, %%vs63   	 \n\t" \
"xvmuldp          %%vs41, %%vs41, %%vs63   	 \n\t"

#define DGEN_LOAD_C \
"lxsdx	          %%vs36, %%r9, %%r22        \n\t" \
"lxsdx            %%vs37, 0, %%r22           \n\t" \
"xxpermdi         %%vs36, %%vs36, %%vs37, 0  \n\t" \
"lxsdx	          %%vs37, %%r9, %%r23        \n\t" \
"lxsdx            %%vs38, 0, %%r23           \n\t" \
"xxpermdi         %%vs37, %%vs37, %%vs38, 0  \n\t" \
"lxsdx	          %%vs38, %%r9, %%r24        \n\t" \
"lxsdx            %%vs39, 0, %%r24           \n\t" \
"xxpermdi         %%vs38, %%vs38, %%vs39, 0  \n\t" \
"lxsdx	          %%vs39, %%r9, %%r25        \n\t" \
"lxsdx            %%vs40, 0, %%r25           \n\t" \
"xxpermdi         %%vs39, %%vs39, %%vs40, 0  \n\t" \
"lxsdx	          %%vs40, %%r9, %%r26        \n\t" \
"lxsdx            %%vs41, 0, %%r26           \n\t" \
"xxpermdi         %%vs40, %%vs40, %%vs41, 0  \n\t" \
"lxsdx	          %%vs41, %%r9, %%r27        \n\t" \
"lxsdx            %%vs42, 0, %%r27           \n\t" \
"xxpermdi         %%vs41, %%vs41, %%vs42, 0  \n\t"

#define DGEN_NEXT_COL_CMATRIX \
"add             %%r22, %%r22, %%r10             \n\t" \
"add             %%r23, %%r23, %%r10             \n\t" \
"add             %%r24, %%r24, %%r10             \n\t" \
"add             %%r25, %%r25, %%r10             \n\t" \
"add             %%r26, %%r26, %%r10             \n\t" \
"add             %%r27, %%r27, %%r10             \n\t"

#define DGENLOAD_SCALE_UPDATE \
DGEN_LOAD_C  \
DGEN_NEXT_COL_CMATRIX \
DGEN_SCALE_BETA

#define DCOL_STORE \
"stxv              %%vs0,   0(%%r16)          \n\t" \
"stxv              %%vs1,  16(%%r16)          \n\t" \
"stxv              %%vs2,  32(%%r16)          \n\t" \
"stxv              %%vs3,  48(%%r16)          \n\t" \
"stxv              %%vs4,  64(%%r16)          \n\t" \
"stxv              %%vs5,  80(%%r16)          \n\t" \
"stxv              %%vs6,   0(%%r17)          \n\t" \
"stxv              %%vs7,  16(%%r17)          \n\t" \
"stxv              %%vs8,  32(%%r17)          \n\t" \
"stxv              %%vs9,  48(%%r17)          \n\t" \
"stxv              %%vs10, 64(%%r17)          \n\t" \
"stxv              %%vs11, 80(%%r17)          \n\t" \
"stxv              %%vs12,  0(%%r18)          \n\t" \
"stxv              %%vs13, 16(%%r18)          \n\t" \
"stxv              %%vs14, 32(%%r18)          \n\t" \
"stxv              %%vs15, 48(%%r18)          \n\t" \
"stxv              %%vs16, 64(%%r18)          \n\t" \
"stxv              %%vs17, 80(%%r18)          \n\t" \
"stxv              %%vs18,  0(%%r19)          \n\t" \
"stxv              %%vs19, 16(%%r19)          \n\t" \
"stxv              %%vs20, 32(%%r19)          \n\t" \
"stxv              %%vs21, 48(%%r19)          \n\t" \
"stxv              %%vs22, 64(%%r19)          \n\t" \
"stxv              %%vs23, 80(%%r19)          \n\t" \
"stxv              %%vs24,  0(%%r20)          \n\t" \
"stxv              %%vs25, 16(%%r20)          \n\t" \
"stxv              %%vs26, 32(%%r20)          \n\t" \
"stxv              %%vs27, 48(%%r20)          \n\t" \
"stxv              %%vs28, 64(%%r20)          \n\t" \
"stxv              %%vs29, 80(%%r20)          \n\t" \
"stxv              %%vs30,  0(%%r21)          \n\t" \
"stxv              %%vs31, 16(%%r21)          \n\t" \
"stxv              %%vs32, 32(%%r21)          \n\t" \
"stxv              %%vs33, 48(%%r21)          \n\t" \
"stxv              %%vs34, 64(%%r21)          \n\t" \
"stxv              %%vs35, 80(%%r21)          \n\t"

#define COL_SCALE_BETA_TEST \
"lxv              %%vs36,  0(%%r16)             \n\t"\
"lxv              %%vs42,  0(%%r17)             \n\t" \
"lxv              %%vs48,  0(%%r18)             \n\t" \
"lxv              %%vs41, 80(%%r16)             \n\t" \
"lxv              %%vs47, 80(%%r17)             \n\t" \
"lxv              %%vs53, 80(%%r18)             \n\t"\
"lxv              %%vs37, 16(%%r16)             \n\t" \
"lxv              %%vs38, 32(%%r16)             \n\t" \
"lxv              %%vs39, 48(%%r16)             \n\t" \
"lxv              %%vs40, 64(%%r16)             \n\t" \
"lxv              %%vs43, 16(%%r17)             \n\t" \
"lxv              %%vs44, 32(%%r17)             \n\t" \
"lxv              %%vs45, 48(%%r17)             \n\t" \
"lxv              %%vs46, 64(%%r17)             \n\t" \
"lxv              %%vs49, 16(%%r18)             \n\t" \
"lxv              %%vs50, 32(%%r18)             \n\t" \
"lxv              %%vs51, 48(%%r18)             \n\t" \
"lxv              %%vs52, 64(%%r18)             \n\t" \
"                                               \n\t"\
"xvmaddadp           %%vs0,  %%vs36,  %%vs63    \n\t"\
"xvmaddadp           %%vs6,  %%vs42,  %%vs63    \n\t"\
"xvmaddadp          %%vs12,  %%vs48,  %%vs63    \n\t"\
"xvmaddadp           %%vs5,  %%vs41,  %%vs63    \n\t"\
"xvmaddadp          %%vs11,  %%vs47,  %%vs63    \n\t"\
"xvmaddadp          %%vs17,  %%vs53,  %%vs63    \n\t"\
"xvmaddadp           %%vs1,  %%vs37,  %%vs63    \n\t"\
"xvmaddadp           %%vs2,  %%vs38,  %%vs63    \n\t"\
"xvmaddadp           %%vs3,  %%vs39,  %%vs63    \n\t"\
"xvmaddadp           %%vs4,  %%vs40,  %%vs63    \n\t"\
"xvmaddadp           %%vs7,  %%vs43,  %%vs63    \n\t"\
"xvmaddadp           %%vs8,  %%vs44,  %%vs63    \n\t"\
"xvmaddadp           %%vs9,  %%vs45,  %%vs63    \n\t"\
"xvmaddadp          %%vs10,  %%vs46,  %%vs63    \n\t"\
"xvmaddadp          %%vs13,  %%vs49,  %%vs63    \n\t"\
"xvmaddadp          %%vs14,  %%vs50,  %%vs63    \n\t"\
"xvmaddadp          %%vs15,  %%vs51,  %%vs63    \n\t"\
"xvmaddadp          %%vs16,  %%vs52,  %%vs63    \n\t"\
"                                               \n\t"\
"lxv              %%vs36,  0(%%r19)             \n\t"\
"lxv              %%vs42,  0(%%r20)             \n\t"\
"lxv              %%vs48,  0(%%r21)             \n\t"\
"lxv              %%vs41, 80(%%r19)             \n\t"\
"lxv              %%vs47, 80(%%r20)             \n\t"\
"lxv              %%vs53, 80(%%r21)             \n\t"\
"lxv              %%vs37, 16(%%r19)             \n\t"\
"lxv              %%vs38, 32(%%r19)             \n\t"\
"lxv              %%vs39, 48(%%r19)             \n\t"\
"lxv              %%vs40, 64(%%r19)             \n\t"\
"lxv              %%vs43, 16(%%r20)             \n\t"\
"lxv              %%vs44, 32(%%r20)             \n\t"\
"lxv              %%vs45, 48(%%r20)             \n\t"\
"lxv              %%vs46, 64(%%r20)             \n\t"\
"lxv              %%vs49, 16(%%r21)             \n\t"\
"lxv              %%vs50, 32(%%r21)             \n\t"\
"lxv              %%vs51, 48(%%r21)             \n\t"\
"lxv              %%vs52, 64(%%r21)             \n\t"\
"                                               \n\t"\
"xvmaddadp          %%vs18,  %%vs36,  %%vs63    \n\t"\
"xvmaddadp          %%vs24,  %%vs42,  %%vs63    \n\t"\
"xvmaddadp          %%vs30,  %%vs48,  %%vs63    \n\t"\
"xvmaddadp          %%vs23,  %%vs41,  %%vs63    \n\t"\
"xvmaddadp          %%vs29,  %%vs47,  %%vs63    \n\t"\
"xvmaddadp          %%vs35,  %%vs53,  %%vs63    \n\t"\
"xvmaddadp          %%vs19,  %%vs37,  %%vs63    \n\t"\
"xvmaddadp          %%vs20,  %%vs38,  %%vs63    \n\t"\
"xvmaddadp          %%vs21,  %%vs39,  %%vs63    \n\t"\
"xvmaddadp          %%vs22,  %%vs40,  %%vs63    \n\t"\
"xvmaddadp          %%vs25,  %%vs43,  %%vs63    \n\t"\
"xvmaddadp          %%vs26,  %%vs44,  %%vs63    \n\t"\
"xvmaddadp          %%vs27,  %%vs45,  %%vs63    \n\t"\
"xvmaddadp          %%vs28,  %%vs46,  %%vs63    \n\t"\
"xvmaddadp          %%vs31,  %%vs49,  %%vs63    \n\t"\
"xvmaddadp          %%vs32,  %%vs50,  %%vs63    \n\t"\
"xvmaddadp          %%vs33,  %%vs51,  %%vs63    \n\t"\
"xvmaddadp          %%vs34,  %%vs52,  %%vs63    \n\t"


#define COL_SCALE_BETA_TEST_2 \
"lxv              %%vs36,  0(%%r16)             \n\t"\
"lxv              %%vs42,  0(%%r17)             \n\t"\
"lxv              %%vs48,  0(%%r18)             \n\t"\
"lxv              %%vs41, 80(%%r16)             \n\t"\
"lxv              %%vs47, 80(%%r17)             \n\t"\
"lxv              %%vs53, 80(%%r18)             \n\t"\
"lxv              %%vs37, 16(%%r16)             \n\t"\
"lxv              %%vs38, 32(%%r16)             \n\t"\
"lxv              %%vs39, 48(%%r16)             \n\t"\
"lxv              %%vs40, 64(%%r16)             \n\t"\
"lxv              %%vs43, 16(%%r17)             \n\t"\
"lxv              %%vs44, 32(%%r17)             \n\t"\
"lxv              %%vs45, 48(%%r17)             \n\t"\
"lxv              %%vs46, 64(%%r17)             \n\t"\
"lxv              %%vs49, 16(%%r18)             \n\t"\
"lxv              %%vs50, 32(%%r18)             \n\t"\
"lxv              %%vs51, 48(%%r18)             \n\t"\
"lxv              %%vs52, 64(%%r18)             \n\t"\
"                                               \n\t"\
"xvmaddadp           %%vs0,  %%vs36,  %%vs63    \n\t"\
"xvmaddadp           %%vs1,  %%vs37,  %%vs63    \n\t"\
"xvmaddadp           %%vs2,  %%vs38,  %%vs63    \n\t"\
"xvmaddadp           %%vs3,  %%vs39,  %%vs63    \n\t"\
"xvmaddadp           %%vs4,  %%vs40,  %%vs63    \n\t"\
"xvmaddadp           %%vs5,  %%vs41,  %%vs63    \n\t"\
"xvmaddadp           %%vs6,  %%vs42,  %%vs63    \n\t"\
"xvmaddadp           %%vs7,  %%vs43,  %%vs63    \n\t"\
"xvmaddadp           %%vs8,  %%vs44,  %%vs63    \n\t"\
"xvmaddadp           %%vs9,  %%vs45,  %%vs63    \n\t"\
"xvmaddadp          %%vs10,  %%vs46,  %%vs63    \n\t"\
"xvmaddadp          %%vs11,  %%vs47,  %%vs63    \n\t"\
"xvmaddadp          %%vs12,  %%vs48,  %%vs63    \n\t"\
"xvmaddadp          %%vs13,  %%vs49,  %%vs63    \n\t"\
"xvmaddadp          %%vs14,  %%vs50,  %%vs63    \n\t"\
"xvmaddadp          %%vs15,  %%vs51,  %%vs63    \n\t"\
"xvmaddadp          %%vs16,  %%vs52,  %%vs63    \n\t"\
"xvmaddadp          %%vs17,  %%vs53,  %%vs63    \n\t"\
"                                               \n\t"\
"lxv              %%vs36,  0(%%r19)             \n\t"\
"lxv              %%vs42,  0(%%r20)             \n\t"\
"lxv              %%vs48,  0(%%r21)             \n\t"\
"lxv              %%vs41, 80(%%r19)             \n\t"\
"lxv              %%vs47, 80(%%r20)             \n\t"\
"lxv              %%vs53, 80(%%r21)             \n\t"\
"lxv              %%vs37, 16(%%r19)             \n\t"\
"lxv              %%vs38, 32(%%r19)             \n\t"\
"lxv              %%vs39, 48(%%r19)             \n\t"\
"lxv              %%vs40, 64(%%r19)             \n\t"\
"lxv              %%vs43, 16(%%r20)             \n\t"\
"lxv              %%vs44, 32(%%r20)             \n\t"\
"lxv              %%vs45, 48(%%r20)             \n\t"\
"lxv              %%vs46, 64(%%r20)             \n\t"\
"lxv              %%vs49, 16(%%r21)             \n\t"\
"lxv              %%vs50, 32(%%r21)             \n\t"\
"lxv              %%vs51, 48(%%r21)             \n\t"\
"lxv              %%vs52, 64(%%r21)             \n\t"\
"                                               \n\t"\
"xvmaddadp          %%vs18,  %%vs36,  %%vs63    \n\t"\
"xvmaddadp          %%vs19,  %%vs37,  %%vs63    \n\t"\
"xvmaddadp          %%vs20,  %%vs38,  %%vs63    \n\t"\
"xvmaddadp          %%vs21,  %%vs39,  %%vs63    \n\t"\
"xvmaddadp          %%vs22,  %%vs40,  %%vs63    \n\t"\
"xvmaddadp          %%vs23,  %%vs41,  %%vs63    \n\t"\
"xvmaddadp          %%vs24,  %%vs42,  %%vs63    \n\t"\
"xvmaddadp          %%vs25,  %%vs43,  %%vs63    \n\t"\
"xvmaddadp          %%vs26,  %%vs44,  %%vs63    \n\t"\
"xvmaddadp          %%vs27,  %%vs45,  %%vs63    \n\t"\
"xvmaddadp          %%vs28,  %%vs46,  %%vs63    \n\t"\
"xvmaddadp          %%vs29,  %%vs47,  %%vs63    \n\t"\
"xvmaddadp          %%vs30,  %%vs48,  %%vs63    \n\t"\
"xvmaddadp          %%vs31,  %%vs49,  %%vs63    \n\t"\
"xvmaddadp          %%vs32,  %%vs50,  %%vs63    \n\t"\
"xvmaddadp          %%vs33,  %%vs51,  %%vs63    \n\t"\
"xvmaddadp          %%vs34,  %%vs52,  %%vs63    \n\t"\
"xvmaddadp          %%vs35,  %%vs53,  %%vs63    \n\t"

#define COL_SCALE_BETA_TEST_3 \
"lxv              %%vs36,  0(%%r16)             \n\t" \
"lxv              %%vs37, 16(%%r16)             \n\t" \
"lxv              %%vs38, 32(%%r16)             \n\t" \
"lxv              %%vs39, 48(%%r16)             \n\t" \
"lxv              %%vs40, 64(%%r16)             \n\t" \
"lxv              %%vs41, 80(%%r16)             \n\t" \
"lxv              %%vs42,  0(%%r17)             \n\t" \
"lxv              %%vs43, 16(%%r17)             \n\t" \
"lxv              %%vs44, 32(%%r17)             \n\t" \
"lxv              %%vs45, 48(%%r17)             \n\t" \
"lxv              %%vs46, 64(%%r17)             \n\t" \
"lxv              %%vs47, 80(%%r17)             \n\t" \
"lxv              %%vs48,  0(%%r18)             \n\t" \
"lxv              %%vs49, 16(%%r18)             \n\t" \
"lxv              %%vs50, 32(%%r18)             \n\t" \
"lxv              %%vs51, 48(%%r18)             \n\t" \
"lxv              %%vs52, 64(%%r18)             \n\t" \
"lxv              %%vs53, 80(%%r18)             \n\t"\
"                                               \n\t"\
"xvmaddadp           %%vs0,  %%vs36,  %%vs63    \n\t"\
"lxv              %%vs36,  0(%%r19)             \n\t"\
"xvmaddadp           %%vs1,  %%vs37,  %%vs63    \n\t"\
"lxv              %%vs37, 16(%%r19)             \n\t"\
"xvmaddadp           %%vs2,  %%vs38,  %%vs63    \n\t"\
"lxv              %%vs38, 32(%%r19)             \n\t"\
"xvmaddadp           %%vs3,  %%vs39,  %%vs63    \n\t"\
"lxv              %%vs39, 48(%%r19)             \n\t"\
"xvmaddadp           %%vs4,  %%vs40,  %%vs63    \n\t"\
"lxv              %%vs40, 64(%%r19)             \n\t"\
"xvmaddadp           %%vs5,  %%vs41,  %%vs63    \n\t"\
"lxv              %%vs41, 80(%%r19)             \n\t"\
"xvmaddadp           %%vs6,  %%vs42,  %%vs63    \n\t"\
"lxv              %%vs42,  0(%%r20)             \n\t"\
"xvmaddadp           %%vs7,  %%vs43,  %%vs63    \n\t"\
"lxv              %%vs43, 16(%%r20)             \n\t"\
"xvmaddadp           %%vs8,  %%vs44,  %%vs63    \n\t"\
"lxv              %%vs44, 32(%%r20)             \n\t"\
"xvmaddadp           %%vs9,  %%vs45,  %%vs63    \n\t"\
"lxv              %%vs45, 48(%%r20)             \n\t"\
"xvmaddadp          %%vs10,  %%vs46,  %%vs63    \n\t"\
"lxv              %%vs46, 64(%%r20)             \n\t"\
"xvmaddadp          %%vs11,  %%vs47,  %%vs63    \n\t"\
"lxv              %%vs47, 80(%%r20)             \n\t"\
"xvmaddadp          %%vs12,  %%vs48,  %%vs63    \n\t"\
"lxv              %%vs48,  0(%%r21)             \n\t"\
"xvmaddadp          %%vs13,  %%vs49,  %%vs63    \n\t"\
"lxv              %%vs49, 16(%%r21)             \n\t"\
"xvmaddadp          %%vs14,  %%vs50,  %%vs63    \n\t"\
"lxv              %%vs50, 32(%%r21)             \n\t"\
"xvmaddadp          %%vs15,  %%vs51,  %%vs63    \n\t"\
"lxv              %%vs51, 48(%%r21)             \n\t"\
"xvmaddadp          %%vs16,  %%vs52,  %%vs63    \n\t"\
"lxv              %%vs52, 64(%%r21)             \n\t"\
"xvmaddadp          %%vs17,  %%vs53,  %%vs63    \n\t"\
"lxv              %%vs53, 80(%%r21)             \n\t"\
"                                               \n\t"\
"                                               \n\t"\
"xvmaddadp          %%vs18,  %%vs36,  %%vs63    \n\t"\
"xvmaddadp          %%vs19,  %%vs37,  %%vs63    \n\t"\
"xvmaddadp          %%vs20,  %%vs38,  %%vs63    \n\t"\
"xvmaddadp          %%vs21,  %%vs39,  %%vs63    \n\t"\
"xvmaddadp          %%vs22,  %%vs40,  %%vs63    \n\t"\
"xvmaddadp          %%vs23,  %%vs41,  %%vs63    \n\t"\
"xvmaddadp          %%vs24,  %%vs42,  %%vs63    \n\t"\
"xvmaddadp          %%vs25,  %%vs43,  %%vs63    \n\t"\
"xvmaddadp          %%vs26,  %%vs44,  %%vs63    \n\t"\
"xvmaddadp          %%vs27,  %%vs45,  %%vs63    \n\t"\
"xvmaddadp          %%vs28,  %%vs46,  %%vs63    \n\t"\
"xvmaddadp          %%vs29,  %%vs47,  %%vs63    \n\t"\
"xvmaddadp          %%vs30,  %%vs48,  %%vs63    \n\t"\
"xvmaddadp          %%vs31,  %%vs49,  %%vs63    \n\t"\
"xvmaddadp          %%vs32,  %%vs50,  %%vs63    \n\t"\
"xvmaddadp          %%vs33,  %%vs51,  %%vs63    \n\t"\
"xvmaddadp          %%vs34,  %%vs52,  %%vs63    \n\t"\
"xvmaddadp          %%vs35,  %%vs53,  %%vs63    \n\t"
