#include <iostream>
#include <string>
using namespace std;

struct Proveedor
{
    int codigo;
    string nombre;
};

struct Producto
{
    int codigo;
    string nombre;
    int stock;
    float costo;
};

struct Compra
{
    int numero;
    int codigoProveedor;
    int codigoProducto;
    int cantidad;
    float costoUnitario;
};

const int MAXV = 10;
const int MAXP = 20;
const int MAXC = 50;

int buscarProveedor(const Proveedor v[], int n, int cod)
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

int buscarProducto(const Producto v[], int n, int cod)
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

void registrarCompra(Compra c[], int &nc, Producto p[], int np, const Proveedor v[], int nv)
{
    if (nc == MAXC)
    {
        cout << "Capacidad de compras llena." << endl;
    }
    else
    {
        int codV, codP, cant;
        float costo;
        cout << "Codigo del proveedor: ";
        cin >> codV;
        cout << "Codigo del producto: ";
        cin >> codP;
        int posP = buscarProducto(p, np, codP);
        if (buscarProveedor(v, nv, codV) == -1)
        {
            cout << "El proveedor no existe." << endl;
        }
        else if (posP == -1)
        {
            cout << "El producto no existe." << endl;
        }
        else
        {
            do
            {
                cout << "Cantidad (> 0): ";
                cin >> cant;
            } while (cant <= 0);
            do
            {
                cout << "Costo unitario (> 0): ";
                cin >> costo;
            } while (costo <= 0);
            c[nc].numero = nc + 1;
            c[nc].codigoProveedor = codV;
            c[nc].codigoProducto = codP;
            c[nc].cantidad = cant;
            c[nc].costoUnitario = costo;
            p[posP].stock += cant;
            p[posP].costo = costo;
            nc++;
            cout << "Compra registrada." << endl;
        }
    }
}

float totalProveedor(const Compra c[], int nc, int codV)
{
    float total = 0;
    for (int i = 0; i < nc; i++)
    {
        if (c[i].codigoProveedor == codV)
        {
            total += c[i].cantidad * c[i].costoUnitario;
        }
    }
    return total;
}

int main()
{
    Proveedor v[MAXV];
    Producto p[MAXP];
    Compra c[MAXC];
    int nv = 0, np = 0, nc = 0, op;

    do
    {
        cout << "\n1) Registrar proveedores\n2) Registrar productos\n3) Registrar compra\n"
             << "4) Consultar compras por proveedor\n0) Salir\nOpcion: ";
        cin >> op;

        switch (op)
        {
        case 1:
        {
            int cant;
            cout << "Cuantos proveedores desea agregar? ";
            cin >> cant;
            for (int k = 0; k < cant; k++)
            {
                if (nv == MAXV)
                {
                    cout << "Capacidad llena." << endl;
                }
                else
                {
                    int cod;
                    cout << "\nCodigo: ";
                    cin >> cod;
                    if (buscarProveedor(v, nv, cod) != -1)
                    {
                        cout << "Codigo duplicado." << endl;
                    }
                    else
                    {
                        v[nv].codigo = cod;
                        cout << "Nombre: ";
                        getline(cin >> ws, v[nv].nombre);
                        nv++;
                    }
                }
            }
            break;
        }
        case 2:
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
                            cout << "Stock inicial (>= 0): ";
                            cin >> p[np].stock;
                        } while (p[np].stock < 0);
                        do
                        {
                            cout << "Costo (>= 0): ";
                            cin >> p[np].costo;
                        } while (p[np].costo < 0);
                        np++;
                    }
                }
            }
            break;
        }
        case 3:
            if (nv == 0 || np == 0)
            {
                cout << "Se necesitan proveedores y productos." << endl;
            }
            else
            {
                registrarCompra(c, nc, p, np, v, nv);
            }
            break;
        case 4:
            if (nv == 0)
            {
                cout << "No hay proveedores." << endl;
            }
            else
            {
                int cod;
                cout << "Codigo del proveedor: ";
                cin >> cod;
                int pos = buscarProveedor(v, nv, cod);
                if (pos == -1)
                {
                    cout << "El proveedor no existe." << endl;
                }
                else
                {
                    cout << "Compras a " << v[pos].nombre << ":" << endl;
                    for (int i = 0; i < nc; i++)
                    {
                        if (c[i].codigoProveedor == cod)
                        {
                            int pp = buscarProducto(p, np, c[i].codigoProducto);
                            cout << c[i].numero << " | " << p[pp].nombre << " | cant " << c[i].cantidad
                                 << " | costo " << c[i].costoUnitario << endl;
                        }
                    }
                    cout << "Total adquirido: " << totalProveedor(c, nc, cod) << endl;
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
