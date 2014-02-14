#ifndef ETIQUETA_H
#define ETIQUETA_H
#include <iostream>
#include "Lista.h"

using namespace std;
/*
Esta clase implementa las triplas de tres enteros que utilizará la clase router para determinar hacia dónde debe enviar los paquetes.
*/
class Etiqueta
{
	private:
		int router_destino;		
		int router_despacho;		
		int peso_trayecto;
		//Lista<int> camino;
	public:		
		Etiqueta(int, int, int);
		~Etiqueta();
		int despacho();
		int destino();
		int peso_total();
		void mod_peso_trayecto(int);//modifica peso_trayecto
		void mod_despacho(int);
		void imprimir();
		//void agregar_nodo(int);
		//Lista<int> obtener_camino();
		//void corregir(int);

};

#endif // ETIQUETA_H
