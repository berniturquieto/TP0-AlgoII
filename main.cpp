#include <iostream>
#include "Complejo.h"

using namespace std;

int main (){
	

	Complejo c1, c2=Complejo(1,1), c3=c2,c4;



	c1.print_complejo();
	c2.print_complejo();
	c3.print_complejo();


	c4=c2.exponencial();

	cout<<"exponencial"<<endl;

	c4.print_complejo();
	c2.print_complejo();

	return 0;
}