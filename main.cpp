#include <iostream>
#include "libreria.h"
#include "libreria.cpp"
using namespace std;

int main(int argc, char *argv[]) {
	int op=0;

	Provincia Cordoba;
	Cordoba.setData(1);
	Provincia Mendoza;
	Mendoza.setData(2);
	Provincia SF;
	SF.setData(3);

	
	
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
			Cordoba.total();
			Mendoza.total();
			SF.total();
			break;
		case 2:
			Cordoba.promProv();
			Mendoza.promProv();
			SF.promProv();
			break;
		case 3:
			Cordoba.promCiud();
			Mendoza.promCiud();
			SF.promCiud();
			break;
		case 4:
			Cordoba.ciudadCalida();
			Mendoza.ciudadCalida();
			SF.ciudadCalida();
			break;
		case 5:
			Cordoba.ciudadFria();
			Mendoza.ciudadFria();
			SF.ciudadFria();
			break;
		case 6:
			Cordoba.diaFrio();
			Mendoza.diaFrio();
			SF.diaFrio();
			break;
		case 7:
			Cordoba.diaCalido();
			Mendoza.diaCalido();
			SF.diaCalido();
			break;
		case 8:
			Cordoba.plantarPimientos();
			Mendoza.plantarPimientos();
			SF.plantarPimientos();
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


