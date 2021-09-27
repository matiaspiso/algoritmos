
#include <iostream>
using namespace std;

int main() {
   int i,n, sumedades;
   float promedades;
   int ed[70];
   string nom[70];
   // 60) Ingresar N valores correspondientes a los nombres y edades de los alumnos de un curso (N<=70).
   // Informar la edad promedio de �ste y un listado con los nombres de los alumnos cuya edad supera dicho promedio.
   sumedades = 0;
   cout << "Ing. cant. de alumnos del curso (max. 70)" << endl;
   cin >> n;
   for (i=0;i<=n-1;i++) {
      cout << "Ing nombre" << endl;
      cin >> nom[i];
      cout << "Ing edad" << endl;
      cin >> ed[i];
      sumedades = sumedades+ed[i];
   }
   promedades = sumedades/(n*1.0);
   cout << "El promedio de edad del curso es " << promedades << endl;
   // verifico Edades mayores al promedio
   cout << "Lista de alumnos con edad superior al promedio " << endl;
   for (i=0;i<=n-1;i++) {
      if (ed[i]>promedades)
      {
        cout << nom[i] << " " << ed[i] << endl;
      }
   }
   cout << "Fin Programa " << endl;
   return 0;
}
