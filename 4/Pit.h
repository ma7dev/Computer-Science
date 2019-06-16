/******************************************************
** Program: Game.h
** Author: Mazen Alotaibi
** Date: 05/23/2016
** Description: 
******************************************************/ 
#ifndef PIT_H
#define PIT_H

#include "Events.h"

class Pit : public Events
{
public:
	Pit();
	~Pit();
	void Action();
	Pit &operator=(const Pit &);
};

#endif