#ifndef _IMAGE_H_INCLUIDO_
#define _IMAGE_H_INCLUIDO_

#include <iostream>

using namespace std;

class image{
  private:
		int width;
  	int heigth;
  	int greyscale;
  	int **matrix;

	public:

    // Contructores
  	image(); // Por defecto
  	image(const int, const int, const int);  // Constructor por argument
    image(); // Constructor copia
  	~image();  // Destructor
  	

  	// Setters y getters
		set_width(const int);
   	int get_width();
    set_heigth(const int);
    int get_heigth();
    setgreyscale(const int );
    int get_greyscale();

    // Metodos
    //aca va el metodo que llene la matriz de ints
}

#endif