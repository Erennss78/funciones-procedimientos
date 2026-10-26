// Ejercicio 15: Aplicacion modular de series, sumatorias y ordenacion
#include <iostream>
#include <cstdlib>
using namespace std;

// ---------- Lectura y presentacion ----------
int LeerNumero() {
    int n;
    do {
        cout << "Ingrese N (entero positivo): ";
        cin >> n;
    } while (n <= 0);
    return n;
}

void MostrarSuma(int resultado) {
    cout << "La suma es: " << resultado << endl;
}

// ---------- Sumatorias ----------
int SumarNaturales(int n) {
    int suma = 0;
    for (int i = 1; i <= n; i++) {
        suma = suma + i;
    }
    return suma;
}

int SumarImpares(int n) {
    int suma = 0;
    int impar = 1;
    for (int i = 1; i <= n; i++) {
        suma = suma + impar;
        impar = impar + 2;
    }
    return suma;
}

int SumarMultiplos(int n, int multiplo) {
    int suma = 0;
    for (int i = 1; i <= n; i++) {
        suma = suma + i * multiplo;
    }
    return suma;
}

// ---------- Series ----------
void MostrarSerieAritmetica(int inicio, int diferencia, int n) {
    int termino = inicio;
    for (int i = 1; i <= n; i++) {
        cout << termino << " ";
        termino = termino + diferencia;
    }
    cout << endl;
}

void MostrarSerieGeometrica(int inicio, int factor, int n) {
    int termino = inicio;
    for (int i = 1; i <= n; i++) {
        cout << termino << " ";
        termino = termino * factor;
    }
    cout << endl;
}

// ---------- Ordenacion ----------
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

// ---------- Opciones del menu ----------
void OpcionNaturales() {
    int n = LeerNumero();
    MostrarSuma(SumarNaturales(n));
}

void OpcionImpares() {
    int n = LeerNumero();
    MostrarSuma(SumarImpares(n));
}

void OpcionMultiplos7() {
    int n = LeerNumero();
    MostrarSuma(SumarMultiplos(n, 7));
}

void SerieConsecutiva3() {
    int n = LeerNumero();
    MostrarSerieAritmetica(1, 3, n);
}

void SerieConsecutiva5() {
    int n = LeerNumero();
    MostrarSerieAritmetica(3, 5, n);
}

void SerieFactor2() {
    int n = LeerNumero();
    MostrarSerieGeometrica(2, 2, n);
}

void SerieFactor3() {
    int n = LeerNumero();
    MostrarSerieGeometrica(3, 3, n);
}

void OpcionOrdenar() {
    int a, b, c;
    cout << "Ingrese tres numeros enteros: ";
    cin >> a >> b >> c;
    OrdenarTres(a, b, c);
    cout << "Ordenados de menor a mayor: " << a << " " << b << " " << c << endl;
}

void MostrarMenu() {
    cout << endl;
    cout << "========== MENU ==========" << endl;
    cout << "1. Suma de los numeros naturales" << endl;
    cout << "2. Suma de los numeros impares" << endl;
    cout << "3. Suma de los multiplos de 7" << endl;
    cout << "4. Serie consecutiva de 3" << endl;
    cout << "5. Serie consecutiva de 5" << endl;
    cout << "6. Serie con factor 2" << endl;
    cout << "7. Serie con factor 3" << endl;
    cout << "8. Ordenar numeros" << endl;
    cout << "9. Salir" << endl;
    cout << "Elija una opcion: ";
}

// ---------- Programa principal ----------
int main() {
    int opcion;

    do {
        MostrarMenu();
        cin >> opcion;

        if (opcion == 1) {
            OpcionNaturales();
        } else if (opcion == 2) {
            OpcionImpares();
        } else if (opcion == 3) {
            OpcionMultiplos7();
        } else if (opcion == 4) {
            SerieConsecutiva3();
        } else if (opcion == 5) {
            SerieConsecutiva5();
        } else if (opcion == 6) {
            SerieFactor2();
        } else if (opcion == 7) {
            SerieFactor3();
        } else if (opcion == 8) {
            OpcionOrdenar();
        } else if (opcion == 9) {
            cout << "Saliendo del programa..." << endl;
        } else {
            cout << "Opcion no valida" << endl;
        }
    } while (opcion != 9);

    system("pause");
    return 0;
}
