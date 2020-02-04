//Personal note: TIEMPOOOOO DEL INT TIME WEEY

#include <iostream>  //Entrada y salida en consola
#include <string>    //Permite el uso de strings
#include <vector>    //Permite el uso de vectores sin necesidad de inicializar los nodos desde cero
#include <algorithm> //Permite usar funciones disenadas para vectores o listas como el for_each
#include <cmath>     //Permite usar el ceiling
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
    vector<mainCourse> pCourse;
    vector<drink> pDrink;
    vector<food> pFood;
    paymentType pay;
    int idOrder;
    float bill;
    int time;
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
vector<Delivery> aDelivery, aux1;
//Vector Restaurant
vector<Restaurant> aRestaurant, aux2;

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
float totalSales(int op, int pos);
//Prototipo de funcion para ver total de ventas en restaurante
float TotalSales(int op, int pos);
//Prototipo de cambio de usuario
bool changeUser();

//variables globales
bool isAdmin = false;
int idOrder = 1;
int aux, numOrders;
float cont;
float pricePizza = 13.99, pricePasta = 5.55, priceLasagna = 6.25;
float priceGarlicBread = 3.99, pricePizzaRolls = 4.99, priceCheeseSticks = 3.75;
float priceSoda = 0.95, priceBeer = 1.99, priceIcedTea = 1.15;

//Inicio del programa
int main()
{

    int op = 0;
    char aux;

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
            if (!isAdmin) //Si no se accede como administrador
                cout << "No se puede acceder a esta opcion, te me cuidas" << endl;
            else
            {
                cancel(); //Esta solo la va a poder ver el admnistrador
            }
            break;
        case 10:
            cout << "Desea ver el total de ventas en restaurante o a domicilio? (1 = domicilio y 2 = restaurante)\t";
            cin >> op;
            cin.ignore();
            if (op == 1)
            {
                totalSales(op, 1);
            }
            else
            {
                TotalSales(op, 1);
            }

            break;
        case 11:
            logInUser();
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
        isAdmin = false;
        return true;
        break;
    }
    return false;
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
    cout << "Cantidad de personas en la mesa?\t";
    cin >> order.pTable;
    cin.ignore();
    cout << endl;

    do
    {
        cout << "Entrada" << endl;
        cout << "1. Pan con ajo\t";
        cout << priceGarlicBread << endl;
        cout << "2. Pizza rolls\t";
        cout << pricePizzaRolls << endl;
        cout << "3. Palitos de queso\t";
        cout << priceCheeseSticks << endl;
        cout << "0. Salir" << endl;
        cout << "Su opcion: ";
        cin >> aux;
        cin.ignore();

        if (aux == 0)
            break;

        aux--;

        order.houseInfo.pFood.push_back(food(aux));

    } while (aux != 0);

    do
    {
        cout << "Plato principal" << endl;
        cout << "1. Pizza\t";
        cout << pricePizza << endl;
        cout << "2. Pasta\t";
        cout << pricePasta << endl;
        cout << "3. Lasagna\t";
        cout << priceLasagna << endl;
        cout << "0. Salir" << endl;
        cout << "Su opcion:\t";
        cin >> aux;
        cin.ignore();

        if (aux == 0)
            break;

        aux--;

        order.houseInfo.pCourse.push_back(mainCourse(aux));

    } while (aux != 0);

    do
    {
        cout << "Bebida" << endl;
        cout << "1. Cerveza\t";
        cout << priceBeer << endl;
        cout << "2. Soda\t";
        cout << priceSoda << endl;
        cout << "3. Te helado\t";
        cout << priceIcedTea << endl;
        cout << "0. Salir" << endl;
        cout << "Su opcion:\t";
        cin >> aux;
        cin.ignore();

        if (aux == 0)
            break;

        aux--;

        order.houseInfo.pDrink.push_back(drink(aux));

    } while (aux != 0);

    order.houseInfo.idOrder = idOrder++;

    cout << "Tipo de pago" << endl;
    cout << "1. Tarjeta" << endl;
    cout << "2. Efectivo" << endl;
    cout << "Su opcion:\t";
    cin >> aux;
    cin.ignore();
    aux--;

    order.houseInfo.pay.push_back(paymentType(aux));

    cout << "Monto: $";
    cin >> order.houseInfo.bill;
    cin.ignore();

    order.houseInfo.time += (order.houseInfo.pCourse * 1.5 + order.houseInfo.pFood * 1.10 + order.houseInfo.pDrink * 1.35);
    cout << "El tiempo que se tarda es de " << order.houseInfo.time << " minutos.";

    aRestaurant.push_back(order);
}

