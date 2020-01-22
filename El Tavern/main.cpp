#include <iostream>
#include <string>
using namespace std;

//declara define
#define PASSWORD "2darray"

enum mainCourse
{
    pizza,
    pasta,
    lasgna
};
enum drink
{
    te,
    soda,
    agua
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

struct address
{
    string street, state, city;
    int houseNumber;
};

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

struct delivery
{
    address deliveryAddress;
    int cellphone;
    mainInfo deliveryInfo;
};

struct houseOrder
{
    int pTable;
    mainInfo houseInfo;
};

//variables globales
bool isAdmin = false;
int idOrder = 1;
//prototipos
bool logInUser(void);

//Inicio
int main(void)
{
    delivery *dArray = NULL;
    houseOrder *hArray = NULL;
    int option = 0;

    //if(logInUser())              //if(logInUser() == true)
    if (logInUser() == false)
    { //if(!logInUser())
        return 0;
    }

    do
    { //logica principal para iniciar el programa (menu)
        showMenu();
        cin >> option;
        cin.ignore();

        switch (option)
        {
        //Agregar ordem a domicilio
        case 1:
            addOrder(dArray);
            break;
        //orden en restaurante
        case 2:
            addOrder(hArray);
            break;
        //
        case 3:
            break;
        case 4:
            break;
        }

    } while (option != 0);

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
    cout << "SISTEMA DE DESPACHO PIZZERIA TAVERN" << endl;
    cout << "1. Agregar ordenes a domicilio" << endl;
    cout << "2. Agregar ordenes en restaurante" << endl;
    cout << "3. Ver ordenes a domicilio" << endl;
    cout << "4. Ver ordenes en restaurante" << endl;
    cout << "Digite su opcion: " << endl;
}

void addOrder(delivery *array)
{
    int numOrders = 0;
    cout << "Cantidad de pedidos a ingresar: ";
    cin >> numOrders;
    cin.ignore();
    array = new delivery[numOrders];

    for (int i = 0; i < numOrders; i++)
    {
        int aux;
        cout << "Ingrese el nombre del cliente: ";
        getline(cin, array[i].deliveryInfo.name);
        cout << "Ingrese la direccion: " << endl;
        cout << "Colonia: ";
        getline(cin, array[i].deliveryAddress.street);
        cout << "Municipio: ";
        getline(cin, array[i].deliveryAddress.city);
        cout << "Departamento: ";
        getline(cin, array[i].deliveryAddress.state);
        cout << "No. casa: ";
        cin >> array[i].deliveryAddress.houseNumber;
        cin.ignore();

        cout << "Entrada" << endl;
        cout << "1. Pan con Ajo" << endl;
        cout << "2. Palis" << endl;
        cout << "3. PIzza rolls" << endl;
        cout << "ingrese su opcion: ";
        cin >> aux;

        //Esro te ahorra todo el despije de los ifs
        //aux--;
        //array[i].deliveryInfo.pCourse = aux;
        //

        if (aux == 1)
        {
            array[i].deliveryInfo.pFood = garlicBread;
        }
        else if
        {
            array[i].deliveryInfo.pFood = ;
        }
        else
        {
            array[i].deliveryInfo.pFood = Agua;
        }
    }

    cout << "Plato principal" << endl;
    cout << "1. Pizza" << endl;
    cout << "2. Pasta" << endl;
    cout << "3. Lasagna" << endl;
    cout << "ingrese su opcion: ";
    cin >> aux;

    //Esro te ahorra todo el despije de los ifs
    //aux--;
    //array[i].deliveryInfo.pCourse = aux;
    //

    if (aux == 1)
    {
        array[i].deliveryInfo.pCourse = pizza;
    }
    else if
    {
        array[i].deliveryInfo.pCourse = pasta;
    }
    else
    {
        array[i].deliveryInfo.pCourse = lasagna;
    }

    cout << "Bebida" << endl;
    cout << "1. Te" << endl;
    cout << "2. Soda" << endl;
    cout << "3. Agua" << endl;
    cout << "ingrese su opcion: ";
    cin >> aux;

    //Esro te ahorra todo el despije de los ifs
    //aux--;
    //array[i].deliveryInfo.pCourse = aux;
    //

    if (aux == 1)
    {
        array[i].deliveryInfo.pDrink = Te;
    }
    else if
    {
        array[i].deliveryInfo.pDrink = Soda;
    }
    else
    {
        array[i].deliveryInfo.pDrink = Agua;
    }

    array[i].deliveryInfo.idOrder = idOrder++;

    cout << "Tipo de pago" << endl;
    cout << "1. Efectivo" << endl;
    cout << "2. Tarjeta" << endl;
    cout << "ingrese su opcion: ";
    cin >> aux;
    cin.ignore();

    if (aux == 1)
    {
        array[i].deliveryInfo.pay = cash;
    }
    else
    {
        array[i].deliveryInfo.pay = card;
    }

    cout << "Monto a pagar: ";
    cin >> array[i].deliveryInfo.bill;

    void searchByName(delivery * array, int numOrders)
    {
        bool userExists = false;
        string aux = "";
        cout << "Nombre a buscar: " getline(cin, aux);

        for (int i = 0; i < numOrders; i++)
        {
            if (aux.compare(array[i].deliveryInfo.name) == 0)
            {
                //Imprimir datos
                userExists = true;
            }
        }
        (!userExists) ? cout << "No existe el usuario" : cout << ""
    }
}

//HOuse
void addOrder(houseOrder *array)
{
    int aux;
    int numOrders = 0;
    cout << "Cantidad de pedidos a ingresar: ";
    cin >> numOrders;
    cin.ignore();
    array = new houseOrder[numOrders];

    for (int i = 0; i < numOrders; i++)
    {
        int aux;

        cout << "Entrada" << endl;
        cout << "1. Pan con Ajo" << endl;
        cout << "2. Palis" << endl;
        cout << "3. PIzza rolls" << endl;
        cout << "ingrese su opcion: ";
        cin >> aux;

        //Esro te ahorra todo el despije de los ifs
        //aux--;
        //array[i].deliveryInfo.pCourse = aux;
        //

        if (aux == 1)
        {
            array[i].houseInfo.pFood = garlicBread;
        }
        else if
        {
            array[i].houseInfo.pFood = cheeseSticks;
        }
        else
        {
            array[i].houseInfo.pFood = pizzaRolls;
        }
    }

    cout << "Plato principal" << endl;
    cout << "1. Pizza" << endl;
    cout << "2. Pasta" << endl;
    cout << "3. Lasagna" << endl;
    cout << "ingrese su opcion: ";
    cin >> aux;

    //Esro te ahorra todo el despije de los ifs
    //aux--;
    //array[i].deliveryInfo.pCourse = aux;
    //

    if (aux == 1)
    {
        array[i].deliveryInfo.pCourse = pizza;
    }
    else if
    {
        array[i].deliveryInfo.pCourse = pasta;
    }
    else
    {
        array[i].deliveryInfo.pCourse = lasagna;
    }

    cout << "Bebida" << endl;
    cout << "1. Te" << endl;
    cout << "2. Soda" << endl;
    cout << "3. Agua" << endl;
    cout << "ingrese su opcion: ";
    cin >> aux;

    //Esro te ahorra todo el despije de los ifs
    //aux--;
    //array[i].deliveryInfo.pCourse = aux;
    //

    if (aux == 1)
    {
        array[i].deliveryInfo.pDrink = Te;
    }
    else if
    {
        array[i].deliveryInfo.pDrink = Soda;
    }
    else
    {
        array[i].deliveryInfo.pDrink = Agua;
    }

    array[i].deliveryInfo.idOrder = idOrder++;

    cout << "Tipo de pago" << endl;
    cout << "1. Efectivo" << endl;
    cout << "2. Tarjeta" << endl;
    cout << "ingrese su opcion: ";
    cin >> aux;
    cin.ignore();

    if (aux == 1)
    {
        array[i].deliveryInfo.pay = cash;
    }
    else
    {
        array[i].deliveryInfo.pay = card;
    }

    cout << "Monto a pagar: ";
    cin >> array[i].mainInfo.bill;

    void searchByName(houseOrder * array, int numOrders)
    {
        bool userExists = false;
        string aux = "";
        cout << "Nombre a buscar: " getline(cin, aux);

        for (int i = 0; i < numOrders; i++)
        {
            if (aux.compare(array[i].houseInfo.name) == 0)
            {
                //Imprimir numero de personas en la mesa
                userExists = true;
            }
        }
        (!userExists) ? cout << "No existe el usuario" : cout << ""
    }
}
