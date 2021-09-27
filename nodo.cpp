#include <iostream>
#include <string.h>
 
using namespace std;
 
struct per {
    int edad;
    string nombre;
};
 
struct nodo {
    per info;
    nodo* sig; 
};
 
void espacio(int cantidadEspacios) {
    for (int i = 1; i<= cantidadEspacios; i++){
        cout << "" << endl;
    }
}
 
int main()
{
    per persona;
    nodo* pila = NULL;
    nodo* pnue;
    cout << "Edad? " << endl;
    cin >> persona.edad;
    while (persona.edad != 0)
    {
        cout << "Nombre?" << endl;
        cin >> persona.nombre;
        //agregar nodo
        pnue = new nodo();
        pnue -> info = persona;
        pnue -> sig = pila;
        pila = pnue;
        espacio(1);
        cout << "Edad? " << endl;
        cin >> persona.edad;
    }
    //Borrar primer nodo
    if (pila == NULL){
        cout << "No hay valores en la pila" << endl;
    }else{
        nodo* temp;
        temp = pila;
        pila = pila -> sig;
        delete temp;
        espacio(1);
        cout << temp -> info.nombre << " <-- Valor borrado" << endl; //Para ver que da basura :D
    }
    //Mostrar nodos
    if (pila == NULL)
    {
        espacio(1);
        cout << "No hay valores en la pila" << endl;
    }else{
        nodo* ptr;
        while (pila != NULL)
        {   
            ptr = pila;
            espacio(1);
            cout << "Edad: " << ptr -> info.edad << endl; 
            cout << "Nombre: " << ptr -> info.nombre << endl;
            pila = pila -> sig;  
            delete ptr; 
        }
    }   
}
