#ifndef ETIQUETA_H
#define ETIQUETA_H
#include <iostream>

using namespace std;

class Etiqueta
{
	private:
		int router_destino;		
		int router_consecutivo;		
		int peso_trayecto;
	public:		
		Etiqueta(int , int, int);
		~Etiqueta();
		int router_consecutivo();
		int router_destino();
		void mod_peso_trayecto(int nvo_peso);

};

#endif // ETIQUETA_H
