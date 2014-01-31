#include <assert.h>
#include <iostream>
#include <vector>
#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <string.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>


#define INF 9999
#define TAM_MAX_PAG 6
#define TAM_MIN_PAG 2


#define BOLD_RED     "\x1b[31;1m"
#define BOLD_BLUE    "\x1b[34;1m"
#define BOLD_GREEN   "\x1b[32;1m"
#define BOLD_CYAN    "\x1b[36;1m"
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_BRIGHT  "\x1b[1m"
#define ANSI_COLOR_RESET   "\x1b[0m"



using namespace std;

template <typename T>

//implementacion CLASE LISTA
class Lista {

private:
	//implementacion CLASE NODO, cuya clase amiga es LISTA, y puede acceder a elemento y siguiente.
    class Nodo {
        friend class Lista<T>;

    private:
        T elemento;
        Nodo* siguiente;

    public:
        Nodo(T d, Nodo* n = NULL) : elemento(d), siguiente(n) {}

    };
    /*!End Snippet:fullNodo*/

    Nodo* inicio;  // Beginning of list
    Nodo* final;  // End of list
    int cant_nodos;    // Number of Nodos in list
    /*!End Snippet:private*/

public:

    Lista(const Lista<T>& src);  // Copy constructor
    ~Lista(void);  // Destructor

    /*!Begin Snippet:simple*/
    // Default constructor
    Lista(void) : inicio(NULL), final(NULL), cant_nodos(0) {}

    // Returns a reference to first element
    T& primer_elemento(void) {
        assert (inicio != NULL && "Lista vacia"); //abortara la ejecucion dle programa mientras: 1) inicio es un puntero a nulo y 2) mensaje de lista vacia
        return inicio->elemento; //&& es como una AND, ambas condiciones a la vez
    }

    // Returns a reference to last element
    T& ultimo_elemento(void) {
        assert (final != NULL); //aborta si final es un puntero nulo
        return final->elemento;
    }

    // Returns cant_nodos of elements of list
    int tamanio(void) {
        return cant_nodos;
    }

    // Returns whether or not list contains any elements
    bool es_vacia(void) {
        return cant_nodos == 0;
    }
    /*!End Snippet:simple*/

    void insertar_al_principio(T);  // Insert element at beginning
    void insertar_al_final(T);   // Insert element at end
    void quitar_primer_nodo(void);  // Remove element from beginning
    void quitar_ultimo_nodo(void);  // Remove element from end

    void mostrar(void);  // Output contents of list
    void imprimir(void);
    void agregar(T);
    T& elemento_pos(int);
	
	void insertar_nodo_pos(T, int);
	void quitar_nodo_pos(int);
	void intercambiar_pos_nodos(int, int);
	bool contiene(T);
	void copiar_contenido(Lista<T>);

};

template <typename T>
void Lista<T>::copiar_contenido(const Lista<T> fuente){
	this->inicio=NULL;
	this->final=NULL;
	this->cant_nodos=0;
	Nodo* ptr_nodo_actual = fuente.inicio;
    while (ptr_nodo_actual != NULL) {
        this->insertar_al_final(ptr_nodo_actual->elemento);
        ptr_nodo_actual = ptr_nodo_actual->siguiente;
    }
}

/*!Begin Snippet:copyconstructor*/
// Copy constructor
template <typename T>
Lista<T>::Lista(const Lista<T>& src) :
        inicio(NULL), final(NULL), cant_nodos(0) {

    Nodo* ptr_nodo_actual = src.inicio;
    while (ptr_nodo_actual != NULL) {
        this->insertar_al_final(ptr_nodo_actual->elemento);
        ptr_nodo_actual = ptr_nodo_actual->siguiente;
    }

}
/*!End Snippet:copyconstructor*/

/*!Begin Snippet:destructor*/
// Destructor
template <typename T>
Lista<T>::~Lista(void) {

    while (! this->es_vacia()) {
        this->quitar_primer_nodo();
    }
}
/*!End Snippet:destructor*/

/*!Begin Snippet:pushprimer_elemento*/
// Insert an element at the beginning
template <typename T>
void Lista<T>::insertar_al_principio(T elemento) {

    Nodo* nva_inicio = new Nodo(elemento, inicio);

    if (this->es_vacia()) {
        inicio = nva_inicio;
        final = nva_inicio;
    } else {
        inicio = nva_inicio;
    }
    cant_nodos++;
}
/*!End Snippet:pushprimer_elemento*/

/*!Begin Snippet:pushultimo_elemento*/
// Insert an element at the end
template <typename T>
void Lista<T>::insertar_al_final(T elemento) {

    Nodo* nvo_final = new Nodo(elemento, NULL);

    if (this->es_vacia()) {
        inicio = nvo_final;
    } else {
        final->siguiente = nvo_final;
    }

    final = nvo_final;
    cant_nodos++;
}
/*!End Snippet:pushultimo_elemento*/

/*!Begin Snippet:popprimer_elemento*/
// Remove an element from the beginning
template <typename T>
void Lista<T>::quitar_primer_nodo(void) {

    assert(inicio != NULL);

    Nodo* inicio_anterior = inicio;

    if (this->tamanio() == 1) {
        inicio = NULL;
        final = NULL;
    } else {
        inicio = inicio->siguiente;
    }

    delete inicio_anterior;
    cant_nodos--;
}
/*!End Snippet:popprimer_elemento*/

/*!Begin Snippet:popultimo_elemento*/
// Remove an element from the end
template <typename T>
void Lista<T>::quitar_ultimo_nodo(void) {

    assert(final != NULL);

    Nodo* final_anterior = final;

    if (this->tamanio() == 1) {
        inicio = NULL;
        final = NULL;
    } else {

        // Traverse the list to Nodo just before final
        Nodo* ptr_nodo_actual = inicio;
        while (ptr_nodo_actual->siguiente != final) {
            ptr_nodo_actual = ptr_nodo_actual->siguiente;
        }

        // Unlink and reposition
        ptr_nodo_actual->siguiente = NULL;
        final = ptr_nodo_actual;
    }

    delete final_anterior;
    cant_nodos--;
}
/*!End Snippet:popultimo_elemento*/

