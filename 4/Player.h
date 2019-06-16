/******************************************************
** Program: Game.h
** Author: Mazen Alotaibi
** Date: 05/23/2016
** Description: 
******************************************************/ 
#ifndef PLAYER_H
#define PLAYER_H

class Player
{
protected:
	int num_arrows;
	bool has_gold;
	bool is_alive;
	bool wumpus_killed;
	bool player_escaped;
public:
	Player();
	~Player();

	void set_num_arrows(int n);
	void lossing_arrows();
	int get_num_arrows();

	void set_has_gold(bool s);
	bool get_has_gold();

	void set_is_alive(bool s);
	bool get_is_alive();

	void set_wumpus_killed(bool s);
	bool get_wumpus_killed();

	void set_player_escaped(bool s);
	bool get_player_escaped();

	Player &operator=(const Player &);
};

#endif