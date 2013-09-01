#ifndef COMPUTADORA_H
#define CCOMPUTADORA_H
#include <iostream>

using namespace std;

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
		void cant_pag_recibidas();
};

#endif // COMPUTADORA_H

