#include "Conexion.h"

Conexion::Conexion(int * ip_comp_origen, int * ip_comp_destino, int ancho_banda){
	this->ip_comp_origen=ip_comp_origen;
	this->ip_comp_destino=ip_comp_destino;
	this->ancho_banda=ancho_banda;
}

