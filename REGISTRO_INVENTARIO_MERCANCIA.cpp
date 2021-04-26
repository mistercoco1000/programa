#include<iostream>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
#include<fstream>
#include<direct.h>
#include <winsock2.h>
#include<windows.h>
#include <locale.h>
#include <wchar.h>
#include<mysql.h>
using namespace std;

string nombre, usuario[100];
int seleccion, elegir_categoria;

class Registro_lectura{
	
	private:
		
		string registro_del_nombre;
		string lectura_del_nombre;
		
		public :
		
		Registro_lectura(string, string);
		
		void registro_nombre(string nu);
		void lectura_nombre();
	
};

Registro_lectura::Registro_lectura(string _registro_del_nombre, string _lectura_del_nombre){
	
	registro_del_nombre = _registro_del_nombre;
	
	lectura_del_nombre = _lectura_del_nombre;
	
}

void iniciar_sesion();

Registro_lectura nombres(nombre,nombre); 

int main(){
	
	bool d1;
	
	mkdir("C:/BASE_DE_DATOS_REGISTRO_DE_INVENTARIO");
	
	setlocale(LC_ALL, "");
	
	cout<<"\n  1. Iniciar sesión"<<endl;
	cout<<"\n  0. Registrarse"<<endl;
	
	cin>>d1;
	
	
	if(d1){
		
		system("cls");
		
		iniciar_sesion();
		
	}else{
		system("cls");
		
		puts("\t\n     BIENVENID@ AL REGISTRO DE USUARIO\n"); 
		fflush(stdout);
		
		cout<<"\nINGRESE SU NOMBRE POR FAVOR: ";
		
		cin.ignore();
		getline(cin, nombre);
		
		nombres.registro_nombre(nombre);
		
		iniciar_sesion();
	
	}
		
	system("pause");
	
	return 0;
}

void Registro_lectura::registro_nombre(string nu){
	
	ofstream usuarios;
 	
 	usuarios.open("C://BASE_DE_DATOS_REGISTRO_DE_INVENTARIO/registro_nombre.txt",ios::out|ios::app);
 	
 	if(usuarios.fail()){
 		
 		cout<<"NO SE PUDO Generar el archivo";
 		exit(1);
 		
 	}
 	
 	 usuarios<<nu+"\n";
 	 
 	 usuarios.close();
 	 
 	system("cls");
 	
 	cout<<"Registro exitoso";
 	
 	getch();
 	
	system("cls");
	
}

void Registro_lectura::lectura_nombre(){
	
	ifstream archivo; 
	
	archivo.open("C://BASE_DE_DATOS_REGISTRO_DE_INVENTARIO/registro_nombre.txt",ios::in|ios::app);
	
	if(archivo.fail()){
		
		cout<<"no se puedo leer el archivo";
		
		exit(1);
	}
	
	int contador=0;
	
	while(!archivo.eof()){
		
		getline(archivo,usuario[contador]);

		contador++;
	}
	
	archivo.close();
	
}

void iniciar_sesion(){
	
	 	bool terminado=1;
 		cin.ignore();
 	while (terminado){
		
		
		cout<<"\t\n     BIENVENID@ AL REGISTRO DE MERCANCIA DE ALIMENTOS\n" "\nINGRESE SU NOMBRE POR FAVOR: ";
		bool acceder=0;
	
		getline(cin, nombre);
		system("cls");
		
	
				
		nombres.lectura_nombre();
		
		
		for(int i=0; i<100;i++){
			if(nombre==usuario[i] && usuario[i]!="" ){
			 	acceder=1;
			 
				break;
			}
		}
		
		
		
		if(acceder){
		
		
		
			cout<<"\n                        BIENVENID@ " <<nombre<<endl;
		
		
		
					
					cout<<"\n 1 REGISTRAR UN PRODUCTO"<<endl; 
	
					cout<<"\n 2 BUSCAR CATEGORIA DE UN PRODUCTO"<<endl;
					cout<<"\n 3 BUSCAR NOMBRE DEL PRODUCTO"<<endl;
					cout<<endl; cin>>seleccion;
	
					switch(seleccion){
						
						case 1: cout<<"\t BIENVENIDO AL REGISTRO DE ALIMENTOS "<<endl;
			
						cout<<"\n LISTADO DE COMESTIBLES ADMINISTROS EN EL ALMACEN QUE CATEGORIA DESEA REGISTRAR ?"<<endl;
			
						cout<<"\n 1: CARNES"<<endl;
						cout<<"\n 2: CHUCHERIA"<<endl;
						cout<<"\n 3: GRANOS"<<endl;
						cout<<"\n 4: HARINAS"<<endl;
						cout<<"\n 5: GASEOSAS"<<endl;
						cout<<"\n 6: ARTICULOS DE USO PERSONAL"<<endl;
						cout<<endl; cin>>elegir_categoria;
			
						switch(elegir_categoria){
				
							case 1: 
				
							cout<<"\tQUE TIPO DE CARNE DESEA UTILIZAR?"<<endl;
						
							break; 
						}
		
						break;
		
						case 2: cout<<"es la categoria";
						break;
		
						case 3: cout<<"es el nombre";
						break; 
	
						default:	
	
						cout<<"SELECCIONES UNA DE LAS OPCIONES SEÑALADAS";
						break;
					};
					
					terminado=0;
			
			}else{
				cout<<"Usuario no reconocido";
				getch();
				system("cls");
			}
	};
	
}

