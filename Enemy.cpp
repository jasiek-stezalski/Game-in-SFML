#include "Enemy.h"
#include <random>

Enemy::Enemy()
{
	std::random_device rd; 
	std::mt19937 gen(rd());
	std::uniform_real_distribution<> distx(-250, 250);
	std::uniform_real_distribution<> disty(-150, 150);
	std::uniform_real_distribution<> distc(0, 255);
	std::uniform_real_distribution<> distr(2, 6);
	x = distx(gen);
	y = disty(gen);
	rad = distr(gen);
	circle.setRadius(rad);
	circle.setFillColor(sf::Color(distc(gen) , distc(gen), distc(gen)));
	circle.setPosition(x, y);
}

void Enemy::move()
{
	//std::cout << enemyY << " - " << y <<" ";
	if (moveCounter == 0)
	{
		if (rad > enemyRad)
		{
			moveCounter = (int)distanceToEnymy ;
			angle = fabs(y - enemyY) / distanceToEnymy;
			nextY = angle;
			nextX = sqrt(1 - nextY*nextY);
			
		}
		else 
		{
			moveCounter = 1;
			angle = fabs(y - enemyY) / distanceToEnymy;
			nextY = -angle;
			nextX = -sqrt(1 - nextY*nextY);
		}
		distanceToEnymy = 100000;
	}
	if (x < enemyX)
	{
		if (y < enemyY)
		{
			x += nextX;
			y += nextY;
		}
		else
		{
			x += nextX;
			y -= nextY;
		}
	}
	else
	{
		if (y < enemyY)
		{
			x -= nextX;
			y += nextY;
		}
		else
		{
			x -= nextX;
			y -= nextY;
		}
	}
	moveCounter--;
}

void Enemy::generateNewShape(int camX, int camY, int camW, int camH)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<> distx(camX, camX + camW);
	std::uniform_real_distribution<> disty(camY, camY + camH);
	std::uniform_real_distribution<> distr(2, 6);
	std::uniform_real_distribution<> distc(0, 255);
	x = distx(gen);
	y = disty(gen);
	rad = distr(gen);
	circle.setRadius(rad);
	circle.setFillColor(sf::Color(distc(gen), distc(gen), distc(gen)));
	circle.setPosition(x, y);
	distanceToEnymy = 100000;
}

void Enemy::setNextEnymy(double x, double y, double r)
{
	enemyX = x;
	enemyY = y;
	enemyRad = r;
}

Enemy::~Enemy()
{
}




