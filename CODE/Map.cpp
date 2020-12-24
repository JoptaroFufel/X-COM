#include <iostream>
#include <SFML/Graphics.hpp>
#include <string.h>
#include "Map.h"
#include "Game.h"

using namespace sf;

void Map :: building_field() {
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			switch (field[i][j]) {
			case'0':
				a0.setPosition(Vector2f(((float)j * 32 + map_central_x), ((float)i * 32 + map_central_y)));
				window.draw(a0);
				break;
			case'1':
				a1.setPosition(Vector2f(((float)j * 32 + map_central_x), ((float)i * 32 + map_central_y)));
				window.draw(a1);
				break;
			case'2':
				a2.setPosition(Vector2f(((float)j * 32 + map_central_x), ((float)i * 32 + map_central_y)));
				window.draw(a2);
				break;
			}
		}
	}
}