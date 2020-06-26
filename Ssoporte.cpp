#include "Ssoporte.h"
#include "Sasalto.h"

Ssoporte::Ssoporte(string Dnombre,int Dvida,int Dfuerza,int Dblindaje,int Dcamuflaje  )
{
	nombre=Dnombre;
	pvida=Dvida;
	pfuerza= Dfuerza;
	blindaje=Dblindaje; 
	camuflaje=Dcamuflaje;
}
int Ssoporte::Ataque(Soldado* atacado){
	if(typeid(*atacado)==typeid(Sasalto)) {
		 return pfuerza*(15+camuflaje);
	}else {
		return pfuerza* (10);
	}
}
void Ssoporte::Defensa(int ataque , Soldado* atacante){
	if(typeid(*atacante)==typeid(Sasalto)) {
		 pvida = pvida-(ataque/blindaje*2);
	}else {
		pvida = pvida-ataque;
	}
	
}

Ssoporte::~Ssoporte()
{
}
