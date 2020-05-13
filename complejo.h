#ifndef _COMPLEJO_H_INCLUIDO_
#define _COMPLEJO_H_INCLUIDO_

#include <iostream>

using namespace std;

class Complejo{

public:

	// CONSTRUCTORES Y DESTRUCTORES
	Complejo(); // Constructor por defecto
	Complejo(const double , const double ); // Constructor normal, usa doubles
	Complejo(const Complejo &); // Constructor por copia, simplemente copia los dos valores de un complejo a otro
	~Complejo(); // Destructor, no tiene que destruir nada porque no pedimos memoria

	// SETTERS Y GETTERS
	void set_real(const double);
	void set_img(const double);
	double get_real();
	double get_img();
	double get_modulo();
	double get_angulo();

	// PRINTER
	void print_complejo();

	// TRANSFORMACIONES
	Complejo conjugar (); // Conjuga el complejo

	// OPERADORES
	Complejo operator + (const Complejo &); // Suma de complejos
	Complejo operator + (const double &);
	Complejo operator - (const Complejo &); // Resta de complejos
	Complejo operator - (const double &);
	Complejo operator * (const Complejo &); // Multiplicacion de complejos
	Complejo operator * (const double &);
	Complejo operator / (const Complejo &); // Division de complejos
	Complejo operator / (const double &);
	Complejo & operator = (const Complejo &); // Operador =

	// FUNCIONES
	Complejo exponencial ();


private:
	double real; // Dos atributos, real e imaginario, se explica solo
	double img;

};

#endif