#include <iostream>
#include <string>
using namespace std;

struct Estudiante
{
    int codigo;
    string nombre;
    string carrera;
};

int main()
{
    const int MAX = 30;
    Estudiante e[MAX];
    int n, cod, i = 0;

    do
    {
        cout << "Cantidad de estudiantes (1-" << MAX << "): ";
        cin >> n;
    } while (n < 1 || n > MAX);

    for (int k = 0; k < n; k++)
    {
        cout << "\n--- ESTUDIANTE " << k + 1 << " ---" << endl;
        cout << "Codigo: ";
        cin >> e[k].codigo;
        cout << "Nombre: ";
        getline(cin >> ws, e[k].nombre);
        cout << "Carrera: ";
        getline(cin >> ws, e[k].carrera);
    }

    cout << "\nCodigo a buscar: ";
    cin >> cod;

    while (i < n && e[i].codigo != cod)
    {
        i++;
    }

    if (i < n)
    {
        cout << "Encontrado: " << e[i].codigo << " | " << e[i].nombre << " | " << e[i].carrera << endl;
    }
    else
    {
        cout << "El estudiante no existe." << endl;
    }
    return 0;
}
