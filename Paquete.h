#ifndef PAQUETE_H
#define PAQUETE_H
#include <vector>
#define BOLD_RED     "\x1b[31;1m"
#define BOLD_BLUE    "\x1b[34;1m"
#define BOLD_GREEN   "\x1b[32;1m"
#define BOLD_CYAN    "\x1b[36;1m"
#define BOLD_YELLOW  "\x1b[33;1m"
#define BOLD_MAGENTA "\x1b[35;1m"
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_BRIGHT  "\x1b[1m"
#define ANSI_COLOR_RESET   "\x1b[0m"
using std::vector;
//using namespace std;
/*
Esta clase representa las que componen una página y que contiene un número de órden, el tamanio de la página a la que pertenece y las direcciones de origen y de destino en forma de duplas de enteros.
*/

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
		Paquete(vector<int>, vector<int>, int, int, int);
		~Paquete();
		vector<int> obtener_ip_comp_origen();
		vector<int> obtener_ip_comp_destino();
		int obtener_id_pagina();
		int obtener_nro_orden();
		int obtener_tamanio_pagina();
		void imprimir(int);
		void cambiar_orden(int);
		
};

#endif // Paquete_H

