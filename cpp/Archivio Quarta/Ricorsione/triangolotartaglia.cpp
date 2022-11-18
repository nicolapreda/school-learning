/*Disegnare il triangolo di Tartaglia*/
#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    int n;
    cout << "Inserisci la lunghezza del triangolo: ";
    cin >> n;
    int triangolo[n][n];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            triangolo[i][j] = 0;
    triangolo[0][0] = 1;
    for(int i = 1; i < n; i++)
        for(int j = 0; j <= i; j++)
            if(j == 0)
                triangolo[i][j] = triangolo[i - 1][j];
            else
                triangolo[i][j] = triangolo[i - 1][j] + triangolo[i - 1][j - 1];
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= i; j++)
            cout << triangolo[i][j] << " ";
        cout << endl;
    }
    return 0;
}