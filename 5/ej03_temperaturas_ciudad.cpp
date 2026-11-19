#include <iostream>
#include <string>
using namespace std;

struct Ciudad
{
    string nombre;
    float temperatura;
    int altitud;
};

int main()
{
    const int MAX = 50;
    Ciudad c[MAX];
    int n, cont = 0;

    do
    {
        cout << "Cantidad de ciudades (1-" << MAX << "): ";
        cin >> n;
    } while (n < 1 || n > MAX);

    for (int i = 0; i < n; i++)
    {
        cout << "\n--- CIUDAD " << i + 1 << " ---" << endl;
        cout << "Nombre: ";
        getline(cin >> ws, c[i].nombre);
        cout << "Temperatura (C): ";
        cin >> c[i].temperatura;
        cout << "Altitud (m): ";
        cin >> c[i].altitud;
    }

    cout << "\n--- CIUDADES CON TEMPERATURA MENOR A 15 C ---" << endl;
    for (int i = 0; i < n; i++)
    {
        if (c[i].temperatura < 15)
        {
            cout << c[i].nombre << " | " << c[i].temperatura << " C | " << c[i].altitud << " m" << endl;
            cont++;
        }
    }
    cout << "Total: " << cont << endl;
    return 0;
}
