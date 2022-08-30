#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <string>
#include "Bullet.h"
#include "Cannon.h"
#include "Ball.h"
#include "Object.h"
#include "Intro.h"
using namespace std;

class Game
{
public:
	void Play();
	bool checkCollision(float R, float Xc, float Yc, float X1, float Y1, float X2, float Y2);
};

