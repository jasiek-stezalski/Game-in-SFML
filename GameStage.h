#pragma once

#include "LibsAndDeclarations.h"

class GameStage
{
public:
	GameStage();
	GameStage(const GameStage&) = delete;
	GameStage& operator=(const GameStage&) = delete;
	virtual ~GameStage();

private:
public:
	virtual bool init() = 0;
	virtual bool update(float dt) = 0;
	virtual void draw(sf::RenderWindow &window) = 0;
	virtual void release() = 0;
};
