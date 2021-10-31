#include <iostream>

using namespace std;

int main()
{
    int somma = 0, current = 1;

    for (int n_perfetti = 1; n_perfetti <= 5; n_perfetti++)
    {
        for (int numero = current; numero != somma; numero++)
        {
            for (int divisore = 1; divisore < numero; divisore++)
            {
                if (numero % divisore == 0)
                {
                    somma += divisore;
                }
            }
            current = numero;
        }

        cout << somma << " è un numero perfetto" << endl;
        somma = 0;
        
    }
}