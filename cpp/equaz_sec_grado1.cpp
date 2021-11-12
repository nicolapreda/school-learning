#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    float a, b, c, x, x1, x2;
    cout << "Inserisci a" << endl;
    cin >> a;
    cout << "Inserisci b" << endl;
    cin >> b;
    cout << "Inserisci c" << endl;
    cin >> c;
    if (a == 0 && b == 0 && c == 0)
    {
        cout << "INDETERMINATO" << endl;
    }
    else if (a == 0 && b != 0 && c != 0)
    {
        x = -c / b;
        cout << "x= " << x << endl;
    }
 
    int delta = (pow(b, 2)) - (4 * a * c);

    if (delta > 0)
    {
        x1 = (-b + abs(delta)) / (2 * a);
        x2 = (-b - sqrt(delta)) / (2 * a);
        cout << "x1= " << x1 << endl;
        cout << "x2= " << x2 << endl;
    }
    else if (delta < 0 || a == 0 && b == 0 && c != 0)
    {
        cout << "IMPOSSIBILE" << endl;
    }
    else if (delta == 0)
    {
        x = (-b) / (2 * a);
        cout << "x= " << x << endl;
    }

    
}
