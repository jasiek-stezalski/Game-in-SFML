#include "LibsAndDeclarations.h"

#include "Menu.h"
#include "Gameplay.h"

int main(void)
{
	const int game_width = 1366;
	const int game_height = 768;

	// Create the window of the application
	sf::RenderWindow window(sf::VideoMode(game_width, game_height, 32), "SFML Test", sf::Style::Titlebar | sf::Style::Close| sf::Style::Resize);
	window.setVerticalSyncEnabled(true);

	std::unique_ptr<GameStage> game_stage = std::make_unique<Menu>();
	if (!game_stage->init()) return false;

	sf::Clock clock;
	bool is_playing = false;
	while (window.isOpen())
	{
		// EVENTS
		{
			sf::Event event;
			while (window.pollEvent(event))
			{
				// Window closed or escape key pressed: exit
				if ((event.type == sf::Event::Closed) || ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape)))
				{
					game_stage.reset();
					window.close();
					break;
				}
			}
		}

		// UPDATE
		{
			float delta_time = clock.restart().asSeconds();
			if (!is_playing)
			{
				if (game_stage && !game_stage->update(delta_time))
				{
					is_playing = true;

					game_stage.reset();
					game_stage = std::make_unique<Gameplay>();
					game_stage->init();
				}
			}
			else
			{
				if (game_stage && !game_stage->update(delta_time))
				{
					game_stage.reset();
					window.close();
					break;
				}
			}
		}

		// DRAW
		{
			window.clear(sf::Color(0, 0, 0));

			if (game_stage) game_stage->draw(window);

			window.display();
		}
	}

	return 0;
}
