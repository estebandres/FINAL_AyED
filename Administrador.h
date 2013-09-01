#ifndef ADMINISTRADOR_H
#define ADMINISTRADOR_H
#include <iostream>
#include <string>

using namespace std;

class Administrador
{
	private:
		Lista<Router> routers;
		Lista<Computadora*> computadoras;
		Lista<Arco> arcos; 
		Lista<Conexion> conexiones;
		
	public:
		Administrador();
		void simular_cant_paso(int);
		void simular_un_paso();
		void Floid();
		void leer_archivo(string);
		crear_conexiones()
};

#endif // Paquete_H

