/******************************************************
** Program: Bear.cpp
** Author: Mazen Alotaibi
** Date: 05/08/2016
** Description: This is the bear class which is an animal
******************************************************/ 
#include "Bear.h"
/*********************************************************************
** Function: constructor
** Description: set defult values
** Parameters: None
*********************************************************************/
Bear::Bear()
{
	buy = 5000;
	feed = 30;
	heal = 600;
	profit = 250;
	bonus = 0;
	age = 3;
	lifespan = 24;
	babies = 2;
	alive = true;
	name = "Adult";
}
/*********************************************************************
** Function: destructor
** Description: nothing
** Parameters: None
*********************************************************************/
Bear::~Bear(){}
/*********************************************************************
** Function: operator
** Description: change the functionality of "="
** Parameters: Bear &
*********************************************************************/
Bear &Bear::operator=(const Bear &A){
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