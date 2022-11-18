#include <iostream>

using namespace std;

int somma(int v[100], int n);
int main(){
    int n;
    cin>>n;
    int v[n];
    for(int i = 0; i < n; i++){
        cin>>v[i];
    }
    for(int i = 0; i < n; i++){
        cout<<v[i]<<" ";
    }
    
    cout<< somma(v, n)<<endl;
}

int somma(int v[100], int n){
    if(n == 0) return 0;
    return v[n-1]+somma(v,n-1);
}