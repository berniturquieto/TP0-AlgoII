#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <cstdlib>
#include <math.h>

#include "image.h"
#include "complejo.h"
#include "main.h"

using namespace std; 

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

<<<<<<< HEAD
enum functions {z, expz, conjugar};
=======
enum functions {z, expz, conjugar, inversa, logaritmo, seno,pow2};
>>>>>>> 55b8dc6f9be4d9ac84fbec3bcbc98299db7f063c
static functions chosen_function = z;

// **********************************MAIN**********************************//

int main(int argc, char * const argv[]){
	image input_image;

	cmdline cmdl(options);	// Objeto con parametro tipo option_t (struct) declarado globalmente. Ver línea 51 main.cc
	cmdl.parse(argc, argv); // Metodo de parseo de la clase cmdline

	read_pgm(input_image);

	image output_image(input_image.get_max_dim(),input_image.get_max_dim(),input_image.get_greyscale());

	switch(chosen_function){  
		case z:                  
			input_image.print_image(oss);
<<<<<<< HEAD
=======
			return 0;
>>>>>>> 55b8dc6f9be4d9ac84fbec3bcbc98299db7f063c
			break;
		case expz: 
      		map_image(input_image, output_image, &complejo::exponencial);
      		break;
		case conjugar:
			map_image(input_image, output_image, &complejo::conjugar);
			break;
<<<<<<< HEAD
=======
		case inversa:
			map_image(input_image, output_image, &complejo::inversa);
		break;
		case logaritmo:
			map_image(input_image, output_image, &complejo::logaritmo);
		break;
		case seno:
			map_image(input_image, output_image, &complejo::seno);
		break;
		case pow2:
			map_image(input_image, output_image, &complejo::pow2);
		break;
>>>>>>> 55b8dc6f9be4d9ac84fbec3bcbc98299db7f063c
		default: 
			cerr<< "Error en seleccion de funcion" << endl;
			exit(1);
	}

	output_image.print_image(oss);
	return 0;
}

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
		cerr << "cannot open "<< arg<< "."<< endl;
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
		cerr << "cannot open "<< arg<< "."<< endl;
		exit(1);
	}
}

static void opt_function(string const &arg){

  if (arg == FUNCTION_Z || arg == "-") {chosen_function = z;}

  else if (arg == FUNCTION_EXPZ) {chosen_function = expz; }
  else if (arg == FUNCTION_CONJUGAR) {chosen_function = conjugar; }
<<<<<<< HEAD
=======
  else if (arg == FUNCTION_INVERSA) {chosen_function = inversa; } 
  else if (arg == FUNCTION_LOGARITMO) {chosen_function = logaritmo; }
  else if (arg == FUNCTION_SENO) {chosen_function = seno; }
  else if (arg == FUNCTION_POW) {chosen_function = pow2; }
>>>>>>> 55b8dc6f9be4d9ac84fbec3bcbc98299db7f063c
  else {
    cerr << "Funcion invalida" << endl;
    exit(1);
  }
}

static void opt_help(string const &arg){
	cout << "cmdline -f function [-i file] [-o file]"
	     << endl;
	exit(0);
}

//***********************METODOS DE CMDLINE***********************//

cmdline::cmdline(){}

cmdline::cmdline(option_t *table) : option_table(table){
	/* 
	- Lo mismo que hacer:

	option_table = table;

<<<<<<< HEAD
<<<<<<<< HEAD:main.cpp
=======
>>>>>>> 55b8dc6f9be4d9ac84fbec3bcbc98299db7f063c
	Siendo "option_table" un atributo de la clase cmdline
	y table un puntero a objeto o struct de "option_t".
	
	Se estaría contruyendo una instancia de la clase cmdline
	cargandole los datos que se hayan en table (la table con
	las opciones, ver el código en main.cc)
<<<<<<< HEAD
========
  image output_image(input_image.get_max_dim(),input_image.get_max_dim(),input_image.get_greyscale());

  switch(chosen_function){  
    case z:                  
      output_image=input_image;
      break;
    case expz: 
      map_image(input_image, output_image, &complejo::exponencial);
      break;
    case conjugar:
      map_image(input_image, output_image, &complejo::conjugar);
      break;
    default: 
      cerr<< "Error en seleccion de funcion" << endl;
  }
>>>>>>>> 55b8dc6f9be4d9ac84fbec3bcbc98299db7f063c:main2.cpp
=======
>>>>>>> 55b8dc6f9be4d9ac84fbec3bcbc98299db7f063c

	*/
}

