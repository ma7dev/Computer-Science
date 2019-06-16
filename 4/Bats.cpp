/******************************************************
** Program: Bats.cpp
** Author: Mazen Alotaibi
** Date: 05/23/2016
** Description: to setup Bats
******************************************************/ 
#include "Bats.h"
/*********************************************************************
** Function: Bats
** Description: Constructor, setting defult values
** Parameters: NONE
*********************************************************************/
Bats::Bats()
{
	WhoAmI = "Bats";
	Message = "You hear wings flapping.";
}
/*********************************************************************
** Function: ~Bats
** Description: Destructor
** Parameters: NONE
*********************************************************************/
Bats::~Bats(){}
/*********************************************************************
** Function: void Action
** Description: Display message (when player is inside the room)
** Parameters: NONE
*********************************************************************/
void Bats::Action(){
	cout << "----------Super powerful bats took you to another room!" << endl;
}