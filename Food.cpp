#include "Food.h"
#include <random>

Food::Food()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<> distx(-250, 250);
	std::uniform_real_distribution<> disty(-150, 150);
	std::uniform_real_distribution<> distc(0, 255);
	x = distx(gen);
	y = disty(gen);
	square.setOrigin(rad, rad);
	square.setSize(sf::Vector2f(4, 4));
	square.setFillColor(sf::Color(distc(gen), distc(gen), distc(gen)));
	square.setPosition(x, y);
}

void Food::generateNewShape(int const &camX, int const &camY, int const &camW, int const &camH)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<> distx(camX, camX + camW);
	std::uniform_real_distribution<> disty(camY, camY + camH);
	std::uniform_real_distribution<> distc(0, 255);
	x = distx(gen);
	y = disty(gen);
	square.setFillColor(sf::Color(distc(gen), distc(gen), distc(gen)));
	square.setPosition(x, y);
}

Food::~Food()
{
}