void cmdline::parse(int argc, char * const argv[]) {
#define END_OF_OPTIONS(p)       \
	((p)->short_name == 0   \
	 && (p)->long_name == 0 \
	 && (p)->parse == 0)

	for (option_t *op = option_table; !END_OF_OPTIONS(op); ++op)
		op->flags &= ~OPT_SEEN;

	for (int i = 1; i < argc; ++i) {

		if (argv[i][0] != '-') {
			cerr << "Invalid non-option argument: "
			     << argv[i]
			     << endl;
			exit(1);
		}

		if (argv[i][1] == '-'
		    && argv[i][2] == 0)
			break;

		if (argv[i][1] == '-')
			i += do_long_opt(&argv[i][2], argv[i + 1]);
		else
			i += do_short_opt(&argv[i][1], argv[i + 1]);
	}

	for (option_t *op = option_table; !END_OF_OPTIONS(op); ++op) {
#define OPTION_NAME(op) \
	(op->short_name ? op->short_name : op->long_name)
		if (op->flags & OPT_SEEN)
			continue;
		if (op->flags & OPT_MANDATORY) {
			cerr << "Option "<< "-"<< OPTION_NAME(op)<< " is mandatory."<< "\n";
			exit(1);
		}
		if (op->def_value == 0)
			continue;
		op->parse(string(op->def_value));
	}
}

int cmdline::do_long_opt(const char *opt, const char *arg) {
	// Recorremos la tabla de opciones, y buscamos la
	// entrada larga que se corresponda con la opción de 
	// línea de comandos. De no encontrarse, indicamos el
	// error.
	//
	for (option_t *op = option_table; op->long_name != 0; ++op) {
		if (string(opt) == string(op->long_name)) {
			// Marcamos esta opción como usada en
			// forma explícita, para evitar tener
			// que inicializarla con el valor por
			// defecto.
			//
			op->flags |= OPT_SEEN;

			if (op->has_arg) {
				if (arg == 0) { // Verificamos que se provea un argumento
					cerr << "Option requires argument: "<< "--"<< opt<< "\n";
					exit(1);
				}
				op->parse(string(arg));
				return 1;
			} else {
				op->parse(string("")); // Opción sin argumento.
				return 0;
			}
		}
	}
	// Error: opción no reconocida.
	cerr << "Unknown option: "<< "--"<< opt<< "."<< endl;
	exit(1);
	return -1;
}

int cmdline::do_short_opt(const char *opt, const char *arg) {
	option_t *op;

	for (op = option_table; op->short_name != 0; ++op) {

		if (string(opt) == string(op->short_name)) {
			op->flags |= OPT_SEEN;
			if (op->has_arg) {
				if (arg == 0) {	
					cerr << "Option requires argument: "<< "-"<< opt<< "\n";
					exit(1);
				}
				op->parse(string(arg));
				return 1;
			} else {
				op->parse(string(""));
				return 0;
			}
		}
	}
	cerr << "Unknown option: "<< "-"<< opt << "." << endl;
	exit(1);
	return -1;
}


// *******************************FUNCIONES**********************************//


