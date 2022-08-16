#include <iostream>
#include <string.h>
#include <ctype.h>

using namespace std;



int main()
{   int n,a;
    char stringa1[100];

    cout << "Scrivi la prima stringa" << endl;
    cin>>stringa1;

    // converto in maiuscolo

    for (int i=0;i<strlen(stringa1);i++){

        stringa1[i]=toupper(stringa1[i]);
    }

    cout<<stringa1<<endl;


    return 0;
}