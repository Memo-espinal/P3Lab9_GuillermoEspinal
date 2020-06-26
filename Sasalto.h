#ifndef SASALTO_H
#define SASALTO_H

#include "Soldado.h"
#include <string>
#include <typeinfo>
using namespace std;


class Sasalto : public Soldado
{
	public:
		Sasalto(string,int,int,int,int);
		int Ataque(Soldado*);
		void Defensa(int , Soldado*);
		~Sasalto();
	protected:
		int velocidad;
		int Fextra;
};

#endif
