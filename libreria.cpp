#include "libreria.h"

int menu()
{
	int op;
	cout << "Ingrese una opci�n: \n 1. Total de las muestras almacenadas en las listas pertenecientes a cada provincia\n 2. Temperatura promedio de cada provincia\n 3.Temperatura promedio de cada ciudad\n 4.Ciudad m?s c?lida de cada provincia\n 5. Ciudad mas fr?a de cada provincia\n 6. D?a m?s fr?o de cada provincia\n 7. D?a m?s c?lido de cada ciudad\n 8. Mejor provincia para el cultivo de pimientos (temperatura promedio cercana a 23 grados cent?grados)\n 0.Salir" << endl;
	cin >> op;
	return op;
}

Archivo::Archivo()
{	
	file=fopen("./data_set.txt","r");
	
	if (file==NULL){
		cout<<"Imposible abrir el archivo";
		exit(1);
	}
	delete(file);
	
	
}

void Archivo::get(struct city* Cordoba, struct city* SF, struct city* Mendoza){
	int codProv = 0, codCiud = 0, hh = 0, mm = 0, month = 0, day = 0;
	float hum = 0, temp = 0;
	char nombre[50];
	city *newCity = NULL, *copy=NULL, *head=NULL;
	FILE *fp=NULL;
	file=fopen("./data_set.txt","r");
	while (!feof(file))
	{ 	
		fscanf(fp, "%d\t%d\t%s\t%f\t%f\t%d\t%d\t%d\t%d", &codCiud, &codProv, &nombre, &temp, &hum, &hh, &mm, &day, &month);
		
	if(codProv==1){
			Cordoba->cityId=codCiud;
			strcpy(Cordoba->cityName, nombre);
			Cordoba->m.hum=hum;
			Cordoba->m.temp=temp;
			Cordoba->m.time.day=day;
			Cordoba->m.time.month=month;
			Cordoba->m.time.mm=mm;
			Cordoba->m.time.hh=hh;
			Cordoba->next=NULL;

			if(head==NULL){
				head=Cordoba;
			}else{
				copy=head;
				while (copy==NULL){
					copy=copy->next;
				}
				copy->next=Cordoba;}
	}else{
		if(codProv==2){
			Mendoza->cityId=codCiud;
			strcpy(Mendoza->cityName, nombre);
			Mendoza->m.hum=hum;
			Mendoza->m.temp=temp;
			Mendoza->m.time.day=day;
			Mendoza->m.time.month=month;
			Mendoza->m.time.mm=mm;
			Mendoza->m.time.hh=hh;
			Mendoza->next=NULL;

			if(head==NULL){
				head=Mendoza;
			}else{
				copy=head;
				while (copy==NULL){
					copy=copy->next;
				}
				copy->next=Mendoza;}
		}else{
			if(codProv==3){
			SF->cityId=codCiud;
			strcpy(SF->cityName, nombre);
			SF->m.hum=hum;
			SF->m.temp=temp;
			SF->m.time.day=day;
			SF->m.time.month=month;
			SF->m.time.mm=mm;
			SF->m.time.hh=hh;
			SF->next=NULL;

			if(head==NULL){
				head=SF;
			}else{
				copy=head;
				while (copy==NULL){
					copy=copy->next;
				}
				copy->next=SF;}
				}
			}
		}
	fclose(file);
}
}

int total(int num){	
	int cod=0, codP=0, cba=0, men=0, sf=0;
	

	if (num==1){
		cout<<"La cantidad de mediciones tomadas en Córdoba es de: "<<cba;
		return cba;
	}else{
		if(num==2){
			cout<<"La cantidad de mediciones tomadas en Mendoza es de: "<<men;
			return men;
		}else{
			cout<<"La cantidad de mediciones tomadas en Santa Fe es de: "<<sf;
			return sf;
		}
	}

}

void promCiud()
{
}

float promProv(int code, int med)
{	/*city *head=NULL, *copy=NULL;
	head=&ciudades; //???????
	
	float temp=0, promcba=0, prommen=0, promsf=0;
	char name;
	int codciud=0, codprov=0;
	
	if (med==0){
	med=this->total(code);
	}

	//en vez de leer el archivo acá debería recorrer la lista e ir sumando!
	//bueno. Acá ya se me hizo un lío. Hasta no descifrar todo el comportamiento de la estructura, me voy a queddar tildada.
	*/
	return (0.01);

}


void ciudadCalida()
{
}

void ciudadFria()
{
}

void diaCalido()
{
}

void diaFrio()
{
}

void plantarPimientos()
{
}
