#include <iostream>

using namespace std;

int main()
{
    int h, consistenza;
    cout << "Ore trascorse: " << endl;
    cin >> h;

    cout << "Consistenza iniziale della popolazione batterica (Espresso in unità di carica batterica): " << endl;
    cin >> consistenza;
    
    while (h > 0)
    {
        consistenza *= 2;
        h = h - 1;
    }
    cout << "Consistenza finale della popolazione batterica (Espresso in unità di carica batterica): " << consistenza << endl;
    return 0;
}