#include<iostream>
#include<fstream>
#include"cost.cpp"


using namespace std;

int main()
{

	cout << "hello"<<endl;
	int_fixed img_in[ix*iy];
	DispProcTest(img);
	cout << "end cost calc \n";

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
	return 0;
}
