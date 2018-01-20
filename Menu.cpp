#include "Menu.h"

Menu::Menu()
{
}

Menu::~Menu()
{
	release();
}

bool Menu::init()
{
	if (!font.loadFromFile("resources/sansation.ttf"))
		return false;

	message.setFont(font);
	message.setCharacterSize(40);
	message.setPosition(170.f, 150.f);
	message.setColor(sf::Color::White);
	message.setString("SFML test - Menu\nPress space to start the game");

	return true;
}

bool Menu::update(float dt)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) return false;

	return true;
}

void Menu::draw(sf::RenderWindow &window)
{
	window.clear(sf::Color(255, 0, 0));
	window.draw(message);
}

void Menu::release()
{
	message = sf::Text();
	font = sf::Font();
}
