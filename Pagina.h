#ifndef PAGINA_H
#define PAGINA_H
//#include <vector>
#include <iostream>


using namespace std;

class Pagina
{
	private:
		int id;//número de la página.
		int tamanio;//tamaño de la página en cantidad de paquetes
		std::vector<int> ip_comp_origen;//ip pc y router origen
		std::vector<int> ip_comp_destino;//ip pc y router destino
		
	public:		
		Pagina(int, int, std::vector<int>, std::vector<int>);
		~Pagina();
		int obtener_id();
		int obtener_tamanio();
		std::vector<int> obtener_ip_comp_origen();
		std::vector<int> obtener_ip_comp_destino();
		void imprimir(void);
};

#endif // Pagina_H

