#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <string.h>
#include "Game.h"
#include <ctime>
using namespace sf;

class Map: public game {
protected:
	Texture tex_map_tiles;
	Texture det;
	Sprite a0, a1, a2, b1, b2;
	char field[20][20];
public:
	Map() {
		srand(time(NULL));
		tex_map_tiles.loadFromFile("Resources/Map_tiles.png");
		det.loadFromFile("Resources/det.png");
		a0.setTexture(tex_map_tiles);
		a0.setTextureRect(IntRect(0, 0, 32, 62));
		a1.setTexture(tex_map_tiles);
		a1.setTextureRect(IntRect(32, 0, 32, 62));
		a2.setTexture(tex_map_tiles);
		a2.setTextureRect(IntRect(64, 0, 32, 62));
		b1.setTexture(det);
		b1.setTextureRect(IntRect(0, 0, 32, 32));
		b2.setTexture(det);
		b2.setTextureRect(IntRect(32, 0, 32, 32));
		for (int i = 1; i < 20 - 1; i++) {
			for (int j = 1; j < 20 - 1; j++) {
				field[i][j] = rand() % 3 + '0';
			}
		}
	}
	void building_field();
};
