// Ejercicio 12: Calculo del salario semanal
#include <iostream>
#include <cstdlib>
using namespace std;

float CalcularSalario(float horas, float tarifa) {
    float total;
    if (horas <= 40) {
        total = horas * tarifa;
    } else {
        total = 40 * tarifa + (horas - 40) * tarifa * 1.5;
    }
    return total;
}

void MostrarSalario(float horas, float tarifa, float total) {
    cout << "Horas trabajadas: " << horas << endl;
    cout << "Salario por hora: " << tarifa << endl;
    cout << "Salario total: " << total << endl;
}

int main() {
    float horas, tarifa;
    do {
        cout << "Ingrese las horas trabajadas: ";
        cin >> horas;
    } while (horas < 0);
    do {
        cout << "Ingrese el salario por hora: ";
        cin >> tarifa;
    } while (tarifa < 0);

    float total = CalcularSalario(horas, tarifa);
    MostrarSalario(horas, tarifa, total);

    system("pause");
    return 0;
}
