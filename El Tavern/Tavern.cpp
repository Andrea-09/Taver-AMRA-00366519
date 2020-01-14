#include <iostream>
#include <string>
using namespace std;

struct TakeOut{
    string name;
    string adress;
    int phoneNumber;
    int payment;
    string food;
    string mainCourse;
    string drinks;
    string TypePayment;
};

struct AttheTavern{
    string nameReservations;
    int peoplePertable;
    string food;
    string mainCourse;
    string drinks;
    int payment;
    string TypeofPayment;
};

//Prototipo de funcion de menu
void showMenu();
//Prototipo de contrasenia
void constrasenia();

int main(){



    return 0;
}


//Agregar contraseña
void contrasenia(){ 
char pssw[7] = {'2','d','a','r','r','a','y'};
while(pssw[i] != 7){
    if(pssw[i]>32 && i<20)
                {
                  putchar('*');
                  i++;
                }

    }
}
//pss: 2darray
//Funcion Menu
bool continuar = true;
    do{
        int opcion = 0;
        cout << "\n1. Agregar un pedido a domicilio\n";
        cout << "2. Agregar un encargo de restaurante\n";
        cout << "3. Ver pedidos a domicilio\n";
        cout << "4. Ver encargo del restaurante\n";
        cout << "5. Ver total de venta\n";
        cout << "Opcion: ";
        cin >> opcion;
        cin.ignore();
        
        switch(opcion){
        
        
         }