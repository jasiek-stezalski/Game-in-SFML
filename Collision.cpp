#include "Collision.h"

Collision::Collision()
{
}

void Collision::kolizja(Enemy & E, Enemy & F, int &camX, int &camY, int &camA, int &camB)
{
	static double temp = 0;
	temp = sqrt(pow((E.getX() - F.getX()), 2) + pow((E.getY() - F.getY()), 2));
	if (temp <= E.getRad() + F.getRad())
	{
		if (E.getRad() >= F.getRad())
		{
			E.setRad(E.getRad() + 0.25);
			E.circle.setOrigin(E.getRad(), E.getRad());
			E.circle.setRadius(E.getRad());
			F.generateNewShape(camX, camY, camA, camB);
		}
		else
		{
			F.setRad(F.getRad() + 0.25);
			F.circle.setOrigin(F.getRad(), F.getRad());
			F.circle.setRadius(F.getRad());
			E.generateNewShape(camX, camY, camA, camB);
		}
	}
	else if (temp < E.getDistanceToEnymy())
	{
		E.setDistanceToEnymy(temp);
		E.setNextEnymy(F.getX(), F.getY(), F.getRad());
	}
}

void Collision::kolizja(Enemy & E, Food & F, int &camX, int &camY, int &camA, int &camB)
{
	static double temp = 0;
	temp = sqrt(pow((E.getX() - F.getX()), 2) + pow((E.getY() - F.getY()), 2));
	if (temp <= E.getRad() + F.getRad())
	{
		E.setRad(E.getRad() + 0.25);
		E.circle.setOrigin(E.getRad(), E.getRad());
		E.circle.setRadius(E.getRad());
		F.generateNewShape(camX, camY, camA, camB);
	}
	else if (temp < E.getDistanceToEnymy())
	{
		E.setDistanceToEnymy(temp);
		E.setNextEnymy(F.getX(), F.getY(), F.getRad());
	}
}

void Collision::kolizja(Player & P, Enemy & E, int &camX, int &camY, int &camA, int &camB)
{
	static double temp = 0;
	temp = sqrt(pow((P.getX() - E.getX()), 2) + pow((P.getY() - E.getY()), 2));
	if (temp <= P.getRad() + E.getRad())
	{
		if (P.getRad() >= E.getRad())
		{
			P.setRad(P.getRad() + 0.25);
			P.circle.setOrigin(P.getRad(), P.getRad());
			P.circle.setRadius(P.getRad());
			E.generateNewShape(camX, camY, camA, camB);
		}
		else
		{
			E.setRad(E.getRad() + 0.25);
			E.circle.setOrigin(E.getRad(), E.getRad());
			E.circle.setRadius(E.getRad());
			P.generateNewShape(camX, camY, camA, camB);
		}
	}
	else if (temp < E.getDistanceToEnymy())
	{
		E.setDistanceToEnymy(temp);
		E.setNextEnymy(P.getX(), P.getY(), P.getRad());
	}
}

void Collision::kolizja(Player & P, Food & F, int &camX, int &camY, int &camA, int &camB)
{
	if (pow((P.getX() - F.getX()), 2) + pow((P.getY() - F.getY()), 2) <= pow(P.getRad() + F.getRad(), 2))
	{
		P.setRad(P.getRad() + 0.25);
		P.circle.setOrigin(P.getRad(), P.getRad());
		P.circle.setRadius(P.getRad());
		F.generateNewShape(camX, camY, camA, camB);
	}
}

Collision::~Collision()
{
}


