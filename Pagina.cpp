#include "Pagina.h"

Pagina::Pagina(int id, int tamanio, vector<int> ip_comp_origen, vector<int> ip_comp_destino){
	this->id = id;
	this->tamanio = tamanio;
	this->ip_comp_origen = ip_comp_origen;
	this->ip_comp_destino = ip_comp_destino;
}

int Pagina::obtener_id(){
return this->id;
}

int Pagina::obtener_tamanio(){
return this->tamanio;
}

vector<int> Pagina::obtener_ip_comp_origen(){
return this->ip_comp_origen;
}

vector<int>  Pagina::obtener_ip_comp_destino(){
return this->ip_comp_destino;
}



