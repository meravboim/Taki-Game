/* Merav Boim 206489155 */
#include <iterator> // for iterators 
#include "Game.h"


Game::Game()
{
	direction = "right";
}


Game::~Game()
{
	list_of_players.clear();
	int l = list_of_players.size();
	for (int i = 0; i < l; i++) {
		delete[] list_of_players.back();
	}

}

void Game:: if_positive(int &num){//check if numer is positive
	while (num < 0) {
		cout << "you enter a naegative number,by by!" << endl;
		exit(0);
	}
}

void Game::next_turn(std::list<Player*>::iterator &it) {
	std::list<Player*>::iterator temp = list_of_players.end();
	temp--;
	if (direction == "right") {
		if (it ==temp) {
			it = list_of_players.begin();
		}
		else {;
			++it;
		}
	}
	else {
		if (it == list_of_players.begin()) {
			it = temp;
			
		}
		else
			--it;
	}
}

void Game::change_direction() {
	if (direction == "right")
		direction = "left";
	else
		direction = "right";
}

void Game::start() {
	int num_of_players, num_of_cards;
	cout << "How many players?" << endl; //get number of players
	cin >> num_of_players;
	if_positive(num_of_players);
	cout << "How many cards?" << endl; //get number of cards
	cin >> num_of_cards;
	if_positive(num_of_cards);
	for (int i = 0; i < num_of_players;i++) {//get the names of the players
		cout << "player number " << (i + 1) << " name?" << endl;
		string name;
		cin >> name;
		list_of_players.push_back(new Player(name, num_of_cards));
	}
	current_card = Card::generate_card();//random start card
	
	std::list<Player*>::iterator it= list_of_players.begin();
	bool end_game = false;//flag is true if someone won
	while (!end_game) {
		bool move= (*it)->play(current_card);
		if ((*it)->get_num_of_cards() == 0) {
			cout << (*it)->get_name() << " wins!" << endl;
			end_game = true;
		}
		if (move == true) {
			if (current_card.get_sign() == sign::STOP) {
				next_turn(it);
				next_turn(it);
			}
			else if (current_card.get_sign() == sign::CD) {
				change_direction();
				next_turn(it);
			}
			else if (current_card.get_sign() == sign::PLUS) {
				//do nothing
			}
			else 
				next_turn(it);

		}
		else 
			next_turn(it);
	
		
	}
}

