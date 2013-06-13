#include "Computadora.h"

Computadora::Computadora(Router* router, int ip){
this->router = router;
this->ip = {this->router->obtener_ip(), id};//Asignación del vector IP donde el primer campo es el nro de IP de router.
this->paginas_recibidas = new Lista<Pagina>();
}

void Computadora::enviar_pagina(Pagina pagina_envio){
	/*	
	int tamanio = int(new Rand().getNext()*19)+1;
	Pagina pag=new Pagina(cant_pag_enviadas, tamanio, this->ip, );
	cant_pag_enviadas++;
	*/
	this->router->recibir_pagina(pagina_envio);
}

void Computadora::recibir_pagina(Pagina pagina_recibida);{
	this->paginas_recibidas.agregar(pagina_recibida);
}
