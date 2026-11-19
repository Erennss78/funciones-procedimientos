#include <iostream>
#include <string>
using namespace std;

struct Producto
{
    int codigo;
    string descripcion;
    float precio;
    int cantidad;
};

int main()
{
    const int MAX = 50;
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
        cout << "Descripcion: ";
        getline(cin >> ws, p[i].descripcion);
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

    cout << "\n--- PRODUCTOS CON PRECIO MAYOR A USD 5 ---" << endl;
    for (int i = 0; i < n; i++)
    {
        if (p[i].precio > 5)
        {
            cout << p[i].codigo << " | " << p[i].descripcion << " | USD " << p[i].precio
                 << " | Valor: USD " << p[i].precio * p[i].cantidad << endl;
        }
    }
    return 0;
}
