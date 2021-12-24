#include"wrap.h"
using namespace std;


void wrap(int_fixed img[x*y], char disp[x*y], int_fixed dst[x*y]){
    for (int i =0; i<x ;i++)
    {
        for(int j=0;j<y ;j++){
            int d = disp[i + x*j];
            //move the current pixel to the cordinates of the correspending pixel
            if ( i+d < x) dst[i+x*j] = img[i+d + x*j];
            //for the pixels with no correspending pixels in range 
            else dst[i+x*j] = 255;
        }
    }
}