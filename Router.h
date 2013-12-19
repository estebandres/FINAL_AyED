#ifndef ROUTER_H
#define ROUTER_H
#include <iostream>
#include "Lista.h"
#include "Biblioteca_paquetes.h"
#include "Etiqueta.h"
#include "Pagina.h"
#include "Conexion.h"
#include "Computadora.h"
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
		Lista<Conexion*> conexiones_envio;
		Lista<Conexion*> conexiones_recepcion;
		
	public:
		Router(int);
		~Router();		
		//Router(int, Lista<*Computadora>, Lista<Etiqueta>, Lista<Conexion>);
		void recibir_pagina(Pagina);
		void recibir_paquetes();
		void leer_conexiones();
		void enviar_paquetes();
		void cargar_conexiones();
		Etiqueta buscar_en_tabla(Paquete);
		void enviar_pagina(Pagina);
		Pagina construir_pagina(Paquete);
		void mostrar_paquetes();
		void agregar_conexion_envio(Conexion*);
		void agregar_conexion_recepcion(Conexion*);
};

#endif // Paquete_H
