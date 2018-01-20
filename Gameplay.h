#pragma once

#include "LibsAndDeclarations.h"
#include "GameStage.h"
#include "Player.h"
#include "Food.h"
#include "Enemy.h"
#include "Collision.h"
#include <vector>

class Gameplay : public GameStage
{
private:
	std::vector<Enemy> enemy = std::vector<Enemy>(25);
	std::vector<Food> food = std::vector<Food>(100);
	Player player;
	Collision collision;
	sf::View camera;
	int camX = -200;
	int camY = -100;
	int camW = 400;
	int camH = 200;
	int counter = 10;

public:
	Gameplay();
	Gameplay(const Gameplay&) = delete;
	Gameplay& operator=(const Gameplay&) = delete;
	void updateCamera();
	virtual ~Gameplay();
	virtual bool init();
	virtual bool update(float dt);
	virtual void draw(sf::RenderWindow &window);
	virtual void release();
};
