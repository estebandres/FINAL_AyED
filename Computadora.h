#ifndef COMPUTADORA_H
#define COMPUTADORA_H
#include <iostream>
//#include "Router.h"
#include "Lista.h"
#include "Pagina.h"
#include <vector>

//class Router;

using namespace std;
/*
Esta clase representa las computadoras o terminales conectadas a los routers
en la red a simular. Incluye un puntero al router al que está conectada con el objetivo de
solicitarle el envío de una nueva página. Adicionalmente posee una lista de páginas recibidas
que podrá ser usada para medir la eficiencia de la red.
*/
class Computadora
{
	private:
		Router* router;//Puntero al router donde está conectada la máquina.
		vector<int> ip;
		Lista<Pagina> paginas_recibidas;
	public:		
		Computadora(Router*, int);
		//Computadora();
		~Computadora();
		void enviar_pagina(Pagina);
		void recibir_pagina(Pagina);
		int cant_pag_recibidas();
		vector<int> obtener_ip();
};

#endif // COMPUTADORA_H

