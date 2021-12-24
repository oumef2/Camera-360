#include"mutual_information.h"
using namespace std;



void mutual_information(int_fixed img1[x*y], int_fixed img2[x*y], int_fixed dst[x*y])
{
    //size 1/(80*80)
    double_fixed a = 0;
    //MI(I1;I2) = H(I1) + H(I2) - H(I1;I2)

    // calculate the cost 
    for (int i=0 ; i<x ;i++ )
    {
        for(int j=0;j<y ;j++)
        {
            //the pixel and the correspending pixel intencities 
            int p = img1[i +x*j].to_int();
            int q = img2[i +x*j].to_int();
            //calculate mi(i,j) = h(i) + h(j) - h(i;j) and Cmi = -mi 
            double_fixed H1 = -log((hist1[p] * a).to_double());
            double_fixed H2 = -log((hist2[q]* a).to_double());
            double_fixed H12 = -log((hist12[(p,q)]*a).to_double());
            //add -mi(i,j) to the cost
            dst[i+x*j] = - (H1 +H2 -H12)* a;
            
        }
    }
}

double log(double u){
    double s=0.0; 
    double a=0.5; 
    for(int i=0; i<16; i++) {
        u=u*u; 
        if(u>2) { 
            u=u>>1; 
            s+=a; 
        }
        a*=0.5; 
    } 
    return s;
}