#include<iostream>
#include<fstream>
#include"downscale.cpp"


using namespace std;

int_fixed image[ix*iy];

int main()
{
	//read image pgm
	char format[2];
	int temp;
	ifstream f("data/2_.pgm",ios::in);
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
	ofstream txt("/data/image2.txt",ios::out);
	txt<< "image_2 = {";
	for (int i=0; i< tx*ty; i++){
		txt << image[i] <<", ";
	}
    txt.close();

	int_fixed downscale_image[ox*oy];
	downscale(image, downscale_image);
	cout << "end downscaled \n";

	//save results in pgm file
	ofstream of("data/2_downscaled_v.2.pgm",ios::out);
	of << "P2" <<endl;
	
	of << ox <<" "<< oy <<endl;
	of << temp<<endl;

	for(int i = 0; i < ox*oy; i++){
		of << downscale_image[i]<<"\n";
	}
	cout <<"downscale image saved.";
	of.close();
	return 0;
}
