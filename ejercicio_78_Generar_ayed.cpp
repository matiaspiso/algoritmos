#include <iostream>
#include <stdio.h>
using namespace std;
//creamos una estructura que contiene los datos del producto
typedef struct tyProductoArchivo{
	int codProducto;
	double precioUnitario;
	int stock;
};



void GenerarArchivo () {
   tyProductoArchivo RVta;
   FILE *av = fopen("Productos.dat", "w+b"); //abro el archivo para escritura binaria
	for (int i = 1; i <= 5; i++){            //mientras i sea menor a la cantidad de productos repito el ciclo
		cout << "Ingrese cod" << endl;
     	cin >> RVta.codProducto;
     	
     	cout << "Ingrese PU" << endl;
     	cin >> RVta.precioUnitario;
     	
     	cout << "Ingrese stock" << endl;
     	cin >> RVta.stock;
     	
     	
     	fwrite (&RVta, sizeof (RVta), 1, av);
	}
   fclose (av);
};

int main () {
   GenerarArchivo(); 
   return 0;
}
