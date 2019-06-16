/******************************************************
** Program: Game.h
** Author: Mazen Alotaibi
** Date: 05/23/2016
** Description: 
******************************************************/ 
#ifndef ROOM_H
#define ROOM_H

#include "Events.h"
#include "Player.h"
class Room
{
private:
	Events *Event;
	bool has_Event;
	string M;
	string W;
	int num_Events_around; 
public:
	Room();
	~Room();
	void set_Event(Events *s);
	void set_has_Event(bool s);
	Events get_Event();
	bool get_has_Event();
	void set_num_Events_around();
	int get_num_Events_around();
	string get_M();
	string get_W();
	void Action();

	Room &operator=(const Room &);
};

#endif