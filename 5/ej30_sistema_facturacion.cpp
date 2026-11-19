#include <iostream>
#include <string>
using namespace std;

struct Cliente
{
    int codigo;
    string nombre;
};

struct Producto
{
    int codigo;
    string descripcion;
    float precio;
    int stock;
};

struct Factura
{
    int numero;
    int codigoCliente;
    string fecha;
};

struct Detalle
{
    int numeroFactura;
    int codigoProducto;
    int cantidad;
    float precioUnitario;
};

const int MAXC = 10;
const int MAXP = 20;
const int MAXF = 20;
const int MAXD = 80;

int buscarCliente(const Cliente c[], int n, int cod)
{
    int i = 0;
    while (i < n && c[i].codigo != cod)
    {
        i++;
    }
    if (i < n)
    {
        return i;
    }
    return -1;
}

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

int buscarFactura(const Factura f[], int n, int num)
{
    int i = 0;
    while (i < n && f[i].numero != num)
    {
        i++;
    }
    if (i < n)
    {
        return i;
    }
    return -1;
}

float totalFactura(const Detalle d[], int nd, int numFactura)
{
    float total = 0;
    for (int i = 0; i < nd; i++)
    {
        if (d[i].numeroFactura == numFactura)
        {
            total += d[i].cantidad * d[i].precioUnitario;
        }
    }
    return total;
}

void agregarDetalle(Detalle d[], int &nd, Producto p[], int np, const Factura f[], int nf)
{
    if (nd == MAXD)
    {
        cout << "Capacidad de detalles llena." << endl;
    }
    else
    {
        int numF, codP, cant;
        cout << "Numero de factura: ";
        cin >> numF;
        cout << "Codigo del producto: ";
        cin >> codP;
        int posP = buscarProducto(p, np, codP);
        if (buscarFactura(f, nf, numF) == -1)
        {
            cout << "La factura no existe." << endl;
        }
        else if (posP == -1)
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
            else if (cant > p[posP].stock)
            {
                cout << "Stock insuficiente (disponible: " << p[posP].stock << ")." << endl;
            }
            else
            {
                d[nd].numeroFactura = numF;
                d[nd].codigoProducto = codP;
                d[nd].cantidad = cant;
                d[nd].precioUnitario = p[posP].precio;
                p[posP].stock -= cant;
                nd++;
                cout << "Detalle agregado." << endl;
            }
        }
    }
}

void imprimirFactura(const Factura f[], int nf, const Cliente c[], int nc, const Producto p[], int np,
                     const Detalle d[], int nd, int numF)
{
    int pf = buscarFactura(f, nf, numF);
    int pc = buscarCliente(c, nc, f[pf].codigoCliente);
    cout << "\n===== FACTURA " << f[pf].numero << " =====" << endl;
    cout << "Fecha: " << f[pf].fecha << endl;
    cout << "Cliente: " << c[pc].nombre << endl;
    for (int i = 0; i < nd; i++)
    {
        if (d[i].numeroFactura == numF)
        {
            int pp = buscarProducto(p, np, d[i].codigoProducto);
            cout << p[pp].descripcion << " | " << d[i].cantidad << " x " << d[i].precioUnitario
                 << " = " << d[i].cantidad * d[i].precioUnitario << endl;
        }
    }
    cout << "TOTAL: " << totalFactura(d, nd, numF) << endl;
}

int main()
{
    Cliente c[MAXC];
    Producto p[MAXP];
    Factura f[MAXF];
    Detalle d[MAXD];
    int nc = 0, np = 0, nf = 0, nd = 0, op;

    do
    {
        cout << "\n1) Registrar clientes\n2) Registrar productos\n3) Crear factura\n"
             << "4) Agregar detalle a una factura\n5) Consultar o imprimir factura\n"
             << "6) Mostrar total facturado\n0) Salir\nOpcion: ";
        cin >> op;

        switch (op)
        {
        case 1:
        {
            int cant;
            cout << "Cuantos clientes desea agregar? ";
            cin >> cant;
            for (int k = 0; k < cant; k++)
            {
                if (nc == MAXC)
                {
                    cout << "Capacidad llena." << endl;
                }
                else
                {
                    int cod;
                    cout << "\nCodigo: ";
                    cin >> cod;
                    if (buscarCliente(c, nc, cod) != -1)
                    {
                        cout << "Codigo duplicado." << endl;
                    }
                    else
                    {
                        c[nc].codigo = cod;
                        cout << "Nombre: ";
                        getline(cin >> ws, c[nc].nombre);
                        nc++;
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
                        cout << "Descripcion: ";
                        getline(cin >> ws, p[np].descripcion);
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
        case 3:
            if (nc == 0)
            {
                cout << "Primero registre clientes." << endl;
            }
            else if (nf == MAXF)
            {
                cout << "Capacidad de facturas llena." << endl;
            }
            else
            {
                int num, codc;
                cout << "Numero de factura: ";
                cin >> num;
                cout << "Codigo del cliente: ";
                cin >> codc;
                if (buscarFactura(f, nf, num) != -1)
                {
                    cout << "Numero de factura duplicado." << endl;
                }
                else if (buscarCliente(c, nc, codc) == -1)
                {
                    cout << "El cliente no existe." << endl;
                }
                else
                {
                    f[nf].numero = num;
                    f[nf].codigoCliente = codc;
                    cout << "Fecha: ";
                    cin >> f[nf].fecha;
                    nf++;
                    cout << "Factura creada." << endl;
                }
            }
            break;
        case 4:
            if (nf == 0 || np == 0)
            {
                cout << "Se necesitan facturas y productos." << endl;
            }
            else
            {
                agregarDetalle(d, nd, p, np, f, nf);
            }
            break;
        case 5:
            if (nf == 0)
            {
                cout << "No hay facturas." << endl;
            }
            else
            {
                int num;
                cout << "Numero de factura: ";
                cin >> num;
                if (buscarFactura(f, nf, num) == -1)
                {
                    cout << "La factura no existe." << endl;
                }
                else
                {
                    imprimirFactura(f, nf, c, nc, p, np, d, nd, num);
                }
            }
            break;
        case 6:
            if (nf == 0)
            {
                cout << "No hay facturas." << endl;
            }
            else
            {
                float total = 0;
                int mayor = 0;
                float mayorMonto = -1;
                for (int i = 0; i < nf; i++)
                {
                    total += totalFactura(d, nd, f[i].numero);
                }
                for (int i = 0; i < nc; i++)
                {
                    float suma = 0;
                    for (int j = 0; j < nf; j++)
                    {
                        if (f[j].codigoCliente == c[i].codigo)
                        {
                            suma += totalFactura(d, nd, f[j].numero);
                        }
                    }
                    if (suma > mayorMonto)
                    {
                        mayorMonto = suma;
                        mayor = i;
                    }
                }
                cout << "Total facturado: " << total << endl;
                cout << "Cliente con mayor facturacion: " << c[mayor].nombre << " (" << mayorMonto << ")" << endl;
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
