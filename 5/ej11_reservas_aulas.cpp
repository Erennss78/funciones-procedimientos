#include <iostream>
#include <string>
using namespace std;

struct Reserva
{
    int numero;
    string aula;
    int hora;
    string responsable;
};

int main()
{
    const int MAX = 50;
    Reserva r[MAX];
    int n, cont = 0;
    string aula;

    do
    {
        cout << "Cantidad de reservas (1-" << MAX << "): ";
        cin >> n;
    } while (n < 1 || n > MAX);

    for (int i = 0; i < n; i++)
    {
        cout << "\n--- RESERVA " << i + 1 << " ---" << endl;
        cout << "Numero: ";
        cin >> r[i].numero;
        cout << "Aula: ";
        getline(cin >> ws, r[i].aula);
        do
        {
            cout << "Hora (0-23): ";
            cin >> r[i].hora;
        } while (r[i].hora < 0 || r[i].hora > 23);
        cout << "Responsable: ";
        getline(cin >> ws, r[i].responsable);
    }

    cout << "\nAula a consultar: ";
    getline(cin >> ws, aula);

    cout << "\n--- RESERVAS DEL AULA " << aula << " ---" << endl;
    for (int i = 0; i < n; i++)
    {
        if (r[i].aula == aula)
        {
            cout << r[i].numero << " | " << r[i].hora << ":00 | " << r[i].responsable << endl;
            cont++;
        }
    }
    cout << "Total de reservas: " << cont << endl;
    return 0;
}
