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

const int MAX = 30;

int buscar(const Producto v[], int n, int cod)
{
    int i = 0;
    while (i < n && v[i].codigo != cod)
    {
        i++;
    }
    if (i < n)
    {
        return i;
    }
    return -1;
}

int main()
{
    Producto p[MAX];
    int n = 0, op;

    do
    {
        cout << "\n1) Registrar producto\n2) Listar productos\n3) Buscar por codigo\n"
             << "4) Aumentar existencias\n5) Calcular valor total\n0) Salir\nOpcion: ";
        cin >> op;

        switch (op)
        {
        case 1:
            if (n == MAX)
            {
                cout << "Capacidad llena." << endl;
            }
            else
            {
                int cod;
                cout << "Codigo: ";
                cin >> cod;
                if (buscar(p, n, cod) != -1)
                {
                    cout << "El codigo ya existe." << endl;
                }
                else
                {
                    p[n].codigo = cod;
                    cout << "Nombre: ";
                    getline(cin >> ws, p[n].nombre);
                    do
                    {
                        cout << "Precio (>= 0): ";
                        cin >> p[n].precio;
                    } while (p[n].precio < 0);
                    do
                    {
                        cout << "Cantidad (>= 0): ";
                        cin >> p[n].cantidad;
                    } while (p[n].cantidad < 0);
                    n++;
                    cout << "Producto registrado." << endl;
                }
            }
            break;
        case 2:
            if (n == 0)
            {
                cout << "No hay productos." << endl;
            }
            else
            {
                for (int i = 0; i < n; i++)
                {
                    cout << p[i].codigo << " | " << p[i].nombre << " | " << p[i].precio
                         << " | " << p[i].cantidad << endl;
                }
            }
            break;
        case 3:
        case 4:
            if (n == 0)
            {
                cout << "No hay productos." << endl;
            }
            else
            {
                int cod;
                cout << "Codigo: ";
                cin >> cod;
                int pos = buscar(p, n, cod);
                if (pos == -1)
                {
                    cout << "El producto no existe." << endl;
                }
                else if (op == 3)
                {
                    cout << p[pos].codigo << " | " << p[pos].nombre << " | " << p[pos].precio
                         << " | " << p[pos].cantidad << endl;
                }
                else
                {
                    int extra;
                    do
                    {
                        cout << "Cantidad a aumentar (> 0): ";
                        cin >> extra;
                    } while (extra <= 0);
                    p[pos].cantidad += extra;
                    cout << "Nueva existencia: " << p[pos].cantidad << endl;
                }
            }
            break;
        case 5:
            if (n == 0)
            {
                cout << "No hay productos." << endl;
            }
            else
            {
                float total = 0;
                for (int i = 0; i < n; i++)
                {
                    total += p[i].precio * p[i].cantidad;
                }
                cout << "Valor total del inventario: " << total << endl;
            }
            break;
        case 0:
            cout << "Fin del programa." << endl;
            break;
        default:
            cout << "Opcion invalida." << endl;
        }
    } while (op != 0);
    return 0;
}
