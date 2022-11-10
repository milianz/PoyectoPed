//listas
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <Windows.h>
using namespace std;
struct Nodo
{   
    int win,lose;
    string equipo, conferencia;
    Nodo *next;
};
Nodo *list=NULL;
void insertarEquipo(Nodo *&list, string nom,int w,int l,string conference){ 
    Nodo *NodoN =new Nodo;
    NodoN->equipo=nom;
    NodoN->win=w;
    NodoN->lose=l;
    NodoN->conferencia=conference;
    NodoN->next=NULL;
    if(list==NULL){
        list=NodoN;
    }else{
        Nodo *p=list;
        Nodo *q=NULL;
        while (p!=NULL)
        {
          q=p;
          p=p->next;
        }
        q->next=NodoN;
    }   
}
void mostarLista(Nodo *list){
    Nodo *temporal;
    temporal=list;
    if(temporal!=NULL){
        cout<<"Ultimos equipos agregados:"<<endl;
        cout<<"\n"<<"Equipo"<<"\t\t"<<"W"<<"\t"<<"L"<<"\t"<<"conferencia"<<endl; 
        while (temporal!=NULL)
        {
            cout<<temporal->equipo<<"\t\t"<<temporal->win<<"\t"<<temporal->lose<<"\t"<<temporal->conferencia<<"\n";
            temporal=temporal->next;
        }
        system("pause");
    }
    else{
        cout<<"lista vacia"<<endl;
        system("pause");
    }
}
void clearList(Nodo *&list){
}

void case1(){
    ofstream archivo;
    int l,w;
    string Name,conference;
        archivo.open("TablaPosiciones.txt", ios::out|ios::app);//creacion del archivo o abrir el archivo
        if(archivo.fail()){
        cout<<"no se pudo abrir el archivo";
        exit(1);
        }

        fflush(stdin);
        cout<<"Ingrese el nombre del equipo: ";
        getline(cin,Name);
        cout<<"Ingresar el numero de Victorias: ";
        cin>>w;
        cout<<"Ingresar el numero de Derrotas: ";
        cin>>l;
        fflush(stdin);
        cout<<"Ingrese la conferencia del equipo: ";
        getline(cin,conference);
        insertarEquipo(list,Name,w,l,conference);
        archivo<<Name<<"\t\t"<<w<<"\t"<<l<<"\t"<<conference<<"\n";
        archivo.close(); 
        
}
void cargarFichero(){
    ifstream lec;
    int l,w;
    string Name,conference;
    lec.open("TablaPosiciones.txt", ios::in);
    while(!lec.eof()){
    lec>>Name>>w>>l>>conference;
    if(!lec.eof()){
        Nodo *NodoN =new Nodo;
        NodoN->equipo=Name;
        NodoN->win=w;
        NodoN->lose=l;
        NodoN->conferencia=conference;
        NodoN->next=NULL;
    if(list==NULL){
        list=NodoN;
    }else{
        Nodo *p=list;
        Nodo *q=NULL;
        while (p!=NULL)
        {
          q=p;
          p=p->next;
        }
        q->next=NodoN;
    }   
    }
    }
}
void buscarEquipo(){
    system("cls");
    ifstream lec;
    lec.open("TablaPosiciones.txt", ios::in);
    int win,lose;
    string nom,conf, aux_nom;
    bool encontrado = false;
    fflush(stdin);
    cout<<"Digite el nombre del equipo: ";
    getline(cin,aux_nom);
    lec>>nom;
    cout<<"\n"<<"Equipo"<<"\t\t"<<"W"<<"\t"<<"L"<<"\t"<<"conferencia"<<endl;
    while (!lec.eof()&& !encontrado )
    {
        lec>>win;
        lec>>lose;
        lec>>conf;
        if(nom==aux_nom){
            cout<<nom<<"\t\t"<<win<<"\t"<<lose<<"\t"<<conf<<endl;
            encontrado=true;
        }
       lec>>nom;
    }
    lec.close();
    if(!encontrado)
        cout<<"Equipo no encontrado"<<endl;
    system("pause");
}
int main(){
    
    
    int opc;
    do
    {
        cout << "  .:MENU:." <<  endl;
        cout << "1. Ingresar Datos de los equipos." <<endl;
        cout << "2. Ver los ultimos equipos agregados." <<endl;
        cout << "3. Ver tabla de equipos." <<endl;
        cout<< "4. Buscar equipo."<<endl;
        cout << "0. Salir." <<endl;
        cout << "Opcion: ";
        cin >> opc;

        switch (opc)
        {
        case 1:
                case1();
            break;
        case 2:
                mostarLista(list);
        break;
        case 3:
                cargarFichero();
                mostarLista(list);
                clearList(list);
           // 
        break;
        case 4:
                buscarEquipo();
        break;
        case 0:
        break;
        default:
                cout<<"Esa opcion no extiste:(, favor degite una correcta"<<endl;
                 system("pause");
            break;
        }
        system("cls");
    } while (opc != 0);
    cout << "Adios...";
    return 0;
}



