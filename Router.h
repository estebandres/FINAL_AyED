#ifndef ROUTER_H
#define ROUTER_H
#include <iostream>

using namespace std;
/*
Esta clase representa los nodos de la red y opera como enrutador, tiene las funcionalidades de
enviar y recibir paquetes así como recibi páginas completas desde las computadoras que están conectadas a este router.
*/
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
		~Router();		
		//Router(int, Lista<*Computadora>, Lista<Etiqueta>, Lista<Conexion>);
		void recibir_pagina(Pagina pagina_recibida);
		void recibir_paquetes();
		void leer_conexiones();
		void enviar_paquetes();
		void cargar_conexiones();
		Etiqueta buscar_en_tabla(Paquete);
		void mostrar_paquetes();
};

#endif // Paquete_H

