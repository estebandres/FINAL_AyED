#ifndef ROUTER_H
#define ROUTER_H
#include <iostream>

using namespace std;

class Router
{
	private:
		int ip;
		Lista<Computadora*> computadoras;
		Lista<Etiqueta> tabla_enrutamiento;
		Biblioteca_paquetes organizador_paquetes;
		Lista<Conexion> conexiones;
		
	public:
		Router(int);		
		//Router(int, Lista<*Computadora>, Lista<Etiqueta>, Lista<Conexion>);
		void recibir_pagina(Pagina pagina_recibida){
		void recibir_paquetes()
		void leer_conexiones()
		void enviar_paquetes()
		void cargar_conexiones()
		Etiqueta buscar_etiqueta(Paquete)
};

#endif // Paquete_H

