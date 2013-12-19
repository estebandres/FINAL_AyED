#include "Computadora.h"
using namespace std;
Computadora::Computadora(vector<int> ip) : ip(ip),paginas_recibidas(){}
/*Computadora::Computadora():ip(),paginas_recibidas(){
}*/
Computadora::~Computadora(){
}

/*void Computadora::enviar_pagina(Pagina pagina_envio){
	this->router->recibir_pagina(pagina_envio);
}*/

void Computadora::recibir_pagina(Pagina pagina_recibida){
	this->paginas_recibidas.agregar(pagina_recibida);
}
int Computadora::cant_pag_recibidas(){
	return this->paginas_recibidas.tamanio();
}
vector<int> Computadora::obtener_ip(){
	return this->ip;
}



