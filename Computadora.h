#ifndef COMPUTADORA_H
#define COMPUTADORA_H
#include "Lista.h"
#include "Pagina.h"
#include <vector>

/*
Esta clase representa las computadoras o terminales conectadas a los routers
en la red a simular. Incluye un puntero al router al que está conectada con el objetivo de
solicitarle el envío de una nueva página. Adicionalmente posee una lista de páginas recibidas
que podrá ser usada para medir la eficiencia de la red.
*/
class Computadora
{
	private:
		//Router* router;//Puntero al router donde está conectada la máquina.
		vector<int> ip;
		Lista<Pagina> paginas_recibidas; 
	public:		
		Computadora(vector<int>);
		//Computadora();
		~Computadora();
		//void enviar_pagina(Pagina);
		void recibir_pagina(Pagina);
		int cant_pag_recibidas();
		vector<int> obtener_ip();
		void imprimir();
};

#endif // COMPUTADORA_H

