#ifndef MI_INCLUDE
#define MI_INCLUDE
#include"../../ac_fixed.h"

//size of the input
#define ox  80
#define oy 80

#define ix 320
#define iy 240

#define max_pixels 256/2

#define DATA_WIDTH 8
typedef ac_fixed<DATA_WIDTH,DATA_WIDTH,false,AC_RND_INF,AC_SAT> int_fixed;
typedef ac_fixed<16,16,false,AC_RND_INF,AC_SAT> midium_fixed;
typedef ac_fixed<32, 32,false,AC_RND_INF,AC_SAT> long_fixed;
typedef ac_fixed<32, 8,false,AC_RND_INF,AC_SAT> double_fixed;

typedef ac_fixed<16,0,false,AC_RND_INF,AC_SAT> float_fixed;

//size 1/(80*80)
const float_fixed a = 0.00015625;
extern double_fixed entropy1[ox*oy];
extern double_fixed entropy2[ox*oy];
extern double_fixed entropy12[ox*oy];
//design function
void ImgProcTest(int_fixed img_in[ix*iy], int_fixed img_out[ix*iy]);
void mutual_information(double_fixed entropy1[ox*oy], double_fixed entropy2[ox*oy],double_fixed entropy12[ox*oy], double_fixed dst[ox*oy]);

#endif 
