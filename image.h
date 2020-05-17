#ifndef _IMAGE_H_INCLUIDO_
#define _IMAGE_H_INCLUIDO_

#include <iostream>
//#include "pixel.h"
#include "complejo.h"

using namespace std;

class image{
  private:
	int width;
  	int height;
  	int greyscale;
  	int **matrix;

	public:

    // Contructores
  	image(); // Por defecto
  	image(const int, const int, const int);  // Constructor por argument
    //image(); // Constructor copia
  	~image();  // Destructor
  	

  	// Setters y getters
	void set_width(const int);
   	int get_width();
    void set_height(const int);
    int get_height();
    void set_greyscale(const int );
    int get_greyscale();

    // Metodos
    //aca va el metodo que llene la matriz de ints
};

#endif