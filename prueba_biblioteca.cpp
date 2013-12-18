#include <iostream>
#include "Biblioteca_paquetes.h"
#include "Biblioteca_paquetes.cpp"
#include "Paquete.h"
#include "Paquete.cpp"
using namespace std;
int main(){
	Biblioteca_paquetes bltk1(100);
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			for(int k=0;k<3;k++){
				int arreglo[2]={i,666};
				std::vector<int> ip_og(arreglo,arreglo+sizeof(arreglo)/sizeof(arreglo[0]));
				int arreglo2[2]={i+1,666}; //DESTINO Router 2 - Pc 20
				std::vector<int> ip_dt(arreglo2,arreglo2+sizeof(arreglo2)/sizeof(arreglo2[0]));
				Paquete paq(ip_og,ip_dt,j,3,k);
				bltk1.agregar_paquete(paq);
			}
		}
	}
	
	cout<<"-----------------------------------------------------------"<<endl;
	bltk1.imprimir();
	cout<<"-----------------------------------------------------------"<<endl;
	for(int m=0;m<27;m++){
		bltk1.obtener_paquete().imprimir();
	}
	return 0;
}
