/*funzione sumPot( che calcola la somma delle potenze
di un numero in modo ricorsivo*/


#include <iostream>

using namespace std;

int sumPot(int n)
{
    if (n == 0)
        return 1;
    return n * sumPot(n - 1);
}

int main()
{
    int n = 3;
    cout << sumPot(n) << endl;
    return 0;
}