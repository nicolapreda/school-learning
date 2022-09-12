#include <Game.h>

void MainGame::resultPage(int result)
{
	// initialize button result selected
	buttonResultSelected = 1;

	sf::Text exitButton, nextLevelButton, resultString;
	sf::Font font;
	font.loadFromFile("./content/fonts/ArcadeClassic.ttf");

	// initialize window
	RenderWindow resultView(VideoMode(1020, 730), "Labirynth", Style::Close);

	// set result string
	resultString.setFont(font);
	resultString.setCharacterSize(60);

	if (result == 0)
	{
		resultString.setString("You  passed  the  room  " + to_string(updateRoom(0)) + " !!");
		updateRoom(1);

		resultString.setFillColor(Color::Green);
	}
	else if (result == 1)
	{
		resultString.setString("You  failed  the  room  " + to_string(updateRoom(0)) + " !!");
		resultString.setFillColor(Color::Red);

		updateRoom(-1);
	}

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
	nextLevelButton.setString("Go  to  room  " + to_string(updateRoom(0)));
	nextLevelButton.setCharacterSize(30);

	while (resultView.isOpen())
	{
		Event event;

		while (resultView.waitEvent(event))
		{

			switch (event.type)
			{
				case Event::Closed:
					resultView.close();
					break;
				case Event::KeyReleased:
					if (event.key.code == Keyboard::Left)
					{
						if (buttonResultSelected == 1)
						{
							exitButton.setFillColor(Color::White);
							resultView.clear();
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
							resultView.clear();
							buttonResultSelected = 1;

							exitButton.setFillColor(Color::Blue);
						}
						break;
					}
					if (event.key.code == Keyboard::Return)
					{
						if (buttonResultSelected == 1)
						{
							MainGame game;

							// init game engine
							resultView.close();
							while (game.running())
							{
								game.update();
								game.render();
							}
						}
						else
						{
							resultView.close();
						}
					}
					break;
				default:
					break;
			}
			resultView.clear();

			resultView.draw(resultString);
			resultView.draw(exitButton);
			resultView.draw(nextLevelButton);

			resultView.display();
		}
	}
}