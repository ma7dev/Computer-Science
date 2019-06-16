/******************************************************
** Program: Bear.h
** Author: Mazen Alotaibi
** Date: 05/08/2016
** Description: This is the bear class which is an animal
******************************************************/ 
#ifndef BEAR_H
#define BEAR_H

#include "Animal.h"

class Bear : public Animal
{
public:
	Bear();
	~Bear();
	Bear &operator=(const Bear &);
};

#endif