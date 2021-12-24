#include<iostream>
#include<fstream>
#include"distribution_probability.cpp"
using namespace std;


void read_img(string path, int_fixed img[x*y]);

int main()
{
    int_fixed right_img[x*y];
	int_fixed left_img[x*y];

	//read image_2 pgm and disp
    read_img("../data/right_wrapped.pgm", right_img);
    read_img("../data/left_downscaled.pgm", left_img);

	midium_fixed right_histogram[128];
	midium_fixed left_histogram[128];
	distribution_probability(right_img, right_histogram);
	distribution_probability(left_img, left_histogram);
	cout << "end distribution probability calculations \n";

	//save results in txt file
	ofstream txt("../data/left_histogram.txt",ios::out);
	for (int i=0; i< 128; i++){
		txt << left_histogram[i] <<" , ";
	}
    txt.close();

	ofstream txt1("../data/right_histogram.txt",ios::out);
	for (int i=0; i< 128; i++){
		txt1 << right_histogram[i] <<" , ";
	}
    txt1.close();
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
    	cout << "size of "<< path<<" is: "<< tx << "\n"; 
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


