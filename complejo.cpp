#include<iostream>
#include "complejo.h"
#include <math.h>

using namespace std;

// Constructor por defecto
Complejo::Complejo(){ 
	real = 0;
	img = 0;
}

// Constructor normal, primer argumento es real, segundo es img.
Complejo::Complejo(const double arg_real, const double arg_img){
	real = arg_real;
	img = arg_img;
}

// Constructor por copia, simplemente copia los dos valores de un complejo a otro
Complejo::Complejo(const complejo & arg_complejo){
	real = arg_complejo.real;
	img = arg_complejo.img;
}

// Destructor
Complejo::~Complejo(){

}

// Setters
void Complejo::set_real(const double arg_real){
	real = arg_real;	
}

void Complejo::set_img(const double arg_img){
	img = arg_img;
}

// Getters
double Complejo::get_real(void){
	return real;
}

double Complejo::get_img(void){
	return img;
}

double Complejo::get_modulo(){
	return sqrt((this->real)*(this->real) + (this->img)*(this->img));
}

double Complejo::get_angulo(){
	return atan((this->img)/(this->real));
}

// Printer
void Complejo::print_complejo(){
	cout << real << "+" << img << "i" << endl;
}

// CONJUGAR
Complejo Complejo::conjugar (){
	Complejo aux;
	aux.real = this->real;
	aux.img = -(this->img);
	return aux;
}

// Operador SUMA
Complejo Complejo::operator + (const complejo & complejo_a_sumar){
	Complejo aux;
	aux.real = (this->real) + complejo_a_sumar.real;
	aux.img = (this->img) + complejo_a_sumar.img;
	return aux;
}

Complejo complejo::operator + (const double & double_a_sumar){
	Complejo aux;
	aux.real = (this->real) + double_a_sumar;
	aux.img = (this->img);
	return aux;
}

// Operador RESTA
Complejo Complejo::operator - (const Complejo & complejo_a_restar){
	Complejo aux;
	aux.real = (this->real) - complejo_a_restar.real;
	aux.img = (this->img) - complejo_a_restar.img;
	return aux;
}

// Operador RESTA
Complejo Complejo::operator - (const double & double_a_restar){
	Complejo aux;
	aux.real = (this->real) - double_a_restar;
	aux.img = (this->img);
	return aux;
}

// Operador MULTIPLICACION
Complejo Complejo::operator * (const Complejo & A){
	Complejo aux;
	aux.real = (this->real * A.real) - (this->img * A.img);
	aux.img = (this->real * A.img) + (this->img * A.real);
	return aux;
}

Complejo Complejo::operator * (const double & A){
	Complejo aux;
	aux.real = (this->real * A);
	aux.img = (this->img * A);
	return aux;
}

// Operador DIVISION
Complejo Complejo::operator / (const Complejo & divisor){
	Complejo aux;
	double a = this->real;
	double b = this->img;
	double c = divisor.real;
	double d = divisor.img;

	aux.real = (a*c)/(c*c + d*d) + (b*d)/(c*c + d*d);
	aux.img = (b*c)/(c*c + d*d) - (a*d)/(c*c + d*d);
	return aux;
}

Complejo Complejo::operator / (const double & divisor){
	Complejo aux;
	aux.real = this->real / divisor;
	aux.img = this->img / divisor;
	return aux;
}

// Operador IGUAL
Complejo & Complejo::operator = (const Complejo & complejo_a_igualar){
	real=complejo_a_igualar.real;
	img=complejo_a_igualar.img;
	return *this;
}

 // Funciones

Complejo & Complejo::exponencial(const Complejo & c){
  Complejo aux;
  double modulo = exp(c.real);
  double angulo = c.img;
  aux.real = modulo*cos(angulo);
  aux.img = modulo*sin(angulo);
  return Complejo( );
}























