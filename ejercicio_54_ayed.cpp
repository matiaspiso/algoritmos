//Se conocen las ventas de un producto a lo largo de 4 sucursales (0 a 3) y de una semana (días 0 lunes a 6 domingo).
//Para ello se cuenta con la siguiente información sin ningún orden de cada venta de dicho producto 
//Sucursal (1 a 4)  Día (1 a 7)   Cantidad vendida (entero)   
// (se puede repetir sucursal y día lo que significa que ese producto tuvo otra venta en dicha sucursal/día)
//Informar el total de unidades vendidas por cada combinación Sucursal / Día 
// (en las combinaciones sucursal/día en que no haya ninguna venta, se informará lógicamente 0)

#include <iostream>
using namespace std;

int main(){

    int sucursal;
    int diasem;
    int cantvend;
    int ventas[4][7];

    for (int i=0; i<4; i++){
        for (int j=0; j<7; j++){
            ventas[i][j] = 0;
        }
    }


    cout << "Ingrese sucursal (4 para cortar): ";
        cin >> sucursal;
    while (sucursal != 4);{
        cout << "Ingrese sucursal (4 para cortar): ";
        cin >> sucursal;
        cout << "Ingrese dia de la semana: ";
        cin >> diasem;

        cout << "Ingrese cantidad vendida: ";
        cin >> cantvend;

        ventas[sucursal][diasem] += cantvend;

    }

    for (int i=0; i<4; i++){
        cout << "Sucursal " << i << endl;
        for (int j=0; j<7; j++){
            cout << "- Día " << j << ": " << ventas[i][j] << " ventas" << endl;
        }
    }

}

