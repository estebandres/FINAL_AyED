#ifndef BIBLIOTECA_PAQUETES_H
#define BIBLIOTECA_PAQUETES_H
#include <iostream>

using namespace std;

class Biblioteca_paquetes
{
	private:
		Cola<Cola_etiquetada<Cola_etiquetada<Paquete>>> col_paq_clasif;
		Router* mi_router;
	public:		
		Biblioteca_paquetes(Router* router){
		this->col_paq_clasif=new Cola<Cola_etiquetada<Cola_etiquetada<Paquete>>>();
		this->mi_router=router;};
		~Biblioteca_paquetes();
		void agregar_paquete(Paquete);
		Paquete obtener_paquete();
};

#endif // Paquete_H