/*!Begin Snippet:printlist*/
// Display the contents of the list
template <typename T>
void Lista<T>::mostrar(void) {

    cout << "(";

    Nodo* ptr_nodo_actual = inicio;

    if (ptr_nodo_actual != NULL) {

        while (ptr_nodo_actual->siguiente != NULL) {
            cout << ptr_nodo_actual->elemento << ", ";
            ptr_nodo_actual = ptr_nodo_actual->siguiente;
        }
        cout << ptr_nodo_actual->elemento;
    }

    cout << ")" << endl;
}
template <typename T>
void Lista<T>::imprimir(void) {

    cout <<endl<< "-----------------------------------------------------"<<endl;

    Nodo* ptr_nodo_actual = inicio;

    if (ptr_nodo_actual != NULL) {

        while (ptr_nodo_actual->siguiente != NULL) {
            ptr_nodo_actual->elemento.imprimir();
            cout<<endl;
            ptr_nodo_actual = ptr_nodo_actual->siguiente;
        }
        ptr_nodo_actual->elemento.imprimir();
    }

    cout << "-----------------------------------------------------"<<endl;
}
/*!End Snippet:printlist*/
template<typename T>
void Lista<T>::agregar(T elemento){
	this->insertar_al_final(elemento);
}

template <typename T>
T& Lista<T>::elemento_pos(int pos){
    assert (inicio != NULL && "La lista está vacía");
	assert (pos<=cant_nodos-1 && "Se intenta acceder a una nodo inexistente");

	Nodo* ptr_nodo_actual = inicio;
	int pos_actual=0;

       	while (pos_actual!=pos) {
		ptr_nodo_actual = ptr_nodo_actual->siguiente;
		pos_actual++;			
       	}

        return ptr_nodo_actual->elemento;
}

template <typename T>
void Lista<T>::quitar_nodo_pos(int pos){
	
	assert((pos>=0) && "Se desea quitar un nodo con posicion inválida.");
	assert((pos<=cant_nodos-1) && "Se desea quitar un nodo con posicion inválida.");
	
	if(pos==0){
		this->quitar_primer_nodo();
	}
	else{
		if(pos==(this->tamanio()-1)){
			this->quitar_ultimo_nodo();
		}
		else{
			Nodo* ptr_nodo_actual = inicio;
			Nodo* ptr_nodo_anterior = NULL;	
			int pos_actual=0;
       			while (pos_actual<pos) {
				ptr_nodo_anterior = ptr_nodo_actual;
				ptr_nodo_actual = ptr_nodo_actual->siguiente;
				pos_actual++;			
       			}
			ptr_nodo_anterior->siguiente=ptr_nodo_actual->siguiente;
			delete ptr_nodo_actual;
			cant_nodos--;
		}
	}

}

template <typename T>
void Lista<T>::insertar_nodo_pos(T elemento, int pos){

	assert(pos>=0 && "Se desea insertar un nodo con posicion inválida.");
	assert(pos<=cant_nodos-1 && "Se desea insertar un nodo con posicion inválida.");
	
	if(pos==0){
		this->insertar_al_principio(elemento);
		return;
	}
	if(pos==cant_nodos-1){
		this->insertar_al_final(elemento);
		return;
	}
	Nodo* ptr_nodo_actual = inicio;
	Nodo* ptr_nodo_anterior = NULL;

	int pos_actual=0;

	while (pos_actual!=pos) {
		ptr_nodo_anterior = ptr_nodo_actual;
		ptr_nodo_actual = ptr_nodo_actual->siguiente;
		pos_actual++;			
	}
	
	Nodo* nvo_nodo = new Nodo(elemento, ptr_nodo_actual);
	ptr_nodo_anterior->siguiente=nvo_nodo;
	
	cant_nodos++;
}


template <typename T>
void Lista<T>::intercambiar_pos_nodos(int pos_1, int pos_2){
	assert((pos_1>=0 || pos_1<=cant_nodos-1) && "Se desea cambiar de posicion a un nodo con posicion inválida.");// 
	assert((pos_2>=0 || pos_2<=cant_nodos-1) && "Se desea cambiar de posicion a un nodo hacia una posicion inválida.");//
	
	if((pos_1==0 && pos_2==cant_nodos-1) || (pos_1==cant_nodos-1 && pos_2==0)){
		Nodo* ptr_nodo_aux1=new Nodo(this->elemento_pos(0), NULL);
		Nodo* ptr_nodo_aux2=new Nodo(this->elemento_pos(cant_nodos-1), NULL);
		this->quitar_nodo_pos(0);
		this->insertar_al_final(ptr_nodo_aux1->elemento);
		this->quitar_nodo_pos(cant_nodos-2);
		this->insertar_al_principio(ptr_nodo_aux2->elemento);	
	}
	else{
		if(pos_1!=pos_2){
		if(pos_1>pos_2){
			int aux=pos_1;
			pos_1=pos_2;
			pos_2=aux;
		}
		Nodo* ptr_nodo_aux1=new Nodo(this->elemento_pos(pos_1), NULL);
		Nodo* ptr_nodo_aux2=new Nodo(this->elemento_pos(pos_2), NULL);
		this->quitar_nodo_pos(pos_1);
		this->insertar_nodo_pos(ptr_nodo_aux1->elemento, pos_2);
		this->quitar_nodo_pos(pos_2-1);
		this->insertar_nodo_pos(ptr_nodo_aux2->elemento, pos_1);
		}
	}
}

template <typename T>
bool Lista<T>::contiene(T elemento){
	bool contenido = false ;
	Nodo* ptr_nodo_actual = inicio;

    while (ptr_nodo_actual != NULL) {
		//cout<<"CONTIENE: "<<ptr_nodo_actual->elemento<<" == "<<elemento<<endl;
		if(ptr_nodo_actual->elemento == elemento){
			contenido=true;
			//cout<<"CONTIENE_RES: "<<contenido<<endl;
			return contenido;
		}
		ptr_nodo_actual = ptr_nodo_actual->siguiente;
	}
	//cout<<"CONTIENE_RES: "<<contenido<<endl;
	return contenido;
}

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

class Paquete
{
	private:
		vector<int> ip_comp_origen;
		vector<int> ip_comp_destino;
		int id_pagina;
		int tamanio_pagina;
		int nro_orden; //orden del paquete = tamanio/ancho_paquete
		
	public:		
		Paquete();
		Paquete(vector<int>, vector<int>, int, int, int);
		~Paquete();
		vector<int> obtener_ip_comp_origen();
		vector<int> obtener_ip_comp_destino();
		int obtener_id_pagina();
		int obtener_nro_orden();
		int obtener_tamanio_pagina();
		void imprimir();
		void cambiar_orden(int);
		
};

