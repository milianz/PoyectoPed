#include <iostream>
#include <stdlib.h>
#include <String.h>
#include <fstream>

using namespace std;

struct Nodo
{
    char equipo[21], win[4], lose[4], conferencia[21];
    Nodo *next;
};

Nodo *ultimo, *primero, *actual, *nuevoNodo;

void CargarFichero()
{
    char equipo[21], win[4], lose[4], conferencia[21];
    ifstream archivo;

    //Abriendo el archivo de texto
    archivo.open("TablaPosiciones.txt", ios::in);

    //Mientras el archivo no este vacio
    while (!archivo.eof())
    {
        archivo >> equipo >> win >> lose >> conferencia;

        //validando que el archivo no este vacio
        if(!archivo.eof())
        {
            nuevoNodo = new Nodo();
            strcpy(nuevoNodo->equipo, equipo);
            strcpy(nuevoNodo->win, win);
            strcpy(nuevoNodo->lose, lose);
            strcpy(nuevoNodo->conferencia, conferencia);
            if(primero == NULL)
            {
                primero = nuevoNodo;
                primero->next = NULL;
                ultimo = primero;
            }
            else
            {
                ultimo->next = nuevoNodo;
                nuevoNodo->next = NULL;
                ultimo=nuevoNodo;
            }
        }
    }
    archivo.close();
}

void MostrarLista()
{
    actual=primero;
    while (actual != NULL)
    {
        cout <<"\n"<<actual->equipo << "\t\t" <<actual->win << "\t" << actual->lose << "\t" << actual->conferencia;
        actual = actual->next;
    }
    
}

void Menu()
{
    int opc;

    do
    {
        cout << "\n   .:MENU:." <<  endl;
        cout << "1. Mostrar Posiciones." <<endl;
        cout << "0. Salir." <<endl;
        cout << "\nOpcion: ";
        cin >> opc;

        switch (opc)
        {
        case 1:
            cout << "\nTABLA DE POSICIONES." << endl;
            CargarFichero();
            MostrarLista();
            cout << endl;

            system("pause");
            break;
        
        default:
            break;
        }
        system("cls");
    } while (opc != 0);
    cout << "Adios...";
}

int main()
{
    Menu();

    return 0;
}