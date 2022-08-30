#include "Game.h"

bool Game::checkCollision(float R, float Xc, float Yc, float X1, float Y1, float X2, float Y2) {
	float Xn = max(X1, min(Xc, X2));
	float Yn = max(Y1, min(Yc, Y2));
	float Dx = Xn - Xc;
	float Dy = Yn - Yc;
	return (Dx * Dx + Dy * Dy) <= R * R;
}

void Game::Play() {

	sf::Music music;
	music.openFromFile("../data/music.ogg");
	music.play();

	srand(time(NULL));
	float scrx = 800;
	float scry = 800;
	sf::RenderWindow window(sf::VideoMode(scrx, scry), "Ball Blast");

	sf::Texture cannontexture;
	sf::Texture bullettexture;
	sf::Texture backgroundtexture;
	sf::Texture lighttexture;
	sf::Texture steeltexture;
	sf::Texture endbgtexture;
	sf::Texture logotexture;

	sf::Font font;
	sf::Text text;
	if (!font.loadFromFile("../data/font.ttf")) {}
	text.setFont(font);
	text.setCharacterSize(100);
	text.setFillColor(sf::Color::Yellow);


	sf::Text start_text;
	start_text.setFont(font);
	start_text.setCharacterSize(50);
	start_text.setFillColor(sf::Color::Black);
	start_text.setString("Press left or right to play");
	start_text.setPosition(400 - start_text.getLocalBounds().width / 2, 350);

	sf::Text tittletext;
	tittletext.setFont(font);
	tittletext.setCharacterSize(80);
	tittletext.setFillColor(sf::Color::Black);
	tittletext.setString("Ball Blast");
	tittletext.setPosition(400 - tittletext.getLocalBounds().width / 2, 80);


	lighttexture.loadFromFile("../data/light.png");
	sf::Sprite light;
	light.setTexture(lighttexture);
	light.scale(0.7, 0.7);
	pair <sf::Sprite, float> xs;
	xs.first = light;
	xs.second = 0;
	vector <pair<sf::Sprite, float>> lights;


	Intro INTRO;

	sf::Text about;
	about.setFont(font);
	about.setCharacterSize(40);
	about.setFillColor(sf::Color::Black);
	about.setString("      Game C++ SFML\nFrom ProPTIT with love!");
	about.setPosition(400 - about.getLocalBounds().width / 2, 160);

	sf::Text aboutto;
	aboutto.setFont(font);
	aboutto.setCharacterSize(28);
	aboutto.setFillColor(sf::Color::Black);
	aboutto.setString("Press Space to continue");
	aboutto.setPosition(400 - aboutto.getLocalBounds().width / 2 + 80, 300);

	backgroundtexture.loadFromFile("../data/bg.jpg");
	bullettexture.loadFromFile("../data/bullet.png");
	steeltexture.loadFromFile("../data/steel.png");
	endbgtexture.loadFromFile("../data/endbg.png");




	sf::Sprite endbg;
	endbg.setTexture(endbgtexture);
	sf::Color color = endbg.getColor();
	color.a = 100;
	endbg.setColor(color);
	endbg.scale(0.2, 0.12);
	endbg.setPosition(400 - endbgtexture.getSize().x * 0.1, 120);

	sf::Sprite bg;
	bg.setTexture(backgroundtexture);
	bg.scale((float)800 / 697, (float)800 / 697);

	sf::Sprite steel;
	steel.setTexture(steeltexture);
	steel.setOrigin(steel.getPosition().x + steeltexture.getSize().x / 2
		, steel.getPosition().y + steeltexture.getSize().y / 2);
	steel.setPosition(400, 250);

	sf::Sprite logo;
	logotexture.loadFromFile("../data/LogoCLB.png");
	logo.setTexture(logotexture);
	logo.setOrigin(logo.getPosition().x + logotexture.getSize().x / 2
		, logo.getPosition().y + logotexture.getSize().y / 2);

	logo.setScale(0.12, 0.12);
	logo.setPosition(steel.getPosition().x, steel.getPosition().y);

	int highscore = 0;
	int gamestart = 0;
	int newball = 50;
	vector <Bullet> b;
	Cannon cannon;
	sf::Clock clock;
	float paddlespeed = 800;
	float deltatime = 0.f;
	int k = 0;
	float timelinetobullet = 0, timeline = 0;
	int ok = 1;
	int u = 0;

	int gst = 0;
	Object x;
	vector <Object> objects;
	objects.push_back(x);

	int tongdiem = 0;
	while (window.isOpen()) {
		deltatime = clock.restart().asSeconds();
		sf::Event event;

		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}
		if (gamestart == 0) {
			newball = 50;
			tongdiem = 0;
			objects.clear();
			b.clear();
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
				sf::Vector2i ms = sf::Mouse::getPosition(window);
				if ((ms.x - logo.getPosition().x) * (ms.x - logo.getPosition().x) +
					(ms.y - logo.getPosition().y) * (ms.y - logo.getPosition().y) <= logotexture.getSize().x * 0.12 * logotexture.getSize().x * 0.12) {
					gst = 1;
				}
			}
			if (gst == 1) {
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
					gst = 0;
				}
				window.draw(bg);
				window.draw(endbg);
				window.draw(about);
				window.draw(aboutto);
			}

			if (gst == 0) {
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) ||
					sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
					gamestart = 1;
				}
				if (INTRO.goleft == true) {
					cannon.wheel.move(-120 * deltatime, 0);
					cannon.barrel.move(-120 * deltatime, 0);
				}
				else {
					cannon.wheel.move(120 * deltatime, 0);
					cannon.barrel.move(120 * deltatime, 0);
				}
				steel.rotate(deltatime * 100);
				logo.rotate(deltatime * 100);
				INTRO.Update(deltatime);
				window.clear(sf::Color::Green);
				window.draw(bg);
				window.draw(logo);
				window.draw(INTRO.intro);
				window.draw(INTRO.introball);
				window.draw(steel);
				window.draw(tittletext);
				window.draw(cannon.wheel);
				window.draw(cannon.barrel);
				window.draw(start_text);
			}
			window.display();
		}


		if (gamestart == 1) {
			timelinetobullet += deltatime;
			timeline += deltatime;

			if (timelinetobullet >= 0.08 * k) {
				Bullet a(bullettexture, cannon.wheel.getPosition().x, cannon.barrel.getPosition().y);
				b.push_back(a);
				k++;
			}

			for (int i = 0; i < b.size(); i++) {
				b[i].update(paddlespeed, deltatime);
			}

			for (int i = 0; i < objects.size(); i++) {
				objects[i].updateDeltatime(deltatime);
				objects[i].update();
			}

			int s = 0, s2 = 0;
			for (int i = 0; i < objects.size(); i++) {
				if (objects[i].ball.getRadius() == 70) {
					s += 7 * objects[i].diemso;
					s2 += 7;
				}

				else if (objects[i].ball.getRadius() == 55) {
					s += 3 * objects[i].diemso;
					s2 += 3;
				}
				else {
					s += objects[i].diemso;
					s2++;
				}
			}

			if (s < newball && objects.size() < 4 && s2 < 5) {
				bool left = true;
				int randdiem = rand() % 100;
				int randsize = rand() % 2;
				float randpos = rand() % 400;
				if (randpos < 200) randpos = 200;
				int randrad = rand() % 3;
				if (randsize < 101) randsize = 101;
				objects.push_back(x);
				if (randrad == 1) {
					if (randdiem > 45) randdiem = 45 - rand() % 10;
					objects[objects.size() - 1].ballstart = randdiem;
					objects[objects.size() - 1].setdiemso(randdiem);
					objects[objects.size() - 1].ball.setRadius(40);
				}
				else if (randrad == 2) {
					if (randdiem < 40) randdiem = 40 + rand() % 5;
					objects[objects.size() - 1].ballstart = randdiem;
					objects[objects.size() - 1].setdiemso(randdiem);
					objects[objects.size() - 1].ball.setRadius(55);
				}
				else {
					if (randdiem < 70) randdiem = 70 + rand() % 5;
					objects[objects.size() - 1].ballstart = randdiem;
					objects[objects.size() - 1].setdiemso(randdiem);
					objects[objects.size() - 1].ball.setRadius(70);
				}
				if (k == 1) objects[objects.size() - 1].setsize(true);
				else objects[objects.size() - 1].setsize(false);
				objects[objects.size() - 1].setposition(randpos);
				newball += 2;
			}


			for (int i = 0; i < lights.size(); i++) {
				lights[i].second += deltatime;
			}

			for (int i = 0; i < objects.size(); i++) {
				float ballx = objects[i].ball.getPosition().x + objects[i].ball.getRadius();
				float bally = objects[i].ball.getPosition().y + objects[i].ball.getRadius();
				if (Game::checkCollision(objects[i].ball.getRadius(), ballx, bally,
					cannon.barrel.getPosition().x, cannon.barrel.getPosition().y + cannon.barreltexture.getSize().y * 0.3,
					cannon.barrel.getPosition().x + cannon.barreltexture.getSize().x * 0.3, cannon.barrel.getPosition().y)) {
					gamestart = -1;
					break;
				}
				if (Game::checkCollision(objects[i].ball.getRadius(), ballx, bally,
					cannon.wheel.getPosition().x, cannon.wheel.getPosition().y + cannon.wheeltexture.getSize().y * 0.3,
					cannon.wheel.getPosition().x + cannon.wheeltexture.getSize().x * 0.3, cannon.wheel.getPosition().y)) {
					gamestart = -1;
					break;
				}

				for (int j = 0; j < b.size(); j++) {
					float bulletx = b[j].getPosition().x, bullety = b[j].getPosition().y;
					if ((ballx - bulletx) * (ballx - bulletx) + (bally - bullety) * (bally - bullety) <= objects[i].ball.getRadius() * objects[i].ball.getRadius()) {
						for (int ii = 0; ii < 3; ii++) {
							objects[i].diemso--;
							if (objects[i].diemso < 0) break;
							tongdiem++;
							window.draw(text);
						}
						b.erase(b.begin() + j, b.begin() + j + 1);
						j--;
					}
				}
				if (objects[i].diemso <= 0) {

					if (objects[i].ball.getRadius() == 70) {
						objects.push_back(x);
						objects[objects.size() - 1].setmoveball(35);
						int randd = rand() % (objects[i].ballstart / 2);
						if (randd < 20) randd = 20 + rand() % 10;
						objects[objects.size() - 1].setdiemso(randd);
						objects[objects.size() - 1].ball.setRadius(55);
						objects[objects.size() - 1].ballspeed = 100+7-rand()%15;
						objects[objects.size() - 1].godown = false;
						objects[objects.size() - 1].ball.setPosition(objects[i].ball.getPosition().x, objects[i].ball.getPosition().y);
						objects.push_back(x);
						objects[objects.size() - 1].setmoveball(-35);
						objects[objects.size() - 1].ball.setRadius(55);
						objects[objects.size() - 1].ballspeed = 100 + 7 - rand() % 15;
						objects[objects.size() - 1].godown = false;
						objects[objects.size() - 1].setdiemso(rand() % 60);
						objects[objects.size() - 1].ball.setPosition(objects[i].ball.getPosition().x, objects[i].ball.getPosition().y);
						newball += 2;
					}
					else if (objects[i].ball.getRadius() == 55) {
						objects.push_back(x);
						objects[objects.size() - 1].setmoveball(35);
						objects[objects.size() - 1].setdiemso(rand() % (objects[i].ballstart / 2));
						objects[objects.size() - 1].setdiemso(rand() % 60);
						objects[objects.size() - 1].ballspeed = 100;
						objects[objects.size() - 1].godown = false;
						objects[objects.size() - 1].ball.setRadius(40);
						objects[objects.size() - 1].ball.setPosition(objects[i].ball.getPosition().x, objects[i].ball.getPosition().y);
						objects.push_back(x);
						objects[objects.size() - 1].setmoveball(-35);
						objects[objects.size() - 1].ball.setRadius(40);
						objects[objects.size() - 1].ballspeed = 100;
						objects[objects.size() - 1].godown = false;
						objects[objects.size() - 1].setdiemso(rand() % 60);
						objects[objects.size() - 1].ball.setPosition(objects[i].ball.getPosition().x, objects[i].ball.getPosition().y);
						newball += 2;
					}
					xs.first.setPosition(objects[i].ball.getPosition().x, objects[i].ball.getPosition().y);
					lights.push_back(xs);
					lights[lights.size() - 1].first.scale(objects[i].ball.getRadius() / 40, objects[i].ball.getRadius() / 40);
					objects.erase(objects.begin() + i, objects.begin() + i + 1);
					i--;

				}
			}


			cannon.update(paddlespeed, deltatime);
			window.clear(sf::Color::Green);
			window.draw(bg);
			window.draw(cannon.wheel);
			window.draw(cannon.barrel);

			text.setString(to_string(tongdiem));
			text.setPosition(400 - text.getLocalBounds().width / 2, 75);
			window.draw(text);
			for (int i = 0; i < b.size(); i++) {
				window.draw(b[i]);
			}
			for (int i = 0; i < b.size(); i++) {
				if (b[i].getPosition().y < -100) {
					b.erase(b.begin() + i, b.begin() + i + 1);
					i--;
				}
			}
			for (int i = 0; i < lights.size(); i++) {
				if (lights[i].second < 0.1f && lights[i].first.getPosition().y>10) window.draw(lights[i].first);
			}
			for (int i = 0; i < objects.size(); i++) {
				window.draw(objects[i].ball);
				window.draw(objects[i].text);
			}

			window.display();
		}
		if (gamestart == -1) {
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
				INTRO.introball.setPosition(400 - INTRO.introtexture.getSize().x * 0.12 / 2, 430);
				cannon.wheel.setPosition(262.25, 611);
				cannon.barrel.setPosition(291.95f, 553);
				gamestart = 0;
				continue;
			}
			sf::Text hscore;
			sf::Text click;
			click.setFont(font);
			click.setCharacterSize(50);
			click.setFillColor(sf::Color::Black);
			click.setString("Click to continue");
			hscore.setFont(font);
			text.setCharacterSize(120);
			hscore.setCharacterSize(50);
			if (tongdiem <= highscore) {
				hscore.setString("Best score: " + to_string(highscore));
			}
			else {
				hscore.setString("New Record!");
				highscore = tongdiem;
			}
			click.setPosition(400 - click.getLocalBounds().width / 2, 430);
			text.setPosition(400 - text.getLocalBounds().width / 2, 140);
			hscore.setPosition(400 - hscore.getLocalBounds().width / 2, 270);
			window.clear(sf::Color::Yellow);
			window.draw(bg);
			for (int i = 0; i < objects.size(); i++) {
				objects[i].ballspeed = min(objects[i].ballspeed,500.f);
				window.draw(objects[i].ball);
				window.draw(objects[i].text);
				objects[i].update();
			}
			window.draw(endbg);
			window.draw(hscore);
			window.draw(cannon.barrel);
			window.draw(cannon.wheel);
			window.draw(text);
			window.draw(click);
			window.display();

		}
	}
}