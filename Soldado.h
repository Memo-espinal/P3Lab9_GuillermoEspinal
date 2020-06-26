#ifndef SOLDADO_H
#define SOLDADO_H
#include <string>
using namespace std;


class Soldado
{
	public:
		Soldado();
		virtual int Ataque(Soldado*)=0;
		virtual void Defensa(int, Soldado*)=0;
		~Soldado();
	protected:
		//nombre, puntos de
//vida y puntos de fuerza. 
	string nombre;
	int pvida;
	int pfuerza;
};

#endif
