#include "Biblioteca_paquetes.h"
Biblioteca_paquetes::Biblioteca_paquetes(int mi_rout)
	:clasificador(), mi_router(mi_rout){}

Biblioteca_paquetes::~Biblioteca_paquetes(){
	//delete &clasificador;
}

int Biblioteca_paquetes::agregar_paquete(Paquete paq_recibido){
	if(clasificador.tamanio()>0){
		for(int i=0 ; i<clasificador.tamanio() ; i++){
			if(clasificador.elemento_pos(i).obtener_duenio()==router_destino){
				for(int j=0 ; j < clasificador.elemento_pos(i).tamanio() ; j++){
					if(clasificador.elemento_pos(i).elemento_pos(j)==paq_recibido.obtener_id_pagina()){
						clasificador.elemento_pos(i).elemento_pos(j).encolar(paq_recibido);
						if(paq_recibido.obtener_ip_comp_destino[0]==mi_router && paq_recibido.obtener_tamanio_pagina()==clasificador.elemento_pos(i).elemento_pos(j).tamanio()){
							//ordeno y elimino la categoría de la página completada;
							vector<int> vec_desordenado(clasificador.elemento_pos(i).elemento_pos(j).tamanio());
							int k=0;
							while(k<clasificador.elemento_pos(i).elemento_pos(j).tamanio()){
								vec_desordenado[k]=clasificador.elemento_pos(i).elemento_pos(j).elemento_pos(k).obtener_orden();
								vec_ordenado[k]=k;
								k++;
							}
							//vector<int> vec_ordenado=vec_desordenado;//voy cargando en mi vector desordenado los ordenes de los paquetes de la cola.
							//vec_ordenado.sort();
							//ordena la cola de paquetes.
							for(int l=0; l<vec_des.size(); l++){
								for(int m=0; m<vec_ord.size(); m++){
									if(vec_des[l]==vec_ord[m]){
										clasificador.elemento_pos(i).elemento_pos(j).intercambiar_pos_nodos(l,m);
									}
								}
							}
							clasificador.elemento_pos(i).quitar_nodo_pos(j);
							return 1;
						}
						else{
							return 0;
						}
					}
					else{
						Cola<Paquetes> paquetes_nva_pag(paq_recibido.obtener_id_pagina());
						paquetes_nva_pag.encolar(paq_recibido);
						clasificador.elemento_pos(i).encolar(paquetes_nva_pag);
						return 0;
					}
				}
			}
			else{
				Cola<Cola<Paquetes> > paginas_nvo_router(router_destino);
				Cola<Paquetes> paquetes_nva_pag(paq_recibido.obtener_id_pagina());
				paquetes_nva_pag.encolar(paq_recibido);
				paginas_nvo_router.encolar(paquetes_nva_pagina);
				clasificador.encolar(paginas_nvo_router);
				return 0;
			}
		}
	}
	else{
		Cola<Cola<Paquetes> > paginas_nvo_router(router_destino);
		Cola<Paquetes> paquetes_nva_pag(paq_recibido.obtener_id_pagina());
		paquetes_nva_pag.encolar(paq_recibido);
		paginas_nvo_router.encolar(paquetes_nva_pagina);
		clasificador.encolar(paginas_nvo_router);
		return 0;
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
