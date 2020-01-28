#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//declara define
#define PASSWORD "2darray"

enum mainCourse{pizza, pasta, lasagna};
enum drink{icedTea, soda, beer};
enum food{garlicBread, cheeseSticks, pizzaRolls};
enum paymentType{cash, card};

//Registro de direccion
struct address{
    string street, state, city;
    int houseNumber;
};
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
//Registro para pedidos a domicilio
struct TakeOut
{
    address deliveryAddress;
    int cellphone;
    mainInfo deliveryInfo;
    int finishedOrders;
};
//Registro para pedidos en el restaurante
struct houseOrder
{
    int pTable;
    mainInfo houseInfo;
    int finishedOrders;
};

vector <houseOrder> Restaurant;
vector <TakeOut> Delivery;


//variables globales
bool isAdmin = false;
int idOrder = 1;
int aux, numOrders;
float pricePizza = 13.99, pricePasta = 5.55, priceLasagna = 6.25;
float priceGarlicBread = 3.99, pricePizzaRolls = 4.99, priceCheeseSticks = 3.75;
float priceSoda = 0.95, priceBeer = 1.99, priceIcedTea = 1.15;
TakeOut.finishedOrders = 0; //Revisar el contador
houseOrder.finishedOrders = 0;  //Revisar el contador 


//Prototipo de funcion para usuario
bool logInUser(void);
//Prototipo de funcion de menu
void showMenu(void);
//Prototipo en el restaurante
void restaurant(houseOrder *array);
//Prototipo a domicilio
void domicilio(TakeOut *array);
//Prototipo de pedidos a domicilio
void showOrders(TakeOut *array, int numOrdenes);
//Prototipo de pedidos en el restaurante
void showInOrders(houseOrder *array, int numOrdenes);
//Funcion tiempo de espera a domicilio
int showTime(TakeOut *array, int numOrders, int aux);
//Funcion tiempo de espera en restaurante
int showTime(houseOrder *array, int numOrders, int aux);
//Prototipo de buscar una order por nombre en restaurante
void searchByName(houseOrder * array, int numOrders);
//Prototipo de buscar una order por nombre a domicilio
void searchByName(TakeOut * array, int numOrders);


int main(){

    TakeOut *dArray = NULL;
    houseOrder *hArray = NULL;
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

 case 1: domicilio(dArray); break;
 case 2: restaurant(hArray); break;
 case 3: showOrders(dArray, numOrders); break;
 case 4: showInOrders(hArray, numOrders); break;
 case 5: packOffDelivery(); break;
 case 6: packOffHouse(); break;
 case 7: showTime(dArray, numOrders, 0); break;
 case 8: showTime(hArray, numOrders, 0); break;
 case 9: searchByName(hArray, numOrders); break;
 case 10: searchByName(dArray, numOrders); break;
 case 11: cancel(); break;   //Esta solo la va a poder ver el admnistrador 
 case 12: totalSales(); break;
 case 13: changeUser(); break;
 case 14: continuar = false;
        }
    }while(option != 0);


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
    cout << "SISTEMA DE DESPACHO PIZZERIA TAVERN" << endl;
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
void restaurant(houseOrder *array){ 
    houseOrder aux;
    cout << "Numero de ordenes a ingresar: "; cin >> numOrders;
    array = new houseOrder[numOrders];

    //Recorre todo el arreglo
    for(int i = 0; i < numOrders; i++){ 
         int aux = 0;
        cout << "Nombre: "; getline(cin, array[i].houseInfo.name);

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
            array[i].houseInfo.pFood = garlicBread;
        else if(aux == 2)
            array[i].houseInfo.pFood = pizzaRolls;
        else
            array[i].houseInfo.pFood = cheeseSticks;

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
            array[i].houseInfo.pCourse = pizza;
        else if(aux == 2)
            array[i].houseInfo.pCourse = pasta;
        else
            array[i].houseInfo.pCourse = lasagna;

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
            array[i].houseInfo.pDrink = beer;
        else if(aux == 2)
            array[i].houseInfo.pDrink = soda;
        else
            array[i].houseInfo.pDrink = icedTea;

        array[i].houseInfo.idOrder = idOrder++;
        
        cout << "Tipo de pago" << endl;
        cout << "1. Tarjeta" << endl;
        cout << "2. Efectivo" << endl;
        cout << "Su opcion:\t"; cin >> aux;
        cin.ignore();

        if(aux == 1)
            array[i].houseInfo.pay = card;
        else
            array[i].houseInfo.pay = cash;

        cout << "Monto: $"; cin >> array[i].houseInfo.bill;
        cin.ignore();

       


    }
}

