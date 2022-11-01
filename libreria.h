#ifndef LIBRERIA_H
#define LIBRERIA_H

#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <stdio.h>


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

class Archivo{
	private:
		FILE *fp;
	public:
		Archivo();
		};

		int total(int);
		float promProv(int, int);
		void promCiud(void);
		void ciudadCalida(void);
		void ciudadFria(void);
		void diaFrio(void);
		void diaCalido(void);
		void plantarPimientos(void);

#endif
