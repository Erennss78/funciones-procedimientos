#include <iostream>
#include <string>
using namespace std;

struct Jugador
{
    int numero;
    string nombre;
    int partidos;
    int goles;
};

int main()
{
    const int MAX = 30;
    Jugador j[MAX];
    int n, goleador = 0, totalGoles = 0;

    do
    {
        cout << "Cantidad de jugadores (1-" << MAX << "): ";
        cin >> n;
    } while (n < 1 || n > MAX);

    for (int i = 0; i < n; i++)
    {
        cout << "\n--- JUGADOR " << i + 1 << " ---" << endl;
        cout << "Numero: ";
        cin >> j[i].numero;
        cout << "Nombre: ";
        getline(cin >> ws, j[i].nombre);
        do
        {
            cout << "Partidos (>= 0): ";
            cin >> j[i].partidos;
        } while (j[i].partidos < 0);
        do
        {
            cout << "Goles (>= 0): ";
            cin >> j[i].goles;
        } while (j[i].goles < 0);

        totalGoles += j[i].goles;
        if (j[i].goles > j[goleador].goles)
        {
            goleador = i;
        }
    }

    cout << "\nGoleador: " << j[goleador].nombre << " con " << j[goleador].goles << " goles" << endl;
    cout << "Total de goles del equipo: " << totalGoles << endl;

    cout << "\n--- JUGADORES CON PROMEDIO GOLES/PARTIDOS > 0.5 ---" << endl;
    for (int i = 0; i < n; i++)
    {
        if (j[i].partidos > 0 && (float)j[i].goles / j[i].partidos > 0.5)
        {
            cout << j[i].numero << " | " << j[i].nombre << " | " << (float)j[i].goles / j[i].partidos << endl;
        }
    }
    return 0;
}
