#include "Ball.h"

Ball::Ball()
{
	this->setFillColor(sf::Color::Red);
	this->setOutlineThickness(1);
	this->setOutlineColor(sf::Color::Black);
}

void Ball::Update(float moveball, float paddlespeed, float deltatime)
{
	float pi = 3.14159f;
	this->move(sin(moveball * pi / 180) * paddlespeed * deltatime,
		-cos(moveball * pi / 180) * paddlespeed * deltatime);
}