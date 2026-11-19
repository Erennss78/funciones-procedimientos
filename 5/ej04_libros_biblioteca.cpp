#include <iostream>
#include <string>
using namespace std;

struct Libro
{
    int codigo;
    string titulo;
    string autor;
    int anio;
};

int main()
{
    Libro l[5];
    int cont = 0;

    for (int i = 0; i < 5; i++)
    {
        cout << "\n--- LIBRO " << i + 1 << " ---" << endl;
        cout << "Codigo: ";
        cin >> l[i].codigo;
        cout << "Titulo: ";
        getline(cin >> ws, l[i].titulo);
        cout << "Autor: ";
        getline(cin >> ws, l[i].autor);
        cout << "Anio: ";
        cin >> l[i].anio;
    }

    cout << "\n--- LIBROS PUBLICADOS DESDE 2020 ---" << endl;
    for (int i = 0; i < 5; i++)
    {
        if (l[i].anio >= 2020)
        {
            cout << l[i].codigo << " | " << l[i].titulo << " | " << l[i].autor << " | " << l[i].anio << endl;
            cont++;
        }
    }
    cout << "Cantidad encontrada: " << cont << endl;
    return 0;
}
