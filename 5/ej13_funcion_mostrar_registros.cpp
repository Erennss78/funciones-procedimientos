#include <iostream>
#include <string>
using namespace std;

struct Estudiante
{
    int codigo;
    string nombre;
    float promedio;
};

void leerCurso(Estudiante v[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "\n--- ESTUDIANTE " << i + 1 << " ---" << endl;
        cout << "Codigo: ";
        cin >> v[i].codigo;
        cout << "Nombre: ";
        getline(cin >> ws, v[i].nombre);
        cout << "Promedio: ";
        cin >> v[i].promedio;
    }
}

void mostrarCurso(const Estudiante v[], int n)
{
    cout << "\n--- CURSO ---" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << v[i].codigo << " | " << v[i].nombre << " | " << v[i].promedio << endl;
    }
}

int main()
{
    const int MAX = 25;
    Estudiante curso[MAX];
    int n;

    do
    {
        cout << "Cantidad de estudiantes (1-" << MAX << "): ";
        cin >> n;
    } while (n < 1 || n > MAX);

    leerCurso(curso, n);
    mostrarCurso(curso, n);
    return 0;
}
