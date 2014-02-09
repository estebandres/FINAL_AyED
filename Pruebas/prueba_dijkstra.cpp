
#include <iostream>
#include "Etiqueta.h"
#include "Etiqueta.cpp"
#include "Lista.h"
#include "Arco.h"
#include "Arco.cpp"

using namespace std;

Lista<Etiqueta> Dijkstra(int, int, Lista<Arco>);

 int router_inicio=1;

int main()
{
   // Administrador Admin;
    
   
    int cant_routers =4;
    Lista<Arco> arcos_conj;
    Lista<Etiqueta> etiquetas_ok;  

    Arco arco1(0,1,1);  arcos_conj.agregar(arco1);
    Arco arco2(1,0,1);  arcos_conj.agregar(arco2);
    Arco arco3(0,2,4);  arcos_conj.agregar(arco3);
    Arco arco4(2,0,4);  arcos_conj.agregar(arco4);
    Arco arco5(2,1,5);  arcos_conj.agregar(arco5);
    Arco arco6(1,2,5);  arcos_conj.agregar(arco6);
    //Arco arco6(2,2,1);  arcos_conj.agregar(arco6);
    Arco arco7(3,1,2);  arcos_conj.agregar(arco7);
    Arco arco8(1,3,2);  arcos_conj.agregar(arco8);
    Arco arco9(3,2,3);  arcos_conj.agregar(arco9);
    Arco arco0(2,3,3);  arcos_conj.agregar(arco0);
    Arco arco10(0,3,5);  arcos_conj.agregar(arco10);
    Arco arco11(3,0,5);  arcos_conj.agregar(arco11);
    
    
   etiquetas_ok = Dijkstra(0, cant_routers, arcos_conj);
   
   
   /*for (int i =0; i<10; i++)
   {
   etiquetas_ok.elemento_pos(i).destino();
   etiquetas_ok.elemento_pos(i).despacho();
   etiquetas_ok.elemento_pos(i).peso_total();		
   }*/

return 0;
}
 
Lista<Etiqueta> Dijkstra(int nodo_inicio, int cant_routers, Lista<Arco> arcos){
	Lista<int> S;
	Lista<int> Q;
	Lista<Etiqueta> etiquetas; 
	int INF = 999;
//------------INICIALIZACIÓN-------------------------------------
	for(int i=0; i<cant_routers;i++){
		if(i==nodo_inicio){
			Etiqueta etiqueta(i,0);
			//etiqueta.agregar_nodo(nodo_inicio);
			etiquetas.agregar(etiqueta);
		}
		else{
			Etiqueta etiqueta(i,INF);
			etiquetas.agregar(etiqueta);
		}
		Q.agregar(i);
	}
	
	//S.agregar(nodo_inicio);
	Q.mostrar();
	S.mostrar();
	etiquetas.imprimir();
	cout<<"No hay drama"<<endl;
	
//------------CICLO DE PROCESAMIENTO-------------------------------------
	while(!Q.es_vacia()){
		int nodo_elegido;
		int peso_tray_menor=INF;
		int peso_tray_actual;
		int pos;
		for(int i=0; i<Q.tamanio(); i++){//Para todos las posiciones de la lista de etiquetas señecciono la de menor peso_trayecto.
			peso_tray_actual=etiquetas.elemento_pos(Q.elemento_pos(i)).peso_total();
			cout<<peso_tray_actual<<endl;
			if(peso_tray_actual<peso_tray_menor){
				peso_tray_menor=peso_tray_actual;
				nodo_elegido=Q.elemento_pos(i);
				pos=i;
			}
		}
		cout<<"No hay drama. SE ELIGIO EL NODO: "<<nodo_elegido<<endl;
		Q.quitar_nodo_pos(pos);//Con esta acción corta el ciclo while
		S.agregar(nodo_elegido);
		cout<<"Q::";
		Q.mostrar();
		cout<<"S::";
		S.mostrar();
		
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
						cout<<"RELAJO: ";
						etiqueta_vieja->imprimir();
						cout<<endl;
						etiqueta_vieja->mod_peso_trayecto(peso_tray_nvo);
						cout<<"OBTENGO: ";
						etiqueta_vieja->imprimir();
						cout<<endl;
						//cout<<"ELEGIDO = "<<nodo_elegido<<"!= INICIO = "<<nodo_inicio<<endl;
						if(nodo_elegido!=nodo_inicio){
							etiqueta_vieja->agregar_nodo(nodo_elegido);
							//cout<<"Se agregó el nodo: "<<etiqueta_vieja->despacho()<<endl;
						}
					}
				}
			}
		}
	}
	etiquetas.imprimir();
	for(int m=0;m<etiquetas.tamanio();m++){
		//if(etiquetas.elemento_pos(m).despacho()==nodo_inicio)
			cout<<"Llegue"<<endl;
			etiquetas.elemento_pos(m).obtener_camino().mostrar();
			cout<<endl;
	}
	etiquetas.imprimir();
	return etiquetas;
}
