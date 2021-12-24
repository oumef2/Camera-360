#ifndef MI_INCLUDE
#define MI_INCLUDE
#include"../ac_fixed.h"

//size of the input
const int x = 80; 
const int y = 80; 

#define DATA_WIDTH 8
typedef ac_fixed<DATA_WIDTH,DATA_WIDTH,false,AC_RND_INF,AC_SAT> int_fixed;
typedef ac_fixed<16,16,false,AC_RND_INF,AC_SAT> midium_fixed;
typedef ac_fixed<32, 32,false,AC_RND_INF,AC_SAT> long_fixed;

//design function

void wrap(int_fixed img[x*y], char disp[x*y], int_fixed dst[x*y]);

#endif 
