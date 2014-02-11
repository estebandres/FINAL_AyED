#include "Paquete.h"
#include <iostream>


using namespace std;
//using std::vector;

Paquete::Paquete(){
	this->ip_comp_origen=vector<int>(-1,-1);
	this->ip_comp_destino=vector<int>(-1,-1);
	this->id_pagina=-1;
	this->tamanio_pagina=-1;
	this->nro_orden=-1;
}
Paquete::Paquete(vector<int> ip_comp_origen, vector<int> ip_comp_destino, int id_pagina, int tamanio_pagina, int nro_orden){
	this->ip_comp_origen=ip_comp_origen;
	this->ip_comp_destino=ip_comp_destino;
	this->id_pagina=id_pagina;
	this->tamanio_pagina=tamanio_pagina;
	this->nro_orden=nro_orden;
}

vector<int> Paquete::obtener_ip_comp_origen(){
	return this->ip_comp_origen;
}

vector<int> Paquete::obtener_ip_comp_destino(){
	return this->ip_comp_destino;
}

int Paquete::obtener_id_pagina(){
	return this->id_pagina;
}

int Paquete::obtener_nro_orden(){
	return this->nro_orden;
}

int Paquete::obtener_tamanio_pagina(){
	return this->tamanio_pagina;
}

void Paquete::imprimir(int id_pag){
	//cout<<"PAQUETE:"<<this->nro_orden<<" --> PÁGINA: "<<this->id_pagina<<endl;
	if(this->id_pagina==id_pag)
		cout<<BOLD_YELLOW<<"[PAG:"<<this->id_pagina<<",Ro:"<<this->ip_comp_origen[0]<<",Rd:"<<this->ip_comp_destino[0]<<",ORD:"<<this->nro_orden<<"/"<<this->tamanio_pagina<<"]"<<ANSI_COLOR_RESET;
	else
		cout<<"[PAG:"<<this->id_pagina<<",Ro:"<<this->ip_comp_origen[0]<<",Rd:"<<this->ip_comp_destino[0]<<",ORD:"<<this->nro_orden<<"/"<<this->tamanio_pagina<<"]";
}

void Paquete::cambiar_orden(int nvo_nro_orden){
	this->nro_orden=nvo_nro_orden;
}

Paquete::~Paquete(){
	
}
