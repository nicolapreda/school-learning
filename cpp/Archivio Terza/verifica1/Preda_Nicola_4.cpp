/*
    Autore: Nicola Preda
    Data: 11/11/21
    Classe: 3ID
    Funzionamento: Dato in input un valore intero (N) compreso tra 10 e 100 (estremi inclusi) (in caso di errore di inserimento richiedere l'input)
    viene visualizzato a video N multipli del minor numero primo maggiore di N
*/

#include <iostream>

using namespace std;

int main()
{
    //Dichiara due vabiabili: n che verrà preso in input e somma, che sarà utiizzata per mostrare in output N multipli del minor numero primo maggiore di N
    int n, somma = 0;

    //Ripete l'output e la richiesta dell'input fino a quando il numero inserito è compreso tra 10 e 100
    do
    {
        cout << "Inserisci un numero intero compreso tra 10 e 100\n";
        cin>>n;
    } while (n < 10 || n > 100);

    //Dichiara la variabile numero primo che inizialmente prenderà il valore di n
    int n_primo = n;

    /*Dichiara la variabile booleana per capure se il numero è primo oppure no.
    Permetterà al ciclo di uscire quando sarà vera*/
    bool isPrimo = false;

    while (isPrimo == false)
    {
        //Imposta la vabiabile isPrimo inizialmente a true, e incrementa la variabile del numero primo
        isPrimo = true;
        n_primo++;

        /*Il ciclo trova tutti i possibili divisori del numero, all'infuori di 1 e di sè stesso.
        Se un numero nella variabile div è divisore di n_primo la variabile booleana isPrimo ritornerà ancora false*/
        for (int div = 2; div < n; div++)
        {
            if (n_primo % div == 0)
            {
                isPrimo = false;
            }   
        }   
        
    }

    /*Dopo aver trovato il numero primo viene portato in output 
    la variabile somma, che viene incrementata di n_primo per n volte*/ 
    for (int c = 1; c < n; c++)
    {
        somma += n_primo; 
        cout << somma<<endl;;
    }
}

/*
CASI DI TEST:
Input: 10
Output: 
11
22
33
44
55
66
77
88
99

Input: 22
Output: 
23
46
69
92
115
138
161
184
207
230
253
276
299
322
345
368
391
414
437
460
483

Input: 50
Output:
53
106
159
212
265
318
371
424
477
530
583
636
689
742
795
848
901
954
1007
1060
1113
1166
1219
1272
1325
1378
1431
1484
1537
1590
1643
1696
1749
1802
1855
1908
1961
2014
2067
2120
2173
2226
2279
2332
2385
2438
2491
2544
2597
*/