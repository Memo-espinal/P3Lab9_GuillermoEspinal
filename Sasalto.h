#ifndef SASALTO_H
#define SASALTO_H

#include "Soldado.h"
#include <string>
#include <typeinfo>
using namespace std;


class Sasalto : public Soldado
{
	public:
		Sasalto(int,int,int,int);
		int Ataque(Soldado*);
		void Defensa(int , Soldado*);
		string toString();
		size_t getSize();
		int getVelocidad();
		int getFextra();
		~Sasalto();
	protected:
		int velocidad;
		int Fextra;
};

#endif
