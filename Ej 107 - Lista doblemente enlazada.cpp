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
        ptr -> ant = pNue; //salvo que quede como último nodo, quedaba enlazar el ant de ptr con el nuevo
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
   //ahora desde el último nodo (que quedó en antp) recorro la lista hacia atrás
   ptr = antp;
   cout << endl;
   cout << "Lista en orden Decreciente de Cod de Producto"<< endl;
   cout << "CodP  PU"<< endl;
   while (ptr!=NULL) {
      cout << " " << ptr -> Info.codP << "  -  " << ptr -> Info.PU << endl;
      ptr = ptr -> ant;
   }
}
