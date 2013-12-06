#include "Arco.h"
Arco::Arco(int origen, int destino, int peso){
	this->origen=origen;
	this->destino=destino;
	this->peso=peso;
}
Arco::~Arco(){
}
int Arco::origen(){
	return origen;
}
int Arco::destino(){
	return destino;
}
void Arco::mod_peso(int nvo_peso){
	this->peso=nvo_peso;
}

