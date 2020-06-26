#ifndef SSOPORTE_H
#define SSOPORTE_H

#include "Soldado.h"
#include <string>
#include <typeinfo>
using namespace std;

class Ssoporte : public Soldado
{
	public:
		Ssoporte(string,int,int,int,int);
		int Ataque(Soldado*);
		void Defensa(int , Soldado*);
		~Ssoporte();
	protected:
		int blindaje;
		int camuflaje;
};

#endif
