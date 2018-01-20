#pragma once

#include "LibsAndDeclarations.h"

class Enemy
{
private:
	double x;
	double y;
	double rad = 2;

	int moveCounter = 0;
	double distanceToEnymy = 100000;
	double angle = 0;

	double nextX;
	double nextY;
	double enemyX;
	double enemyY;
	double enemyRad;
public:
	sf::CircleShape circle;
	Enemy();
	~Enemy();
	void move();
	double getX() { return x; }
	double getY() { return y; }
	double getRad() { return rad; }
	double getDistanceToEnymy() { return distanceToEnymy; }
	void setRad(double r) { rad = r; }
	void setNextEnymy(double x, double y, double r);
	void setDistanceToEnymy(double d) { distanceToEnymy = d; }
	void generateNewShape(int camX, int camY, int camW, int camH);
};

