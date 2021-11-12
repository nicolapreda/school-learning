/*
    Autore: Nicola Preda
    Data: 11/11/21
    Classe: 3ID
    Funzionamento: Data in input una sequenza di valori interi 
    che termina con 0(non considerato) calcola la somma e la media.
*/

#include <iostream>

using namespace std;

int main()
{
    /*Viene dichiarata la variabile n, che prenderà il valore dei numero interi chiesti in input,
    la variabile somma che verrà mostrata in output alla fine e incrementata ogni volta del numero inserito, 
    ,l'intero valori che conterrà il numero di valori inseriti dall'utente prima dello zero
    e la variabile float media che dovrà contenere la media (somma / valori) dei numeri inseriti */
    int n, somma = 0, valori = 0;
    float media;
    //Esce dal ciclo while soltanto quando n è uguale a 0
    while (n != 0)
    {
        cout << "Inserisci un numero intero\n";
        cin >> n;

        //Non considera nella somma e nella conta dei valori 0
        if (n != 0)
        {
            //La variabile somma viene incrementata di n
            somma += n;
            //Viene incrementata la variabile che conta i valori inseriti dall'utente
            valori++;
        }
    }

    /*Viene calcolata la media dei valori considerando somma come variabile float*/
    media = (float)somma / valori;
    cout << "Somma: " << somma << endl;
    cout << "Media: " << media << endl;
}

/*
CASI DI TEST:
Input: 5 5 0
Output: 
Somma: 10
Media: 5

Input: -2 -7 -10 -15 0
Output:
Somma: -34
Media: -8.5

Input:34 65 765 456 354 435 6 7 6 0 
Output:
Somma: 2128
Media: 236.444

Input: -15 15 6  5 3 -66 0
Output:
Somma: -52
Media: -8.66667

*/