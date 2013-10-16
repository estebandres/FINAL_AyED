/*!Begin Snippet:filebegin*/
#ifndef _Cola_H_
#define _Cola_H_

#include "Lista.h"

using namespace std;

//Cola de Listas

/*!Begin Snippet:fullNodo*/
/*!Begin Snippet:private*/
template <typename T>
class Cola : public Lista<T> {
private:
	int duenio; // ip_equipo asociado
	int tamanio_max; // 
public:
	Cola();
	Cola(int);
	Cola(int, int);
	~Cola();
	void encolar(T);
	void desencolar();
	int obtener_duenio();
	void reencolar();
	int obtener_tamanio_max();
	void fijar_tamanio_max(int);
	bool cola_llena();
	void imprimir();

};


template <typename T>
Cola<T>::Cola(){
	//Lista();
	this->duenio=-1;
	this->tamanio_max=-1;
}

template <typename T>
Cola<T>::Cola(int duenio){
	//Lista();
	this->duenio=duenio;
	this->tamanio_max=-1;
}

template <typename T>
Cola<T>::Cola(int duenio, int tamanio_max){
	//Lista();
	this->duenio=duenio;
	this->tamanio_max=tamanio_max;
}

template <typename T>
Cola<T>::~Cola(){}

template <typename T>
void Cola<T>::encolar(T elemento){
	
		assert(!this->cola_llena() && "Se intenta agregar elementos a una cola llena"); // si la cola esta llena, mando el mensaje
		this->insertar_al_final(elemento);
	
}

template <typename T>
void Cola<T>::desencolar(){
	Lista<T>::quitar_primer_nodo();
}

template <typename T>
void Cola<T>::reencolar(){
	T primer_elem = Lista<T>::primer_elemento();	
	Lista<T>::quitar_primer_nodo();
	encolar(primer_elem);
}

template <typename T>
int Cola<T>::obtener_duenio(){
	return duenio;
}

template <typename T>
int Cola<T>::obtener_tamanio_max(){
	return tamanio_max;
}

template <typename T>
bool Cola<T>::cola_llena(){
	return this->tamanio() == tamanio_max;
}

template <typename T>
void Cola<T>::fijar_tamanio_max(int tam_max){
	this->tamanio_max = tam_max;
}

template <typename T>
void Cola<T>::imprimir(void){
	Lista<T>::imprimir();
}


#endif
