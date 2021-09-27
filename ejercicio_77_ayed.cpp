#include <iostream>
#include <fstream>
using namespace std;

struct t_prod{
  int cod;
  float pu;
};

t_prod prods[30];


void generarArchivo(){
  t_prod prod;
  FILE * ap = fopen("productos.dat", "w+b");

  prod.cod = 123;
  prod.pu = 100;
  fwrite(&prod, sizeof(t_prod), 1, ap);

  prod.cod = 234;
  prod.pu = 200;
  fwrite(&prod, sizeof(t_prod), 1, ap);

  prod.cod = 345;
  prod.pu = 300;
  fwrite(&prod, sizeof(t_prod), 1, ap);

  fclose(ap);

}


float precio_de(int codigo){
  float precio = 0.0;
  for (int i = 0; i < 30; i++){
    if (prods[i].cod == codigo) {
      precio = prods[i].pu;
      break;
    }
  }
  return precio;
}


void ingresarPedidos(){
  FILE * ap = fopen("productos.dat", "r");

  // Carga
  fseek(ap,0,SEEK_END);
  int size = ftell(ap);
  fseek(ap,0,SEEK_SET);
  int n = size / sizeof(t_prod);

  for (int i = 0; i < n; i++){
    fread(&prods[i], sizeof(t_prod), 1, ap);
  }

  // Lectura
  int codprod;
  int cant;
  cout << "Ingrese código de producto (fin=0): " << endl;
  cin >> codprod;

  while(codprod != 0){

    float precio = precio_de(codprod);

    if (precio == 0.0){
      cout << "El pedido solicitado no existe :C" << endl;
    }else{
      cout << "Ingrese cantidad deseada: " << endl;
      cin >> cant;
      
      cout << "El pedido solicitado cuesta: " << cant * precio << endl;
    }

    cout << "Ingrese código de producto (fin=0): " << endl;
    cin >> codprod;
  }

}


int main(){

  // generarArchivo();

  cout << "Ingrese opcion: " << endl;
  cout << "1- Generar archivo" << endl;
  cout << "2- Ingresar pedidos" << endl;
  cout << "3- Salir" << endl;

  int opcion;
  cin >> opcion;

  switch(opcion){
    case 1:
      generarArchivo();
      break;
    case 2:
      ingresarPedidos();
      break;
  }

}
