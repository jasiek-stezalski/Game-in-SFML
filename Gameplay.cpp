#include "Gameplay.h"


Gameplay::Gameplay()
{
}

Gameplay::~Gameplay()
{
	release();
}

void Gameplay::updateCamera()
{
	if (player.getX() - player.getRad() < camX + 0.1 * camW)
	{
		camX--;
		camera.reset(sf::FloatRect(camX, camY, camW, camH));
	}
	else if (player.getX() + player.getRad() > camX + camW - 0.1 * camW)
	{
		camX++;
		camera.reset(sf::FloatRect(camX, camY, camW, camH));
	}
	else if (player.getY() - player.getRad() < camY + 0.1 * camH)
	{
		camY--;
		camera.reset(sf::FloatRect(camX, camY, camW, camH));
	}
	else if (player.getY() + player.getRad() > camY + camH - 0.1 * camH)
	{
		camY++;
		camera.reset(sf::FloatRect(camX, camY, camW, camH));
	}

	//Dla testów////////////////
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
	{
		camY--;
		camX--;
		camW+=2;
		camH+=2;
		camera.reset(sf::FloatRect(camX, camY, camW, camH));
	}
	////////////////////////////
}

bool Gameplay::init()
{
	camera.reset(sf::FloatRect(camX, camY, camW, camH));
	return true;
}

bool Gameplay::update(float dt)
{
	player.move();
	player.circle.setPosition(player.getX(), player.getY());
	updateCamera();
	for (int i = 0; i <food.size(); ++i)
	{
		collision.kolizja(player, food[i], camX, camY, camW, camH);
		camera.reset(sf::FloatRect(camX, camY, camW, camH));
		if (player.getRad() > counter)
		{
			counter += 10;
			camX -= 50;
			camY -= 50;
			camW += 100;
			camH += 100;
		}
		camera.reset(sf::FloatRect(camX, camY, camW, camH));
		for (int j = 0; j < enemy.size(); j++)
			collision.kolizja(enemy[j], food[i], camX, camY, camW, camH);
	}
	for (int i = 0; i < enemy.size(); i++)
	{
		enemy[i].move();
		enemy[i].circle.setPosition(enemy[i].getX(), enemy[i].getY());
		collision.kolizja(player, enemy[i], camX, camY, camW, camH);
		for (int j = 0; j < enemy.size(); j++)
			if (i != j)
				collision.kolizja(enemy[i], enemy[j], camX, camY, camW, camH);
	}

	return true;
}

void Gameplay::draw(sf::RenderWindow &window)
{
	window.setView(camera);

	window.clear(sf::Color(0, 255, 0));
	window.draw(player.circle);
	for (Enemy E : enemy)
		window.draw(E.circle);


	for (Food F : food)
		window.draw(F.square);

	window.setView(window.getDefaultView());
}

void Gameplay::release()
{
}
