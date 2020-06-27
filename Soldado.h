#ifndef SOLDADO_H
#define SOLDADO_H
#include<string>
//#include <string>
using namespace std;


class Soldado
{
	public:
		Soldado();
		virtual int Ataque(Soldado*)=0;
		virtual void Defensa(int, Soldado*)=0;
		virtual string toString()=0;
		virtual size_t getSize()=0;
		//string getNombre();
		int getVida();
		int getFuerza();
		~Soldado();
	protected:
		//nombre, puntos de
//vida y puntos de fuerza. 
	//string nombre;
	int pvida;
	int pfuerza;
};

#endif
