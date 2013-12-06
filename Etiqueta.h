#ifndef ETIQUETA_H
#define ETIQUETA_H
#include <iostream>

using namespace std;
/*
Esta clase implementa las cumplas de tres enteros que utilizará la clase router para
determinar hacia dónde debe enviar los paquetes.
*/
class Etiqueta
{
	private:
		int router_destino;		
		int router_despacho;		
		int peso_trayecto;
	public:		
		Etiqueta(int , int, int);
		~Etiqueta();
		int router_despacho();
		int router_destino();
		void mod_peso_trayecto(int);//modifica peso_trayecto
		void mod_despacho(int);

};

#endif // ETIQUETA_H
