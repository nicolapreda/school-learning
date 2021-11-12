/*
 * NOTE: it is recommended to use this even if you don't
 * understand the following code.
 */

#include <iostream>
#include <vector>

using namespace std;

// input data
int N;
vector<int> A, B, L;

int main() {
//  uncomment the following lines if you want to read/write from files
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    cin >> N;
    A.resize(N);
    B.resize(N);
    L.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i] >> L[i];
    }

    // insert your code here

    int C = N; // number of chimneys produced

    cout << C << endl;
    for (int i = 0; i < C; i++) {
        int k = 1; // number of pipes in the i-th chimney
        cout << k << endl;

        // print the i-th chimney produced
        cout << i << endl;
    }
    return 0;
}
