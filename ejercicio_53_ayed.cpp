//Máximos no únicos 
//Ingresar la nota final de los alumnos de un curso de algoritmos; el ingreso finaliza con nota = 0.
//Informar la nota máxima y las posiciones de ingreso de alumno que compartieron ese máximo.

#include <iostream>
using namespace std;

int main(){

  int notas[10];
  int maximos[10];
  int nota_maxima = 0;
  int cant_maximos = 0;

  for (int i = 0; i < 10; i++){
      cout << "Ingrese nota: " ;
      cin >> notas[i];

      if(notas[i] > nota_maxima){
        nota_maxima = notas[i];
        cant_maximos = 0;
      }

      if(notas[i] == nota_maxima){
        maximos[cant_maximos] = i;
        cant_maximos++;
      }

  }

  cout << "La nota máxima es: " << nota_maxima << endl;
  cout << "La tuvieron las posiciones ";
  for(int i=0; i < cant_maximos; i++){
    cout << maximos[i]+1 << " ";
  }
  cout << endl;

}
