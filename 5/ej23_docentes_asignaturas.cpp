#include <iostream>
#include <string>
using namespace std;

struct Docente
{
    int codigo;
    string nombre;
    string area;
};

struct Asignatura
{
    int codigo;
    string nombre;
    int horas;
    int codigoDocente;
};

const int MAXD = 8;
const int MAXA = 20;

int buscarDocente(const Docente d[], int n, int cod)
{
    int i = 0;
    while (i < n && d[i].codigo != cod)
    {
        i++;
    }
    if (i < n)
    {
        return i;
    }
    return -1;
}

int buscarAsignatura(const Asignatura a[], int n, int cod)
{
    int i = 0;
    while (i < n && a[i].codigo != cod)
    {
        i++;
    }
    if (i < n)
    {
        return i;
    }
    return -1;
}

int calcularHoras(const Asignatura a[], int na, int codDocente)
{
    int suma = 0;
    for (int i = 0; i < na; i++)
    {
        if (a[i].codigoDocente == codDocente)
        {
            suma += a[i].horas;
        }
    }
    return suma;
}

void listarAsignaturasDocente(const Asignatura a[], int na, int codDocente)
{
    for (int i = 0; i < na; i++)
    {
        if (a[i].codigoDocente == codDocente)
        {
            cout << a[i].codigo << " | " << a[i].nombre << " | " << a[i].horas << " h" << endl;
        }
    }
}

int main()
{
    Docente d[MAXD];
    Asignatura a[MAXA];
    int nd = 0, na = 0, op;

    do
    {
        cout << "\n1) Registrar docentes\n2) Registrar asignaturas\n3) Consultar por docente\n"
             << "4) Docente con mayor carga horaria\n0) Salir\nOpcion: ";
        cin >> op;

        switch (op)
        {
        case 1:
        {
            int cant;
            cout << "Cuantos docentes desea agregar? ";
            cin >> cant;
            for (int k = 0; k < cant; k++)
            {
                if (nd == MAXD)
                {
                    cout << "Capacidad llena." << endl;
                }
                else
                {
                    int cod;
                    cout << "\nCodigo: ";
                    cin >> cod;
                    if (buscarDocente(d, nd, cod) != -1)
                    {
                        cout << "Codigo duplicado." << endl;
                    }
                    else
                    {
                        d[nd].codigo = cod;
                        cout << "Nombre: ";
                        getline(cin >> ws, d[nd].nombre);
                        cout << "Area: ";
                        getline(cin >> ws, d[nd].area);
                        nd++;
                    }
                }
            }
            break;
        }
        case 2:
            if (nd == 0)
            {
                cout << "Primero registre docentes." << endl;
            }
            else
            {
                int cant;
                cout << "Cuantas asignaturas desea agregar? ";
                cin >> cant;
                for (int k = 0; k < cant; k++)
                {
                    if (na == MAXA)
                    {
                        cout << "Capacidad llena." << endl;
                    }
                    else
                    {
                        int cod, codd;
                        cout << "\nCodigo de asignatura: ";
                        cin >> cod;
                        cout << "Codigo del docente: ";
                        cin >> codd;
                        if (buscarAsignatura(a, na, cod) != -1)
                        {
                            cout << "Codigo duplicado." << endl;
                        }
                        else if (buscarDocente(d, nd, codd) == -1)
                        {
                            cout << "El docente no existe." << endl;
                        }
                        else
                        {
                            a[na].codigo = cod;
                            a[na].codigoDocente = codd;
                            cout << "Nombre: ";
                            getline(cin >> ws, a[na].nombre);
                            do
                            {
                                cout << "Horas (> 0): ";
                                cin >> a[na].horas;
                            } while (a[na].horas <= 0);
                            na++;
                        }
                    }
                }
            }
            break;
        case 3:
            if (nd == 0)
            {
                cout << "No hay docentes." << endl;
            }
            else
            {
                int cod;
                cout << "Codigo del docente: ";
                cin >> cod;
                int pos = buscarDocente(d, nd, cod);
                if (pos == -1)
                {
                    cout << "El docente no existe." << endl;
                }
                else
                {
                    cout << "Asignaturas de " << d[pos].nombre << ":" << endl;
                    listarAsignaturasDocente(a, na, cod);
                    cout << "Total de horas: " << calcularHoras(a, na, cod) << endl;
                }
            }
            break;
        case 4:
            if (nd == 0 || na == 0)
            {
                cout << "Se necesitan docentes y asignaturas." << endl;
            }
            else
            {
                int mayor = 0;
                for (int i = 1; i < nd; i++)
                {
                    if (calcularHoras(a, na, d[i].codigo) > calcularHoras(a, na, d[mayor].codigo))
                    {
                        mayor = i;
                    }
                }
                cout << "Mayor carga: " << d[mayor].nombre << " con "
                     << calcularHoras(a, na, d[mayor].codigo) << " horas" << endl;
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
