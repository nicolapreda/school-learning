/*stringa s di caratteri, scrivere una funzione ricorsiva c++ che restituisca la stringa ottenuta da s eliminando tutti gli spazi bianchi*/

#include <iostream>
#include <string>
using namespace std;

string eliminaSpazi(string s);

int main()
{
    string s;
    cout << "Inserisci la stringa: ";
    getline(cin, s);
    cout << "Stringa senza spazi: " << eliminaSpazi(s) << endl;
    return 0;
}

string eliminaSpazi(string s)
{
    if(s.length() == 0)
        return "";
    if(s[0] == ' ')
        return eliminaSpazi(s.substr(1));
    return s[0] + eliminaSpazi(s.substr(1));
}

