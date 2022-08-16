#include <iostream>
#include <cmath>
using namespace std;


float distanzapunti(int px, int py,int p1x, int p1y ){
      sqrt(pow((p1x - px), 2) + pow((p1y-py), 2));
      
}


int main(){
    int x1,x2,y1,y2,x3,y3;
    cout << "Inserisci la x della prima coordinata\n";
    cin>>x1;
    cout << "Inserisci la y della prima coordinata\n";
    cin>>y1;

    cout << "Inserisci la x della seconda coordinata\n";
    cin>>x2;
    cout << "Inserisci la y della seconda coordinata\n";
    cin>>y2;

    cout << "Inserisci la x della terza coordinata\n";
    cin>>x2;
    cout << "Inserisci la y della terza coordinata\n";
    cin>>y2;
    
    cout<<"Il perimetro del triangolo è: "<<endl;
    cout<< distanzapunti(x1,y1,x2,y2) + distanzapunti(x2,y2,x3,y3) + distanzapunti(x1,y1,x3,y3)<<endl;
    
}