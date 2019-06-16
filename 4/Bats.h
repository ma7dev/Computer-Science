/******************************************************
** Program: Game.h
** Author: Mazen Alotaibi
** Date: 05/23/2016
** Description: 
******************************************************/ 
#ifndef BATS_H
#define BATS_H

#include "Events.h"

class Bats : public Events
{
public:
	Bats();
	~Bats();
	void Action();
	Bats &operator=(const Bats &);
};

#endif