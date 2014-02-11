#ifndef BIBLIOTECA_PAQUETES_H
#define BIBLIOTECA_PAQUETES_H
#include <iostream>
#include "Cola.h"
#include "Paquete.h"
using namespace std;
/*
Esta clase es la estructura de datos que garantiza justicia en el envío de paquetes, esto es,
igual atención a las solicitudes de todos los routers y para todas las páginas.
En su interiror se implementa una colección de tipo anidada de tres niveles que se usa para organizar los
paquetes. Esta colección es del tipo cola y utiliza el campo especial duenio para identificar a qué router
y página pertenecen los paquetes encolados.
*/

class Biblioteca_paquetes
{
	private:
		Cola<Cola<Cola<Paquete> > > clasificador;
		int mi_router;
	public:
		Biblioteca_paquetes(int);
		~Biblioteca_paquetes();
		int agregar_paquete(Paquete);
		Paquete obtener_paquete();
		void imprimir(int);
		int tamanio();
		int destino_proa();
		int hay_envios();
		void reencolar_destino();
		int cant_destinos();
};

#endif // Paquete_H

