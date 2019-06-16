/******************************************************
** Program: Gold.cpp
** Author: Mazen Alotaibi
** Date: 05/23/2016
** Description: to setup Gold
******************************************************/ 
#include "Gold.h"
/*********************************************************************
** Function: Gold
** Description: Constructor, setting defult values
** Parameters: NONE
*********************************************************************/
Gold::Gold(){
	WhoAmI = "Gold";
	Message = "You see a glimmer nearby.";
}
/*********************************************************************
** Function: ~Gold
** Description: Destructor
** Parameters: NONE
*********************************************************************/
Gold::~Gold(){}
/*********************************************************************
** Function: void Action
** Description: Display message (when player is inside the room)
** Parameters: NONE
*********************************************************************/
void Gold::Action(){
	cout << "----------You have the gold" << endl;
}