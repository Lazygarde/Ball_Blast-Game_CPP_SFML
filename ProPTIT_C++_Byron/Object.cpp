#include "Object.h"

Object::Object()
{
	srand(time(NULL));
	this->start = true;
	this->left = false;
	this->godown = true;
	if (ball.getPosition().x <= 200) this->ballspeed = 50;
	else this->ballspeed = 75+5-rand()%10;
	this->timeline = 0;
	sf::Color color(0, 255, 0);
	ball.setFillColor(color);
	Object::updateFont();
}

void Object::setsize(bool left) {
	this->left = left;
}

void Object::setdiemso(int diemso) {
	this->diemso = diemso;
}

void Object::updateDeltatime(float deltatime)
{
	this->deltatime = deltatime;
}

void Object::setmoveball(float moveball)
{
	this->moveball = moveball;
}


void Object::updateFont()
{
	if (!font.loadFromFile("../data/font.ttf")) {}
	text.setFont(font);
	text.setCharacterSize(20);
	text.setFillColor(sf::Color::Black);
}

void Object::updateSizechu()
{
	if (diemso < 10) sizechu = 53;
	else if (diemso < 100) sizechu = 47;
	else if (diemso < 1000) sizechu = 40;
}

void Object::setposition(float y) {
	if (left == true) {
		ballspeed = 55;
		ball.setPosition(-ball.getRadius() - 1, y);
		this->moveball = 90;
	}
	else {
		ballspeed = 55;
		ball.setPosition(801, y);
		this->moveball = -90;
	}
}

void Object::updateText()
{
	text.setString(to_string(diemso));
}

void Object::updateBallspeed()
{
		if (godown == true) {
			if (ballspeed <= 400&&!start) {
				if (ballspeed >= 300) ballspeed = ballspeed + 0.6 * timeline;
				else ballspeed = ballspeed + 0.8 * timeline;
			}
		}
		else {
			start = false;
			if (ball.getPosition().y <= 60) ballspeed = 20;
			else if (ball.getPosition().y <= 400) ballspeed = ballspeed - 0.40 * timeline;
			else ballspeed = ballspeed - 0.6 * timeline;
		}
}

void Object::updateMoveball()
{
	if (start == true) {
		if (left) {
			if (ball.getPosition().x > 20) {
				timeline = 0;
				moveball = 145;
				ballspeed = 100;
				start = false;
			}
		}
		else {
			if (ball.getPosition().x +ball.getRadius()*2<780) {
				timeline = 0;
				moveball = -145;
				ballspeed = 100;
				start = false;
			}
		}
	}
	else {
		if (ballspeed < 30 || ball.getPosition().y <= 40) {
			timeline = 0;
			godown = true;
			ballspeed = 100;
			moveball = 180 - moveball;
		}
		if (ball.getPosition().y >= 667.7f - ball.getRadius() * 2) {
			timeline = 0;
			godown = false;
			ballspeed = 450;
			moveball = 180 - moveball;
		}
		if (ball.getPosition().x <= 1 || ball.getPosition().x >= 800 - 2 * ball.getRadius() - 1) {
			moveball = -moveball;
		}
	}
}

void Object::updatePositionForText()
{
	text.setPosition(ball.getPosition().x + ball.getRadius()-text.getLocalBounds().width*0.7,
		ball.getPosition().y + ball.getRadius()-text.getLocalBounds().height);
}

void Object::update()
{
	timeline += deltatime;
	Object::updateSizechu();
	Object::updateText();
	Object::updateBallspeed();
	Object::updateMoveball();
	Object::updatePositionForText();
	ball.Update(moveball, ballspeed, deltatime);
}