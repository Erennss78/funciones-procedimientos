#include <iostream>
#include <string>
using namespace std;

struct Prestamo
{
    int codigo;
    string estudiante;
    string libro;
    int dias;
};

int main()
{
    const int MAX = 50;
    Prestamo p[MAX];
    int n, mayor = 0;

    do
    {
        cout << "Cantidad de prestamos (1-" << MAX << "): ";
        cin >> n;
    } while (n < 1 || n > MAX);

    for (int i = 0; i < n; i++)
    {
        cout << "\n--- PRESTAMO " << i + 1 << " ---" << endl;
        cout << "Codigo: ";
        cin >> p[i].codigo;
        cout << "Estudiante: ";
        getline(cin >> ws, p[i].estudiante);
        cout << "Libro: ";
        getline(cin >> ws, p[i].libro);
        do
        {
            cout << "Dias (> 0): ";
            cin >> p[i].dias;
        } while (p[i].dias <= 0);
        if (p[i].dias > mayor)
        {
            mayor = p[i].dias;
        }
    }

    cout << "\n--- PRESTAMOS DE MAS DE 15 DIAS ---" << endl;
    for (int i = 0; i < n; i++)
    {
        if (p[i].dias > 15)
        {
            cout << p[i].codigo << " | " << p[i].estudiante << " | " << p[i].libro << " | " << p[i].dias << " dias" << endl;
        }
    }
    cout << "Mayor numero de dias: " << mayor << endl;
    return 0;
}
