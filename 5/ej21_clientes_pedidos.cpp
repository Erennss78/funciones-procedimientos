#include <iostream>
#include <string>
using namespace std;

struct Cliente
{
    int codigo;
    string nombre;
    string telefono;
};

struct Pedido
{
    int numero;
    int codigoCliente;
    string fecha;
    float total;
};

const int MAXC = 10;
const int MAXP = 30;

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

int buscarPedido(const Pedido p[], int n, int num)
{
    int i = 0;
    while (i < n && p[i].numero != num)
    {
        i++;
    }
    if (i < n)
    {
        return i;
    }
    return -1;
}

void leerClientes(Cliente c[], int &n)
{
    int cant;
    cout << "Cuantos clientes desea agregar? ";
    cin >> cant;
    for (int k = 0; k < cant; k++)
    {
        if (n == MAXC)
        {
            cout << "Capacidad de clientes llena." << endl;
        }
        else
        {
            int cod;
            cout << "\nCodigo: ";
            cin >> cod;
            if (buscarCliente(c, n, cod) != -1)
            {
                cout << "Codigo duplicado, cliente omitido." << endl;
            }
            else
            {
                c[n].codigo = cod;
                cout << "Nombre: ";
                getline(cin >> ws, c[n].nombre);
                cout << "Telefono: ";
                cin >> c[n].telefono;
                n++;
            }
        }
    }
}

void leerPedidos(Pedido p[], int &np, const Cliente c[], int nc)
{
    int cant;
    cout << "Cuantos pedidos desea agregar? ";
    cin >> cant;
    for (int k = 0; k < cant; k++)
    {
        if (np == MAXP)
        {
            cout << "Capacidad de pedidos llena." << endl;
        }
        else
        {
            int num, codc;
            cout << "\nNumero de pedido: ";
            cin >> num;
            cout << "Codigo del cliente: ";
            cin >> codc;
            if (buscarPedido(p, np, num) != -1)
            {
                cout << "Numero de pedido duplicado." << endl;
            }
            else if (buscarCliente(c, nc, codc) == -1)
            {
                cout << "El cliente no existe." << endl;
            }
            else
            {
                p[np].numero = num;
                p[np].codigoCliente = codc;
                cout << "Fecha: ";
                cin >> p[np].fecha;
                do
                {
                    cout << "Total (>= 0): ";
                    cin >> p[np].total;
                } while (p[np].total < 0);
                np++;
            }
        }
    }
}

float totalPorCliente(const Pedido p[], int np, int codc)
{
    float suma = 0;
    for (int i = 0; i < np; i++)
    {
        if (p[i].codigoCliente == codc)
        {
            suma += p[i].total;
        }
    }
    return suma;
}

int main()
{
    Cliente c[MAXC];
    Pedido p[MAXP];
    int nc = 0, np = 0, op;

    do
    {
        cout << "\n1) Registrar clientes\n2) Registrar pedidos\n3) Listar clientes\n"
             << "4) Consultar pedidos y total por cliente\n5) Cliente con mayor importe\n0) Salir\nOpcion: ";
        cin >> op;

        switch (op)
        {
        case 1:
            leerClientes(c, nc);
            break;
        case 2:
            if (nc == 0)
            {
                cout << "Primero registre clientes." << endl;
            }
            else
            {
                leerPedidos(p, np, c, nc);
            }
            break;
        case 3:
            if (nc == 0)
            {
                cout << "No hay clientes." << endl;
            }
            else
            {
                for (int i = 0; i < nc; i++)
                {
                    cout << c[i].codigo << " | " << c[i].nombre << " | " << c[i].telefono << endl;
                }
            }
            break;
        case 4:
            if (nc == 0)
            {
                cout << "No hay clientes." << endl;
            }
            else
            {
                int cod;
                cout << "Codigo del cliente: ";
                cin >> cod;
                int pos = buscarCliente(c, nc, cod);
                if (pos == -1)
                {
                    cout << "El cliente no existe." << endl;
                }
                else
                {
                    cout << "Pedidos de " << c[pos].nombre << ":" << endl;
                    for (int i = 0; i < np; i++)
                    {
                        if (p[i].codigoCliente == cod)
                        {
                            cout << p[i].numero << " | " << p[i].fecha << " | " << p[i].total << endl;
                        }
                    }
                    cout << "Total comprado: " << totalPorCliente(p, np, cod) << endl;
                }
            }
            break;
        case 5:
            if (nc == 0 || np == 0)
            {
                cout << "Se necesitan clientes y pedidos." << endl;
            }
            else
            {
                int mayor = 0;
                for (int i = 1; i < nc; i++)
                {
                    if (totalPorCliente(p, np, c[i].codigo) > totalPorCliente(p, np, c[mayor].codigo))
                    {
                        mayor = i;
                    }
                }
                cout << "Mayor importe: " << c[mayor].nombre << " con "
                     << totalPorCliente(p, np, c[mayor].codigo) << endl;
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
