/*
    Autore: Nicola Preda
    Data: 4/11/21
    Classe: 3ID
    Funzionamento: calcolo somma e media aritmetica di dieci numeri casuali compresi tra 10 e 90 tramite la funzione rand().
*/

#include <iostream>

using namespace std;

int main()
{
    srand(time(0));

    int random, somma = 0;
    // Random genera un numero tra 0 e 65535, ma i numeri di random saranno compresi soltanto tra 10 e 90, di conseguenza la somma e la media non saranno numeri grand. La variabile int quindi è efficiente per rand e somma

    float media = 0;
    //Per la variabile media utilizzo una variabile float perchè la media di più valori può generare un numero con la virgola.

    for (int numero = 1; numero <= 10; numero++)
    {
        while (random < 10 || random > 90)
        {
            random = rand();
        }
        
        somma += random;

    }
    cout<<"Somma: "<<somma<<endl;
    media = somma / 10;
    cout<<"Media: "<<media<<endl;
}