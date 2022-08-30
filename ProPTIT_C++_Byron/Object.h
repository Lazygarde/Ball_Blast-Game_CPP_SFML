#pragma once
#include "Ball.h"
#include <algorithm>
class Object
{
public:
	int ballstart;
	bool start;
	bool godown;
	bool left;
	float timeline;
	float ballspeed;
	float moveball;
	float deltatime;
	int sizechu;
	int diemso;
	Ball ball;
	sf::Font font;
	sf::Text text;
	Object();
	void setposition(float y);
	void setsize(bool left);
	void setdiemso(int diemso);
	void updateDeltatime(float deltatime);
	void setmoveball(float moveball);
	void updateFont();
	void updateSizechu();
	void updateText();
	void updateBallspeed();
	void updateMoveball();
	void updatePositionForText();
	void update();
};