//Personal note: tomar en cuenta el cambio de menu y el cambio de usuario
//ACTUALIZADO
#include <iostream>  //Entrada y salida en consola
#include <string>   //Permite el uso de strings
#include <vector>   //Permite el uso de vectores sin necesidad de inicializar los nodos desde cero
#include <algorithm>
using namespace std;

//declarar define para la contrasena
#define PASSWORD "2darray"

//Enumeracion del menu
enum mainCourse{pizza, pasta, lasagna};
enum drink{icedTea, soda, beer};
enum food{garlicBread, cheeseSticks, pizzaRolls};
enum paymentType{cash, card};

//Registro de direccion
struct address{
    string street, state, city;
    int houseNumber;
};
typedef struct address Address;

//Registro de informacion general para los pedidos
struct mainInfo
{
    string name;
    mainCourse pCourse;
    drink pDrink;
    food pFood;
    paymentType pay;
    int idOrder;
    float bill;
};
typedef struct mainInfo MainInfo;

//Registro para pedidos a domicilio
struct TakeOut
{
    address deliveryAddress;
    int cellphone;
    mainInfo deliveryInfo;
    int finishedOrders;
};
typedef struct TakeOut Delivery;

//Registro para pedidos en el restaurante
struct houseOrder
{
    int pTable;
    mainInfo houseInfo;
    int finishedOrders;
};
typedef struct houseOrder Restaurant;

//Vector Delivery
vector <Delivery> aDelivery;
//Vector Restaurant
vector <Restaurant> aRestaurant;

//Prototipo de funcion para usuario
bool logInUser(void);
//Prototipo de funcion de menu
void showMenu(void);
//Prototipo en el restaurante
void restaurant();
//Prototipo a domicilio
void domicilio();
//Prototipo de pedidos a domicilio
void showOrders();
//Prototipo de pedidos en el restaurante
void showInOrders();
//Funcion tiempo de espera a domicilio
void showTime(Delivery, int aux);
//Funcion tiempo de espera en restaurante
void showTime(Restaurant, int aux);
//Funcion de despacho de ordenes a domicilio
void packOffDelivery();
//Funcion de despacho de ordenes en el restaurante
void packOffHouse();
//Funcion para cancelar ordenes
void cancel();


//variables globales
bool isAdmin = false;
int idOrder = 1;
int aux, numOrders;
float pricePizza = 13.99, pricePasta = 5.55, priceLasagna = 6.25;
float priceGarlicBread = 3.99, pricePizzaRolls = 4.99, priceCheeseSticks = 3.75;
float priceSoda = 0.95, priceBeer = 1.99, priceIcedTea = 1.15;


//Inicio del programa
int main(){

    int option = 0;

   if (logInUser() == false){
       return 0;
   }
    
    bool continuar = true;
    do{
        
        int opcion = 0;
        showMenu();
        cin>>opcion;
        cin.ignore();
        
        switch(opcion){

			 case 1: domicilio() ; break;    //Revisar los parametros
			 case 2: restaurant(); break;
			 case 3: showOrders(); break;
			 case 4: showInOrders(); break;
			 case 5: packOffDelivery(); break;
			 case 6: packOffHouse(); break;
	//		 case 7: showTime(aDelivery, aux); break;
	//		 case 8: showTime(aRestaurant, aux); break;
//			 case 9: cancel(); break;   //Esta solo la va a poder ver el admnistrador 
//			 case 10: totalSales(); break;
//			 case 11: changeUser(); break;
//			 case 12: continuar = false;
        }
    }while(option != 12);


    return 0;
    }



bool logInUser(void){
    string Enterpassword = "";
    char option;
    cout << "************INICIO DE SESION************" << endl;
    cout << "Ingrese como Administrador(A) o Empleado(E): " << endl;
    cin >> option;
    cin.ignore();

    switch (option){
    case 'a':
    case 'A':
        cout << "Ingrese la contraseña: ";
        cin >> Enterpassword;
        if (Enterpassword.compare(PASSWORD) == 0){
            isAdmin = true;
            return true;
        }
        else{
            cout << "Contraseña incorrecta" << endl;
        }
        break;

    case 'e':
    case 'E':
       if(isAdmin = false){
       return true;
        break;
    }
    return false;
    }
  }

   void showMenu(void)
{
    cout << "******SISTEMA DE DESPACHO PIZZERIA TAVERN******" << endl;
    cout << "1. Agregar ordenes a domicilio" << endl;
    cout << "2. Agregar ordenes en restaurante" << endl;
    cout << "3. Ver ordenes a domicilio" << endl;
    cout << "4. Ver ordenes en restaurante" << endl;
    cout << "5. Despachar ordenes a domicilio" << endl;
    cout << "6. Despachar ordenes en restaurante" << endl;
    cout << "7. Ver tiempo de espera a domicilio" << endl;
    cout << "8. Ver tiempo de espera en restaurante" << endl;
    cout << "9. Cancelar una orden" << endl;
    cout << "10. Calcular el total de ventas" << endl;
    cout << "11. Cambiar de usuario" << endl;
    cout << "12. Salir" << endl;
    cout << "Digite su opcion: " << endl;
}

