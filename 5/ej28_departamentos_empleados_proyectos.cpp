#include <iostream>
#include <string>
using namespace std;

struct Departamento
{
    int codigo;
    string nombre;
};

struct Empleado
{
    int codigo;
    string nombre;
    int codigoDepartamento;
};

struct Proyecto
{
    int codigo;
    string nombre;
    int codigoResponsable;
    float presupuesto;
};

const int MAXD = 6;
const int MAXE = 25;
const int MAXP = 20;

int buscarDepartamento(const Departamento d[], int n, int cod)
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

int buscarEmpleado(const Empleado e[], int n, int cod)
{
    int i = 0;
    while (i < n && e[i].codigo != cod)
    {
        i++;
    }
    if (i < n)
    {
        return i;
    }
    return -1;
}

int buscarProyecto(const Proyecto p[], int n, int cod)
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

float proyectosDepartamento(const Proyecto p[], int np, const Empleado e[], int ne, int codDepto)
{
    float suma = 0;
    for (int i = 0; i < np; i++)
    {
        int pe = buscarEmpleado(e, ne, p[i].codigoResponsable);
        if (e[pe].codigoDepartamento == codDepto)
        {
            cout << p[i].codigo << " | " << p[i].nombre << " | " << p[i].presupuesto
                 << " | resp. " << e[pe].nombre << endl;
            suma += p[i].presupuesto;
        }
    }
    return suma;
}

int main()
{
    Departamento d[MAXD];
    Empleado e[MAXE];
    Proyecto p[MAXP];
    int nd = 0, ne = 0, np = 0, op;

    do
    {
        cout << "\n1) Registrar departamentos\n2) Registrar empleados\n3) Registrar proyectos\n"
             << "4) Proyectos y presupuesto por departamento\n5) Responsables de mas de un proyecto\n"
             << "0) Salir\nOpcion: ";
        cin >> op;

        switch (op)
        {
        case 1:
        {
            int cant;
            cout << "Cuantos departamentos desea agregar? ";
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
                    if (buscarDepartamento(d, nd, cod) != -1)
                    {
                        cout << "Codigo duplicado." << endl;
                    }
                    else
                    {
                        d[nd].codigo = cod;
                        cout << "Nombre: ";
                        getline(cin >> ws, d[nd].nombre);
                        nd++;
                    }
                }
            }
            break;
        }
        case 2:
            if (nd == 0)
            {
                cout << "Primero registre departamentos." << endl;
            }
            else
            {
                int cant;
                cout << "Cuantos empleados desea agregar? ";
                cin >> cant;
                for (int k = 0; k < cant; k++)
                {
                    if (ne == MAXE)
                    {
                        cout << "Capacidad llena." << endl;
                    }
                    else
                    {
                        int cod, codd;
                        cout << "\nCodigo del empleado: ";
                        cin >> cod;
                        cout << "Codigo del departamento: ";
                        cin >> codd;
                        if (buscarEmpleado(e, ne, cod) != -1)
                        {
                            cout << "Codigo duplicado." << endl;
                        }
                        else if (buscarDepartamento(d, nd, codd) == -1)
                        {
                            cout << "El departamento no existe." << endl;
                        }
                        else
                        {
                            e[ne].codigo = cod;
                            e[ne].codigoDepartamento = codd;
                            cout << "Nombre: ";
                            getline(cin >> ws, e[ne].nombre);
                            ne++;
                        }
                    }
                }
            }
            break;
        case 3:
            if (ne == 0)
            {
                cout << "Primero registre empleados." << endl;
            }
            else
            {
                int cant;
                cout << "Cuantos proyectos desea agregar? ";
                cin >> cant;
                for (int k = 0; k < cant; k++)
                {
                    if (np == MAXP)
                    {
                        cout << "Capacidad llena." << endl;
                    }
                    else
                    {
                        int cod, codr;
                        cout << "\nCodigo del proyecto: ";
                        cin >> cod;
                        cout << "Codigo del responsable: ";
                        cin >> codr;
                        if (buscarProyecto(p, np, cod) != -1)
                        {
                            cout << "Codigo duplicado." << endl;
                        }
                        else if (buscarEmpleado(e, ne, codr) == -1)
                        {
                            cout << "El responsable no existe." << endl;
                        }
                        else
                        {
                            p[np].codigo = cod;
                            p[np].codigoResponsable = codr;
                            cout << "Nombre: ";
                            getline(cin >> ws, p[np].nombre);
                            do
                            {
                                cout << "Presupuesto (> 0): ";
                                cin >> p[np].presupuesto;
                            } while (p[np].presupuesto <= 0);
                            np++;
                        }
                    }
                }
            }
            break;
        case 4:
            if (nd == 0)
            {
                cout << "No hay departamentos." << endl;
            }
            else
            {
                int cod;
                cout << "Codigo del departamento: ";
                cin >> cod;
                int pos = buscarDepartamento(d, nd, cod);
                if (pos == -1)
                {
                    cout << "El departamento no existe." << endl;
                }
                else
                {
                    cout << "Proyectos de " << d[pos].nombre << ":" << endl;
                    float suma = proyectosDepartamento(p, np, e, ne, cod);
                    cout << "Presupuesto total: " << suma << endl;
                }
            }
            break;
        case 5:
            if (np == 0)
            {
                cout << "No hay proyectos." << endl;
            }
            else
            {
                int hallados = 0;
                for (int i = 0; i < ne; i++)
                {
                    int cont = 0;
                    for (int j = 0; j < np; j++)
                    {
                        if (p[j].codigoResponsable == e[i].codigo)
                        {
                            cont++;
                        }
                    }
                    if (cont > 1)
                    {
                        cout << e[i].codigo << " | " << e[i].nombre << " | " << cont << " proyectos" << endl;
                        hallados++;
                    }
                }
                if (hallados == 0)
                {
                    cout << "Ningun empleado responde por mas de un proyecto." << endl;
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
