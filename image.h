#ifndef _IMAGE_H_INCLUIDO_
#define _IMAGE_H_INCLUIDO_

#include <iostream>
#include "complejo.h"

using namespace std;

class image{
  private:
	int size [2]; //ancho y alto
  	int greyscale;
  	int **matrix;

	public:

    // Contructores
  	image(); // Por defecto
  	image(const int, const int, const int, int **);  // Constructor por argument
      //image(); // Constructor copia
  	~image();  // Destructor
  	

  	// Setters y getters
    void set_width(const int);
   	int get_width();
    void set_height(const int);
    int get_height();
    void set_greyscale(const int );
    int get_greyscale();
    void printMatrix();
    void printMatrix(ostream*);
    void fill_matrix(int **);

    // Metodos
    //aca va el metodo que llene la matriz de ints
};

#endif