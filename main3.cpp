#include <iostream>


#include "image.h"

using namespace std;


int main(int argc, char * const argv[]){
/*	cmdline cmdl(options);	// Objeto con parametro tipo option_t (struct) declarado globalmente. Ver línea 51 main.cc
	cmdl.parse(argc, argv); // Metodo de parseo de la clase cmdline
*/
	int w = 24, h = 7, gs = 10;

	int ** matrix;


  	matrix = new int*[h];
  	for (int i = 0; i < w; i++){  // Crea la matriz de enteros y los llena con ceros
  	    matrix[i] = new int[w];   // Hay que tener en cuenta q la matriz va a ser cuadrada
  	}    

	for (int i=0; i<w; i++){
		matrix[0][i]=1;
		matrix[1][i]=2;
		matrix[6][i]=7;
	}
	cout<<"Imagen original"<<endl;
	for(int x=0;x<h;x++){
        for(int y=0;y<w;y++) {
            std::cout << matrix[x][y];
            std::cout << " ";
        }

        std::cout<<std::endl;
    }


	cout<<"Imagen original cuadrada"<<endl;
	image image_in(w,h,gs,matrix);


	

	image_in.printMatrix();



	return 0;
}