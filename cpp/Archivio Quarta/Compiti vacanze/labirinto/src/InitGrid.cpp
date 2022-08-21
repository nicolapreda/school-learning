#include <Game.h>
#include <fstream>

void MainGame::initMap()
{
	srand(time(NULL));

	//start map
	for (int y = 0; y < 7; y++)
	{
		for (int x = 0; x < 7; x++)
		{
			map[y][x] = 0;
		}
	}

	//set spawn point
	currentPositionY = rand() % 7;
	currentPositionX = rand() % 7;

	map[currentPositionY][currentPositionX] = 1;
	int lenght = 5;

	cout << currentPositionY << " ";
	cout << currentPositionX << endl
		 << endl;

	for (int i = 2; i <= lenght; i++)
	{

		// 0 => sopra
		// 1 => sotto
		// 2 => sinistra
		// 3 => destra
		int directionRand = rand() % 4;

		switch (directionRand)
		{
			case 0:
				if (map[currentPositionY - 1][currentPositionX] == 0 && currentPositionY - 1 >= 0)
				{
					map[currentPositionY - 1][currentPositionX] = i;
					currentPositionY--;
				}
				else
				{
					i--;
				}

				break;
			case 1:
				if (map[currentPositionY + 1][currentPositionX] == 0 && currentPositionY + 1 <= 7)
				{
					map[currentPositionY + 1][currentPositionX] = i;
					currentPositionY++;
				}
				else
				{
					i--;
				}
				break;
			case 2:
				if (map[currentPositionY][currentPositionX - 1] == 0 && currentPositionX - 1 >= 0)
				{
					map[currentPositionY][currentPositionX - 1] = i;
					currentPositionX--;
				}
				else
				{
					i--;
				}
				break;
			case 3:
				if (map[currentPositionY][currentPositionX + 1] == 0 && currentPositionX + 1 <= 7)
				{
					map[currentPositionY][currentPositionX + 1] = i;
					currentPositionX++;
				}
				else
				{
					i--;
				}
				break;
			default:
				break;
		}
	}
	fstream gridFile;
	gridFile.open("gridFile.txt", fstream::out);
	//print matrix
	for (int y = 0; y < 7; y++)
	{
		for (int x = 0; x < 7; x++)
		{
			gridFile << map[y][x] << " ";
			cout << map[y][x] << " ";
		}
		cout << "\n";
		gridFile << "CIAO";
	}
	gridFile.close();
	cout << "\n\n\n";
}
