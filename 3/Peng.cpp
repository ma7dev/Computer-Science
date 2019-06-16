/******************************************************
** Program: Peng.cpp
** Author: Mazen Alotaibi
** Date: 05/08/2016
** Description: This is the peng class which is an animal
******************************************************/ 
#include "Peng.h"
/*********************************************************************
** Function: constructor
** Description: set defult values
** Parameters: None
*********************************************************************/ 
Peng::Peng()
{
	buy = 1000;
	feed = 10;
	heal = 200;
	profit = 50;
	bonus = 0;
	age = 3;
	lifespan = 18;
	babies = 3;
	alive = true;
	name = "Adult";
}
/*********************************************************************
** Function: destructor
** Description: nothing
** Parameters: None
*********************************************************************/ 
Peng::~Peng(){}
/*********************************************************************
** Function: operator
** Description: change the functionality of "="
** Parameters: Peng &
*********************************************************************/ 
Peng &Peng::operator=(const Peng &A){
	buy = A.buy;
	feed = A.feed;
	heal = A.heal;
	profit = A.profit;
	bonus = A.bonus;
	age = A.age;
	lifespan = A.lifespan;
	babies = A.babies;
	alive = A.alive;
	name = A.name;
	return *this;
}