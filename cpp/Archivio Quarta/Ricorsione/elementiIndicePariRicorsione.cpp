#include <iostream>

using namespace std;

int indicePari(int v[10], int n);

int main(){
    int v[5] = {1,2,3,4,5};

    cout<<indicePari(v, 5);
}

int indicePari(int v[10], int n){
    if(n == 0)
        return -1;
    else if(v[n-1] % 2 == 0)
        return n-1;
    else
        return indicePari(v, n-1);
}