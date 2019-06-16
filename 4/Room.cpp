/******************************************************
** Program: Room.cpp
** Author: Mazen Alotaibi
** Date: 05/23/2016
** Description: where setting rooms
******************************************************/ 
#include "Room.h"
/*********************************************************************
** Function: Room
** Description: constructor, to set defult values
** Parameters: NONE
*********************************************************************/
Room::Room(){
	Event = NULL;
	has_Event = false;
	num_Events_around = 0;
}
/*********************************************************************
** Function: ~Room
** Description: destrctor, to delete the Event pointer
** Parameters: NONE
*********************************************************************/
Room::~Room(){
	Event = NULL;
	delete Event;
}
/*********************************************************************
** Function: void set_Event
** Description: to set the event, which is inside the room
** Parameters: Events pointer
*********************************************************************/
void Room::set_Event(Events *s){
	if(Event != NULL)
		Event = NULL;
	Event = s;
	M = Event->get_Message();
	W = Event->get_WhoAmI();
	has_Event = true;
}
/*********************************************************************
** Function: Events get_Event
** Description: to return Events pointer
** Parameters: NONE
*********************************************************************/
Events Room::get_Event(){
	return *Event;
}
/*********************************************************************
** Function: void set_has_Event
** Description: to set if the room has an event inside of it or not
** Parameters: bool s
*********************************************************************/
void Room::set_has_Event(bool s){
	has_Event = s;
}
/*********************************************************************
** Function: void set_num_Events_around
** Description: to add the number of events around the room
** Parameters: NONE
*********************************************************************/
void Room::set_num_Events_around(){
	num_Events_around++;
}
/*********************************************************************
** Function: bool get_has_Event
** Description: to return if the room has an event inside of it or not
** Parameters: NONE
*********************************************************************/
bool Room::get_has_Event(){
	return has_Event;
}
/*********************************************************************
** Function: int get_num_Events_around
** Description: to return the numebr of events around the room
** Parameters: NONE
*********************************************************************/
int Room::get_num_Events_around(){
	return num_Events_around;
}
/*********************************************************************
** Function: string get_M
** Description: to return Message
** Parameters: NONE
*********************************************************************/
string Room::get_M(){
	return M;
}
/*********************************************************************
** Function: string get_W
** Description: to return WhoAmI
** Parameters: NONE
*********************************************************************/
string Room::get_W(){
	return W;
}
/*********************************************************************
** Function: void Action
** Description: to apply Action
** Parameters: NONE
*********************************************************************/
void Room::Action(){
	Event->Action();
}