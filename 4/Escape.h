/******************************************************
** Program: Game.h
** Author: Mazen Alotaibi
** Date: 05/23/2016
** Description: 
******************************************************/ 
#ifndef ESCAPE_H
#define ESCAPE_H

#include "Events.h"

class Escape : public Events
{
public:
	Escape();
	~Escape();
	void Action();
	Escape &operator=(const Escape &);
};

#endif