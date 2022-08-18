#include <Game.h>

MainGame::~MainGame()
{
	delete window;
}

MainGame::MainGame()
{

	initializeVariables();
	initWindow();
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
}

void MainGame::render()
{
	// clear window
	window->clear();
}
