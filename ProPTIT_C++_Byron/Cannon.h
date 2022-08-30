#pragma once
#include <SFML/Graphics.hpp>
class Cannon
{
public:
	bool godown;
	sf::Texture wheeltexture;
	sf::Texture barreltexture;
	sf::Sprite wheel;
	sf::Sprite barrel;
	Cannon();
	void update(float paddlespeed, float deltatime);
};

