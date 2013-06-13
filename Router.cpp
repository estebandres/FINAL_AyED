#include "Router.h"

Router::Router(int ip, Lista<Router> routers_vecinos, Lista<Maquinas> maquinas, Lista<Etiquetas> tabla_enrutamiento){
this->ip = ip;
this->routers_vecinos = routers_vecinos;
this->maquinas = maquinas;
this->tabla_enrutamiento = tabla_enrutamiento;
this->cola_envio = new CDE();
this->paquetes_recibidos = new CDR();
}

void Router::recibir_pagina(Pagina pagina_recibida){
for(int i=0;i<pagina_recibida.get_tamanio();i++){
	cola_envio.agregar(new Paquete(&pagina_recibida,i));
}
}

void Router::recibir_paquete(Paquete paquete_recibido){
if(paquete_recibido.get_ip_maq_destino()[0]==this->ip)
	paquetes_recibidos.agregar(paquete_recibido);
else
	cola_envio.agregar(paquete_recibido);
}

void Router::enviar_paquetes(){
//se deben ocupar todo el ancho de banda de cada conexión par completar el envío.
	int conexiones_llenas[conexiones.get_tamanio()] = {0};
	bool conexiones_disponibles = true;
/*	while(conexiones_disponibles){
		bool todos_unos = true;
		for(int i=0;i<conexiones.get_tamanio();i++){
			if(conexiones_llenas[i]==0){
				todos_unos = false;
				if(cola_envio.get_primer_paquete().get_ip_maq_destino()[0] == conexiones.get_objeto_pos(i).get_ip_destino()){
					if(!conexiones.get_objeto_pos(i).llena())
						conexiones.get_objeto_pos(i).agregar_paquete(cola_envio.desencolar_paquete());
					else{//El ancho de banda esta lleno
						cola_envio.reencolar_router();
						conexiones.get_objeto_pos(i).enviar();
						conexiones_llenas[i] = 1;}
				}
			}
		}
		if(todos_unos)
			conexiones_disponibles = false;
	}*/
	while(conexiones_disponibles){
		bool todos_unos = true;
		for(int i=0;i<conexiones.get_tamanio();i++){
			if(conexiones_llenas[i]==0){//Esto hace que solo se recorran las conexiones cuyos anchos de banda no están completos. 
				todos_unos = false;
				if(tabla_enrutamiento.get_ip_destino_inmediato(cola_envio.get_primer_paquete().get_ip_maq_destino()[0]) == conexiones.get_objeto_pos(i).get_ip_destino()){
					if(!conexiones.get_objeto_pos(i).llena())
						conexiones.get_objeto_pos(i).agregar_paquete(cola_envio.desencolar_paquete());
					else{//El ancho de banda esta lleno
						cola_envio.reencolar_router();
						conexiones.get_objeto_pos(i).enviar();
						conexiones_llenas[i] = 1;}
				}	
			}
		}

		if(todos_unos)
			conexiones_disponibles = false;
	}
	
}
