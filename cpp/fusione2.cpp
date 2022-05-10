#include <iostream>

using namespace std;

void fondi(int V1[], int V2[], int V3[], int n)
{
    int i = 0, j = 0, k = 0;
    do
    {
        if (V1[i] < V2[j])
            V3[k++] = V1[i++];
        else
            V3[k++] = V2[j++];

    } while (i < n && j < n);
    // copio la coda dell'array non ancora terminato
    if (i == n)
        for (int y = j; y < n; y++)
            V3[k++] = V2[y];
    else
        for (int y = i; y < n; y++)
            V3[k++] = V1[y];
}

void visualizza(int Arr[], int n)
{

    for (int i = 0; i < n; i++)
        cout << Arr[i] << "\t";
    cout << endl;
}

int main()
{
    int B[7] = {2, 5, 8, 12, 15, 20, 30};
    int A[7] = {1, 3, 6, 9, 17, 33, 37};
    int C[14] = {0};

    visualizza(C, 14);
    fondi(A, B, C, 7);
    visualizza(C, 14);
}
