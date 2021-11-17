#include "downscale.h"
using namespace std;


void downscale(int src[],int dst[])
{
	//division de isize by 256 (2^8)
	int scale = (isize >>8);

	//average sum calclulations 
	for (int x=0; x<osize; x++)
	{
		for (int y=0; y<osize; y++)
		{
			dst[x + osize*y]=0;
			for (int i=x*scale; i<(x+1)*scale; i++)
			{
				for (int j=y*scale; j<(y+1)*scale; j++){
					dst[x + osize*y] += src[i+ isize*j];
				}
			}
			dst[x + osize*y] >>= 4;
		}
	}
}

