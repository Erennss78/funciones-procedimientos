#include <iostream>
#include <string>
using namespace std;

struct Producto
{
    int codigo;
    string nombre;
    float precio;
};

void mostrar(const Producto v[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << v[i].codigo << " | " << v[i].nombre << " | " << v[i].precio << endl;
    }
}

int main()
{
    const int N = 8;
    Producto p[N];

    for (int i = 0; i < N; i++)
    {
        cout << "\n--- PRODUCTO " << i + 1 << " ---" << endl;
        cout << "Codigo: ";
        cin >> p[i].codigo;
        cout << "Nombre: ";
        getline(cin >> ws, p[i].nombre);
        do
        {
            cout << "Precio (>= 0): ";
            cin >> p[i].precio;
        } while (p[i].precio < 0);
    }

    cout << "\n--- ANTES DE ORDENAR ---" << endl;
    mostrar(p, N);

    for (int i = 0; i < N - 1; i++)
    {
        for (int j = 0; j < N - 1 - i; j++)
        {
            if (p[j].precio > p[j + 1].precio)
            {
                Producto aux = p[j];
                p[j] = p[j + 1];
                p[j + 1] = aux;
            }
        }
    }

    cout << "\n--- DESPUES DE ORDENAR (precio ascendente) ---" << endl;
    mostrar(p, N);
    return 0;
}
