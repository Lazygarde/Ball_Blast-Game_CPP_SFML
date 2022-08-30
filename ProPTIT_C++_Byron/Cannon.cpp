#include "Cannon.h"

Cannon::Cannon()
{
	godown = true;
	wheeltexture.loadFromFile("../data/wheel.png");
	barreltexture.loadFromFile("../data/barrel.png");
	wheel.setTexture(wheeltexture);
	barrel.setTexture(barreltexture);
	wheel.scale(0.3f, 0.3f);
	barrel.scale(0.3f, 0.3f);
	wheel.setPosition(342.25, 611);
	barrel.setPosition(371.95f, 553);
}

void Cannon::update(float paddlespeed, float deltatime)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && wheel.getPosition().x >= 0) {
		wheel.move(-paddlespeed * deltatime, 0);
		barrel.move(-paddlespeed * deltatime, 0);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && wheel.getPosition().x <= 800 - 385 * 0.3) {
		wheel.move(paddlespeed * deltatime, 0);
		barrel.move(paddlespeed * deltatime, 0);
	}

	if (barrel.getPosition().y <= 552)
		godown = true;
	if (barrel.getPosition().y >= 562)
		godown = false;


	if (godown == true) {
		barrel.move(0, 100 * deltatime);
	}
	else {
		barrel.move(0, -100 * deltatime);
	}
}