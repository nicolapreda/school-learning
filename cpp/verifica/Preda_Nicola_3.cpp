/*
    Autore: Nicola Preda
    Data: 11/11/21
    Classe: 3ID
    Funzionamento: Dati in input due valori interi 
    calcola il prodotto ottimizzato tra i 2 effettuando somme 
    ripetute visualizzando volta per volta la somma parziale
*/

#include <iostream>

using namespace std;

int main()
{
    /*Dichiaro le variabili n1 e n2 che prenderanno il valore chiesto in input, 
    e somma che conterrà il valore della somma di n1 per n2 volte grazie a un ciclo*/
    int n1, n2, somma = 0;
    cout << "Inserisci il primo numero intero\n";
    cin >> n1;
    cout << "Inserisci il secondo numero intero\n";
    cin >> n2;
    for (int c = 0; c < n2; c++)
    {
        /*Viene portato in output il valore di somma, che viene incrementata ogni volta
        da n1 per n2 volte*/
        somma +=  n1;
        cout<<somma<<endl;
    }
    
}

/*
CASI DI TEST:
Input: 8 6 
Output:
8
16
24
32
40
48

Input: 8 32
Output: 
8
16
24
32
40
48
56
64
72
80
88
96
104
112
120
128
136
144
152
160
168
176
184
192
200
208
216
224
232
240
248
256

*/