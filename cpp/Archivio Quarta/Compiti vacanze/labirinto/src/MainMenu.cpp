#include "Platform/Platform.hpp"
#include <Game.h>

using namespace sf;

int main()
{
	// initialize window
	RenderWindow MainMenu(VideoMode(1020, 730), "Labirynth", Style::Close);

	// initialize font text and variables for main menu
	Font font;
	Text mainMenu[2], title[2];
	font.loadFromFile("./content/fonts/ArcadeClassic.ttf");

	/*
	Texture texture;
	texture.loadFromFile("./content/background.png");
	Sprite sprite;
	sprite.setTexture(texture);
	sprite.setOrigin(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2);
	float xPos = (float)1024 / 2;
	float yPos = (float)720 / 2;
	sprite.setPosition(xPos, yPos);
	*/

	// initialize text
	for (int i = 0, h = 340; i < 3; i++, h += 100)
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
				title[i].setString("LABI");
				break;
			case 1:
				title[i].setString("RYNTH");
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
						if (mainMenuSelected > 0)
						{
							mainMenu[mainMenuSelected].setFillColor(Color::Blue);
							MainMenu.clear();
							mainMenuSelected--;
							mainMenu[mainMenuSelected].setFillColor(Color::White);
						}
						break;
					}
					if (event.key.code == Keyboard::Down)
					{
						if (mainMenuSelected < 2)
						{
							mainMenu[mainMenuSelected].setFillColor(Color::Blue);
							MainMenu.clear();
							mainMenuSelected++;

							mainMenu[mainMenuSelected].setFillColor(Color::White);
						}
						break;
					}
					if (event.key.code == Keyboard::Return)
					{
						int x = mainMenuSelected;

						// init game engine
						MainMenu.close();
						MainGame game;

						if (x == 0)
						{
							while (game.running())
							{

								game.update();
								game.render();
							}
						}
					}
					break;
				default:
					break;
			}

			MainMenu.clear();
			// draw texture
			MainMenu.draw(title[0]);
			MainMenu.draw(title[1]);

			MainMenu.draw(mainMenu[0]);
			MainMenu.draw(mainMenu[1]);
			MainMenu.display();
		}
	}
}