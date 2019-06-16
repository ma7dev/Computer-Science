/******************************************************
** Program: Game.h
** Author: Mazen Alotaibi
** Date: 05/08/2016
** Description: This is the game class which has all the zoo and the functionality of using them
******************************************************/ 
#ifndef GAME_H
#define GAME_H

#include "Zoo.h"

class Game
{
private:
	Zoo z;
	int money;
	int day;
	int feeding_kind;
public:
	Game();
	~Game();
	void set_money(int n);
	int get_money();
	void set_feeding_kind(int n);
	int get_feeding_kind();
	void set_losses(int n);
	void random_event(int n);
	void random_die();
	void set_day_add();
	int get_day();
	bool is_pos_int(string str);
	bool is_in_range(string str, int x);
	void start_game();	
};
#endif