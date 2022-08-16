#include <iostream>

using namespace std;

int main()
{
    int x, w = 0;
    cout << "Dai un valore a x: ";
    cin >> x;
    if (x == 0)
    {
        w = 1;
        cout << "\nIl valore di w e': " << w;
    }
    do
    {
        w++;
        x = x / 10;

    } while (x > 0);
    cout << "\nIl valore di w e': " << w << endl;
    return 0;
}
