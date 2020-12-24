#pragma once
#include "Player.h"

class HandleEvents: public Player {
public:
	bool mov = true;
	Vector2f pos1, pos2;
	Text texting;
	bool round = true;
	bool menu = true;
	int current = 0;
	bool trigger = true;
	int enabled = 0;
	int point = 0;
	bool victory = true;
	bool k = true;
	int x, y;
	Clock clock;
	bool game = 0;
	int dir = 0, dir_last = 0;
	void setText(String, int);
	void events();
};
