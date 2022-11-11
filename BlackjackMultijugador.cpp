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

int CartasMaquina2(){
    int numero;
    int carta = 0, puntosMaquina = 0, as = 0;
    int comodin=11;
    int comodin2=10;
    carta = Random(1, 12);
    //validando el valor de 1.
    if(carta == 1)
    {
       // cout << "\n la Maquina Obtuvo un AS. Que valor desea asignarle? 1 || 11" << endl;
        as=Random(1,2);
        
        switch (as)
        {
        case 1:
            carta = 1;
            break;

        case 2:
            carta = comodin;
            break;

        default:
            //cout << "El valor solo puede ser 1 u 11" << endl;
            break;
        }
    }
    if(carta==2){
    //cout<<"la carta de la maquina es 2";
    //NombreCartA();
    //cout<<endl;
    }
     if(carta==3){
        //cout<<"la carta de la maquina es 3 ";
        //NombreCartA();
        //cout<<endl;
        
    } if(carta==4){
        //cout<<"la carta de la maquina es 4 ";
   
        //NombreCartA();
   cout<<endl;
    }
     if(carta==5){
        //cout<<"la carta de la maquina es 5";
      
        //NombreCartA();
   cout<<endl;
    } 
    if(carta==6){
        //cout<<"la carta de la maquina es 6";
   
        //NombreCartA();
   cout<<endl;
        
    } 
    if(carta==7){
        //cout<<"la carta de la maquina es 7 ";
  
        //NombreCartA();
   cout<<endl;
    } 
    if(carta==8){
        //cout<<"la carta de la maquina es 8";
  
        //NombreCartA();
   cout<<endl;
    } 
    if(carta==9){
        //cout<<"la carta de la maquina es 9 ";

        //NombreCartA();
   cout<<endl;
        
    } 
    if(carta==10){
        //cout<<"la carta de la maquina es 10";
        //NombreCartA();
   cout<<endl;
        
    }
    if(carta==12){
        //carta 11 igual a los comodines que hagarra de alphabet 

int resta;
      resta=carta-2;  
        //srand(time(NULL));
        //string alphabet = "JQK";
        //char ch = alphabet[rand() % alphabet.size()];
        //cout << "Obtuvo "<<ch;
        //NombreCartA();
        //cout<<endl;
        //cout<<"Y el valor de esa carta es 10"<<endl;*/
        return resta;

    }
    puntosMaquina += carta;

    return puntosMaquina;

}
//Funcion para calcular los puntos del jugador.
int CartasJugador()
{
    int numero;
    int carta = 0, puntosJugador = 0, as = 0;
    int comodin=11;
    int comodin2=10;
    
    carta = Random(1, 12);
    //validando el valor de 1.
    if(carta == 1)
    {
        cout << "\nObtuvo un AS";
        NombreCartA();
        cout<<"Que valor desea asignarle? 1 || 11" << endl;
        cout << "Valor: ";
        cin >> as;
        
        switch (as)
        {
        case 1:
            carta = 1;
            break;

        case 11:
            carta = comodin;
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
    if (carta==11){

    }
    if(carta==12){
        //carta 11 igual a los comodines que hagarra de alphabet
        int resta; 
        resta=carta-2; 
        srand(time(NULL));
        string alphabet = "JQK";
        char ch = alphabet[rand() % alphabet.size()];
        cout << "Obtuvo "<<ch;
        NombreCartA();
        cout<<endl;
        cout<<"Y el valor de esa carta es 10"<<endl;
        return resta;
    }
    puntosJugador += carta;

    return puntosJugador;
}

//Funcion que retorna las cartas del jugador 2.
int CartasJugador2()
{
    int numero;
    int carta = 0, puntosJugador = 0, as = 0;
    int comodin=11;
    int comodin2=10;
    
    carta = Random(1, 12);
    //validando el valor de 1.
    if(carta == 1)
    {
        cout << "\nObtuvo un AS";
        NombreCartA();
        cout<<"Que valor desea asignarle? 1 || 11" << endl;
        cout << "Valor: ";
        cin >> as;
        
        switch (as)
        {
        case 1:
            carta = 1;
            break;

        case 11:
            carta = comodin;
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
    if (carta==11){

    }
    if(carta==12){
        //carta 11 igual a los comodines que hagarra de alphabet
        int resta; 
        resta=carta-2; 
        srand(time(NULL));
        string alphabet = "JQK";
        char ch = alphabet[rand() % alphabet.size()];
        cout << "Obtuvo "<<ch;
        NombreCartA();
        cout<<endl;
        cout<<"Y el valor de esa carta es 10"<<endl;
        return resta;
    }
    puntosJugador += carta;

    return puntosJugador;
}

//Funcion para jugar dos personas
void Multijugador()
{
    int valor1 = 0, valor2 = 0, opc;
    string jugador1 , jugador2;
    char continuar;

    system("cls");
    cout << "\n\tINGRESAR NICKNAMES." << endl;
    cout << "\nJugador 1: ";
    cin >> jugador1;
    cout << "Jugador 2: ";
    cin >> jugador2;

    system("cls");
    cout << "\nQuien jugara primero?" << endl;
    cout << "1- " << jugador1 << endl;
    cout << "2- " << jugador2 << endl;
    cout << "\nOpcion: ";
    cin >> opc;

    if(opc == 1)
    {
        do
        {
            system("cls");
            cout << "\n\t[" << jugador1 << "]" << endl;
            cout << "\nDesea una carta? s||Si n||No." << endl;
            cout << "Opcion: ";
            cin >> continuar;

            cout << "\n";

            if(continuar == 's' || continuar == 'S')
            {
                valor1 += CartasJugador();
                cout << "Puntos actuales " << valor1 << "." << endl;
                cout << "\n";
            }
            system("pause");
        
        } while (continuar == 's' || continuar == 'S');
        
        system("cls");
        cout << "|************************************************************|" << endl;
        cout << "|*********     Pasando al siguiente jugador...      *********|" << endl;
        cout << "| [ENTER] para continuar.                                    |" << endl;
        cout << "|************************************************************|" << endl;
        cout << "\n";
        system("pause");

        do
        {
            system("cls");
            cout << "\n\t[" << jugador2 << "]" << endl;
            cout << "\nDesea una carta? s||Si n||No." << endl;
            cout << "Opcion: ";
            cin >> continuar;

            cout << "\n";

            if(continuar == 's' || continuar == 'S')
            {
                valor2 += CartasJugador2();
                cout << "Puntos actuales " << valor2 << "." << endl;
                cout << "\n";
            }
            system("pause");
        
        } while (continuar == 's' || continuar == 'S');
        
        //Validando quien gano MOSTRANDO RESULTADOS.
        if(valor1 == 21)
        {
            system("cls");
            cout << "|************************************************************|" << endl;
            cout << "|              Victoria para: " << jugador1 << endl;
            cout << "|           Puntaje final:    " << valor1 << " VS " << valor2 << endl;
            cout << "|************************************************************|" << endl;
            cout << "\n";
            exit(1);

        }
        
        if(valor2 == 21)
        {
            system("cls");
            cout << "|************************************************************|" << endl;
            cout << "|              Victoria para: " << jugador2 << endl;
            cout << "|           Puntaje final:    " << valor2 << " VS " << valor1 <<endl;
            cout << "|************************************************************|" << endl;
            cout << "\n";
            exit(1);

        }

        if(valor1 > 21 && valor2 < 21)
        {
            system("cls");
            cout << "|************************************************************|" << endl;
            cout << "|              Victoria para: " << jugador2 << endl;
            cout << "|           Puntaje final:  " << valor2 << " VS " << valor1 <<endl;
            cout << "|************************************************************|" << endl;
            cout << "\n";
            exit(1);

        }

        if(valor2 > 21 && valor1 < 21)
        {
            system("cls");
            cout << "|************************************************************|" << endl;
            cout << "|              Victoria para: " << jugador1 << endl;
            cout << "|           Puntaje final:  " << valor1 <<" VS "<< valor2 <<endl;
            cout << "|************************************************************|" << endl;
            cout << "\n";
            exit(1);

        }

        if(valor1 > valor2)
        {
            system("cls");
            cout << "|************************************************************|" << endl;
            cout << "|              Victoria para: " << jugador1 << endl;
            cout << "|           Puntaje final:  " << valor1 <<" VS "<< valor2 <<endl;
            cout << "|************************************************************|" << endl;
            cout << "\n";
            exit(1);

        }

        if(valor2 > valor1)
        {
            system("cls");
            cout << "|************************************************************|" << endl;
            cout << "|              Victoria para: " << jugador2 << endl;
            cout << "|           Puntaje final:  " << valor2 <<" VS "<< valor1 <<endl;
            cout << "|************************************************************|" << endl;
            cout << "\n";
            exit(1);

        }

        if(valor2 == valor1)
        {
            system("cls");
            cout << "|************************************************************|" << endl;
            cout << "|**************    EMPATE! No hay ganador.     **************|" << endl;
            cout << "|              Puntaje final:    " <<valor2<<" VS "<<valor1<<"                  |"<<endl;
            cout << "|************************************************************|" << endl;
            cout << "\n";
            exit(1);

        }

    }

    //EMPIEZA LA OPCION 2.
    else if(opc == 2)
    {
        do
        {
            system("cls");
            cout << "\n\t[" << jugador2 << "]" << endl;
            cout << "\nDesea una carta? s||Si n||No." << endl;
            cout << "Opcion: ";
            cin >> continuar;

            cout << "\n";

            if(continuar == 's' || continuar == 'S')
            {
                valor2 += CartasJugador();
                cout << "Puntos actuales " << valor2 << "." << endl;
                cout << "\n";
            }
            system("pause");
        
        } while (continuar == 's' || continuar == 'S');
        
        system("cls");
        cout << "|************************************************************|" << endl;
        cout << "|*********     Pasando al siguiente jugador...      *********|" << endl;
        cout << "| [ENTER] para continuar.                                    |" << endl;
        cout << "|************************************************************|" << endl;
        cout << "\n";
        system("pause");

        //PASANDO AL JUGADOR 2
        do
        {
            system("cls");
            cout << "\n\t[" << jugador1 << "]" << endl;
            cout << "\nDesea una carta? s||Si n||No." << endl;
            cout << "Opcion: ";
            cin >> continuar;

            cout << "\n";

            if(continuar == 's' || continuar == 'S')
            {
                valor1 += CartasJugador();
                cout << "Puntos actuales " << valor1 << "." << endl;
                cout << "\n";
            }
            system("pause");
        
        } while (continuar == 's' || continuar == 'S');
        
        //Validando quien gano MOSTRANDO RESULTADOS.
        if(valor2 == 21)
        {
            system("cls");
            cout << "|************************************************************|" << endl;
            cout << "|                  Victoria para: " << jugador2 << endl; 
            cout << "|           Puntaje final:    " << valor2 << " VS " << valor1 << endl;
            cout << "|************************************************************|" << endl;
            cout << "\n";
            exit(1);

        }
        
        if(valor1 == 21)
        {
            system("cls");
            cout << "|************************************************************|" << endl;
            cout << "|              Victoria para: " << jugador1 << endl;
            cout << "|           Puntaje final:    " << valor1 << " VS " << valor2 <<endl;
            cout << "|************************************************************|" << endl;
            cout << "\n";
            exit(1);

        }

        if(valor1 > 21 && valor2 < 21)
        {
            system("cls");
            cout << "|************************************************************|" << endl;
            cout << "|              Victoria para: " <<jugador2 << endl;
            cout << "|           Puntaje final:  " << valor2 <<" VS "<<valor1 <<endl;
            cout << "|************************************************************|" << endl;
            cout << "\n";
            exit(1);

        }

        if(valor2 > 21 && valor1 < 21)
        {
            system("cls");
            cout << "|************************************************************|" << endl;
            cout << "|              Victoria para: " << jugador1 << endl;
            cout << "|           Puntaje final:  " << valor1 << " VS " << valor2 <<endl;
            cout << "|************************************************************|" << endl;
            cout << "\n";
            exit(1);

        }

        if(valor1 > valor2)
        {
            system("cls");
            cout << "|************************************************************|" << endl;
            cout << "|              Victoria para: " << jugador1 << endl;
            cout << "|           Puntaje final:  " << valor1 <<" VS "<< valor2 <<endl;
            cout << "|************************************************************|" << endl;
            cout << "\n";
            exit(1);

        }

        if(valor2 > valor1)
        {
            system("cls");
            cout << "|************************************************************|" << endl;
            cout << "|              Victoria para: " << jugador2 << endl;
            cout << "|           Puntaje final:  " << valor2 <<" VS "<< valor1 <<endl;
            cout << "|************************************************************|" << endl;
            cout << "\n";
            exit(1);

        }

        if(valor2 == valor1)
        {
            system("cls");
            cout << "|************************************************************|" << endl;
            cout << "|**************    EMPATE! No hay ganador.     **************|" << endl;
            cout << "|              Puntaje final:    " <<valor2<<" VS "<<valor1<<"                  |"<<endl;
            cout << "|************************************************************|" << endl;
            cout << "\n";
            exit(1);

        }
    }
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
    cout << "Opcion-> ";
    cin >> continuar;
    char opc;
    int opc2;
    int valor = 0, puntosMaq = 0, valor2=0;
    if(continuar == 1)
    {
       cout<<"\nDesea Jugar contra la maquina o con amigos:\n";
       cout<<"1- Maquina.\n";
       cout<<"2- Amigos.\n";
       cout << "Opcion-> ";
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
                valor2+=CartasMaquina2();
                //cout<<"Puntos de la maquina:"<< valor2<<"."<<endl;
                valor += CartasJugador();
                cout << "Puntos actuales: " << valor << "." << endl; 

            }
                        
            if(valor2 == 21)
            {
                system("cls");
                cout << "|************************************************************|" << endl;
                cout << "|*************** Derrota! Gano la Maquina *******************|" << endl;
                cout << "|                         " <<valor2<<"                      |"<<endl;
                cout << "|************************************************************|" << endl;
                cout << "\n";
                exit(1);
            }

            if(valor2 > 21 && valor<21)
            {
                system("cls");
                cout << "|************************************************************|" << endl;
                cout << "|********* Ganaste la maquina Excedio 21 puntos. ************|" << endl;
                cout << "|              puntos de la maquina" <<valor2<<"             |"<<endl;
                cout << "|************************************************************|" << endl;
                cout << "\n";
                exit(1);
            }
            if(valor > 21)
            {
                system("cls");
                cout << "|************************************************************|" << endl;
                cout << "|*************** Derrota! Excedio 21 puntos. ****************|" << endl;                    
                cout << "|************************************************************|" << endl;
                cout << "\n";
                exit(1);
            }

            if(valor==21)
            {
                system("cls");
                cout << "|************************************************************|" << endl;
                cout << "|********* Victoria!!!!!! tu puntuacion es de 21 ************|" << endl;
                cout << "|************************************************************|" << endl;
                cout << "\n";
                exit(1);
            }
            cout << "\n";
            system ("pause");
                        

        } 
        while (opc == 's' || opc == 'S');

        system("cls");
        cout << "|************************************************************|" << endl;
        cout << "|                                                            |" << endl;
        cout << "|****Tu puntuacion: "<< valor << " VS " << "Puntuacion de la maquina: " << valor2<<" ******|"<<endl;
        cout << "|                                                            |" << endl;
        cout << "|************************************************************|" << endl;
        cout << "\n";
        if(valor>valor2)
        {
            cout<<"VICTORIA" << endl;
        }
        if(valor<valor2)
        {
            cout<<"GANA LA MAQUINA" << endl;
        }
        }    
        else if (opc2==2)
        {
            Multijugador();
        }
        else
        {
            cout << "Ingrese una opcion valida, por favor." << endl;
        }
    }
    else
    {
        cout << "Ingrese una opcion valida, por favor." << endl;
    }
}

int main ()
{
    Juego();
    return 0;
}
