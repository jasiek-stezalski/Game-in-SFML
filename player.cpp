#include "player.h"
#include <random>
#include <windows.h>


Player::Player()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<> distx(-25, 25);
	std::uniform_real_distribution<> disty(-25, 25);
	x = distx(gen);
	y = disty(gen);
	circle.setRadius(rad);
	circle.setOrigin(rad, rad);
	circle.setFillColor(sf::Color::Blue);
	circle.setOutlineThickness(0.5);
	circle.setPosition(x, y);
}

void Player::move()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		y--;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		x--;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		y++;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		x++;
}

void Player::generateNewShape(int &camX, int &camY, int &camW, int &camH)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<> distx(-200, 200);
	std::uniform_real_distribution<> disty(-100, 100);
	x = distx(gen);
	y = disty(gen);
	rad = 2;
	circle.setRadius(rad);
	circle.setOrigin(rad, rad);
	circle.setPosition(x, y);
	camW = 400;
	camH = 200;
	camX = x - camW / 2;
	camY = y - camH / 2;
	Sleep(1000);
}

Player::~Player()
{
}


