//      Lista doblemente enlazada
//Dado un conjunto de Códigos de Producto (numérico) y Precios Unitarios que finalizan con un 0,
//generar una Lista ordenada por Código de Producto con dichos valores e imprimirla en orden creciente y decreciente.
//Nota: resolverlo de 2 maneras
//-Primero generando la lista en orden creciente con InsertaOrdenado y luego a medida que la imprime irla descolgando de la lista y apilándola en una Pila que luego imprimirá.
//-Generando una lista doblemente enlazada que la genera en orden creciente mediante InsertaOrdenado, la recorre hacia un lado para imprimirla con un orden, y en el otro sentido para imprimirla con el otro orden.


#include <iostream>
using namespace std;

struct TProd {
   int codP;
   float PU;
};

struct Nodo {
   Nodo* ant;
   TProd Info;
   Nodo* sig;
};

void insertaOrdenado(Nodo* &lista, TProd RInfo){
   Nodo* pNue = new Nodo();
   pNue -> Info = RInfo;
   if((lista==NULL) || (pNue -> Info.codP < lista -> Info.codP)){
      pNue -> sig = lista;
      pNue -> ant = NULL;
      if (lista != NULL)
           lista -> ant = pNue; //engancho el ant del que era 1er nodo con el nuevo
      lista = pNue;
   } else {
      Nodo *ptr = lista;
      Nodo *antP;
      while((ptr != NULL) && (pNue -> Info.codP > ptr -> Info.codP)){
         antP = ptr;
         ptr = ptr -> sig;
      }
      antP -> sig = pNue;
      pNue -> ant = antP;
      pNue -> sig = ptr;
      if (ptr != NULL)
        ptr -> ant = pNue; //salvo que quede como �ltimo nodo, quedaba enlazar el ant de ptr con el nuevo
   }
}

void EliminaPrimero(Nodo* &lista, TProd &RInfo){
   Nodo *ptr = lista;
   RInfo = ptr -> Info;
   lista = lista -> sig;
   delete ptr;
}

int main() {
   TProd RProd;
   Nodo *lista = NULL;
   Nodo *ptr;
   Nodo *antp;

   cout << "Ingrese un Codigo de producto" << endl;
   cin >> RProd.codP;
   while(RProd.codP != 0){
      cout << "Ingrese un precio unitario" << endl;
      cin >> RProd.PU;
      insertaOrdenado(lista, RProd);
      cout << "Ingrese un Codigo de producto" << endl;
      cin >> RProd.codP;
   }

   cout << "Lista en orden Creciente de Cod de Producto"<< endl;
   cout << "CodP  PU"<< endl;
   ptr=lista;
   while (ptr!=NULL) {
      cout << " " << ptr -> Info.codP << "  -  " << ptr -> Info.PU << endl;
      antp = ptr;
      ptr = ptr -> sig;
   }
   //ahora desde el �ltimo nodo (que qued� en antp) recorro la lista hacia atr�s
   ptr = antp;
   cout << endl;
   cout << "Lista en orden Decreciente de Cod de Producto"<< endl;
   cout << "CodP  PU"<< endl;
   while (ptr!=NULL) {
      cout << " " << ptr -> Info.codP << "  -  " << ptr -> Info.PU << endl;
      ptr = ptr -> ant;
   }
}
