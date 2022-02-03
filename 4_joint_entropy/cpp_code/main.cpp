#include<iostream>
#include<fstream>
#include"joint_entropy.cpp"


using namespace std;

int main()
{
    int_fixed img[ix*iy];
	int_fixed img_in[ix*iy];
	ImgProcTest(img_in,img);
	cout << "end joint entropy calc \n";

	//save results in pgm file
	ofstream of("show.pgm",ios::out);
	of << "P2" <<endl;
	
	of << ix <<" "<< iy <<endl;
	of << 255 <<endl;

	for(int i = 0; i < ix*iy; i++){
		of << img[i]<<"\n";
	}
	cout <<"joint entropy saved.";
	of.close();
}






