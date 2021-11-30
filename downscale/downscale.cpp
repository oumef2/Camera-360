#include "downscale.h"
using namespace std;

int divide(int a, int b){
    if( a-b < 0) return 0;
    else if ( a-b == 0) return 1;
    else 
	{
       return divide(a-b, b) + 1;
    }
}

long_fixed divide(long_fixed a, int b){
	long_fixed tmp = a-b;
    if( tmp < 0) return 0;
    else if ( tmp == 0) return 1;
    else 
	{
		//cout <<tmp <<" :"<<divide(tmp, b) + 1<<endl;
       	return divide(tmp, b) + 1;
    }
}

void downscale(int_fixed src[ix*iy],int_fixed dst[ox*oy])
{
	//division de isize by 256 (2^8)
	int xscale = divide(ix, ox);
	int yscale = divide(iy, oy);
	long_fixed sum = 0;
	//average sum calclulations 
	for (int x=0; x<ox; x++)
	{
		for (int y=0; y<oy; y++)
		{
			dst[x + ox*y] = 0;
			sum = 0;
			for (int i=x*xscale; i<(x+1)*xscale; i++)
			{
				for (int j=y*yscale; j<(y+1)*yscale; j++){
					sum = sum +src[i+ ix*j];
				}
			}
			sum = divide(sum, xscale*yscale);
			dst[x + ox*y]= sum;
		}
	}
}

