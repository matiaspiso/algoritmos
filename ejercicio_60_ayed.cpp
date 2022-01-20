//Ingresar N valores correspondientes a los nombres y edades de los alumnos de un curso (N<=70). 
//Informar la edad promedio de éste y un listado con los nombres y edades de los alumnos cuya edad superó dicho promedio.

#include <iostream>
using namespace std;

struct alum {
  string nombre;
  int edad;
};


int main(){

  int cantidad = 0;
  alum alumnes[70];
  string nombre;
  int suma_edades = 0;

  cout << "Ingrese nombre: " ;
  cin >> nombre;

  while (nombre != "0"){

    alumnes[cantidad].nombre = nombre;

    cout << "Ingrese edad: " ;
    cin >> alumnes[cantidad].edad;

    suma_edades += alumnes[cantidad].edad;

    cout << "Ingrese nombre: " ;
    cin >> nombre;

    cantidad++;
  }

  float promedio = suma_edades / cantidad;

  cout << endl << "La edad promedio es " << promedio << endl;

  for (int i=0; i<cantidad; i++){

    if (promedio < alumnes[i].edad){
      cout << "Alumne " << i << ":" << endl;
      cout << "Nombre: " << alumnes[i].nombre << endl;
      cout << "Edad: " << alumnes[i].edad << endl << endl;
    }


  }


}
