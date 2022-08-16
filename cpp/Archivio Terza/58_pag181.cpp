#include <iostream>

using namespace std;
void substring(char s1[], int p1, int p2, char s2[])
{

    
        for (int i = p1; i < p2; i++)
        {
            s2[i] = s1[i];
        }
        for (int i = 0; i < 10; i++)
        {
            cout<<s2[i];
        }
        
    
}

int main()
{
    char stringa[100], stringa2[100];
    int p1, p2;

    cout << "Inserisci la stringa\n";
    cin >> stringa;

    cout << "Inserisci la prima posizione\n";
    cin >> p1;
    cout << "Inserisci la seconda posizione\n";
    cin >> p2;

    substring(stringa, p1, p2, stringa2);
}