#include "Sasalto.h"


Sasalto::Sasalto(int Dvida,int Dfuerza,int Dvelocidad,int DFextra )
{
	//nombre=Dnombre;
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
int Sasalto:: getVelocidad(){
	return velocidad;
}
int Sasalto::getFextra(){
	return Fextra;
}
string Sasalto::toString(){
	string ret = " velocidad: ";
	ret+=to_string(velocidad);
	ret+=" ";
	ret+="Fuerza extra: ";
	ret+=to_string(Fextra);
	return ret;
}
size_t Sasalto::getSize(){
	return sizeof(Sasalto);
}

Sasalto::~Sasalto()
{
}
