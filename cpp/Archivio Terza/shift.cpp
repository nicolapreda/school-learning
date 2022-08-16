#include <iostream>

using namespace std;

int main()
{
    const int N = 7;
    int A[N] = {1, 2, 3, 4, 5, 6, 7};

    // shift a sinistra

    int temp = A[0];
    for (int i = 0; i < N - 1; i++)
        A[i] = A[i + 1];
    A[N - 1] = temp;

    for (int i = 0; i < N; i++)
        cout << A[i] << " ";
    cout << endl;

    int B[N] = {1, 2, 3, 4, 5, 6, 7};

    // shift a destra di 3
    for (int j = 1; j <= 3; j++)
    {
        temp = B[N - 1];
        for (int i = N - 1; i >= 0; i--)
            B[i] = B[i - 1];
        B[0] = temp;
    }
    for (int i = 0; i < N; i++)
        cout << B[i] << " ";
}