/*Esta funcion lee del archivo de input y llena la imagen VACIA que
se le pase como argumento. Se supone que hay un solo comentario y
el pgm esta bien organizado*/
void read_pgm(image & img_arg){
  int aux_int, aux_size[2], aux_greyscale;
  int i=0;
  int ** aux_matrix;
  string in_string, temp;		


  getline(*iss, in_string); // Identificador
  in_string.pop_back();
  if (in_string[0] != PGM_IDENTIFIER[0] && in_string[1] != PGM_IDENTIFIER[1]){
    cerr<< "No es PGM" <<endl;
    exit(1);
  }


  getline(*iss, in_string);   // Supongo que tiene un solo comentario, lo salteo
  if (in_string[0] == SKIP_LINE_IDENTIFIER){
    //cout << "Encontro un comentario" << endl; // Lo salteo
    getline(*iss, in_string); // Dimsensiones

  }

  
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
  tener en cuenta q la matriz va a sedr cuadrada por eso se pide
  dos veces de dimension "max"*/
  aux_matrix = new int*[aux_size[1]]; 
  for (int i = 0; i < aux_size[1]; i++){  
      aux_matrix[i] = new int[aux_size[0]]; 
  }

  for (int i = 0; i < aux_size[1]; i++)
  {
    for (int j = 0; j < aux_size[0]; j++)
    {
      *iss >> aux_int;
      aux_matrix[i][j] = aux_int;
    }
  }


  img_arg.fill_matrix(aux_matrix);  // Lleno la matriz de imagen
 
  for (int i = 0; i<aux_size[1]; i++)   //Destruyo matriz auxiliar              
        delete[] aux_matrix[i];
  delete[] aux_matrix;
}


