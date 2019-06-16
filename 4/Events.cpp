/******************************************************
** Program: Events.cpp
** Author: Mazen Alotaibi
** Date: 05/23/2016
** Description: where setting Events
******************************************************/ 
#include "Events.h"
/*********************************************************************
** Function: Events
** Description: Constructors, setting defult values
** Parameters: NONE
*********************************************************************/
Events::Events(){
	WhoAmI = "Nothing";
	Message = "";

}
/*********************************************************************
** Function: ~Events
** Description: Destructor
** Parameters: NONE
*********************************************************************/
Events::~Events(){}
/*********************************************************************
** Function: void set_Message
** Description: to setup the message
** Parameters: string m, which is the input
*********************************************************************/
void Events::set_Message(string m){
	Message = m;
}
/*********************************************************************
** Function: void Action
** Description: NONE
** Parameters: NONE
*********************************************************************/
void Events::Action(){}
/*********************************************************************
** Function: string get_Message
** Description: return Message
** Parameters: NONE
*********************************************************************/
string Events::get_Message(){
	return Message;
}
/*********************************************************************
** Function: void set_WhoAmI
** Description: to setup WhoAmI
** Parameters: string w
*********************************************************************/
void Events::set_WhoAmI(string w){
	WhoAmI = w;
}
/*********************************************************************
** Function: string get_WhoAmI
** Description: to return WhoAmI
** Parameters: NONE
*********************************************************************/
string Events::get_WhoAmI(){
	return WhoAmI;
}
/*********************************************************************
** Function: Events & operator system overload
** Description: changing the functionality of a tool, which is "=", when equaling an Event with another
** Parameters: Events &s, to change the implicit of the Event
*********************************************************************/
Events &Events::operator=(const Events &s){
	Message = s.Message;
	return *this;
}