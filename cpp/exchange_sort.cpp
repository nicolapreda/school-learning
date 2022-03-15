#include <iostream>

using namespace std;

int main()
{
    int vettore[10] = {2, 3, 6, 7, 5, 4, 8, 9, 0, 1};

    int temp;
    for (int i = 0; i < 10; i++)
    {
        for (int j = (i + 1); j < 10; j++)
        {
            if (vettore[i] > vettore[j])
            {
                temp = vettore[i];
                vettore[i] = vettore[j];
                vettore[j] = temp;
            }
        }
    }

    for (int i = 0; i < 10; i++)
    {
        cout<<vettore[i]<<endl;
    }
    
}