<<<<<<< HEAD
complejo ** generate_matrix_c(double max){
  complejo ** matrix;
  
  matrix = new complejo*[(int)max]; // Pido memoria para la matriz
  for (int i = 0; i < max; i++){  
      matrix[i] = new complejo[(int)max];
    }
=======
void generate_matrix_c(double max, complejo *** matrix){
  
  (*matrix) = new complejo*[(int)max]; // Pido memoria para la matriz
  for (int i = 0; i < max; i++){  
      (*matrix)[i] = new complejo[(int)max];
   }
>>>>>>> 55b8dc6f9be4d9ac84fbec3bcbc98299db7f063c

  double paso=2/(max-1);
  double aux_real=-1;
  double aux_imag=1;
    for (int i = 0; i < max; i++){    // raws// Rellena la matris con color negro 
      for (int j = 0; j < max; j++){  // co
<<<<<<< HEAD
        matrix[i][j]=complejo(aux_real,aux_imag);
=======
        (*matrix)[i][j]=complejo(aux_real,aux_imag);
>>>>>>> 55b8dc6f9be4d9ac84fbec3bcbc98299db7f063c
        aux_real=aux_real+paso;
        }
        aux_real=-1;
        aux_imag=aux_imag-paso;
      
    }
<<<<<<< HEAD
    return matrix;
}


int * binary_search(complejo c, complejo ** matrix, int in_lim[2], int fin_lim[2]){//ini [x0,y0] fin [xf,yf]
  
  if (in_lim[0]>fin_lim[0] || in_lim[1]>fin_lim[1]){
    return NULL;
  }
=======

}


int * binary_search(const complejo c, complejo *** matrix, int in_lim[2], int fin_lim[2]){//ini [x0,y0] fin [xf,yf]

  	// Esta funcion realiza la cusqueda del complejo c en la mtriz matrix recivida por punteroa traves del metodo binario de busqueda de
  	// forma recursiva. in_lim y fin_lim representan
  	// los limites inferiores y superiores respectivamente, de donde se encuentra el valor c o el mas proximo a este.
	// Se prueba que los limites iniciales sean menores a los finales, de no ser asi se devuleve NULL
  if (in_lim[0]>fin_lim[0] || in_lim[1]>fin_lim[1]){
    return NULL;
  }
  // Se corrobora que el valor c a buscar este dentro de el semiplano que conforman los puntos (-1+i), (-1-i), (1-i) y (1+i)
  // sino retorna NULL
>>>>>>> 55b8dc6f9be4d9ac84fbec3bcbc98299db7f063c

  if(abs(c.get_real()) > 1 || abs(c.get_img()) > 1){
    return NULL;
  }

<<<<<<< HEAD
  if ((fin_lim[0]-in_lim[0]) == 1 && (fin_lim[1]-in_lim[1]) == 1){

    if (abs(c.get_real() - (matrix[in_lim[1]][in_lim[0]]).get_real()) > abs(c.get_real() - (matrix[fin_lim[1]][fin_lim[0]]).get_real())){
      in_lim[0] = fin_lim[0];
    }
    if (abs(c.get_img() - (matrix[in_lim[1]][in_lim[0]]).get_img()) > abs(c.get_img() - (matrix[fin_lim[1]][fin_lim[0]]).get_img())){
=======
  // Caso base:
  // En este c
  if ((fin_lim[0]-in_lim[0]) == 1 && (fin_lim[1]-in_lim[1]) == 1){

    if (abs(c.get_real() - ((*matrix)[in_lim[1]][in_lim[0]]).get_real()) > abs(c.get_real() - ((*matrix)[fin_lim[1]][fin_lim[0]]).get_real())){
      in_lim[0] = fin_lim[0];
    }
    if (abs(c.get_img() - ((*matrix)[in_lim[1]][in_lim[0]]).get_img()) > abs(c.get_img() - ((*matrix)[fin_lim[1]][fin_lim[0]]).get_img())){
>>>>>>> 55b8dc6f9be4d9ac84fbec3bcbc98299db7f063c
      in_lim[1] = fin_lim[1];
    }
    return in_lim;
  }

  int medio_x = in_lim[0]+(fin_lim[0]-in_lim[0])/2;
  int medio_y = in_lim[1]+(fin_lim[1]-in_lim[1])/2; 

<<<<<<< HEAD
  if (c.get_real()>= (matrix[medio_y][medio_x]).get_real()){
    in_lim[0] = medio_x;
    if (c.get_img()>= (matrix[medio_y][medio_x]).get_img()){
=======
  if (c.get_real()>= ((*matrix)[medio_y][medio_x]).get_real()){
    in_lim[0] = medio_x;
    if (c.get_img()>= ((*matrix)[medio_y][medio_x]).get_img()){
>>>>>>> 55b8dc6f9be4d9ac84fbec3bcbc98299db7f063c
      fin_lim[1] = medio_y;
      return binary_search(c, matrix, in_lim, fin_lim);
    }else{
      in_lim[1] = medio_y;
      return binary_search(c, matrix, in_lim, fin_lim);
    }

  }else{
    fin_lim[0] = medio_x;
<<<<<<< HEAD
    if (c.get_img()>=(matrix[medio_y][medio_x]).get_img()){
=======
    if (c.get_img()>=((*matrix)[medio_y][medio_x]).get_img()){
>>>>>>> 55b8dc6f9be4d9ac84fbec3bcbc98299db7f063c
      fin_lim[1] = medio_y;
      return binary_search(c, matrix, in_lim, fin_lim);
    }else{
      in_lim[1] = medio_y;
      return binary_search(c, matrix, in_lim, fin_lim);
    }
  } 
}


void map_image(image & original, image & destino, complejo(complejo::*function_pointer)(void)){

  int * pos;
  int in_lim[2];
  int fin_lim[2];
  int aux_color;
  int max = original.get_max_dim();
  complejo aux;
  complejo ** complex_matrix;

<<<<<<< HEAD
  complex_matrix = generate_matrix_c(original.get_max_dim());
=======
  generate_matrix_c(original.get_max_dim(), &complex_matrix);
>>>>>>> 55b8dc6f9be4d9ac84fbec3bcbc98299db7f063c

  in_lim[0]=0;
  in_lim[1]=0;
  fin_lim[0]=max-1; 
  fin_lim[1]=max-1; 


  for(int i=0; i < destino.get_max_dim();i++){
    for (int j = 0; j < destino.get_max_dim(); j++)
    {
      in_lim[0]=0;
      in_lim[1]=0;
      fin_lim[0]=max-1; 
      fin_lim[1]=max-1;
      aux = complex_matrix[i][j];

      aux = (aux.*function_pointer)();

<<<<<<< HEAD
      pos = binary_search(aux,complex_matrix,in_lim,fin_lim);
=======
      pos = binary_search(aux,&complex_matrix,in_lim,fin_lim);
>>>>>>> 55b8dc6f9be4d9ac84fbec3bcbc98299db7f063c
      if (pos !=NULL){
        aux_color = original.get_matrix_value(pos[1],pos[0]);
        destino.set_matrix_value(i,j,aux_color);
      }
    }
  }
<<<<<<< HEAD
=======
  
  for (int i = 0; i<max; i++){    	// Borra la memoria pedida por generate_matrix_c
      if (complex_matrix[i]){          
        delete[] complex_matrix[i];
      }
    }
  
  delete[] complex_matrix;
>>>>>>> 55b8dc6f9be4d9ac84fbec3bcbc98299db7f063c

} 
