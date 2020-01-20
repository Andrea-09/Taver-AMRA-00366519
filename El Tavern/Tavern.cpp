//*Usar arreglos dinamicos para almacenar la cantidad de ordenes. Hecho.
// *un número único y correlativo en el que las órdenes se realizan. 
// *Agregar al menú principal una opción para buscar una orden 
//  según el nombre de la persona que la realizó.  Hecho, o algo asi.
//Personal note: Faltan hacer unas funciones, por eso el menu tiene error. 

#include <iostream>
#include <string>
using namespace std;

struct Address{
    int houseNumber;
    string street, city, state;
};

struct TakeOut{
    string name, address, food, mainCourse, drinks, TypePayment;
    int phoneNumber;
    Address personalAddress;
};

struct AttheTavern{
    string nameReservations, food, mainCourse, drinks, TypeofPayment;
    int peoplePertable;
};


//Prototipo de funcion de menu
void mainMenu();
//Prototipo de contrasenia
int password();
//Prototipo en el restaurante
void restaurant();
//Prototipo a domicilio
void domicilio();
//Prototipo de pedidos a domicilio
void showOrders(int* B, int numOrdenes);
//Prototipo de pedidos en el restaurante
void showInOrders(int* A, int numOrdenes);
//Prototipo de mostrar ventas
void showSales(int* A, int* B);
//Prototipo buscar ordenes
void searchOrder(int* A, int* B);

string user;
AttheTavern info;
TakeOut add;
int* A, B;
int numOrders;

int main(){

    cout << "\t\t\t\t LOGIN USUARIO" << endl;
    cout << "\t\t\t\t ---------------" << endl;
    cout << "Ingresar como Empleado o Administrador: ";
    getline(cin, user);

    // Al comparar cadenas de texto van entre comillas dobles " ", al comparar caracteres van entre comillas simples ' '
    if( user == "administrador" || "Administrador"){
        // El comando return intenta retornar lo que retorna la funcion password
        // La funcion password es void entonces no puede devolver nada, entonces el return termina la ejecucion del programa
        return password();
        cout << "Bienvenido" << endl;
        // No se puede mandar a llamar a una funcion sin los parentesis(), misma observacion con el return
    
        mainMenu();

    return 0;
}


//Agregar contraseña
int password();{
    int aux; 
    for(int i = 0; i < 7; i++){ 
    char pssw[7] = {'2','d','a','r','r','a','y'};
cout << "Ingrese la contrasena: ";
// pssw es un arreglo que almacena la contraseña correcta, si el cin se hace a esa posicion
// 1. Da error porque no se puede hacer cin a un arreglo sin indicar posicion
// 2. Se pierde el dato de la contraseña correcta
// Recomendacion: usar arreglo auxiliar
cin >> pssw[i];
if(pssw == "2darray"){
        // pssw es un arreglo, no se puede comparar con una cadena
      cout << "\nAcceso concedido \n";
   }else{
      cout << "\nAcceso denegado...\n";
        }
    }
}
//pss: 2darray

//Funcion En restaurante
// Segun la logica implementada, recibir A esta de mas
void restaurant(){ 
    cout << "Numero de ordenes a ingresar: "; cin >> numOrders;
    A = new int[numOrders];

    for(int i = 0; i < numOrders; i++){ 
    cout << "Ingrese el nombre de la persona que realizo la reserva: ";
    getline(cin, info.nameReservations[i]); cout << endl;
    cout << "Cantidad de personas por mesa?";  cin >> info.peoplePertable[i]; cout << endl;
    cout << "Por favor eliga un plato principal entre pizza, ensalada o pasta: "; cin >> info.mainCourse[i];  cout << endl;
    cout << "Por favor eliga entre nuestras entradas de quesadillas o nachos: "; cin >> info.food[i]; cout << endl;
    cout << "Por favor eliga entre gaseosa o té: "; cin >> info.drinks[i]; cout << endl;
    cout << "Su total a pagar es de $22.75" << endl;
    cout << "Ingrese su forma de pago: ";
    cin >> info.TypeofPayment[i];
    }
}

//Funcion a domicilio
// Segun la logica implementada, recibir B esta de mas
void domicilio(){
    cout << "Numero de ordenes a ingresar: "; cin >> numOrders;
    B = new int[numOrders];

    for(int i = 0; i < numOrders; i++){ }
    cout << "Nombre de la persona que realizo el pedido: ";
    getline(cin, add.name[i]); cout << endl;
    cout << "Direccion: ";  
    getline(cin, add.personalAddress.address[i]); cout << endl; 
    cout << "Numero de telefono: ";  
    cin >> add.phoneNumber[i]; cout << endl;
    cout << "Por favor eliga un plato principal entre pizza, ensalada o pasta: "; cin >> add.food[i];  cout << endl;
    cout << "Por favor eliga entre nuestras entradas de quesadillas o nachos: "; cin >> add.mainCourse[i]; cout << endl;
    cout << "Por favor eliga entre gaseosa o té: "; cin >> add.drinks[i]; cout << endl;
    cout << "Su total a pagar es de $28.25" << endl;
    cout << "Ingrese su forma de pago: ";
    cin >> add.TypePayment[i];
    }
}

//Funcion mostrar pedidos a domicilio
void showOrders(int* B, int numOrdenes){
    for(int i = 0; i < numOrders; i++){
        cout << B[i] << endl;
    }
}

//Funcion mostrar pedidos en el restaurante
void showInOrders(int* A, int numOrdenes){
    for(int i = 0; i < numOrders; i++){
        cout << A[i] << endl;
    }
}

//Funcion mostrar las ventas
void showSales(int* A, int* B){

}

//Funcion buscar ordenes
void searchOrder(int* A, int* B){
    for(int i = 0; i < numOrders; i++){
        cout << "Pedidos en el restaurante";
        cout << info.nameReservations[i] << endl;
        cout << "Pedidos a domicilio";
        cout << add.name[i] << endl;

    }
}

//Funcion Menu
void mainMenu(){

bool continuar = true;
    do{
        int opcion = 0;
cout<<"\n\t\t\t\t*************************";
cout<<"\n\t\t\t\t El Tavern ";
cout<<"\n\t\t\t\t      * MENU PRINCIPAL *";
cout<<"\n\t\t\t\t*************************";
cout<<"\n\n\n\t\t\t1.Agregar pedido a domicilio";
cout<<"\n\t\t\t2.Agegar encargo en restaurante";
cout<<"\n\t\t\t3.Ver pedidos";
cout<<"\n\t\t\t4.Ver encargos";
cout<<"\n\t\t\t5.Ver total de ventas";
cout<<"\n\t\t\t6.Buscar orden";
cout<<"\n\t\t\t7.Salir";
cout<<"\n\n\t\t\tElija una opcion: ";
cin>>opcion;
        cin.ignore();
        
        switch(opcion){
            switch(opcion){

 case 1: domicilio(); break;

 case 2: restaurant(); break;

 case 3: showOrders(B, numOrders); break;

 case 4: showInOrders(A, numOrders); break;

 case 5: showSales(A, B); break;

 case 6: searchOrder(A, B); break;

 case 7: continuar = false;
        }
    }while(continuar){ ;

        }
    
