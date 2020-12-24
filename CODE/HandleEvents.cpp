#include "HandleEvents.h"


void HandleEvents::events() {
	
	clock.getElapsedTime().asSeconds();	
	
	
	
	while (window.isOpen()) {
		Event event;
		Vector2i pos = Mouse::getPosition(window);
		x = (pos.x-map_central_x)/32-1;
		y = (pos.y-map_central_y)/32-1;
		float time;
		time = clock.getElapsedTime().asMicroseconds()/800;
		clock.restart();
		
		if (!steps[0] && !steps[1] && !steps[2] && round && trigger) {
			round = false;
			if (lives[3]) steps[3] = 10, shoot[3] = true;
			if (lives[4]) steps[4] = 10, shoot[4] = true;
			if (lives[5]) steps[5] = 10, shoot[5] = true;
			game = false;
			current = 3;
		}
		if (!steps[3] && !steps[4] && !steps[5] && !round && trigger) {
			round = true;
			if (lives[0]) steps[0] = 10, shoot[0] = true;
			if (lives[1]) steps[1] = 10, shoot[1] = true;
			if (lives[2]) steps[2] = 10, shoot[2] = true;
			game = false;
			current = 1;
		}
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed) {
				window.close();
			}
			if (!victory && Keyboard::isKeyPressed(Keyboard::Escape)) {
				victory = true;
				menu = true;
				music.stop();
			}
			if (menu) {
				if (music.getStatus() != sf::Music::Status::Playing) {
					music.openFromFile("Resources/mus/menu.wav");
					music.play();
				}
				if (event.type == Event::MouseButtonPressed) {
					if (event.key.code == Mouse::Left) {
						if (pos.x > 22 && pos.y > 304 && pos.x < 476 && pos.y < 383 && k) {
							music.stop();
							menu = false;
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
						if (pos.x > 22 && pos.y > 419 && pos.x < 341 && pos.y < 498 && k) {
							k = false;
						}
						if (pos.x > 22 && pos.y > 608 && pos.x < 268 && pos.y < 687 && k) {
							window.close();
						}
					}
				}
				if (Keyboard::isKeyPressed(Keyboard::Escape) && !k) {
					k = true;
				}
			}
			if (!menu) {
				if (music.getStatus() != sf::Music::Status::Playing) {
					music.openFromFile("Resources/mus/b1.wav");
					music.play();
				}
				//choose
				if (Keyboard::isKeyPressed(Keyboard::Escape)) {
					menu = true;
				}
				if (Keyboard::isKeyPressed(Keyboard::Enter) && !game) {
					game = true;
				}
				if ((Keyboard::isKeyPressed(Keyboard::Num1) || Keyboard::isKeyPressed(Keyboard::Numpad1)) && mov && game && trigger) {
					if (round) current = 0;
					else current = 3;

				}
				if ((Keyboard::isKeyPressed(Keyboard::Num2) || Keyboard::isKeyPressed(Keyboard::Numpad2)) && mov && game && trigger) {
					if (round) current = 1;
					else current = 4;
				}
				if ((Keyboard::isKeyPressed(Keyboard::Num3) || Keyboard::isKeyPressed(Keyboard::Numpad3)) && mov && game && trigger) {
					if (round) current = 2;
					else current = 5;
				}
				//movement
				if (steps[current] && lives[current] && game && mov) {
					if (Keyboard::isKeyPressed(Keyboard::Left)) {
						dir = 1;
						pos1 = player[current].getPosition();
						mov = false;
						pos_x[current]--;
					}
					if (Keyboard::isKeyPressed(Keyboard::Right)) {
						dir = 2;
						pos1 = player[current].getPosition();
						mov = false;
						pos_x[current]++;
					}
					if (Keyboard::isKeyPressed(Keyboard::Up)) {
						dir = 3;
						pos1 = player[current].getPosition();
						mov = false;
						pos_y[current]--;
					}
					if (Keyboard::isKeyPressed(Keyboard::Down)) {
						dir = 4;
						pos1 = player[current].getPosition();
						mov = false;
						pos_y[current]++;
					}
				}
				//mouse
				if (game && mov) {
					if (event.type == Event::MouseButtonPressed) {
						if (event.key.code == Mouse::Left) {
							for (int i = 0; i < 6; i++) {
								if (x == pos_x[i] && y == pos_y[i]) {
									if (round && i > 2 && lives[i] > 0) {
										trigger = false;
										aim.setPosition(Vector2f(x * 32 + map_central_x - 50, y * 32 + map_central_y - 50 - 16));
										point = i;
										break;
									}
									if (round && i < 3 && lives[i]>0) {
										trigger = true;
										current = i;
										break;
									}
									if (!round && i < 3 && lives[i]>0) {
										trigger = false;
										aim.setPosition(Vector2f(x * 32 + map_central_x - 50, y * 32 + map_central_y - 50 - 16));
										point = i;
										break;
									}
									if (!round && i > 2 && lives[i]>0) {
										trigger = true;
										current = i;
										break;
									}
								}
								else trigger = true;
							}
						}
					}
				}
				//shooting
				if (Keyboard::isKeyPressed(Keyboard::Space) && !trigger && steps[current]) {
					dir = 0;
					enabled = 1;
					if (pos_x[current] < pos_x[point] && pos_y[current] == pos_y[point]) {
						dir = 1;
						if (pos_x[current] + 1 == pos_x[point]) enabled = 2;
					}
					if (pos_x[current] > pos_x[point] && pos_y[current] == pos_y[point]) {
						dir = 2;
						if (pos_x[current] - 1 == pos_x[point]) enabled = 2;
					}
					if (pos_x[current] == pos_x[point] && pos_y[current] < pos_y[point]) {
						dir = 3;
						if (pos_x[current] + 1 == pos_x[point]) enabled = 2;
					}
					if (pos_x[current] == pos_x[point] && pos_y[current] > pos_y[point]) {
						dir = 4;
						if (pos_x[current] - 1 == pos_x[point]) enabled = 2;
					}
					if (dir == 0) enabled = 0, trigger = true;
				}
			}
		}
		window.clear();
		if (!menu) {
			building_field();
			if (game) {
				std::cout << time << std::endl;
				try {
					collision(current, dir);
				}
				catch (int a) {
					mov = true;
				}
				if (!mov) {
					moving(current, dir, time);
					animation(current, dir, time, enabled);
					if (pos1.x + 31 < player[current].getPosition().x || pos1.x - 31 > player[current].getPosition().x || pos1.y + 31 < player[current].getPosition().y || pos1.y - 31 > player[current].getPosition().y) steps[current]--, mov = true;
				}
			}
			if (round) {
				for (int i = 0; i < 3; i++)
				{
					if (lives[i] > 0) {
						b1.setPosition(Vector2f(((float)(pos_x[i] + 1) * 32 + map_central_x), ((float)(pos_y[i] + 1) * 32 + map_central_y)));
						window.draw(b1);
					}
				}
				for (int i = 3; i < 6; i++)
				{
					if (lives[i] > 0) {
						b2.setPosition(Vector2f(((float)(pos_x[i] + 1) * 32 + map_central_x), ((float)(pos_y[i] + 1) * 32 + map_central_y)));
						window.draw(b2);
					}
				}
			}
			else {
				for (int i = 0; i < 3; i++)
				{
					if (lives[i] > 0) {
						b2.setPosition(Vector2f(((float)(pos_x[i] + 1) * 32 + map_central_x), ((float)(pos_y[i] + 1) * 32 + map_central_y)));
						window.draw(b2);
					}
				}
				for (int i = 3; i < 6; i++)
				{
					if (lives[i] > 0) {
						b1.setPosition(Vector2f(((float)(pos_x[i] + 1) * 32 + map_central_x), ((float)(pos_y[i] + 1) * 32 + map_central_y)));
						window.draw(b1);
					}
				}
			}
			drawing();
			if (game && (!trigger)) {
				if (!trigger) window.draw(aim);
				if (enabled) {
					animation(current, dir, time, enabled);
					if (!shoot[current]) {
						enabled = 0;
						trigger = true;
						steps[current] = 0;
						lives[point]--;
					}
				}
			}
			if (!game && round) setText("Player 1", 40), window.draw(texting);
			if (!game && !round) setText("Player 2", 40), window.draw(texting);
		}
		
		if (menu) {
			if (k) window.draw(menu0);
			if (!k) window.draw(menu1);
		}
		if (lives[0]<=0 && lives[1]<=0 && lives[2]<=0 && !menu) {
			if (victory) music.stop();
			victory = false;
			window.draw(menu2);
			if (music.getStatus() != sf::Music::Status::Playing) {
				music.openFromFile("Resources/mus/victory.wav");
				music.play();
			}
			Text winner;
			winner.setFont(font);
			winner.setCharacterSize(60);
			winner.setString("PLAYER 2 WINS");
			winner.setPosition(Vector2f(160, 280));
			window.draw(winner);
		}
		if (lives[3]<=0 && lives[4]<=0 && lives[5]<=0 && !menu) {
			if(victory) music.stop();
			victory = false;
			window.draw(menu2);
			if (music.getStatus() != sf::Music::Status::Playing) {
				music.openFromFile("Resources/mus/victory.wav");
				music.play();
			}
			Text winner;
			winner.setFont(font);
			winner.setCharacterSize(60);
			winner.setString("PLAYER 1 WINS");
			winner.setPosition(Vector2f(160, 280));
			window.draw(winner);
		}
		window.display();
	}
}

void HandleEvents::setText(String str, int size) {
	texting.setFont(font);
	texting.setCharacterSize(size);
	texting.setString(str);
	texting.setPosition(Vector2f(win_weight / 2 - str.getSize()*size/3, win_height / 2 - size / 2));
}