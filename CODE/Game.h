#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <exception>
#include <Windows.h>
using namespace sf;
;
class game{
public:
	RenderWindow window;
	int win_height = 720;
	int win_weight = 1280;
	int map_central_x = win_weight / 2 - 10 * 32;
	int map_central_y = win_height / 2 - 10 * 32;
	Texture tex_menu0;
	Texture tex_menu1;
	Texture tex_menu2;
	Music music;
	Sprite menu0;
	Sprite menu1;
	Sprite menu2;
	Font font;
public:
	game() {
		tex_menu0.loadFromFile("Resources/menu.png");
		tex_menu1.loadFromFile("Resources/tut.png");
		tex_menu2.loadFromFile("Resources/victory.png");
		
		menu0.setTexture(tex_menu0);
		menu1.setTexture(tex_menu1);
		menu2.setTexture(tex_menu2);

		music.setLoop(true);
		music.setVolume(5);

		font.loadFromFile("Resources/font.ttf");
		window.create(VideoMode(win_weight, win_height), "X-COM");
		window.setVerticalSyncEnabled(true);
		window.setFramerateLimit(60);
	}
};