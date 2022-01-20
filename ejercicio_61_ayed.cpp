//Una empresa de aviación realiza máximo 500 vuelos semanales a distintos puntos del país y requiere desarrollar un programa para la venta de pasajes. 
//Para ello dispone de la información de los Vuelos, con un registro por cada uno de los N vuelos que realiza,
//sin ningún orden, con el siguiente diseño de registro: 
//a.1) código de vuelo (4 caracteres)   a.2) cantidad de pasajes disponibles (3 dígitos)
//Se deben ingresar los pedidos de los potenciales compradores y con el siguiente diseño de registro:
//b.1) código de vuelo    b.2) cantidad de pasajes solicitados
//El lote finaliza con un código de vuelo = “.”
//Se pide: 

//1) Cada vez que a un solicitante se le pueden vender sus pasajes, imprimir en el momento la siguiente línea:
//   Cant de pasajes vendidos     Código de Vuelo
//                999                                      XXXX
//Por ahora la salida de datos se hace luego de cada ingreso, más adelante podremos emitir el listado al final enviándolo a un archivo.

//2) Al final del proceso emitir el siguiente listado por código de vuelo
//Código de Vuelo     Pasajes disponibles    Total Pasajes no vendidos (por falta de disponibilidad) 
//       XXXX                           999                                  99999

//Cuando se solicita una cantidad de pasajes que no está disponible en su totalidad, se rechaza dicha solicitud por completo
//y dicha cantidad pasa a acumular la de Total de Pasajes no vendidos para dicho vuelo.
//Por ejemplo, si del vuelo AB14 quedan en dado momento 20 pasajes disponibles y viene alguien que solicita 50 pasajes para un contingente,
//se rechazan los 50 pasajes y se acumulan estos 50 a los pasajes rechazados que ya hubiera para dicho vuelo.


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