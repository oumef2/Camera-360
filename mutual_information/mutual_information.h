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
typedef ac_fixed<32, 8,false,AC_RND_INF,AC_SAT> double_fixed;
//add calculated histogram here 
midium_fixed hist1[126]; 
midium_fixed hist2[126];
long_fixed hist12[126*126];

//design function
void mutual_information(int_fixed img1[x*y], int_fixed img2[x*y], int_fixed dst[x*y]);

#endif 
