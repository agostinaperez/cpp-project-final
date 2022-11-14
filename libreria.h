#ifndef LIBRERIA_H
#define LIBRERIA_H

#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <cmath>
#include <stdio.h>

using namespace std;
int menu(void);

struct timestamp
{
	int day;
	int month;
	int hh;
	int mm;
};

struct measurement
{
	struct timestamp time;
	float temp;
	float hum;
};

struct city
{
	struct city *next;
	struct measurement m;
	int cityId;
	char cityName[50];
};

class Archivo
{
private:
	FILE *file;

public:
	Archivo();
	void get(struct city **, struct city **, struct city **);
};

int total(int, struct city **, struct city **, struct city **);
float promProv(int, struct city *, struct city *, struct city *);
void promCiud(struct city *, struct city *, struct city *);
void ciudadCalida(struct city *, struct city *, struct city *);
void ciudadFria(struct city *, struct city *, struct city *);
void diaFrio(struct city *, struct city *, struct city *);
void diaCalido(struct city *, struct city *, struct city *);
void plantarPimientos(float, float, float, struct city *, struct city *, struct city *);

#endif
