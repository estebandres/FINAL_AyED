#ifndef CONEXION_H
#define CONEXION_H
#include <iostream>
#include "Arco.h"
#include "Cola.h"
#include "Paquete.h"

using namespace std;
/*
Esta clase representa la vía que comunica dos routers en la red y hace referencia al arco del grafo de la red a simular. Consta de dos nros de ip, el origen y destino así como la especificación del ancho de banda y una cola para emular las limitaciones del canal. 
*/
class Conexion : public Arco
{
	private:
		Cola<Paquete> canal;
	public:		
		Conexion(int, int, int);
		~Conexion();
		//set<int> obtener_terminales();
		void cargar(Paquete);
		Paquete leer();
		int obtener_ancho_banda();
		bool conexion_saturada();
		bool conexion_libre();
};

#endif // CONEXION_H
