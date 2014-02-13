#include <iostream>
#include <sstream>
#include "Administrador.h"


using namespace std;
int main(int argc, char **argv)
{
	Administrador admin;
	cout<<endl<<BOLD_CYAN<<" +-+-+-+-+-+-+-+ +-+-+-+-+-+"<<ANSI_COLOR_RESET<<"    ----------------------------------"<<endl;
	cout<<BOLD_CYAN<<" |T|R|A|B|A|J|O| |F|I|N|A|L|"<<ANSI_COLOR_RESET<<"    final_AyED 2014:                  "<<endl; 
	cout<<BOLD_CYAN<<" +-+-+-+-+-+-+-+ +-+-+-+-+-+"<<ANSI_COLOR_RESET<<"    Simulación del Tráfico de Paquetes"<<endl;
	cout<<BOLD_BLUE<<"              _______ _____"<<ANSI_COLOR_RESET<<"   	en una Red de Routers.            "<<endl;
	cout<<BOLD_BLUE<<"   /\\        (_______|___  \\"<<ANSI_COLOR_RESET<<"  	Autores:    Esteban Morales       "<<endl;
	cout<<BOLD_BLUE<<"  /  \\  _   _ _____   _   \\ \\"<<ANSI_COLOR_RESET<<" 	            Adelina Mayol         "<<endl;
	cout<<BOLD_BLUE<<" / /\\ \\| | | |  ___) | |   | |"<<ANSI_COLOR_RESET<<"	            Guillermo Valetti     "<<endl;
	cout<<BOLD_BLUE<<"| |__| | |_| | |_____| |__/ /"<<ANSI_COLOR_RESET<<" 	Repositorio:                      "<<endl;
	cout<<BOLD_BLUE<<"|______|\\__  |_______)_____/"<<ANSI_COLOR_RESET<<"  	github.com/Andresteve07/FINAL_AyED"<<endl;
	cout<<BOLD_BLUE<<"       (____/"<<ANSI_COLOR_RESET<<BOLD_MAGENTA<<" FEBRERO 2014"<<ANSI_COLOR_RESET<<"     	__________________________________"<<endl<<endl;


	cout<<BOLD_GREEN<<"Configure la RED que desea simular modificando el archivo conf.txt que se encuentra en el mismo directorio que el ejecutable."<<endl;
	cout<<"Cuando termine presione ENTER."<<ANSI_COLOR_RESET<<endl;
	cin.get();
	admin.leer_archivo();
	admin.probar_conf();
	admin.dibujar_grafo();
	cout<<BOLD_GREEN<<"Ingrese la cantidad de pasos a simular y presione ENTER. (Si se presiona enter sin especificar la cantidad de pasos se simulará un único paso.)"<<ANSI_COLOR_RESET<<endl;
	int comando=0;
	while (true) {
		cin>>comando;
		if(comando>0){
			if(comando==1){
				cout<<BOLD_GREEN<<ANSI_COLOR_BRIGHT<<"SIMULACIÓN DE UN PASO"<<ANSI_COLOR_RESET<<endl;
				admin.simular_un_paso(true);
			}
			else{
				cout<<BOLD_GREEN<<ANSI_COLOR_BRIGHT<<"SIMULACIÓN DE "<<comando<<" PASOS."<<ANSI_COLOR_RESET<<endl;
				admin.simular_cant_pasos(comando);
			}
		}
		else{
			cout<<BOLD_GREEN<<ANSI_COLOR_BRIGHT<<"SIMULACIÓN TERMINADA"<<ANSI_COLOR_RESET<<endl;
			break;
		}
			
	}
	return 0;
}
