// Ejercicio 11: Presentacion de fechas (d/m/aa)
#include <iostream>
#include <cstdlib>
using namespace std;

void FormatearAnio(int anio) {
    if (anio < 10) {
        cout << "0";
    }
    cout << anio;
}

void MostrarFecha(int dia, int mes, int anio) {
    cout << "Fecha: " << dia << "/" << mes << "/";
    FormatearAnio(anio);
    cout << endl;
}

int main() {
    int dia, mes, anio;
    cout << "Ingrese el dia: ";
    cin >> dia;
    cout << "Ingrese el mes: ";
    cin >> mes;
    do {
        cout << "Ingrese el anio (dos digitos, 0 a 99): ";
        cin >> anio;
    } while (anio < 0 || anio > 99);

    MostrarFecha(dia, mes, anio);

    system("pause");
    return 0;
}
