#ifndef MI_INCLUDE
#define MI_INCLUDE
#include"../../ac_fixed.h"

//size of the input
#define ox 80 
#define oy 80

#define ix 320
#define iy 240 

#define DATA_WIDTH 8
typedef ac_fixed<DATA_WIDTH,DATA_WIDTH,false,AC_RND_INF,AC_SAT> int_fixed;
typedef ac_fixed<16,16,false,AC_RND_INF,AC_SAT> midium_fixed;
typedef ac_fixed<32, 32,false,AC_RND_INF,AC_SAT> long_fixed;

extern int_fixed img[ox*oy];
extern char disparity_mapo[ox*oy];
//design function
void ImgProcTest(int_fixed img_in[ix*iy], int_fixed img_out[ix*iy]);
void wrap(int_fixed img[ox*oy], char disp[ox*oy], int_fixed dst[ox*oy]);
//disparity map 
#endif 
