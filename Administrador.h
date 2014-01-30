#ifndef ADMINISTRADOR_H
#define ADMINISTRADOR_H
//#include <iostream>
//#include <string>
#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include "Lista.h"
#include "Etiqueta.h"
#include "Paquete.h"
#include "Conexion.h"
#include "Pagina.h"
#include "Router.h"
#include "Computadora.h"

using namespace std;
/*
Esta clase se encarga de administrar la simulación. Puede ver y modificar absolutamente todos los parámetros
de la red Routers, computadoras, conexiones. Tiene la funcionalidad de calcular caminos óptimos con la 
implementación del algoritmo de Dijkstra para grafos direccionados y que admite ciclos no recurrentes.
Adicionalmente es capáz de leer la configuración de la red desde un archivo y dibujar el grafo
de la red haciendo uso de la librería graphvz mediante la aplicación Dot de los repositorios de ubuntu.
Cabe mensionar que se determinó que todos routers tienen la misma cantidad de maquinas conectadas.
*/
class Administrador
{
	private:
		Lista<Router> routers;
		Lista<Computadora*> computadoras;
		Lista<Arco> arcos;
		Lista<Conexion> conexiones;
		int cant_comp_por_router;
		int cant_routers;
		int total_pag;
		int cant_pasos;
		
	public:
		Administrador();
		~Administrador();
		void simular_cant_pasos(int);
		void simular_un_paso(bool);
		Lista<Etiqueta> Dijkstra(int);
		void calcular_tablas();
		void leer_archivo();
		//void crear_conexiones();
		int dibujar_grafo();
		void crear_pagina();
		void probar_conf();
};

#endif // Paquete_H

