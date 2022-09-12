#include <Game.h>

void MainGame::winMenu()
{
	// initialize button result selected
	buttonResultSelected = 1;

	sf::Text exitButton, nextLevelButton, resultString;
	sf::Font font;
	font.loadFromFile("./content/fonts/ArcadeClassic.ttf");

	// initialize window
	RenderWindow winMenu(VideoMode(1020, 730), "Labirynth", Style::Close);

	// set result string
	resultString.setFont(font);
	resultString.setCharacterSize(60);

	resultString.setString("You won!!");
	updateRoom(1);

	resultString.setFillColor(Color::Green);

	sf::FloatRect textRect = resultString.getLocalBounds();
	resultString.setOrigin(textRect.left + textRect.width / 2.0f,
		textRect.top + textRect.height / 2.0f);
	resultString.setPosition(sf::Vector2f(1020 / 2.0f, 730 / 2.0f));

	exitButton.setFont(font);
	exitButton.setPosition(Vector2f(150.f, 500.f));
	exitButton.setFillColor(Color::Blue);
	exitButton.setCharacterSize(30);
	exitButton.setString("Exit");

	nextLevelButton.setFont(font);
	nextLevelButton.setPosition(Vector2f(650.f, 500.f));
	nextLevelButton.setFillColor(Color::White);
	nextLevelButton.setString("Play again");
	nextLevelButton.setCharacterSize(30);

	while (winMenu.isOpen())
	{
		Event event;

		while (winMenu.waitEvent(event))
		{

			switch (event.type)
			{
				case Event::Closed:
					winMenu.close();
					break;
				case Event::KeyReleased:
					if (event.key.code == Keyboard::Left)
					{
						if (buttonResultSelected == 1)
						{
							exitButton.setFillColor(Color::White);
							winMenu.clear();
							buttonResultSelected = 0;
							nextLevelButton.setFillColor(Color::Blue);
						}
						break;
					}
					if (event.key.code == Keyboard::Right)
					{
						if (buttonResultSelected == 0)
						{
							nextLevelButton.setFillColor(Color::White);
							winMenu.clear();
							buttonResultSelected = 1;

							exitButton.setFillColor(Color::Blue);
						}
						break;
					}
					if (event.key.code == Keyboard::Return)
					{
						MainGame game;
						if (buttonResultSelected == 1)
						{
							winMenu.close();
						}
						else
						{
							updateRoom(-1);
							winMenu.close();
							gameMode = 0;
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
			winMenu.clear();

			winMenu.draw(resultString);
			winMenu.draw(exitButton);
			winMenu.draw(nextLevelButton);

			winMenu.display();
		}
	}
}