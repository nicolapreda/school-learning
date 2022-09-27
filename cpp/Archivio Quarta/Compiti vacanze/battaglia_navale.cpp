/*file navi.txt contiene una mappa
di dimensione 10x10 sulla quale sono
disposte 3 navi (una da tre elementi,
una da due e una da uno)*/

#include <iostream>
#include <fstream>
#include <stdio.h>  /* printf, scanf, puts, NULL */
#include <stdlib.h> /* srand, rand */
#include <time.h>   /* time */
/*
 */

using namespace std;

void setShots(int matrix[10][10], int ship3Pos[3][3], int ship2pos[2][2], int ship1Pos[2])
{

    fstream shotsFile;
    shotsFile.open("Colpi.txt", fstream::out);
    int nShots = rand() % 10 + 20, YShot, XShot, points = 0, ship3Shots = 0, ship2Shots = 0;
    
    shotsFile << "Numero di colpi disponibili: " << nShots << endl;
    for (int i = 0; i < nShots; i++)
    {

        XShot = rand() % 10;
        YShot = rand() % 10;

        if (ship1Pos[0] == YShot && ship1Pos[1] == XShot)
        {
            points += 10;
            shotsFile << "Colpita e affondata nave da 1; ";
        }
        if (ship2pos[0][1] == YShot && ship2pos[0][1] == XShot && ship2Shots < 3)
        {
            points += 10;
            shotsFile << "Colpita nave da 2; ";
            ship2Shots++;
        }
        if (ship2pos[1][1] == YShot && ship2pos[1][1] == XShot && ship2Shots < 3)
        {
            points += 10;
            shotsFile << "Colpita nave da 2; ";
            ship2Shots++;
        }

        if (ship3Pos[0][1] == YShot && ship3Pos[0][1] == XShot && ship3Shots < 4)
        {
            points += 10;
            shotsFile << "Colpita nave da 3; ";
            ship3Shots++;
        }
        if (ship3Pos[1][1] == YShot && ship3Pos[1][1] == XShot && ship3Shots < 4)
        {
            points += 10;
            shotsFile << "Colpita nave da 3; ";
            ship3Shots++;
        }
        if (ship3Pos[2][1] == YShot && ship3Pos[2][1] == XShot && ship3Shots < 4)
        {
            points += 10;
            shotsFile << "Colpita nave da 3; ";
            ship3Shots++;
        }
        if (ship3Shots == 3)
        {
            shotsFile << "Affondata nave da 3; ";
            points += 50;
        }
        if (ship2Shots == 2)
        {
            shotsFile << "Affondata nave da 2; ";
            points += 25;
        }

        shotsFile << YShot << " " << XShot << endl;
    }

    shotsFile << "Punti totali: " << points <<endl;
    shotsFile.close();
}

