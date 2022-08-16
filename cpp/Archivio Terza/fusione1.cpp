#include <iostream>

using namespace std;


//merge two arrays
void merge(int a[], int b[], int c[], int n, int m) {
    int i = 0, j = 0, k = 0;
    while (i < n && j < m) {
        if (a[i] < b[j]) {
            c[k] = a[i];
            i++;
        } else {
            c[k] = b[j];
            j++;
        }
        k++;
    }
    while (i < n) {
        c[k] = a[i];
        i++;
        k++;
    }
    while (j < m) {
        c[k] = b[j];
        j++;
        k++;
    }
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
    int A[8] = {1, 3, 6, 9, 17, 33, 37, 40};
    int C[14] = {0};

    visualizza(C, 14);
    merge(A, B, C, 7, 8);
    visualizza(C, 14);
}
