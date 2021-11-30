#ifndef DOWNSCALE_INCLUDE
#define DOWNSCALE_INCLUDE
#include"ac_fixed.h"

const int ox = 80; 
const int oy = 80; 

const int ix = 320; 
const int iy = 240; 


#define DATA_WIDTH 8
typedef ac_fixed<DATA_WIDTH,DATA_WIDTH,false,AC_RND_INF,AC_SAT> int_fixed;
typedef ac_fixed<32, 32,false,AC_RND_INF,AC_SAT> long_fixed;
//down sizing an image using simple average methode. input:
//		source is the source image to down size 
//		out_size is and integer meaning the size of the output is (out_size,out_size)
void downscale(int_fixed src[ix*iy],int_fixed dst[ox*oy]);

#endif 
