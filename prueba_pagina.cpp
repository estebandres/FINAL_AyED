#include <iostream> //libreria de flujo de datos I/O para con la consola
#include "Pagina.h"
#include "Pagina.cpp"
#include <vector> //utilizado para los valores ip
#include "Lista.h"

using namespace std;
/*
 *El siguiente programa tiene como objetivo, testear el correcto funcionamiento de la Clase Pagina
 * Para ello, inicializamos dos Paginas, de diferentes tamaños e identificadores,e igual origen y destino
 * (siendo *p1 y p2, la primera un puntero y la segunda una instancia)
 *  Para probar los metodos propios de la clase, imprimirmos por pantalla el valor de cada campo de manera
 *  individual, y despues repetimos la impresion, PERO AHORA, usando el propio metodo imprimir-imprimir de 
 *  la clase Lista, que no hace mas que llamar al metodo, de manera recursiva. (Previamente, inicializada 
 *  lista1, donde fueron cargadas las 2 paginas antes creadas.
 * 
 */

int main(int argc, char **argv)
{
	
	//
	int arreglo[2]={1,2}; 
	std::vector<int> ip_og(arreglo,arreglo+sizeof(arreglo)/sizeof(arreglo[0]));
	int arreglo2[2]={2,4};
	std::vector<int> ip_dt(arreglo2,arreglo2+sizeof(arreglo2)/sizeof(arreglo2[0]));
	
	Pagina *p1=new Pagina(1,5,ip_og,ip_dt);
	Pagina p2(90,20,ip_og,ip_dt);
	
	cout<<"Pagina1"<<endl;
	cout<<"id: "<<p1->obtener_id()<<endl;
	cout<<"tamanio: "<<p1->obtener_tamanio()<<endl;
	cout<<"ip origen: "<<p1->obtener_ip_comp_origen()[0]<<"--"<<p1->obtener_ip_comp_origen()[1]<<endl;
	cout<<"ip destino: "<<p1->obtener_ip_comp_destino()[0]<<"--"<<p1->obtener_ip_comp_destino()[1]<<endl;
	cout<<endl;
	cout<<endl;
	cout<<"Pagina2"<<endl;
	cout<<"id: "<<p2.obtener_id()<<endl;
	cout<<"tamanio: "<<p2.obtener_tamanio()<<endl;
	cout<<"ip origen: "<<p2.obtener_ip_comp_origen()[0]<<"--"<<p2.obtener_ip_comp_origen()[1]<<endl;
	cout<<"ip destino: "<<p2.obtener_ip_comp_destino()[0]<<"--"<<p2.obtener_ip_comp_destino()[1]<<endl<<endl;
	
	Lista<Pagina> lista1; //nuevo Obj Lista, llamado "lista1", que contiene paginas. Una lista de Paginas
	
	cout<<"tamaño de la lista: "<<lista1.tamanio()<<endl<<endl;
	lista1.agregar(*p1);
	lista1.agregar(p2);
	lista1.imprimir(); //metodo de lista, que llama a cada metodo "imprimir" de cada elemento == pagina
	
	return 0;
}

