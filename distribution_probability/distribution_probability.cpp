#include"distribution_probability.h"
using namespace std;



void distribution_probability(int_fixed img[x*y], midium_fixed dst[128]){
    int_fixed p;
    for(int i = 0; i<128; i++) dst[i]=0;
    for (int i =0 ;i<x*y; i++){
        p = img[i]>>1;
        dst[p.to_int()] ++;
    }
}
