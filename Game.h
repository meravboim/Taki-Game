/* Merav Boim 206489155 */
#pragma once
#ifndef GAME_H
#define GAME_H
#include "Player.h"
#include "Card.h"
#include <list>
using namespace std;

class Game {
private:
	Card current_card;
	string direction;
	list <Player*> list_of_players;

	Game& operator=(const Game&);
	Game(const Game&);

	void if_positive(int &);
	void next_turn(std::list<Player*>::iterator &);
	void change_direction();
	
public:
	Game();
	~Game();
	void start();
	
};
#endif





