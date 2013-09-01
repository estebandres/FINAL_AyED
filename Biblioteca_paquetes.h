#ifndef BIBLIOTECA_PAQUETES_H
#define BIBLIOTECA_PAQUETES_H
#include <iostream>

using namespace std;

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
};

Biblioteca_paquetes::Biblioteca_paquetes(int mi_router){
	this->mi_router=mi_router;
}

Biblioteca_paquetes::~Biblioteca_paquetes(){
	delete &clasificador;
}

int Biblioteca_paquetes::agregar_paquete(Paquete paq_recibido){
	int router_destino = paq_recibido.obtener_ip_comp_destino()[0];
	bool paquete_encolado=false;
	//if(paquete_envio.obtener_ip_comp_destino()[1]==mi_router->computadoras().elemento_pos(i).paquete_envio.obtener_tamanio_pagina() == clasificador.primer_elemento().primer_elemento().tamanio())//Si la computadora destino es
	if(clasificador.tamanio()>0){
	
//Si el clasificador tiene paquetes de la misma pagina para el mismo router, guarda el paquete en esa cola.
		for(int i=0 ; i<clasificador.tamanio() ; i++){	
			if(clasificador.elemento_pos(i).obtener_duenio()==router_destino){//Si el clasificador tiene una coleccion de paquetes para el router destino.
				for(int j=0 ; j < clasificador.elemento_pos(i).tamanio() ; j++){
					if(clasificador.elemento_pos(i).elemento_pos(j)==paq_recibido.obtener_id_pagina()){
						clasificador.elemento_pos(i).elemento_pos(j).encolar(paq_recibido);
						if(paq_recibido.obtener_ip_comp_destino[0]==mi_router && paq_recibido.obtener_tamanio_pagina()==clasificador.elemento_pos(i).elemento_pos(j).tamanio()){ //si el paquete encolado completa una pagina para este router los ordena y devuelve "1"
							vector<int> vec_desordenado(clasificador.elemento_pos(i).elemento_pos(j).tamanio());
							
							int k=0;
							while(k<clasificador.elemento_pos(i).elemento_pos(j).tamanio()){
								vec_desordenado[k]=clasificador.elemento_pos(i).elemento_pos(j).elemento_pos(k).obtener_orden();
								k++;
							}
							vector<int> vec_ordenado=vec_desordenado;//voy cargando en mi vector desordenado los ordenes de los paquetes de la cola.
							vec_ordenado.sort();
							//ordena la cola de paquetes.
							for(int l=0; l<vec_des.size(); l++){
								for(int m=0; m<vec_ord.size(); m++){
									if(vec_des[l]==vec_ord[m]){
										clasificador.elemento_pos(i).elemento_pos(j).intercambiar_pos_nodos(l,m);
									}
								}
							}
							return 1;
						}
						//paquete_encolado=true;
						return 0;
					}
				}
				if(!paquete_encolado){
	//Si el paquete no fue encolado significa que no existe una cola de paquetes de esa pagina para tal router.
	//entonces crea una cola para ese ruter y esa página.
					Cola<Paquetes> paquetes_nva_pag(paq_recibido.obtener_id_pagina());
					paquetes_nva_pag.encolar(paq_recibido);
					clasificador.elemento_pos(i).encolar(paquetes_nva_pag);
					//paquete_encolado=true;
					return 0;
				}
			}	
		}
	//	if(!paquete_encolado){
	//Si el paquete no fue encolado significa que no existe una cola para el router destino.
			Cola<Cola<Paquetes> > paginas_nvo_router(router_destino);
			Cola<Paquetes> paquetes_nva_pag(paq_recibido.obtener_id_pagina());
			paquetes_nva_pag.encolar(paq_recibido);
			paginas_nvo_router.encolar(paquetes_nva_pagina);
			clasificador.encolar(paginas_nvo_router);
			
		//{
	else{
//Si el clasificador está vació debo agregar la categoria entera para este router y esta pagina.
		Cola<Cola<Paquetes> > paginas_nvo_router(router_destino);
		Cola<Paquetes> paquetes_nva_pag(paq_recibido.obtener_id_pagina());
		paquetes_nva_pag.encolar(paq_recibido);
		paginas_nvo_router.encolar(paquetes_nva_pagina);
		clasificador.encolar(paginas_nvo_router);
	}

}

Paquete Biblioteca_paquetes::obtener_paquete(){
	assert (("Se intenta obtener paquetes de la coleccion vacia", clasificador.tamanio()==0));
	if(clasificador.primer_elemento().obtener_duenio()==mi_router)//Si estoy en las paginas de mi router reencolo.
		clasificador.reencolar();
	Paquete paquete_envio = clasificador.primer_elemento().primer_elemento().primer_elemento();
	clasificador.primer_elemento().primer_elemento().desencolar();
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


#endif // Paquete_H

