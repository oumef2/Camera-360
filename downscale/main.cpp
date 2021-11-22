#include<iostream>
#include<fstream>
#include"downscale.cpp"


using namespace std;

int_fixed image[1074*1074];

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
	cout << "size of init image is: "<< tx << "\n";
	f >> temp;
	int a; 
	for(int i = 0; i < tx*ty; i++){
		f >> a;
		image[i] = a;
	}
	cout <<"first pixel of image is: "<< image[0]<<"\n";
	f.close();

	int_fixed downscale_image[osize*osize];
	downscale(image, downscale_image);
	cout << "end downscaled \n";

	//save results in pgm file
	ofstream of("1_downscaled_o.pgm",ios::out);
	of << "P2" <<endl;
	
	of << osize <<" "<< osize <<endl;
	of << temp<<endl;

	for(int i = 0; i < osize*osize; i++){
		of << downscale_image[i]<<"\n";
	}
	cout <<"downscale image saved.";
	of.close();
	return 0;
}
