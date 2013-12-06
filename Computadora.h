#ifndef COMPUTADORA_H
#define CCOMPUTADORA_H
#include <iostream>

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
		~Computadora();
		void enviar_pagina(Pagina);
		void recibir_pagina(Pagina);
		int cant_pag_recibidas();
};

#endif // COMPUTADORA_H

