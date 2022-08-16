// NOTE: it is recommended to use this even if you don't understand the following code.

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// input data
string W;

int main() {
//  uncomment the following lines if you want to read/write from files
  ifstream cin("input.txt");
  ofstream cout("output.txt");

    cin >> W;

    // insert your code here
    char lettere[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    string prefix = "";
    int count = 0;
    for(int x = 0; x<W.length(); x++){
        prefix += "a";
    }

    cout << 42 << endl; // print the result
    return 0;
}
