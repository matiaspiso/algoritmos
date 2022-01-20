//) Dado un archivo de alumnos que contiene Legajo, Materia, y las notas de Par1, Par2, RecP1 y RecP2
//(si se aprobó Par1 y/o Par2 en el Rec correspondiente se carga 0).
//A efectos de simplificar el programa se supone que existe un único recuparatorio por parcial.
//	Informar
//-Lista de alumnos aprobados (6 o más en ambos parciales o en los recuperatorios correspondientes)
//-cantidad de alumnos promocionados, 8 o más en ambos parciales o a lo sumo usando 1 sólo recuperatorio con 8 o más

#include <iostream>
#include <fstream>
#include <stdio.h>
using namespace std;

struct t_alumne{
  string nombre;
  int legajo;
  string materia;
  float par1;
  float par2;
  float recp1;
  float recp2;
};

t_alumne notas_test[3];

void generarArchivo(){
  FILE * av = fopen("notas.dat", "w+b");

  t_alumne alum;
  for(int i = 0; i < 3; i++){
    cout << "Ingresá nombre: " << endl;
    cin >> alum.nombre;
    cout << "Ingresá legajo: " << endl;
    cin >> alum.legajo;
    cout << "Ingresá materia: " << endl;
    cin >> alum.materia;
    cout << "Ingresá par1: " << endl;
    cin >> alum.par1;
    cout << "Ingresá par2: " << endl;
    cin >> alum.par2;
    if (alum.par1 >= 8){
      alum.recp1 = 0;
    }else{
      cout << "Ingresá recp1: " << endl;
      cin >> alum.recp1;
    }
    if (alum.par2 >= 8){
      alum.recp2 = 0;
    }else{
      cout << "Ingresá recp2: " << endl;
      cin >> alum.recp2;
    }

    notas_test[i] = alum;
  }

  // size_t fwrite(const void * buffer, size_t size, size_t count, FILE * stream);

  for (int i = 0; i < 3; i++){
    fwrite(&notas_test[i], sizeof(t_alumne), 1, av);
  }

  fclose(av);

}

void imprimirAprobadosYPromocionados(){
  FILE * iv = fopen("notas.dat", "r");
  t_alumne alum;
  int cant_promo = 0;

  fread(&alum, sizeof(t_alumne), 1, iv);
  while(!feof(iv)){
    if((alum.par1 >= 8 && alum.par2 >= 8) || (alum.par1 >= 8 && alum.recp2 >= 8) || (alum.recp1 > 8 && alum.par2 >= 8)){
      cant_promo += 1;
      cout << alum.nombre << " promocionó" << endl;
    }else{

      if( (alum.par1 >= 6 && alum.par2 >= 6) || (alum.par1 >= 6 && alum.recp2 >= 6) || (alum.recp1 >= 6 && alum.par2 >= 6) || (alum.recp1 >= 6 && alum.recp2 >= 6)) {
        cout << alum.nombre << " aprobó" << endl;
      }
      // else{
      //   cout << alum.nombre << " desaprobó" << endl;
      // }

    }

    fread(&alum, sizeof(t_alumne), 1, iv);

  }

  fclose(iv);

}


int main(){

  imprimirAprobadosYPromocionados();

  // cout << "Ingrese opcion: " << endl;
  // cout << "1- Generar archivo" << endl;
  // cout << "2- Leer archivo" << endl;
  // cout << "3- Salir" << endl;
  //
  // int opcion;
  // cin >> opcion;
  //
  // switch(opcion){
  //   case 1:
  //     generarArchivo();
  //     break;
  //   case 2:
  //     leerArchivo();
  //     break;
  // }

}
