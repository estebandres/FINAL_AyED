#ifndef ETIQUETA_H
#define ETIQUETA_H
#include <iostream>

using namespace std;

class Etiqueta
{
	private:
		int ip_router_destino;		
		int ip_router_siguiente;		
		int peso_total;
	public:		
		Etiqueta(int , int, int);
		~Etiqueta();
};

#endif // ETIQUETA_H
