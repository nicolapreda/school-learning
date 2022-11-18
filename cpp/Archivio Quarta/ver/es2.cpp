/**/
#include <iostream>

using namespace std;

string cambiaStr(string st, int len);
int main()
{

    string s = "4321";
    string s1 = cambiaStr(s, 4);
    cout << s + s1 << endl;
}

string cambiaStr(string st, int len)
{
    if (len == 0)
        return "";
    return st.at(len - 1) + cambiaStr(st.substr(0, len - 1), len - 1);
}