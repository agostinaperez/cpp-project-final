#include "libreria.h"

int menu()
{
	int op;
	cout << "Ingrese una opcion: \n 1. Total de las muestras almacenadas en las listas pertenecientes a cada provincia\n 2. Temperatura promedio de cada provincia\n 3.Temperatura promedio de cada ciudad\n 4.Ciudad mas calida de cada provincia\n 5. Ciudad mas fria de cada provincia\n 6. Dia mas frio de cada provincia\n 7. Dia mas calido de cada ciudad\n 8. Mejor provincia para el cultivo de pimientos (temperatura promedio cercana a 23 grados centigrados)\n 0.Salir" << endl;
	cin >> op;
	return op;
}

//constructor
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

void Archivo::get(struct city ** Cordoba, struct city ** SF, struct city ** Mendoza)
{
	int codProv = 0, codCiud = 0, hh = 0, mm = 0, month = 0, day = 0;
	float hum = 0, temp = 0;
	char nombre[50];

	//creación de listas complementarias (copy, y los heads)
	city *copy = NULL, *newNode=NULL;
	file = fopen("./data_set.txt", "r");

	//recorrido del archivo
	while (!feof(file)){	
		newNode=new(city);
		if(newNode==NULL){
			cout<<"No hay suficiente espacio de memoria";
			exit(1);
		}
		
		//lectura de datos
		fscanf(file, "%d\t%d\t%s\t%f\t%f\t%d\t%d\t%d\t%d", &codCiud, &codProv, &nombre, &temp, &hum, &hh, &mm, &day, &month);

		/*este if se hace para cargar cada medición en su correspondiente
		provincia, según su código de provincia*/
		if (codProv == 3)
		{
			newNode->cityId = codCiud;
			strcpy(newNode->cityName, nombre);
			newNode->m.hum = hum;
			newNode->m.temp = temp;
			newNode->m.time.day = day;
			newNode->m.time.month = month;
			newNode->m.time.mm = mm;
			newNode->m.time.hh = hh;
			newNode->next = NULL;

			if (*Cordoba == NULL)
			{
				*Cordoba= newNode;
			}
			else
			{
				copy = *Cordoba;
				while (copy->next != NULL)
				{
					copy = copy->next;
				}
				copy->next = newNode;
			}
		}
		else
		{
			if (codProv == 1)
			{
				newNode->cityId = codCiud;
				strcpy(newNode->cityName, nombre);
				newNode->m.hum = hum;
				newNode->m.temp = temp;
				newNode->m.time.day = day;
				newNode->m.time.month = month;
				newNode->m.time.mm = mm;
				newNode->m.time.hh = hh;
				newNode->next = NULL;

				if (*Mendoza == NULL)
				{
					*Mendoza= newNode;
				}
				else
				{
					copy = *Mendoza;
					while (copy->next != NULL)
					{
						copy = copy->next;
					}
					copy->next = newNode;
				}
			}
			else
			{
				if (codProv == 2)
				{
					newNode->cityId = codCiud;
					strcpy(newNode->cityName, nombre);
					newNode->m.hum = hum;
					newNode->m.temp = temp;
					newNode->m.time.day = day;
					newNode->m.time.month = month;
					newNode->m.time.mm = mm;
					newNode->m.time.hh = hh;
					newNode->next = NULL;
		

					if (*SF == NULL)
					{
						*SF = newNode;
					}
					else
					{
						copy = *SF;
						while (copy->next != NULL)
						{
							copy = copy->next;
						}
						copy->next = newNode;
					}
				}
			}
		}
		
	}
	
	
	fclose(file);
	
}


void total(int num, struct city **Cordoba, struct city **SF, struct city **Mendoza){
	
	//no s� por qu� no me funciona esto
	int men = 0, sf = 0, numero=0;
	long cba=0;
	city *copy = NULL;
	numero=num;
	

	if (numero == 3){
		
		copy = *Cordoba;
		while (copy != NULL)
		{
			cba =cba+ 1;
			copy = copy->next;
		}

		cout << "La cantidad de mediciones tomadas en Cordoba es de: " << cba<<endl;
	}
	else
	{
		if (numero == 1)
		{
			copy = *Mendoza;
			while (copy != NULL)
			{
				men =men+ 1;
				copy = copy->next;
			}

			cout << "La cantidad de mediciones tomadas en Mendoza es de: " << men<<endl;
		}
		else
		{
			copy = *SF;
			while (copy != NULL)
			{
				sf =sf+ 1;
				copy = copy->next;
			}

			cout << "La cantidad de mediciones tomadas en Santa Fe es de: " << sf<<endl;
		}
	}
	free(copy);
	
}

