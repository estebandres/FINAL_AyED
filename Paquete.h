#ifndef PAQUETE_H
#define PAQUETE_H
#include <vector>

using namespace std;
//definir el ancho del paquete

class Paquete
{
	private:
		vector<int> ip_comp_origen;
		vector<int> ip_comp_destino;
		int id_pagina;
		int tamanio_pagina;
		int nro_orden; //orden del paquete = tamanio/ancho_paquete
		
	public:		
		Paquete();
		Paquete(vector<int> ip_comp_origen, vector<int> ip_comp_destino, int id_pagina, int tamanio_pagina, int nro_orden);
		~Paquete();
		vector<int> obtener_ip_comp_origen();
		vector<int> obtener_ip_comp_destino();
		int obtener_id_pagina();
		int obtener_nro_orden();
		int obtener_tamanio_pagina();
		void imprimir();
		void cambiar_orden(int);
		
};


#endif // Paquete_H

