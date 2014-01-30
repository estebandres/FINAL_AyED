#include "Router.h"

#define BOLD_RED     "\x1b[31;1m"
#define BOLD_BLUE    "\x1b[34;1m"
#define BOLD_GREEN   "\x1b[32;1m"
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_BRIGHT  "\x1b[1m"
#define ANSI_COLOR_RESET   "\x1b[0m"
using namespace std;

Router::Router(int ip_router):ip(ip_router),computadoras(),tabla_enrutamiento(),organizador_paquetes(ip_router),conexiones_envio(),conexiones_recepcion(){}

Router::~Router(){
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
	for(int i=0; i<conexiones_recepcion.tamanio(); i++){
		while(!conexiones_recepcion.elemento_pos(i)->conexion_libre()){//Mientras que la conexión en la posición i de la lsita de conexiones no esté libre...
			Paquete paq_leido=conexiones_recepcion.elemento_pos(i)->leer();//esta instruccion terminará por liberar la conexion y finalizar el while.
			bool pag_completa=this->organizador_paquetes.agregar_paquete(paq_leido);
			if(pag_completa){//si estan todos los paquetes de una página para este router
				Pagina pag_construida = this->construir_pagina(paq_leido);//en la realidad la computadora se encarga de generar la pagina
				this->enviar_pagina(pag_construida);
			}
		}
	}
}

Pagina Router::construir_pagina(Paquete paq_leido){
	Pagina pag(paq_leido.obtener_id_pagina(), paq_leido.obtener_tamanio_pagina(), paq_leido.obtener_ip_comp_origen(), paq_leido.obtener_ip_comp_destino());
	return pag;
}//Devuelve una página con la informaxión del paquete paq_leido.

void Router::enviar_pagina(Pagina pag_cons){
	for(int i=0; i<computadoras.tamanio();i++){//recorre la lista de punteros a computadoras y le envpia la página a la maquina apuntada que tiene el mismo ip que el destino de la página.
		if(computadoras.elemento_pos(i)->obtener_ip() == pag_cons.obtener_ip_comp_destino())
				computadoras.elemento_pos(i)->recibir_pagina(pag_cons);
	}
}

void Router::enviar_paquetes(){
	this->cargar_conexiones();
	
}
void Router::cargar_conexiones(){//envia el mensaje pero no espera una respuesta de recepcion exitosa UTP!
	bool conexiones_saturadas=false;
	while(organizador_paquetes.tamanio()!=0 && !conexiones_saturadas){//mientras hayan paquetes en el organizador y las conexiones no esten sat 
		Paquete paq_envio = this->organizador_paquetes.obtener_paquete();//aqui se puede vaciar el organizador_paquetes -->corta el while
		int router_despacho=buscar_en_tabla(paq_envio).despacho();
		conexiones_saturadas=true;//inicializa en verdadero asi permite hacer la operacion AND. 
		for(int i=0; i<conexiones_envio.tamanio(); i++){//este ciclo recorre todas las conexiones del router en busca de aquella que lo conecta con el router de despacho para tal paquete paw_envio.
			if(conexiones_envio.elemento_pos(i)->destino()==router_despacho)
				conexiones_envio.elemento_pos(i)->cargar(paq_envio);
			conexiones_saturadas=conexiones_saturadas && conexiones_envio.elemento_pos(i)->conexion_saturada();//Aqui corta el while si las conexiones estan saturadas.
		}	
	}
}

Etiqueta Router::buscar_en_tabla(Paquete paq){
	for(int i=0;i<tabla_enrutamiento.tamanio();i++){
		if(tabla_enrutamiento.elemento_pos(i).destino() == paq.obtener_ip_comp_destino()[0])
			return tabla_enrutamiento.elemento_pos(i);
	}
	assert(0 && "Router::buscar_en_tabla -> \"No se encontró la etiqueta para el destino del paquete.\"");
}

void Router::mostrar_paquetes(){
	cout<<BOLD_GREEN "-----------------------------------------------------------------------------" ANSI_COLOR_RESET<<endl;
	cout << BOLD_RED "R"<<this->ip<<":"<< BOLD_BLUE "TOTAL DE PAQUETES: "<<this->organizador_paquetes.tamanio()<<ANSI_COLOR_RESET<<endl;
	//cout<<"R"<<this->ip<<":"<<endl;
	this->organizador_paquetes.imprimir();
	cout<<BOLD_GREEN "-----------------------------------------------------------------------------" ANSI_COLOR_RESET<<endl;
}

void Router::agregar_conexion_envio(Conexion* con){
	this->conexiones_envio.agregar(con);
}

void Router::agregar_conexion_recepcion(Conexion* con){
	this->conexiones_recepcion.agregar(con);
}

int Router::obtener_ip(){
	this->computadoras.tamanio();
	return this->ip;
}

int Router::total_paquetes(){
	return this->organizador_paquetes.tamanio();
}

void Router::actualizar_tabla(Lista<Etiqueta> nva_tabla){
	this->tabla_enrutamiento=nva_tabla;
}

void Router::agregar_computadora(Computadora* esta){
	computadoras.tamanio();
}
void Router::imprimir(){
	cout<<"ROUTER: "<<this->ip<<endl;
	for(int i=0;i<computadoras.tamanio();i++){
		cout<<"COMPUTADORA: ("<<computadoras.elemento_pos(i)->obtener_ip()[0]<<"|"<<computadoras.elemento_pos(i)->obtener_ip()[1]<<")"<<endl;
	}
	for(int j=0;j<conexiones_recepcion.tamanio();j++){
		cout<<"CONEXIONES_RECEPCION: "<<endl;
		conexiones_recepcion.elemento_pos(j)->imprimir();
		cout<<endl;
	}
	for(int m=0;m<conexiones_recepcion.tamanio();m++){
		cout<<"CONEXIONES_ENVIO: "<<endl;
		conexiones_envio.elemento_pos(m)->imprimir();
		cout<<endl;
	}
}
