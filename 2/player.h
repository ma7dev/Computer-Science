#ifndef PLAYER_H
#define PLAYER_H

#include "hand.h"

class player
{
private:
	hand p_hand;
	int playing_total;
	int card_total;
	int bet;
public:
	player();
	player(player &);
	~player();

	hand &get_p_hand();

	int get_playing_total();
	int get_card_total();
	int get_bet();

	void set_p_hand(card);
	void set_playing_total(int);
	void set_card_total(int);
	void set_bet(int);
	void cal_card_total(bool);

	player &operator=(player &);
};

#endif

