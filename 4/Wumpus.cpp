/******************************************************
** Program: Wumpus.cpp
** Author: Mazen Alotaibi
** Date: 05/23/2016
** Description: to setup Wumpus
******************************************************/ 
#include "Wumpus.h"
/*********************************************************************
** Function: Wumpus
** Description: Constructor, setting defult values
** Parameters: NONE
*********************************************************************/
Wumpus::Wumpus(){
	WhoAmI = "Wumpus";
	Message = "You smell a terrible stench.";
}
/*********************************************************************
** Function: ~Wumpus
** Description: Destructor
** Parameters: NONE
*********************************************************************/
Wumpus::~Wumpus(){}
/*********************************************************************
** Function: void Action
** Description: Display message (when player is inside the room)
** Parameters: NONE
*********************************************************************/
void Wumpus::Action(){
	cout << "----------You have been eaten by the monster" << endl;
}