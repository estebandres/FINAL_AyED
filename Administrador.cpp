#include "Administrador.h"
#include <fstream>
#include <sstream>

Administrador::Administrador(){
}

Administrador::~Administrador(){
}

void Administrador::simular_cant_pasos(int){
}

void Administrador::crear_paginas(){
//cada cierta cantidad de pasos de simulacion se generaran paginas aleatorioas de compuatadoras aleatorias.
}

void Administrador::simular_un_paso(){//recorrer la lista de router y ejecutar enviar y despues en otro ciclo recibir
}

void Administrador::Floid(){
}

void Administrador::leer_archivo(string nombre_archivo){
	std::ifstream archivo_conf = infile(nombre_archivo);
	string linea;
	while(getline(archivo_conf, linea)){
		switch(linea[0]){
		case('#'){
			linea.erase(line.begin());
			std::istringstream iss(line);
			int nro;
			if (!(iss >> nro)) { 
				cout<<"Error en la lectura de la cantidad de routers."<<endl;
				break; 
			} // error
			for(int i=0; i<nro; i++){
				Router router_i(i);
				routers.agregar(router_i);
			}
		}
		break;
		case('*'):
		{
			linea.erase(line.begin());
			std::istringstream iss(line);
			int nro;
			if (!(iss >> nro)) { 
				cout<<"Error en la lectura de la cantidad de computadoras por router."<<endl;
				break; 
			} // error
			for(int i=0; i<routers.tamanio(); i++){
				for(int j=0; j<nro; j++){
					int arreglo[]={i,j};
					vector<int> ip_comp_i_j(arreglo,arreglo+sizeof(arreglo)/sizeof(arreglo[0]));
					Router *ptr_router_i=&routers.elemento_pos(i);//puntero al router de la posicion i de la lista de routers de la red.
					Computadora computadora_i_j(ip_comp_i_j,ptr_router);
					Computadora *ptr_comp_i_j=&computadora_i_j;//puntero a la computadora recien creada
					computadoras.agregar(computadora_i_j);//se agrega la computadora a la lista de computadoras de la red.
					routers.elemento_pos(i).agregar_computadora(ptr_comp_i_j);//se agrega la computadora a la lista de punteros a computadoras del router al que pertenece.
				}
			}
		}	
		break;
		case('@'):
		{
			linea.erase(line.begin());
			std::istringstream iss(line);
			int router_i, router_j, ancho_banda;
			if (!(iss >> router_i >> routeer_j >> ancho_banda)) { 
				cout<<"Error en la lectura de la conexion de router."<<endl;
				break; 
			} // error
			Arco arco_k(ip_router_i,ip_router_j,ancho_banda);
			arcos.agregar(arco_k);
		}
		break;
		}
	}
}
void Administrador::crear_conexiones(){
	for(int i=0; i<arcos.tamanio(); i++){
		Conexion nva_conexion(arcos.elemento_pos(i).nodo_i(), arcos.elemento_pos(i).nodo_j(), arcos.elemento_pos(i).peso());
		bool existe=false;
		for(int m=0; m<conexiones.tamanio(); m++){
			if(nva_conexion.terminales()==conexiones.elemento_pos(m).terminales())
			existe=true;
		}
		if(!existe){
			conexiones.agregar(nva_conexion);
		}
	}
}