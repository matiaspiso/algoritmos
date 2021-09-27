#include <iostream>
#include <fstream>
#include <stdio.h>
#include <cstdlib>
#include <time.h>

using namespace std;

struct alumne {
  char nombre[30];
  int edad;
};

char nombres[5][15] = {"Matías", "Vladi", "Lucho", "Javi", "Luquitas"};
char apellidos[5][15] = {"Rodriguez", "Fernandez", "Charkot", "Carbajal", "Mineutas"};

string nombre_azar(){
  char nombre_completo[30] = "";
  char * sep = " ";
  strcat(nombre_completo, nombres[rand()%5]);
  strcat(nombre_completo, sep);
  strcat(nombre_completo, apellidos[rand()%5]);
  return nombre_completo;
}


int main(){
  alumne alu;
  for (int i = 0; i < 5; i++){
    string nombre_completo = nombre_azar();

    // Lleno alumne
    alu.edad = rand() % 32 + 18;
    strcpy(alu.nombre, nombre_completo.c_str());

    // Muestro
    cout << alu.nombre << " tiene " << alu.edad << " años" << endl;
  }
}
