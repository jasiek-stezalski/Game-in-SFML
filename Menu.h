#pragma once

#include "LibsAndDeclarations.h"
#include "GameStage.h"

class Menu : public GameStage
{
public:
	Menu();
	Menu(const Menu&) = delete;
	Menu& operator=(const Menu&) = delete;
	virtual ~Menu();

private:
	sf::Font font;
	sf::Text message;

public:
	virtual bool init();
	virtual bool update(float dt);
	virtual void draw(sf::RenderWindow &window);
	virtual void release();
};
