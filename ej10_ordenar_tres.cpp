// Ejercicio 10: Ordenar tres numeros
#include <iostream>
#include <cstdlib>
using namespace std;

void Intercambiar(int &x, int &y) {
    int aux = x;
    x = y;
    y = aux;
}

void OrdenarTres(int &a, int &b, int &c) {
    if (a > b) {
        Intercambiar(a, b);
    }
    if (a > c) {
        Intercambiar(a, c);
    }
    if (b > c) {
        Intercambiar(b, c);
    }
}

int main() {
    int a, b, c;
    cout << "Ingrese tres numeros enteros: ";
    cin >> a >> b >> c;

    OrdenarTres(a, b, c);
    cout << "Ordenados de menor a mayor: " << a << " " << b << " " << c << endl;

    system("pause");
    return 0;
}
