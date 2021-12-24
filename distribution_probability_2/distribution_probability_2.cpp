#include"distribution_probability_2.h"
using namespace std;



void distribution_probability_2(int_fixed img1[x*y],int_fixed img2[x*y], long_fixed dst[126*126]){
    int_fixed p, q;
    for(int i=0; i<126*126; i++) dst[i] = 0;
    for (int i =0 ;i<x*y; i++){
        //divide the pixels by 2 to lower memory usage
        p = img1[i]>>1;
        q = img2[i]>>1;
        dst[p.to_int() + 126*q.to_int()] ++;
    }
}
