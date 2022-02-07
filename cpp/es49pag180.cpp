#include <iostream>
using namespace std;

bool palindroma(char s[])
{
    int lunghezza, i;
    for (lunghezza = 0; s[lunghezza] != '\0'; lunghezza++);
    for (i = 0; i < lunghezza / 2; i++)
        if (s[i] != s[lunghezza - i - 1])
            return false;
    return true;
}

int main()
{
    char stringa[100];

    cout << "Inserire la stringa: ";
    cin >> stringa;

    if (palindroma(stringa))
        cout << "Stringa palindroma" << endl;
    else
        cout << "Stringa non palindroma" << endl;
}
