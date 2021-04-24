/*

                                                       REGISTRO DE INVENTARIO DE MERCANCIA DE ALIMENTOS
                                                       
    TODOS LOS REGISTROS LO ENCONTRARA EN EL DISCO LOCAL C - prueba_parcial_jose_pineda_c.i_27.549.172_4to_semestre_ing_de_sistemas_seccion_04s-2629-d1

*/

#include<iostream>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
#include<fstream>
#include<direct.h>
#include<windows.h>

using namespace std;



	string nombre;
	bool decision;
	int seleccion;
	string u[100];
	int busqueda_categoria_producto = 2;
	int busqueda_nombre_producto = 3;
	int elegir_categoria;


void lectura_registro_nombre();
void iniciar_sesion();
void registro(string nu);

int main(){ 

	mkdir("C:/BASE_DE_DATOS_REGISTRO_DE_INVENTARIO");

	
	bool d1;
	cout<<"\n  1. Iniciar sesión"<<endl;
	cout<<"\n  0. Registrarse"<<endl;
	cin>>d1;
	
		
	if(d1){
		system("cls");
		iniciar_sesion();
	}else{
		system("cls");
		cout<<"\t\n     BIENVENID@ AL REGISTRO DE USUARIO\n" "\nINGRESE SU NOMBRE POR FAVOR ";
		cin.ignore();
		getline(cin, nombre);
		
		registro(nombre);
		
		iniciar_sesion();
	
	}
	
	
	system("pause");
 	getch();
	return 0;
 }
 
 void iniciar_sesion(){
 	bool terminado=1;
 		cin.ignore();
 	while (terminado){
		
		
		cout<<"\t\n     BIENVENID@ AL REGISTRO DE MERCANCIA DE ALIMENTOS\n" "\nINGRESE SU NOMBRE POR FAVOR: ";
		bool acceder=0;
	
		getline(cin, nombre);
		system("cls");
		
	
				
		lectura_registro_nombre();
		
		
		for(int i=0; i<100;i++){
			if(nombre==u[i] && u[i]!="" ){
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
 
 
 void registro(string nu){
 	
 	ofstream usuarios;
 	
 	usuarios.open("C://registro_nombre.txt",ios::out|ios::app);
 	
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

void lectura_registro_nombre(){
	
	ifstream archivo; 
	
	archivo.open("C://registro_nombre.txt",ios::in|ios::app);
	
	if(archivo.fail()){
		
		cout<<"no se puedo leer el archivo";
		exit(1);
	}
	int contador=0;
	while(!archivo.eof()){
		
	 getline(archivo,u[contador]);

	 contador++;
	}
	archivo.close();
}
