#include<iostream>
#include<fstream>
#include"cpp_code/downscale.cpp"


using namespace std;

int_fixed image[ix*iy];
int_fixed image1[ix*iy];
int main()
{
	//read image pgm
	char format[2];
	int temp;
	ifstream f("../data1/0_left.pgm",ios::in);
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
	//write image array
	/*
	ofstream txt("/data/image2.txt",ios::out);
	txt<< "image_2 = {";
	for (int i=0; i< tx*ty; i++){
		txt << image[i] <<", ";
	}
    txt.close();
*/
	int_fixed downscale_image[ox*oy];
	downscale(image, downscale_image, image1);
	cout << "end downscaled \n";

	//save results in pgm file
	ofstream of("show.pgm",ios::out);
	of << "P2" <<endl;
	
	of << ix <<" "<< iy <<endl;
	of << temp<<endl;

	for(int i = 0; i < ix*iy; i++){
		of << image1[i]<<"\n";
	}
	cout <<"downscale vision saved.";
	of.close();
	return 0;
}
