
// Include files for data types
#include "math.h"
#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std ;
#include "mc_scverify.h"
#include "../../ac_fixed.h"
#include "downscale.h"

/* Pour  Compilation et exécution sur PC */
//#define CCS_MAIN main
//#define CCS_DESIGN(d) d

CCS_MAIN(int argc, char **argv) {
	ifstream simg_in("img_in.pgm");
  	ofstream simg_out("img_out.pgm");
  	char  type[128], tmp[128];
  	int sx, sy;
	ac_fixed<DATA_WIDTH,DATA_WIDTH,false,AC_RND_INF,AC_SAT> img_in[ix*iy];
	ac_fixed<DATA_WIDTH,DATA_WIDTH,false,AC_RND_INF,AC_SAT> img_out[ix*iy];
 	/*
	Lecture fichier entree
	*/
	if (simg_in.is_open()) printf("file opened\n");
	simg_in.getline(type, 128);
	simg_in.getline(tmp, 128);
	while (tmp[0]== '#') simg_in.getline(tmp, 128);
	sscanf(tmp, "%d %d\n", &sx, &sy);
	printf( "%d %d\n", sx, sy);
	int level;
	simg_in>>level;
	int data;
	for(int i=0; i<sx*sy;i++)
   	{
	 	simg_in >> data;
	 	img_in[i]=data;
	 	
   	}
	/* Execute traitement */
	CCS_DESIGN(ImgProcTest)(img_in, img_out) ;

	/*
	Fichier sortie
	*/
	simg_out << "P2" << endl;
	simg_out << ix<< " ";
	simg_out << iy<< endl;
	simg_out <<  255 << endl;
	for(int i=0; i<ix*iy;i++)
	{
		simg_out <<  img_out[i].to_int() << endl;
	}
	return 0;
}
