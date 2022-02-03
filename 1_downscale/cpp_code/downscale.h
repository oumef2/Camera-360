#ifndef DOWNSCALE_INCLUDE
#define DOWNSCALE_INCLUDE
#include"../../ac_fixed.h"

#define ox 80 
#define oy 80

#define ix 320
#define iy 240 

#define xscale  4 //divide(ix, ox);
#define yscale 3//divide(iy, oy);

#define DATA_WIDTH 8
typedef ac_fixed<DATA_WIDTH,DATA_WIDTH,false,AC_RND_INF,AC_SAT> int_fixed;
typedef ac_fixed<32, 32,false,AC_RND_INF,AC_SAT> long_fixed;
typedef ac_fixed<32,0,false,AC_RND_INF,AC_SAT> float_fixed;

extern int_fixed image_right[ix*iy];
extern int_fixed imange_left[ix*iy];
//down sizing an image using simple average methode. input:
//		source is the source image to down size 
//		out_size is and integer meaning the size of the output is (out_size,out_size)
void downscale(int_fixed src[ix*iy],int_fixed dst[ox*oy], int_fixed img_out[ix*iy]);

void ImgProcTest(int_fixed img_in[ix*iy], int_fixed img_out[ix*iy]);
#endif 