Paquete::Paquete(){
	this->ip_comp_origen=vector<int>(-1,-1);
	this->ip_comp_destino=vector<int>(-1,-1);
	this->id_pagina=-1;
	this->tamanio_pagina=-1;
	this->nro_orden=-1;
}
Paquete::Paquete(vector<int> ip_comp_origen, vector<int> ip_comp_destino, int id_pagina, int tamanio_pagina, int nro_orden){
	this->ip_comp_origen=ip_comp_origen;
	this->ip_comp_destino=ip_comp_destino;
	this->id_pagina=id_pagina;
	this->tamanio_pagina=tamanio_pagina;
	this->nro_orden=nro_orden;
}

vector<int> Paquete::obtener_ip_comp_origen(){
	return this->ip_comp_origen;
}

vector<int> Paquete::obtener_ip_comp_destino(){
	return this->ip_comp_destino;
}

int Paquete::obtener_id_pagina(){
	return this->id_pagina;
}

int Paquete::obtener_nro_orden(){
	return this->nro_orden;
}

int Paquete::obtener_tamanio_pagina(){
	return this->tamanio_pagina;
}

void Paquete::imprimir(){
	//cout<<"PAQUETE:"<<this->nro_orden<<" --> PÁGINA: "<<this->id_pagina<<endl;
	cout<<"[PAG:"<<this->id_pagina<<",Ro:"<<this->ip_comp_origen[0]<<",Rd:"<<this->ip_comp_destino[0]<<",ORD:"<<this->nro_orden<<"/"<<this->tamanio_pagina<<"]";
}

void Paquete::cambiar_orden(int nvo_nro_orden){
	this->nro_orden=nvo_nro_orden;
}

Paquete::~Paquete(){
	
}

/*
Esta clase representa el arco o la arista de un grafo.
Es la entidad que conecta dos nodos o vértices y que se le asigna un peso o distancia.
*/
class Arco
{
	private:
		int nodo_origen;		
		int nodo_destino;		
		int peso_arco;
	public:		
		Arco(int , int, int);
		~Arco();
		int origen();
		int destino();
		int peso();
		void mod_peso(int);//modifica el valor del peso del Arco.
		void imprimir();
};

Arco::Arco(int origen, int destino, int peso) : nodo_origen(origen),nodo_destino(destino),peso_arco(peso)
{}
Arco::~Arco(){
}
int Arco::origen(){
	return this->nodo_origen;
}
int Arco::destino(){
	return this->nodo_destino;
}
int Arco::peso(){
	return this->peso_arco;
}
void Arco::mod_peso(int nvo_peso){
	this->peso_arco=nvo_peso;
}
void Arco::imprimir(){
	cout<<"["<<this->nodo_origen<<"|"<<this->nodo_destino<<"|"<<this->peso_arco<<"]";
}

/*
Esta clase representa el arco de el grafo que ilustra la red a simular.
Consta de un par de terminales, la especificación del ancho de banda y
una cola para emular las limitaciones del canal. 
*/
class Conexion : public Arco
{
	private:
		Cola<Paquete> canal;
	public:		
		Conexion(int, int, int);
		~Conexion();
		//set<int> obtener_terminales();
		void cargar(Paquete);
		Paquete leer();
		int obtener_ancho_banda();
		bool conexion_saturada();
		bool conexion_libre();
};


Conexion::Conexion(int origen, int destino, int ancho) : Arco(origen, destino, ancho), canal(){
	this->canal.fijar_tamanio_max(ancho);
}

Conexion::~Conexion(){
}
/*
set<int> Conexion::obtener_terminales(){
	return this->terminales;
}*/

void Conexion::cargar(Paquete paq){
	//assert(canal.cola_llena() && "Se intenta cargar una conexion que está saturada.");
	this->canal.encolar(paq);
}

Paquete Conexion::leer(){
	Paquete paq_leido = this->canal.primer_elemento();
	this-> canal.desencolar();
	return paq_leido;
	
}

bool Conexion::conexion_saturada(){
	return this->canal.cola_llena();
}

int Conexion::obtener_ancho_banda(){
	return this->peso();
}

bool Conexion::conexion_libre(){
	return this->canal.es_vacia();
}

/*
Esta clase implementa las cumplas de tres enteros que utilizará la clase router para
determinar hacia dónde debe enviar los paquetes.
*/
class Etiqueta
{
	private:
		int router_destino;		
		int router_despacho;		
		int peso_trayecto;
		//Lista<int> camino;
	public:		
		Etiqueta(int, int, int);
		~Etiqueta();
		int despacho();
		int destino();
		int peso_total();
		void mod_peso_trayecto(int);//modifica peso_trayecto
		void mod_despacho(int);
		void imprimir();
		//void agregar_nodo(int);
		//Lista<int> obtener_camino();
		//void corregir(int);

};

Etiqueta::Etiqueta(int router_destino, int router_despacho, int peso_trayecto){
	this->router_destino=router_destino;
	//this->router_despacho=router_despacho;//router al que se debe despachar los paquetes que tienen como destino el router_destino;
	this->peso_trayecto=peso_trayecto;
}
Etiqueta::~Etiqueta(){
}
int Etiqueta::despacho(){
	return this->router_despacho;
}
int Etiqueta::destino(){
	return this->router_destino;
}
int Etiqueta::peso_total(){
	return this->peso_trayecto;
}
void Etiqueta::mod_peso_trayecto(int nvo_peso){
	this->peso_trayecto = nvo_peso;
}
void Etiqueta::mod_despacho(int nvo_router_despacho){
	this->router_despacho = nvo_router_despacho;
}
void Etiqueta::imprimir(){
	cout<<"["<<this->router_destino<<"|"<<this->router_despacho<<"|"<<this->peso_trayecto<<"]";
}


/*
Esta clase representa las páginas que generan las computadoras
y que contiene una identificación su tamaño en cantidad de paquetes y las direcciones
de origen y de destino en duplas.
*/

class Pagina
{
	private:
		int id;//número de la página.
		int tamanio;//tamaño de la página en cantidad de paquetes
		vector<int> ip_comp_origen;//ip pc y router origen
		vector<int> ip_comp_destino;//ip pc y router destino
		
	public:		
		Pagina(int, int, std::vector<int>, std::vector<int>);
		~Pagina();
		int obtener_id();
		int obtener_tamanio();
		std::vector<int> obtener_ip_comp_origen();
		std::vector<int> obtener_ip_comp_destino();
		void imprimir(void);
};

