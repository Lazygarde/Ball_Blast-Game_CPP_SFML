#include "Intro.h"

Intro::Intro()
{
	goleft = true;
	Intro::introtexture.loadFromFile("../data/intro.png");
	Intro::introballtexture.loadFromFile("../data/introball.png");
	intro.setTexture(introtexture);
	introball.setTexture(introballtexture);
	intro.scale(0.12, 0.12);
	introball.scale(0.12, 0.12);
	intro.setPosition(400-introtexture.getSize().x*0.12/2, 430);
	introball.setPosition(400 - introballtexture.getSize().x * 0.12 / 2, 430);
}

void Intro::Update(float deltatime)
{
	if (introball.getPosition().x <= 400 - introtexture.getSize().x * 0.12 / 2)
		goleft = false;
	if (introball.getPosition().x >= 400 + introtexture.getSize().x * 0.12 / 2 - introballtexture.getSize().x*0.12)
		goleft = true;
	if (goleft == true)
		introball.move(-deltatime * 200,0);
	else
		introball.move(deltatime * 200, 0);
}
