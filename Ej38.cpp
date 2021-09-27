// Este codigo ha sido generado por el modulo psexport 20180802-w32 de PSeInt.
// Es posible que el codigo generado no sea completamente correcto. Si encuentra
// errores por favor reportelos en el foro (http://pseint.sourceforge.net).

#include<iostream>
using namespace std;

// Para leer variables de texto se utiliza el operador << del objeto cin, que
// lee solo una palabra. Para leer una linea completa (es decir, incluyendo los
// espacios en blanco) se debe utilzar getline (ej, reemplazar cin>>x por
// getline(cin,x)), pero obliga a agregar un cin.ignore() si antes del getline
// se leyó otra variable con >>.

int main() {
	bool haynumero1020;
	int num;
	haynumero1020 = false;
	cout << "Ingrese un numero. 0 para cortar" << endl;
	cin >> num;
	while ((num!=0)) {
		if ((num>=10) && (num<=20)) {
			haynumero1020 = true;
		} else {
			// NO DEBE VOLVER AL VALOR ORIGINAL
			// HayNumero1020<- Falso
		}
		cout << "Ingrese un numero. 0 para cortar" << endl;
		cin >> num;
	}
	if ((haynumero1020)) {
		cout << "Hubo al menos un valor entre 10 y 20" << endl;
	} else {
		cout << "No hubo ningun valor entre 10 y 20" << endl;
	}
	return 0;
}

