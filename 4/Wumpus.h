/******************************************************
** Program: Game.h
** Author: Mazen Alotaibi
** Date: 05/23/2016
** Description: 
******************************************************/  
#ifndef WUMPUS_H
#define WUMPUS_H

#include "Events.h"

class Wumpus : public Events{
public:
	Wumpus();
	~Wumpus();
	void Action();
	Wumpus &operator=(const Wumpus &);
};

#endif