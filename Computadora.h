#ifndef COMPUTADORA_H
#define CCOMPUTADORA_H
#include <iostream>

using namespace std;

class Computadora
{
	private:
		Router* router;//Puntero al router donde está conectada la máquina.
		int* ip;
		Lista<Pagina> paginas_recibidas;
		int cant_pag_enviadas;
	public:		
		Computadora(Router*, int);
		~Computadora();
		void enviar_pagina();
		void recibir_pagina(Pagina);
};

#endif // COMPUTADORA_H

