#include <iostream>
#include <string>
using namespace std;

struct Libro
{
    int codigo;
    string titulo;
    string autor;
};

int buscarLibro(const Libro v[], int n, int codigo)
{
    int i = 0;
    while (i < n && v[i].codigo != codigo)
    {
        i++;
    }
    if (i < n)
    {
        return i;
    }
    return -1;
}

int main()
{
    const int MAX = 20;
    Libro l[MAX];
    int n, cod;

    do
    {
        cout << "Cantidad de libros (1-" << MAX << "): ";
        cin >> n;
    } while (n < 1 || n > MAX);

    for (int i = 0; i < n; i++)
    {
        cout << "\n--- LIBRO " << i + 1 << " ---" << endl;
        cout << "Codigo: ";
        cin >> l[i].codigo;
        cout << "Titulo: ";
        getline(cin >> ws, l[i].titulo);
        cout << "Autor: ";
        getline(cin >> ws, l[i].autor);
    }

    cout << "\nCodigo a buscar: ";
    cin >> cod;
    int pos = buscarLibro(l, n, cod);

    if (pos == -1)
    {
        cout << "El libro no existe." << endl;
    }
    else
    {
        cout << "Encontrado: " << l[pos].codigo << " | " << l[pos].titulo << " | " << l[pos].autor << endl;
    }
    return 0;
}
