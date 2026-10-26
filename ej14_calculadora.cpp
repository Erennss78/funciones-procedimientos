// Ejercicio 14: Calculadora modular
#include <iostream>
#include <cstdlib>
using namespace std;

float Sumar(float a, float b) {
    return a + b;
}

float Restar(float a, float b) {
    return a - b;
}

float Multiplicar(float a, float b) {
    return a * b;
}

float Dividir(float a, float b) {
    return a / b;
}

void MostrarMenu() {
    cout << endl;
    cout << "===== CALCULADORA =====" << endl;
    cout << "1. Sumar" << endl;
    cout << "2. Restar" << endl;
    cout << "3. Multiplicar" << endl;
    cout << "4. Dividir" << endl;
    cout << "5. Salir" << endl;
    cout << "Elija una opcion: ";
}

void MostrarResultado(float resultado) {
    cout << "Resultado: " << resultado << endl;
}

int main() {
    float a, b;
    int opcion;

    cout << "Ingrese el primer numero: ";
    cin >> a;
    cout << "Ingrese el segundo numero: ";
    cin >> b;

    do {
        MostrarMenu();
        cin >> opcion;

        if (opcion == 1) {
            MostrarResultado(Sumar(a, b));
        } else if (opcion == 2) {
            MostrarResultado(Restar(a, b));
        } else if (opcion == 3) {
            MostrarResultado(Multiplicar(a, b));
        } else if (opcion == 4) {
            if (b == 0) {
                cout << "Error: no se puede dividir para cero" << endl;
            } else {
                MostrarResultado(Dividir(a, b));
            }
        } else if (opcion == 5) {
            cout << "Saliendo..." << endl;
        } else {
            cout << "Opcion no valida" << endl;
        }
    } while (opcion != 5);

    system("pause");
    return 0;
}
