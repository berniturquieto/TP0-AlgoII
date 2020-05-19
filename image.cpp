#include<iostream>
#include "image.h"

using namespace std;

// Constructor por defecto
image::image(){

  size[0]=0;    //ancho
  size[1]=0;    // alto
  greyscale=0;
  this->matrix=NULL;
}

// Constructor por parametro
image::image(const int w, const int h, const int gs, int ** matrix){

    int max = 0;
    size[0] = w;
    size[1] = h;
    greyscale = gs;
    if(w<h){max = h;} else{max = w;}

    this->matrix = new int*[max+1];
    for (int i = 0; i < max; i++){  // Crea la matriz de enteros y los llena con ceros
      this->matrix[i] = new int[max+1];   // Hay que tener en cuenta q la matriz va a ser cuadrada
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

  if(size[0]<size[1]){max = size[1];} else{max = size[0];}

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
  size[0] = A;
}

int image::get_width(){
  return size[0];
}

void image::set_height(const int A){
  size[1] = A;
}

int image::get_height(){
  return size[1];
}

void image::set_greyscale(const int A){
  greyscale = A;
}

int image::get_greyscale(){
  return greyscale;
}



void image::printMatrix(){
  int max=0;

  if(size[0]<size[1]){max = size[1];} else{max = size[0];}

  for(int x=0 ; x<max ; x++){
    for(int y=0 ; y<max ; y++) {
      cout << this->matrix[x][y] << " ";
    }
    cout << endl;
  }
}

void image::printMatrix(ostream *os){

    int max=0;
    if(size[0]<size[1]){max = size[1];} else{max = size[0];}

    *os << "P2"<<'\n'<<max<<" "<<max<<'\n'<<greyscale<<'\n';
    if (os->bad()) {
        cerr << "cannot write to output stream."
        << endl;
        exit(1);
    }

    for(int x=0;x<max;x++)
    {
        for(int y=0;y<max;y++) {
            *os << this->matrix[x][y];
            *os << " ";
                if (os->bad()) {
                    cerr << "cannot write to output stream."
                    << endl;
                    exit(1);
                }            
        }

        *os<<std::endl;
        if (os->bad()) {
            cerr << "cannot write to output stream."
            << endl;
            exit(1);
        } 
    }
}


void image::fill_matrix(int ** matrix){
    int max=0;
    int h=size[1];
    if(size[0]<size[1]){max = size[1];} else{max = size[0];}

    this->matrix = new int*[max];

    for (int i=0 ; i<max ; i++){  // Crea la matriz de enteros y los llena con ceros
      this->matrix[i] = new int[max];   // Hay que tener en cuenta q la matriz va a ser cuadrada
    }                               // Por eso se pide dos veces de dimension "max"

    cout << "Max: " << max << ", " << "Height: " << h<< endl;

    for (int i = 0; i < max; i++){    // raws// Rellena la matris con color negro 
        for (int j = 0; j < max; j++){  // co
            //cout << "i: " << i << ", " << "j: "<< j <<endl;
            if ( i<((max-h)/2) || i>((max+h)/2)-1 ){
              //cout << "aca1"<< endl;
              this->matrix[i][j] = 0;
            }else{
              //cout << "aca2" << endl;
              this->matrix[i][j] = matrix[i-(h+1)][j];
            }
        }
    }

}
