#include <iostream>
#include <string>
using namespace std;

struct Empleado
{
    int codigo;
    string nombre;
    float sueldo;
};

const int N = 10;

int buscar(const Empleado v[], int n, int cod)
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

void actualizarSueldo(Empleado v[], int n, int cod, float nuevo)
{
    int pos = buscar(v, n, cod);
    if (pos == -1)
    {
        cout << "El empleado no existe." << endl;
    }
    else
    {
        v[pos].sueldo = nuevo;
        cout << "Sueldo actualizado." << endl;
    }
}

int main()
{
    Empleado e[N];
    int n = 0, op;

    do
    {
        cout << "\n1) Registrar empleados\n2) Mostrar empleados\n3) Buscar empleado por codigo\n"
             << "4) Actualizar sueldo\n0) Salir\nOpcion: ";
        cin >> op;

        switch (op)
        {
        case 1:
            for (int i = 0; i < N; i++)
            {
                cout << "\n--- EMPLEADO " << i + 1 << " ---" << endl;
                cout << "Codigo: ";
                cin >> e[i].codigo;
                cout << "Nombre: ";
                getline(cin >> ws, e[i].nombre);
                do
                {
                    cout << "Sueldo (> 0): ";
                    cin >> e[i].sueldo;
                } while (e[i].sueldo <= 0);
            }
            n = N;
            break;
        case 2:
            if (n == 0)
            {
                cout << "No hay empleados registrados." << endl;
            }
            else
            {
                for (int i = 0; i < n; i++)
                {
                    cout << e[i].codigo << " | " << e[i].nombre << " | " << e[i].sueldo << endl;
                }
            }
            break;
        case 3:
            if (n == 0)
            {
                cout << "No hay empleados registrados." << endl;
            }
            else
            {
                int cod;
                cout << "Codigo: ";
                cin >> cod;
                int pos = buscar(e, n, cod);
                if (pos == -1)
                {
                    cout << "El empleado no existe." << endl;
                }
                else
                {
                    cout << e[pos].codigo << " | " << e[pos].nombre << " | " << e[pos].sueldo << endl;
                }
            }
            break;
        case 4:
            if (n == 0)
            {
                cout << "No hay empleados registrados." << endl;
            }
            else
            {
                int cod;
                float nuevo;
                cout << "Codigo: ";
                cin >> cod;
                do
                {
                    cout << "Sueldo nuevo (> 0): ";
                    cin >> nuevo;
                } while (nuevo <= 0);
                actualizarSueldo(e, n, cod, nuevo);
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
