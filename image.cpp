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


// SETTERS Y GETTERS

image::set_width(int A){
  width = A;
}

int image::get_width(){
  return width;
}

image::set_heigth(int A){
  heigth = A;
}

int image::get_heigth(){
  return heigth;
}

image::set_greyscale(int A){
  greyscale = A;
}

int image::get_greyscale(){
  return greyscale:
}