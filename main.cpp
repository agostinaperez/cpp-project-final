#include <iostream>
#include "libreria.h"
#include "libreria.cpp"
using namespace std;

int main(int argc, char *argv[])
{
	//Creación de listas enlazadas
	city *Cordoba = NULL, *SF = NULL, *Mendoza = NULL;
	Cordoba=new(city);
	SF=new(city);
	Mendoza=new(city);

	//instanciando el objeto
	Archivo archivo;

	int op = 0, cba_med = 0, men_med = 0, sf_med = 0;
	float tempcba = 0, tempmen = 0, tempsf = 0;

	//carga de datos a las listas
	
	archivo.get(&Cordoba, &SF, &Mendoza);

	do
	{	//Menú de opciones
		op = menu();

		//Implementación de las funciones
		switch (op)
		{
		case 1:
			men_med = total(1, &Cordoba, &SF, &Mendoza);
			sf_med = total(2, &Cordoba, &SF, &Mendoza);
			cba_med = total(3, &Cordoba, &SF, &Mendoza);
			break;
		case 2:
			tempmen = promProv(1, Cordoba, SF, Mendoza);
			tempsf = promProv(2, Cordoba, SF, Mendoza);
			tempcba = promProv(3, Cordoba, SF, Mendoza);
			cout<<"La temperatura promedio de Mendoza es de "<<tempmen<<" grados, la de Santa Fe es de "<<tempsf<<", y la de Cordoba es de "<<tempcba<<endl;
			break;
		case 3:
			promCiud(Cordoba, SF, Mendoza);
			break;
		case 4:
			ciudadCalida(Cordoba, SF, Mendoza);
			break;
		case 5:
			ciudadFria(Cordoba, SF, Mendoza);
			break;
		case 6:
			diaFrio(Cordoba, SF, Mendoza);
			break;
		case 7:
			diaCalido(Cordoba, SF, Mendoza);
			break;
		case 8:
			plantarPimientos(tempcba, tempmen, tempsf, Cordoba, SF, Mendoza);
			break;
		case 0:
			break;
		default:
			cout << "Lo sentimos, esta opci?n no existe, int?ntelo de nuevo" << endl;
			break;
		}
	} while (op != 0);
	return 0;
}
