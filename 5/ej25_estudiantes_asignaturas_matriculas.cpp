#include <iostream>
#include <string>
using namespace std;

struct Estudiante
{
    int codigo;
    string nombre;
};

struct Asignatura
{
    int codigo;
    string nombre;
    int creditos;
};

struct Matricula
{
    int numero;
    int codigoEstudiante;
    int codigoAsignatura;
    float nota;
};

const int MAXE = 20;
const int MAXA = 8;
const int MAXM = 60;

int buscarEstudiante(const Estudiante e[], int n, int cod)
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

bool existeMatricula(const Matricula m[], int n, int codE, int codA)
{
    int i = 0;
    while (i < n && !(m[i].codigoEstudiante == codE && m[i].codigoAsignatura == codA))
    {
        i++;
    }
    return i < n;
}

float promedioEstudiante(const Matricula m[], int n, int codE, int &aprobadas)
{
    float suma = 0;
    int cont = 0;
    aprobadas = 0;
    for (int i = 0; i < n; i++)
    {
        if (m[i].codigoEstudiante == codE)
        {
            suma += m[i].nota;
            cont++;
            if (m[i].nota >= 7)
            {
                aprobadas++;
            }
        }
    }
    if (cont == 0)
    {
        return 0;
    }
    return suma / cont;
}

int main()
{
    Estudiante e[MAXE];
    Asignatura a[MAXA];
    Matricula m[MAXM];
    int ne = 0, na = 0, nm = 0, op;

    do
    {
        cout << "\n1) Registrar estudiantes\n2) Registrar asignaturas\n3) Matricular estudiante\n"
             << "4) Consultar matriculas por estudiante\n5) Calcular promedio del estudiante\n0) Salir\nOpcion: ";
        cin >> op;

        switch (op)
        {
        case 1:
        {
            int cant;
            cout << "Cuantos estudiantes desea agregar? ";
            cin >> cant;
            for (int k = 0; k < cant; k++)
            {
                if (ne == MAXE)
                {
                    cout << "Capacidad llena." << endl;
                }
                else
                {
                    int cod;
                    cout << "\nCodigo: ";
                    cin >> cod;
                    if (buscarEstudiante(e, ne, cod) != -1)
                    {
                        cout << "Codigo duplicado." << endl;
                    }
                    else
                    {
                        e[ne].codigo = cod;
                        cout << "Nombre: ";
                        getline(cin >> ws, e[ne].nombre);
                        ne++;
                    }
                }
            }
            break;
        }
        case 2:
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
                    int cod;
                    cout << "\nCodigo: ";
                    cin >> cod;
                    if (buscarAsignatura(a, na, cod) != -1)
                    {
                        cout << "Codigo duplicado." << endl;
                    }
                    else
                    {
                        a[na].codigo = cod;
                        cout << "Nombre: ";
                        getline(cin >> ws, a[na].nombre);
                        do
                        {
                            cout << "Creditos (> 0): ";
                            cin >> a[na].creditos;
                        } while (a[na].creditos <= 0);
                        na++;
                    }
                }
            }
            break;
        }
        case 3:
            if (ne == 0 || na == 0)
            {
                cout << "Se necesitan estudiantes y asignaturas." << endl;
            }
            else if (nm == MAXM)
            {
                cout << "Capacidad de matriculas llena." << endl;
            }
            else
            {
                int codE, codA;
                cout << "Codigo del estudiante: ";
                cin >> codE;
                cout << "Codigo de la asignatura: ";
                cin >> codA;
                if (buscarEstudiante(e, ne, codE) == -1)
                {
                    cout << "El estudiante no existe." << endl;
                }
                else if (buscarAsignatura(a, na, codA) == -1)
                {
                    cout << "La asignatura no existe." << endl;
                }
                else if (existeMatricula(m, nm, codE, codA))
                {
                    cout << "El estudiante ya esta matriculado en esa asignatura." << endl;
                }
                else
                {
                    m[nm].numero = nm + 1;
                    m[nm].codigoEstudiante = codE;
                    m[nm].codigoAsignatura = codA;
                    do
                    {
                        cout << "Nota (0-10): ";
                        cin >> m[nm].nota;
                    } while (m[nm].nota < 0 || m[nm].nota > 10);
                    nm++;
                    cout << "Matricula registrada." << endl;
                }
            }
            break;
        case 4:
        case 5:
            if (ne == 0)
            {
                cout << "No hay estudiantes." << endl;
            }
            else
            {
                int cod;
                cout << "Codigo del estudiante: ";
                cin >> cod;
                int pos = buscarEstudiante(e, ne, cod);
                if (pos == -1)
                {
                    cout << "El estudiante no existe." << endl;
                }
                else if (op == 4)
                {
                    cout << "Matriculas de " << e[pos].nombre << ":" << endl;
                    for (int i = 0; i < nm; i++)
                    {
                        if (m[i].codigoEstudiante == cod)
                        {
                            int pa = buscarAsignatura(a, na, m[i].codigoAsignatura);
                            cout << a[pa].nombre << " | nota " << m[i].nota << endl;
                        }
                    }
                }
                else
                {
                    int aprobadas;
                    float prom = promedioEstudiante(m, nm, cod, aprobadas);
                    cout << "Promedio de " << e[pos].nombre << ": " << prom << endl;
                    cout << "Asignaturas aprobadas: " << aprobadas << endl;
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
