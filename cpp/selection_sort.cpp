#include <iostream>

using namespace std;

int main()
{
    int vettore[6] = {5, 4, 6, 3, 2, 1};
    int temp;
    for (int i = 0, min; i < 6; i++)
    {
        min = i;
        for (int j = i + 1; j < 6; j++)
            if (vettore[j] < vettore[min])
                min = j;

        temp = vettore[min];
        vettore[min] = vettore[i];
        vettore[i] = temp;
    }

    for(int x = 0; x < 6; x++) {
        cout<<vettore[x]<<endl;
    }
}