#include <iostream>
#include <string>
using namespace std;

struct Estudiante
{
    int codigo;
    string nombre;
    float promedio;
};

int main()
{
    Estudiante est[5];

    for (int i = 0; i < 5; i++)
    {
        cout << "\n--- ESTUDIANTE " << i + 1 << " ---" << endl;
        cout << "Codigo: ";
        cin >> est[i].codigo;
        cout << "Nombre: ";
        getline(cin >> ws, est[i].nombre);
        cout << "Promedio: ";
        cin >> est[i].promedio;
    }

    cout << "\n--- LISTA DE ESTUDIANTES ---" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << est[i].codigo << " | " << est[i].nombre << " | " << est[i].promedio << endl;
    }
    return 0;
}
