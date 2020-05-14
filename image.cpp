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
image::image(int w, int h, int gs){

  int max = 0;
  width = w;
  height = h;
  greyscale = gs;

  if(w<h){
     max = h;
  }
  else{
    max = w;
  }

  matrix = new pixel*[max];
  for (int i = 0; i < max; i++){
      matrix[i] = new pixel[max];
  }

  for (int i = 0, i < max, i++){
    for (int j = 0; i < max; ++i)
    {
      matrix[i][j] = 0;
    }
  }
}


// Destructor

/*image::~image(){
  for (int i=0,,i++){

  }

}*/


// Setter y getters

image::set_width(int A){
  width = A;
}

int image::get_width(){
  return width;
}

image::set_heigth(int A){
  height = A;
}

int image::get_height(){
  return height;
}

image::set_greyscale(int A){
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

image::color2black(image & img){

}










