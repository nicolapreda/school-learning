#include <iostream>

using namespace std;

int main()
{
    long long n = 1, somma_div = 0;

    for (int n_perfetti = 1; n_perfetti <= 5; n_perfetti++)
    {
        while (n != somma_div)
        {
            
            for (long long i = 1; i < n; i++)
            {
                if (n % i == 0)
                {
                    somma_div += i;
                }
            }
            if (n != somma_div)
            {
                n++;
                somma_div = 0;
            }
        }
            cout << n <<" è un numero perfetto!" << endl;
            somma_div = 0;
            n++;

    }
    return 0;

}
