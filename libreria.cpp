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
	file = fopen("./data_set.txt", "r");

	if (file == NULL)
	{
		cout << "Imposible abrir el archivo";
		exit(1);
	}
	fclose(file);
}

void Archivo::get(struct city *Cordoba, struct city *SF, struct city *Mendoza)
{
	int codProv = 0, codCiud = 0, hh = 0, mm = 0, month = 0, day = 0;
	float hum = 0, temp = 0;
	char nombre[50];
	city *copy = NULL, *headC = NULL, *headSF = NULL, *headM = NULL;
	FILE *fp = NULL;
	file = fopen("./data_set.txt", "r");
	while (!feof(file))
	{
		fscanf(fp, "%d\t%d\t%s\t%f\t%f\t%d\t%d\t%d\t%d", &codCiud, &codProv, &nombre[50], &temp, &hum, &hh, &mm, &day, &month);

		if (codProv == 1)
		{
			Cordoba->cityId = codCiud;
			strcpy(Cordoba->cityName, nombre);
			Cordoba->m.hum = hum;
			Cordoba->m.temp = temp;
			Cordoba->m.time.day = day;
			Cordoba->m.time.month = month;
			Cordoba->m.time.mm = mm;
			Cordoba->m.time.hh = hh;
			Cordoba->next = NULL;

			if (headC == NULL)
			{
				headC = Cordoba;
			}
			else
			{
				copy = headC;
				while (copy == NULL)
				{
					copy = copy->next;
				}
				copy->next = Cordoba;
			}
		}
		else
		{
			if (codProv == 2)
			{
				Mendoza->cityId = codCiud;
				strcpy(Mendoza->cityName, nombre);
				Mendoza->m.hum = hum;
				Mendoza->m.temp = temp;
				Mendoza->m.time.day = day;
				Mendoza->m.time.month = month;
				Mendoza->m.time.mm = mm;
				Mendoza->m.time.hh = hh;
				Mendoza->next = NULL;

				if (headM == NULL)
				{
					headM = Mendoza;
				}
				else
				{
					copy = headM;
					while (copy == NULL)
					{
						copy = copy->next;
					}
					copy->next = Mendoza;
				}
			}
			else
			{
				if (codProv == 3)
				{
					SF->cityId = codCiud;
					strcpy(SF->cityName, nombre);
					SF->m.hum = hum;
					SF->m.temp = temp;
					SF->m.time.day = day;
					SF->m.time.month = month;
					SF->m.time.mm = mm;
					SF->m.time.hh = hh;
					SF->next = NULL;

					if (headSF == NULL)
					{
						headSF = SF;
					}
					else
					{
						copy = headSF;
						while (copy == NULL)
						{
							copy = copy->next;
						}
						copy->next = SF;
					}
				}
			}
		}
		fclose(file);
		delete (copy);
	}
}

int total(int num, struct city *Cordoba, struct city *SF, struct city *Mendoza)
{
	int cba = 0, men = 0, sf = 0;
	city *copy = NULL, *headC = Cordoba, *headSF = SF, *headM = Mendoza;

	if (num == 1)
	{
		copy = headC;
		while (copy != NULL)
		{
			cba += 1;
			copy = copy->next;
		}

		cout << "La cantidad de mediciones tomadas en Córdoba es de: " << cba;
		return cba;
	}
	else
	{
		if (num == 2)
		{
			copy = headM;
			while (copy != NULL)
			{
				men += 1;
				copy = copy->next;
			}

			cout << "La cantidad de mediciones tomadas en Mendoza es de: " << men;
			return men;
		}
		else
		{
			copy = headSF;
			while (copy != NULL)
			{
				sf += 1;
				copy = copy->next;
			}

			cout << "La cantidad de mediciones tomadas en Santa Fe es de: " << sf;
			return sf;
		}
	}
}

void promCiud()
{
}

float promProv(int num, struct city *Cordoba, struct city *SF, struct city *Mendoza)
{
	city *headC = Cordoba, *headSF = SF, *headM = Mendoza, *copy = NULL;
	int contador = 0;
	float temp = 0, promcba = 0, prommen = 0, promsf = 0;

	if (num == 1)
	{
		copy = headC;
		while (copy != NULL)
		{
			temp += Cordoba->m.temp;
			contador += 1;
			copy = copy->next;
		}
		promcba = temp / contador;
		return promcba;
	}
	else
	{
		if (num == 2)
		{
			copy = headM;
			while (copy != NULL)
			{
				temp += Mendoza->m.temp;
				contador += 1;
				copy = copy->next;
			}
			prommen = temp / contador;
			return prommen;
		}
		else
		{
			copy = headSF;
			while (copy != NULL)
			{
				temp += SF->m.temp;
				contador += 1;
				copy = copy->next;
			}
			promsf = temp / contador;
			return promsf;
		}
	}
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

void plantarPimientos(float tempcba, float tempmen, float tempsf,struct city *Cordoba, struct city *SF, struct city *Mendoza )
{			
	if(tempcba==0){
		tempcba = promProv(1, Cordoba, SF, Mendoza);
	}
	if(tempmen==0){
		tempmen = promProv(2, Cordoba, SF, Mendoza);
	}if(tempsf==0){
		tempsf = promProv(3, Cordoba, SF, Mendoza);
	}

	//acá tendría q 


}
