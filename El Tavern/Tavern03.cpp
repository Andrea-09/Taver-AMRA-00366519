//Personal note: tomar en cuenta el cambio de menu y el cambio de usuario

#include <iostream>  //Entrada y salida en consola
#include <string>    //Permite el uso de strings
#include <vector>    //Permite el uso de vectores sin necesidad de inicializar los nodos desde cero
#include <algorithm> //Permite usar funciones disenadas para vectores o listas como el for_each
using namespace std;

//declarar define para la contrasena
#define PASSWORD "2darray"

//Enumeracion del menu
enum mainCourse
{
    pizza,
    pasta,
    lasagna
};
enum drink
{
    icedTea,
    soda,
    beer
};
enum food
{
    garlicBread,
    cheeseSticks,
    pizzaRolls
};
enum paymentType
{
    cash,
    card
};

//Registro de direccion
struct address
{
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
};
typedef struct TakeOut Delivery;

//Registro para pedidos en el restaurante
struct houseOrder
{
    int pTable;
    mainInfo houseInfo;
};
typedef struct houseOrder Restaurant;

//Vector Delivery
vector<Delivery> aDelivery;
//Vector Restaurant
vector<Restaurant> aRestaurant;

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
//Prototipo de funcion tiempo de espera a domicilio
void showTime(vector<Delivery> aDelivery);
//Prototitpo de funcion tiempo de espera en restaurante
void showTime(vector<Restaurant> aRestaurant);
//Prototipo de funcion de despacho de ordenes a domicilio
void packOffDelivery();
//Prototitpo de funcion de despacho de ordenes en el restaurante
void packOffHouse();
//Prototipo de funcion para cancelar ordenes
void cancel();
//Prototipo de funcion para ver el total de ventas
float totalSales();
//Prototipo de menu de empleado
void showMenuE();
//Prototipo de cambio de usuario
bool changeUser();

//variables globales
bool isAdmin = false;
int idOrder = 1;
int aux, numOrders;
float pricePizza = 13.99, pricePasta = 5.55, priceLasagna = 6.25;
float priceGarlicBread = 3.99, pricePizzaRolls = 4.99, priceCheeseSticks = 3.75;
float priceSoda = 0.95, priceBeer = 1.99, priceIcedTea = 1.15;

//Inicio del programa
int main()
{

    int option = 0;

    if (logInUser() == false)
    {
        return 0;
    }
    bool continuar = true;

    do
    {

        int opcion = 0;
        showMenu();
        cin >> opcion;
        cin.ignore();

        switch (opcion)
        {

        case 1:
            domicilio();
            break;
        case 2:
            restaurant();
            break;
        case 3:
            showOrders();
            break;
        case 4:
            showInOrders();
            break;
        case 5:
            packOffDelivery();
            break;
        case 6:
            packOffHouse();
            break;
        case 7:
            showTime(aDelivery);
            break;
        case 8:
            showTime(aRestaurant);
            break;
        case 9:
            cancel();
            break; //Esta solo la va a poder ver el admnistrador
        case 10:
            totalSales();
            break;
        case 11:
            changeUser();
            break;
        case 12:
            continuar = false;
        }
    } while (continuar);

    return 0;
}

