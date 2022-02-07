#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
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

int arrayCasuale(int min, int max, int array[]){
    
    for (int i = 0; i < sizeof(array); i++)
    {
        srand (time(NULL));
        int nCasuale = rand() % max + min;
        array[i] = nCasuale;
    }
    
}