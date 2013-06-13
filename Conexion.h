#ifndef CONEXION_H
#define CCONEXION_H
#include <iostream>

using namespace std;

class Conexion
{
	private:
		Router* router;//Puntero al router donde está conectada la máquina.
		int* ip;
		Lista<Pagina> paginas_recibidas;
		int cant_pag_enviadas;
	public:		
		Conexion(int * ip_comp_origen, int * ip_comp_destino, int ancho_banda);
		~Conexion();
};

#endif // CONEXION_H
