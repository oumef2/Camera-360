#include<iostream>
#include<fstream>
#include"entropy.cpp"
using namespace std;


//void read_img(string path, int_fixed img[x*y]);

int main()
{
    int_fixed img[ix*iy];
	int_fixed img_in[ix*iy];
	ImgProcTest(img_in,img);
	cout << "end entropy calc \n";

	//save results in pgm file
	ofstream of("show.pgm",ios::out);
	of << "P2" <<endl;
	
	of << ix <<" "<< iy <<endl;
	of << 255 <<endl;

	for(int i = 0; i < ix*iy; i++){
		of << img[i]<<"\n";
	}
	cout <<"cost saved.";
	of.close();
}