//Funcion a domicilio
void domicilio(TakeOut *array){
    int aux;
    cout << "Numero de ordenes a ingresar: "; cin >> numOrders;
    array = new TakeOut[numOrders];

    //Recorre todo el arreglo
    for(int i = 0; i < numOrders; i++){ 
    cout << "Nombre de la persona que realizo el pedido: ";
    getline(cin, array[i].deliveryInfo.name); 
    cout << "Direccion: "; 
    cout << "Colonia: "; 
    getline(cin, array[i].deliveryAddress.street); cout << endl; 
    cout << "Municipio: "; 
    getline(cin, array[i].deliveryAddress.city); cout << endl; 
    cout << "Departamento: "; 
    cout << "No. casa: ";
    cin >> array[i].deliveryAddress.houseNumber;
    cin.ignore();
    getline(cin, array[i].deliveryAddress.state); cout << endl; 
    cout << "Numero de telefono: ";  
    cin >> array[i].cellphone; cout << endl;
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
            array[i].deliveryInfo.pFood = garlicBread;
        else if(aux == 2)
            array[i].deliveryInfo.pFood = pizzaRolls;
        else
            array[i].deliveryInfo.pFood = cheeseSticks;

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
            array[i].deliveryInfo.pCourse = pizza;
        else if(aux == 2)
            array[i].deliveryInfo.pCourse = pasta;
        else
            array[i].deliveryInfo.pCourse = lasagna;

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
            array[i].deliveryInfo.pDrink = beer;
        else if(aux == 2)
            array[i].deliveryInfo.pDrink = soda;
        else
            array[i].deliveryInfo.pDrink = icedTea;

        array[i].deliveryInfo.idOrder = idOrder++;
        
        cout << "Tipo de pago" << endl;
        cout << "1. Tarjeta" << endl;
        cout << "2. Efectivo" << endl;
        cout << "Su opcion:\t"; cin >> aux;
        cin.ignore();

        if(aux == 1)
            array[i].deliveryInfo.pay = card;
        else
            array[i].deliveryInfo.pay = cash;

        cout << "Monto: $"; cin >> array[i].deliveryInfo.bill;
        cin.ignore();
    }
}

//Funcion mostrar pedidos a domicilio
void showOrders(TakeOut *array, int numOrdenes){
    for(int i = 0; i < numOrders; i++){
        cout << array[i].deliveryInfo.name << endl;  //Cuando ya esten las colas usar size
    }
}

//Funcion mostrar pedidos en el restaurante
void showInOrders(houseOrder *array, int numOrdenes){
    for(int i = 0; i < numOrders; i++){
        cout << array[i].houseInfo.name << endl; //Esto no es asi, se debe usar la funcion size cuando ya esten las colas
    }
}

//Funcion tiempo de espera a domicilio
int showTime(TakeOut *array, int numOrders, int aux){
    if(aux == numOrders){
        return aux;
    }
    else{
        return (array[aux].deliveryInfo.pCourse * 1.5 + array[aux].deliveryInfo.pFood * 1.10 + array[aux].deliveryInfo.pDrink * 1.35) + 15;
        cout << "El total del tiempo de espera (en minutos) es: " << showTime(array, numOrders, aux + 1);
    }
}

//Funcion tiempo de espera en restaurante
int showTime(houseOrder *array, int numOrders, int aux){
    int aux;
    if(aux == numOrders){
        return aux;
    }
    else{
        return (array[aux].houseInfo.pCourse * 1.5 + array[aux].houseInfo.pFood * 1.10 + array[aux].houseInfo.pDrink * 1.35);
        cout << "El total del tiempo de espera (en minutos es): " << showTime(array, numOrders, aux + 1);
    }
}

//Funcion para buscar una orden por nombre en el restaurante
void searchByName(houseOrder * array, int numOrders){
        bool userExists = false;
        string aux = " ";
        cout << "Nombre a buscar: "; getline(cin, aux);

        for (int i = 0; i < numOrders; i++)
        {
            if (aux.compare(array[i].houseInfo.name) == 0)
            {
                //Imprimir numero de personas en la mesa
                userExists = true;
            }
        }
        (!userExists) ? cout << "No existe el usuario" : cout << " ";
    }

//Funcion para buscar una orden por nombre a domicilio
void searchByName(TakeOut * array, int numOrders){
        bool userExists = false;
        string aux = " ";
        cout << "Nombre a buscar: "; getline(cin, aux);

        for (int i = 0; i < numOrders; i++)
        {
            if (aux.compare(array[i].deliveryInfo.name) == 0)
            {
                //Imprimir numero de personas en la mesa
                userExists = true;
            }
        }
        (!userExists) ? cout << "No existe el usuario" : cout << " ";
    }


    
