#include <iostream>
#include "libreria.h"
#include "libreria.c"
using namespace std;

int main(int argc, char *argv[]) {
	E op=0;
	
	City ciudad;
	
	FILE *fp;
	fp=fopen("./data_set.txt","r");
	if (fp==NULL){
		cout<<"Imposible abrir el archivo";
		exit(1);
	}
	fclose(fp);
	
	do{
		op=menu();
		switch(op){
		case 1:
			ciudad.total(fp);
			break;
		case 2:
			ciudad.promProv();
			break;
		case 3:
			ciudad.promCiud();
			break;
		case 4:
			ciudad.ciudadCalida();
			break;
		case 5:
			ciudad.ciudadFria();
			break;
		case 6:
			ciudad.diaFrio();
			break;
		case 7:
			ciudad.diaCalido();
			break;
		case 8:
			ciudad.plantarPimientos();
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



