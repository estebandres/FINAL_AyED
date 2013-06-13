#include "Paquete.h"
		
Paquete::Paquete(int* ip_comp_origen, int* ip_comp_destino, int id_pagina, int tamanio_pagina, int nro_orden){
	this->ip_comp_origen=ip_comp_origen;
	this->ip_comp_destino=ip_comp_destino;
	this->id_pagina=id_pagina;
	this->tamanio_pagina=tamanio_pagina;
	this->nro_orden=nro_orden;
}

int * Paquete::obtener_ip_comp_origen(){
	return this->ip_comp_origen;
}

int * Paquete::obtener_ip_comp_destino(){
	return this->ip_comp_destino;
}

int Paquete::obtener_id_pagina();{
	return this->id_pagina;
}

int Paquete::obtener_nro_orden(){
	return this->nro_orden;
}

int Paquete::obtener_tamanio_pagina(){
	return this->tamanio_pagina;
}
