#include <iostream>
using namespace std;

int main(){
    int numero = 1; 

    for(int r = 1; r <= 10; r++){
        for (int c = 1; c <= 10; c++)
        {
            cout<<numero<<" ";
            numero++;
        }
        cout<<endl;
        
    }
}