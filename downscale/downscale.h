#ifndef DOWNSCALE_INCLUDE
#define DOWNSCALE_INCLUDE


const int osize = 256; // 256 ipower 8 of 2 to make division easier 
const int isize = 1024; // 1024 devided by osize else the image might be croped 


//down sizing an image using simple average methode. input:
//		source is the source image to down size 
//		out_size is and integer meaning the size of the output is (out_size,out_size)
void downscale(int src[],int dst[]);

#endif 