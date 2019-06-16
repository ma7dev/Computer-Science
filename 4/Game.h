/******************************************************
** Program: Game.h
** Author: Mazen Alotaibi
** Date: 05/23/2016
** Description: 
******************************************************/ 
#include "Events.h"
#include "Gold.h"
#include "Bats.h"
#include "Pit.h"
#include "Escape.h"
#include "Wumpus.h"
#include "Room.h"
#include "Player.h"

class Game{
private:
	Room **R;
	Events **E;
	Player P;
	int rows;
	int cols;
	int r_p;
	int c_p;
	int r_e;
	int c_e;
	int r_w;
	int c_w;
	int num_Events;
	int times;
public:
	Game();
	~Game();
	void set_E();
	void set_R(int rows, int cols);
	void set_P(Player x);
	void move();
	void get_P_info();
	void print_Grid();
	void set_Escape();
	void in_Room();
	bool player_Killed();
	void check_Around();
	void wumpus_awake();
	void print_whole_Grid();
	bool check_if_player_won();
	int AI_Action();
	void player_statues(bool s);
};