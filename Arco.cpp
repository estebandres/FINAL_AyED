#include "Arco.h"
Arco::Arco(int origen, int destino, int peso) : nodo_origen(origen),nodo_destino(destino),peso_arco(peso)
{}
Arco::~Arco(){
}
int Arco::origen(){
	return this->nodo_origen;
}
int Arco::destino(){
	return this->nodo_destino;
}
int Arco::peso(){
	return this->peso_arco;
}
void Arco::mod_peso(int nvo_peso){
	this->peso_arco=nvo_peso;
}
void Arco::imprimir(){
	cout<<"["<<this->nodo_origen<<"|"<<this->nodo_destino<<"|"<<this->peso_arco<<"]";
}
