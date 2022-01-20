#include <iostream>
using namespace std;

struct TProd {
   int codP;
   int Suc;
   float PU;
};

struct Nodo {
   TProd Info;
   Nodo* sig;
};

void insertaOrdenadoPorDobleClave(Nodo* &lista, TProd RInfo){
   Nodo* pNue = new Nodo();
   pNue -> Info = RInfo;
   //inserto adelante si la lista es null, si el cod es menor al 1ro
   //o si el cód es igual al 1ro siendo la Suc menor a la 1ra
   if((lista==NULL) || (pNue -> Info.codP < lista -> Info.codP)
      || ((pNue -> Info.codP = lista -> Info.codP) && (pNue -> Info.Suc < lista -> Info.Suc)) ){
      pNue -> sig = lista;
      lista = pNue;
   } else {
      Nodo *ptr = lista;
      Nodo *antP;

      //me quedo ciclando mientras el cod a insertar sea mayor al que apunto
      //o si el cód es igual y la Suc mayor a la que apunto
      while((ptr != NULL) && ( (pNue -> Info.codP > ptr -> Info.codP)
        || ((pNue -> Info.codP = ptr -> Info.codP) && (pNue -> Info.Suc > ptr -> Info.Suc)) )){
         antP = ptr;
         ptr = ptr -> sig;
      }
      antP -> sig = pNue;
      pNue -> sig = ptr;
   }
}

void ElminaPrimero(Nodo* &lista, TProd &RInfo){
   Nodo *ptr = lista;
   RInfo = ptr -> Info;
   lista = lista -> sig;
   delete ptr;
}

int main() {
   TProd RProd;
   Nodo *lista = NULL;

   cout << "Ing Codigo de producto" << endl;
   cin >> RProd.codP;
   while(RProd.codP != 0){
      cout << "Ingrese sucursal" << endl;
      cin >> RProd.Suc;
      cout << "Ingrese precio unitario" << endl;
      cin >> RProd.PU;
      insertaOrdenadoPorDobleClave(lista, RProd);
      cout << "Ingrese un Codigo de producto" << endl;
      cin >> RProd.codP;
   }

   cout << "CodP  PU"<< endl;
   while (lista!=NULL) {
      ElminaPrimero(lista, RProd);
      cout << " " << RProd.codP << " - " << RProd.Suc << " - " << RProd.PU << endl;
   }
   return 0;
}
