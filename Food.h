#pragma once

#include "LibsAndDeclarations.h"

class Food
{
private:
	double x;
	double y;
	double rad = 1.99;
public:
	sf::RectangleShape square;
	Food();
	void Food::generateNewShape(int const &camX, int const &camY, int const &camW, int const &camH);
	double getX() { return x; }
	double getY() { return y; }
	double getRad() { return rad; }
	~Food();
};




