#include <iostream>
#include <fstream>
using namespace std;

int main(){
    char N[5],diam[9];
    int i = 0,num,nump;
    ifstream inFile;
    inFile.open("input.txt");
    inFile.getline(N,5,'\n');
    num = atoi(N);
    cout << num << endl;

    while (i < num && inFile.eof())
    {
        inFile.getline(diam,9,' ');
        nump = atoi(diam);
        cout << nump << endl;
    }
} 