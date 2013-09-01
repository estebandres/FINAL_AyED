#ifndef PAGINA_H
#define PAGINA_H
#include <iostream>

using namespace std;

class Pagina
{
	private:
		int id;//número de la página.
		int tamanio;//tamaño de la página en cantidad de paquetes
		vector<int> ip_comp_origen;
		vector<int> ip_comp_destino;
		
	public:		
		Pagina(int, int, vector<int>, vector<int>);
		~Pagina();
		int obtener_id();
		int obtener_tamanio();
		vector<int> obtener_ip_comp_origen();
		vector<int> obtener_ip_comp_destino();
};

#endif // Pagina_H

