#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

void showMatrix(char matrix[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << matrix[i][j] << '\t';
        }
        cout << "\n\n";
    }
}


void skipLaunch(int b, char matrix[3][3])
{
    if (b == 2 || b == 5 || b == 8)
    {
        int a;
        showMatrix(matrix);

        cout << "Premi 1 per continuare\n";
        cin >> a;
        cout << "\n\n";
    }
}


bool checkWinner(char matrix[3][3], char player)
{

    // check if player has won horizontally
    for (int i = 0; i < 3; i++)
    {
        if (matrix[i][0] == player && matrix[i][1] == player && matrix[i][2] == player)
        {
            return true;
        }
    }
    // check if player has won vertically
    for (int i = 0; i < 3; i++)
    {
        if (matrix[0][i] == player && matrix[1][i] == player && matrix[2][i] == player)
        {
            return true;
        }
    }
    // check if player has won diagonally
    if (matrix[0][0] == player && matrix[1][1] == player && matrix[2][2] == player)
    {
        return true;
    }
    if (matrix[0][2] == player && matrix[1][1] == player && matrix[2][0] == player)
    {
        return true;
    }

    return false;
}
bool fillMatrix(char matrix[3][3], char player)
{

    // fill matrix with 0
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            matrix[i][j] = '-';
        }
    }
    int turn = 0;
    int b = 0;
    srand(time(NULL));

    for (int j = 0; j < 9; j++)
    {
        int randomX = rand() % 3;
        int randomY = rand() % 3;

        if (turn == 0)
        {
            if (matrix[randomX][randomY] == '-')
            {
                matrix[randomX][randomY] = 'X';
                turn = 1;
                b++;
                skipLaunch(b, matrix);
            }
            else
            {
                j--;
            }
        }
        else
        {
            if (matrix[randomX][randomY] == '-')
            {
                matrix[randomX][randomY] = 'O';
                turn = 0;
                b++;
                skipLaunch(b, matrix);
            }
            else
            {
                j--;
            }
        }

        if (checkWinner(matrix, player))
            return true;
    }
    return false;
}

int main()
{
    char matrix[3][3];
    // select player
    char player;
    while (player != 'X' && player != 'O')
    {
        cout << "Player 1 (X) or Player 2 (O)? ";
        cin >> player;
    }
    cout << endl;

    if (fillMatrix(matrix, player))
    {
        showMatrix(matrix);
        cout << "Hai vinto!" << endl;
    }
    else
    {
        showMatrix(matrix);
        cout << "Non hai vinto!" << endl;
    }

    return 0;
}
