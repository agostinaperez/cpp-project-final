
#include "libreria.h"

E menu (V){
	E op;
	std::cout<<"Ingrese una opción: \n 1. Total de las muestras almacenadas en las listas pertenecientes a cada provincia\n 2. Temperatura promedio de cada provincia\n 3.Temperatura promedio de cada ciudad\n 4.Ciudad m?s c?lida de cada provincia\n 5. Ciudad mas fr?a de cada provincia\n 6. D?a m?s fr?o de cada provincia\n 7. D?a m?s c?lido de cada ciudad\n 8. Mejor provincia para el cultivo de pimientos (temperatura promedio cercana a 23 grados cent?grados)\n 0.Salir"<<endl;
	cin>>op;
	return op;
}
	
	City::City(){
		FILE *fp;
		int id_c=0, id_p=0, temp=0, h=0, hh=0, mm=0, dia=0, mes=0;
		char nombre[50];
		fp=fopen("./data_set.txt", "r");
		fscanf(fp, "%d, %d, %c, %d, %d, %d, %d, %d, %d", &id_c, &id_p,&nombre[50], &temp, &h, &hh, &mm, &dia, &mes);
		this->city.cityId=id_c;
		fclose(fp);
	}
	
	V City::total (FILE *fp){
		fp=fopen("./data_set.txt", "r");
		
		
	}
	
	V City:: promCiud (V){
		
	}
	
	V City::promProv (V){
		
	}
	
	V City::ciudadCalida (V){
		
	}
	
	V City::ciudadFria (V){
		
	}
	
	V City::diaCalido (V){
		
	}
	
	V City::diaFrio (V){
		
	}
	
	V City::plantarPimientos (V){
		
	}
	
	
