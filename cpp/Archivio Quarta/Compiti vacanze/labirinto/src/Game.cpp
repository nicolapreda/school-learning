#include <Game.h>

MainGame::~MainGame()
{
	delete window;
}

MainGame::MainGame(5)
{

	initializeVariables();
	initWindow();
	initMap(length);

	if (updateRoom(0) == 5)
	{
		winMenu();
	}

	initPlaneTable();

	initTextureGrid();
	placeDoors();
	initPlayer();
	rightDoor = checkDoor(updateRoom(0));
}

int MainGame::checkDoor(int room)
{
	for (int y = 0; y < 7; y++)
	{
		for (int x = 0; x < 7; x++)
		{
			if (map[y][x] == room)
			{
				if (map[y + 1][x] == room + 1)
					return 1;
				else if (map[y][x + 1] == room + 1)
					return 3;
				else if (map[y - 1][x] == room + 1)
					return 0;
				else if (map[y][x - 1] == room + 1)
					return 2;
			}
		}
	}
	return -1;
}

bool MainGame::running()
{
	return window->isOpen();
}

// functions
void MainGame::update()
{
	pollEvents();
}

void MainGame::initializeVariables()
{
	window = nullptr;
}

void MainGame::initWindow()
{
	// init height and width of the window
	videoMode.height = 730;
	videoMode.width = 1020;

	// init main variables
	life = 3;

	// init window
	window = new RenderWindow(videoMode, "Labirynth", Style::Close);

	// set a framerate limit
	window->setFramerateLimit(144);
}

void MainGame::pollEvents()
{
	while (window->pollEvent(event))
	{

		// manage events
		switch (event.type)
		{
			case Event::Closed:
				window->close();
				break;
			default:
				break;
		}
	}
	int doorCollision = checkDoorCollision();
	if (doorCollision == rightDoor)
	{
		window->close();
		updateScore(100);
		resultPage(0);
	}
	// check player movements
	if (Keyboard::isKeyPressed(Keyboard::Key::A))
	{

		player.move(-2.0f, 0.0f);

		if (checkWallCollision())
		{
			player.move(2.0f, 0.0f);
		}
	}
	if (Keyboard::isKeyPressed(Keyboard::Key::W))
	{

		player.move(0.0f, -2.0f);

		if (checkWallCollision())
		{
			player.move(0.0f, 2.0f);
		}
	}
	if (Keyboard::isKeyPressed(Keyboard::Key::S))
	{

		player.move(0.0f, 2.0f);

		if (checkWallCollision())
		{
			player.move(0.0f, -2.0f);
		}
	}
	if (Keyboard::isKeyPressed(Keyboard::Key::D))
	{

		player.move(2.0f, 0.0f);

		if (checkWallCollision())
		{
			player.move(-2.0f, 0.0f);
		}
	}
}

void MainGame::render()
{
	// clear window
	window->clear();

	//draw elements
	for (int i = 0; i < 187; i++)
	{
		window->draw(grid[i]);
	}

	for (int x = 0; x < 4; x++)
	{
		window->draw(door[x]);
	}

	window->draw(planeTable);

	//set score string
	scoreString.setString("Score  " + to_string(updateScore(0)));
	window->draw(scoreString);

	//set life string
	lifeString.setString("Lifes  " + to_string(life));
	window->draw(lifeString);

	//set level string
	roomString.setString("Room  " + to_string(updateRoom(0)));
	window->draw(roomString);

	window->draw(player);

	window->display();

	if (life <= 0)
	{
		updateScore(-1);
		window->close();
		resultPage(1);
	}
}

void MainGame::initPlayer()
{
	// load texture
	if (!playerTexture.loadFromFile("./content/main.png"))
	{
		cout << "Texture player not loaded" << endl;
	}
	player.setTexture(playerTexture);
	player.setPosition(61.f, 144.f);
}

int MainGame::updateRoom(int addRoom)
{
	static int room = 1;
	if (addRoom == 1)
	{
		++room;
	}
	else if (addRoom == -1)
	{
		room = 1;
	}

	return room;
}

int MainGame::updateScore(int addScore)
{
	static int score = 0;

	if (addScore == -1)

		score = 0;
	else if (addScore > 0)
		score += addScore;

	return score;
}