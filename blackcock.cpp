#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <time.h>
#include <windows.h>
#include <iomanip>
#include <ctime>
#include <vector>

using namespace std;

enum Valor{ as, dos, tres, cuatro, cinco, seis, siete, ocho, nueve, diez, jack, queen, king};
        //  0    1    2      3       4     5     6      7     8      9     10    11    12
enum Tipo{ Corazones, Diamantes, Picas, Treboles};
        //     0          1        2      3

struct Carta{
    Valor valor;
    Tipo tipo;
    int num_tipos=4;
    int num_valores=13;
};

struct Mazo{
    vector <Carta> cartas;
    int max_cartas=52;
};

//declarando Funciones.
void PantallaDeCarga();
void calcularPorcentaje(int& numerador,int& denominador);
void creando_mazo(Mazo&);
void imprimiendo_mazo( const Mazo&);
int imprimir_carta(const Carta&);
void barajear_mazo(Mazo&);
bool repartir_cartas(Mazo&, vector<Carta>&, vector<Carta>&, int);
int print_hands(const vector<Carta>&, string);
bool repartir_cartas1(Mazo &mazo, vector<Carta> &jugador, int tirada);
int print_hands1(const vector<Carta> &hand);
void Juego();

//inicio del main.
int main ()
{
    Juego();

    return 0;
}
//fin del main.

