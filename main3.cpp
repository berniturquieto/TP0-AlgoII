#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <cstdlib>

#include "cmdline.h"


#include "image.h"

using namespace std;
complejo ** complex_matrix(double);
int * binary_search(complejo, complejo **, int [2], int [2]);


//static ostream *oss = 0;	// Output Stream (clase para manejo de los flujos de salida)
//static fstream ofs;		// Output File Stream (derivada de la clase ofstream que deriva de ostream para el manejo de archivos)

int main(void ){
/*	cmdline cmdl(options);	// Objeto con parametro tipo option_t (struct) declarado globalmente. Ver línea 51 main.cc
	cmdl.parse(argc, argv); // Metodo de parseo de la clase cmdline
*/
	int w = 1, h = 5, gs = 10, max=0;
	int * pos;
	int in_lim[2];
	int fin_lim[2];
	int ** matrix;
	complejo ** matrix_c;
	complejo c(0.34,-0.78);

 /*	matrix = new int*[h];
  	for (int i = 0; i < h; i++){  // Crea la matriz de enteros y los llena con ceros
  	    matrix[i] = new int[w];   // Hay que tener en cuenta q la matriz va a ser cuadrada
  	    cout<<i;
  	}    

	for (int i=0; i<w; i++){
		matrix[i][0]=5;
	}
	cout<<"Imagen original"<<endl;
	for(int x=0;x<h;x++){
        for(int y=0;y<w;y++) {
            std::cout << matrix[x][y];
            std::cout << " ";
        }

        std::cout<<std::endl;
    }
	cout<<"Imagen original cuadrada"<<endl;


	image *image_in = new image();
	cout<<"paso"<<endl;

	image_in->set_greyscale(gs);
	image_in->set_width(w);
	image_in->set_height(h);
	image_in->fill_matrix(matrix);


	image_in->printMatrix();


*/
	/*if(w<h){max = h;} else{max = w;}
	max=10;
	matrix_c=complex_matrix(max);

    for(int x=0;x<max;x++){
        for(int y=0;y<max;y++) {
            matrix_c[x][y].print_complejo();  
            cout<<" ";
        }
        cout<<endl;

        std::cout<<std::endl;
    }*/

   /* ofs.open("prueba.pgm", ios::out);
    oss = &ofs;
    

    // Verificamos que el stream este OK.
    //
    if (!oss->good()) {
        cerr << "cannot open "
             << "."
             << endl;
        exit(1);        // EXIT: Terminación del programa en su totalidad
    }
    image_in.print_image(oss);


   */
	c= c.exponencial();

    in_lim[0]=0;
    in_lim[1]=0;
    fin_lim[0]=max-1;
    fin_lim[1]=max-1;
    c.print_complejo();

    //cout<<in_lim[0]<<fin_lim[0]<<";"<<in_lim[1]<<fin_lim[1]<<"El complejo en el centro es:"<<endl;

	int medio_x = (fin_lim[0]-in_lim[0])/2;//L + (R - L) / 2
	int medio_y = (fin_lim[1]-in_lim[1])/2;   
	//cout<<"medios"<<medio_x<<medio_y<<endl; 
    //cout<<(matrix_c[medio_x][medio_y]).get_real()<<endl;

    pos = binary_search(c,matrix_c,in_lim,fin_lim);
    if (pos !=NULL){
    	cout<<"lo encontro en :"<<pos[1]<<","<<pos[0]<<endl;
    	cout<<"y vale :"<<endl;
    	(matrix_c[pos[1]][pos[0]]).print_complejo();
    	cout<<endl;
    }else{
    	cout<<"ERROR"<<endl;
    }
    
    //delete image_in;
	return 0;
}





complejo ** complex_matrix(double max){

	complejo ** matrix;
	
	matrix = new complejo*[(int)max];	// Pido memoria para la matriz
 	for (int i = 0; i < max; i++){	
      matrix[i] = new complejo[(int)max];
  	}

	double paso=2/(max-1);
	double aux_real=-1;
	double aux_imag=1;
  	for (int i = 0; i < max; i++){    // raws// Rellena la matris con color negro 
    	for (int j = 0; j < max; j++){  // co
    		matrix[i][j]=complejo(aux_real,aux_imag);
    		aux_real=aux_real+paso;
      	}
      	aux_real=-1;
      	aux_imag=aux_imag-paso;
      
    }
    return matrix;
}




int * binary_search(complejo c, complejo ** matrix, int in_lim[2], int fin_lim[2]){//ini [x0,y0] fin [xf,yf]
	

	//cout<<"iniciales;"<<in_lim[0]<<","<<in_lim[1]<<"  finales:"<<fin_lim[0]<<","<<fin_lim[1]<<endl;

	if (in_lim[0]>fin_lim[0] || in_lim[1]>fin_lim[1]){
		return NULL;
	}

	if(c.get_real() >1 || c.get_img() > 1){
		return NULL;
	}

	if ((fin_lim[0]-in_lim[0]) == 1 && (fin_lim[1]-in_lim[1]) == 1){


		if (abs(c.get_real() - (matrix[in_lim[1]][in_lim[0]]).get_real()) > abs(c.get_real() - (matrix[fin_lim[1]][fin_lim[0]]).get_real())){
			in_lim[0] = fin_lim[0];
		}
		if (abs(c.get_img() - (matrix[in_lim[1]][in_lim[0]]).get_img()) > abs(c.get_img() - (matrix[fin_lim[1]][fin_lim[0]]).get_img())){
			in_lim[1] = fin_lim[1];
		}
		return in_lim;
	}

	int medio_x = in_lim[0]+(fin_lim[0]-in_lim[0])/2;
	int medio_y = in_lim[1]+(fin_lim[1]-in_lim[1])/2; 
	//cout<<"medio actual:  ";
	//matrix[medio_y][medio_x].print_complejo();
	//cout<<endl;
	if (c.get_real()>= (matrix[medio_y][medio_x]).get_real()){
		in_lim[0] = medio_x;
		if (c.get_img()>= (matrix[medio_y][medio_x]).get_img()){
			fin_lim[1] = medio_y;
			return binary_search(c, matrix, in_lim, fin_lim);
		}else{
			in_lim[1] = medio_y;
			return binary_search(c, matrix, in_lim, fin_lim);
		}

	}else{
		fin_lim[0] = medio_x;
		if (c.get_img()>=(matrix[medio_y][medio_x]).get_img()){
			fin_lim[1] = medio_y;
			return binary_search(c, matrix, in_lim, fin_lim);
		}else{
			in_lim[1] = medio_y;
			return binary_search(c, matrix, in_lim, fin_lim);
		}
	}	
}
