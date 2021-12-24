#include<iostream>
#include<fstream>
#include"downscale.cpp"


using namespace std;
void read_img(string path, int_fixed img[ix*iy]);

int_fixed left_image[ix*iy];
int_fixed right_image[ix*iy];
int_fixed display_image[ix*iy];
int main()
{
	//read lest image image pgm
	read_img("../data/left.pgm",left_image);
	read_img("../data/right.pgm",right_image);

	//downscale left image
	int_fixed downscale_image[ox*oy];
	downscale(left_image, downscale_image, display_image);
	cout << "left image downscaled \n";

	//save results in pgm file
	ofstream of("../data/left_downscaled.pgm",ios::out);
	of << "P2" <<endl;
	of << ix <<" "<< iy <<endl;
	of << 255 <<endl;
	for(int i = 0; i < ox*oy; i++){
		of << downscale_image[i]<<"\n";
	}
	cout <<"left_downscaled image saved.";
	of.close();

	//downscale right image
	downscale(right_image, downscale_image, display_image);
	cout << "right image downscaled \n";

	//save results in pgm file
	ofstream of("../data/right_downscaled.pgm",ios::out);
	of << "P2" <<endl;
	of << ix <<" "<< iy <<endl;
	of << 255 <<endl;
	for(int i = 0; i < ox*oy; i++){
		of << downscale_image[i]<<"\n";
	}
	cout <<"right_downscaled image saved.";
	of.close();


	return 0;
}


void read_img(string path, int_fixed img[ix*iy]){
    //read image_1 pgm
	char format[2];
	int temp;
	ifstream f(path,ios::in);
	f >> format;
	int tx,ty;
	f >> tx; f >> ty;
    if (tx != ix || ty != iy){
    	cout << "size of init image is: "<< tx << "\n"; 
    }
    f >> temp;
	int a; 
	for(int i = 0; i < ix*iy; i++){
		f >> a; img[i] = a;
	}
	cout <<"first pixel of"<< path<<" is: "<< img[0]<<"\n";
	f.close();
}