void setShips(int matrix[10][10])
{
    int ship3Pos[3][3], ship2pos[2][2], ship1Pos[2];
    srand(time(NULL));

    bool placed3 = false, placed2 = false;

    // set 1-length ship
    int randX1 = rand() % 10;
    int randY1 = rand() % 10;
    matrix[randY1][randX1] = 1;
    ship1Pos[randY1, randX1];

    // set 2-length ship
    while (placed2 == false)
    {
        int randX2 = rand() % 10, randY2 = rand() % 10;
        while (matrix[randY2][randX2] == 1 || matrix[randY2][randX2] == 3)
        {
            randX2 = rand() % 10;
            randY2 = rand() % 10;
        }
        matrix[randY2][randX2] = 2;
        ship2pos[0][0] = randY2;
        ship2pos[0][1] = randX2;

        // 0 => sopra
        // 1 => sotto
        // 2 => sinistra
        // 3 => destra
        int directionRand = rand() % 4;
        switch (directionRand)
        {
        case 0:
            if (matrix[randY2 - 1][randX2] == 0 && randY2 - 1 > 0)
            {
                matrix[randY2 - 1][randX2] = 2;
                ship2pos[1][0] = randY2 - 1;
                ship2pos[1][1] = randX2;
                placed2 = true;
            }
            else
            {
                placed2 = false;
            }

            break;
        case 1:
            if (matrix[randY2 + 1][randX2] == 0 && randY2 + 1 < 10)
            {
                matrix[randY2 + 1][randX2] = 2;
                ship2pos[1][0] = randY2 + 1;
                ship2pos[1][1] = randX2;
                placed2 = true;
            }
            else
            {
                placed2 = false;
            }
            break;
        case 2:
            if (matrix[randY2][randX2 - 1] == 0 && randX2 - 1 > 0)
            {
                matrix[randY2][randX2 - 1] = 2;
                ship2pos[1][0] = randY2;
                ship2pos[1][1] = randX2 - 1;
                placed2 = true;
            }
            else
            {
                placed2 = false;
            }
            break;
        case 3:
            if (matrix[randY2][randX2 + 1] == 0 && randX2 + 1 < 10)
            {
                matrix[randY2][randX2 + 1] = 2;
                ship2pos[1][0] = randY2;
                ship2pos[1][1] = randX2 + 1;
                placed2 = true;
            }
            else
            {
                placed2 = false;
            }
            break;
        default:
            break;
        }
    }

    // set 3-length ship
    while (placed3 == false)
    {
        int randX3 = rand() % 10, randY3 = rand() % 10;
        while (matrix[randY3][randX3] == 1 || matrix[randY3][randX3] == 2)
        {
            randX3 = rand() % 10;
            randY3 = rand() % 10;
        }

        matrix[randY3][randX3] = 3;
        ship3Pos[0][0] = randY3;
        ship3Pos[0][1] = randX3;
        // 0 => sopra
        // 1 => sotto
        // 2 => sinistra
        // 3 => destra
        int directionRand = rand() % 4;
        switch (directionRand)
        {
        case 0:
            if (matrix[randY3 - 2][randX3] == 0 && matrix[randY3 - 1][randX3] == 0 && randY3 - 2 > 0)
            {
                matrix[randY3 - 2][randX3] = 3;
                matrix[randY3 - 1][randX3] = 3;
                ship3Pos[1][0] = randY3 - 1;
                ship3Pos[1][1] = randX3;
                ship3Pos[2][0] = randY3 - 2;
                ship3Pos[2][1] = randX3;
                placed3 = true;
            }
            else
            {
                placed3 = false;
            }

            break;
        case 1:
            if (matrix[randY3 + 2][randX3] == 0 && matrix[randY3 + 1][randX3] == 0 && randY3 + 2 < 10)
            {
                matrix[randY3 + 2][randX3] = 3;
                matrix[randY3 + 1][randX3] = 3;
                ship3Pos[1][0] = randY3 + 1;
                ship3Pos[1][1] = randX3;
                ship3Pos[2][0] = randY3 + 2;
                ship3Pos[2][1] = randX3;
                placed3 = true;
            }
            else
            {
                placed3 = false;
            }
            break;
        case 2:
            if (matrix[randY3][randX3 - 2] == 0 && matrix[randY3][randX3 - 1] == 0 && randX3 - 2 > 0)
            {
                matrix[randY3][randX3 - 2] = 3;
                matrix[randY3][randX3 - 1] = 3;
                ship3Pos[1][0] = randY3;
                ship3Pos[1][1] = randX3 - 1;
                ship3Pos[2][0] = randY3;
                ship3Pos[2][1] = randX3 - 2;
                placed3 = true;
            }
            else
            {
                placed3 = false;
            }
            break;
        case 3:
            if (matrix[randY3][randX3 + 2] == 0 && matrix[randY3][randX3 + 1] == 0 && randX3 + 2 < 10)
            {
                matrix[randY3][randX3 + 2] = 3;
                matrix[randY3][randX3 + 1] = 3;
                ship3Pos[1][0] = randY3;
                ship3Pos[1][1] = randX3 + 1;
                ship3Pos[2][0] = randY3;
                ship3Pos[2][1] = randX3 + 2;
                placed3 = true;
            }
            else
            {
                placed3 = false;
            }
            break;
        default:
            break;
        }
    }

    setShots(matrix, ship3Pos, ship2pos, ship1Pos);
}

void initMap(int matrix[10][10])
{
    // initialize matrix
    for (int y = 0; y < 10; y++)
    {
        for (int x = 0; x < 10; x++)
        {
            matrix[y][x] = 0;
        }
    }
}

void output(int matrix[10][10])
{

    fstream gridFile;
    gridFile.open("Navi.txt", fstream::out);

    // print matrix
    for (int y = 0; y < 10; y++)
    {
        for (int x = 0; x < 10; x++)
        {
            gridFile << matrix[y][x] << " ";
        }
        gridFile << endl;
    }

    gridFile.close();
}

int main()
{
    int matrix[10][10];
    initMap(matrix);

    setShips(matrix);

    output(matrix);

    return 0;
}