#include <iostream>
#include <string.h>
 
using namespace std;
 
struct prod {
    int cod;
    int stk;
};
 
struct nodo {
    prod info;
    nodo* sig; 
};
 
void espacio(int cantidadEspacios) {
    for (int i = 1; i<= cantidadEspacios; i++){
        cout << "" << endl;
    }
}
 
int main()
{
    prod producto;
    nodo* lista = NULL;
    nodo* pnue;
    cout << "Codigo? " << endl;
    cin >> producto.cod;
    while (producto.cod != 0)
    {
        cout << "Stock?" << endl;
        cin >> producto.stk;
        //agregar nodo
        pnue = new nodo();
        pnue -> info = producto;
        if (lista == NULL || lista -> info.cod > pnue -> info.cod)
        {
            pnue -> sig = lista;
            lista = pnue;
        }else{
            nodo* ptr = lista;
            while (ptr -> sig != NULL && ptr -> sig -> info.cod < pnue -> info.cod)
            {
                ptr = ptr -> sig; 
            }
            pnue -> sig = ptr -> sig;
            ptr -> sig = pnue;
        }
        espacio(1);
        cout << "Codigo? " << endl;
        cin >> producto.cod;
    }
    espacio(2);
    cout << "Producto?" << endl;
    cin >> producto.cod;
    while (producto.cod != 0)
    {
        nodo* ptr = lista;
        nodo* prod;
        bool esta = false;
        while (ptr != NULL && ptr -> info.cod != producto.cod)
        {   
            ptr = ptr -> sig;  
        }
        if (ptr == NULL){
            cout << "El producto no existe" << endl;
        }else{
            prod = ptr;
            cout << "Cantidad?" << endl;
            cin >> producto.stk;
            if (producto.stk > prod -> info.stk)
            {
                cout << "No hay stock suficiente" << endl;
            }else{
                prod -> info.stk -= producto.stk;
                cout << "Se vendieron " << producto.stk << " unidades" << endl;
            }
        }
        cout << "Producto?" << endl;
        cin >> producto.cod;
    }
    /*
    //Borrar primer nodo
    if (lista == NULL){
        cout << "No hay valores en la lista" << endl;
    }else{
        nodo* temp;
        temp = lista;
        lista = lista -> sig;
        delete temp;
        espacio(1);
        cout << temp -> info.nombre << " <-- Valor borrado" << endl; //Para ver que da basura :D
    }
    */
    //Mostrar nodos
    if (lista == NULL)
    {
        espacio(1);
        cout << "No hay valores en la lista" << endl;
    }else{
        nodo* ptr2;
        while (lista != NULL)
        {   
            ptr2 = lista;
            espacio(1);
            cout << "Codigo: " << ptr2 -> info.cod << endl; 
            cout << "Stock: " << ptr2 -> info.stk << endl;
            lista = lista -> sig;  
            delete ptr2; 
        }
        
    }   
