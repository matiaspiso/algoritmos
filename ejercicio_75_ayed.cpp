//Idem anterior pero donde el main proponga un menú de opciones con Generar archivo y Leer archivo, ambos resueltos modularmente,
// y opción de Salir del Programa.
//Que el programa controle si existe el archivo al intentar abrirlo e informe si no existe,
// por si se intenta leer antes de haberlo generado alguna vez.

#include <iostream>
#include <fstream>
using namespace std;

// Definimos un tipo:
struct t_venta {
  string cod_producto;
  int cant_vendida;
};

// ifstream (input file)
// ofstream (output file)

void generarArchivo(){
  t_venta venta;

  ofstream salida("archivo.dat", ofstream::binary);

  cout << "Ingrese código de producto: ";
  cin >> venta.cod_producto;
  while(venta.cod_producto != "0"){
    cout << "Ingrese cantidad vendida: ";
    cin >> venta.cant_vendida;

    salida.write((char *) &venta, sizeof(t_venta));

    cout << "Ingrese código de producto: ";
    cin >> venta.cod_producto;
  }
  salida.close();

  cout << endl;
}


void leerArchivo(){
  t_venta venta;

  ifstream entrada("archivo.dat", ifstream::binary);

  if(entrada.is_open()){
    cout << "El archivo existe" << endl;

    entrada.seekg(0, entrada.end);
    int largo = entrada.tellg();
    int cant_registros = largo / sizeof(t_venta);
    cout << "El archivo tiene " << largo << " bytes" << endl;
    cout << "El archivo parece tener " << cant_registros << " registros" << endl;
    entrada.seekg(0, entrada.beg);

    for (int i=0; i < cant_registros; i++){
      entrada.read((char *) &venta, sizeof(t_venta));
      cout << "Cod prod: " << venta.cod_producto << endl;
      cout << "Cant vendida: " << venta.cant_vendida << endl;
    }

  }else{
    cout << "El archivo no existe" << endl;
  }



  entrada.close();
}


int main(){

  cout << "Ingrese opcion: " << endl;
  cout << "1- Generar archivo" << endl;
  cout << "2- Leer archivo" << endl;
  cout << "3- Salir" << endl;

  int opcion;
  cin >> opcion;

  // leerArchivo();

  switch(opcion){
    case 1:
      generarArchivo();
      break;
    case 2:
      leerArchivo();
      break;
  }

}

// if(!wf) {
//    cout << "Cannot open file!" << endl;
//    return 1;
// }








// EJEMPLO DE INTERNET

// using namespace std;
// struct Student {
//    int roll_no;
//    string name;
// };
//
// int main() {
//    ofstream wf("student.dat", ios::out | ios::binary);
//    if(!wf) {
//       cout << "Cannot open file!" << endl;
//       return 1;
//    }
//    Student wstu[3];
//    wstu[0].roll_no = 1;
//    wstu[0].name = "Ram";
//    wstu[1].roll_no = 2;
//    wstu[1].name = "Shyam";
//    wstu[2].roll_no = 3;
//    wstu[2].name = "Madhu";
//    for(int i = 0; i < 3; i++)
//       wf.write((char *) &wstu[i], sizeof(Student));
//    wf.close();
//    if(!wf.good()) {
//       cout << "Error occurred at writing time!" << endl;
//       return 1;
//    }
//
//    ifstream rf("student.dat", ios::out | ios::binary);
//    if(!rf) {
//       cout << "Cannot open file!" << endl;
//       return 1;
//    }
//    Student rstu[3];
//
//    for(int i = 0; i < 3; i++)
//       rf.read((char *) &rstu[i], sizeof(Student));
//    rf.close();
//
//    if(!rf.good()) {
//       cout << "Error occurred at reading time!" << endl;
//       return 1;
//    }
//    cout<<"Student's Details:"<<endl;
//    for(int i=0; i < 3; i++) {
//       cout << "Roll No: " << wstu[i].roll_no << endl;
//       cout << "Name: " << wstu[i].name << endl;
//       cout << endl;
//    }
//    return 0;
// }
