#ifndef dealer_H
#define dealer_H

#include "hand.h"

class dealer
{
private:
	hand d_hand;
	int card_total;
public:
	dealer();
	dealer(dealer &);
	~dealer();

	hand &get_d_hand();

	int get_card_total();

	void set_d_hand(card);
	void set_card_total(int);
	void cal_card_total();
};

#endif

