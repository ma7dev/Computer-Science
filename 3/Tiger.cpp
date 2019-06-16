/******************************************************
** Program: Tiger.cpp
** Author: Mazen Alotaibi
** Date: 05/08/2016
** Description: This is the tiger class which is an animal
******************************************************/ 
#include "Tiger.h"
/*********************************************************************
** Function: constructor
** Description: set defult values
** Parameters: None
*********************************************************************/
Tiger::Tiger()
{
	buy = 10000;
	feed = 50;
	heal = 1000;
	profit = 1000;
	bonus = 0;
	age = 3;
	lifespan = 26;
	babies = 1;
	alive = true;
	name = "Adult";
}
/*********************************************************************
** Function: destructor
** Description: nothing
** Parameters: None
*********************************************************************/
Tiger::~Tiger(){}
/*********************************************************************
** Function: operator
** Description: change the functionality of '='
** Parameters: Tiger &
*********************************************************************/
Tiger &Tiger::operator=(const Tiger &A){
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


