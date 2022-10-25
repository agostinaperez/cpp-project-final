#ifndef LIBRERIA_H
#define LIBRERIA_H

#include <iostream>
#include <cstring>
using namespace std;

int menu(void);

struct timestamp{
	int day;
	int month;
	int hh;
	int mm;
};

struct measurement{
	struct timestamp time;
	float temp;
	float hum;
};


struct city{
	struct city *next;
	struct measurement m;
	int cityId;
	char cityName[50];
};

class Provincia{
	private:
		struct city ciudades;
	public:
		void setData(int);
		void total(void);
		void promProv(void);
		void promCiud(void);
		void ciudadCalida(void);
		void ciudadFria(void);
		void diaFrio(void);
		void diaCalido(void);
		void plantarPimientos(void);
		
};



#endif
