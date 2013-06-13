#ifndef PAQUETE_H
#define PAQUETE_H
#include <iostream>

using namespace std;

class Paquete
{
	private:
		int* ip_comp_origen;
		int* ip_comp_destino;
		int id_pagina;
		int tamanio_pagina;
		int nro_orden;
		
	public:		
		Paquete(int*, int*, int, int, int);
		int get_ip_router_destino();
		int get_ip_maquina_destino();
		int get_id_pagina();
		int get_nro_orden();
};

#endif // Paquete_H

