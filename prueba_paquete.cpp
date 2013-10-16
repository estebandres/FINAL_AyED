
#include <iostream>
#include <vector>
#include "Paquete.h"
#include <stdlib.h>
#include "Paquete.cpp"
#include "Cola.h"
#include "Lista.h"


using namespace std;

int main(int argc, char **argv)
{
	//Test - Etapa 1 - Creacionhy utilizacion de los metodos
	
	cout<<"TESTEO METODOS DE PAQUETE -------------------------------------"<<endl;
	int arreglo[2]={1,10}; //ORIGEN Router 1 - Pc 10
	std::vector<int> ip_og(arreglo,arreglo+sizeof(arreglo)/sizeof(arreglo[0]));
	int arreglo2[2]={2,20}; //DESTINO Router 2 - Pc 20
	std::vector<int> ip_dt(arreglo2,arreglo2+sizeof(arreglo2)/sizeof(arreglo2[0]));
	//Los paquetes 1,2 y 3pertenecen a la pagina 10, de tamaño 3 
	Paquete Pq_1(ip_og, ip_dt, 10, 3, 1);
	Paquete Pq_2(ip_og, ip_dt, 10, 3, 2);
	Paquete Pq_3(ip_og, ip_dt, 10, 3, 3);
	//los paquetes 3,4 y 5 pertenecen a la pagina 12, de tamaño 25
	Paquete Pq_4(ip_og, ip_dt, 12, 25, 2);
	Paquete Pq_5(ip_og, ip_dt, 12, 25, 16);
	Paquete Pq_6(ip_og, ip_dt, 12, 25, 25);
	
		cout<<"Datos del Paquete "<<Pq_1.obtener_nro_orden()<<" de la pagina "<<Pq_1.obtener_id_pagina()<<" de tamaño "<<Pq_1.obtener_tamanio_pagina()<<"-------------------------"<<endl;
		cout<<"Los paquetes viajaran de la Pc "<< Pq_1.obtener_ip_comp_origen()[1]<<", del Router "<<Pq_1.obtener_ip_comp_origen()[0]<<". A la Pc "<<Pq_1.obtener_ip_comp_destino()[1]<<" del Router "<<Pq_1.obtener_ip_comp_destino()[0]<<endl;
		cout<<"Ahora, cambiamos su òrden (1ero) con el (3ero), entre sì, mostrando siempre primero el orden del Paquete 1 "<<endl;
		cout<<"Antes: "<<endl;
		Pq_1.imprimir();
		Pq_3.imprimir();
		Pq_3.cambiar_orden(1);
		Pq_1.cambiar_orden(3);
		cout<<"Despues, sus òrdenes son: "<<endl;
		Pq_1.imprimir();
		Pq_3.imprimir();
	
/*		//Test - Etapa 2.0 - Cargar en Lista
		
		cout<<"TESTEO METODOS DE LISTA, CON PAQUETES---------------------------------"<<endl;
		Lista<Paquete> ListaA;
		cout<<endl;
   	    cout<<"ListaA.tamanio(): "<<ListaA.tamanio()<<endl;
   	    ListaA.imprimir();
   	    ListaA.insertar_al_final(Pq_1);
    	ListaA.imprimir();
	*/	 
	
	
	//Test - Etapa 2.1 - Cargar en cola
	cout<<endl;
	cout<<"TESTEO METODOS DE COLA, CON PAQUETES---------------------------------"<<endl;
	
	//creacion de una cola, con elementos tipo Paquete
	cout<<"Creacion de una cola, con elementos tipo Paquete"<<endl;
	Cola<Paquete> colaA; 
	Cola<Paquete> colaB; 
	
	//fijar tamaño a las colas
	cout<<"fijar tamaño a las colas: 3 y 25"<<endl;
	colaA.fijar_tamanio_max(3);
	colaB.fijar_tamanio_max(25);
	cout<<"colaA.obtener_tamanio_max(): "<<colaA.obtener_tamanio_max()<<endl;
	cout<<"colaA.tamanio() ((deim el anterior)) : "<<colaA.tamanio()<<endl;
    cout<<"colaA.cola_llena() ((false)) : "<<colaA.cola_llena()<<endl;
    
    cout<<"Preguntas Iniciales"<<endl;
	cout<<"ColaA llena? "<<colaA.cola_llena()<<endl;
	cout<<"ColaA tamanio? (idem) "<<colaA.tamanio()<<endl;
	cout<<"ColaA obtener_tamanio_max? "<<colaA.obtener_tamanio_max()<<endl;
	
	cout<<"ColaB llena? "<<colaB.cola_llena()<<endl;
	cout<<"ColaB tamanio? (idem) "<<colaB.tamanio()<<endl;
	cout<<"ColaB obtener_tamanio_max? "<<colaB.obtener_tamanio_max()<<endl;
	
    //Colocacion de Paquetes en ambas colas (la cola coloca a medida que llegan los paquetes, no depende del orden)
	cout<<"Colocacion de 6 Paquetes"<<endl;
	
	colaA.encolar(Pq_1);
	colaA.encolar(Pq_2);
	colaA.encolar(Pq_3);
	
	colaB.encolar(Pq_4);
	colaB.encolar(Pq_5);
	colaB.encolar(Pq_6);
		
	cout<<"Preguntamos si estan llenas. Deberia estar llena la Primer Cola solamente"<<endl;
	cout<<"ColaA llena? "<<colaA.cola_llena()<<endl;
	cout<<"ColaA tamanio? (idem) "<<colaA.tamanio()<<endl;
	cout<<"ColaA obtener_tamanio_max? "<<colaA.obtener_tamanio_max()<<endl;
	
	cout<<"ColaB llena? "<<colaB.cola_llena()<<endl;
	cout<<"ColaB tamanio? (idem) "<<colaB.tamanio()<<endl;
	cout<<"ColaB obtener_tamanio_max? "<<colaB.obtener_tamanio_max()<<endl;
	
	cout<<"Vistos los elementos de la cola $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl;
	colaA.imprimir();
	colaB.imprimir();
	cout<<" REencolamos un elemento de cada cola, y mostramos el resultado================"<<endl;
    colaA.reencolar();
    colaB.reencolar();
    colaA.imprimir();
	colaB.imprimir();
    cout<<"Ahora, eliminamos los dos primeros elementos de cada una de las colas, y mostramos ////////"<<endl;
	colaA.desencolar();
    colaB.desencolar();
    colaA.imprimir();
	colaB.imprimir();
    
    
	return 0;
}

