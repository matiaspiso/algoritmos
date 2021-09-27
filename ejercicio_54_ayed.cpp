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

