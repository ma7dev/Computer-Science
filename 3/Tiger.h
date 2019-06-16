/******************************************************
** Program: Tiger.h
** Author: Mazen Alotaibi
** Date: 05/08/2016
** Description: This is the tiger class which is an animal
******************************************************/ 
#ifndef TIGER_H
#define TIGER_H

#include "Animal.h"

class Tiger : public Animal
{
public:
	Tiger();
	~Tiger();
	Tiger &operator=(const Tiger &);
};

#endif