#include <iostream>

using namespace std;

float power(float a, unsigned int b);
int main(){
    float a;
    unsigned int b;
    cin>>a;
    cin>>b;
    cout<<power(a,b)<<endl;
}


float power(float a, unsigned int b){
    if(b == 0) return 1;
    return a * power(a, b-1);
}