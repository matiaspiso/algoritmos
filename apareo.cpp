#include <iostream>
#include <fstream>
#include <stdio.h>
#include <cstdlib>
#include <time.h>
using namespace std;

struct t_producto{
  int codProd;
  int cantVen;
};


void generarArchivos(int cantA, int cantB){
  int codP = 1;
  int hechoA = 0;
  int hechoB = 0;

  // Abrir archivoA
  // Abrir archivoB
 FILE * A = fopen("productosA.dat", "w+b");
 FILE * B = fopen("productosB.dat", "w+b");
 t_producto productos;

  for(int i=0; i < cantA + cantB; i++){

    productos.cantVen = rand() % 100;
    productos.codProd = codP;

    // Si me queda espacio en ambos, elijo al azar
    // en cual volcar el próximo registo...
    if (hechoA < cantA && hechoB < cantB){
      int eleccion = rand() % 2;
      if (eleccion == 0){
        fwrite(&productos, sizeof(t_producto), 1, A);
        hechoA += 1;
      }else{
        fwrite(&productos, sizeof(t_producto), 1, B);
        hechoB += 1;
      }
    }else{
      // ...sino, vuelco en el que quede espacio
      if (hechoA < cantA){
        fwrite(&productos, sizeof(t_producto), 1, A);
        hechoA += 1;
      }else{
        fwrite(&productos, sizeof(t_producto), 1, B);
        hechoB += 1;
      }
    }

    // Incrementar codP en una pequeña cantidad al azar
     codP += rand()%3 + 1;
  }

  fclose(A);
  fclose(B);
}


void mostrarArchivos(){

  t_producto productos;
  FILE * A = fopen("productosA.dat", "r+b");
  FILE * B = fopen("productosB.dat", "r+b");

  cout << endl << "Mostrando archivoA: " << endl;
  fread(&productos, sizeof(t_producto), 1, A);
  while(!feof(A)){
    cout<< productos.codProd<<"/";
    cout<< productos.cantVen<<endl;
    fread(&productos, sizeof(t_producto), 1, A);
  }

  cout << endl << "Mostrando archivoB: " << endl;
  fread(&productos, sizeof(t_producto), 1, B);
  while(!feof(B)){
    cout<< productos.codProd<<"/";
    cout<< productos.cantVen<<endl;
    fread(&productos, sizeof(t_producto), 1, B);
  }
 fclose(A);
 fclose(B);

}

void aparearArchivos(){

  t_producto rA;
  t_producto rB;
  FILE * INA = fopen("productosA.dat", "r+b");
  FILE * INB = fopen("productosB.dat", "r+b");

  FILE * OUT = fopen("apareado.dat", "w+b");

  fread(&rA, sizeof(t_producto), 1, INA);
  fread(&rB, sizeof(t_producto), 1, INB);
  while(!feof(INA) && !feof(INB)){

    if(rA.codProd < rB.codProd){
      fwrite(&rA, sizeof(t_producto), 1, OUT);
      fread(&rA, sizeof(t_producto), 1, INA);
    }else{
      fwrite(&rB, sizeof(t_producto), 1, OUT);
      fread(&rB, sizeof(t_producto), 1, INB);
    }

  }

  while(!feof(INA)){
    fwrite(&rA, sizeof(t_producto), 1, OUT);
    fread(&rA, sizeof(t_producto), 1, INA);
  }

  while(!feof(INB)){
    fwrite(&rA, sizeof(t_producto), 1, OUT);
    fread(&rA, sizeof(t_producto), 1, INB);
  }

  fclose(INA);
  fclose(INB);
  fclose(OUT);

}

void mostrarApareado(){
  t_producto productos;
  FILE * APA = fopen("apareado.dat", "r+b");

  cout << endl << endl << "Mostrando apareado: " << endl;
  fread(&productos, sizeof(t_producto), 1, APA);
  while(!feof(APA)){
    cout<< productos.codProd<<"/";
    cout<< productos.cantVen<<endl;
    fread(&productos, sizeof(t_producto), 1, APA);
  }

  fclose(APA);

}


int main(){
  int cantA,cantB;
  cout<< "ingrese cantidad de elementos para el archivo 1: "<<endl;
  cin>> cantA;

  cout<<"ingrese cantidad de elementos para el archivo 2: "<<endl;
  cin>> cantB;
  //cout << "Time: " << time(NULL) << endl;
  srand( (unsigned)time(NULL) );
  generarArchivos(cantA,cantB);
  mostrarArchivos();
  aparearArchivos();
  mostrarApareado();
}
