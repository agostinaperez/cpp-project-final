#include "libreria.h"

int menu()
{
	int op;
	cout << "Ingrese una opci�n: \n 1. Total de las muestras almacenadas en las listas pertenecientes a cada provincia\n 2. Temperatura promedio de cada provincia\n 3.Temperatura promedio de cada ciudad\n 4.Ciudad m?s c?lida de cada provincia\n 5. Ciudad mas fr?a de cada provincia\n 6. D?a m?s fr?o de cada provincia\n 7. D?a m?s c?lido de cada ciudad\n 8. Mejor provincia para el cultivo de pimientos (temperatura promedio cercana a 23 grados cent?grados)\n 0.Salir" << endl;
	cin >> op;
	return op;
}

void Provincia::setData(int num)
{
	int codProv = 0, codCiud = 0, hum = 0, temp = 0, hh = 0, mm = 0, month = 0, day = 0;
	char nombre[50];
	city *newCity = NULL, *copy=NULL, *head=NULL;

	FILE *fp;
	fp = fopen("./data_set.txt", "r");
	if (fp == NULL)
	{
		cout << "Imposible abrir el archivo";
		exit(1);
	}

	while (!feof(fp))
	{
		fscanf(fp, "%d, %d, %c, %d, %d, %d, %d, %d, %d", &codCiud, &codProv, &nombre[50], &temp, &hum, &hh, &mm, &day, &month);
		if (codCiud == num)
		{
			// tengo q ver si hacer el array o como
			newCity = new (city);
			newCity->cityId = codProv;
			strcpy(newCity->cityName, nombre);
			newCity->m.hum = hum;
			newCity->m.temp = temp;
			newCity->m.time.day = day;
			newCity->m.time.month = month;
			newCity->m.time.hh = hh;
			newCity->m.time.mm = mm;
			newCity->next = NULL;

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
		}
	}

	fclose(fp);

	copy=head;
	while (copy!=NULL){
		cout<<copy->cityId;
		cout<<copy->cityName;
		cout<<copy->m.temp;
		copy=copy->next;
	}
}

void Provincia::total()
{
}

void Provincia::promCiud()
{
}

void Provincia::promProv()
{
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
