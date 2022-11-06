#include <iostream>
#include "libreria.h"
#include "libreria.cpp"
using namespace std;

int main(int argc, char *argv[])
{

	city *Cordoba = NULL, *SF = NULL, *Mendoza = NULL;

	Archivo archivo;

	int op = 0, cba_med = 0, men_med = 0, sf_med = 0;
	float tempcba = 0, tempmen = 0, tempsf = 0;

	archivo.get(Cordoba, SF, Mendoza);

	do
	{
		op = menu();
		switch (op)
		{
		case 1:
			cba_med = total(1, Cordoba, SF, Mendoza);
			men_med = total(2, Cordoba, SF, Mendoza);
			sf_med = total(3, Cordoba, SF, Mendoza);
			break;
		case 2:
			tempcba = promProv(1, Cordoba, SF, Mendoza);
			tempmen = promProv(2, Cordoba, SF, Mendoza);
			tempsf = promProv(3, Cordoba, SF, Mendoza);
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
