#ifndef LIBRERIA_H
#define LIBRERIA_H

#include <iostream>
#include <cstring>
using namespace std;

typedef int E;
typedef char C;
typedef float F;
typedef void V;

E menu(V);

class Provincia{
	private:
		struct city ciudades[55];
		E id;
	public:
		V setData(V);
		V total(V);
		V promProv(V);
		V promCiud(V);
		V ciudadCalida(V);
		V ciudadFria(V);
		V diaFrio(V);
		V diaCalido(V);
		V plantarPimientos(V);
		
};

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
	C cityName[50];
};

#endif
