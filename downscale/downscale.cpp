#include "downscale.h"
using namespace std;
#pragma hls_design top


void downscale(int_fixed src[ix*iy],int_fixed dst[ox*oy], int_fixed img_out[ix*iy])
{
	//division de isize by 256 (2^8)
	long_fixed sum = 0;
	// pre calculation of xscale*yscale to avoide using devision 
	float_fixed inverse_n=0.08333; 
	//copy the input image to the output
	for (int i=0; i<ix; i++){
	    for( int j=0; j<iy; j++){
	        img_out[i+ix*j] = src[i+ix*j];
	    }     
	}
	//average sum calclulations 
	for (int x=0; x<ox; x++)
	{
		for (int y=0; y<oy; y++)
		{
			//initialise the output pixel by 0 
			dst[x + ox*y] = 0;
			//use a 32bits int to sum to avoid over loading in dst(8bits ints)
			sum = 0;
			for (int i=x*xscale; i<(x+1)*xscale; i++)
			{
				for (int j=y*yscale; j<(y+1)*yscale; j++){
					sum = sum +src[i+ ix*j];
				}
			}
			sum = sum * inverse_n; // division par xscale*yscale
			dst[x + ox*y]= sum;
		}
	}
	//copying the downscaled image on the top right of the output image 
	for (int i=0; i<ox; i++){
	    for( int j=0; j<oy; j++){
	        img_out[i+ix*j] = dst[i+ox*j];
	    }     
	}
}

