// Dado un conjunto de Codigos de Producto (numerico) y Stock que finalizan con un Cod Producto igual a 0,
// generar una Lista ordenada por Codigo de Producto con dichos valores.
// Luego ingresar una serie de pedidos que tienen Codigo de Producto y Cantidad solicitada, y finalizan con CÃ³digos de Producto igual a 0.
// Por cada pedido indicar si se puede realizar el mismo de acuerdo al stock, y mantener actualizado el stock de los productos.
// Al final del proceso imprimir una lista con los Codigos y stock actualizado

#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

struct Producto{
    int codigo;
    int stock;
};
struct Nodo{
   Producto info;
   Nodo* sig;
};

struct Pedido{
    int codigo;
    int cantidad;
};

Nodo* insertarOrdenado(Nodo* &lista,Producto info)
{
    Nodo * pnue = new Nodo();
    pnue->info = info;

    if ( (lista == NULL) || (pnue->info.codigo < lista->info.codigo))
    {
            pnue->sig = lista;
            lista = pnue;
    }
    else
    {
        Nodo* ptr = lista;
        Nodo* ant;
        while((ptr != NULL) && (ptr->info.codigo < pnue->info.codigo))
        {
            ant = ptr;
            ptr = ptr-> sig;
        }
        pnue->sig = ptr; //Cuando el nuevo queda como último, ptr = NULL
        ant->sig=pnue;
    }
    return pnue;
}

Nodo* buscar(Nodo* lista,Pedido pedido)
{
    Nodo* ptr = lista;
    while( ptr!= NULL && ptr->info.codigo!= pedido.codigo) // ptr!= NULL siempre primero
     {
        ptr=ptr->sig;
    }
    return ptr;
}

void ingresarProductos(Nodo* &lista)
{
    Producto info;
    Nodo* ptr;

    cout << "Ingrese codigo de producto: ";
    cin >> info.codigo;

    while(info.codigo!= 0 )
    {
        cout << "Ingrese el stock: ";
        cin >> info.stock;

        ptr = insertarOrdenado(lista,info);

        cout << "Ingrese codigo de producto: ";
        cin >> info.codigo;
    }
}

void ingresaryProcesarPedidos(Nodo* &lista)
{
    Pedido pedido;
    cout << endl << "Ingrese codigo de producto: ";
    cin >> pedido.codigo;

    while(pedido.codigo!= 0 )
    {
        Nodo* encontrado = buscar(lista,pedido);

        if(encontrado == NULL)
        {
           cout << "No se encontro el codigo" << endl;
        }
           else
        {
              cout << endl << "Ingrese la cantidad: ";
              cin >> pedido.cantidad;

              if( encontrado->info.stock > pedido.cantidad)
              {
                encontrado->info.stock -= pedido.cantidad;
                cout << "Cantidad Vendida: " << pedido.cantidad << endl;
              }
              else
                cout << "No se puede realizar el pedido por falta de stock" << endl;
        }

        cout << endl << "Ingrese codigo de producto: ";
        cin >> pedido.codigo;
    }

}

void mostrar(Nodo* lista)
{
    // si la lista se recorriese por última vez,
    // lista se pasaría por referencia y adentro del ciclo se agregaría lo que se indica abajo
    cout << "Codigo de producto     " << "Stock" << endl;
    while( lista!=NULL )
    {
        cout << lista->info.codigo << "               " << lista->info.stock << endl;
        // acá se agegaría ptr = lista
        lista = lista->sig;
        // y acá delete ptr, si queremos ir liberando la lista al imprimirla por última vez
    }
}

int main()
{
    int opcion;
    Nodo* lista = NULL;

   do {
      cout << "Ingrese la opcion deseada" << endl;
      cout << "1) Ingresar Productos "  << endl;
      cout << "2) Ingresar Pedido" << endl;
      cout << "3) Imprimir lista" << endl;
      cout << "0) Salir"<<endl;
      cin >> opcion;

      switch (opcion) {
         case 0:
            cout<<"Muchas gracias por utilizar el programa"<<endl;
            break;
         case 1:
               ingresarProductos(lista);
               break;
         case 2:
               ingresaryProcesarPedidos(lista);
               break;
        case 3:
                mostrar(lista);
                break;
         default:
            cout <<"ERROR! La opcion seleccionada es invalida"<<endl;
            break;
      }
   }
   while (opcion != 0);
   return 0;
}
