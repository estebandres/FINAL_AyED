#include "Computadora.h"
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

Computadora::Computadora(Router* router, int id){
this->router = router;
int ip_maq[2] = {this->router->obtener_ip(), id};//Asignación del vector IP donde el primer campo es el nro de IP de router y el segundo es la identificación de la máquina.
this->ip(ip_maq,ip_maq+sizeof(ip_maq)/sizeof(ip_maq[0]));
}
Computadora::~Computadora(){
}

void Computadora::enviar_pagina(Pagina pagina_envio){
	this->router->recibir_pagina(pagina_envio);
}

void Computadora::recibir_pagina(Pagina pagina_recibida);{
	this->paginas_recibidas.agregar(pagina_recibida);
}
int Computadora::cant_pag_recibidas(){
	return this->paginas_recibidas.tamanio();
}
