/* Merav Boim 206489155 */

#include "Player.h"

Player::Player() {
	num_of_cards = 0;
}

Player::Player(string n, int card) {
	name = n;
	num_of_cards = card;
	vector <Card> temp(num_of_cards);
	cards = temp;
	for (int i = 0; i < num_of_cards; i++) {
		cards[i] = (Card::generate_card());
	}
}

Player::Player(const Player &p){
	name = p.name;
	num_of_cards = p.num_of_cards;
	cards.clear();
	for (int i = 0; i < num_of_cards; i++) {
		cards.push_back(p.cards[i]);
	}
}

Player& Player::operator=(const Player& player) {
	 name= player.name; 
	 num_of_cards = player.num_of_cards; 
	 vector<Card> temp(num_of_cards);
	 cards = temp;
	 for (int i = 0; i < num_of_cards; ++i) {
		 cards[i] = player.cards[i];
	 }
	 return *this;
	}
	
	string Player::get_name() const { return name; }
	int Player::get_num_of_cards() const { return num_of_cards; }
	vector<Card> Player::get_cards() const { return cards; }


void Player::print_turn() const {//print turn
	for (size_t i = 0; i < cards.size(); i++) {
		cout << "(" << i + 1 << ")" << cards[i] << " ";
	}
	cout << endl;
}

bool Player::play(Card& card){
	cout << "current: " << card << endl;
	cout << get_name() << ", your turn - " << endl;
	cout << "Your cards: ";
	print_turn();
	int selected_card;
	cin >> selected_card;
	if (selected_card > 0 && selected_card <= num_of_cards) {
		while(!card.is_legal(cards[selected_card - 1])) {
			cout << "You can't put " << cards[selected_card - 1]<< " on " << card << endl;
			cin >> selected_card;
			if (selected_card <= 0 || selected_card > num_of_cards) {
				Card temp = Card::generate_card();
				this->cards.push_back(temp);
				this->num_of_cards++;
				return false;
			}
		}
		if (selected_card > 0 && selected_card <= num_of_cards) {
			card = cards[selected_card - 1];
			this->cards.erase(cards.begin()+selected_card - 1);
			this->num_of_cards--;
		}
		return true;
	}
	else {
		Card temp = Card::generate_card();
		cards.push_back(temp);
		num_of_cards++;
		return false;
	}
}
