#include <iostream>
#include "libreria.h"
#include "libreria.cpp"
using namespace std;

int main(int argc, char *argv[]) {

	city *Cordoba=NULL, *SF=NULL, *Mendoza=NULL;

	Archivo archivo;

	int op=0, cba_med=0, men_med=0, sf_med=0;
	float tempcba=0, tempmen=0, tempsf=0;

	archivo.get(Cordoba, SF, Mendoza);
	
	
	do{
		op=menu();
		switch(op){
		case 1:
			cba_med=total(1);
			men_med=total(2);
			sf_med=total(3);
			break;
		case 2:
			tempcba=promProv(1, cba_med);
			tempmen=promProv(2, men_med);
			tempsf=promProv(3, sf_med);
			break;
		case 3:
			
			break;
		case 4:
			
			break;
		case 5:
			
			break;
		case 6:
		
			break;
		case 7:
		
			break;
		case 8:
			
			break;
		case 0: 
			break;
		default:
			cout<<"Lo sentimos, esta opci?n no existe, int?ntelo de nuevo"<<endl;
			break;
		}
	}while(op!=0);
	return 0;
}


