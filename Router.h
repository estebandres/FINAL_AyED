#ifndef ROUTER_H
#define ROUTER_H
#include <iostream>

using namespace std;

class Router
{
	private:
		int ip;
		Lista<*Router> routers_vecinos;
		Lista<*Computadora> Computadoras;
		Lista<Etiquetas> tabla_enrutamiento;
		Biblioteca_paquetes organizador_paquetes;
		Lista<Cola> colas_envio;
		Lista<int> id_paginas_recibidas;
		Lista_etiquetada<Lista_etiquetada<Paquetes>>;
		
	public:		
		Router(int, Lista<*Router>, Lista<Computadora>, Lista<Etiquetas>){
			this-> ip;
			this-> router_vecinos;
			this-> organizador_paquetes = new Biblioteca_paquetes(this);
		};
		void recibir_pagina(Pagina);
		void recibir_paquete(Paquete);//agrega el paquete al organizador_paquetes 
		void encolar_paquetes();//carga las colas_envio con los paquetes que va sacando del organizador_paquetes
//una vez que estan llenas o no tengo mas paquetes en el organizador_paquetes termina el método.
		void enviar_paquete();//vacia las colas de envío.Este se ejecuta primero en un ciclo de simulacion.
		void enviar_pagina(Pagina);//Recibe una página del organizador de paquetes y se la envía a la computadora destino.
		void cargar_router_vecino(*Router vecino, int ancho_banda){
		routers_vecinos.agregar(*Router vecino);
		colas_envio.agregar(new Cola<Paquete>(ancho_banda));
		};
};

#endif // Paquete_H

