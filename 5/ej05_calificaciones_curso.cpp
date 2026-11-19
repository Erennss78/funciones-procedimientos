#include <iostream>
#include <string>
using namespace std;

struct Alumno
{
    string cedula;
    string nombre;
    float nota1;
    float nota2;
};

int main()
{
    const int MAX = 40;
    Alumno a[MAX];
    int n, cont = 0;

    do
    {
        cout << "Cantidad de alumnos (1-" << MAX << "): ";
        cin >> n;
    } while (n < 1 || n > MAX);

    for (int i = 0; i < n; i++)
    {
        cout << "\n--- ALUMNO " << i + 1 << " ---" << endl;
        cout << "Cedula: ";
        cin >> a[i].cedula;
        cout << "Nombre: ";
        getline(cin >> ws, a[i].nombre);
        do
        {
            cout << "Nota 1 (0-10): ";
            cin >> a[i].nota1;
        } while (a[i].nota1 < 0 || a[i].nota1 > 10);
        do
        {
            cout << "Nota 2 (0-10): ";
            cin >> a[i].nota2;
        } while (a[i].nota2 < 0 || a[i].nota2 > 10);
    }

    cout << "\n--- PROMEDIOS ---" << endl;
    for (int i = 0; i < n; i++)
    {
        float prom = (a[i].nota1 + a[i].nota2) / 2;
        cout << a[i].cedula << " | " << a[i].nombre << " | Promedio: " << prom << endl;
        if (prom >= 7)
        {
            cont++;
        }
    }
    cout << "Alumnos con promedio >= 7: " << cont << endl;
    return 0;
}
