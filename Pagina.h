#ifndef PAGINA_H
#define PAGINA_H
#include <iostream>

using namespace std;

class Pagina
{
	private:
		int id;//número de la página.
		int tamanio;//tamaño de la página en cantidad de paquetes
		int* ip_comp_origen;
		int* ip_comp_destino;
		
	public:		
		Pagina(int, int, int*, int*);
		~Pagina();
		int obtener_id();
		int obtener_tamanio();
		int obtener_ip_comp_origen();
		int obtener_ip_comp_destino();
};

#endif // Pagina_H

