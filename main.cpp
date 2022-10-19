#include <iostream>
#include "libreria.h"
using namespace std;
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




int main(int argc, char *argv[]) {
	E op=0;

	FILE *fp;
	fp=fopen("./data_set.txt","r");
	if (fp==NULL){
		cout<<"Imposible abrir el archivo";
		exit(1);
	}

	do{
		op=menu();
		switch(op){
		case 1:
			total();
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

