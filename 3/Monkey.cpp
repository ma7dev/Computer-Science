/******************************************************
** Program: Monkey.cpp
** Author: Mazen Alotaibi
** Date: 05/08/2016
** Description: This is the monkey class which is an animal
******************************************************/ 
#include "Monkey.h"
/*********************************************************************
** Function: constructor
** Description: set defult values
** Parameters: None
*********************************************************************/
Monkey::Monkey()
{
	buy = 2500;
	feed = 25;
	heal = 250;
	profit = 250;
	bonus = 0;
	age = 3;
	lifespan = 25;
	babies = 5;
	alive = true;
	name = "Adult";
}
/*********************************************************************
** Function: destructor
** Description: nothing
** Parameters: None
*********************************************************************/
Monkey::~Monkey(){}
/*********************************************************************
** Function: operator
** Description: change the functionality of "="
** Parameters: MOnkey &
*********************************************************************/
Monkey &Monkey::operator=(const Monkey &A){
	buy = A.buy;
	feed = A.feed;
	heal = A.heal;
	bonus = A.bonus;
	profit = A.profit;
	age = A.age;
	lifespan = A.lifespan;
	babies = A.babies;
	alive = A.alive;
	name = A.name;
	return *this;
}