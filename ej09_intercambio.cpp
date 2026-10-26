// Ejercicio 9: Intercambio de valores
#include <iostream>
#include <cstdlib>
using namespace std;

void Intercambiar(int &a, int &b) {
    int aux = a;
    a = b;
    b = aux;
}

int main() {
    int a, b;
    cout << "Ingrese el primer numero: ";
    cin >> a;
    cout << "Ingrese el segundo numero: ";
    cin >> b;

    cout << "Valores originales: a = " << a << ", b = " << b << endl;
    Intercambiar(a, b);
    cout << "Valores intercambiados: a = " << a << ", b = " << b << endl;

    system("pause");
    return 0;
}
