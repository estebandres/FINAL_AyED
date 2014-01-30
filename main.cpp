#include <iostream>
#include <sstream>
#include "Administrador.h"
#include "Administrador.cpp"
int main(int argc, char **argv)
{
	Administrador admin;
	cout<<"Configure la RED que desea simular modificando el archivo conf.txt que se encuentra en el mismo directorio que el ejecutable."<<endl;
	cout<<"Cuando termine presione ENTER."<<endl;
	cin.get();
	admin.leer_archivo();
	admin.probar_conf();
	admin.dibujar_grafo();
	cout<<"Ingrese la cantidad de pasos a simular y presione ENTER. (Si se presiona enter sin especificar la cantidad de pasos se simulará un único paso.)"<<endl;
	int comando=0;
	while (true) {
		cin>>comando;
		if(comando>0){
			if(comando==1)
				cout<<"Simulación de un paso"<<endl;
			else
				cout<<"Simulación de "<<comando<<" pasos."<<endl;
		}
		else{
			cout<<"Simulación Terminada."<<endl;
			break;
		}
			
	}
	return 0;
}
