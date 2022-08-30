#include "Bullet.h"

Bullet::Bullet(sf::Texture& texture, float cnpstion_x, float xnpstion_y)
{
	this->setTexture(texture);
	this->setScale(0.12, 0.12);
	this->setPosition(cnpstion_x + 385 * 0.3 / 2 - 98 * 0.1 / 2\
		, xnpstion_y - 341 * 0.3 / 2 + 40);
}

void Bullet::update(float paddlespeed, float deltatime)
{
	this->move(0, -paddlespeed * deltatime);
}
