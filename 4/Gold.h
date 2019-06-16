/******************************************************
** Program: Game.h
** Author: Mazen Alotaibi
** Date: 05/23/2016
** Description: 
******************************************************/ 
#ifndef GOLD_H
#define GOLD_H

#include "Events.h"

class Gold : public Events
{
public:
	Gold();
	~Gold();
	void Action();
	Gold &operator=(const Gold &);
};

#endif