#include<iostream>
#include "image.h"

using namespace std;

// Constructor por defecto
image::image(){

  width=0;
  height=0;
  greyscale=0;
  (*matrix) = NULL;
  matrix = NULL;
}

// Constructor normal
image::image(const int w, const int h, const int gs){

  int max = 0;
  width = w;
  height = h;
  greyscale = gs;

  if(w<h){max = h; } else{max = w;}

  matrix = new pixel*[max];
  for (int i = 0; i < max; i++){
      matrix[i] = new pixel[max];
  }

  for (int i = 0, i < max, i++){
    for (int j = 0; i < max; ++i){
      matrix[i][j] = 0;
    }
  }
}

// CONSTRUCTOR COPIA HACEMOS?


// Destructor
image::~image(){              // Pregunto si matrix no es nula, si no lo es, recorro
  if (matrix){                // cada lugar y pregunto si no es nulo. Si no es nulo 
    for (i=0; i<width; i++){  // hago free. Despues de recorrer todo el vector de 
      if (matrix[i]){         // matrix, hago free de matrix.
        delete[] matrix[i];
      }
    }
  }
  delete[] matrix;
}


// Setter y getters

image::set_width(const int A){
  width = A;
}

int image::get_width(){
  return width;
}

image::set_heigth(const int A){
  height = A;
}

int image::get_height(){
  return height;
}

image::set_greyscale(const int A){
  greyscale = A;
}

int image::get_greyscale(){
  return greyscale:
}

/*void image::createMatrix(){

  this->matrix = new int*[this->height];
  for (int i = 0; i < this->height; ++i)
    matrix[i] = new int[this->width];
}

*/

//image::color2black(image & img){

//}