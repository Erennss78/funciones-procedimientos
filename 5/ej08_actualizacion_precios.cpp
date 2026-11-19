#include <iostream>
#include <string>
using namespace std;

struct Producto
{
    int codigo;
    string nombre;
    float precio;
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
        cout << "\n1) Registrar productos\n2) Listar productos\n3) Buscar producto por codigo\n"
             << "4) Modificar precio\n0) Salir\nOpcion: ";
        cin >> op;

        switch (op)
        {
        case 1:
        {
            int cant;
            do
            {
                cout << "Cantidad de productos (1-" << MAX << "): ";
                cin >> cant;
            } while (cant < 1 || cant > MAX);
            n = cant;
            for (int i = 0; i < n; i++)
            {
                cout << "\n--- PRODUCTO " << i + 1 << " ---" << endl;
                cout << "Codigo: ";
                cin >> p[i].codigo;
                cout << "Nombre: ";
                getline(cin >> ws, p[i].nombre);
                do
                {
                    cout << "Precio (> 0): ";
                    cin >> p[i].precio;
                } while (p[i].precio <= 0);
            }
            break;
        }
        case 2:
            if (n == 0)
            {
                cout << "No hay productos registrados." << endl;
            }
            else
            {
                for (int i = 0; i < n; i++)
                {
                    cout << p[i].codigo << " | " << p[i].nombre << " | " << p[i].precio << endl;
                }
            }
            break;
        case 3:
        case 4:
            if (n == 0)
            {
                cout << "No hay productos registrados." << endl;
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
                else
                {
                    if (op == 4)
                    {
                        do
                        {
                            cout << "Nuevo precio (> 0): ";
                            cin >> p[pos].precio;
                        } while (p[pos].precio <= 0);
                        cout << "Registro actualizado:" << endl;
                    }
                    cout << p[pos].codigo << " | " << p[pos].nombre << " | " << p[pos].precio << endl;
                }
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
