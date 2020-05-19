#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <cstdlib>

#include "cmdline.h"
#include "image.h"

using namespace std;

//************************DECLARACION FUNCIONES************************//

static void opt_input(string const &);
static void opt_output(string const &);
static void opt_function(string const &);
static void opt_help(string const &);
void read_pgm(image &);

//*****************************VARIABLES GLOBALES*****************************//

static istream *iss = 0;	// Input Stream (clase para manejo de los flujos de entrada)
static ostream *oss = 0;	// Output Stream (clase para manejo de los flujos de salida)
static fstream ifs; 		// Input File Stream (derivada de la clase ifstream que deriva de istream para el manejo de archivos)
static fstream ofs;		// Output File Stream (derivada de la clase ofstream que deriva de ostream para el manejo de archivos)

static string PGM_IDENTIFIER = "P2";
static char SKIP_LINE_IDENTIFIER = '#';

static option_t options[] = {
	{1, "i", "input", "-", opt_input, OPT_DEFAULT},
	{1, "o", "output", "-", opt_output, OPT_DEFAULT},
	{1, "f", "function", NULL, opt_function, OPT_DEFAULT},
	{0, "h", "help", NULL, opt_help, OPT_DEFAULT},
	{0, },
};

enum functions {z, expz};
static functions chosen_function = z;

#define FUNCTION_Z "z"
#define FUNCTION_EXPZ "expz"
#define NUL '\0'

//************************FUNCIONES DE CMDLINE************************//

static void opt_input(string const &arg){

	if (arg == "-") {
		iss = &cin;		// Establezco la entrada estandar cin como flujo de entrada
	}
	else {
		ifs.open(arg.c_str(), ios::in);

		iss = &ifs;
	}

	// Verificamos que el stream este OK.
	if (!iss->good()) {
		cerr << "cannot open "
		     << arg
		     << "."
		     << endl;
		exit(1);
	}
}

static void opt_output(string const &arg){

	if (arg == "-") {	// Veo si el input es -, si es: 
		oss = &cout;	// Establezco la salida estandar cout como flujo de salida
	} else {
		ofs.open(arg.c_str(), ios::out);
		oss = &ofs;
	}

	if (!oss->good()) {
		cerr << "cannot open "
		     << arg
		     << "."
		     << endl;
		exit(1);
	}
}

static void opt_function(string const &arg){

  if (arg == FUNCTION_Z || arg == "-") {chosen_function = z;}

  else if (arg == FUNCTION_EXPZ) {chosen_function = expz; }
  else{
    cerr << "Funcion invalida" << endl;
    exit(1);
  }
}

static void opt_help(string const &arg){
	cout << "cmdline -f function [-i file] [-o file]"
	     << endl;
	exit(0);
}

// **********************************MAIN**********************************//

int main(int argc, char * const argv[]){


	cmdline cmdl(options);	// Objeto con parametro tipo option_t (struct) declarado globalmente. Ver línea 51 main.cc
	cmdl.parse(argc, argv); // Metodo de parseo de la clase cmdline

	image input_image;
	image output_image;

	read_pgm(input_image);
	ofs.open("prueba.pgm", ios::out);
    oss = &ofs;
  
    // Verificamos que el stream este OK.

    if (!oss->good()) {
        cerr << "cannot open " << "." << endl;
        exit(1);        // EXIT: Terminación del programa en su totalidad
    }
    cout << "abrio el archivo" << endl;
    //input_image.printMatrix(oss);   ACA HAY SIGSEVVVVVVVVVVVVVVVVVVVVVVV

    switch(chosen_function){  
      case z:                     
        cout<< "elegite z" << endl;
        break;
      case expz: 
        cout<< "elegite expz" << endl;
        break;
      default: 
        cout<< "lo rompite" << endl;
    }

	return 0;
}

// *******************************FUNCIONES**********************************//

/*Esta funcion lee del archivo de input y llena la imagen VACIA que
se le pase como argumento. Se supone que hay un solo comentario y
el pgm esta bien organizado*/
void read_pgm(image & img_arg){
  int aux, aux_size[2], aux_greyscale;
  int i=0, j=0;
  int ** aux_matrix;
  string in_string, temp;		


  getline(*iss, in_string); // Identificador
  in_string.pop_back();
  if (in_string != PGM_IDENTIFIER){
    cerr<< "No es PGM" <<endl;
    exit(1);
  }


  getline(*iss, in_string);   // Supongo que tiene un solo comentario, lo salteo
  if (in_string[0] == SKIP_LINE_IDENTIFIER){
    //cout << "Encontro un comentario" << endl; // Lo salteo
  }


  getline(*iss, in_string); // Dimsensiones
  stringstream ss (in_string);
  while(!ss.eof()){
      ss >> temp;
      if(stringstream(temp) >> aux_int){  // Si puedo convertir a int, guardo
        aux_size[i] = aux_int;
        i++;
      }
      temp = "";
  }
  img_arg.set_width(aux_size[0]);
  img_arg.set_height(aux_size[1]);
  i=0;

  getline(*iss, in_string); // Escala de grises
  aux_greyscale = stoi(in_string);
  img_arg.set_greyscale(aux_greyscale);

  /*Crea la matriz de enteros y los llena con ceros. Hay que
  tener en cuenta q la matriz va a ser cuadrada por eso se pide
  dos veces de dimension "max"*/

  aux_matrix = new int*[aux_size[1]]; // Pido memoria para la cant de columnas (ancho)
  for (int i = 0; i < aux_size[1]; i++){  // Por cada columna
      aux_matrix[i] = new int[aux_size[0]]; // Pido cantidad de filas
  }
  i=0;

  while(getline(*iss, in_string)){	// Relleno matriz, agarro primer linea
    stringstream iss (in_string);

    while(!iss.eof()){
      iss >> temp;

      if(stringstream(temp) >> aux_int){

      	if(aux_int >= 0 && aux_int <= aux_greyscale){
        	aux_matrix[j][i] = aux_int;
        	i++;
        } else{cerr << "No esta en la aux_greyscale" << endl; exit(1);}

      }
      temp = "";
    }
    i = 0;
    j++;
  }

  /*cout << aux_size[0] << ", " << aux_size[1] << endl;
  cout << aux_greyscale << endl;

  for(int x=0 ; x< aux_size[1]; x++){
    for(int y=0 ; y< aux_size[0]; y++){
      cout << aux_matrix[x][y] << " ";
    }
    cout << endl;
  }*/       //PRUEBAS DE IMPRESION antes de mandar a llena la matriz de img

  img_arg.fill_matrix(aux_matrix);   //ACA HAY SIGSEVVVVVVVVVVVVVVVVVVV
  img_arg.printMatrix();

  // DESTRUIR LA MATRIZ AUXILIAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAR
}
