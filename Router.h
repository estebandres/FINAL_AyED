#ifndef ROUTER_H
#define ROUTER_H
#include <iostream>
#include "Computadora.h"
#include "Lista.h"
#include "Biblioteca_paquetes.h"
#include "Etiqueta.h"
#include "Pagina.h"
#include "Conexion.h"
#include "Paquete.h"

using namespace std;

/*
Esta clase representa los nodos de la red y opera como enrutador, tiene las funcionalidades de enviar y recibir paquetes así como recibi páginas completas desde las computadoras que están conectadas a este router. La recepción del paquete se realiza mediante la lectura de sus conexiones de recepción y el envío mediante la carga de las conexiones de envío. Cada router tiene una identificación entera, una colección de computadoras, una lista de conexiones de envío y otra de recepción, además cuenta con una tabla de enrutamiento que contiene las etiquetas para cada destino.
*/
class Router
{
	private:
		int ip;
		Lista<Computadora> computadoras;
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
		int buscar_en_tabla(int);
		void enviar_pagina(Pagina);
		Pagina construir_pagina(Paquete);
		void mostrar_paquetes(int);
		void agregar_conexion_envio(Conexion*);
		void agregar_conexion_recepcion(Conexion*);
		int obtener_ip();
		int total_paquetes();
		void actualizar_tabla(Lista<Etiqueta>);
		void agregar_computadora(Computadora);
		void imprimir();
};

#endif // Paquete_H
