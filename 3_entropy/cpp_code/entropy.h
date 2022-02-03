#ifndef MI_INCLUDE
#define MI_INCLUDE
#include"../../ac_fixed.h"

//size of the input
#define ox 80 
#define oy 80

#define ix 320
#define iy 240

#define max_pixels 256/2


#define DATA_WIDTH 8
typedef ac_fixed<DATA_WIDTH,DATA_WIDTH,false,AC_RND_INF,AC_SAT> int_fixed;
typedef ac_fixed<16,16,false,AC_RND_INF,AC_SAT> midium_fixed;
typedef ac_fixed<32, 32,false,AC_RND_INF,AC_SAT> long_fixed;

typedef ac_fixed<32,0,false,AC_RND_INF,AC_SAT> float_fixed;
typedef ac_fixed<32,16,false,AC_RND_INF,AC_SAT> double_fixed;

const double_fixed test[9] = {-3.32193, -2.32193, -1.73697, -1.32193, -1.0 , -0.736966, -0.514573, -0.321928, -0.152003};

//design function
extern int_fixed image_right [ox*oy];
extern int_fixed image_left [ox*oy];

void ImgProcTest(int_fixed img_in[ix*iy], int_fixed img_out[ix*iy]);
void entropy(int_fixed img[ox*oy],double_fixed entropy[ox*oy]);
void distribution_probability(int_fixed img[ox*oy], midium_fixed dst[max_pixels]);
double_fixed mylog2(double_fixed m);
double_fixed mylog2_top(double_fixed w);
double_fixed mylog2_down(double_fixed w);
#endif 
