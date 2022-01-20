// 60) Ingresar N valores correspondientes a los nombres y edades de los alumnos de un curso (N<=70).
// Informar la edad promedio de este y un listado con los nombres de los alumnos cuya edad supera dicho promedio.

#include <iostream>
using namespace std;

struct tAlumno //registro tabla de alumno
{
   string nombre;
   int edad;
};

int main() {
   int ce, i,n, sumedades;
   float promedades;
//   int ed[70];
//   string nom[70];
   tAlumno VAlu[70];
   sumedades = 0;
   ce = 0;
   cout << "Ing. cant. de alumnos del curso (max. 70)" << endl;
   cin >> n;
   for (i=0;i<=n-1;i++) {
      cout << "Ing nombre" << endl;
      cin >> VAlu[i].nombre;
      cout << "Ing edad" << endl;
      cin >> VAlu[i].edad;
      sumedades = sumedades+VAlu[i].edad;
   }
   promedades = sumedades/(n*1.0);
   cout << "El promedio de edad del curso es " << promedades << endl;
   // verifico Edades mayores al promedio
   cout << "Lista de alumnos con edad superior al promedio " << endl;
   for (i=0;i<=n-1;i++) {
      if (VAlu[i].edad>promedades)
      {
        cout << VAlu[i].nombre << " " << VAlu[i].edad << endl;
      }
   }
   cout << "Fin Programa " << endl;
   return 0;
}


