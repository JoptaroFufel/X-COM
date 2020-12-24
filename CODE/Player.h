#pragma once
#include "Map.h"
#include "Player.h"
using namespace sf;

class Player: public Map {
public:
	int lives[6];
	int steps[6];
	int pos_x[6];
	int pos_y[6];
	bool shoot[6];
	Image image[6];
	Texture texture[6];
	Texture tex_wpn[6];
	Texture tex_tbl;
	Texture avatars;
	Texture dead;
	Texture h;
	Texture aimer;
	Sprite aim;
	Sprite heart;
	Sprite avatar[6];
	Sprite player[6];
	Sprite weapon[6];
	Sprite table;
public:
	Player() {
		h.loadFromFile("Resources/health.png");
		aimer.loadFromFile("Resources/aim.png");
		tex_tbl.loadFromFile("Resources/panel.png");
		avatars.loadFromFile("Resources/kekich.png");
		dead.loadFromFile("Resources/dead.png");

		aim.setTexture(aimer);
		heart.setTexture(h);
		table.setTexture(tex_tbl);

		for (int i = 0; i < 3; i++) {
			avatar[i].setTexture(avatars);
			avatar[i].setTextureRect(IntRect(i * 150, 0, 150, 160));
			avatar[i].setPosition(Vector2f(0,map_central_y+i*200));
		}
		for (int i = 3; i < 6; i++) {
			avatar[i].setTexture(avatars);
			avatar[i].setTextureRect(IntRect(i * 150, 0, 150, 160));
			avatar[i].setPosition(Vector2f(win_weight - 150, map_central_y + (i-3) * 200));
		}

		image[0].loadFromFile("Resources/Snake Broskin.png");
		image[1].loadFromFile("Resources/Bro Dredd.png");
		image[2].loadFromFile("Resources/Dirty Brorry.png");
		image[3].loadFromFile("Resources/Brodell Walker.png");
		image[4].loadFromFile("Resources/Broniversal Soldier.png");
		image[5].loadFromFile("Resources/Col James Broddock.png");

		for (int i = 0; i < 6; i++) {
			texture[i].loadFromImage(image[i], IntRect(0, 0, 32, 32));
			player[i].setTexture(texture[i]);
			tex_wpn[i].loadFromImage(image[i], IntRect(0, 3 * 32, 32, 32));
			weapon[i].setTexture(tex_wpn[i]);
			player[i].setScale(2, 2);
			weapon[i].setScale(2, 2);
			lives[i] = 3;
			steps[i] = 10;
			shoot[i] = true;
		}

		player[0].setPosition(Vector2f(map_central_x + 16 + 32, map_central_y - 16 + 32));
		weapon[0].setPosition(Vector2f(map_central_x + 16 + 32, map_central_y - 16 + 32));
		pos_x[0] = 1; pos_y[0] = 1;
		player[1].setPosition(Vector2f(map_central_x + 16, map_central_y - 16 + 32));
		weapon[1].setPosition(Vector2f(map_central_x + 16, map_central_y - 16 + 32));
		pos_x[1] = 0; pos_y[1] = 1;
		player[2].setPosition(Vector2f(map_central_x + 16 + 32, map_central_y - 16));
		weapon[2].setPosition(Vector2f(map_central_x + 16 + 32, map_central_y - 16));
		pos_x[2] = 1; pos_y[2] = 0;
		player[3].setPosition(Vector2f(map_central_x + 16 + 16 * 32, map_central_y - 16 + 16 * 32));
		weapon[3].setPosition(Vector2f(map_central_x + 16 + 16 * 32, map_central_y - 16 + 16 * 32));
		pos_x[3] = 16; pos_y[3] = 16;
		player[4].setPosition(Vector2f(map_central_x + 16 + 16 * 32, map_central_y - 16 + 17 * 32));
		weapon[4].setPosition(Vector2f(map_central_x + 16 + 16 * 32, map_central_y - 16 + 17 * 32));
		pos_x[4] = 16; pos_y[4] = 17;
		player[5].setPosition(Vector2f(map_central_x + 16 + 17 * 32, map_central_y - 16 + 16 * 32));
		weapon[5].setPosition(Vector2f(map_central_x + 16 + 17 * 32, map_central_y - 16 + 16 * 32));
		pos_x[5] = 17; pos_y[5] = 16;

	}
	~Player() {};
	void drawing();
	void moving(int, int, float);
	void collision(int, int&);
	void animation(int, int&, float, int);
};