// NOTE: it is recommended to use this even if you don't understand the following code.

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// input data
int N;
long long M, L;
vector<long long> D;

int main() {
//  uncomment the following lines if you want to read/write from files
  ifstream cin("input.txt");
  ofstream cout("output.txt");


    cin >> N >> M >> L;
    D.resize(N);
    for (int i=0; i<N; i++)
        cin >> D[i];

    // insert your code here

    // 1 --> N Checkpoint , Distanza binocolo , Lunghezza strada
    // 2 --> Metri dei vari checkpoint
    int count = 0;
    int ril = 0;
    //int checkpoints[N];
    int visione[N*2];
    for(int x = 0; x<N*2; x++){
      if(D[x]-M >=0){visione[x]=D[x]-M;}else{visione[x]=0;}
      cout<<visione[x]<<" ";
      x++;
      if(D[x]+M>L){visione[x]=L;}else{visione[x]=D[x]+M;};
      cout<<visione[x]<<" ";
    }
    cout<<endl;
    int idk = 0;
    for(int x = 0; x<N;x++){
      for(int y=0; y<N*2;y++){
        if(visione[idk]<=D[x] && visione[idk+1]>=D[x]){
          count++;
        }
        idk+=2;
      }
      if(ril>count || x==0){
        ril=count;
      }
      count=0;
      idk=0;
    }

    cout << ril << endl; // print the result
    return 0;
}
