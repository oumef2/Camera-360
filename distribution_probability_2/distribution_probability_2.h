#ifndef MI_INCLUDE
#define MI_INCLUDE
#include"../ac_fixed.h"

//size of the input
const int x = 80; 
const int y = 80; 

#define DATA_WIDTH 8
typedef ac_fixed<DATA_WIDTH,DATA_WIDTH,false,AC_RND_INF,AC_SAT> int_fixed;
typedef ac_fixed<32, 32,false,AC_RND_INF,AC_SAT> long_fixed;
typedef ac_fixed<32,0,false,AC_RND_INF,AC_SAT> float_fixed;
typedef ac_fixed<16,0,false,AC_RND_INF,AC_SAT> double_fixed;



//design function
//calculate the distibution of each pixel and its correspending pixel in the image
void disparity_probability_2(int_fixed img1[x*y], int_fixed img2[x*y], long_fixed dst[126*126]);

#endif 
