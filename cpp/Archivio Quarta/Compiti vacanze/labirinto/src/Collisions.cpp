#include <Game.h>

int MainGame::checkDoorCollision()
{
	for (int i = 0; i < 4; i++)
	{
		if (player.getGlobalBounds().intersects(door[i].getGlobalBounds()))
		{
			return i;
		}
	}
	return -1;
}

bool MainGame::checkWallCollision()
{
	for (int y = 0, counter = 0; y < 11; y++)
	{
		for (int x = 0; x < 17; x++, counter++)
		{
			if (x == 0 || y == 0 || x == 16 || y == 10)
			{
				//check if collides the entire area of the grid
				if (player.getGlobalBounds().intersects(grid[counter].getGlobalBounds()))
				{

					return true;
				}
			}
		}
	}
	return false;
}