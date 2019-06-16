/******************************************************
** Program: Pit.cpp
** Author: Mazen Alotaibi
** Date: 05/23/2016
** Description: to setup Pit
******************************************************/ 
#include "Pit.h"
/*********************************************************************
** Function: Pit
** Description: Constructor, setting defult values
** Parameters: NONE
*********************************************************************/
Pit::Pit()
{
	WhoAmI = "Pit";
	Message = "You feel a breeze.         ";
}
/*********************************************************************
** Function: ~Pit
** Description: Destructor
** Parameters: NONE
*********************************************************************/
Pit::~Pit(){}
/*********************************************************************
** Function: void Action
** Description: Display message (when player is inside the room)
** Parameters: NONE
*********************************************************************/
void Pit::Action(){
	cout << "----------You have been Killed by falling in a Pit" << endl;
}