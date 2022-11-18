#include <iostream>

using namespace std;
int prodotto(int x, int y);

int main(){
    int x,y;
    cin>>x;
    cin>>y;

    cout<<prodotto(x,y)<<endl;
}


int prodotto(int x, int y){
    if(y == 0)
        return 0;
    return x+prodotto(x, y-1);
}