#ifndef DOWNSCALE_INCLUDE
#define DOWNSCALE_INCLUDE
#include"../ac_fixed.h"

//size of output image 
const int ox = 80; 
const int oy = 80; 
//size of input imafe (size of the image given by a raspberry pi camera)
const int ix = 320; 
const int iy = 240; 

const int xscale = 4; // ix / ox
const int yscale = 3; // iy / oy

#define DATA_WIDTH 8
typedef ac_fixed<DATA_WIDTH,DATA_WIDTH,false,AC_RND_INF,AC_SAT> int_fixed;
typedef ac_fixed<32, 32,false,AC_RND_INF,AC_SAT> long_fixed;
typedef ac_fixed<32,0,false,AC_RND_INF,AC_SAT> float_fixed;

//down sizing an image using simple average methode. input:
//		source is the source image to down size 
//      dest is the downsized image
//		output is a visualization of the image and its downsize 
void downscale(int_fixed src[ix*iy],int_fixed dst[ox*oy], int_fixed img_out[ix*iy]);


#endif 
