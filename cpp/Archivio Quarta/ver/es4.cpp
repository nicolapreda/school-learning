/*scrivi un metodo ricorsivo per convertire un numero da base 10 a base 2*/

#include <iostream>

using namespace std;

int converti(int n)
{
    if (n == 0)
        return 0;
    return n % 2 + 10 * converti(n / 2);
    /*spiegazione:
    se n = 0, ritorna 0
    altrimenti, ritorna il resto della divisione per 2 + 10 * converti(n / 2)
    perchè 10 * converti(n / 2) è il numero convertito in base 2 senza il resto della divisione per 2
    
    esempio:
    converti(10)
    10 % 2 + 10 * converti(10 / 2)
    0 + 10 * converti(5)
    0 + 10 * (5 % 2 + 10 * converti(5 / 2))
    0 + 10 * (1 + 10 * converti(2))
    0 + 10 * (1 + 10 * (2 % 2 + 10 * converti(2 / 2)))
    0 + 10 * (1 + 10 * (0 + 10 * converti(1)))
    0 + 10 * (1 + 10 * (0 + 10 * (1 % 2 + 10 * converti(1 / 2))))
    0 + 10 * (1 + 10 * (0 + 10 * (1 + 10 * converti(0))))   // qui n = 0, quindi ritorna 0
    0 + 10 * (1 + 10 * (0 + 10 * (1 + 0)))
    0 + 10 * (1 + 10 * (0 + 10))
    0 + 10 * (1 + 10 * 0)
    0 + 10 * (1 + 0)
    0 + 10 * 1
    0 + 10
    10
    
    
    */
}

int main()
{
    int n = 1;
    cout << converti(n) <<endl;
    return 0;
}

