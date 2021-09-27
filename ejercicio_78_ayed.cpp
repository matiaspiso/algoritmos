#include <iostream>
#include <stdio.h>
using namespace std;
//----------------------------------------------------------------------------------------------------------------------------------------------------------
const int cantidadProductos = 5;   //cantidad de productos definidos en el otro .cpp

// Definimos un tipo:
typedef struct tyProductoArchivo{
	int codProducto;
	double precioUnitario;
	int stock;
};

// Definimos un tipo:
typedef struct tyIngreso{
	int codProducto;
	int stock;
};

//funciones de ingreso de datos:

int ingresarCodigoProducto(){
	int codProducto;

	cout << "Ingresar codigo de producto" << endl;
	cin >> codProducto;

	return codProducto;
}

double ingresarPrecioUnitario(){
	double precioUnitario;

	cout << "Ingresar precio unitario" << endl;
	cin >> precioUnitario;

	return precioUnitario;
}

int ingresarStock(){
	int stock;

	cout << "Ingresar stock" << endl;
	cin >> stock;

	return stock;
}
//fin funciones de ingreso de datos.

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//bloque mati
//funcion no void:










void restarStockArchivo(int codigoProductoABuscar, int stock)
{
    FILE *arch;
    arch=fopen("Productos.dat","r+b"); // abre el archivo de lectura,
    tyProductoArchivo producto;
    bool seModifico = false;

	fread(&producto, sizeof(tyIngreso), 1, arch); //sizeof, devuelve el tamaño en bytes que ocupa una variable o algún tipo de dato
   	while(!feof(arch) && !seModifico)
    {

    	if (producto.codProducto==codigoProductoABuscar)
        {
    	   producto.stock = stock;
           seModifico = true;
           int pos=ftell(arch)-sizeof(tyProductoArchivo);   //ftell, retorna la posición actual del puntero de lectura/escritura de un archivo.
           fseek(arch,pos,SEEK_SET);                    //fseek permite desplazar el indicador de posición de fichero al sitio desde donde el cual quieres acceder al fichero
           fwrite(&producto, sizeof(tyProductoArchivo), 1, arch); //sizeof, devuelve el tamaño en bytes que ocupa una variable o algún tipo de dato
        }
        fread(&producto, sizeof(tyProductoArchivo), 1, arch);
	}

   fclose (arch);          //cierra el archivo

}

void restarStockVector (int & stockProducto, int stockIngresado){    // el stock que tenemos por referencia se debe a que necesitamos devolver
                                                                     // el valor del mismo modificado.
	stockProducto = stockProducto - stockIngresado;
}

void restarStock (int & stockProducto, int stockIngresado, int codigoProductoABuscar){
	restarStockVector(stockProducto, stockIngresado);
	restarStockArchivo(codigoProductoABuscar, stockIngresado);
	// Vamos a la posicion del vector que encontramos y restamos el stock correspondiente y el archivo lo modificamos.
	// se puede restar del archivo y volver a cargar en el vector y viceversa.
}
















//salida de datos:---------------------------------------------------------------------------------------------------------------------------------------------------------------------

void mostrarPrecioAPagar (int precio, int stock){
	cout << "El precio a pagar es de $" << precio*stock << endl;
}

void mostrarNoHayStockDisponible (){
	cout << "No hay stock disponible para ese producto" << endl;
}

void mostrarNoExisteEseProducto (){
	cout << "Ese producto es inexistente" << endl;
}
//fin salida de datos.

int main (){
	tyIngreso ingresoProductos;                                  // define la variable del tipo tyIngreso // (Ingreso del cliente)
	tyProductoArchivo vecProductos[cantidadProductos];           // Archivo de stock (5 productos) - No era bueno realizar consultas cada vez
																 // que se quiere hacer una compra, ya que sería menos eficiente.
																 // (El enunciado decía que era hasta 30 productos, por lo que se puede trabajar
																 // con un vector)	 
	int posProductoBuscado;                                      // define variables tipo int
	int controlStock;

	LeerArchivo(vecProductos); // carga el vector
//facu

	ingresoProductos.codProducto = ingresarCodigoProducto(); //guarda en el registro el ingreso de datos
	while (ingresoProductos.codProducto != 0){               //mientras el codigo sea diferente de 0 ...

		ingresoProductos.stock = ingresarStock();            //guarda en el registro el ingreso de datos
		posProductoBuscado = buscarProducto(vecProductos, ingresoProductos.codProducto); 
		//alan
		if (posProductoBuscado != -1){
			//luis
			if (validarStock(vecProductos[posProductoBuscado].stock, ingresoProductos.stock)){ //Teniendo la posicion del producto, tengo que
				// validar si el stock que me ingresaron corresponde al que ya estaba en el archivo. 

				restarStock(vecProductos[posProductoBuscado].stock, ingresoProductos.stock, ingresoProductos.codProducto); 
				mostrarPrecioAPagar(vecProductos[posProductoBuscado].precioUnitario, ingresoProductos.stock);
			}
			else{
				mostrarNoHayStockDisponible(); // muestra que no hay stock si es mayor al del archivo.
			}
		}
		else{
			mostrarNoExisteEseProducto();
		}
		ingresoProductos.codProducto = ingresarCodigoProducto();
	}
	return 0;
}