//Funcion a domicilio
void domicilio()
{
    Delivery order;
    int auxFood = 0;
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

    do
    {
        cout << "Entrada" << endl;
        cout << "1. Pan con Ajo\t"; //display prices

        cout << "2. Palitos de queso\t";

        cout << "3. PIzza rolls\t";
        cout << "0. Salir\t";

        cout << "ingrese su opcion: \t";
        cin >> aux;

        if (aux == 0)
            break;

        aux--;

        order.deliveryInfo.pFood.push_back(food(aux));

    } while (aux != 0);

    do
    {

        cout << "Plato principal" << endl;
        cout << "1. Pizza\t";
        cout << pricePizza << endl;
        cout << "2. Pasta\t";
        cout << pricePasta << endl;
        cout << "3. Lasagna\t";
        cout << priceLasagna << endl;
        cout << "0. Salir" << endl;
        cout << "Su opcion:\t";
        cin >> aux;
        cin.ignore();

        if (aux == 0)
            break;

        aux--;

        order.deliveryInfo.pCourse.push_back(mainCourse(aux));

    } while (aux != 0);

    do
    {
        cout << "Bebida" << endl;
        cout << "1. Cerveza\t";
        cout << priceBeer << endl;
        cout << "2. Soda\t";
        cout << priceSoda << endl;
        cout << "3. Te helado\t";
        cout << priceIcedTea << endl;
        cout << "0. Salir" << endl;
        cout << "Su opcion:\t";
        cin >> aux;
        cin.ignore();

        if (aux == 0)
            break;

        aux--;

        order.deliveryInfo.pDrink.push_back(drink(aux));

    } while (aux != 0);

    order.deliveryInfo.idOrder = idOrder++;

    cout << "Tipo de pago" << endl;
    cout << "1. Tarjeta" << endl;
    cout << "2. Efectivo" << endl;

    cout << "Su opcion:\t";
    cin >> aux;
    cin.ignore();
    aux--;

    order.deliveryInfo.pay.push_back(paymentType(aux));

    cout << "Monto: $";
    cin >> order.deliveryInfo.bill;
    cin.ignore();

    order.deliveryInfo.time += (order.deliveryInfo.pCourse * 1.5 + order.deliveryInfo.pFood * 1.10 + order.deliveryInfo.pDrink * 1.35);
    cout << "El tiempo que se tarda es de " << order.deliveryInfo.time << " minutos.";

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
    { //foreach solo se puede usar en vectores, accede a un elemento del vector
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
    int i = 0;
    for (auto iter = aDelivery.begin(); iter != aDelivery.end(); ++iter)
    {
        if (iter->deliveryInfo.name == orderName)
        {
            aux1.push_back(aDelivery.at(i));
            iter = aDelivery.erase(iter);
            cout << "La orden ha sido despachada.\n";
            break;
        }

        cout << "Pedidos actuales: ";
        for (int i = 0; i < aDelivery.size(); i++)
        {
            cout << aDelivery[i].deliveryInfo.name << "  ";
        }
        cout << endl;
        i++;
    }
}

//Funcion de despacho de ordenes en el restaurante
void packOffHouse()
{
    string orderName;

    cout << "Ingrese el nombre de la orden a despachar: ";
    getline(cin, orderName);
    int i = 0;
    for (auto iter = aRestaurant.begin(); iter != aRestaurant.end(); ++iter)
    {
        if (iter->houseInfo.name == orderName)
        {
            aux2.push_back(aRestaurant.at(i));
            iter = aRestaurant.erase(iter);
            cout << "La orden ha sido despachada.\n";
            break;
        }

        cout << "Pedidos actuales: ";
        for (int i = 0; i < aRestaurant.size(); i++)
        {
            cout << aRestaurant[i].houseInfo.name << "  ";
        }
        cout << endl;
    }
}

// Funcion para cancelar una orden
void cancel()
{
    int option;
    int ID;
    int confirm;
    bool found = true;

    cout << "Desea cancelar una orden en restaurante o a domicilio? (1 = restaurante y 2 = domicilio)\t";
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
//Esto se arregla con tres funciones extra de fors para ir recorriedno los vectores de comida, bebida y entrada
//A la funcion de ventas le vas a sumar cada funcion extra que hiciste mas la llamada recursiva de totalSales, same shit para la otra
float totalSales(int op, int pos)
{
    float sub = 0;

    if (pos == aux1.size())
        return 0;
    else
    {
        switch (aux1[pos].deliveryInfo.pCourse)
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
        switch (aux1[pos].deliveryInfo.pFood)
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
        switch (aux1[pos].deliveryInfo.pDrink)
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
        return sub + totalSales(op, pos + 1) + ((sub + totalSales(op, pos + 1)) * 0.13);
    }
}

//Funciion total de ventas en restaurante
float TotalSales(int op, int pos)
{
    float sub = 0;
    if (pos == aux2.size())
        return 0;
    else
    {
        switch (aux2[pos].houseInfo.pCourse)
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
        switch (aux2[pos].houseInfo.pFood)
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
        switch (aux2[pos].houseInfo.pDrink)
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
        return sub + totalSales(op, pos + 1) + ((sub + totalSales(op, pos + 1)) * 0.13);
    }
}
