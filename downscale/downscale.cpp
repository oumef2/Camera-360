#include "downscale.h"
using namespace std;


void downscale(int_fixed src[],int_fixed dst[])
{
	//division de isize by 256 (2^8)
	int scale = (isize >>8);
	long_fixed sum = 0;

	//average sum calclulations 
	for (int x=0; x<osize; x++)
	{
		for (int y=0; y<osize; y++)
		{
			dst[x + osize*y]=0;
			sum = 0;
			for (int i=x*scale; i<(x+1)*scale; i++)
			{
				for (int j=y*scale; j<(y+1)*scale; j++){
					sum = sum +src[i+ isize*j];
				}
			}
			sum >>= 4;
			dst[x + osize*y]= sum;
		}
	}
}

