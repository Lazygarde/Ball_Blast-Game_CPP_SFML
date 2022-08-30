#pragma once
#include <SFML/Graphics.hpp>
class Bullet :public sf::Sprite {
public:
	Bullet(sf::Texture& texture, float cnpstion_x, float xnpstion_y);
	void update(float paddlespeed, float deltatime);
};