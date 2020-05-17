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

// Constructor copia
/*pixel::pixel(const pixel & pixel_a_copiar){
	color = pixel_a_copiar.color;
	pos.set_real((pixel_a_copiar.get_pos()).get_real());
	pos.set_img((pixel_a_copiar.get_pos()).get_img());
}*/

// Destructor. En este caso no hace nada porque no se pide memoria.
pixel::~pixel(){}	

// Setters y Getters
void pixel::set_color(const int A){
	color = A;
}

void pixel::set_pos(const double arg_real, const double arg_img){
	pos.set_real(arg_real);
	pos.set_img(arg_img);
}

void pixel::set_pos(const complejo arg_complejo){	// Setter de pos pero pasandole un complejo

	double r = arg_complejo.get_real();
	double i = arg_complejo.get_img();
	pos.set_real(r);
	pos.set_img(i);
}

int pixel::get_color(){
	return color;
}

complejo pixel::get_pos(){
	return pos;
}

// Printer
void pixel::print_pixel(){
	pos.print_complejo();
	cout << " " << color << endl;
}

void pixel::print_color(){
	cout << color << endl;
}