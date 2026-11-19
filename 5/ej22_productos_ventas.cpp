#include <iostream>
#include <string>
using namespace std;

struct Producto
{
    int codigo;
    string nombre;
    float precio;
    int stock;
};

struct Venta
{
    int numero;
    int codigoProducto;
    int cantidad;
};

const int MAXP = 15;
const int MAXV = 40;

int buscarProducto(const Producto p[], int n, int cod)
{
    int i = 0;
    while (i < n && p[i].codigo != cod)
    {
        i++;
    }
    if (i < n)
    {
        return i;
    }
    return -1;
}

void registrarVenta(Producto p[], int np, Venta v[], int &nv)
{
    if (nv == MAXV)
    {
        cout << "Capacidad de ventas llena." << endl;
    }
    else
    {
        int cod, cant;
        cout << "Codigo del producto: ";
        cin >> cod;
        int pos = buscarProducto(p, np, cod);
        if (pos == -1)
        {
            cout << "El producto no existe." << endl;
        }
        else
        {
            cout << "Cantidad: ";
            cin >> cant;
            if (cant <= 0)
            {
                cout << "Cantidad invalida." << endl;
            }
            else if (cant > p[pos].stock)
            {
                cout << "Stock insuficiente (disponible: " << p[pos].stock << ")." << endl;
            }
            else
            {
                v[nv].numero = nv + 1;
                v[nv].codigoProducto = cod;
                v[nv].cantidad = cant;
                p[pos].stock -= cant;
                nv++;
                cout << "Venta registrada. Importe: " << cant * p[pos].precio << endl;
            }
        }
    }
}

float totalVentas(const Venta v[], int nv, const Producto p[], int np)
{
    float total = 0;
    for (int i = 0; i < nv; i++)
    {
        int pos = buscarProducto(p, np, v[i].codigoProducto);
        total += v[i].cantidad * p[pos].precio;
    }
    return total;
}

int main()
{
    Producto p[MAXP];
    Venta v[MAXV];
    int np = 0, nv = 0, op;

    do
    {
        cout << "\n1) Registrar productos\n2) Registrar venta\n3) Listar productos con existencias\n"
             << "4) Listar ventas\n5) Mostrar total vendido\n0) Salir\nOpcion: ";
        cin >> op;

        switch (op)
        {
        case 1:
        {
            int cant;
            cout << "Cuantos productos desea agregar? ";
            cin >> cant;
            for (int k = 0; k < cant; k++)
            {
                if (np == MAXP)
                {
                    cout << "Capacidad llena." << endl;
                }
                else
                {
                    int cod;
                    cout << "\nCodigo: ";
                    cin >> cod;
                    if (buscarProducto(p, np, cod) != -1)
                    {
                        cout << "Codigo duplicado." << endl;
                    }
                    else
                    {
                        p[np].codigo = cod;
                        cout << "Nombre: ";
                        getline(cin >> ws, p[np].nombre);
                        do
                        {
                            cout << "Precio (> 0): ";
                            cin >> p[np].precio;
                        } while (p[np].precio <= 0);
                        do
                        {
                            cout << "Stock (>= 0): ";
                            cin >> p[np].stock;
                        } while (p[np].stock < 0);
                        np++;
                    }
                }
            }
            break;
        }
        case 2:
            if (np == 0)
            {
                cout << "Primero registre productos." << endl;
            }
            else
            {
                registrarVenta(p, np, v, nv);
            }
            break;
        case 3:
            if (np == 0)
            {
                cout << "No hay productos." << endl;
            }
            else
            {
                cout << "--- CON EXISTENCIAS ---" << endl;
                for (int i = 0; i < np; i++)
                {
                    if (p[i].stock > 0)
                    {
                        cout << p[i].codigo << " | " << p[i].nombre << " | " << p[i].precio
                             << " | stock " << p[i].stock << endl;
                    }
                }
                cout << "--- AGOTADOS ---" << endl;
                for (int i = 0; i < np; i++)
                {
                    if (p[i].stock == 0)
                    {
                        cout << p[i].codigo << " | " << p[i].nombre << endl;
                    }
                }
            }
            break;
        case 4:
            if (nv == 0)
            {
                cout << "No hay ventas." << endl;
            }
            else
            {
                for (int i = 0; i < nv; i++)
                {
                    int pos = buscarProducto(p, np, v[i].codigoProducto);
                    cout << "Venta " << v[i].numero << " | " << p[pos].nombre << " | cant " << v[i].cantidad
                         << " | importe " << v[i].cantidad * p[pos].precio << endl;
                }
            }
            break;
        case 5:
            if (nv == 0)
            {
                cout << "No hay ventas." << endl;
            }
            else
            {
                cout << "Total vendido: " << totalVentas(v, nv, p, np) << endl;
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
