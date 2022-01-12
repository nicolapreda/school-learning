#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// input data
int N;
vector<int> A, B;

int main() {
    ifstream cin("input.txt");
    ofstream cout("output.txt");
    
    cin >> N;
    A.resize(N);
    B.resize(N);
    int count = 0;
    for (int i=0; i<N; i++){
        cin >> A[i] >> B[i];
        if(B[i]>=A[i-1]){
            count++;
        }
        if(i>0 && A[i]<=B[i-1]){
            count++;
        }
    }
     
    if(count-(N-1)==N){
        cout << "YES" << endl;
    }else{
        cout<<"NO"<<endl;
    }
     // print the result
    return 0;
}