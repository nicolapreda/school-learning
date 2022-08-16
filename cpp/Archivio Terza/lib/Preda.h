#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <iterator>
#include <charconv>
#include <stdio.h>
#include <string.h>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;

// Dichiarazione funzioni
int maxArray(int array[], int l);
int minArray(int array[], int l);
int sommaArray(int array[], int l);
double mediaArray(int array[], int l);
bool isPrimo(int n);
int maggiorOccorrenza(int array[], int l, int n);
int occorrenzePerElemento(int array[], int l);
int valoreMassimoOccorrenze(int array[], int l);
int arrayCasuale(int min, int max, int array[]);
int carattereinASCII(char carattere[]);
char ASCIIinCarattere(int ASCII);
void posizione0(int array[], int l);
void cercaElemento(int array[], int l, int elemento);
int posizioneElemento(int array[], int l, int elemento);
int confrontoArray(int array1[], int array2[], int l1, int l2);
int confrontoArraySL(int array1[], int array2[], int l);
void contornoTesto(char testo[]);
void stampaASCII(int array[], int l);
float arrotonda(float n, int arr);
string separatoreMigliaia(int n);

int maxArray(int array[], int l)
{
    int maxelement = 0;
    for (int i = 0; i < l; i++)
    {
        if (array[i] > maxelement)
            maxelement = array[i];
    }
    return maxelement;
}

int minArray(int array[], int l)
{
    int minelement = array[0];
    for (int i = 1; i < l; i++)
    {
        if (array[i] < minelement)
            minelement = array[i];
    }
    return minelement;
}

int sommaArray(int array[], int l)
{
    int somma = 0;
    for (int i = 0; i < l; i++)
    {
        somma += array[i];
    }

    return somma;
}

double mediaArray(int array[], int l)
{
    int somma = 0;
    double media = 0;
    for (int i = 0; i < l; i++)
    {
        somma += array[i];
    }
    media = somma / l;

    return media;
}

string separatoreMigliaia(int n)
{
    string str = "";
    string numero = to_string(n);

    int count = 0;
    for (int i = numero.size() - 1;
         i >= 0; i--)
    {
        count++;
        str.push_back(numero[i]);
        if (count == 3)
        {
            str.push_back('.');
            count = 0;
        }
    }
    reverse(str.begin(), str.end());

    return str;
}

bool isPrimo(int n)
{
        if (n <= 1)
            return false;

        for (int i = 2; i < n; ++i)
            if (n % i == 0)
                return false;

        return true;
    
}
int maggiorOccorrenza(int array[], int l)
{

    int occorrenze = 0;
    int maxoccorrenze = 0;
    int occorrenzaMaggiore;
    for (int i = 0; i < l; i++)
    {
        for (int x = 0; x < l; x++)
        {
            if (array[i] == array[x])
            {
                occorrenze++;
            }
        }
        if (occorrenze > maxoccorrenze)
        {
            maxoccorrenze = occorrenze;
            occorrenzaMaggiore = array[i];
        }
        occorrenze = 0;
    }
    return occorrenzaMaggiore;
}

int arrayCasuale(int min, int max, int grandezza)
{
    int array[grandezza];
    
    for (int i = 0; i < grandezza; i++)
    {
        srand (time(0));
        int nCasuale = rand() % max + min;
        array[i] = nCasuale;
    }

    return array[grandezza];
}

int carattereinASCII(char carattere[])
{
    int inASCII = carattere[0];
    return inASCII;
}

char ASCIIinCarattere(int ascii)
{
    char carattere(ascii);
    return carattere;
}

void posizione0(int array[], int l)
{
    for (int i = 0; i < l; i++)
    {
        if (array[i] == 0)
        {
            cout << "Lo 0 si trova nella posizione " << i << " dell'array\n";
        }
    }
}

void cercaElemento(int array[], int l, int elemento)
{
    for (int i = 0; i < l; i++)
    {
        if (array[i] == elemento)
        {
            cout << elemento << " si trova nella posizione " << i << " dell'array\n";
        }
    }
}

int valoreMassimoOccorrenze(int array[], int l)
{

    int occorrenze = 0;
    int maxoccorrenze = 0;

    for (int i = 0; i < l; i++)
    {
        for (int x = 0; x < l; x++)
        {
            if (array[x] == array[i])
            {
                occorrenze++;
            }
        }
        if (occorrenze > maxoccorrenze)
        {
            maxoccorrenze = occorrenze;
        }
        occorrenze = 0;
    }
    return maxoccorrenze;
}

int posizioneElemento(int array[], int l, int elemento)
{
    for (int i = 0; i < l; i++)
    {
        if (array[i] == elemento)
        {
            return i;
        }
    }
    return -1;
}

int confrontoArray(int array1[], int array2[], int l1, int l2)
{

    for (int i = 0; i < l1 || i < l2; i++)
    {
        if (array1[i] == 0 || array2[i] == 0)
        {
            return 0;
        }
        else if (array1[i] > array2[i])
        {
            return 1;
        }
        else if (array1[i] < array2[i])
        {
            return -1;
        }
    }
    return 0;
}

int confrontoArraySL(int array1[], int array2[], int l)
{
    for (int i = 0; i < l; i++)
    {

        if (array1[i] > array2[i])
        {
            return 1;
        }
        else if (array1[i] < array2[i])
        {
            return -1;
        }
    }
    return 0;
}

// Check
void contornoTesto(char testo[])
{
    for (int i = 0; i < strlen(testo) * 4; i++)
    {
        cout << "*";
    }
    cout << endl;
    cout << "*";
    for (int i = 0; i < (strlen(testo) * 3) / 2; i++)
    {
        cout << " ";
    }
    cout << testo;
    for (int i = 0; i < ((strlen(testo) * 3) / 2) - 1; i++)
    {
        cout << " ";
    }
    cout << "*";
    cout << endl;
    for (int i = 0; i < strlen(testo) * 4; i++)
    {
        cout << "*";
    }
}
// Check
void stampaASCII(int array[], int l)
{

    char caratteri[l];
    for (int i = 0; i < l || array[i] != 0; i++)
    {
        caratteri[i] = array[i];
    }
    cout << caratteri;
}
// Check
float arrotonda(float n, int arr)
{
    int arrotondamento = pow(10, arr);
    float valore = (int)(n * arrotondamento + .5);
    return (float)valore / arrotondamento;
}

// Check
int occorrenzePerElemento(int array[], int l)
{

    int occorrenze[l] = {0};

    for (int i = 0; i < l; i++)
    {
        for (int x = 0; x < l; x++)
        {
            if (array[x] == array[i])
            {
                occorrenze[i]++;
            }
        }
    }
    return occorrenze[l];
}