void promCiud(struct city *Cordoba, struct city *SF, struct city *Mendoza)
{	int ciudades=0;
	float acumulador=0, cant=0, t=0;
	string nombre;
	city *copy=NULL;
	int cod_ciud=0;
	copy=Cordoba;

	while (copy != NULL)
	{
		cod_ciud=copy->cityId;
		if (cod_ciud==ciudades){
			acumulador+=copy->m.temp;
			cant+=1;
			nombre=copy->cityName;

		}
		else{
			t=(acumulador/cant);
			cout<<"La temperatura promedio de la ciudad "<<nombre<<" es de "<<t<<endl;
			ciudades+=1;
		}

		copy = copy->next;
	}
	
	copy=Mendoza;
	ciudades=77;
	cant=0;
	acumulador=0;
	while (copy != NULL)
	{
		cod_ciud=copy->cityId;
		if (cod_ciud==ciudades){
			acumulador=acumulador+copy->m.temp;
			cant+=1;
			nombre=copy->cityName;
		}
		else{
			t=acumulador/cant;
			cout<<"La temperatura promedio de la ciudad "<<nombre<<" es de "<<t<<endl;
			ciudades+=1;
		}

		copy = copy->next;
	}

	copy=SF;
	ciudades=24;
	cant=0;
	acumulador=0;
	while (copy != NULL)
	{
		cod_ciud=copy->cityId;
		if (cod_ciud==ciudades){
			acumulador+=copy->m.temp;
			cant+=1;
			nombre=copy->cityName;
		}
		else{
			t=acumulador/cant;
			cout<<"La temperatura promedio de la ciudad "<<nombre<<" es de "<<t<<endl;
			ciudades+=1;
		}

		copy = copy->next;
	}

	free(copy);


}

float promProv(int num, struct city *Cordoba, struct city *SF, struct city *Mendoza)
{
	city *copy = NULL;
	int contador = 0;
	float temp = 0, promcba = 0, prommen = 0, promsf = 0;

	if (num == 3)
	{
		copy = Cordoba;
		while (copy != NULL)
		{
			temp += copy->m.temp;
			contador += 1;
			copy = copy->next;
		}
		promcba = temp / contador;
		free(copy);
		return promcba;
	}
	else
	{
		if (num == 1)
		{
			copy = Mendoza;
			while (copy != NULL)
			{
				temp += copy->m.temp;
				contador += 1;
				copy = copy->next;
			}
			prommen = temp / contador;
			free(copy);
			return prommen;
		}
		else
		{
			copy = SF;
			while (copy != NULL)
			{
				temp += copy->m.temp;
				contador += 1;
				copy = copy->next;
			}
			promsf = temp / contador;
			free(copy);
			return promsf;
		}
	}

}

void ciudadCalida(struct city *Cordoba, struct city *SF, struct city *Mendoza)
{	city *copy=NULL;
	string cCor, cSF, cMen;
	float mayor=-100;
	copy=Cordoba;
	while (copy != NULL)
		{	if((copy->m.temp)>mayor){
			cCor=copy->cityName;
			mayor=copy->m.temp;
		}	
			copy = copy->next;
		}

	cout<<"La ciudad mas calida de Cordoba es "<<cCor<<endl;

	mayor=-100;
	copy=Mendoza;
	while (copy != NULL)
		{	if((copy->m.temp)>mayor){
			cMen=copy->cityName;
			mayor=copy->m.temp;
		}	
			copy = copy->next;
		}

	cout<<"La ciudad mas calida de Mendoza es "<<cMen<<endl;

	mayor=-100;
	copy=SF;
	while (copy != NULL)
		{	if((copy->m.temp)>mayor){
			cSF=copy->cityName;
			mayor=copy->m.temp;
		}	
			copy = copy->next;
		}

	cout<<"La ciudad mas calida de Santa Fe es "<<cSF<<endl;
	free(copy);

}

