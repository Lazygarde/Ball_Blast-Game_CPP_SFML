#pragma once
#include <SFML/Graphics.hpp>
class Intro
{
public:
	bool goleft;
	sf::Texture introtexture;
	sf::Texture introballtexture;
	sf::Sprite intro;
	sf::Sprite introball;
	Intro();
	void Update(float deltatime);
};

