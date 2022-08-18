#include "Platform/Platform.hpp"
#include <Game.h>

int main()
{
	// initialize window
	RenderWindow MainMenu(VideoMode(1020, 730), "Bomberman", Style::Close);

	// initialize font text and variables for main menu
	Font font;
	Text mainMenu[2], title[2];
	font.loadFromFile("./content/fonts/ArcadeClassic.ttf");

	// load background
	Texture texture;
	texture.loadFromFile("./content/background.png");
	Sprite sprite;
	sprite.setTexture(texture);
	sprite.setOrigin(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2);
	float xPos = (float)1024 / 2;
	float yPos = (float)720 / 2;
	sprite.setPosition(xPos, yPos);

	// initialize text
	for (int i = 0, h = 340; i < 2; i++, h += 100)
	{
		mainMenu[i].setFont(font);
		mainMenu[i].setOutlineThickness(2);
		mainMenu[i].setOutlineColor(Color::Black);

		mainMenu[i].setCharacterSize(60);
		mainMenu[i].setPosition(100, h);
		mainMenu[i].setFillColor(Color::Blue);
		switch (i)
		{
			case 0:
				mainMenu[i].setFillColor(Color::White);
				mainMenu[i].setString("PLAY");
				break;
			case 1:
				mainMenu[i].setString("EXIT");
				break;
			default:
				break;
		}
	}

	// initialize title
	for (int i = 0, h = 50; i < 2; i++, h += 100)
	{
		title[i].setFont(font);
		title[i].setOutlineThickness(2);
		title[i].setOutlineColor(Color::Black);
		title[i].setFillColor(Color::White);
		title[i].setCharacterSize(150);
		title[i].setPosition(100, h);

		switch (i)
		{
			case 0:
				title[i].setString("BOMBER");
				break;
			case 1:
				title[i].setString("MAN");
				break;
			default:
				break;
		}
	}

	int mainMenuSelected = 0;
	while (MainMenu.isOpen())
	{
		Event event;

		while (MainMenu.waitEvent(event))
		{
			switch (event.type)
			{
				case Event::Closed:
					MainMenu.close();
					break;
				case Event::KeyReleased:
					if (event.key.code == Keyboard::Up)
					{
						if (mainMenuSelected == 1)
						{
							mainMenu[mainMenuSelected].setFillColor(Color::Blue);
							MainMenu.clear();
							mainMenuSelected = 0;
							mainMenu[mainMenuSelected].setFillColor(Color::White);
						}
						break;
					}
					if (event.key.code == Keyboard::Down)
					{
						if (mainMenuSelected == 0)
						{
							mainMenu[mainMenuSelected].setFillColor(Color::Blue);
							MainMenu.clear();
							mainMenuSelected = 1;
							mainMenu[mainMenuSelected].setFillColor(Color::White);
						}
						break;
					}
					if (event.key.code == Keyboard::Return)
					{
						int x = mainMenuSelected;

						// init game engine
						MainGame game;
						switch (x)
						{
							case 0:
								MainMenu.close();
								while (game.running())
								{
									game.update();
									game.render();
								}

								break;
							case 1:
								MainMenu.close();

								break;
							default:
								break;
						}
					}
					break;
				default:
					break;
			}

			MainMenu.clear();
			// draw texture
			MainMenu.draw(sprite);
			MainMenu.draw(title[0]);
			MainMenu.draw(title[1]);

			MainMenu.draw(mainMenu[0]);
			MainMenu.draw(mainMenu[1]);
			MainMenu.display();
		}
	}
}