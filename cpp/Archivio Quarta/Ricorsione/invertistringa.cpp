/*funzione ricorsiva che inverte stringa*/

#include <iostream>

using namespace std;

void inverti(char *s);

int main()
{
    char s[100];
    cout << "Inserisci una stringa: ";
    cin >> s;
    inverti(s);
    cout << "La stringa invertita e': " << s << endl;
    return 0;
}

void inverti(char *s)
{
    if (*s == '\0')
        return;
    else
    {
        inverti(s + 1);
        cout << *s;
    }
}

