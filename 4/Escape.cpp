/******************************************************
** Program: Escape.cpp
** Author: Mazen Alotaibi
** Date: 05/23/2016
** Description: to setup Escape
******************************************************/ 
#include "Escape.h"
/*********************************************************************
** Function: Escape
** Description: Constructor, setting defult values
** Parameters: NONE
*********************************************************************/
Escape::Escape(){
	WhoAmI = "Escape";
	Message = "The Escape is near you";
}
/*********************************************************************
** Function: ~Escape
** Description: Destructor
** Parameters: NONE
*********************************************************************/
Escape::~Escape(){}
/*********************************************************************
** Function: void Action
** Description: Display message (when player is inside the room)
** Parameters: NONE
*********************************************************************/
void Escape::Action(){
	cout << "----------You have Easpaced the Maze" << endl;
}