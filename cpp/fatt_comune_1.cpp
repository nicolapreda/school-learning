#include <iostream>

using namespace std;

int main()
{
    int x, y, min_divisore = 0;

    do
    {
        cout << "Inserisci x maggiore di 0\n";
        cin >> x;
    } while (x <= 0);

    do
    {
        cout << "Inserisci y maggiore di 0\n";
        cin >> y;
    } while (y <= 0);

    for(int i = 2; min_divisore != i; i++){
        if (x%i == 0 && y%i == 0)
        {
            min_divisore = i;
        }
        
    }
    cout<<min_divisore<<endl;
    
}