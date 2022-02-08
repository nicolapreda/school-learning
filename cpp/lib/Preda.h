#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <iterator>
#include <charconv>
#include <stdio.h>
#include <string.h>
#include <cmath>

using namespace std;

// Dichiarazione funzioni
int maxArray(int array[], int n);
int minArray(int array[], int n);
int sommaArray(int array[], int n);
double mediaArray(int array[], int n);
int maxOccorrenza(int array[], int n);
bool isPrimo(int n);
int maggiorOccorrenza(int array[], int n);
int interoMigliaia(int n);
int arrayCasuale(int min, int max, int array[]);
int carattereinASCII(char carattere[]);
char ASCIIinCarattere(int ASCII);
void posizione0(int array[], int l);
void cercaElemento(int array[], int l, int elemento);
int posizioneElemento(int array[], int l, int elemento);
int confrontoArray(int array1[], int array2[]);
int confrontoArraysl(int array1[], int array2[]);
void contornoTesto(char testo[]);
void stampaASCII(int array[]);
float arrotonda(float n, int arr);
void miglInt(int n);
int occorrenzePerElemento(int array[]);

int maxArray(int array[], int n)
{
    int maxelement = 0;
    for (int i = 0; i < n; i++)
    {
        if (array[i] > maxelement)
            maxelement = array[i];
    }
    return maxelement;
}

int minArray(int array[], int n)
{
    int minelement = array[0];
    for (int i = 1; i < n; i++)
    {
        if (array[i] < minelement)
            minelement = array[i];
    }
    return minelement;
}

int sommaArray(int array[], int n)
{
    int somma = 0;
    for (int i = 0; i < n; i++)
    {
        somma += array[i];
    }

    return somma;
}

double mediaArray(int array[], int n)
{
    int somma = 0;
    double media = 0;
    for (int i = 0; i < n; i++)
    {
        somma += array[i];
    }
    media = somma / n;

    return media;
}

int maxOccorrenza(int array[], int n)
{
    int nCorrente, occorrenzaCorrente = 0;

    for (int i = 0; i < n; i++)
    {
        if (array[i] == nCorrente)
            occorrenzaCorrente++;
    }
}

int interoMigliaia(int n)
{
}

bool isPrimo(int n)
{
    bool primo = true;
    for (int i = 2; i < n && primo != false; i++)
    {
        if (primo % i == 0)
        {
            primo = false;
        }
    }
    return primo;
}

int maggiorOccorrenza(int array[], int n)
{
    int a = array[0], counter = 0, counter1 = 0;
    for (int x = 0; x < n; x++)
        if (array[0] == array[x])
        {
            counter++;
        }

    for (int x = 1; x < n; x++)
    {
        for (int y = 0; y < n; y++)
        {
            if (array[x] == array[y])
            {
                counter1++;
            }
        }
        if (counter1 > counter)
        {
            counter = counter1;
            a = array[x];
        }
    }
    return a;
}

int arrayCasuale(int min, int max, int array[])
{

    for (int i = 0; i < sizeof(array); i++)
    {
        srand(time(NULL));
        int nCasuale = rand() % max + min;
        array[i] = nCasuale;
    }
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

// Calcolare il valore massimo di occorrenze tra gli elementi interi di un array
int maxValoreOccorrenze(int array[], int l)
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

int confrontoArray(int array1[], int array2[])
{

    for (int i = 0; i < sizeof(array1) || i < sizeof(array2); i++)
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

int confrontoArraysl(int array1[], int array2[])
{
    for (int i = 0; i < sizeof(array1); i++)
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

int occorrenzeArray(int array[])
{
    int occorrenze[sizeof(array)] = {0};

    for (int i = 0; i < sizeof(array); i++)
    {
        for (int x = 0; i < sizeof(array); i++)
        {
            if (array[i] == array[x])
            {
                occorrenze[i]++;
            }
        }
    }
}

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

void stampaASCII(int array[])
{

    char caratteri[sizeof(array)];
    for (int i = 0; i < sizeof(array) || array[i] != 0; i++)
    {
        caratteri[i] = array[i];
    }
    cout << caratteri;
}

float arrotonda(float n, int arr)
{
    int arrotondamento = pow(10, arr);
    float valore = (int)(n * arrotondamento + .5);
    return (float)valore / arrotondamento;
}

void miglInt(int n)
{
    int lValore = sizeof(n);
    vector<int> digitArray;
    while (n > 0)
    {
        int digit = n % 10;
        n /= 10;
        std::cout << digit << " ";
        digitArray.push_back(digit);
    }
    reverse(digitArray.begin(), digitArray.end()); // reverse the order of digits

    int counter = 0;

    for (int i = lValore, x = 0; i > 0; i--, x++)
    {

        counter++;
        if (counter == 3)
        {
            cout << ".";
        }
        else
        {

        }
    }
}

int occorrenzePerElemento(int array[]){
    int occorrenze[sizeof(array)] = {0};

    for (int i = 0; i < sizeof(array); i++)
    {
        for (int x = 0; x < sizeof(array); x++)
        {
            if (array[x] == array[i])
            {
                occorrenze[i]++;

            }
            
        }
        
    }

    return occorrenze[sizeof(array)];
    
}