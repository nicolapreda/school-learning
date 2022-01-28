#include <iostream>

using namespace std;

string S;

int main()
{
    unsigned long long index = 0;
    unsigned long long pot26 = 1;
    cin >> S;
    for (int i = 1; i < S.length(); i++)
    {
        pot26 = pot26 * 26;
        index = index + pot26;
    }

    unsigned long long pos = 0;
    for (int x = 0; x < S.length(); x++)
    {
        pos = S.at(S.length() - x - 1) - 97;
        for (int y = 0; y < x; y++)
        {
            pos *= 26;
        }
        index = index + pos;
    }

    cout << index << endl;
}