bool logInUser(void)
{
    string Enterpassword = "";
    char option;
    cout << "************INICIO DE SESION************" << endl;
    cout << "Ingrese como Administrador(A) o Empleado(E): " << endl;
    cin >> option;
    cin.ignore();

    switch (option)
    {
    case 'a':
    case 'A':
        cout << "Ingrese la contraseña: ";
        cin >> Enterpassword;
        if (Enterpassword.compare(PASSWORD) == 0)
        {
            isAdmin = true;
            return true;
        }
        else
        {
            cout << "Contraseña incorrecta" << endl;
        }
        break;

    case 'e':
    case 'E':
        if (isAdmin == false)
        {
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
void restaurant()
{
    Restaurant order;

    int aux = 0;
    cout << "Nombre: ";
    getline(cin, order.houseInfo.name);
    cout << "Cantidad de personas? ";
    cin >> order.pTable;
    cin.ignore();
    cout << endl;

    cout << "Entrada" << endl;
    cout << "1. Pan con ajo\t";
    cout << priceGarlicBread << endl;
    cout << "2. Pizza rolls\t";
    cout << pricePizzaRolls << endl;
    cout << "3. Palitos de queso\t";
    cout << priceCheeseSticks << endl;
    cout << "Su opcion: ";
    cin >> aux;
    cin.ignore();

    if (aux == 1)
        order.houseInfo.pFood = garlicBread;
    else if (aux == 2)
        order.houseInfo.pFood = pizzaRolls;
    else
        order.houseInfo.pFood = cheeseSticks;

    cout << "Plato principal" << endl;
    cout << "1. Pizza\t";
    cout << pricePizza << endl;
    cout << "2. Pasta\t";
    cout << pricePasta << endl;
    cout << "3. Lasagna\t";
    cout << priceLasagna << endl;
    cout << "Su opcion:\t";
    cin >> aux;
    cin.ignore();

    if (aux == 1)
        order.houseInfo.pCourse = pizza;
    else if (aux == 2)
        order.houseInfo.pCourse = pasta;
    else
        order.houseInfo.pCourse = lasagna;

    cout << "Bebida" << endl;
    cout << "1. Cerveza\t";
    cout << priceBeer << endl;
    cout << "2. Soda\t";
    cout << priceSoda << endl;
    cout << "3. Te helado\t";
    cout << priceIcedTea << endl;
    cout << "Su opcion:\t";
    cin >> aux;
    cin.ignore();

    if (aux == 1)
        order.houseInfo.pDrink = beer;
    else if (aux == 2)
        order.houseInfo.pDrink = soda;
    else
        order.houseInfo.pDrink = icedTea;

    order.houseInfo.idOrder = idOrder++;

    cout << "Tipo de pago" << endl;
    cout << "1. Tarjeta" << endl;
    cout << "2. Efectivo" << endl;
    cout << "Su opcion:\t";
    cin >> aux;
    cin.ignore();

    if (aux == 1)
        order.houseInfo.pay = card;
    else
        order.houseInfo.pay = cash;

    cout << "Monto: $";
    cin >> order.houseInfo.bill;
    cin.ignore();

    aRestaurant.push_back(order);
}

//Funcion a domicilio
void domicilio()
{
    Delivery order;
    int aux;

    cout << "Nombre de la persona que realizo el pedido: ";
    getline(cin, order.deliveryInfo.name);
    cout << "Direccion " << endl;
    cout << "Colonia: ";
    getline(cin, order.deliveryAddress.street);
    cout << endl;
    cout << "Municipio: ";
    getline(cin, order.deliveryAddress.city);
    cout << endl;
    cout << "Departamento: ";
    getline(cin, order.deliveryAddress.state);
    cout << endl;
    cout << "No. casa: ";
    cin >> order.deliveryAddress.houseNumber;
    cin.ignore();
    cout << "Numero de telefono: ";
    cin >> order.cellphone;
    cout << endl;
    //Toda la informacion se guarda en el arreglo

    cout << "Entrada" << endl;
    cout << "1. Pan con Ajo\t";
    cout << priceGarlicBread << endl;
    cout << "2. Palitos de queso\t";
    cout << priceCheeseSticks << endl;
    cout << "3. PIzza rolls\t";
    cout << pricePizzaRolls << endl;
    cout << "ingrese su opcion: \t";
    cin >> aux;

    //Guarda la opcion en el arreglo
    if (aux == 1)
        order.deliveryInfo.pFood = garlicBread;
    else if (aux == 2)
        order.deliveryInfo.pFood = pizzaRolls;
    else
        order.deliveryInfo.pFood = cheeseSticks;

    cout << "Plato principal" << endl;
    cout << "1. Pizza\t";
    cout << pricePizza << endl;
    cout << "2. Pasta\t";
    cout << pricePasta << endl;
    cout << "3. Lasagna\t";
    cout << priceLasagna << endl;
    cout << "Su opcion:\t";
    cin >> aux;
    cin.ignore();

    //Guarda la opcion en el arreglo
    if (aux == 1)
        order.deliveryInfo.pCourse = pizza;
    else if (aux == 2)
        order.deliveryInfo.pCourse = pasta;
    else
        order.deliveryInfo.pCourse = lasagna;

    cout << "Bebida" << endl;
    cout << "1. Cerveza\t";
    cout << priceBeer << endl;
    cout << "2. Soda\t";
    cout << priceSoda << endl;
    cout << "3. Te helado\t";
    cout << priceIcedTea << endl;
    cout << "Su opcion:\t";
    cin >> aux;
    cin.ignore();

    //Guarda la opcion del cliente dentro del arreglo
    if (aux == 1)
        order.deliveryInfo.pDrink = beer;
    else if (aux == 2)
        order.deliveryInfo.pDrink = soda;
    else
        order.deliveryInfo.pDrink = icedTea;

    order.deliveryInfo.idOrder = idOrder++;

    cout << "Tipo de pago" << endl;
    cout << "1. Tarjeta" << endl;
    cout << "2. Efectivo" << endl;
    cout << "Su opcion:\t";
    cin >> aux;
    cin.ignore();

    if (aux == 1)
        order.deliveryInfo.pay = card;
    else
        order.deliveryInfo.pay = cash;

    cout << "Monto: $";
    cin >> order.deliveryInfo.bill;
    cin.ignore();

    aDelivery.push_back(order);
}

//Funcion mostrar pedidos a domicilio

void showOrders()
{
    for (int i = 0; i < aDelivery.size(); i++)
    {
        cout << "Nombre: " << aDelivery[i].deliveryInfo.name << endl;
        cout << "Plato principal: " << aDelivery[i].deliveryInfo.pCourse << endl;
        cout << "Bebida: " << aDelivery[i].deliveryInfo.pDrink << endl;
        cout << "Aperitivo: " << aDelivery[i].deliveryInfo.pFood << endl;
        cout << "Tipo de pago: " << aDelivery[i].deliveryInfo.pay << endl;
        cout << "Monto a pagar: $" << aDelivery[i].deliveryInfo.bill << endl;
        cout << "Numero de orden: " << aDelivery[i].deliveryInfo.idOrder << endl;
    }
}

//Funcion mostrar pedidos en el restaurante
void showInOrders()
{
    for (int i = 0; i < aRestaurant.size(); i++)
    {
        cout << "Nombre: " << aRestaurant[i].houseInfo.name << endl;
        cout << "Cantidad de personas en la mesa: " << aRestaurant[i].pTable << endl;
        cout << "Plato principal: " << aRestaurant[i].houseInfo.pCourse << endl;
        cout << "Bebida: " << aRestaurant[i].houseInfo.pDrink << endl;
        cout << "Aperitivo: " << aRestaurant[i].houseInfo.pFood << endl;
        cout << "Tipo de pago: " << aRestaurant[i].houseInfo.pay << endl;
        cout << "Monto a pagar: $" << aRestaurant[i].houseInfo.bill << endl;
        cout << "Numero de orden: " << aRestaurant[i].houseInfo.idOrder << endl;
    }
}

//Ambas funciones para mostrar el tiempo estan sobrecargadas

//Funcion tiempo de espera a domicilio
void showTime(vector<Delivery> aDelivery)
{
    int suma = 0;
    Delivery aux;
    for (Delivery aux : aDelivery)
    {   //foreach solo se puede usar en vectores, accede a un elemento del vector
        //sin tener que recorrer todo el vector

        suma += (aux.deliveryInfo.pCourse * 1.5 + aux.deliveryInfo.pFood * 1.10 + aux.deliveryInfo.pDrink * 1.35) + 15;
        cout << "El tiempo de espera de su orden es de " << suma << " minutos." << endl;
    }
}

//Funcion tiempo de espera en el restaurante
void showTime(vector<Restaurant> aRestaurant)
{
    Restaurant aux;
    int suma = 0;
    for (Restaurant aux : aRestaurant)
    {
        suma += (aux.houseInfo.pCourse * 1.5 + aux.houseInfo.pFood * 1.10 + aux.houseInfo.pDrink * 1.35);
        cout << "El tiempo de espera de su orden es de " << suma << " minutos." << endl;
    }
}

//Funcion de despacho de ordenes a domicilio
void packOffDelivery()
{
    string orderName;

    cout << "Ingrese el nombre de la orden a despachar: ";
    getline(cin, orderName);
    for (auto iter = aDelivery.begin(); iter != aDelivery.end(); ++iter)
    {
        if (iter->deliveryInfo.name == orderName)
        {
            iter = aDelivery.erase(iter);
            cout << "La orden ha sido despachada.\n";
            break;
        }

        cout << "Pedidos actuales: ";
        for (int i = 0; i < aDelivery.size(); i++)
        {
            cout << aDelivery[i].deliveryInfo.name << "  ";
        }
    }
}

//Funcion de despacho de ordenes en el restaurante
void packOffHouse()
{
    string orderName;

    cout << "Ingrese el nombre de la orden a despachar: ";
    getline(cin, orderName);
    for (auto iter = aRestaurant.begin(); iter != aRestaurant.end(); ++iter)
    {
        if (iter->houseInfo.name == orderName)
        {
            iter = aRestaurant.erase(iter);
            cout << "La orden ha sido despachada.\n";
            break;
        }

        cout << "Pedidos actuales: ";
        for (int i = 0; i < aRestaurant.size(); i++)
        {
            cout << aRestaurant[i].houseInfo.name << "  ";
        }
    }
}

// Funcion para cancelar una orden
void cancel()
{
    int option;
    int ID;
    int confirm;
    bool found = true;

    cout << "Desea cancelar una orden en restaurante o a domicilio (1 = restaurante y 2 = domicilio)\t";
    cin >> option;
    cin.ignore();
    cout << endl;

    if (option == 1)
    {
        cout << "Ingrese el ID de la orden que desea eliminar: ";
        cin >> ID;
        cin.ignore();
        cout << endl;
        for (int i = 0; i < aRestaurant.size(); i++)
        {
            if (aRestaurant[i].houseInfo.idOrder == ID)
            {
                found = true;
                cout << "Desea eliminar esta orden? (1 = si, 2 = no)\n";
                cin >> confirm;
                cin.ignore();
                if (confirm == 1)
                {
                    for (auto iter = aRestaurant.begin(); iter != aRestaurant.end(); ++iter)
                    {
                        if (iter->houseInfo.idOrder == ID)
                        {
                            iter = aRestaurant.erase(iter);
                            cout << "La orden ha sido eliminada.\n";
                            break;
                        }
                    }
                }
            }
        }
        if (found == false)
        {
            cout << "No se encontro la orden.\n";
        }
    }

    else if (option == 2)
    {
        cout << "Ingrese el ID de la orden que desea eliminar: ";
        cin >> ID;
        cin.ignore();
        cout << endl;
        for (int i = 0; i < aDelivery.size(); i++)
        {
            if (aDelivery[i].deliveryInfo.idOrder == ID)
            {
                found = true;
                cout << "Desea eliminar esta orden? (1 = si, 2 = no)\n";
                cin >> confirm;
                cin.ignore();
                if (confirm == 1)
                {
                    for (auto iter = aDelivery.begin(); iter != aDelivery.end(); ++iter)
                    {
                        if (iter->deliveryInfo.idOrder == ID)
                        {
                            iter = aDelivery.erase(iter);
                            cout << "La orden ha sido eliminada.\n";
                            break;
                        }
                    }
                }
            }
        }
    }
    if (found == false)
    {
        cout << "No se encontro la orden.\n";
    }
}

//Funcion recursiva para ver el total de ventas

float totalSales(int op, int pos)
{
    float sub = 0;

    if (pos == aDelivery.size())
        return 0;
    else
    {
        switch (aDelivery[0].deliveryInfo.pCourse)
        {
        case pizza:
            sub += 13.99;
            break;
        case pasta:
            sub += 5.55;
            break;
        case lasagna:
            sub += 6.25;
            break;
        }
        switch (aDelivery[0].deliveryInfo.pFood)
        {
        case garlicBread:
            sub += 3.99;
            break;
        case cheeseSticks:
            sub += 3.75;
            break;
        case pizzaRolls:
            sub += 4.99;
            break;
        }
        switch (aDelivery[0].deliveryInfo.pDrink)
        {
        case icedTea:
            sub += 1.15;
            break;
        case soda:
            sub += 0.95;
            break;
        case beer:
            sub += 1.99;
            break;
        }

        return sub + llamada rec(op, pos + 1);
    }

    if (option == 1)
    {
        if (aDelivery.empty())
        {
            return 0;
        }
        else
        {
            switch (aDelivery[0].deliveryInfo.pFood)
            {
            case pizza:
                sub = 13.99;
                break;
            case pasta:
                sub = 5.55;
                break;
            case lasagna:
                sub = 6.25;
                break;
            }
            switch (pFood)
            {
            case garlicBread:
                sub = 3.99;
                break;
            case cheeseSticks:
                sub = 3.75;
                break;
            case pizzaRolls:
                sub = 4.99;
                break;
            }
            switch (pDrink)
            {
            case icedTea:
                sub = 1.15;
                break;
            case soda:
                sub = 0.95;
                break;
            case beer:
                sub = 1.99;
                break;
            }
            return sub + totalSales(); //Agregar el 13% de IVA
        }
    }

    else if (option == 2)
    {
        if (aRestaurant.size())
        {
            return 0;
        }
        else
        {
            switch (dish)
            {
            case pizza:
                sub = 13.99;
                break;
            case pasta:
                sub = 5.55;
                break;
            case lasagna:
                sub = 6.25;
                break;
            }
            switch (pFood)
            {
            case garlicBread:
                sub = 3.99;
                break;
            case cheeseSticks:
                sub = 3.75;
                break;
            case pizzaRolls:
                sub = 4.99;
                break;
            }
            switch (pDrink)
            {
            case icedTea:
                sub = 1.15;
                break;
            case soda:
                sub = 0.95;
                break;
            case beer:
                sub = 1.99;
                break;
            }
        }
        return sub + totalSales(); //Falta agregar el 13% de IVA
    }
}

//Muestra el menu que vera el empleado
void showMenuE()
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
    cout << "9. Calcular el total de ventas" << endl;
    cout << "10. Cambiar de usuario" << endl;
    cout << "11. Salir" << endl;
    cout << "Digite su opcion: " << endl;
}

//Funcion cambiar de usuario
bool changeUser()
{
    string Enterpassword = "";
    char opt;
    int option = 0;

    cout << "Desea cambiar de usuario? (1 = si, 2 = no)\n";
    cin >> option;
    cin.ignore();
    if (option == 1)
    {
        cout << "Ingrese a que usuario le gustaria cambiar: ";
        cin >> opt;
        cin.ignore();
        switch (opt)
        {
        case 'a':
        case 'A':
            cout << "Ingrese la contraseña: ";
            cin >> Enterpassword;
            if (Enterpassword.compare(PASSWORD) == 0)
            {
                isAdmin = true;
                return true;
            }
            else
            {
                cout << "Contraseña incorrecta" << endl;
            }
            break;

        case 'e':
        case 'E':
            if (isAdmin == false)
            {
                return true;
                break;
            }
            return false;
        }
    }
    else
    {
        return 0;
    }
}
