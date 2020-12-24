#include <iostream>
#include <SFML/Graphics.hpp>
#include "Player.h"

using namespace std;
using namespace sf;

void Player::drawing() {
	Vector2f pos;
	Text text[6];
	ostringstream out;
	

	for (int i = 0; i < 6; i++) {
		if (lives[i] == 0) {
			player[i].setTexture(dead);
			player[i].setTextureRect(IntRect(i * 32, 0, 32, 32));
			window.draw(player[i]);
		}
		else {
			window.draw(player[i]);
			window.draw(weapon[i]);
		}
	}

	for (int i = 0; i < 3; i++) {
		window.draw(avatar[i]);
		table.setTextureRect(IntRect(0, 0, 240, 60));
		table.setPosition(Vector2f(avatar[i].getPosition().x, avatar[i].getPosition().y + 128));
		window.draw(table);
		Text text1;
		Text text2;
		Text text3;
		text1.setFont(font);
		text2.setFont(font);
		text3.setFont(font);		
		text1.setCharacterSize(60);
		text2.setCharacterSize(30);
		text3.setCharacterSize(30);
		ostringstream out1,out2;
		out1 << steps[i];
		out2 << i+1;
		text1.setString(out1.str());
		text1.setPosition(Vector2f(table.getPosition().x+180, table.getPosition().y - 30));
		text3.setString(out2.str());
		text3.setPosition(Vector2f(table.getPosition().x + 10, table.getPosition().y + 25));
		window.draw(text1);
		window.draw(text3);
		if (lives[i] <= 0) {
			text2.setString("DEAD");
			text2.setPosition(Vector2f(avatar[i].getPosition().x + 2, avatar[i].getPosition().y + 120));
			window.draw(text2);
		}
		else for (int j = 0; j < lives[i]; j++) {
			heart.setPosition(Vector2f(Vector2f(avatar[i].getPosition().x + 2 + 33 * j, avatar[i].getPosition().y + 120)));
			window.draw(heart);
		}
	}
	for (int i = 3; i < 6; i++) {
		window.draw(avatar[i]);
		table.setTextureRect(IntRect(0, 60, 240, 60));
		table.setPosition(Vector2f(avatar[i].getPosition().x-90, avatar[i].getPosition().y + 128));
		window.draw(table);
		Text text1;
		Text text2;
		Text text3;
		text1.setFont(font);
		text2.setFont(font);
		text3.setFont(font);
		text1.setCharacterSize(60);
		text2.setCharacterSize(30);
		text3.setCharacterSize(30);
		ostringstream out1, out2;
		out1 << steps[i];
		out2 << i-2;
		text1.setString(out1.str());
		text3.setString(out2.str());
		text1.setPosition(Vector2f(win_weight - 250, table.getPosition().y - 30));
		text3.setPosition(Vector2f(win_weight - 25, table.getPosition().y + 25));
		window.draw(text1);
		window.draw(text3);
		if (lives[i] <= 0) {
			text2.setString("DEAD");
			text2.setPosition(Vector2f(win_weight - 2 - 160, avatar[i].getPosition().y + 120));
			window.draw(text2);
		}
		else for (int j = 0; j < lives[i]; j++) {
			heart.setPosition(Vector2f(Vector2f(win_weight - 2 - 33*(j+1), avatar[i].getPosition().y + 120)));
			window.draw(heart);
		}
	}
}

void Player::moving(int i, int direction, float time) {
	if (lives[i]<=0) {
		return;
	}
	if (direction == 1) {
		player[i].move(-32 * (time / 500), 0);
		weapon[i].move(-32 * (time / 500), 0);
	}
	if (direction == 2) {
		player[i].move(32* (time / 500), 0);
		weapon[i].move(32 * (time / 500), 0);
	}
	if (direction == 3) {
		player[i].move(0, -32 * (time / 500));
		weapon[i].move(0, -32 * (time / 500));
	}
	if (direction == 4) {
		player[i].move(0, 32 * (time / 500));
		weapon[i].move(0, 32 * (time / 500));
	}
}

