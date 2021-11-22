#ifndef DOWNSCALE_INCLUDE
#define DOWNSCALE_INCLUDE
#include"ac_fixed.h"

const int osize = 256; // 256 ipower 8 of 2 to make division easier 
const int isize = 1024; // 1024 devided by osize else the image might be croped 

#define DATA_WIDTH 8
typedef ac_fixed<DATA_WIDTH,DATA_WIDTH,false,AC_RND_INF,AC_SAT> int_fixed;
typedef ac_fixed<DATA_WIDTH*4,DATA_WIDTH*4,false,AC_RND_INF,AC_SAT> long_fixed;
//down sizing an image using simple average methode. input:
//		source is the source image to down size 
//		out_size is and integer meaning the size of the output is (out_size,out_size)
void downscale(int_fixed src[],int_fixed dst[]);

#endif 
