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

static enum funciones ("z", "exp(z)");
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

static void opt_function(string const &arg){		// HAY QUE CAMBIAR ESTO
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

	int w = 24, h = 7, gs = 10;
	image image_in(w,h,gs);

	image_in.printMatrix();

	return 0;
}


void read_pgm(image & img_arg){	// Esta funcion lee del archivo de input y llena la
  int aux, i = 0, j = 0;		// imagen que se le pase como argumento. Se supone
  string in_string, temp;		// que hay un solo comentario y el pgm esta bien organizado

  getline(*iss, in_string); // Identificador
  in_string.pop_back();
  if (in_string != PGM_IDENTIFIER){
    cerr << "No es PGM" << endl;
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
          size[i] = aux; // CAMBIAAAAAAAAAAAAAAAAAAAAAAAAAAR
          i++;
        }
        temp = "";
    }
  }
  i = 0;

  getline(*iss, in_string); // Escala de grises
  greyscale = stoi(in_string);  //CAMBIAAAAAAAAAAAAAAAAAAAAAR


  while(getline(*iss, in_string)){
    stringstream ss (in_string);
    while(!ss.eof()){
      ss >> temp;
      if(stringstream(temp) >> aux){
        matri[j][i] = aux;  //CAMBIAAAAAAAAAAAAAAAAAAAAAAAAAAAR
        i++;
      }
      temp = "";
    }
    i = 0;
    j++;
  }
}
