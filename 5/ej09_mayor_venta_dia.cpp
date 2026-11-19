#include <iostream>
#include <string>
using namespace std;

struct Vendedor
{
    int id;
    string nombre;
    float ventas;
};

int main()
{
    Vendedor v[6];
    int mayor = 0;

    for (int i = 0; i < 6; i++)
    {
        cout << "\n--- VENDEDOR " << i + 1 << " ---" << endl;
        cout << "ID: ";
        cin >> v[i].id;
        cout << "Nombre: ";
        getline(cin >> ws, v[i].nombre);
        do
        {
            cout << "Ventas (>= 0): ";
            cin >> v[i].ventas;
        } while (v[i].ventas < 0);
    }

    for (int i = 1; i < 6; i++)
    {
        if (v[i].ventas > v[mayor].ventas)
        {
            mayor = i;
        }
    }

    cout << "\nMayor venta: " << v[mayor].nombre << " con " << v[mayor].ventas << endl;
    return 0;
}
