/*
    Autore: Nicola Preda
    Data: 11/11/21
    Classe: 3ID
    Funzionamento: Dato in input un valore reale viene comunicato in output:
    - se positivo o negativo
    - la parte intera
    - la parte decimale

*/

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    //Dichiaro la variabile float n che conterrà il numero, con o senza virgola
    float n;

    cout << "Inserisci un valore reale\n";
    cin >> n;
    /*Viene trovato il numero intero dichiarando una variabile 
    che prende float n e la trasforma in in, trascurando quindi la parte decimale*/ 
    int numero_intero = (int)n;
    //Se il valore è positivo viene messo in output "Positivo", altrimenti "Negativo"
    if (n > 0)
    {
        cout << "Positivo\n";
    }
    else
    {
        cout << "Negativo\n";
    }
    /*Utilizzo la funzione di cmath per rappresentare il valore assoluto. 
    Avrei potuto moltiplicare per -1 i risultati nel caso in cui avessi 
    inserito un valore negativo*/
    cout << "Parte intera: " << abs(numero_intero) << endl;
    cout << "Parte decimale: " << abs(n - numero_intero) << endl;
}


/*
CASI DI TEST:
Input: 3.14
Output: 
Positivo
Parte intera: 3
Parte decimale: 0.14

Input: -3.14
Output: 
Negativo
Parte intera: -3
Parte decimale: -0.14

Input:-4354
Output:
Negativo
Parte intera: 4354
Parte decimale: 0


*/