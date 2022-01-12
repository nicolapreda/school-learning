#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// input data
int N;
string S;

int main() {
    //  uncomment the following lines if you want to read/write from files
    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    cin >> N;
    cin >> S;
    
    // insert your code here
    int giusta;
    char parola[N];

    for(int i=0;i<S.length();i++)
    {
        parola[i] = ("%c,",S[i]);
    }
    char pirla[26]={'q','w','e','r','t','y','u','i','o','p','a','s','d','f','g','h','j','k','l','z','x','c','v','b','n','m'};
    S.clear();
    for(int y = 0; y<N; y++){
        for(int x = 0; x<26;x++){
            if(parola[y]==pirla[x]){
                S += pirla[x+1];
                break;
            }
        }
    }

    cout << S << endl; // print the result
    return 0;
}
