#include<iostream>
#include<fstream>
#include"downscale.cpp"


using namespace std;

int image[1074*1074];

int main()
{
	//read image pgm
	char format[2];
	int temp;
	ifstream f("1.pgm",ios::in);
	f >> format;
	int tx,ty;
	f >> tx;
	f >> ty;
	cout << tx << "\n";
	f >> temp;
	
	for(int i = 0; i < tx*ty; i++){
		f >> image[i];
	}
	cout << image[0]<<"\n";
	f.close();

	int downscale_image[osize*osize];
	downscale(image, downscale_image);
	cout << "end downscaled \n";

	//save results in pgm file
	ofstream of("1_downscaled_order.pgm",ios::out);
	of << format <<"\n";
	
	of << osize <<" "<< osize <<"\n";
	of << temp<<"\n";

	for(int i = 0; i < osize*osize; i++){
		of << downscale_image[i]<<"\n";
	}
	cout <<"downscale image saved.";
	of.close();
	return 0;
}