//Funcion En restaurante
void restaurant(){ 
    Restaurant order;
    //Recorre todo el arreglo
    for(int i = 0; i < aRestaurant.size(); i++){ 
         int aux = 0;
        cout << "Nombre: "; getline(cin, order.houseInfo.name);

        cout << "Entrada" << endl;
        cout << "1. Pan con ajo";
        cout << priceGarlicBread << endl;
        cout << "2. Pizza rolls";
        cout << pricePizzaRolls << endl;
        cout << "3. Palitos de queso";
        cout << priceCheeseSticks << endl;
        cout << "Su opcion: "; cin >> aux;
        cin.ignore();

        if(aux == 1)
            order.houseInfo.pFood = garlicBread;
        else if(aux == 2)
            order.houseInfo.pFood = pizzaRolls;
        else
            order.houseInfo.pFood = cheeseSticks;

        cout << "Plato principal" << endl;
        cout << "1. Pizza";
        cout << pricePizza << endl;
        cout << "2. Pasta ";
        cout << pricePasta << endl;
        cout << "3. Lasagna";
        cout << priceLasagna << endl;
        cout << "Su opcion:\t"; cin >> aux;
        cin.ignore();

        if(aux == 1)
            order.houseInfo.pCourse = pizza;
        else if(aux == 2)
            order.houseInfo.pCourse = pasta;
        else
            order.houseInfo.pCourse = lasagna;

        cout << "Bebida" << endl;
        cout << "1. Cerveza";
        cout << priceBeer << endl;
        cout << "2. Soda";
        cout << priceSoda << endl;
        cout << "3. Te helado";
        cout << priceIcedTea << endl;
        cout << "Su opcion:\t"; cin >> aux;
        cin.ignore();

        if(aux == 1)
            order.houseInfo.pDrink = beer;
        else if(aux == 2)
            order.houseInfo.pDrink = soda;
        else
            order.houseInfo.pDrink = icedTea;

        order.houseInfo.idOrder = idOrder++;
        
        cout << "Tipo de pago" << endl;
        cout << "1. Tarjeta" << endl;
        cout << "2. Efectivo" << endl;
        cout << "Su opcion:\t"; cin >> aux;
        cin.ignore();

        if(aux == 1)
            order.houseInfo.pay = card;
        else
            order.houseInfo.pay = cash;

        cout << "Monto: $"; cin >> order.houseInfo.bill;
        cin.ignore();

        aRestaurant.insert(aRestaurant.end(), order);

    }
}

//Funcion a domicilio
void domicilio(){
    Delivery order;
    int aux;
    
    //Recorre todo el arreglo
    for(int i = 0; i < aDelivery.size(); i++){ 
    cout << "Nombre de la persona que realizo el pedido: ";
    getline(cin, order.deliveryInfo.name); 
    cout << "Direccion: "; 
    cout << "Colonia: "; 
    getline(cin, order.deliveryAddress.street); cout << endl; 
    cout << "Municipio: "; 
    getline(cin, order.deliveryAddress.city); cout << endl; 
    cout << "Departamento: "; 
    cout << "No. casa: ";
    cin >> order.deliveryAddress.houseNumber;
    cin.ignore();
    getline(cin, order.deliveryAddress.state); cout << endl; 
    cout << "Numero de telefono: ";  
    cin >> order.cellphone; cout << endl;
    //Toda la informacion se guarda en el arreglo

    
    cout << "Entrada" << endl;
        cout << "1. Pan con Ajo"; 
        cout << priceGarlicBread << endl;
        cout << "2. Palitos de queso";
        cout << priceCheeseSticks << endl;
        cout << "3. PIzza rolls";
        cout << pricePizzaRolls << endl;
        cout << "ingrese su opcion: ";
        cin >> aux;

        //Guarda la opcion en el arreglo
        if(aux == 1)
            order.deliveryInfo.pFood = garlicBread;
        else if(aux == 2)
            order.deliveryInfo.pFood = pizzaRolls;
        else
            order.deliveryInfo.pFood = cheeseSticks;

        cout << "Plato principal" << endl;
        cout << "1. Pizza";
        cout << pricePizza << endl;
        cout << "2. Pasta";
        cout << pricePasta << endl;
        cout << "3. Lasagna";
        cout << priceLasagna << endl;
        cout << "Su opcion:\t"; cin >> aux;
        cin.ignore();

        //Guarda la opcion en el arreglo
        if(aux == 1)
            order.deliveryInfo.pCourse = pizza;
        else if(aux == 2)
            order.deliveryInfo.pCourse = pasta;
        else
            order.deliveryInfo.pCourse = lasagna;

        cout << "Bebida" << endl;
        cout << "1. Cerveza";
        cout << priceBeer << endl;
        cout << "2. Soda";
        cout << priceSoda << endl;
        cout << "3. Te helado";
        cout << priceIcedTea << endl;
        cout << "Su opcion:\t"; cin >> aux;
        cin.ignore();

        //Guarda la opcion del cliente dentro del arreglo
        if(aux == 1)
            order.deliveryInfo.pDrink = beer;
        else if(aux == 2)
            order.deliveryInfo.pDrink = soda;
        else
            order.deliveryInfo.pDrink = icedTea;

        order.deliveryInfo.idOrder = idOrder++;
        
        cout << "Tipo de pago" << endl;
        cout << "1. Tarjeta" << endl;
        cout << "2. Efectivo" << endl;
        cout << "Su opcion:\t"; cin >> aux;
        cin.ignore();

        if(aux == 1)
            order.deliveryInfo.pay = card;
        else
            order.deliveryInfo.pay = cash;

        cout << "Monto: $"; cin >> order.deliveryInfo.bill;
        cin.ignore();

         aDelivery.insert(aDelivery.end(), order);
    }
}

