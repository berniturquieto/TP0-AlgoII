#include<iostream>
#include "pixel.h"

using namespace std;

// Constructor por defecto
pixel::pixel(){
	color = 0;
	pos.set_real(0);
	pos.set_img(0);
}

// Constructor donde se le pasa parte real, img y el color.
pixel::pixel(const double arg_real, const double arg_img, const int arg_color){
	color = arg_color;
	pos.set_real(arg_real);
	pos.set_img(arg_img);
}

pixel::pixel(const & pixel){

}

// Destructor. En este caso no hace nada porque no se pide memoria
pixel::~pixel(){}	

// Setters y Getters
pixel::set_color(const int A){
	color = A;
}

pixel::set_pos(const double arg_real, const double arg_img){
	pos.set_real(arg_real);
	pos.set_img(arg_img);
}

pixel::set_pos(const complejo arg_complejo){	// Setter de pos pero pasandole un complejo
	pos.set_real(arg_complejo.get_real());
	pos.set_img(arg_complejo.get_img());	// ESTO LO PUEDO HACER ASI O VA CON "->" ?
}

int pixel::get_color(){
	return color;
}

complejo pixel::get_pos(){
	return pos;
}