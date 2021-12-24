#include<iostream>
#include<fstream>
#include"distribution_probability_2.cpp"


using namespace std;
void read_img(string path, int_fixed img[x*y]);

int main()
{
    int_fixed right_img[x*y];
	int_fixed left_img[x*y];

	//read image_2 pgm and disp
    read_img("../data/left_downscaled.pgm", left_img);
    read_img("../data/right_wrapped.pgm", right_img);

	long_fixed histogram[126*126];
	distribution_probability_2(right_img,left_img, histogram);
	cout << "end distribution probability calculations \n";

	//save results in txt file
	ofstream txt("../data/histogram.txt",ios::out);
	for (int i=0; i< 126*126; i++){
		txt << histogram[i] <<" ";
	}
    txt.close();
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


