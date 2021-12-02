#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

using namespace std;

int main()
{
    srand (time(NULL));
    int n;
    do
    {
        n = rand() % 40 + 1;
    } while (n % 2 == 0 );
    
    cout<<n<<endl;

    for (int c = n; c != 0; c--)
    {
        for (int n_ast = c; n_ast != 0; n_ast--)
        {
            cout << "*";
        }
        cout << endl;
        

    }
}