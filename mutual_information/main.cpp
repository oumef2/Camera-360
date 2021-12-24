#include<iostream>
#include<fstream>
#include"mutual_information.cpp"


using namespace std;
void read_img(string path, int_fixed img[x*y]);


int main()
{
	int_fixed left_img[x*y];
	int_fixed right_img[x*y];

	//read image_2 pgm and disp
    read_img("../data/left_downscaled.pgm", left_img);
    read_img("../data/right_wrapped.pgm", right_img);
   
	int_fixed cost[x*y];
	mutual_information(left_img, right_img, cost);
	cout << "end mutual information cost calculations \n";

	//save results in pgm file
	ofstream of("../data/cost_mi.pgm",ios::out);
	of << "P2" <<endl;
	
	of << x <<" "<< y <<endl;
	of << 255 <<endl;

	for(int i = 0; i < x*y; i++){
		of << cost[i]<<"\n";
	}
	cout <<"cost saved.";
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
