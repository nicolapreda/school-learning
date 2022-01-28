
#include <iostream>

using namespace std;


int main()
{
  int vettore[5]= {1,2,3,4,5} ;
  int dimensione = 5;


  for (int i=0; i < dimensione / 2; ++i) {
    int tmp = vettore[i];
    vettore[i]=vettore[dimensione-1-i];
    vettore[dimensione-1-i]=tmp;
  }
  for (int i=0; i < dimensione; ++i)
    cout<<"\n"<< vettore[i];

  return 0;
}