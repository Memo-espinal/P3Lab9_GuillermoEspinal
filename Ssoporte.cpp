#include "Ssoporte.h"
#include "Sasalto.h"

Ssoporte::Ssoporte(int Dvida,int Dfuerza,int Dblindaje,int Dcamuflaje  )
{
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
int Ssoporte::getBlindaje(){
	return blindaje;
}
int Ssoporte::getCamuflaje(){
	return camuflaje;
}
string Ssoporte::toString(){
	string ret = "Blindaje: ";
	ret+=to_string(blindaje);
	ret+=" ";
	ret+="Camuflaje: ";
	ret+=to_string(camuflaje);
	return ret;
}
size_t Ssoporte::getSize(){
	return sizeof(Ssoporte);
}

Ssoporte::~Ssoporte()
{
}
