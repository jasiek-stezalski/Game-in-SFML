#pragma once

#include "LibsAndDeclarations.h"


class Player
{
private:
	double x;
	double y;
	double rad = 2;
public:
	sf::CircleShape circle;
	Player();
	~Player();
	void move();
	double getX() { return x; }
	double getY() { return y; }
	double getRad() { return rad; }
	void setRad(double r) { rad = r; }
	void generateNewShape(int &camX, int &camY, int &camW, int &camH);
};


