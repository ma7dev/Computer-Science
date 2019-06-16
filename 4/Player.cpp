/******************************************************
** Program: Player.cpp
** Author: Mazen Alotaibi
** Date: 05/23/2016
** Description: to setup player
******************************************************/ 
#include "Player.h"
/*********************************************************************
** Function: Player
** Description: Constructor, setting defult values
** Parameters: NONE
*********************************************************************/
Player::Player(){
	num_arrows = 3;
	has_gold = false;
	is_alive = true;
	wumpus_killed = false;
	player_escaped = false;
}
/*********************************************************************
** Function: ~Player
** Description: Destructor
** Parameters: NONE
*********************************************************************/
Player::~Player(){}
/*********************************************************************
** Function: void set_num_arrows
** Description: it set the number of arrows when the user asked to enter it
** Parameters: int n, number of arrows, which is usually a user input
*********************************************************************/
void Player::set_num_arrows(int n){
	num_arrows = n;
}
/*********************************************************************
** Function: void lossing_arrows
** Description: when player shoots one arrow will be discarded
** Parameters: NONE
*********************************************************************/
void Player::lossing_arrows(){
	num_arrows--;
}
/*********************************************************************
** Function: void get_num_arrows
** Description: to return num_arrows
** Parameters: NONE
*********************************************************************/
int Player::get_num_arrows(){
	return num_arrows;
}
/*********************************************************************
** Function: void set_has_gold
** Description: to setup if the user has gold or not
** Parameters: bool s
*********************************************************************/
void Player::set_has_gold(bool s){
	has_gold = s;
}
/*********************************************************************
** Function: void set_is_alive
** Description: to setup if the user is alive or not
** Parameters: bool s
*********************************************************************/
void Player::set_is_alive(bool s){
	is_alive = s;
}
/*********************************************************************
** Function: bool get_has_gold
** Description: return if the user has gold or not
** Parameters: NONE
*********************************************************************/
bool Player::get_has_gold(){
	return has_gold;
}
/*********************************************************************
** Function: bool geT_is_alive
** Description: return of the user is alive or not
** Parameters: NONE
*********************************************************************/
bool Player::get_is_alive(){
	return is_alive;
}
/*********************************************************************
** Function: void set_wumpus_killed
** Description: to setup if the user killed the wumpus or not
** Parameters: bool s
*********************************************************************/
void Player::set_wumpus_killed(bool s){
	wumpus_killed = s;
}
/*********************************************************************
** Function: bool get_wumpus_killed
** Description: to setup if the user killed the wumpus or not
** Parameters: NONE
*********************************************************************/
bool Player::get_wumpus_killed(){
	return wumpus_killed;
}
/*********************************************************************
** Function: void set_player_escaped
** Description: to setup if the user escaped the maze or not
** Parameters: bool s
*********************************************************************/
void Player::set_player_escaped(bool s){
	player_escaped = s;
}
/*********************************************************************
** Function: bool get_player_escaped
** Description: to setup if the user escaped the maze or not
** Parameters: NONE
*********************************************************************/
bool Player::get_player_escaped(){
	return player_escaped;
}
/*********************************************************************
** Function: Player & operator system overload
** Description: changing the functionality of a tool, which is "=", when equaling a Player with another
** Parameters: Player &P, to change the implicit of the Event
*********************************************************************/
Player &Player::operator=(const Player &P){
	num_arrows = P.num_arrows;
	has_gold = P.has_gold;
	is_alive = P.is_alive;
	return *this;
}