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
void agregarEqupo(){

}
void ordenar_lista_wins(){
    Nodo *actual_i,*actual_j,*aux;
    if(primero==NULL){
        cout<<"lista vacia";
    }
    else{
        actual_i=primero;
        while(actual_i!=NULL){
           actual_j=actual_i->next;
           while(actual_j!=NULL){
            //comparacion
            if(actual_i->win>actual_j->win){
                aux=new Nodo();
                //guardar actual_i en aux
                strcpy(aux->equipo,actual_i->equipo);
                strcpy(aux->win,actual_i->win);
                strcpy(aux->lose,actual_i->lose);
                strcpy(aux->conferencia,actual_i->conferencia);
                //pasar actual_j a actual_i
                strcpy(actual_i->equipo,actual_j->equipo);
                strcpy(actual_i->win,actual_j->win);
                strcpy(actual_i->lose,actual_j->lose);
                strcpy(actual_i->conferencia,actual_j->conferencia);
                //auxiliar a actual_j
                strcpy(actual_j->equipo,aux->equipo);
                strcpy(actual_j->win,aux->win);
                strcpy(actual_j->lose,aux->lose);
                strcpy(actual_j->conferencia,aux->conferencia);
            }
            actual_j=actual_j->next;
           }
           actual_i=actual_i->next;
        }
    }
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

        cout << "1. Mostrar Posiciones.(Ordenada por wins)" <<endl;
        cout << "0. Salir." <<endl;
        cout << "\nOpcion: ";
        cin >> opc;

        switch (opc)
        {
        case 1:
            cout << "\nTABLA DE POSICIONES.(Ordenada por wins)" << endl;
            CargarFichero();
            ordenar_lista_wins();
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