void ciudadFria(struct city *Cordoba, struct city *SF, struct city *Mendoza)
{	city *copy=NULL;
	string fCor, fSF, fMen;
	float menor=100;
	copy=Cordoba;
	while (copy != NULL)
		{	if((copy->m.temp)<menor){
			fCor=copy->cityName;
			menor=copy->m.temp;
		}	
			copy = copy->next;
		}

	cout<<"La ciudad mas fria de Cordoba es "<<fCor<<endl;

	menor=100;
	copy=Mendoza;
	while (copy != NULL)
		{	if((copy->m.temp)<menor){
			fMen=copy->cityName;
			menor=copy->m.temp;
		}	
			copy = copy->next;
		}

	cout<<"La ciudad mas fria de Mendoza es "<<fMen<<endl;

	menor=100;
	copy=SF;
	while (copy != NULL)
		{	if((copy->m.temp)<menor){
			fSF=copy->cityName;
			menor=copy->m.temp;
		}	
			copy = copy->next;
		}

	cout<<"La ciudad mas fria de Santa Fe es "<<fSF<<endl;
	free(copy);

}

void diaCalido(struct city *Cordoba, struct city *SF, struct city *Mendoza)
{	city *copy=NULL;
	int dia=0, mes=0;
	float mayor=-100;
	copy=Cordoba;
	while (copy != NULL)
		{	if((copy->m.temp)>mayor){
			dia=copy->m.time.day;
			mes=copy->m.time.month;
			mayor=copy->m.temp;
		}	
			copy = copy->next;
		}

	cout<<"El dia mas calido de Cordoba fue el "<<dia<<"/"<<mes<<endl;

	mayor=-100;
	copy=Mendoza;
	while (copy != NULL)
		{	if((copy->m.temp)>mayor){
			dia=copy->m.time.day;
			mes=copy->m.time.month;
			mayor=copy->m.temp;
		}	
			copy = copy->next;
		}

	cout<<"El dia mas calido de Mendoza fue el "<<dia<<"/"<<mes<<endl;

	mayor=-100;
	copy=SF;
	while (copy != NULL)
		{	if((copy->m.temp)>mayor){
			dia=copy->m.time.day;
			mes=copy->m.time.month;
			mayor=copy->m.temp;
		}	
			copy = copy->next;
		}

	cout<<"El dia mas calido de Santa Fe fue el "<<dia<<"/"<<mes<<endl;

	free(copy);
}

void diaFrio(struct city *Cordoba, struct city *SF, struct city *Mendoza)
{	city *copy=NULL;
	int dia=0, mes=0;
	float menor=100;
	copy=Cordoba;
	while (copy != NULL)
		{	if((copy->m.temp)<menor){
			dia=copy->m.time.day;
			mes=copy->m.time.month;
			menor=copy->m.temp;
		}	
			copy = copy->next;
		}

	cout<<"El dia mas frio de Cordoba fue el "<<dia<<"/"<<mes<<endl;

	menor=100;
	copy=Mendoza;
	while (copy != NULL)
		{	if((copy->m.temp)<menor){
			dia=copy->m.time.day;
			mes=copy->m.time.month;
			menor=copy->m.temp;
		}	
			copy = copy->next;
		}

	cout<<"El dia mas frio de Mendoza fue el "<<dia<<"/"<<mes<<endl;

	menor=100;
	copy=SF;
	while (copy != NULL)
		{	if((copy->m.temp)<menor){
			dia=copy->m.time.day;
			mes=copy->m.time.month;
			menor=copy->m.temp;
		}	
			copy = copy->next;
		}

	cout<<"El dia mas frio de Santa Fe fue el "<<dia<<"/"<<mes<<endl;

	free(copy);
}

void plantarPimientos(float tempcba, float tempmen, float tempsf, struct city *Cordoba, struct city *SF, struct city *Mendoza)
{
	float cba = 0, sf = 0, men = 0;

	if (tempcba == 0)
	{
		tempcba = promProv(1, Cordoba, SF, Mendoza);
	}
	if (tempmen == 0)
	{
		tempmen = promProv(2, Cordoba, SF, Mendoza);
	}
	if (tempsf == 0)
	{
		tempsf = promProv(3, Cordoba, SF, Mendoza);
	}

	cba = abs(tempcba - 23);

	sf = abs(tempsf - 23);

	men = abs(tempmen - 23);

	if (cba < men && cba < sf)
	{
		cout << "La mejor provincia para plantar pimientos es Cordoba"<<endl;
	}
	else
	{
		if (men < cba && men < sf)
		{
			cout << "La mejor provincia para plantar pimientos es Mendoza"<<endl;
		}
		else
		{
			if (sf < cba && sf < men)
			{
				cout << "La mejor provincia para plantar pimientos es Santa Fe"<<endl;
			}
		}
	}
}
