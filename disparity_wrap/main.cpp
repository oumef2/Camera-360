#include<iostream>
#include<fstream>
#include"wrap.cpp"


using namespace std;
void read_img(string path, int_fixed img[x*y]);
void read_img(string path, char img[x*y]);


int main()
{
    int_fixed right_image[x*y];
    char disparity_map[x*y];

	//read image_2 pgm and disp
    read_img("../data1/right_downscaled.pgm", right_image);
    read_img("../data1/disparity_map.pgm", disparity_map);
   

	int_fixed wrapped_image[x*y];
    wrap(right_image, disparity_map, wrapped_image);
	cout << "end of image wrapping \n";

	//save results in pgm file
	ofstream of("../data/right_wrapped.pgm",ios::out);
	of << "P2" <<endl;
	
	of << x <<" "<< y <<endl;
	of << 255 <<endl;

	for(int i = 0; i < x*y; i++){
		of << wrapped_image[i]<<"\n";
	}
	cout <<"wrapped image saved.";
	of.close();
	return 0;
}


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