Pagina::Pagina(int id, int tamanio, vector<int> ip_comp_origen, vector<int> ip_comp_destino):id(id),tamanio(tamanio),ip_comp_origen(ip_comp_origen),ip_comp_destino(ip_comp_destino){}

Pagina::~Pagina()
{}

int Pagina::obtener_id(){
return this->id;
}

int Pagina::obtener_tamanio(){
return this->tamanio;
}

vector<int> Pagina::obtener_ip_comp_origen(){
return this->ip_comp_origen;
}

vector<int>  Pagina::obtener_ip_comp_destino(){
return this->ip_comp_destino;
}

void Pagina::imprimir(void){
	cout<<"Pagina: "<<this->obtener_id()<<endl;
	cout<<"tamanio: "<<this->obtener_tamanio()<<endl;
	cout<<"ip origen: "<<this->obtener_ip_comp_origen()[0]<<"--"<<this->obtener_ip_comp_origen()[1]<<endl;
	cout<<"ip destino: "<<this->obtener_ip_comp_destino()[0]<<"--"<<this->obtener_ip_comp_destino()[1]<<endl;
}


/*
Esta clase representa las computadoras o terminales conectadas a los routers
en la red a simular. Incluye un puntero al router al que está conectada con el objetivo de
solicitarle el envío de una nueva página. Adicionalmente posee una lista de páginas recibidas
que podrá ser usada para medir la eficiencia de la red.
*/
class Computadora
{
	private:
		//Router* router;//Puntero al router donde está conectada la máquina.
		vector<int> ip;
		Lista<Pagina> paginas_recibidas; 
	public:		
		Computadora(vector<int>);
		//Computadora();
		~Computadora();
		//void enviar_pagina(Pagina);
		void recibir_pagina(Pagina);
		int cant_pag_recibidas();
		vector<int> obtener_ip();
		void imprimir();
};

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
void Computadora::imprimir(){
	cout<<"Computadora: ("<<this->ip[0]<<"|"<<this->ip[1]<<endl;
}

/*
Esta clase es la estructura de datos que garantiza justicia en el envío de paquetes, esto es,
igual atención a las solicitudes de todos los routers y para todas las páginas.
En su interiror se implementa una colección de tipo anidada de tres niveles que se usa para organizar los
paquetes. Esta colección es del tipo cola y utiliza el campo especial duenio para identificar a qué router
y página pertenecen los paquetes encolados.
*/

class Biblioteca_paquetes
{
	private:
		Cola<Cola<Cola<Paquete> > > clasificador;
		int mi_router;
	public:
		Biblioteca_paquetes(int);
		~Biblioteca_paquetes();
		int agregar_paquete(Paquete);
		Paquete obtener_paquete();
		void imprimir();
		int tamanio();
		int destino_proa();
		int hay_envios();
		void reencolar_destino();
		int cant_destinos();
};

Biblioteca_paquetes::Biblioteca_paquetes(int mi_rout)
	:clasificador(), mi_router(mi_rout){}

Biblioteca_paquetes::~Biblioteca_paquetes(){
}

int Biblioteca_paquetes::agregar_paquete(Paquete paq_recibido){
	bool hay_cat_router=false;
	bool hay_cat_pagina=false;
	int i,j;
	int router_destino = paq_recibido.obtener_ip_comp_destino()[0];
	/*cout<<"-----------------------------------------------------"<<endl;
	cout<<"TAMANIO: "<<clasificador.tamanio()<<endl;
	
	cout<<"ROUTER DESTINO: "<<router_destino<<endl;;
	cout<<"PAGINA DESTINO: "<<paq_recibido.obtener_id_pagina()<<endl;
	cout<<"------------------------------------------------------"<<endl;*/
	if(clasificador.tamanio()>0){//Si el clasificador no está vacío.
		//cout<<"El clasificador no está vacío"<<endl;
		for(i=0 ; i<clasificador.tamanio() ; i++){
			if(clasificador.elemento_pos(i).obtener_duenio()==router_destino){
				hay_cat_router=true;
				break;
			}
		}
			if(hay_cat_router){//Si la categoría del clasificador en la posicion (i) tiene como dueño al router destino del paquete.
//Si el clasificador tiene la categoría para el router_destino del paquete en la posicion (i).
				//cout<<"hay paginas para este router "<<router_destino<<endl;
				for(j=0 ; j < clasificador.elemento_pos(i).tamanio() ; j++){
					if(clasificador.elemento_pos(i).elemento_pos(j).obtener_duenio()==paq_recibido.obtener_id_pagina()){
						hay_cat_pagina=true;
						break;
					}
				}
					//cout<<"REVISO PAGINA: "<<hay_cat_pagina;
					if(hay_cat_pagina){//Si la categoría de páginas para tal router contiene una para la página del paquete.
//Si el clasificador tiene la categoría para la página del paquete en la poscion (j) dentro de la categoría del router destino en la posición (i).
						//cout<<"hay paquetes para la pagina"<<paq_recibido.obtener_id_pagina()<<endl;
						clasificador.elemento_pos(i).elemento_pos(j).encolar(paq_recibido);
						if(paq_recibido.obtener_ip_comp_destino()[0]==mi_router && paq_recibido.obtener_tamanio_pagina()==clasificador.elemento_pos(i).elemento_pos(j).tamanio()){//Si el paquete tiene como destino mi_router y además completa una página.
							//Ordeno los paquetes en órden ascendente y Elimino la categoría de la página completada;
							//cout<<"Pagina completa"<<endl;
							vector<int> vec_des(clasificador.elemento_pos(i).elemento_pos(j).tamanio());
							vector<int> vec_ord(vec_des.size());
							int k=0;
							while(k<clasificador.elemento_pos(i).elemento_pos(j).tamanio()){
								vec_des[k]=clasificador.elemento_pos(i).elemento_pos(j).elemento_pos(k).obtener_nro_orden();
								vec_ord[k]=k;
								k++;
							}
							//vector<int> vec_ordenado=vec_desordenado;//voy cargando en mi vector desordenado los ordenes de los paquetes de la cola.
							//vec_ordenado.sort();
							//ordena la cola de paquetes.
							for(vector<int>::size_type l=0; l<vec_ord.size(); l++){
								if(vec_ord == vec_des)
									break;								
								for(vector<int>::size_type m=0; m<vec_des.size(); m++){
									if(vec_des[l]==vec_ord[m]){
										int aux=0;
										aux=vec_des[l];
										vec_des[l]=vec_des[m];
										vec_des[m]=aux;
										//clasificador.elemento_pos(i).elemento_pos(j).intercambiar_pos_nodos(l,m);
									}
								}
							}
							clasificador.elemento_pos(i).quitar_nodo_pos(j);
							return 1;
						}
						else{//Si el paquete NO venía para mi_router o NO se completo la página.
							return 0;
						}
					}
					else{//Si el clasificador NO tiene la categoría para la página del paquete. 
						//cout<<"agrega cat pag"<<endl;
						Cola<Paquete> paquetes_nva_pag(paq_recibido.obtener_id_pagina());
						paquetes_nva_pag.encolar(paq_recibido);
						clasificador.elemento_pos(i).encolar(paquetes_nva_pag);
						return 0;
					}
			}
			else{//Si el clasificador NO tiene la categoría para el router destino del paquete.
				//cout<<"agrega cat router"<<endl;
				Cola<Cola<Paquete> > paginas_nvo_router(router_destino);
				Cola<Paquete> paquetes_nva_pag(paq_recibido.obtener_id_pagina());
				paquetes_nva_pag.encolar(paq_recibido);
				paginas_nvo_router.encolar(paquetes_nva_pag);
				clasificador.encolar(paginas_nvo_router);
				return 0;
			}
	}
	else{//Si el clasificador ESTÁ VACÍO.
		//cout<<"Estaba vacio"<<endl;
		Cola<Cola<Paquete> > paginas_nvo_router(router_destino);
		Cola<Paquete> paquetes_nva_pag(paq_recibido.obtener_id_pagina());
		paquetes_nva_pag.encolar(paq_recibido);
		paginas_nvo_router.encolar(paquetes_nva_pag);
		clasificador.encolar(paginas_nvo_router);
		return 0;
	}
	return 0;

}

