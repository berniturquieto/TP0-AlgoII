#include<iostream>
#include "image.h"

using namespace std;

// Constructor por defecto
image::image(){

  
  width=0;    //ancho
  height=0;    // alto
  greyscale=0;
  //cout<<"aca"<<endl;
  //this->matrix = NULL;
  //cout<<"Termino de construir"<<endl;
}

// Constructor por parametro
image::image(const int w, const int h, const int gs){ //matriz cuadrada

    int max = 0;
    width = w;
    height = h;
    greyscale = gs;
    if(w<h){max = h;} else{max = w;}

    this->matrix = new int*[max+1];
    for (int i = 0; i < max; i++){  // Crea la matriz de enteros y los llena con ceros
      this->matrix[i] = new int[max+1];   // Hay que tener en cuenta q la matriz va a ser cuadrada
    }                               // Por eso se pide dos veces de dimension "max"

    for (int i = 0; i < max; i++){    // raws// Rellena la matris con color negro 
        for (int j = 0; j < max; j++){  // co
          this->matrix[i][j] = 0;
            /*if (i<((max-h)/2) || i>((max+h)/2)-1){
              this->matrix[i][j] = 0;
            }else{
              this->matrix[i][j] = matrix[i-(h+1)][j];
            }*/
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

int image::get_max_dim(){
  if(width < height) {return height;}
  else{return width;}
}

void image::set_matrix_value(const int & i,const int & j,const int & aux_color){
  matrix[i][j]=aux_color;
}

int image::get_matrix_value(const int & i,const int & j){
  return matrix[i][j];
}




void image::printMatrix(){
  int max=0;

  if(width<height){max = height;} else{max = width;}

  for(int x=0 ; x<max ; x++){
    for(int y=0 ; y<max ; y++) {
      cout << this->matrix[x][y] << " ";
    }
    cout << endl;
  }
}

void image::print_image(ostream *os){

    int max=0;
    if(width<height){max = height;} else{max = width;}

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

/* Este metodo pide memoria y llena la matriz mediante el argumento
se supone que tiene las dimensiones cargadas*/
void image::fill_matrix(int ** matrix){
    int max=0;
    bool IS_VERTICAL = true;
   
    max = get_max_dim();
    if (width>height)
      IS_VERTICAL=false;

    this->matrix = new int*[max]; // Pidio memoria
    for (int i=0 ; i<max ; i++){
      this->matrix[i] = new int[max];
    }
    
    for (int i = 0; i < max; i++) // Recorro la matriz cuadrada
    {
        for (int j = 0; j < max; j++)
        {
          if (IS_VERTICAL) // Para imagenes vertical
          {
            if ( j<((max-width)/2) || j>((max+width)/2)-1 )
              this->matrix[i][j] = 0;
            else{
              this->matrix[i][j] = matrix[i][j-(max-width)/2];
            }
          }
          else    // Para imagenes horizontal
          {
            if ( i<((max-height)/2) || i>((max+height)/2)-1 )
              this->matrix[i][j] = 0;
            else
              this->matrix[i][j] = matrix[i-(max-height)/2][j];
          } 
        }
    }
}
