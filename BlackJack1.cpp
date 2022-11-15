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
void creando_mazo(Mazo&);
void imprimiendo_mazo( const Mazo&);
void imprimir_carta(const Carta&);
void barajear_mazo(Mazo&);
bool repartir_cartas(Mazo&, vector<Carta>&, vector<Carta>&, int);
void print_hand(const vector<Carta>&);
void Juego();
//inicio del main.
int main (){
Juego();
return 0;
}
//fin del main.

//haciendo las funciones.
void PantallaDeCarga(){
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
        cout << "|  -> El valor de los ACES(1) puede ser uno u once.          |" << endl;
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
void Juego(){
vector <Carta> jugador;
vector <Carta> maquina;
Mazo mi_mazo;
creando_mazo(mi_mazo);
barajear_mazo(mi_mazo);
    int continuar = 0,opc2=0;
    system ("cls");
    PantallaDeCarga();
    cout << "\nDesea Jugar? 1||Si 0||No." << endl;
    cout << "Opcion->";
    cin >> continuar;
    char opc;
    if(continuar = 1)
    {
    cout<<"Desea Jugar contra la maquina o con amigos:\n";
    cout<<"1- Maquina.\n";
    cout<<"2- Amigos.\n";
    cout << "Opcion->";
    cin >> opc2;
    if(opc2=1)
    {
        do{   
    system("cls");
    cout << "Desea pedir una carta? s||Si n||No" << endl;
    cout << "-> ";
    cin >> opc;
    if(opc == 's' || opc == 'S'){
            repartir_cartas(mi_mazo,jugador,maquina,1);
            print_hand(jugador);
            cout<<endl;
            cout<<"La suma de sus cartas es: ";
            system("pause");
    }
        } while (opc == 's' || opc == 'S');
       
    }
}
}
void creando_mazo(Mazo& mazo){
    Carta carta;
    for(int tipo=0;tipo<carta.num_tipos;tipo++){
        for(int valor=0; valor<carta.num_valores;valor++){
            carta.tipo=Tipo(tipo);
            carta.valor=Valor(valor);
            mazo.cartas.push_back(carta);
        }
    }
}
void imprimiendo_mazo( const Mazo& mazo){
    for(Carta c:mazo.cartas){
        imprimir_carta(c);
    }
}
void imprimir_carta(const Carta& carta){string tipo, valor;
        int valnum=0;
if(carta.valor==0){
valor="su carta es un AS";

}
if(carta.valor==1){
 valor="su carta es un 2";
 
}
if(carta.valor==2){
    valor="su carta es un 3";   
}
if(carta.valor==3){
    valor="su carta es un 4";
}
if(carta.valor==4){
    valor="su carta es un 5";
}
if(carta.valor==5){
    valor="su carta es un 6";
}
if(carta.valor==6){
    valor="su carta es un 7";
}
if(carta.valor==7){
    valor="su carta es un 8";
}
if(carta.valor==8){
valor="su carta es un 9";
}
if(carta.valor==9){
valor="su carta es un 10";
}
if(carta.valor==10){
valor="su carta es una J";
}
if(carta.valor==11){
valor="su carta es una Q";
}
if(carta.valor==12){
valor="su carta es una K";
}
if (carta.tipo==0){
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
        
    cout<<valor<<" de "<<tipo<<"."<<endl;
}
void barajear_mazo(Mazo& mazo){
srand( time(NULL));
Mazo barajeado;
int num;
num=rand();
for (int i = 0; i <num ; i++)
{
    while(!mazo.cartas.empty()){
    size_t rand_index = rand() % mazo.cartas.size();
    barajeado.cartas.push_back(mazo.cartas[rand_index]);
    mazo.cartas.erase(mazo.cartas.begin() + rand_index);
    }
}

mazo=barajeado;
}
bool repartir_cartas(Mazo& mazo, vector<Carta>& jugador, vector<Carta>& maquina, int tirada){
    if(mazo.cartas.size()<2*tirada){
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
void print_hand(const vector<Carta>& hand){
    for(Carta c: hand){
        imprimir_carta(c);
    }
}
