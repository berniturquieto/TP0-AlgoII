#include <iostream>


#include "image.h"
#include "complejo.h"

using namespace std;
complejo ** complex_matrix(double);

int main(void ){
/*	cmdline cmdl(options);	// Objeto con parametro tipo option_t (struct) declarado globalmente. Ver línea 51 main.cc
	cmdl.parse(argc, argv); // Metodo de parseo de la clase cmdline
*/
	int w = 24, h = 7, gs = 10, max=0;

	int ** matrix;
	complejo ** matrix_c;


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

	if(w<h){max = h;} else{max = w;}
	max=5;
	matrix_c=complex_matrix(max);
    for(int x=0;x<max;x++){
        for(int y=0;y<max;y++) {
            matrix_c[x][y].print_complejo();  
            cout<<" ";
        }
        cout<<endl;

        std::cout<<std::endl;
    }



	return 0;
}




complejo ** complex_matrix(double max){
	complejo ** matrix;

	double aux=max/2;
	matrix = new complejo*[(int)max];

 	for (int i = 0; i < max; i++){  // Crea la matriz de enteros y los llena con ceros
      matrix[i] = new complejo [(int)max];   // Hay que tener en cuenta q la matriz va a ser cuadrada
  	}                               // Por eso se pide dos veces de dimension "max"

  	for (int i = 0; i < max; i++){    // raws// Rellena la matris con color negro 
    	for (int j = 0; j < max; j++){  // co
    		matrix[i][j]=complejo(((j+1)-aux)/aux,-((i+1)-aux)/aux);
      	}
      
    }

    return matrix;
}
