#include <iostream>
#include <string.h>

using namespace std;

void inizializza(char matrice[26][26])
{
    // initialize The Vigenère Cipher Encryption Matrix
    for (int i = 0, counter = 0; i < 26; i++, counter = 0 + i)
    {
        for (int j = 0; j < 26; j++, counter++)
        {
            if (65 + counter > 90)
            {
                counter = 0;
            }
            matrice[i][j] = 65 + counter;
        }
    }
}

void codifica(char frase[], char matrice[26][26], char verme[])
{
    int c = 0;
    for (int i = 0; i < strlen(frase); i++)
    {
        if (frase[i] != 32)
        {
            cout << matrice[(int)frase[i] - 65][(int)verme[c] - 65];
            c++;
        }
        else
        {
            cout << " ";
        }
        if (c >= strlen(verme))
        {
            c = 0;
        }
    }
}

void decodifica(char verme[], char frase[], char matrice[26][26])
{
    int c = 0;
    for (int i = 0; i < strlen(frase); i++)
    {
        if (frase[i] != 32)
        {
            int colonna = (int)frase[i] - 65;
            int riga = (int)verme[c] - 65;
            while((int)matrice[riga][colonna] != (int)frase[i])
            {
                colonna++;
            }
            cout<<matrice[0][colonna];
            c++;
        }
        else
        {
            cout << " ";
        }
        if (c >= strlen(verme))
        {
            c = 0;
        }
    }
}

void stampa(char matrice[26][26])
{

    // print matrix
    for (int i = 0; i < 26; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            cout << matrice[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    char chiaro[10] = "provaciao";
    char verme[4] = "abc";
    char tavolaVigenere[26][26];
    inizializza(tavolaVigenere);
    stampa(tavolaVigenere);
    codifica(chiaro, tavolaVigenere, verme);
    cout << endl;
}
