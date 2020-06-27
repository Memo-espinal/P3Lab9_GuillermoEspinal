#include <iostream>
#include<string>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include"Soldado.h"
#include "Sasalto.h"
#include "Ssoporte.h"

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	vector<Soldado*>V1soldados;
	vector<Soldado*>V2soldados;
	loop :
		int resp=0;
		cout<< "1. Crear soldado"<< endl;
		cout<<"2. Eliminar soldados"<<endl;
		cout<<"3. Listar soldados"<<endl;
		cout<<"4. Guardar soldados"<<endl;
		cout<<"5. Cargar soldados"<<endl;
		cout<<"6. Simulación"<<endl;
		cout<<"7. Salir"<<endl;
		cin>>resp;
		switch(resp){
			case 1:{
				int lista=0;
				cout <<"Para que lista quiere crear:"<< endl;
				cout <<" 1"<< endl;
				cout <<" 2"<< endl;
				cin>> lista;
				int crear=0;
				cout << "Ingrese que quiere crear:"<< endl;
				cout <<"1.-Soldado de Asalto"<< endl;
				cout <<"2.-Soldado de Soporte" << endl;
				cin>> crear ;
				string nombre;
				int pvida=0;
				int pfuerza=0;
				cout << "Ingrese el nombre : "<< endl;
				getline(cin,nombre);
				getline(cin,nombre);
				cout <<"Ingrese los puntos de vida: "<< endl;
				cin>> pvida;
				cout <<"Ingrese los puntos de fuerza : "<< endl;
				cin >>pfuerza;
				
				if (crear==1){
					int velocidad;
					int fextra;
					cout <<"Ingrese la velocidad:"<<endl;
					cin>> velocidad;
					cout<<"Ingrese la fuerza extra: "<< endl;
					cin>> fextra;
					if(lista==1){
						V1soldados.push_back(new Sasalto(pvida,pfuerza,velocidad,fextra));
					}else{
						V2soldados.push_back(new Sasalto(pvida,pfuerza,velocidad,fextra));
					}
				}else{
					int blindaje=0;
					int camuflaje=0;
					cout<<"Ingrese la cantidad de blindaje: "<<endl;
					cin>>blindaje;
					cout <<"Ingrese la cantidad de camuflaje: "<<endl;
					cin>> camuflaje;
					if(lista==1){
						V1soldados.push_back(new Ssoporte(pvida,pfuerza,blindaje,camuflaje));
					}else{
						V2soldados.push_back(new Sasalto(pvida,pfuerza,blindaje,camuflaje));
					}
				}
				
				goto loop;
				break;
			}
			case 2 :{
				int lista=0;
				cout<<"De que lista quiere eliminar soldados?"<<endl;
				cin>>lista;
				if(lista==1){
					if(V1soldados.size()>0){
						for (int i=0; i<V1soldados.size();i++){
							cout<< i <<".- "<<" "<<"Vida: "<<V1soldados[i]->getVida()<<" Fuerza: "<<V1soldados[i]->getFuerza()<<V1soldados[i]->toString()<<endl;
						}
					}else{
						cout<<"No hay soldados en esa lista"<< endl;
					}
					
				}else if (lista==2){
					if(V2soldados.size()>0){
						for (int i=0; i<V2soldados.size();i++){
							cout<< i <<".- "<<" "<<"Vida: "<<V2soldados[i]->getVida()<<" Fuerza: "<<V2soldados[i]->getFuerza()<<V2soldados[i]->toString()<<endl;
						}	
					}else{
						cout<<"No hay solados en esta lista"<<endl;
					}	
				}
				int elim=0;
				cout<<"INgrese que soldado quiere eliminar: "<< endl;
				cin>>elim;
				if(lista==1){
					if(elim>V1soldados.size()){
						cout<<"Esa no es una posiciion de los soldados"<<endl;
					}else{
						V1soldados.erase(V1soldados.begin()+elim);
						cout<<"El soldado de ha eliminado!"<< endl;
					}
				}else if (lista==2){
					if(elim>V2soldados.size()){
						cout<<"Esa no es una posicion de los soldados"<<endl;
					}else{
						V2soldados.erase(V2soldados.begin()+elim);
						cout<<"El soldado de ha eliminado!"<< endl;
					}
				}
				if(lista!=1){
					if(lista!=2){
						cout<<"Solo hay 2 listas";
					}
				}
				goto loop;
				break;
			}
			case 3 :{
				int lista=0;
				cout <<" que lista quiere ver ?"<<endl;
				cout<< "Lista 1 : "<< V1soldados.size()<< " ";
				cout<<"Lista 2 : "<<V2soldados.size()<<endl;
				cin>>lista;
				cout<< lista<< endl;
				if(lista==1){
					//cout <<"entre al if "<<endl;
					if(V1soldados.size()>0){
						for (int i=0; i<V1soldados.size();i++){
							//cout<< "almenos llego al for.";
							cout<< i <<".- "<<" "<<"Vida: "<<V1soldados[i]->getVida()<<" Fuerza: "<<V1soldados[i]->getFuerza()<<V1soldados[i]->toString()<<endl;
						}
					}else{
						cout<<"No hay soldados en esa lista"<< endl;
					}
					
				}else if (lista==2){
					if(V2soldados.size()>0){
						for (int i=0; i<V2soldados.size();i++){
							cout<< i <<".- "<<" "<<"Vida: "<<V2soldados[i]->getVida()<<" Fuerza: "<<V2soldados[i]->getFuerza()<<V2soldados[i]->toString()<<endl;
						}
					}else{
						cout<<"No hay soldados en esa lista"<< endl;
					}
				}else{
					cout<<"SOlo hay 2 listas"<< endl;
				}
				goto loop;
				break;
			}
			case 4 :{
				ofstream file("soldados1.bin", ios::binary|ios::trunc);
				if(file.is_open()){
					 size_t tempSize=0;
					 for (int i =0 ; i<V1soldados.size();i++){
					 	Soldado* temp =V1soldados[i]; 
					 	tempSize=temp->getSize();
					 	file.write((char*)&tempSize,sizeof(size_t));
					 	file.write((char*)temp,tempSize);
					} 
				}
				ofstream file2("soldados2.bin", ios::binary|ios::trunc);
				if(file.is_open()){
					 size_t tempSize=0;
					 for (int i =0 ; i<V2soldados.size();i++){
					 	Soldado* temp =V2soldados[i];
					 	tempSize=temp->getSize();
					 	file2.write((char*)&tempSize,sizeof(size_t));
					 	file2.write((char*)temp,tempSize);
					} 
				}
				file.close();
				file2.close();
				goto loop;
				break;
			}
			case 5 : {
				V1soldados.clear();
				V2soldados.clear();
				ifstream file("soldados1.bin",ios::binary);
				//if(file.is_open()){
				size_t tempSize=0;
					while(file.read((char*) &tempSize, sizeof(size_t))){
						cout<<"entre al while   ";
						Soldado* soldado=(Soldado*)malloc(tempSize);
						//cout<<"me mame antes del read: ";
						file.read((char*)soldado,tempSize);
						cout<<tempSize;
						//cout << soldado->getNombre()<<endl;
						//cout<<"me mame antes del push";
						V1soldados.push_back(soldado);
						cout<<"meti al soldado";
					}
				//}
				//Segundo archivo
				ifstream file2("soldados2.bin",ios::binary);
				//if(file2.is_open()){
				 tempSize=0;
					while(file2.read((char*) &tempSize, sizeof(size_t))){
						Soldado* soldado=(Soldado*)malloc(tempSize);
						file2.read((char*)soldado,tempSize);
							cout<<tempSize;
						V2soldados.push_back(soldado);
					}
				//}//
				cout<<"Cargados los soldados!"<<endl;
				file.close();
				file2.close();
				
				goto loop;
				break;
			}
			case 6: {
				if(V1soldados.size()>0&&V2soldados.size()>0){
					int turno =1;
					while(V1soldados.size()>0&&V2soldados.size()>0){
						srand(time(NULL));
						int num1=0;
						int num2 =0;
						num1= 0+rand()%(V1soldados.size()-0);
						num2= 0+rand()%(V2soldados.size()-0);	
						if (turno%2!=0){
							cout<<"Turno "<<turno<<"lista 1 sera la atacante y lista 2 la defensora!!!"<<endl;
							Soldado* atacante=V1soldados[num1];
							Soldado* defensor=V2soldados[num2];
							int ataque = atacante->Ataque(defensor);
							defensor->Defensa(ataque,atacante);
							if(defensor->getVida()<=0){
								V2soldados.erase(V2soldados.begin()+num2);
								cout<<"!!Defensor muere! sera eliminado!!"<<endl;
							}else{
								cout<<"!!Aguanto como macho pecho peludo!!"<<endl;
							}
						}else{
							cout<<"Turno "<<turno<<"lista 2 sera la atacante y lista 1 la defensora!!!"<<endl;
							Soldado* atacante=V2soldados[num2];
							Soldado* defensor=V1soldados[num1];
							int ataque =atacante->Ataque(defensor);
							defensor->Defensa(ataque,atacante);
							if(defensor->getVida()<=0){
								V1soldados.erase(V1soldados.begin()+num1);
								cout<<"!!Defensor muere! sera eliminado!!"<<endl;
							}else{
								cout<<"!!Aguanto como macho pecho peludo!!"<<endl;
							}
							
						}
						cout<<"\n\nLista 1 restantes: "<<V1soldados.size()<<"  Lista 2 restantes : "<<V2soldados.size();
						turno++;
					}
					
					cout<< "simulacion terminada!!"<<endl;
					
				}
				
			
				
				
				
				break;
			}
				
		}
	
	
	return 0;
}
