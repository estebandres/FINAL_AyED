#include "Router.h"

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
	//cout<<"Router::recibir_paquetes()"<<endl;
	this->leer_conexiones();
}

void Router::leer_conexiones(){
	//cout<<"Router::leer_conexiones()"<<endl;
	//cout<<"Soy el Router "<<this->ip<<" y tengo "<<conexiones_recepcion.tamanio()<<"conexiones de recepcion"<<endl;
	//cout<<"***"<<conexiones_recepcion.tamanio()<<"***"<<endl;
	for(int i=0; i<conexiones_recepcion.tamanio(); i++){
		//cout<<"Hola1"<<endl;
		//cout<<"conexion nro:"<<i<<" libre?: "<<conexiones_recepcion.elemento_pos(i)->conexion_libre()<<endl;
		while(!conexiones_recepcion.elemento_pos(i)->conexion_libre()){//Mientras que la conexión en la posición i de la lsita de conexiones no esté libre...
			Paquete paq_leido=conexiones_recepcion.elemento_pos(i)->leer();//esta instruccion terminará por liberar la conexion y finalizar el while.
			//cout<<"Hola2"<<endl;
			bool pag_completa=this->organizador_paquetes.agregar_paquete(paq_leido);
			//cout<<"Hola3"<<endl;
			if(pag_completa){//si estan todos los paquetes de una página para este router
				Pagina pag_construida = this->construir_pagina(paq_leido);//en la realidad la computadora se encarga de generar la pagina
				//cout<<"PAGINA CONTRUIDA ID: "<<pag_construida.obtener_id()<<endl;
				this->enviar_pagina(pag_construida);
			}
			//cout<<"Hola4"<<endl;
		}
	}
}

Pagina Router::construir_pagina(Paquete paq_leido){
	Pagina pag(paq_leido.obtener_id_pagina(), paq_leido.obtener_tamanio_pagina(), paq_leido.obtener_ip_comp_origen(), paq_leido.obtener_ip_comp_destino());
	cout<<"PÁGUINA ID: "<<paq_leido.obtener_id_pagina()<<" CONSTRUIDA EN R"<<this->ip<<endl;
	return pag;
}//Devuelve una página con la informaxión del paquete paq_leido.

void Router::enviar_pagina(Pagina pag_cons){
	for(int i=0; i<computadoras.tamanio();i++){//recorre la lista de punteros a computadoras y le envpia la página a la maquina apuntada que tiene el mismo ip que el destino de la página.
		if(computadoras.elemento_pos(i).obtener_ip() == pag_cons.obtener_ip_comp_destino())
				computadoras.elemento_pos(i).recibir_pagina(pag_cons);
	}
}

void Router::enviar_paquetes(){
	this->cargar_conexiones();
	
}

void Router::cargar_conexiones(){
	Lista<int> conexiones_saturadas;
	bool carga_imposible=false;
	int cant_rotaciones=0;
	int despacho_req=-1;
	while(organizador_paquetes.cant_destinos()>0 && conexiones_saturadas.tamanio()<conexiones_envio.tamanio() && !carga_imposible){//mientras hayan paquetes en el organizador para envío y las conexiones no esten saturadas 
		despacho_req=this->buscar_en_tabla(this->organizador_paquetes.destino_proa());
		//cout<<"ENVIO DESDE R"<<this->ip<<" DESTINO PROA: "<<organizador_paquetes.destino_proa()<<" DESPACHO:"<<despacho_req<<endl;
		//this->tabla_enrutamiento.imprimir();
		//cout<<"CONEXIONES SATURADAS: "<<endl;
		//conexiones_saturadas.mostrar();
		
		if(conexiones_saturadas.contiene(despacho_req) || this->organizador_paquetes.destino_proa()==this->ip){
			this->organizador_paquetes.reencolar_destino();
			cant_rotaciones++;
		}
		else{
			for(int i=0; i<conexiones_envio.tamanio(); i++){//este ciclo recorre todas las conexiones del router en busca de aquella que lo conecta con el router de despacho para el paquete en la proa del organizador.
			//cout<<"Conexión (destino): "<<conexiones_envio.elemento_pos(i)->destino()<< "--SAT?-- "<<conexiones_envio.elemento_pos(i)->conexion_saturada()<<endl;
				if(conexiones_envio.elemento_pos(i)->destino() == despacho_req){
					//cout<<"Chau4"<<endl;
					conexiones_envio.elemento_pos(i)->cargar(organizador_paquetes.obtener_paquete());
					cant_rotaciones=0;
					if(conexiones_envio.elemento_pos(i)->conexion_saturada()){
						conexiones_saturadas.agregar(conexiones_envio.elemento_pos(i)->destino());
					}
				}
			}
		}
		if(cant_rotaciones==organizador_paquetes.cant_destinos())
			carga_imposible=true;
		if(this->organizador_paquetes.tamanio()==1 && this->organizador_paquetes.destino_proa() == this->ip)
			carga_imposible=true;
	}
}

int Router::buscar_en_tabla(int destino){
	//cout<<"Tamanio de tabla: "<<tabla_enrutamiento.tamanio()<<endl;
	//tabla_enrutamiento.imprimir();
	for(int i=0;i<tabla_enrutamiento.tamanio();i++){
		if(tabla_enrutamiento.elemento_pos(i).destino() == destino)
			return tabla_enrutamiento.elemento_pos(i).despacho();
	}
	assert(0 && "Router::buscar_en_tabla -> \"No se encontró la etiqueta para el destino del paquete.\"");
}

void Router::mostrar_paquetes(int id_pag){
	cout<<endl<<BOLD_GREEN "-----------------------------------------------------------------------------" ANSI_COLOR_RESET<<endl;
	cout << BOLD_RED "R"<<this->ip<<":"<< BOLD_BLUE "TOTAL DE PAQUETES: "<<this->organizador_paquetes.tamanio()<<ANSI_COLOR_RESET<<endl;
	//cout<<"R"<<this->ip<<":"<<endl;
	cout<<BOLD_GREEN "-----------------------------------------------------------------------------" ANSI_COLOR_RESET<<endl;
	this->organizador_paquetes.imprimir(id_pag);
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
	//Lista<Etiqueta> tabla = nva_tabla;
	//cout<<"000000000000000000000000000000000000000000"<<endl;
	//nva_tabla.imprimir();
	this->tabla_enrutamiento.copiar_contenido(nva_tabla);
	//tabla_enrutamiento.imprimir();
	//cout<<"111111111111111111111111111111111111111111"<<endl;
}

void Router::agregar_computadora(Computadora esta){
	computadoras.agregar(esta);
}
void Router::imprimir(){
	cout<<"ROUTER: "<<this->ip<<endl;
	for(int i=0;i<computadoras.tamanio();i++){
		cout<<"COMPUTADORA: ("<<computadoras.elemento_pos(i).obtener_ip()[0]<<"|"<<computadoras.elemento_pos(i).obtener_ip()[1]<<")"<<endl;
	}
	for(int j=0;j<conexiones_recepcion.tamanio();j++){
		cout<<"CONEXIONES_RECEPCION: "<<endl;
		conexiones_recepcion.elemento_pos(j)->imprimir();
		cout<<endl<<conexiones_recepcion.elemento_pos(j);
		cout<<endl;
	}
	for(int m=0;m<conexiones_recepcion.tamanio();m++){
		cout<<"CONEXIONES_ENVIO: "<<endl;
		conexiones_envio.elemento_pos(m)->imprimir();
		cout<<endl<<conexiones_envio.elemento_pos(m);
		cout<<endl;
	}
}
