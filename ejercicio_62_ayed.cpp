#include <iostream>
using namespace std;

int ventas[5][4];
int precios[5][4];

int precios_t[5][4] = {
  {132, 170, 210, 240},
  {200, 240, 280, 320},
  {240, 180, 340, 400},
  {300, 340, 400, 460},
  {360, 420, 480, 540}
};

int ventas_t[5][4] = {
  {32, 17,  21, 5},
  {7,  13,  21, 4},
  {32,  4,  17, 24},
  {12,  6,   3, 13},
  {22,  1,  17, 11}
};

char colores[5] = {'A', 'B', 'C', 'D', 'E'};

int main(){

  // Subpunto 1
  cout << "1- Totales por combinación modelo/color: " << endl;
  for(int i = 0; i < 5; i++){
    for(int j = 0; j < 4; j++){
      cout << "Modelo " << j+1 << ", color " << colores[i] << ": $" << ventas_t[i][j] * precios_t[i][j] << endl;
    }
  }

  // Subpunto 2
  cout << endl << "2- Totales por modelo: " << endl;

  for(int i = 0; i < 4; i++){
    int total = 0;
    for(int j = 0; j < 5; j++){
      total += ventas_t[j][i] * precios_t[j][i];
    }
    cout << "Modelo " << i+1 << ": $" << total << endl;
  }

  // Subpunto 3
  cout << endl << "3- Totales por color: " << endl;

  for(int i = 0; i < 5; i++){
    int total = 0;
    for(int j = 0; j < 4; j++){
      total += ventas_t[i][j] * precios_t[i][j];
    }
    cout << "Color " << i+1 << ": $" << total << endl;
  }

  // Subpunto 3
  cout << endl << "3- Totales por color: " << endl;

  int total = 0;
  for(int i = 0; i < 5; i++){
    for(int j = 0; j < 4; j++){
      total += ventas_t[i][j] * precios_t[i][j];
    }
  }
  cout << "Total en calzados: $" << total << endl;

}

// Cantidad de ventas:
//     1   2   3   4
// A  32  17  21   5
// B   7  13  21   4
// C  32   4  17  24
// D  12   6   3  13
// E  22   1  17  11

// Precios:
//       1     2     3     4
// A  $132  $170  $210  $240
// B  $200  $240  $280  $320
// C  $240  $180  $340  $400
// D  $300  $340  $400  $460
// E  $360  $420  $480  $540
