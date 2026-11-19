#include <iostream>
#include <string>
using namespace std;

struct Empleado
{
    int codigo;
    string nombre;
    int edad;
    string departamento;
};

int main()
{
    const int MAX = 50;
    Empleado e[MAX];
    int n, suma = 0, cont = 0;
    string depto;

    do
    {
        cout << "Cantidad de empleados (1-" << MAX << "): ";
        cin >> n;
    } while (n < 1 || n > MAX);

    for (int i = 0; i < n; i++)
    {
        cout << "\n--- EMPLEADO " << i + 1 << " ---" << endl;
        cout << "Codigo: ";
        cin >> e[i].codigo;
        cout << "Nombre: ";
        getline(cin >> ws, e[i].nombre);
        do
        {
            cout << "Edad (18-99): ";
            cin >> e[i].edad;
        } while (e[i].edad < 18 || e[i].edad > 99);
        cout << "Departamento: ";
        getline(cin >> ws, e[i].departamento);
        suma += e[i].edad;
    }

    cout << "\nDepartamento a consultar: ";
    getline(cin >> ws, depto);

    for (int i = 0; i < n; i++)
    {
        if (e[i].departamento == depto)
        {
            cont++;
        }
    }

    cout << "Promedio de edad: " << (float)suma / n << endl;
    cout << "Empleados en " << depto << ": " << cont << endl;
    return 0;
}
