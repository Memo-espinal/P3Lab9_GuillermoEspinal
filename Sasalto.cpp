#include "Sasalto.h"


Sasalto::Sasalto(string Dnombre,int Dvida,int Dfuerza,int Dvelocidad,int DFextra )
{
	nombre=Dnombre;
	pvida=Dvida;
	pfuerza= Dfuerza;
	velocidad= Dvelocidad;
	Fextra = DFextra;

}
int Sasalto::Ataque(Soldado* atacado){
	if(typeid(*atacado)==typeid(Sasalto)) {
		 return pfuerza*10;
	}else {
		return pfuerza* (10 + (velocidad * 2));
	}
}
void Sasalto::Defensa(int ataque , Soldado* atacante){
	if(typeid(*atacante)==typeid(Sasalto)) {
		 pvida = pvida-ataque;
	}else {
		pvida = pvida - (ataque/Fextra);
	}
	
}

Sasalto::~Sasalto()
{
}
