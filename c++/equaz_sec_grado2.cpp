#include <iostream>

//Libreria per elevazioni a potenza(pow) e radici(sqrt) 
#include <cmath>

using namespace std;

int main()
{
    int a, b, c, res;
    float x, y;
    cout << "Inserisci a: "<<endl;
    cin >> a;
    cout << "Inserisci b: "<<endl;
    cin >> b;
    cout << "Inserisci c: "<<endl;
    cin >> c;

    int delta = (pow(b, 2)) - (4 * a * c);
    

    if (a == 0 || delta < 0)
    {
        cout << "Equazione impossibile"<<endl;
    }
    else if (delta == 0)
    {
        res = -b / 2 * a;
        cout << "Risultato = " << res;
    }
    else
    {
        
        x = (-b + sqrt(delta)) / (2 * a);
        y = (-b - sqrt(delta)) / (2 * a);
        cout << "X: " << x << endl;
        cout << "Y: " << y;
    }


}