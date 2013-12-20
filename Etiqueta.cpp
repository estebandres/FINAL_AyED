#include "Etiqueta.h"

Etiqueta::Etiqueta(int router_destino, int peso_trayecto) : camino(){
	this->router_destino=router_destino;
	this->camino.agregar(this->router_destino);
	//this->router_despacho=router_despacho;//router al que se debe despachar los paquetes que tienen como destino el router_destino;
	this->peso_trayecto=peso_trayecto;
}
Etiqueta::~Etiqueta(){
}
int Etiqueta::despacho(){
	if(this->camino.es_vacia()){
		return -1;
	}
	else{
		return this->camino.primer_elemento();
	}
}
int Etiqueta::destino(){
	return this->router_destino;
}
int Etiqueta::peso_total(){
	return this->peso_trayecto;
}
void Etiqueta::mod_peso_trayecto(int nvo_peso){
	this->peso_trayecto = nvo_peso;
}
/*void Etiqueta::mod_despacho(int nvo_router_despacho){
	this->router_despacho = nvo_router_despacho;
}*/
void Etiqueta::imprimir(){
	cout<<"["<<this->router_destino<<"|"<<this->despacho()<<"|"<<this->peso_trayecto<<"]";
}
void Etiqueta::agregar_nodo(int nodo){
		this->camino.quitar_ultimo_nodo();
		this->camino.agregar(nodo);
		this->camino.agregar(this->router_destino);
}
Lista<int> Etiqueta::obtener_camino(){
	return this->camino;
}
