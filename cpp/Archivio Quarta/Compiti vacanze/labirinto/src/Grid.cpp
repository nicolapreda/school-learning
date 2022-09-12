#include <Game.h>
#include <fstream>

// initialize plane table
void MainGame::initPlaneTable()
{
	// draw plane table
	planeTable.setFillColor(Color(0, 0, 85));
	planeTable.setSize(Vector2f(1020, 100));
	planeTable.setPosition(Vector2f(0, 0));

	//load font
	if (!font.loadFromFile("./content/fonts/ArcadeClassic.ttf"))
	{
		cout << "Font not loaded" << endl;
	}

	//set score string
	scoreString.setFont(font);
	scoreString.setPosition(Vector2f(10.f, 50.f));
	scoreString.setFillColor(Color::White);
	scoreString.setCharacterSize(30);

	//set life string
	lifeString.setFont(font);
	lifeString.setPosition(Vector2f(800.f, 10.f));
	lifeString.setFillColor(Color::White);
	lifeString.setCharacterSize(30);

	//set room string
	roomString.setFont(font);
	roomString.setPosition(Vector2f(800.f, 50.f));
	roomString.setFillColor(Color::White);
	roomString.setCharacterSize(30);
}

void MainGame::initTextureGrid()
{
	int yPos = 84, xPos = 0;
	for (int y = 0, counter = 0; y < 11; y++, yPos += 60, xPos = 0)
	{
		for (int x = 0; x < 17; x++, counter++, xPos += 60)
		{
			if (x == 0 || y == 0 || x == 16 || y == 10)
			{
				if (!wall.loadFromFile("./content/perm_wall.png"))
				{
					cout << "Texture not loaded" << endl;
				}
				grid[counter].setTexture(wall);
			}
			else
			{
				if (!floor.loadFromFile("./content/floor.jpg"))
				{
					cout << "Texture not loaded" << endl;
				}
				grid[counter].setTexture(floor);
			}
			grid[counter].setPosition(xPos, yPos);
		}
	}
}

void MainGame::initMap(int length)
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

	cout << currentPositionY << " ";
	cout << currentPositionX << endl
		 << endl;

	for (int i = 2; i <= length; i++)
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
		gridFile << "\n";
	}
	gridFile.close();
	cout << "\n\n\n";
}

void MainGame::updateMap()
{
	fstream gridFile;
	gridFile.open("gridFile.txt");
	for (int y = 0; y < 7; y++)
	{
		for (int x = 0; x < 7; x++)
		{
			gridFile >> map[y][x];
		}
	}
}

void MainGame::placeDoors()
{

	for (int i = 0; i < 4; i++)
	{
		if (!doorTexture.loadFromFile("./content/door.jpg"))
		{
			cout << "Texture not loaded" << endl;
		}
		door[i].setTexture(doorTexture);

		switch (i)
		{
			case 0:
				door[i].setPosition(420, 86);
				break;
			case 1:
				door[i].rotate(180.f);

				door[i].setPosition(658, 741);
				break;
			case 2:
				door[i].rotate(-90.f);
				door[i].setPosition(1, 504);
				break;
			case 3:
				door[i].rotate(90.f);
				door[i].setPosition(1019, 264);

			default:
				break;
		}
	}
}

void MainGame::loadMapFromFile()
{
	fstream gridFile;
	gridFile.open("customMap.txt");
	for (int y = 0; y < 7; y++)
	{
		for (int x = 0; x < 7; x++)
		{
			gridFile >> map[y][x];
		}
	}
}