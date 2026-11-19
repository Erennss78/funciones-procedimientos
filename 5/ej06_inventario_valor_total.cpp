#include <iostream>
#include <string>
using namespace std;

struct Articulo
{
    int codigo;
    string nombre;
    int stock;
    float costo;
};

int main()
{
    const int MAX = 20;
    Articulo a[MAX];
    int n;
    float total = 0;

    do
    {
        cout << "Cantidad de articulos (1-" << MAX << "): ";
        cin >> n;
    } while (n < 1 || n > MAX);

    for (int i = 0; i < n; i++)
    {
        cout << "\n--- ARTICULO " << i + 1 << " ---" << endl;
        cout << "Codigo: ";
        cin >> a[i].codigo;
        cout << "Nombre: ";
        getline(cin >> ws, a[i].nombre);
        do
        {
            cout << "Stock (>= 0): ";
            cin >> a[i].stock;
        } while (a[i].stock < 0);
        do
        {
            cout << "Costo (>= 0): ";
            cin >> a[i].costo;
        } while (a[i].costo < 0);
        total += a[i].stock * a[i].costo;
    }

    cout << "\nValor total del inventario: " << total << endl;
    cout << "\n--- ARTICULOS CON STOCK CERO ---" << endl;
    for (int i = 0; i < n; i++)
    {
        if (a[i].stock == 0)
        {
            cout << a[i].codigo << " | " << a[i].nombre << endl;
        }
    }
    return 0;
}