Paquete Biblioteca_paquetes::obtener_paquete(){
	assert (clasificador.tamanio()>0 && "Se intenta obtener paquetes de la coleccion vacia");
	//cout<<"Hey1"<<endl;
	if(clasificador.primer_elemento().obtener_duenio()==mi_router)//Si estoy en las paginas de mi router reencolo.
		clasificador.reencolar();
	//cout<<"Hey2"<<endl;
	Paquete paquete_envio = clasificador.primer_elemento().primer_elemento().primer_elemento();
	clasificador.primer_elemento().primer_elemento().desencolar();
	//cout<<"Hey3"<<endl;
	if(clasificador.primer_elemento().primer_elemento().es_vacia())//si la página no tiene más paquetes...
		clasificador.primer_elemento().desencolar();//Desencolo la página para ese router.
	else
		clasificador.primer_elemento().reencolar();
	if(clasificador.primer_elemento().es_vacia())//si no hay más paginas para ese router
		clasificador.desencolar();//desencolo tal router del clasificador.
	else		
		clasificador.reencolar();
	return paquete_envio;
}

void Biblioteca_paquetes::imprimir(){
	for(int i=0;i<clasificador.tamanio();i++){
		for(int j=0;j<clasificador.elemento_pos(i).tamanio();j++){
			for(int k=0;k<clasificador.elemento_pos(i).elemento_pos(j).tamanio();k++){
				clasificador.elemento_pos(i).elemento_pos(j).elemento_pos(k).imprimir();
				cout<<" ; ";
			}
		}
	}
}
int Biblioteca_paquetes::tamanio(){	
	int tam=0;
	for(int i=0;i<clasificador.tamanio();i++){
		for(int j=0;j<clasificador.elemento_pos(i).tamanio();j++){
			for(int k=0;k<clasificador.elemento_pos(i).elemento_pos(j).tamanio();k++){
				tam++;
			}
		}
	}
	return tam;
}

int Biblioteca_paquetes::destino_proa(){
	return clasificador.primer_elemento().obtener_duenio();
}

void Biblioteca_paquetes::reencolar_destino(){
	this->clasificador.reencolar();
}

int Biblioteca_paquetes::cant_destinos(){
	return this->clasificador.tamanio();
}

/*
Esta clase representa los nodos de la red y opera como enrutador, tiene las funcionalidades de
enviar y recibir paquetes así como recibi páginas completas desde las computadoras que están conectadas a este router.
*/
class Router
{
	private:
		int ip;
		Lista<Computadora> computadoras;
		Lista<Etiqueta> tabla_enrutamiento;
		Biblioteca_paquetes organizador_paquetes;
		Lista<Conexion*> conexiones_envio;
		Lista<Conexion*> conexiones_recepcion;
		
	public:
		Router(int);
		~Router();		
		//Router(int, Lista<*Computadora>, Lista<Etiqueta>, Lista<Conexion>);
		void recibir_pagina(Pagina);
		void recibir_paquetes();
		void leer_conexiones();
		void enviar_paquetes();
		void cargar_conexiones();
		int buscar_en_tabla(int);
		void enviar_pagina(Pagina);
		Pagina construir_pagina(Paquete);
		void mostrar_paquetes();
		void agregar_conexion_envio(Conexion*);
		void agregar_conexion_recepcion(Conexion*);
		int obtener_ip();
		int total_paquetes();
		void actualizar_tabla(Lista<Etiqueta>);
		void agregar_computadora(Computadora);
		void imprimir();
};

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

