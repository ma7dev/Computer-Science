/******************************************************
** Program: Peng.h
** Author: Mazen Alotaibi
** Date: 05/08/2016
** Description: This is the peng class which is an animal
******************************************************/ 
#ifndef PENG_H
#define PENG_H

#include "Animal.h"

class Peng : public Animal
{
public:
	Peng();
	~Peng();
	Peng &operator=(const Peng &);
};

#endif