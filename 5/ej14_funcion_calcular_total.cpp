#include <iostream>
#include <string>
using namespace std;

struct Producto
{
    int codigo;
    string nombre;
    float precio;
    int cantidad;
};

float valorInventario(const Producto v[], int n)
{
    float total = 0;
    for (int i = 0; i < n; i++)
    {
        total += v[i].precio * v[i].cantidad;
    }
    return total;
}

int main()
{
    const int MAX = 30;
    Producto p[MAX];
    int n;

    do
    {
        cout << "Cantidad de productos (1-" << MAX << "): ";
        cin >> n;
    } while (n < 1 || n > MAX);

    for (int i = 0; i < n; i++)
    {
        cout << "\n--- PRODUCTO " << i + 1 << " ---" << endl;
        cout << "Codigo: ";
        cin >> p[i].codigo;
        cout << "Nombre: ";
        getline(cin >> ws, p[i].nombre);
        do
        {
            cout << "Precio (>= 0): ";
            cin >> p[i].precio;
        } while (p[i].precio < 0);
        do
        {
            cout << "Cantidad (>= 0): ";
            cin >> p[i].cantidad;
        } while (p[i].cantidad < 0);
    }

    cout << "\nValor del inventario: " << valorInventario(p, n) << endl;
    return 0;
}
