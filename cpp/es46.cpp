#include <iostream>

using namespace std;

int main(){
    long long millenni;
    double massa;
    
    cout<<"Numero di millenni trascorsi\n";
    cin>>millenni;

    cout<<"Massa iniziale del materiale radioattivo (g):\n";
    cin>>massa;

    for(int x = 0; x< millenni; x++){
      massa/=2;
    }
    cout<<"Massa finale: "<<massa<<"g\n";
    main();
}