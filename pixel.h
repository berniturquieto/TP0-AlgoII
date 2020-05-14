#ifndef _IMAGE_H_INCLUIDO_
#define _IMAGE_H_INCLUIDO_

#include <iostream>

using namespace std;

class pixel {	
  private:

  	complejo pos;	// Posicion del pixel, tenemos que ver como seteamos esto, no lo entendemos
  	int color;		// Color en escala de gris

  public:

  	pixel(); // Constructor por defecto
  	pixel(const double, const double, const int ); // Constructor real,img,color
  	pixel(const & pixel); // Constructor copia
  	~pixel();	// Destructor
  
  	set_color(const int);
  	set_pos(const double, const double);
  	set_pos(const complejo);
  	int get_color();
  	complejo get_pos();

  
}

#endif

// un main seria:
/* 
 main{
 	image imagen_original;
 	image imagen_transformada;
 
 	leer imagen_original; aca ya tendria guardada la matriz original, con su matriz de pixeles llenada, los valores de grises leidos. Es una funcion de leer y parsear un archivo. 
  Para los complejos podemos:
  // OPCION UNO: hacer que lo llene directamente la funcion de arriba
  // OPCION DOS: hacer un metodo de la clase imagen que asigne los complejos y hacerlo luego de leerla (recorre la matriz de ints y va asignando).
  
  transformar_imagen(const image & imagen_original, image & imagen_transformada); esta funcion lee de imagen_original cada pixel, aplica la transformacion, hace las comparaciones (ve si cae dentro o fuera) y lo va guardando en imagen transformada.
 
 }
 
 */