#include <iostream>
#include <string>
using namespace std;

struct Paciente
{
    int codigo;
    string nombre;
    int edad;
};

struct Cita
{
    int numero;
    int codigoPaciente;
    string fecha;
    string especialidad;
    string estado;
};

const int MAXP = 15;
const int MAXC = 35;

int buscarPaciente(const Paciente p[], int n, int cod)
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

int buscarCita(const Cita c[], int n, int num)
{
    int i = 0;
    while (i < n && c[i].numero != num)
    {
        i++;
    }
    if (i < n)
    {
        return i;
    }
    return -1;
}

bool estadoValido(const string &e)
{
    return e == "pendiente" || e == "atendida";
}

void actualizarEstado(Cita c[], int n, int num, const string &nuevo)
{
    int pos = buscarCita(c, n, num);
    if (pos == -1)
    {
        cout << "La cita no existe." << endl;
    }
    else
    {
        c[pos].estado = nuevo;
        cout << "Estado actualizado." << endl;
    }
}

int main()
{
    Paciente p[MAXP];
    Cita c[MAXC];
    int np = 0, nc = 0, op;

    do
    {
        cout << "\n1) Registrar pacientes\n2) Registrar citas\n3) Consultar citas de un paciente\n"
             << "4) Cambiar estado de una cita\n5) Mostrar citas pendientes\n0) Salir\nOpcion: ";
        cin >> op;

        switch (op)
        {
        case 1:
        {
            int cant;
            cout << "Cuantos pacientes desea agregar? ";
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
                    if (buscarPaciente(p, np, cod) != -1)
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
                            cout << "Edad (0-120): ";
                            cin >> p[np].edad;
                        } while (p[np].edad < 0 || p[np].edad > 120);
                        np++;
                    }
                }
            }
            break;
        }
        case 2:
            if (np == 0)
            {
                cout << "Primero registre pacientes." << endl;
            }
            else
            {
                int cant;
                cout << "Cuantas citas desea agregar? ";
                cin >> cant;
                for (int k = 0; k < cant; k++)
                {
                    if (nc == MAXC)
                    {
                        cout << "Capacidad llena." << endl;
                    }
                    else
                    {
                        int num, codp;
                        string estado;
                        cout << "\nNumero de cita: ";
                        cin >> num;
                        cout << "Codigo del paciente: ";
                        cin >> codp;
                        if (buscarCita(c, nc, num) != -1)
                        {
                            cout << "Numero duplicado." << endl;
                        }
                        else if (buscarPaciente(p, np, codp) == -1)
                        {
                            cout << "El paciente no existe." << endl;
                        }
                        else
                        {
                            cout << "Fecha: ";
                            cin >> c[nc].fecha;
                            cout << "Especialidad: ";
                            getline(cin >> ws, c[nc].especialidad);
                            do
                            {
                                cout << "Estado (pendiente/atendida): ";
                                cin >> estado;
                            } while (!estadoValido(estado));
                            c[nc].numero = num;
                            c[nc].codigoPaciente = codp;
                            c[nc].estado = estado;
                            nc++;
                        }
                    }
                }
            }
            break;
        case 3:
            if (np == 0)
            {
                cout << "No hay pacientes." << endl;
            }
            else
            {
                int cod;
                cout << "Codigo del paciente: ";
                cin >> cod;
                int pos = buscarPaciente(p, np, cod);
                if (pos == -1)
                {
                    cout << "El paciente no existe." << endl;
                }
                else
                {
                    cout << "Citas de " << p[pos].nombre << ":" << endl;
                    for (int i = 0; i < nc; i++)
                    {
                        if (c[i].codigoPaciente == cod)
                        {
                            cout << c[i].numero << " | " << c[i].fecha << " | " << c[i].especialidad
                                 << " | " << c[i].estado << endl;
                        }
                    }
                }
            }
            break;
        case 4:
            if (nc == 0)
            {
                cout << "No hay citas." << endl;
            }
            else
            {
                int num;
                string nuevo;
                cout << "Numero de cita: ";
                cin >> num;
                do
                {
                    cout << "Nuevo estado (pendiente/atendida): ";
                    cin >> nuevo;
                } while (!estadoValido(nuevo));
                actualizarEstado(c, nc, num, nuevo);
            }
            break;
        case 5:
            if (nc == 0)
            {
                cout << "No hay citas." << endl;
            }
            else
            {
                cout << "--- CITAS PENDIENTES ---" << endl;
                for (int i = 0; i < nc; i++)
                {
                    if (c[i].estado == "pendiente")
                    {
                        cout << c[i].numero << " | " << c[i].fecha << " | " << c[i].especialidad << endl;
                    }
                }
                cout << "--- PENDIENTES POR ESPECIALIDAD ---" << endl;
                for (int i = 0; i < nc; i++)
                {
                    bool yaContada = false;
                    int j = 0;
                    while (j < i && !yaContada)
                    {
                        if (c[j].especialidad == c[i].especialidad)
                        {
                            yaContada = true;
                        }
                        j++;
                    }
                    if (!yaContada)
                    {
                        int cont = 0;
                        for (int k = 0; k < nc; k++)
                        {
                            if (c[k].especialidad == c[i].especialidad && c[k].estado == "pendiente")
                            {
                                cont++;
                            }
                        }
                        cout << c[i].especialidad << ": " << cont << endl;
                    }
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
