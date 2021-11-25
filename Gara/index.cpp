#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ifstream inFile;
    inFile.open("input.txt");
    cout<<inFile;
}