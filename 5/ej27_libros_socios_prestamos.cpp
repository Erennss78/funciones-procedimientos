#include <iostream>
#include <string>
using namespace std;

struct Libro
{
    int codigo;
    string titulo;
    int disponibles;
};

struct Socio
{
    int codigo;
    string nombre;
};

struct Prestamo
{
    int numero;
    int codigoLibro;
    int codigoSocio;
    int dias;
    bool devuelto;
};

const int MAXL = 15;
const int MAXS = 20;
const int MAXP = 50;

int buscarLibro(const Libro l[], int n, int cod)
{
    int i = 0;
    while (i < n && l[i].codigo != cod)
    {
        i++;
    }
    if (i < n)
    {
        return i;
    }
    return -1;
}

int buscarSocio(const Socio s[], int n, int cod)
{
    int i = 0;
    while (i < n && s[i].codigo != cod)
    {
        i++;
    }
    if (i < n)
    {
        return i;
    }
    return -1;
}

int buscarPrestamo(const Prestamo p[], int n, int num)
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

void prestar(Libro l[], int nl, const Socio s[], int ns, Prestamo p[], int &np)
{
    if (np == MAXP)
    {
        cout << "Capacidad de prestamos llena." << endl;
    }
    else
    {
        int codL, codS;
        cout << "Codigo del libro: ";
        cin >> codL;
        cout << "Codigo del socio: ";
        cin >> codS;
        int posL = buscarLibro(l, nl, codL);
        if (posL == -1)
        {
            cout << "El libro no existe." << endl;
        }
        else if (buscarSocio(s, ns, codS) == -1)
        {
            cout << "El socio no existe." << endl;
        }
        else if (l[posL].disponibles == 0)
        {
            cout << "No hay ejemplares disponibles." << endl;
        }
        else
        {
            p[np].numero = np + 1;
            p[np].codigoLibro = codL;
            p[np].codigoSocio = codS;
            do
            {
                cout << "Dias de prestamo (> 0): ";
                cin >> p[np].dias;
            } while (p[np].dias <= 0);
            p[np].devuelto = false;
            l[posL].disponibles--;
            cout << "Prestamo " << p[np].numero << " registrado." << endl;
            np++;
        }
    }
}

void devolver(Libro l[], int nl, Prestamo p[], int np)
{
    int num;
    cout << "Numero de prestamo: ";
    cin >> num;
    int pos = buscarPrestamo(p, np, num);
    if (pos == -1)
    {
        cout << "El prestamo no existe." << endl;
    }
    else if (p[pos].devuelto)
    {
        cout << "El prestamo ya fue devuelto." << endl;
    }
    else
    {
        p[pos].devuelto = true;
        int posL = buscarLibro(l, nl, p[pos].codigoLibro);
        l[posL].disponibles++;
        cout << "Devolucion registrada." << endl;
    }
}

void listarActivos(const Prestamo p[], int np, const Libro l[], int nl, const Socio s[], int ns)
{
    int cont = 0;
    for (int i = 0; i < np; i++)
    {
        if (!p[i].devuelto)
        {
            int pl = buscarLibro(l, nl, p[i].codigoLibro);
            int ps = buscarSocio(s, ns, p[i].codigoSocio);
            cout << p[i].numero << " | " << l[pl].titulo << " | " << s[ps].nombre
                 << " | " << p[i].dias << " dias" << endl;
            cont++;
        }
    }
    if (cont == 0)
    {
        cout << "No hay prestamos activos." << endl;
    }
}

int main()
{
    Libro l[MAXL];
    Socio s[MAXS];
    Prestamo p[MAXP];
    int nl = 0, ns = 0, np = 0, op;

    do
    {
        cout << "\n1) Registrar libros\n2) Registrar socios\n3) Registrar prestamo\n"
             << "4) Registrar devolucion\n5) Listar prestamos activos\n6) Consultar disponibilidad de un libro\n"
             << "0) Salir\nOpcion: ";
        cin >> op;

        switch (op)
        {
        case 1:
        {
            int cant;
            cout << "Cuantos libros desea agregar? ";
            cin >> cant;
            for (int k = 0; k < cant; k++)
            {
                if (nl == MAXL)
                {
                    cout << "Capacidad llena." << endl;
                }
                else
                {
                    int cod;
                    cout << "\nCodigo: ";
                    cin >> cod;
                    if (buscarLibro(l, nl, cod) != -1)
                    {
                        cout << "Codigo duplicado." << endl;
                    }
                    else
                    {
                        l[nl].codigo = cod;
                        cout << "Titulo: ";
                        getline(cin >> ws, l[nl].titulo);
                        do
                        {
                            cout << "Ejemplares disponibles (>= 0): ";
                            cin >> l[nl].disponibles;
                        } while (l[nl].disponibles < 0);
                        nl++;
                    }
                }
            }
            break;
        }
        case 2:
        {
            int cant;
            cout << "Cuantos socios desea agregar? ";
            cin >> cant;
            for (int k = 0; k < cant; k++)
            {
                if (ns == MAXS)
                {
                    cout << "Capacidad llena." << endl;
                }
                else
                {
                    int cod;
                    cout << "\nCodigo: ";
                    cin >> cod;
                    if (buscarSocio(s, ns, cod) != -1)
                    {
                        cout << "Codigo duplicado." << endl;
                    }
                    else
                    {
                        s[ns].codigo = cod;
                        cout << "Nombre: ";
                        getline(cin >> ws, s[ns].nombre);
                        ns++;
                    }
                }
            }
            break;
        }
        case 3:
            if (nl == 0 || ns == 0)
            {
                cout << "Se necesitan libros y socios." << endl;
            }
            else
            {
                prestar(l, nl, s, ns, p, np);
            }
            break;
        case 4:
            if (np == 0)
            {
                cout << "No hay prestamos." << endl;
            }
            else
            {
                devolver(l, nl, p, np);
            }
            break;
        case 5:
            if (np == 0)
            {
                cout << "No hay prestamos." << endl;
            }
            else
            {
                int cod;
                cout << "Codigo del socio (0 para ver todos): ";
                cin >> cod;
                if (cod == 0)
                {
                    listarActivos(p, np, l, nl, s, ns);
                }
                else if (buscarSocio(s, ns, cod) == -1)
                {
                    cout << "El socio no existe." << endl;
                }
                else
                {
                    int cont = 0;
                    for (int i = 0; i < np; i++)
                    {
                        if (!p[i].devuelto && p[i].codigoSocio == cod)
                        {
                            int pl = buscarLibro(l, nl, p[i].codigoLibro);
                            cout << p[i].numero << " | " << l[pl].titulo << " | " << p[i].dias << " dias" << endl;
                            cont++;
                        }
                    }
                    if (cont == 0)
                    {
                        cout << "El socio no tiene prestamos activos." << endl;
                    }
                }
            }
            break;
        case 6:
            if (nl == 0)
            {
                cout << "No hay libros." << endl;
            }
            else
            {
                int cod;
                cout << "Codigo del libro: ";
                cin >> cod;
                int pos = buscarLibro(l, nl, cod);
                if (pos == -1)
                {
                    cout << "El libro no existe." << endl;
                }
                else
                {
                    cout << l[pos].titulo << ": " << l[pos].disponibles << " disponibles" << endl;
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
