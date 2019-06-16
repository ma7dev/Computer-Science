#ifndef GAME_H
#define GAME_H

#include "player.h"
#include "dealer.h"
#include "deck.h"

class game
{
private:
	deck cards;
	player *players;
	dealer dealer_CPU;
	int num_players;
public:
	game(int, int);
	~game();
	deck get_cards();
	player get_player(int);
	dealer get_dealer_CPU();
	int get_num_players();

	void remove_players();

	void set_cards(deck);
	void set_player(int, player);
	void set_dealer_CPU(dealer);
	void set_num_players(int);
	bool is_pos_int(string);
	bool is_in_range(string, int);
	void redo();
	void start_game();
};

#endif
