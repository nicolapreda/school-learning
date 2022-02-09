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
int maxArray(int array[]);
int minArray(int array[]);
int sommaArray(int array[]);
double mediaArray(int array[]);
bool isPrimo(int n);

int maggiorOccorrenza(int array[], int n);
int occorrenzePerElemento(int array[]);
int maxValoreOccorrenze(int array[]);

int arrayCasuale(int min, int max, int array[]);
int carattereinASCII(char carattere[]);
char ASCIIinCarattere(int ASCII);
void posizione0(int array[]);
void cercaElemento(int array[], int elemento);
int posizioneElemento(int array[], int elemento);
int confrontoArray(int array1[], int array2[]);
int confrontoArraySL(int array1[], int array2[]);
void contornoTesto(char testo[]);
void stampaASCII(int array[]);
float arrotonda(float n, int arr);
int grandezzaArray(int array[]);
void intMigliaia(int n);
string separatoreMigliaia(int n);

int maxArray(int array[])
{
    int maxelement = 0;
    for (int i = 0; i < grandezzaArray(array); i++)
    {
        if (array[i] > maxelement)
            maxelement = array[i];
    }
    return maxelement;
}

int minArray(int array[])
{
    int minelement = array[0];
    for (int i = 1; i < grandezzaArray(array); i++)
    {
        if (array[i] < minelement)
            minelement = array[i];
    }
    return minelement;
}

int sommaArray(int array[])
{
    int somma = 0;
    for (int i = 0; i < grandezzaArray(array); i++)
    {
        somma += array[i];
    }

    return somma;
}

double mediaArray(int array[])
{
    int somma = 0;
    double media = 0;
    for (int i = 0; i < grandezzaArray(array); i++)
    {
        somma += array[i];
    }
    media = somma / grandezzaArray(array);

    return media;
}

string separatoreMigliaia(int n)
{
	string str = "";
	string numero = to_string(n);

	int count = 0;
	for (int i = numero.size() - 1;
		i >= 0; i--) {
		count++;
		str.push_back(numero[i]);
		if (count == 3) {
			str.push_back('.');
			count = 0;
		}
	}
	reverse(str.begin(), str.end());


	return str;
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

int maggiorOccorrenza(int array[])
{
    int a = array[0], counter = 0, counter1 = 0;
    for (int x = 0; x < grandezzaArray(array); x++)
        if (array[0] == array[x])
        {
            counter++;
        }

    for (int x = 1; x < grandezzaArray(array); x++)
    {
        for (int y = 0; y < grandezzaArray(array); y++)
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

int arrayCasuale(int min, int max, int grandezza)
{
    int array[grandezza];
    for (int i = 0; i < grandezza; i++)
    {
        srand(time(NULL));
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

void posizione0(int array[])
{
    for (int i = 0; i < grandezzaArray(array); i++)
    {
        if (array[i] == 0)
        {
            cout << "Lo 0 si trova nella posizione " << i << " dell'array\n";
        }
    }
}

void cercaElemento(int array[], int elemento)
{
    for (int i = 0; i < grandezzaArray(array); i++)
    {
        if (array[i] == elemento)
        {
            cout << elemento << " si trova nella posizione " << i << " dell'array\n";
        }
    }
}

// Calcolare il valore massimo di occorrenze tra gli elementi interi di un array
int maxValoreOccorrenze(int array[])
{

    int occorrenze = 0;
    int maxoccorrenze = 0;

    for (int i = 0; i < grandezzaArray(array); i++)
    {
        for (int x = 0; x < grandezzaArray(array); x++)
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

int posizioneElemento(int array[], int elemento)
{
    for (int i = 0; i < grandezzaArray(array); i++)
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

    for (int i = 0; i < grandezzaArray(array1) || i < grandezzaArray(array2); i++)
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

int confrontoArraySL(int array1[], int array2[])
{
    for (int i = 0; i < grandezzaArray(array1); i++)
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


//Check
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
//Check
void stampaASCII(int array[])
{

    char caratteri[grandezzaArray(array)];
    for (int i = 0; i < grandezzaArray(array) || array[i] != 0; i++)
    {
        caratteri[i] = array[i];
    }
    cout << caratteri;
}
//Check
float arrotonda(float n, int arr)
{
    int arrotondamento = pow(10, arr);
    float valore = (int)(n * arrotondamento + .5);
    return (float)valore / arrotondamento;
}


//Check
int occorrenzePerElemento(int array[])
{
    int grandezza = grandezzaArray(array);

    int occorrenze[grandezza] = {0};

    for (int i = 0; i < grandezza; i++)
    {
        for (int x = 0; x < grandezza; x++)
        {
            if (array[x] == array[i])
            {
                occorrenze[i]++;
            }
        }
    }
    return occorrenze[grandezza];
}
//Check
int grandezzaArray(int array[])
{
    return sizeof(array) / sizeof(array[0]);
}