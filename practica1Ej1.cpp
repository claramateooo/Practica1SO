#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    string nombreArchivo = "nombres.txt";
    string linea;
    ifstream archivo(nombreArchivo);

    if (archivo.is_open()) {
        while (getline(archivo, linea)) {
            cout << linea << endl;
        }
        archivo.close();
     
    } else {
        cout << "No se pudo abrir el archivo: " << nombreArchivo << endl;
    }

    return 0;
}