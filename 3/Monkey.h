/******************************************************
** Program: Monkey.h
** Author: Mazen Alotaibi
** Date: 05/08/2016
** Description: This is the monkey class which is an animal
******************************************************/
#ifndef MONKEY_H
#define MONKEY_H

#include "Animal.h"

class Monkey : public Animal
{
public:
	Monkey();
	~Monkey();
	Monkey &operator=(const Monkey &);
};

#endif