void Player::animation(int i, int& dir, float time, int kek) {
	static float frame;
	frame += time*0.01;
	if (kek == 0) {
		if (frame > 3) {
			frame = 0;
		}
		if (dir == 3) {
			texture[i].loadFromImage(image[i], IntRect(32 * (int)frame, 0, 32, 32));
			tex_wpn[i].loadFromImage(image[i], IntRect(32 * (int)frame, 32 * 2, 32, 32));
			player[i].setTexture(texture[i]);
			weapon[i].setTexture(tex_wpn[i]);
		}
		if (dir == 1) {
			texture[i].loadFromImage(image[i], IntRect(32 * 3 - (32 * (int)frame), 0, 32, 32));
			tex_wpn[i].loadFromImage(image[i], IntRect(32 * 3 - (32 * (int)frame), 32 * 2, 32, 32));
			player[i].setTexture(texture[i]);
			player[i].setTextureRect(IntRect(31, 0, -32, 32));
			weapon[i].setTexture(tex_wpn[i]);
			weapon[i].setTextureRect(IntRect(31, 0, -32, 32));
		}
		if (dir == 2) {
			texture[i].loadFromImage(image[i], IntRect((32 * (int)frame), 0, 32, 32));
			tex_wpn[i].loadFromImage(image[i], IntRect((32 * (int)frame), 32 * 2, 32, 32));
			player[i].setTexture(texture[i]);
			player[i].setTextureRect(IntRect(0, 0, 32, 32));
			weapon[i].setTexture(tex_wpn[i]);
			weapon[i].setTextureRect(IntRect(0, 0, 32, 32));
		}
		if (dir == 4) {
			texture[i].loadFromImage(image[i], IntRect((32 * (int)frame), 0, 32, 32));
			tex_wpn[i].loadFromImage(image[i], IntRect((32 * (int)frame), 32 * 2, 32, 32));
			player[i].setTexture(texture[i]);
			weapon[i].setTexture(tex_wpn[i]);
		}
	}
	else if (kek == 1) {
		if (frame > 3) {
			frame = 0;
			shoot[i] = false;
		}
		if (dir == 3) {
			texture[i].loadFromImage(image[i], IntRect(0, 0, 32, 32));
			tex_wpn[i].loadFromImage(image[i], IntRect(32 * (int)frame, 32 * 3, 32, 32));
			player[i].setTexture(texture[i]);
			weapon[i].setTexture(tex_wpn[i]);
		}
		if (dir == 1) {
			texture[i].loadFromImage(image[i], IntRect(0, 0, 32, 32));
			tex_wpn[i].loadFromImage(image[i], IntRect(32 * 3 - (32 * (int)frame), 32 * 3, 32, 32));
			player[i].setTexture(texture[i]);
			weapon[i].setTexture(tex_wpn[i]);
		}
		if (dir == 2) {
			texture[i].loadFromImage(image[i], IntRect(0, 0, 32, 32));
			tex_wpn[i].loadFromImage(image[i], IntRect((32 * (int)frame), 32 * 3, 32, 32));
			player[i].setTexture(texture[i]);
			weapon[i].setTexture(tex_wpn[i]);
		}
		if (dir == 4) {
			texture[i].loadFromImage(image[i], IntRect((32 * (int)frame), 0, 32, 32));
			tex_wpn[i].loadFromImage(image[i], IntRect((32 * (int)frame), 32 * 3, 32, 32));
			player[i].setTexture(texture[i]);
			weapon[i].setTexture(tex_wpn[i]);
		}
	}
	else {
		if (frame > 3) {
			frame = 0;
			shoot[i] = false;
		}
		if (dir == 3) {
			texture[i].loadFromImage(image[i], IntRect(32 * (int)frame, 32, 32, 32));
			tex_wpn[i].loadFromImage(image[i], IntRect(32 * (int)frame, 32 * 2, 32, 32));
			player[i].setTexture(texture[i]);
			weapon[i].setTexture(tex_wpn[i]);
		}
		if (dir == 1) {
			texture[i].loadFromImage(image[i], IntRect(32 * (int)frame, 32, 32, 32));
			tex_wpn[i].loadFromImage(image[i], IntRect(32 * (int)frame, 32 * 2, 32, 32));
			player[i].setTexture(texture[i]);
			weapon[i].setTexture(tex_wpn[i]);
		}
		if (dir == 2) {
			texture[i].loadFromImage(image[i], IntRect((32 * (int)frame), 32, 32, 32));
			tex_wpn[i].loadFromImage(image[i], IntRect((32 * (int)frame), 32 * 2, 32, 32));
			player[i].setTexture(texture[i]);
			weapon[i].setTexture(tex_wpn[i]);
		}
		if (dir == 4) {
			texture[i].loadFromImage(image[i], IntRect((32 * (int)frame), 32, 32, 32));
			tex_wpn[i].loadFromImage(image[i], IntRect((32 * (int)frame), 32 * 2, 32, 32));
			player[i].setTexture(texture[i]);
			weapon[i].setTexture(tex_wpn[i]);
		}
	}
}

void Player::collision(int curr, int& direction) {
	if (!lives[curr]) throw 1;
	switch (direction) {
	case 1:
		if (pos_x[curr]==-1) pos_x[curr]++, throw 1;
		for (int i = 0; i < curr; i++)
			if(pos_x[curr]==pos_x[i] && pos_y[curr] == pos_y[i]) pos_x[curr]++, throw 1;
		for (int i = curr+1; i < 6; i++)
			if (pos_x[curr] == pos_x[i] && pos_y[curr] == pos_y[i]) pos_x[curr]++, throw 1;
	case 2:
		if (pos_x[curr]==18) pos_x[curr]--, throw 1;
		for (int i = 0; i < curr; i++)
			if (pos_x[curr] == pos_x[i] && pos_y[curr] == pos_y[i]) pos_x[curr]--, throw 1;
		for (int i = curr + 1; i < 6; i++)
			if (pos_x[curr] == pos_x[i] && pos_y[curr] == pos_y[i]) pos_x[curr]--, throw 1;
	case 3:
		if (pos_y[curr]==-1) pos_y[curr]++, throw 1;
		for (int i = 0; i < curr; i++)
			if (pos_x[curr] == pos_x[i] && pos_y[curr] == pos_y[i]) pos_y[curr]++, throw 1;
		for (int i = curr + 1; i < 6; i++)
			if (pos_x[curr] == pos_x[i] && pos_y[curr] == pos_y[i]) pos_y[curr]++, throw 1;
	case 4:
		if (pos_y[curr]==18) pos_y[curr]--, throw 1;
		for (int i = 0; i < curr; i++)
			if (pos_x[curr] == pos_x[i] && pos_y[curr] == pos_y[i]) pos_y[curr]--, throw 1;
		for (int i = curr + 1; i < 6; i++)
			if (pos_x[curr] == pos_x[i] && pos_y[curr] == pos_y[i]) pos_y[curr]--, throw 1;
	}
}