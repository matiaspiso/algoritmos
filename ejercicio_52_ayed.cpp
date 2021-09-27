#include <iostream>
using namespace std;

int main(){
    int cantvend;
    int codprod; 
    float precios[10];
    for (int i = 0; i < 10; i++){
        cout << "Ingrese código del producto: " ;
        cin >> codprod;
        cout << "Ingrese precio del producto " << codprod << ": ";
        cin >> precios[codprod-1];
    }

    
    
    cout << endl << endl << "Ingrese código de producto: ";
    cin >> codprod; 
    while (codprod != 0){
        cout << "Ingrese cantidad vendida: ";
        cin >> cantvend; 

        cout << "La venta fue de $" << cantvend * precios[codprod-1]  << endl;

        cout << "Ingrese código de producto: ";
        cin >> codprod; 
    }

}