//haciendo las funciones.
void PantallaDeCarga()
{
    char LCharacter= char(3);
    char LBar[51]={' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
    ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
    ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
    ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
    ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',0};
    int LCounter;
    Sleep(1000);
    for (LCounter= 0; LCounter<50; LCounter++){
        LBar[LCounter]=LCharacter;
        Sleep(100);
        system("cls");
        cout << "|************************************************************|" << endl;
        cout << "|*********** Bienvenido al Juego Blackjack o 21. ************|" << endl;
        cout << "|                                                            |" << endl;
        cout << "|                     ~~~ [REGLAS] ~~~                       |" << endl;
        cout << "|  -> El valor de los ACES(1) puede ser uno                  |" << endl;
        cout << "|  -> La Maquina gana los empates, al menos que tengas 21.   |" << endl;
        cout << "|                                                            |" << endl;
        cout << "|************************************************************|" << endl;
        cout << "|                                                            |" << endl;
        cout << "|                    ~~~ [VICTORIA] ~~~                      |" << endl;
        cout << "|  -> Para ganar tiene que tener una puntuacion igual o      |" << endl;
        cout << "|     cercana a 21.                                          |" << endl;
        cout << "|                                                            |" << endl;
        cout << "|************************************************************|" << endl;
        cout << "|"<<setw(40)<<"Cargando Juego..."<<"                    |"<<endl;
        cout << "|"<<setw(55)<<LBar<<"     |"<<endl;
        cout << "|************************************************************|";
    }
}


void Juego()
{
    vector <Carta> jugador;
    vector <Carta> maquina;
    Mazo mi_mazo;
    double den=0, porcentaje=0, car=0;
    int continuar = 0,opc2=0,acomulador=0;
    string str1="humano";
    string str2="maquina";

    creando_mazo(mi_mazo);
    barajear_mazo(mi_mazo);

    system ("cls");
    PantallaDeCarga();

    cout << "\nDesea Jugar? 1||Si 0||No." << endl;
    cout << "Opcion-> ";
    cin >> continuar;
    
    char opc;

    system ("cls");
    if(continuar ==1)
    {
        cout<<"Desea jugar contra la maquina o en solitario?\n";
        cout<<"1- Maquina.\n";
        cout<<"2- Jugar solo.\n";
        cout << "Opcion-> ";
        cin >> opc2;
        if(opc2==1)
        {
            do
            {   
                system("cls");
                cout << "Desea pedir una carta? s||Si n||No" << endl;
                cout << "-> ";
                cin >> opc;

                if(opc == 's' || opc == 'S')
                {
                    repartir_cartas(mi_mazo,jugador,maquina,1);
                    print_hands(jugador,str1);
                    cout<<"------------------carta del Jugador----------------------"<<endl;
                    system("pause");
                    cout<<"carta de la maquina: \n";
                    print_hands(maquina,str2);
                    cout<<"------------------carta del Maquina----------------------"<<endl;
                    system("pause");
                }
            } 
            while (opc == 's' || opc == 'S');
       
        }
        if (opc2==2)
        {
            do
            {
                system("cls");
                cout << "Desea pedir una carta? s||Si n||No" << endl;
                cout << "-> ";
                cin >> opc;

                if (opc == 's' || opc == 'S')
                {   
                    acomulador=acomulador+1;
                    repartir_cartas1(mi_mazo, jugador, 1);
                    print_hands1(jugador);
                    cout<<endl;
                    cout<<"ingrese cuantas cartas se pasan de 21->";
                    cin>>car;
                    if(car==0){
                        cout<<"La probabilidad de que se pase de 21 es: 0%"<<endl;
                    }else{
                    den=52-acomulador;
                    porcentaje=(car/den)*100;
                    cout<<"La probabilidad de que se pase de 21 es: "<<porcentaje<<"%"<<endl;
                    }
                    cout << "------------------carta del Jugador----------------------" << endl;
                    system("pause");
                }
            } 
            while (opc == 's' || opc == 'S');
        }
    }  
}

void creando_mazo(Mazo& mazo)
{
    Carta carta;

    for(int tipo=0;tipo<carta.num_tipos;tipo++)
    {
        for(int valor=0; valor<carta.num_valores;valor++)
        {
            carta.tipo=Tipo(tipo);
            carta.valor=Valor(valor);
            mazo.cartas.push_back(carta);
        }
    }
}

void imprimiendo_mazo( const Mazo& mazo)
{
    for(Carta c:mazo.cartas)
    {
        imprimir_carta(c);
    }
}

int imprimir_carta(const Carta& carta){
int cartax=0,puntosJugador=0,as=0;
int numero;
string valor,tipo;

if (carta.tipo==0)
{
    tipo="Corazones";
}
if (carta.tipo==1){
     tipo="Diamantes";
}
if (carta.tipo==2){
     tipo="Picas";
}
if (carta.tipo==3){
    tipo="Treboles";
}
if(carta.valor==0){
cout << "\nObtuvo un AS de "<<tipo;
cartax=1;

}
if(carta.valor==1){
cout << "\nObtuvo un 2 de "<<tipo;
cartax=2;
}
if(carta.valor==2){
cout << "\nObtuvo un 3 de "<<tipo;
cartax=3;
}
if(carta.valor==3){
    cout << "\nObtuvo un 4 de "<<tipo;
cartax=4;
}
if(carta.valor==4){
    cout << "\nObtuvo un 5 de "<<tipo;
 cartax=5;
}
if(carta.valor==5){
    cout << "\nObtuvo un 6 de "<<tipo;
 cartax=6;
}
if(carta.valor==6){
    cout << "\nObtuvo un 7 de "<<tipo;
 cartax=7;
}
if(carta.valor==7){
    cout << "\nObtuvo un 8 de "<<tipo;
 cartax=8;
}
if(carta.valor==8){
cout << "\nObtuvo un 9 de "<<tipo;
 cartax=9;
}
if(carta.valor==9){
cout << "\nObtuvo un 10 de "<<tipo;
 cartax=10;
}
if(carta.valor==10){
cout << "\nObtuvo un J de "<<tipo;
 cartax=10;
}
if(carta.valor==11){
cout << "\nObtuvo un Q de "<<tipo;
 cartax=10;
}
if(carta.valor==12){
cout << "\nObtuvo un K de "<<tipo;
 cartax=10;}

puntosJugador+=cartax;
return puntosJugador;
}

void barajear_mazo(Mazo& mazo)
{
    srand( time(NULL));
    Mazo barajeado;
    int num;
    num=rand();
    for (int i = 0; i <num ; i++)
    {
        while(!mazo.cartas.empty())
        {
        size_t rand_index = rand() % mazo.cartas.size();
        barajeado.cartas.push_back(mazo.cartas[rand_index]);
        mazo.cartas.erase(mazo.cartas.begin() + rand_index);
        }
    }
    mazo=barajeado;
}

bool repartir_cartas(Mazo& mazo, vector<Carta>& jugador, vector<Carta>& maquina, int tirada)
{
    if(mazo.cartas.size()<2*tirada)
    {
        return false;
    }
    
    for (int i = 0; i < tirada; i++)
    {
        jugador.push_back(mazo.cartas[0]);
        mazo.cartas.erase(mazo.cartas.begin());
        maquina.push_back(mazo.cartas[0]);
        mazo.cartas.erase(mazo.cartas.begin());
    }
    return true;
}

int print_hands(const vector<Carta>& hand,string player)
{
    int valor=0;
    string aux1="humano";
    string aux2="maquina";
    system("cls");

    for(Carta c: hand)
    {
        valor+=imprimir_carta(c);
    }
    cout<<endl<<"La suma de sus cartas es: "<<valor<<endl;
    if(valor > 21)
    {
        system("cls");
        cout << "|************************************************************|" << endl;
        cout << "|*************** Derrota! Excedio 21 puntos. ****************|" << endl; 
        if(player==aux1)
        {
            cout << "|***************Gana "<<aux2<<" ********************************|"<<endl;
        }
        else
        {
            cout << "|***************Gana "<<aux1<<" ********************************|"<<endl;
        }
            cout << "|************************************************************|" << endl;
            cout << "\n";
        exit(1);
    }

    if(valor==21)
    {
        system("cls");
        cout << "|************************************************************|" << endl;
        cout << "|********* Victoria!!!!!! la puntuacion es de 21 ************|" << endl;
        if(player==aux1)
        {
            cout << "|**********************"<<aux1<<"*****************************|"<<endl;
        }
        else
        {
            cout << "|**********************"<<aux2<<"*****************************|"<<endl;
        }
        cout << "|************************************************************|" << endl;
        cout << "\n";
        exit(1);
    }
}

bool repartir_cartas1(Mazo &mazo, vector<Carta> &jugador, int tirada)
{
    if (mazo.cartas.size() < 2 * tirada)
    {
        return false;
    }

    for (int i = 0; i < tirada; i++)
    {
        jugador.push_back(mazo.cartas[0]);
        mazo.cartas.erase(mazo.cartas.begin());
    }
    return true;
}

int print_hands1(const vector<Carta> &hand)
{
    int valor = 0;
    
    system("cls");
    for (Carta c : hand)
    {
        valor += imprimir_carta(c);
        
    }
    cout << "\nLa suma de sus cartas es: " << valor;
    if(valor==21)
    {
        system("cls");
        cout << "|************************************************************|" << endl;
        cout << "|********* Victoria!!!!!! la puntuacion es de 21 ************|" << endl;
        cout << "|************************************************************|" << endl;
        cout << "\n";
        exit(1);
    }
}