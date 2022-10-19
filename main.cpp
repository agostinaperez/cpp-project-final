#include <iostream>
using namespace std;

typedef int E;
typedef char C;
typedef float F;
//quiero hacer typedefs de los punteros y estructuras pero vemos


struct timestamp{
	E day;
	E month;
	E hh;
	E mm;
};

struct measurement{
	struct timestamp time;
	F temp;
	F hum;
};


struct city{
	struct city *next;
	struct measurement m;
	E cityId;
	C cityName[50];//capaz quiero q sea string pero vemos
};


E menu(void);

int main(int argc, char *argv[]) {
	E op=0;
	do{
		op=menu();
		switch(op){
		case 1:
			break;
		case 2:
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
		case 0: break;
		default:
			cout<<"Lo sentimos, esta opción no existe, inténtelo de nuevo"<<endl;
			break;
		}
	}while(op!=0);
	return 0;
}

E menu (void){
	E op;
	cout<<"Ingrese una opción: \n 1. Total de las muestras almacenadas en las listas pertenecientes a cada provincia\n 2. Temperatura promedio de cada provincia\n 3.Temperatura promedio de cada ciudad\n 4.Ciudad más cálida de cada provincia\n 5. Ciudad mas fría de cada provincia\n 6. Día más frío de cada provincia\n 7. Día más cálido de cada ciudad\n 8. Mejor provincia para el cultivo de pimientos (temperatura promedio cercana a 23 grados centígrados)\n 0.Salir"<<endl;
	cin>>op;
	return op;
}
