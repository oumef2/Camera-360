#include<iostream>
#include<fstream>
#include"cpp_code/wrap.cpp"


using namespace std;
//void read_img(string path, int_fixed img[x*y]);
//void read_img(string path, char img[x*y]);


int main()
{
    int_fixed img[ix*iy];

	//read image_2 pgm and disp
    //read_img("../data1/downscaled_right.pgm", img2);
    //read_img("../data1/disparity_map_init.pgm", disp);
    /*
	//write image array
	ofstream txt("/data/image2.txt",ios::out);
	txt<< "image_2 = {";
	for (int i=0; i< tx*ty; i++){
		txt << image[i] <<", ";
	}
    txt.close();
    */  

	int_fixed wrapped_image[ix*iy];
    ImgProcTest(img, wrapped_image);
	cout << "end mutual information cost calculations \n";

	//save results in pgm file
	ofstream of("show.pgm",ios::out);
	of << "P2" <<endl;
	
	of << ix <<" "<< iy <<endl;
	of << 255 <<endl;

	for(int i = 0; i < ix*iy; i++){
		of << wrapped_image[i]<<"\n";
	}
	cout <<"wrapped image saved.";
	of.close();
	return 0;
}

/*
void read_img(string path, int_fixed img[x*y]){
    //read image_1 pgm
	char format[2];
	int temp;
	ifstream f(path,ios::in);
	f >> format;
	int tx,ty;
	f >> tx;
	f >> ty;
    if (tx != x || ty != y){
    	cout << "size of init image is: "<< tx << "\n"; 
    }
    f >> temp;
	int a; 
	for(int i = 0; i < x*y; i++){
		f >> a;
		img[i] = a;
	}
	cout <<"first pixel of"<< path<<" is: "<< img[0]<<"\n";
	f.close();
}



void read_img(string path, char img[x*y]){
    //read image_1 pgm
	char format[2];
	int temp;
	ifstream f(path,ios::in);
	f >> format;
	int tx,ty;
	f >> tx;
	f >> ty;
    if (tx != x || ty != y){
    	cout << "size of init image is: "<< tx << "\n"; 
    }
    f >> temp;
	int a; 
	for(int i = 0; i < x*y; i++){
		f >> a;
		img[i] = a;
	}
	cout <<"first pixel of"<< path<<" is: "<< img[0]<<"\n";
	f.close();
}
*/