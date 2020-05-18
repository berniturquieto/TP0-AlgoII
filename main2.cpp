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
static void opt_factor(string const &);
static void opt_help(string const &);
void read_pgm(image &);

//*****************************VARIABLES GLOBALES*****************************//

//static enum funciones ("z", "exp(z)");
static int factor;
static istream *iss = 0;	// Input Stream (clase para manejo de los flujos de entrada)
static ostream *oss = 0;	// Output Stream (clase para manejo de los flujos de salida)
static fstream ifs; 		// Input File Stream (derivada de la clase ifstream que deriva de istream para el manejo de archivos)
static fstream ofs;		// Output File Stream (derivada de la clase ofstream que deriva de ostream para el manejo de archivos)

static string PGM_IDENTIFIER = "P";
static char SKIP_LINE_IDENTIFIER = '#';

static option_t options[] = {
	{1, "i", "input", "-", opt_input, OPT_DEFAULT},
	{1, "o", "output", "-", opt_output, OPT_DEFAULT},
	{1, "f", "factor", NULL, opt_factor, OPT_MANDATORY},
	{0, "h", "help", NULL, opt_help, OPT_DEFAULT},
	{0, },
};


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

static void opt_factor(string const &arg){		// HAY QUE CAMBIAR ESTO
	istringstream iss(arg);

	// Intentamos extraer la funcion de la línea de comandos.

	if (!(iss >> factor)
	    || !iss.eof()) {
		cerr << "non-integer factor: "
		     << arg
		     << "."
		     << endl;
		exit(1);
	}

	if (iss.bad()) {
		cerr << "cannot read integer factor."
		     << endl;
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

	//cout << "aaa" << endl;

	image input_image;
	//cout << "2" << endl;

	image output_image;
	//cout << "3" << endl;


	read_pgm(input_image);
	ofs.open("prueba.pgm", ios::out);
    oss = &ofs;
  
    // Verificamos que el stream este OK.
    //
    if (!oss->good()) {
        cerr << "cannot open "
             << "."
             << endl;
        exit(1);        // EXIT: Terminación del programa en su totalidad
    }
    cout << "abrio el archivo" << endl;
    input_image.printMatrix(oss);

	return 0;
}


void read_pgm(image & img_arg){// Esta funcion lee del archivo de input y llena la
  int aux, aux_size[2], i = 0, j = 0, greyscale;	// imagen que se le pase como argumento. Se supone
  int ** aux_matrix;
  string in_string, temp;		// que hay un solo comentario y el pgm esta bien organizado


  getline(*iss, in_string); // Identificador
  in_string.pop_back();
  if (in_string != PGM_IDENTIFIER){
    cerr<< "leyo"<<in_string << "No es PGM" <<endl;
    exit(1);
  }


  getline(*iss, in_string);   // Supongo que tiene un solo comentario
  if (in_string[0] == SKIP_LINE_IDENTIFIER){
    cout << "Encontro un comentario" << endl; // Lo salteo
  }
  else{
    getline(*iss, in_string); // Dimsensiones
    stringstream ss (in_string);
    while(!ss.eof()){
        ss >> temp;
        if(stringstream(temp) >> aux){  // Si puedo convertir a int, guardo
          aux_size[i] = 0;
          i++;
        }
        temp = "";
    }
  }
  img_arg.set_width(aux_size[0]);
  img_arg.set_height(aux_size[1]);
  cout << "w" << aux_size[0]<<":" <<aux_size[1] << endl;
  i=0;
  
  getline(*iss, in_string); // Escala de grises
  greyscale = stoi(in_string);

  img_arg.set_greyscale(greyscale);

  aux_matrix = new int*[aux_size[0]];
  for (int i = 0; i < aux_size[0]; i++){  // Crea la matriz de enteros y los llena con ceros
      aux_matrix[i] = new int[aux_size[1]];   // Hay que tener en cuenta q la matriz va a ser cuadrada
  }                               // Por eso se pide dos veces de dimension "max"
  i=0;
  j=0;
  while(getline(*iss, in_string)){	// Relleno matriz
    stringstream ss (in_string);
    cout << "entre"<<i << endl;
    while(!ss.eof()){
      ss >> temp;
      cout << "entre2" << j<< endl;
      if(stringstream(temp) >> aux){
      	if(aux >= 0 && aux <= greyscale){
          cout << "if" << endl;
        	aux_matrix[j][i] = aux;
          cout << "if2" << endl;
        	i++;
        } else{
        	cerr << "No esta en la greyscale" << endl;
        	exit(1);
        }
      }
      temp = "";
    }
    i = 0;
    j++;
  }
  cout << "llegue aca" << endl;
  img_arg.fill_matrix(aux_matrix);
}
