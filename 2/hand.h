#ifndef HAND_H
#define HAND_H

#include "card.h"

class hand
{
private:
	card *cards;
	int num_cards;
public:
	hand();
	~hand();
	
	card* get_cards_pointer();
	card get_cards(int);

	int get_num_cards();
	int cal(bool);

	void set_cards(int, card);
	void set_num_cards(int);
	void add_card(card);
	void print_cards(bool);
	
	hand &operator=(hand &);
};

#endif