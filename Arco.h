#ifndef ARCO_H
#define ARCO_H
#include <iostream>

using namespace std;

class Arco
{
	private:
		int oringen;		
		int destino;		
		int peso;
	public:		
		Arco(int , int, int);
		~Arco();
		int origen();
		int destino();
		int peso();
		void mod_peso(int);
};

#endif // ARCO_H
