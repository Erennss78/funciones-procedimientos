#include <iostream>
#include <string>
using namespace std;

struct Curso
{
    int codigo;
    string nombre;
    int cupo;
};

struct Estudiante
{
    int codigo;
    string nombre;
};

struct Inscripcion
{
    int numero;
    int codigoCurso;
    int codigoEstudiante;
};

const int MAXC = 8;
const int MAXE = 30;
const int MAXI = 70;

int buscarCurso(const Curso c[], int n, int cod)
{
    int i = 0;
    while (i < n && c[i].codigo != cod)
    {
        i++;
    }
    if (i < n)
    {
        return i;
    }
    return -1;
}

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

bool yaInscrito(const Inscripcion ins[], int n, int codC, int codE)
{
    int i = 0;
    while (i < n && !(ins[i].codigoCurso == codC && ins[i].codigoEstudiante == codE))
    {
        i++;
    }
    return i < n;
}

int inscritosCurso(const Inscripcion ins[], int n, int codC)
{
    int cont = 0;
    for (int i = 0; i < n; i++)
    {
        if (ins[i].codigoCurso == codC)
        {
            cont++;
        }
    }
    return cont;
}

int cuposDisponibles(const Curso c[], int nc, const Inscripcion ins[], int ni, int codC)
{
    int pos = buscarCurso(c, nc, codC);
    return c[pos].cupo - inscritosCurso(ins, ni, codC);
}

int main()
{
    Curso c[MAXC];
    Estudiante e[MAXE];
    Inscripcion ins[MAXI];
    int nc = 0, ne = 0, ni = 0, op;

    do
    {
        cout << "\n1) Registrar cursos\n2) Registrar estudiantes\n3) Inscribir estudiante\n"
             << "4) Inscritos y cupos por curso\n5) Curso con mas inscripciones\n0) Salir\nOpcion: ";
        cin >> op;

        switch (op)
        {
        case 1:
        {
            int cant;
            cout << "Cuantos cursos desea agregar? ";
            cin >> cant;
            for (int k = 0; k < cant; k++)
            {
                if (nc == MAXC)
                {
                    cout << "Capacidad llena." << endl;
                }
                else
                {
                    int cod;
                    cout << "\nCodigo: ";
                    cin >> cod;
                    if (buscarCurso(c, nc, cod) != -1)
                    {
                        cout << "Codigo duplicado." << endl;
                    }
                    else
                    {
                        c[nc].codigo = cod;
                        cout << "Nombre: ";
                        getline(cin >> ws, c[nc].nombre);
                        do
                        {
                            cout << "Cupo (> 0): ";
                            cin >> c[nc].cupo;
                        } while (c[nc].cupo <= 0);
                        nc++;
                    }
                }
            }
            break;
        }
        case 2:
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
        case 3:
            if (nc == 0 || ne == 0)
            {
                cout << "Se necesitan cursos y estudiantes." << endl;
            }
            else if (ni == MAXI)
            {
                cout << "Capacidad de inscripciones llena." << endl;
            }
            else
            {
                int codC, codE;
                cout << "Codigo del curso: ";
                cin >> codC;
                cout << "Codigo del estudiante: ";
                cin >> codE;
                if (buscarCurso(c, nc, codC) == -1)
                {
                    cout << "El curso no existe." << endl;
                }
                else if (buscarEstudiante(e, ne, codE) == -1)
                {
                    cout << "El estudiante no existe." << endl;
                }
                else if (yaInscrito(ins, ni, codC, codE))
                {
                    cout << "El estudiante ya esta inscrito en ese curso." << endl;
                }
                else if (cuposDisponibles(c, nc, ins, ni, codC) == 0)
                {
                    cout << "El curso no tiene cupo." << endl;
                }
                else
                {
                    ins[ni].numero = ni + 1;
                    ins[ni].codigoCurso = codC;
                    ins[ni].codigoEstudiante = codE;
                    ni++;
                    cout << "Inscripcion registrada." << endl;
                }
            }
            break;
        case 4:
            if (nc == 0)
            {
                cout << "No hay cursos." << endl;
            }
            else
            {
                for (int i = 0; i < nc; i++)
                {
                    cout << "\n" << c[i].nombre << " | inscritos: " << inscritosCurso(ins, ni, c[i].codigo)
                         << " | cupos restantes: " << cuposDisponibles(c, nc, ins, ni, c[i].codigo) << endl;
                    for (int j = 0; j < ni; j++)
                    {
                        if (ins[j].codigoCurso == c[i].codigo)
                        {
                            int pe = buscarEstudiante(e, ne, ins[j].codigoEstudiante);
                            cout << "   - " << e[pe].nombre << endl;
                        }
                    }
                }
            }
            break;
        case 5:
            if (nc == 0 || ni == 0)
            {
                cout << "Se necesitan cursos e inscripciones." << endl;
            }
            else
            {
                int mayor = 0;
                for (int i = 1; i < nc; i++)
                {
                    if (inscritosCurso(ins, ni, c[i].codigo) > inscritosCurso(ins, ni, c[mayor].codigo))
                    {
                        mayor = i;
                    }
                }
                cout << "Curso con mas inscripciones: " << c[mayor].nombre << " ("
                     << inscritosCurso(ins, ni, c[mayor].codigo) << ")" << endl;
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
