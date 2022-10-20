/*scrivere una funzione ricorsiva c++ avente il seguente prototipo
    float power(float a , unsigned int b);
    che calcoli la potenza a^b.
*/
#include <iostream>
using namespace std;
float power(float a, unsigned int b)
{
    if (b == 0)
    {
        return 1;
    }
    else
    {
        return a * power(a, b - 1);
    }
}

int main()
{
    float a;
    unsigned int b;
    cout << "Inserisci la base: ";
    cin >> a;
    cout << "Inserisci l'esponente: ";
    cin >> b;
    cout << a << "^" << b << " = " << power(a, b) << endl;
    return 0;
}