/*funzione ricorsiva che calcola le occorrenze di un carattere*/

#include <iostream>

using namespace std;

int conta(char c, char *s);

int main()
{
    char s[100];
    char c;
    cout << "Inserisci una stringa: ";
    cin >> s;
    cout << "Inserisci un carattere: ";
    cin >> c;
    cout << "Il carattere " << c << " compare " << conta(c, s) << " volte nella stringa " << s << endl;
    return 0;
}

int conta(char c, char *s)
{
    if (*s == '\0')
        return 0;
    else
        if (*s == c)
            return 1 + conta(c, s + 1);
        else
            return conta(c, s + 1);
}
