#include <iostream>
#include "libreria.h"
#include "libreria.cpp"
using namespace std;

int main(int argc, char *argv[]) {
	
	int op=0, cba_med=0, men_med=0, sf_med=0;
	float tempcba=0, tempmen=0, tempsf=0;

	Mediciones mediciones[3];

	for (int i=0; i<3; i++){
		mediciones[i].setData(i);
	}
	
	do{
		op=menu();
		switch(op){
		case 1:
			for (int i=0; i<3; i++){
				mediciones[i].total(i);
			}
			break;
		case 2:
			/*tempcba=Cordoba.promProv(1, cba_med);
			tempmen=Mendoza.promProv(2, men_med);
			tempsf=SF.promProv(3, sf_med);*/
			break;
		case 3:
			/*Cordoba.promCiud();
			Mendoza.promCiud();
			SF.promCiud();*/
			break;
		case 4:
			/*Cordoba.ciudadCalida();
			Mendoza.ciudadCalida();
			SF.ciudadCalida();*/
			break;
		case 5:
			/*Cordoba.ciudadFria();
			Mendoza.ciudadFria();
			SF.ciudadFria();*/
			break;
		case 6:
			/*Cordoba.diaFrio();
			Mendoza.diaFrio();
			SF.diaFrio();*/
			break;
		case 7:
			/*Cordoba.diaCalido();
			Mendoza.diaCalido();
			SF.diaCalido();*/
			break;
		case 8:
			/*Cordoba.plantarPimientos();
			Mendoza.plantarPimientos();
			SF.plantarPimientos();*/
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


