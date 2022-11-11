#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <time.h>
#include<windows.h>
#include <iomanip>
#include <ctime>
using namespace std;

//funcion para escoger una palabra de alphabet aleatoreamente
void NombreCartA(){
const int array_size=4;
srand(time(0));
string alphabet[array_size] ={"Corazones","Diamantes","Treboles","Picas"};

int index= rand()%array_size;
cout<<" de "<<alphabet[index]<<endl;
}

//Funcion para generar un numero aleatorio.
int Random(int min, int max) //rango : [min, max]
{
static bool first = true;
    if (first) 
    {
        srand( time(NULL) ); 
        first = false;
    }
return min + rand() % (( max + 1 ) - min);
}

//Funcion para calcular los puntos de la maquina.
int CartasMaquina(int valor)
{
    int carta = 0, puntosMaquina = 0;

    while(valor>puntosMaquina && puntosMaquina<21)
    {
        //Generando un valor aleatorio de 1 a 11.
        carta = Random(1, 11); 
        
        //Validando el valor de 1
        if(carta == 1)
        {
            puntosMaquina += 11;
            if(puntosMaquina > 21)
            {
            puntosMaquina += 1;
            }
            carta = 0;
        }
        //Si el numero generado es mayor que 10 su valor sera 10.
        if (carta > 10)
        {
            carta = 10;
        }

        //Validar si la maquina se paso de puntos.
        if(puntosMaquina > 21)
        {
            cout << "\nVictoria! la maquina se paso de puntos."<<endl;
            cout << "Tu puntuacion: " << valor << " VS " << "Puntuacion de la maquina: " << puntosMaquina << endl;
            cout << "\n";
            exit(1);
        } 
    }
    return puntosMaquina;
}

//Funcion para calcular los puntos del jugador.
int CartasJugador()
{
    int numero;
    int carta = 0, puntosJugador = 0, as = 0;
    
    carta = Random(1, 12);
    //validando el valor de 1.
    if(carta == 1)
    {
        cout << "\nObtuvo un AS. Que valor desea asignarle? 1 || 11" << endl;
        cout << "Valor: ";
        cin >> as;
        
        switch (as)
        {
        case 1:
            carta = 1;
            break;

        case 11:
            carta = 11;
            break;

        default:
            cout << "El valor solo puede ser 1 u 11" << endl;
            break;
        }
    }
    if(carta==2){
   cout<<"Su numero de carta es 2";
   NombreCartA();
   cout<<endl;
    }
     if(carta==3){
        cout<<"Su numero de carta es 3";
        NombreCartA();
        cout<<endl;
        
    } if(carta==4){
        cout<<"Su numero de carta es 4";
        NombreCartA();
   cout<<endl;
    }
     if(carta==5){
        cout<<"Su numero de carta es 5";
        NombreCartA();
   cout<<endl;
    } 
    if(carta==6){
        cout<<"Su numero de carta es 6";
        NombreCartA();
   cout<<endl;
        
    } 
    if(carta==7){
        cout<<"Su numero de carta es 7";
        NombreCartA();
   cout<<endl;
    } 
    if(carta==8){
        cout<<"Su numero de carta es 8";
        NombreCartA();
   cout<<endl;
    } 
    if(carta==9){
        cout<<"Su numero de carta es 9";
        NombreCartA();
   cout<<endl;
        
    } 
    if(carta==10){
        cout<<"Su numero de carta es 10";
        NombreCartA();
   cout<<endl;
        
    }
    if(carta==12){
        //carta 11 igual a los comodines que hagarra de alphabet 
        srand(time(NULL));
        string alphabet = "JQK";
        char ch = alphabet[rand() % alphabet.size()];
        cout << "\nObtuvo "<<ch<< endl;
        NombreCartA();
        cout<<endl;
        cout<<"Y el valor de esa carta es 10"<<endl;

    }
    else
    {
        //Si el numero generado es mayor qsue 10 su valor sera 10.
        if(carta > 10)
        {
            carta = 10;
        }
    }
    
    puntosJugador += carta;

    return puntosJugador;
}
//bienvenida Actualizada
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

void Juego()
{
    int continuar = 0;
    system ("cls");
    PantallaDeCarga();
    cout << "\nDesea Jugar? 1||Si 0||No." << endl;
    cout << "Opcion->";
    cin >> continuar;
    char opc;
    int opc2;
    int valor = 0, puntosMaq;
    if(continuar == 1)
    {
       cout<<"Desea Jugar contra la maquina o con amigos:\n";
       cout<<"1- Maquina.\n";
       cout<<"2- Amigos.\n";
       cout << "Opcion->";
       cin >> opc2;
       if(opc2==1)
                {
                    do
                    {   
                        system("cls");
                        cout << "Desea una carta? s||Si n||No" << endl;
                        cout << "Opcion: ";
                        cin >> opc;

                        if(opc == 's' || opc == 'S')
                        {
                            valor += CartasJugador();
                            cout << "Puntos actuales: " << valor << "." << endl; 

                        }
                        if(valor > 21)
                        {
                            cout << "\nDerrota! Excedio 21 puntos." << endl;
                            cout << "\n";
                            exit(1);
                        }

                        cout << "\n";
                        system ("pause");

                    } while (opc == 's' || opc == 'S');

                        system("cls");
                        if(valor <= 21)
                        {
                            puntosMaq = CartasMaquina(valor);
                        }
                        if(puntosMaq > valor || puntosMaq == valor)
                        {
                            cout << "\nDerrota! La maquina tiene mayor puntuacion." << endl;
                            cout << "Tu puntuacion: " << valor << " VS " << "Puntuacion de la maquina: " << puntosMaq << endl;
                            cout << "\n";
                        }
                }
    else if (opc2==2)
    {
        cout<<"En proceso.."<<endl;
    }
    else{
        cout<<"esa opcion no existe";
    }
    }
    else{
        cout<<"no existe";
    }
}

int main (){
Juego();
return 0;
}