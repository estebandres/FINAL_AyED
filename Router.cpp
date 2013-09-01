#include "Router.h"

Router::Router(int ip, Lista<*Router> routers_vecinos, Lista<Maquinas> maquinas, Lista<Etiquetas> tabla_enrutamiento){
this->ip = ip;
this->routers_vecinos = routers_vecinos;
this->maquinas = maquinas;
this->tabla_enrutamiento = tabla_enrutamiento;
this->cola_envio = new CDE();
this->paquetes_recibidos = new CDR();
}

void Router::recibir_pagina(Pagina pagina_recibida){
	for(int i=0;i<pagina_recibida.obtener_tamanio();i++){
	this->organizador_paquetes.agregar_paquete(Paquete(pagina_recibida.obtener_ip_comp_origen(), pagina_recibida.obtener_ip_comp_destino(), pagina_recibida.obtener_id(), pagina_recibida.obtener_tamanio(),i));
	}
}

void Router::recibir_paquetes(){
	this->leer_conexiones();
	
}

void Router::leer_conexiones(){
	for(int i=0; i<conexiones.tamanio(); i++){
		while(!conexiones.elemento_pos(i).conexion_libre()){
			Paquete paq_leido=conexiones.elemento_pos(i).leer();//esta instruccion terminará por liberar la conexion y finalizar el while.
			bool pag_completa=this->organizador_paquetes.agregar_paquete(paq_leido);
			if(pagina_completa){//si estan todos los paquetes de una página para este router
				Pagina pag_construida = this->construir_pagina(paq_leido);//en la realidad la computadora se encarga de generar la pagina
				this->enviar_pagina(pag_construida);
		}
	}
}

void Router::enviar_paquetes(){
	this->cargar_conexiones();
	
}
void Router::cargar_conexiones(){//envia el mensaje pero no espera una respuesta de recepcion exitosa UTP!
	bool conexiones_saturadas=false;
	while(organizador_paquetes.tamanio()!=0 && !conexiones_saturadas){//mientras hayan paquetes en el organizador y las conexiones no esten sat 
		Paquete paq_envio = this->organizador_paquetes.obtener_paquete();//aqui se puede vaciar el organizador_paquetes -->corta el while
		int proximo_router=buscar_etiqueta(paq_envio).camino().primer_elemento();
		conexiones_saturadas=true;//inicializa en verdadero asi permite hacer la operacion AND. 
		for(int i=0; i<conexiones.tamanio(); i++){
			int bornes[]={this->ip,proximo_router};
			set<int> estos_terminales(bornes,bornes+2);
			if(conexiones.elemento_pos(i).obtener_terminales()==estos_terminales)
				conexion.cargar(paq_envio);
			conexiones_saturadas=conexiones_saturadas && conexiones.elemento_pos(i).conexion_saturada();//Aqui corta el while si las conexiones estan saturadas.
		}	
	}
}

Etiqueta Router::buscar_etiqueta(Paquete){

}