void Router::mostrar_paquetes(){
	cout<<endl<<BOLD_GREEN "-----------------------------------------------------------------------------" ANSI_COLOR_RESET<<endl;
	cout << BOLD_RED "R"<<this->ip<<":"<< BOLD_BLUE "TOTAL DE PAQUETES: "<<this->organizador_paquetes.tamanio()<<ANSI_COLOR_RESET<<endl;
	//cout<<"R"<<this->ip<<":"<<endl;
	cout<<BOLD_GREEN "-----------------------------------------------------------------------------" ANSI_COLOR_RESET<<endl;
	this->organizador_paquetes.imprimir();
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

/*
Esta clase se encarga de administrar la simulación. Puede ver y modificar absolutamente todos los parámetros
de la red Routers, computadoras, conexiones. Tiene la funcionalidad de calcular caminos óptimos con la 
implementación del algoritmo de Dijkstra para grafos direccionados y que admite ciclos no recurrentes.
Adicionalmente es capáz de leer la configuración de la red desde un archivo y dibujar el grafo
de la red haciendo uso de la librería graphvz mediante la aplicación Dot de los repositorios de ubuntu.
Cabe mensionar que se determinó que todos routers tienen la misma cantidad de maquinas conectadas.
*/
class Administrador
{
	private:
		Lista<Router> routers;
		Lista<Arco> arcos;
		Lista<Conexion*> conexiones;
		int cant_comp_por_router;
		int cant_routers;
		int total_pag;
		int cant_pasos;
		
	public:
		Administrador();
		~Administrador();
		void simular_cant_pasos(int);
		void simular_un_paso(bool);
		Lista<Etiqueta> Dijkstra(int);
		void calcular_tablas();
		void leer_archivo();
		//void crear_conexiones();
		int dibujar_grafo();
		void crear_pagina();
		void probar_conf();
};

Administrador::Administrador()
	:routers(),arcos(),conexiones(),cant_comp_por_router(0),cant_routers(0),total_pag(0),cant_pasos(1){}

Administrador::~Administrador(){
}

void Administrador::simular_cant_pasos(int cant_pasos){
		
		for(int i=0; i<cant_pasos; i++){
			this->simular_un_paso(false);
		}
}

void Administrador::crear_pagina(){
//Cada cierta cantidad de pasos de simulacion (5) se generaran paginas aleatorioas de compuatadoras aleatorias.
//
	unsigned int seed;
	FILE* urandom = fopen("/dev/urandom", "r");
	fread(&seed, sizeof(int), 1, urandom);
	fclose(urandom);
	srand(seed);
	//srand(time(0));
	int i = rand() % (cant_routers);
	//srand(time(0));
	int j = rand() % (cant_comp_por_router);//el +1 vá por definición de rand().
	int arreglo1[2]={i,j};
	vector<int> ip_comp_origen(arreglo1,arreglo1+sizeof(arreglo1)/sizeof(arreglo1[0]));
	//srand(time(0));
	int k = rand() % (cant_routers);
	//srand(time(0));
	int l = rand() % (cant_comp_por_router);
	int arreglo2[2]={k,l};
	vector<int> ip_comp_destino(arreglo2,arreglo2+sizeof(arreglo2)/sizeof(arreglo2[0]));
	int tam_pag = rand() % ( (TAM_MAX_PAG+1) - TAM_MIN_PAG ) + TAM_MIN_PAG;//uso (TAM_MAX_PAG+1) así el rango de valores pseudoaleatorios incluye el nro TAM_MAX_PAG
	Pagina nva_pag(total_pag, tam_pag, ip_comp_origen, ip_comp_destino);
	cout<<"SE CREO UNA NUEVA PAGINA: "<<endl;
	nva_pag.imprimir();
	//Se envía la página creada al router que corresponde.
	
	routers.elemento_pos(i).recibir_pagina(nva_pag);//Por razones de tiempo no se pudo implementar la colecciones de páginas recibidas y para envío que deberían compartir los routeres con sus máquinas por lo tanto se les envía las páginas creadas desde adminsuistrador, 
	total_pag++;
}

void Administrador::simular_un_paso(bool verbose){//recorrer la lista de routers y ejecutar enviar y despues en otro ciclo recibir
	
	cout<<BOLD_RED "PASO DE SIMULACION NRO: " ANSI_COLOR_RESET<<cant_pasos<<endl<<endl;
	if(cant_pasos == 1){//Si este es el primer paso de simulación
		this->calcular_tablas();
		//cout<<"Estoy en el if"<<endl;
		int bandera=cant_routers;
		//cout<<"El valor de bandera es: "<<bandera<<endl;
		while(bandera>=0){
			//cout<<"Estoy en el while"<<endl;
			this->crear_pagina();//Se crearán tantas páginas como routers tiene el sistema.
			bandera--;
		}
		cout<<endl<<BOLD_CYAN<<"-----------------------------------------------ESTADO INICIAL--------------------------------------------"<<ANSI_COLOR_RESET<<endl;
		for(int i=0;i<routers.tamanio();i++){
			routers.elemento_pos(i).mostrar_paquetes();
		}
	}
	if((cant_pasos % 5) == 0){//Cada 5 pasos de simulación se crea una página.
		this->crear_pagina();
	}
	if((cant_pasos % 30) == 0){//Cada 30 pasos de simulación se recalculan las tablas de enrutamiento por lo que debe actualizarse el peso de todos los arcos.
		cout<<BOLD_RED"PASARON "<<cant_pasos<<" PASOS DE SIMULACION"ANSI_COLOR_RESET<<endl;
		int nvo_peso;		
		for(int i=0;i<arcos.tamanio();i++){
			nvo_peso=routers.elemento_pos(arcos.elemento_pos(i).destino()).total_paquetes()/conexiones.elemento_pos(i)->peso();
			assert(nvo_peso>=0 && "peso de arco negativo");
			if(nvo_peso>0)//Actualizará si y solo si el nvo_peso es mayor que cero
				arcos.elemento_pos(i).mod_peso(nvo_peso);
				
		}
		this->calcular_tablas();
	}
	//cout<<"Tamanio de Routers"<<routers.tamanio()<<endl;
	cout<<endl<<BOLD_CYAN<<"-----------------------------------------------RECEPCIÓN DE PAQUETES--------------------------------------------"<<ANSI_COLOR_RESET<<endl;
	for(int i=0;i<routers.tamanio();i++){
		//cout<<"Recepcion del ROuter nro:"<<i<<endl;
		routers.elemento_pos(i).recibir_paquetes();
	}
	if(verbose){
		for(int i=0;i<routers.tamanio();i++){
			routers.elemento_pos(i).mostrar_paquetes();
		}
	}
	//cout<<"Tamanio de Routers"<<routers.tamanio()<<endl;
	cout<<endl<<BOLD_CYAN<<"-----------------------------------------------ENVÍO DE PAQUETES--------------------------------------------"<<ANSI_COLOR_RESET<<endl;
	for(int i=0;i<routers.tamanio();i++){
		//cout<<"Envio del ROuter nro:"<<i<<endl;
		routers.elemento_pos(i).enviar_paquetes();
	}
	/*if(verbose){
		for(int i=0;i<routers.tamanio();i++){
			routers.elemento_pos(i).mostrar_paquetes();
		}
	}*/
	this->cant_pasos++;
}

Lista<Etiqueta> Administrador::Dijkstra(int nodo_inicio){
	Lista<int> S;
	Lista<int> Q;
	Lista<Etiqueta> etiquetas;
	Lista<int> adyacentes;
	//Lista<int> predecesores;
	vector<int> predecesores(cant_routers);
	//cout<<predecesores[3]<<predecesores[5]<<endl;
	
//------------INICIALIZACIÓN-------------------------------------	
	for(int i=0; i<cant_routers;i++){
		if(i==nodo_inicio){
			Etiqueta etiqueta(i,0,0);
			etiquetas.agregar(etiqueta);
			predecesores[i]=nodo_inicio;			
		}
		else{
			Etiqueta etiqueta(i,-1,INF);
			etiquetas.agregar(etiqueta);
			predecesores[i]=-1;
		}
		Q.agregar(i);
	}
	for(int j=0;j<arcos.tamanio();j++){
		if(arcos.elemento_pos(j).origen()==nodo_inicio){
			adyacentes.agregar(arcos.elemento_pos(j).destino());
		}
	}
	
//------------CICLO DE PROCESAMIENTO-------------------------------------
	while(!Q.es_vacia()){
		int nodo_elegido;
		int peso_tray_menor=INF;
		int peso_tray_actual;
		int pos;
		for(int i=0; i<Q.tamanio(); i++){//Para todos las posiciones de la lista de etiquetas señecciono la de menor peso_trayecto.
			peso_tray_actual=etiquetas.elemento_pos(Q.elemento_pos(i)).peso_total();
			//cout<<peso_tray_actual<<endl;
			if(peso_tray_actual<peso_tray_menor){
				peso_tray_menor=peso_tray_actual;
				nodo_elegido=Q.elemento_pos(i);
				pos=i;
			}
		}
		//Q.mostrar();
		//S.mostrar();
		Q.quitar_nodo_pos(pos);//Con esta acción corta el ciclo while
		S.agregar(nodo_elegido);
		
		Arco* arco_actual;
		int peso_tray_nvo;
		Etiqueta* etiqueta_vieja;
		for(int k=0;k<arcos.tamanio();k++){//para cada uno de los arcos del grafo.
			arco_actual= &arcos.elemento_pos(k);
			if(arco_actual->origen()==nodo_elegido){//Si el arco tiene como orígen el nodo que estamos analizando. Osea corroboro sobre los que son adyancentes al nodo_elegido.
				if(!S.contiene(arco_actual->destino())){//Si el destino de ese arco NO está dentro de los nodos calculados.
					etiqueta_vieja = & etiquetas.elemento_pos(arco_actual->destino());
					peso_tray_nvo=etiquetas.elemento_pos(nodo_elegido).peso_total()+arco_actual->peso();
					//RELAJO - ACTUALIZO
					if(etiqueta_vieja->peso_total()>peso_tray_nvo){//Si el peso del trayecto de la etiqueta vieja es mayor que el peso del trayecto calculado.
						etiqueta_vieja->mod_peso_trayecto(peso_tray_nvo);
						//predecesores.insertar_nodo_pos(nodo_elegido, arco_actual->destino());
						predecesores[arco_actual->destino()]=nodo_elegido;
					}
				}
			}
		}
	}
	
	for(size_t i=0;i<predecesores.size();i++){
		if(predecesores[i]==nodo_inicio)
			predecesores[i]=i;
	}
	
	bool todos_adyacentes=false;
	while(!todos_adyacentes){
		todos_adyacentes=true;
		for(size_t m=0;m<predecesores.size();m++){
			if(predecesores[m]!=nodo_inicio){
				if(!adyacentes.contiene(predecesores[m])){
					//cout<<"Entre al if. Parece que"<<predecesores[m]<<"No es adyacente."<<endl;
					predecesores[m]=predecesores[predecesores[m]];
				}
				//cin.get();
				todos_adyacentes=todos_adyacentes && adyacentes.contiene	(predecesores[m]);
				//cout<<"LA PRODUCTORIA: "<<todos_adyacentes<<endl;
			}
		}	
	}
	
	for(int n=0;n<etiquetas.tamanio();n++){
		etiquetas.elemento_pos(n).mod_despacho(predecesores[n]);
	}
	cout<<"TABLA DE ENRUTAMIENTO R"<<nodo_inicio<<": "<<endl;
	//cin.get();
	etiquetas.imprimir();
	return etiquetas;
}

void Administrador::calcular_tablas(){
	for(int i=0; i<cant_routers; i++){
		Lista<Etiqueta> tabla = this->Dijkstra(i);
		//cout<<"||||||||||||||||||||||||||||||||||||||"<<endl;
		//tabla.imprimir();
		routers.elemento_pos(i).actualizar_tabla(tabla);
	}
}

void Administrador::leer_archivo(){
	std::ifstream archivo_conf("config.txt");
	string linea;
	while(getline(archivo_conf, linea)){
		switch(linea[0]){
		case('#'):
		{
			linea.erase(linea.begin());//borra el primer caracter de la línea, en este caso el símbolo #
			std::istringstream iss(linea);
			int nro;
			if (!(iss >> nro)) { 
				cout<<"Error en la lectura de la cantidad de routers."<<endl;
				break; 
			} // error
			cant_routers=nro;
			for(int i=0; i<cant_routers; i++){
				Router router_i(i);
				routers.agregar(router_i);
			}
		}
		break;
		case('*'):
		{
			linea.erase(linea.begin());
			std::istringstream iss(linea);
			int nro;
			if (!(iss >> nro)) { 
				cout<<"Error en la lectura de la cantidad de computadoras por router."<<endl;
				break; 
			} // error
			cant_comp_por_router=nro;
			for(int i=0; i<cant_routers; i++){
				for(int j=0; j<cant_comp_por_router; j++){
					int arreglo[]={i,j};
					vector<int> ip_comp_i_j(arreglo,arreglo+sizeof(arreglo)/sizeof(arreglo[0]));
					//Router* ptr_router_i=&routers.elemento_pos(i);//puntero al router de la posicion i de la lista de routers de la red.
					
					Computadora computadora_i_j(ip_comp_i_j);
					//computadora_i_j.imprimir();
					//cout<<endl;
					//Computadora *ptr_comp_i_j = &computadora_i_j;//puntero a la computadora recien creada
					//computadoras.agregar(ptr_comp_i_j);//se agrega el puntero de la computadora recien creada a la lista de computadoras de la red.
					routers.elemento_pos(i).agregar_computadora(computadora_i_j);//se agrega la computadora a la lista de punteros a computadoras del router al que pertenece.
				}
			}
		}	
		break;
		case('@'):
		{
			linea.erase(linea.begin());
			std::istringstream iss(linea);
			int origen, destino, ancho_banda;
			if (!(iss >> origen >> destino >> ancho_banda)) { 
				cout<<"Error en la lectura de la conexion de router."<<endl;
				break; 
			} // error
			//int peso = ancho_banda/routers.elemento_pos(router_j).total_paquetes();//No tiene propósito hacer esto al iniciar la simulación ya que los routers no tienen paquetes que enviar.
			Conexion* ptr_conexion = new Conexion(origen, destino, ancho_banda);
			conexiones.agregar(ptr_conexion);
			ptr_conexion->imprimir();
			cout<<endl;
			routers.elemento_pos(ptr_conexion->origen()).agregar_conexion_envio(ptr_conexion);//El router que corresponde al orígen de la conexión va a cargar paquetes.
			routers.elemento_pos(ptr_conexion->destino()).agregar_conexion_recepcion(ptr_conexion);//El router que corresponde al destino de la conexión va a leer los paquetes cargados en el canal.
			Arco nvo_arco(origen, destino, TAM_MAX_PAG/ancho_banda);//Como el peso es la distancia, dificultad o costo de la comunicacion entre nodos, entonces debe ser inversamente proporcional a los anchos de banda
			arcos.agregar(nvo_arco);
		}
		break;
		}
	}
}

int Administrador::dibujar_grafo(){
	
	FILE * f = popen( "date +\"%m-%d_%H-%M-%S\"", "r" );
    if ( f == 0 ) {
        fprintf( stderr, "No se pudo ejecutar \"date\".\n" );
        return 1;
    }
    const int BUFSIZE = 1000;
    char buf[ BUFSIZE ];
    fgets( buf, BUFSIZE,  f );
    cout<<buf<<endl;
    pclose( f );
    /*std::string linea(buf);
    linea[linea.size()-1]='\0';
    std::stringstream flujo_cadenas;
	flujo_cadenas << "grafo_" << linea << ".dot";
	std::string cadena_concat = flujo_cadenas.str();
	cout<<cadena_concat<<endl;
	*/
	buf[strlen(buf)-1]='\0';
	char nombre_archivo[100];
	strcpy(nombre_archivo,"grafo_");
	strcat(nombre_archivo,buf);
	strcat(nombre_archivo,".dot");
	cout<<nombre_archivo<<endl;
	ofstream flujo_salida;
	
	
	flujo_salida.open(nombre_archivo);
	flujo_salida<<"digraph G \{"<<endl;
	//flujo_salida<<"graph [splines = ortho];"<<endl;
	for(int i=0; i<cant_routers;i++){
		for(int j=0; j<cant_comp_por_router;j++){
		flujo_salida<<i<<" -> m"<<i<<j<<";"<<endl;
		flujo_salida<<"m"<<i<<j<<" [label=\"\",shape=circle,height=0.12,width=0.12,fontsize=1,color=red,style=filled];"<<endl;
		}
		flujo_salida<<i<<" [label="<<"\"R"<<i<<"\""<<",shape=doublecircle,fontsize=10];"<<endl;
	}
	for(int k=0;k<arcos.tamanio();k++){
		/*set<int>::iterator it_1 = conexiones.elemento_pos(k).terminales().begin();
		set<int>::iterator it_2 = it_1++;
		flujo_salida<<*it_1<<" -- "<<*it_2<<" [color=blue,penwidth=3.0]"<<endl;*/
		flujo_salida<<arcos.elemento_pos(k).origen()<<" -> "<<arcos.elemento_pos(k).destino()<<" [label=\""<<arcos.elemento_pos(k).peso()<<"\",color=blue,penwidth=3.0]"<<endl;
	}
	flujo_salida<<"}"<<endl;
	
	char compilar_dot[100];
	strcpy(compilar_dot,"dot -Tpng ");
	strcat(compilar_dot,nombre_archivo);
	strcat(compilar_dot," -o ");
	strcat(compilar_dot,buf);
	strcat(compilar_dot,".png");
		
	FILE * f2 = popen( compilar_dot, "r" );
    if ( f2 == 0 ) {
        fprintf( stderr, "No se pudo ejecutar el compilar_dot.\n" );
        return 1;
    }
    char mostrar_png[100];
	strcpy(mostrar_png,"eog ");
	strcat(mostrar_png,buf);
	strcat(mostrar_png,".png");
	
	cout<<mostrar_png<<endl;
	
    int Input[2], Output[2];

	pipe( Input );
	pipe( Output );

	if( fork() ){
		// Este es el proceso padre.
		// Close the reading end of the input pipe.
		close( Input[ 0 ] );
		// Close the writing end of the output pipe
		close( Output[ 1 ] );

		// Here we can interact with the subprocess.  Write to the subprocesses stdin via Input[ 1 ], and read from the subprocesses stdout via Output[ 0 ].
	}
	else{    // We're in the child here.
		close( Input[ 1 ] );
		dup2( Input[ 0 ], STDIN_FILENO );
		close( Output[ 0 ] );
		dup2( Output[ 1 ], STDOUT_FILENO );

		FILE * f3 = popen( mostrar_png, "r" );
		if ( f3 == 0 ) {
			fprintf( stderr, "No se pudo ejecutar mostrar_png.\n" );
			return 1;
		}
	}
	return 0;
}

void Administrador::probar_conf(){
	routers.imprimir();
	cout<<"ARCOS:"<<endl;
	arcos.imprimir();
	cout<<"CONEXIONES:"<<endl;
	for(int i=0;i<conexiones.tamanio();i++){
		conexiones.elemento_pos(i)->imprimir();
		cout<<endl;
	}
}


int main(int argc, char **argv)
{
	Administrador admin;
	cout<<"Configure la RED que desea simular modificando el archivo conf.txt que se encuentra en el mismo directorio que el ejecutable."<<endl;
	cout<<"Cuando termine presione ENTER."<<endl;
	cin.get();
	admin.leer_archivo();
	admin.probar_conf();
	//admin.dibujar_grafo();
	cout<<"Ingrese la cantidad de pasos a simular y presione ENTER. (Si se presiona enter sin especificar la cantidad de pasos se simulará un único paso.)"<<endl;
	int comando=0;
	while (true) {
		cin>>comando;
		if(comando>0){
			if(comando==1){
				cout<<"Simulación de un paso"<<endl;
				admin.simular_un_paso(true);
			}
			else{
				cout<<"Simulación de "<<comando<<" pasos."<<endl;
				admin.simular_cant_pasos(comando);
			}
		}
		else{
			cout<<"Simulación Terminada."<<endl;
			break;
		}
			
	}
	return 0;
}
