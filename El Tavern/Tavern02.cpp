#include<iostream>
#include<string>
#include<queue>
using namespace std;

string contrasena = "2darray";

struct registro{
	string nombre;
	string direccion;
	int telefono;
	string platoPrincipal;
};
typedef struct registro datosP;

queue <datosP>  unaCola;

void precios(){
	float pizza = 0, ensalada = 0, pasta = 0;
	float alitas = 0, nachosChili = 0, papasFritas = 0, arosCebolla = 0;
	float soda = 0, jugo = 0, te = 0;
	
}

void listDom(){
	
	
}

void platoPrincipal(){
	char opcion;
	
	cout << "Escoga su plato principal:" << endl;
	cout << "\t1. Pizza\n\t2. Ensalada\n\t3. Pasta";
	
	switch(opcion){
		case 1: break;
		case 2: break;
		case 3: break;
	}
}

int entregaDomicilio(){
	datosP aux;
	
	cout << "Ingrese su nombre: ";
	getline(cin, aux.nombre);
	cout << "Ingrese una direccion: ";
	getline(cin, aux.direccion);
	cout << "Ingrese un telefono: ";
	cin >> aux.telefono;
	unaCola.push(aux);
}

void menuEmpleado(){
	char option;
	
	do{
		cout << "Menu" << endl;
		cout << "\ta) Agregar pedido a domicilio\n\tb) Agregar encargo a restaurante\n\tc) Ver pedidos a domicilio\n\td) Ver encargos en el restaurante\n\te) Salir";
		cout << "\nSu opcion: ";
		cin >> option;
		
		switch(option){
			case 'a': entregaDomicilio(); break;
			case 'c': listDom(); break;
		}
		cout << endl;
	}while(option != 'e');
}

void menuAdmin(){
	char option;
	
	do{
		cout << "Menu" << endl;
		cout << "\ta) Agregar pedido a domicilio\n\tb) Agregar encargo a restaurante\n\tc) Ver pedidos a domicilio\n\td) Ver encargos en el restaurante\n\te) Ver total de venta\n\tf)Borrar ordenes\n\tg) Salir ";
		cout << "\nSu opcion: ";
		cin >> option;
		
		switch(option){
			case 'a': entregaDomicilio(); break;
			case 'c': listDom(); break;
		}
		cout << endl;
	}while(option != 'g');
}

int main(){
	string clave;
	char opcion;
	
	do{
	
		cout << "Selecciones su cargo: " << endl;
		cout << "\ta) Empleado\n\tb) Administrador\n\te) Salir";
		cout << "\nSu opcion";
		cin >> opcion;
		
		switch(opcion){
			
			case 'a': menuEmpleado(); break;
			
			case 'b':
				do{
					cout << "Ingrese la contrasena: " ;
					cin >> clave;
					if (clave == contrasena){
					menuAdmin();
					}
				}while(clave != contrasena);
				
				break;
		}
	}while(opcion != 'c');
	
	
	return 0;
}

