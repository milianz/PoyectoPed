#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <time.h>

using namespace std;

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
    int carta = 0, puntosJugador = 0, as = 0;
    
    carta = Random(1, 11);
    
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
    else
    {
        //Si el numero generado es mayor que 10 su valor sera 10.
        if(carta > 10)
        {
            carta = 10;
        }
    }
    puntosJugador += carta;

    return puntosJugador;
}

void Bievenida()
{
    int continuar = 0;
    system ("cls");
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
    cout << "\nDesea continuar? 1||Si 0||No." << endl;
    cout << "Opcion: ";
    cin >> continuar;

    char opc;
    int valor = 0, puntosMaq;
    if(continuar == 1)
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
                cout << "\nPuntos actuales: " << valor << "." << endl; 

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
}

int main ()
{
    Bievenida();

    return 0;
}