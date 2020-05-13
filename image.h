#ifndef _IMAGE_H_INCLUIDO_
#define _IMAGE_H_INCLUIDO_

#include <iostream>

using namespace std;

// Lo q se me ocurre es tener dos de estas variables clase image. Una original y otra transformada.

class image{
  private:
		int width;
  	int heigth;
  	int greyscale;
  	pixel **matrix;

	public:
  	image();
  	image();
  	image();
  	~image();
  	
		set_width(int );
    int get_width();
    set_heigth(int );
    int get_heigth();
    set_greyscale(int );
    int get_greyscale();
}

#endif