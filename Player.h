/* Merav Boim 206489155 */
#pragma once
#ifndef PLAYER_H
#define PLAYER_H
#include "Card.h"
#include <vector>
using namespace std;

class Player {
private:
	string name;
	int num_of_cards;
	vector <Card> cards;

public:
	Player(string ,int);
	Player(const Player&);
	Player();
	void print_turn()const;
	Player& operator=(const Player&);
	string get_name() const;
	int get_num_of_cards() const;
	vector<Card> get_cards() const;
	bool play(Card&);


};
#endif




