#include <iostream>

using namespace std;

int main(){
    int a,b,c,res;
    cout<<"inserisci il primo numero:"<<endl;
    cin>>a;
    cout<<"inserisci il secondo numero:"<<endl;
    cin>>b;
    cout<<"inserisci il terzo numero:"<<endl;
    cin>>c;

    if (a >= b && a >= c)
    {
        cout<<"Il numero maggiore è: "<<a<<endl<<endl;
        return main();
    }else if(b >= a && b >= c){
        cout<<"Il numero maggiore è: "<<b<<endl<<endl;
        return main();
    }else if(c >= a && c >= b){
        cout<<"Il numero maggiore è: "<<c<<endl<<endl;
        return main();
    }else if(c == b && c == a){
        cout<<"I tre numeri sono uguali!"<<endl<<endl;
        return main();
    }
    
}