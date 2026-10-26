// Ejercicio 13: Validacion de una fecha
#include <iostream>
#include <cstdlib>
using namespace std;

bool EsBisiesto(int anio) {
    return (anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0);
}

int DiasDelMes(int mes, int anio) {
    int dias[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int resultado = dias[mes - 1];
    if (mes == 2 && EsBisiesto(anio)) {
        resultado = 29;
    }
    return resultado;
}

bool EsFechaValida(int dia, int mes, int anio) {
    bool valida = false;
    if (anio > 0 && mes >= 1 && mes <= 12) {
        if (dia >= 1 && dia <= DiasDelMes(mes, anio)) {
            valida = true;
        }
    }
    return valida;
}

int main() {
    int dia, mes, anio;
    cout << "Ingrese el dia: ";
    cin >> dia;
    cout << "Ingrese el mes: ";
    cin >> mes;
    cout << "Ingrese el anio: ";
    cin >> anio;

    if (EsFechaValida(dia, mes, anio)) {
        cout << "La fecha " << dia << "/" << mes << "/" << anio << " es VALIDA" << endl;
    } else {
        cout << "La fecha " << dia << "/" << mes << "/" << anio << " NO es valida" << endl;
    }

    system("pause");
    return 0;
}
