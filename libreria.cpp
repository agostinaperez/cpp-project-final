#include "libreria.h"

int menu()
{
	int op;
	cout << "Ingrese una opci�n: \n 1. Total de las muestras almacenadas en las listas pertenecientes a cada provincia\n 2. Temperatura promedio de cada provincia\n 3.Temperatura promedio de cada ciudad\n 4.Ciudad m?s c?lida de cada provincia\n 5. Ciudad mas fr?a de cada provincia\n 6. D?a m?s fr?o de cada provincia\n 7. D?a m?s c?lido de cada ciudad\n 8. Mejor provincia para el cultivo de pimientos (temperatura promedio cercana a 23 grados cent?grados)\n 0.Salir" << endl;
	cin >> op;
	return op;
}

Provincia::Provincia(int num)
{	city *provincias[3]={NULL};
	int codProv = 0, codCiud = 0, hh = 0, mm = 0, month = 0, day = 0;
	float hum = 0, temp = 0;
	char nombre[50];
	city *newCity = NULL, *copy=NULL, *head=NULL;

	FILE *fp;
	fp=fopen("./data_set.txt","r");
	if (fp==NULL){
		cout<<"Imposible abrir el archivo";
		exit(1);
	}
	
	while (!feof(fp))
	{ 	
		fscanf(fp, "%d\t%d\t%s\t%f\t%f\t%d\t%d\t%d\t%d", &codCiud, &codProv, &nombre, &temp, &hum, &hh, &mm, &day, &month);
		
	
		if (codProv == num)
		{
			newCity = new (city);
			newCity->cityId = codCiud;
			strcpy(newCity->cityName, nombre);
			newCity->m.hum = hum;
			newCity->m.temp = temp;
			newCity->m.time.day = day;
			newCity->m.time.month = month;
			newCity->m.time.hh = hh;
			newCity->m.time.mm = mm;
			newCity->next = NULL;
			
			cout<<num<<endl;
			cout<<codProv<<endl;
			cout<<newCity->m.temp<<endl;
			cout<<newCity->cityName<<endl;
			
			if (head == NULL)
			{
				head = newCity;
			}
			else
			{
				copy = head;
				while (copy == NULL)
				{
					copy = copy->next;
				}
				copy->next = newCity;
			}
			

			provincias[num-1]=newCity;
			
		}
	}
	
	fclose(fp);
	
}

int Provincia::total(int num)
{	int cod=0, codP=0, cba=0, men=0, sf=0;
	FILE *fp;
	fp=fopen("./data_set.txt","r");
	if (fp==NULL){
		cout<<"Imposible abrir el archivo";
		exit(1);
	}

	while (!feof(fp)){
		fscanf(fp, "%d, %d", &cod, &codP);
		if(codP==num && codP==1){
			cba+=1;
		}else{
			if(codP==num && codP==2){
				men+=1;
			}else{
				if(codP==num && codP==3){
					sf+=1;
				}
			}
		}
	}
	fclose(fp);

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

void Provincia::promCiud()
{
}

float Provincia::promProv(int code, int med)
{	city *head=NULL, *copy=NULL;
	head=&ciudades; //???????
	
	float temp=0, promcba=0, prommen=0, promsf=0;
	char name;
	int codciud=0, codprov=0;
	
	if (med==0){
	med=this->total(code);
	}

	//en vez de leer el archivo acá debería recorrer la lista e ir sumando!
	//bueno. Acá ya se me hizo un lío. Hasta no descifrar todo el comportamiento de la estructura, me voy a queddar tildada.
	
	return (0.01);

}


void Provincia::ciudadCalida()
{
}

void Provincia::ciudadFria()
{
}

void Provincia::diaCalido()
{
}

void Provincia::diaFrio()
{
}

void Provincia::plantarPimientos()
{
}
