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
image::image(const int w, const int h, const int gs, int ** matrix){

  int max = 0;
  width = w;
  height = h;
  greyscale = gs;

  if(w<h){max = h;} else{max = w;}

  this->matrix = new int*[max];
  for (int i = 0; i < max; i++){  // Crea la matriz de enteros y los llena con ceros
      this->matrix[i] = new int[max];   // Hay que tener en cuenta q la matriz va a ser cuadrada
  }                               // Por eso se pide dos veces de dimension "max"

  for (int i = 0; i < max; i++){    // raws// Rellena la matris con color negro 
    for (int j = 0; j < max; j++){  // co
      if (i<((max-h)/2) || i>((max+h)/2)-1){
        this->matrix[i][j] = 0;
      }else{
        this->matrix[i][j] = matrix[i-(h+1)][j];
      }
      
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
    for (int i = 0; i<max; i++){    
      if (matrix[i]){          
        delete[] matrix[i];
      }
    }
  }
  delete[] matrix;
}


// Setter y getters

void image::set_width(const int A){
  width = A;
}

int image::get_width(){
  return width;
}

void image::set_height(const int A){
  height = A;
}

int image::get_height(){
  return height;
}

void image::set_greyscale(const int A){
  greyscale = A;
}

int image::get_greyscale(){
  return greyscale;
}



void image::printMatrix(){
  int max=0;
  if(width<height){max = height;} else{max = width;}
    for(int x=0;x<max;x++)
    {
        for(int y=0;y<max;y++) {
            std::cout << this->matrix[x][y];
            std::cout << " ";
        }

        std::cout<<std::endl;
    }
}