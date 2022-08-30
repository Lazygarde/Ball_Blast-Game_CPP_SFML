#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
class Ball : public sf::CircleShape
{
public:
	Ball();
	void Update(float moveball, float paddlespeed, float deltatime);
};