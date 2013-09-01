#ifndef CONEXION_H
#define CONEXION_H
#include <iostream>
#include <std::set>
using namespace std;

class Conexion
{
	private:
		set<int> terminales;
		int ancho_banda;
		Cola<Paquete> canal;
	public:		
		Conexion();
		//~Conexion();
		set<int> obtener_terminales();
		void cargar(Paquete);
		Paquete leer();
		int obtener_ancho_banda();
		bool conexion_saturada();
		bool conexion_libre();
};

Conexion::Conexion(){
}

Conexion::Conexion(int terminal_i, int terminal_j, int ancho){
	int bornes[]={terminal_i,terminal_j};
	this->routers=set<int>(bornes,bornes+2);
	this->ancho_banda=ancho;
	this->canal.fijar_tamanio_max(this->ancho_banda);
}

set<int> Conexion::obtener_terminales(){
	return this->terminales;
}

void Conexion::cargar(Paquete){
	//assert(canal.cola_llena() && "Se intenta cargar una conexion que está saturada.");
	this->canal.encolar(Paquete);
}

Paquete Conexion::leer(){
	Paquete paq_leido = this->canal.primer_elemento();
	this-> canal.desencolar();
	return paq_leido;
	
}

bool Conexion::conexion_saturada(){
	return canal.cola_llena();
}

int Conexion::obtener_ancho_banda(){
	return this->ancho_banda;
}

bool Conexion::conexion_libre(){
	return this->canal.es_vacia();
}

#endif // CONEXION_H