//Funcion mostrar pedidos a domicilio

void showOrders(){
    for(int i = 0; i < aDelivery.size(); i++){
        cout << aDelivery[i].deliveryInfo.name << endl; 
        cout << aDelivery[i].deliveryInfo.pCourse << endl;  
         cout << aDelivery[i].deliveryInfo.pDrink << endl;
          cout << aDelivery[i].deliveryInfo.pFood << endl;
    }
}

//Funcion mostrar pedidos en el restaurante
void showInOrders(){
    for(int i = 0; i < aRestaurant.size(); i++){
        cout << aRestaurant[i].houseInfo.name << endl;
        cout << aRestaurant[i].houseInfo.pCourse << endl;
        cout << aRestaurant[i].houseInfo.pDrink << endl;
        cout << aRestaurant[i].houseInfo.pFood << endl;
     } 
}

//Funcion tiempo de espera a domicilio

void showTime(Delivery, int aux){
    int suma = 0;
    for(Delivery aux : aDelivery){    //foreach solo se puede usar en vectores, accede a un elemento del vector
                                     //sin tener que recorrer todo el vector

        suma += (aux.deliveryInfo.pCourse * 1.5 + aux.deliveryInfo.pFood * 1.10 + aux.deliveryInfo.pDrink * 1.35) + 15;
        cout << "El tiempo de espera de su orden es de " << suma << endl;

    }
}

//Funcion tiempo de espera en el restaurante
void showTime(Restaurant, int aux){
    int suma = 0;
    for(Restaurant aux : aRestaurant){
        suma += (aux.houseInfo.pCourse * 1.5 + aux.houseInfo.pFood * 1.10 + aux.houseInfo.pDrink * 1.35);
        cout << "El tiempo de espera de su orden es de " << suma << endl;

    }
}

//Funcion de despacho de ordenes a domicilio
void packOffDelivery(){
    string orderName;

    cout << "Ingrese el nombre de la orden a despachar: "; 
    getline(cin, orderName); 
    for(auto iter = aDelivery.begin(); iter != aDelivery.end(); ++iter){
        if(iter->deliveryInfo.name== orderName){
            iter = aDelivery.erase(iter);
            cout << "La orden ha sido despachada.\n";
            break;
            }   

    cout << "Pedidos actuales: ";
    for (int i = 0; i < aDelivery.size(); i++){ 
        cout << aDelivery[i].deliveryInfo.name << "  "; 
        }
    }
}

//Funcion de despacho de ordenes en el restaurante
void packOffHouse(){
    string orderName;

    cout << "Ingrese el nombre de la orden a despachar: "; 
    getline(cin, orderName); 
    for(auto iter = aRestaurant.begin(); iter != aRestaurant.end(); ++iter){
        if(iter->houseInfo.name== orderName){
            iter = aRestaurant.erase(iter);
            cout << "La orden ha sido despachada.\n";
            break;
            }   

    cout << "Pedidos actuales: ";
    for (int i = 0; i < aRestaurant.size(); i++){ 
        cout << aRestaurant[i].houseInfo.name << "  "; 
        }
    }
}

//Funcion para cancelar una orden
void cancel(){
    
}


        