#pragma once

#include "player.h"
#include "Food.h"
#include "Enemy.h"

class Collision
{
public:
	Collision();
	~Collision();

	void kolizja(Enemy & E, Enemy & F, int &camX, int &camY, int &camA, int &camB);

	void kolizja(Enemy & P, Food & F, int &camX, int &camY, int &camA, int &camB);

	void kolizja(Player &P, Enemy &E, int &camX, int &camY, int &camA, int &camB);

	void kolizja(Player &P, Food &F, int &camX, int &camY, int &camA, int &camB);


};

/*
template<class AnyType>
void Collision::kolizja(AnyType & P, Food & F, int &camX, int &camY, int &camA, int &camB)
{
	if (pow((P.getX() - F.getX()), 2) + pow((P.getY() - F.getY()), 2) <= pow(P.getRad() + 2, 2))
	{
			P.setRad(P.getRad() + 0.25);
			P.circle.setOrigin(P.getRad(), P.getRad());
			P.circle.setRadius(P.getRad());
			F.generateNewShape(camX, camY, camA, camB);
	}
}
*/
