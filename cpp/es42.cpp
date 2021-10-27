#include <iostream>
using namespace std;

int main() {
  long long caselle, chicchi_f = 1; 
  cout<<"Numero di caselle\n";
  cin>>caselle;

  for(int x = 1; x < caselle; x++){
    chicchi_f *= 2;
  }
  cout<<"Numero di chicchi finale: "<<chicchi_f<<endl<<endl;
  main();
} 