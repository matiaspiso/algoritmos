#include <iostream>
using namespace std;

// Definimos un tipo:
struct t_vuelo {
  string cod_vuelo;
  int disponibles;
  int rechazados;
};

// Definimos una variable:
struct {
  string cod_vuelo;
  int solicitados;
} compra;

t_vuelo vuelos[500];
int cant_vuelos = 0;

void BuscarEnVec(t_vuelo vuelos[], string cod_vuelo, int &pos){
  for(int i = 0; i < cant_vuelos; i++){
    if(cod_vuelo == vuelos[i].cod_vuelo){
      pos = i;
    }
  }
}



// Boilerplate
int main(){

  // Carga de vuelos:

  t_vuelo vuelo;
  cout << "Ingrese código de vuelo: " << endl;
  cin >> vuelo.cod_vuelo;

  while(vuelo.cod_vuelo != "."){
    cout << "Ingrese cantidad de pasajes disponibles: " << endl;
    cin >> vuelo.disponibles;
    vuelo.rechazados = 0;
    vuelos[cant_vuelos] = vuelo;
    cant_vuelos++;
    cout << "Ingrese código de vuelo: " << endl;
    cin >> vuelo.cod_vuelo;
  }


  // Procesamiento de ventas:

  cout << "Ingrese código de vuelo para compra: " << endl;
  cin >> compra.cod_vuelo;
  int pos_vuelo;

  while(compra.cod_vuelo != "."){

    cout << "Ingrese cantidad de pasajes que desea: " << endl;
    cin >> compra.solicitados;

    BuscarEnVec(vuelos, compra.cod_vuelo, pos_vuelo);

    // Apuntar al vuelo de turno para averiguar cuantos disponibles y restarle o sumar a la cantidad de ventas perdidas
    vuelo = vuelos[pos_vuelo];

    if(vuelo.disponibles >= compra.solicitados){
      cout << "Código de vuelo: " << vuelo.cod_vuelo << endl;
      cout << "Cantidad de pasajes vendidos: " << compra.solicitados << endl;
      vuelo.disponibles -= compra.solicitados;
    }else{
      cout << "Compra rechazada, cantidad de pasajes no disponibles" << endl;
      vuelo.rechazados += compra.solicitados;
    }

    vuelos[pos_vuelo] = vuelo; // actualicemos en el mismo lugar del que lo sacamos

    cout << "Ingrese código de vuelo para compra: " << endl;
    cin >> compra.cod_vuelo;

  }

  // Emitimos el listado
  for(int i = 0; i < cant_vuelos; i++){
    cout << endl;
    cout << "Código de vuelo: " << vuelos[i].cod_vuelo << endl;
    cout << "Disponibles: " << vuelos[i].disponibles << endl;
    cout << "Rechazados: " << vuelos[i].rechazados << endl;
    cout << endl;
    cout << "--" << endl;
  }

}
1