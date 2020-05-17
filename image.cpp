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

// Constructor por parametro
image::image(const int w, const int h, const int gs){


  width = w;
  height = h;
  greyscale = gs;

  if(w<h){int max = h;} else{int max = w;}

  matrix = new pixel*[max];
  for (int i = 0; i < max; i++){  // Crea la matriz de enteros y los llena con ceros
      matrix[i] = new pixel[max];   // Hay que tener en cuenta q la matriz va a ser cuadrada
  }                               // Por eso se pide dos veces de dimension "max"

  for (int i = 0, i < max, i++){
    for (int j = 0; j < max; j++){  
      matrix[i][j].set_color(0);
    }
  }
}

// CONSTRUCTOR COPIA HACEMOS?


// Destructor
/* Pregunto si matrix no es nula, si no lo es, 
recorro cada lugar y pregunto si no es nulo. 
Si no es nulo hago free. Despues de recorrer 
todo el vector de matrix, hago free de matrix.*/
image::~image(){ 
  int max = 0;

  if(width<height){max = height;} else{max = width;}

  if (matrix){                
    for (i=0; i<max; i++){    
      if (matrix[i]){          
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


/*
void image::printMatrix(){
  if(w<h){max = h;} else{max = w;}
    for(int x=0;x<max;x++)
    {
        for(int y=0;y<this->max;y++) {
            std::cout << this->matrix[x][y].get_color();
            std::cout << " ";
        }

        std::cout<<std::endl;
    }
}*/