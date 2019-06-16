#ifndef DECK_H
#define DECK_H

#include "card.h"
#include <random>
#include <ctime>
#include <algorithm>

class deck
{
private:
	card cards[52];
	int num_cards;
public:
	deck();
	~deck();

	card get_cards(int);
	card &get_top_card();
	
	int get_num_cards();

	void set_cards(int, card);
	void set_num_cards(int);
	void shuffle();
};

#endif