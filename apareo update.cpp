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


void generarArchivo(int cant, char * nombre_archivo){
  // codP empieza siendo azar entre 1 y 5
  int codP = rand() % 5 + 1;
  FILE * F = fopen((char *)nombre_archivo, "w+b");
  t_producto producto;

  for(int i=0; i < cant; i++){

    producto.cantVen = rand() % 1000 + 1;
    producto.codProd = codP;

    fwrite(&producto, sizeof(t_producto), 1, F);

    // Incrementar codP en una pequeña cantidad al azar
    codP += rand() % 5;
  }

  fclose(F);
}


void generarArchivos(int cantA, int cantB){

 generarArchivo(cantA, "productosA.dat");
 generarArchivo(cantB, "productosB.dat");

}


void mostrarArchivos(){

  t_producto productos;
  FILE * A = fopen("productosA.dat", "r+b");
  FILE * B = fopen("productosB.dat", "r+b");

  cout << endl << "Mostrando archivoA: " << endl;
  fread(&productos, sizeof(t_producto), 1, A);
  while(!feof(A)){
    cout << productos.codProd << " | ";
    cout << productos.cantVen << endl;
    fread(&productos, sizeof(t_producto), 1, A);
  }

  cout << endl << "Mostrando archivoB: " << endl;
  fread(&productos, sizeof(t_producto), 1, B);
  while(!feof(B)){
    cout << productos.codProd << " | ";
    cout << productos.cantVen << endl;
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

  // Patrón while: leemos justo antes y justo al final
  fread(&rA, sizeof(t_producto), 1, INA);
  fread(&rB, sizeof(t_producto), 1, INB);

  while(!feof(INA) && !feof(INB)){

    if(rA.codProd <= rB.codProd){
      fwrite(&rA, sizeof(t_producto), 1, OUT);
      // cout << "Escribiendo " << rA.codProd << endl;
      fread(&rA, sizeof(t_producto), 1, INA);
    }else{
      fwrite(&rB, sizeof(t_producto), 1, OUT);
      // cout << "Escribiendo " << rB.codProd << endl;
      fread(&rB, sizeof(t_producto), 1, INB);
    }

  }


  // Si alguno de los dos termina, vaciamos el que falte:

  while(!feof(INA)){
    fwrite(&rA, sizeof(t_producto), 1, OUT);
    // cout << "Escribiendo " << rA.codProd << endl;
    fread(&rA, sizeof(t_producto), 1, INA);
  }

  while(!feof(INB)){
    fwrite(&rB, sizeof(t_producto), 1, OUT);
    // cout << "Escribiendo " << rB.codProd << endl;
    fread(&rB, sizeof(t_producto), 1, INB);
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
    cout << productos.codProd << " | ";
    cout << productos.cantVen << endl;
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
  // cout << "Time: " << time(NULL) << endl;
  srand( (unsigned)time(NULL) );

  generarArchivos(cantA, cantB);
  mostrarArchivos();
  aparearArchivos();
  mostrarApareado();
}
