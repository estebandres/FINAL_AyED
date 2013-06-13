#include "Pagina.h"

Pagina::Pagina(int id, int tamanio, int* ip_comp_origen, int* ip_comp_destino){
	this->id = id;
	this->tamanio = tamanio;
	int [2] nvo_vector1;
	int [2] nvo_vector2;
	for(int i=0; i<2; i++){
		nvo_vector1[i] = ip_comp_origen[i];
		nvo_vector2[i] = ip_comp_destino[i];
	}
	this->ip_comp_origen = nvo_vector1;
	this->ip_comp_destino = nvo_vector2;
}

int Pagina::obtener_id(){
return this->id;
}

int Pagina::obtener_tamanio(){
return this->tamanio;
}

int * Pagina::obtener_ip_comp_origen(){
return this->ip_comp_origen;
}

int * Pagina::obtener_ip_comp_destino(){
return this->ip_comp_destino;
}



