#include <iostream>
#include <string>
using namespace std;

struct Matricula
{
    int codigo;
    string estudiante;
    string asignatura;
    float nota;
};

int main()
{
    const int MAX = 40;
    Matricula m[MAX];
    int n, cont = 0, menores = 0;
    float suma = 0;
    string asig;

    do
    {
        cout << "Cantidad de matriculas (1-" << MAX << "): ";
        cin >> n;
    } while (n < 1 || n > MAX);

    for (int i = 0; i < n; i++)
    {
        cout << "\n--- MATRICULA " << i + 1 << " ---" << endl;
        cout << "Codigo: ";
        cin >> m[i].codigo;
        cout << "Estudiante: ";
        getline(cin >> ws, m[i].estudiante);
        cout << "Asignatura: ";
        getline(cin >> ws, m[i].asignatura);
        do
        {
            cout << "Nota (0-10): ";
            cin >> m[i].nota;
        } while (m[i].nota < 0 || m[i].nota > 10);
    }

    cout << "\nAsignatura a consultar: ";
    getline(cin >> ws, asig);

    cout << "\n--- MATRICULAS DE " << asig << " ---" << endl;
    for (int i = 0; i < n; i++)
    {
        if (m[i].asignatura == asig)
        {
            cout << m[i].codigo << " | " << m[i].estudiante << " | " << m[i].nota << endl;
            suma += m[i].nota;
            cont++;
            if (m[i].nota < 7)
            {
                menores++;
            }
        }
    }

    if (cont == 0)
    {
        cout << "No hay matriculas para esa asignatura." << endl;
    }
    else
    {
        cout << "Nota promedio: " << suma / cont << endl;
        cout << "Estudiantes con nota menor a 7: " << menores << endl;
    }
    return 0;
}
