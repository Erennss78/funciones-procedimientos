// Ejercicio 8: Series geometricas
#include <iostream>
#include <cstdlib>
using namespace std;

int LeerNumero() {
    int n;
    do {
        cout << "Ingrese N (entero positivo): ";
        cin >> n;
    } while (n <= 0);
    return n;
}

void MostrarSerieGeometrica(int inicio, int factor, int n) {
    int termino = inicio;
    for (int i = 1; i <= n; i++) {
        cout << termino << " ";
        termino = termino * factor;
    }
    cout << endl;
}

void SerieFactor2(int n) {
    cout << "Serie factor 2: ";
    MostrarSerieGeometrica(2, 2, n);
}

void SerieFactor3(int n) {
    cout << "Serie factor 3: ";
    MostrarSerieGeometrica(3, 3, n);
}

int main() {
    int n = LeerNumero();
    SerieFactor2(n);
    SerieFactor3(n);
    system("pause");
    return 0;
}
