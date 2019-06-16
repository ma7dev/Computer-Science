/******************************************************
** Program: Animal.cpp
** Author: Mazen Alotaibi
** Date: 05/08/2016
** Description: This is the animal class that has all the details to be an animal
******************************************************/ 
#include "Animal.h"
/*********************************************************************
** Function: constructor
** Description: set defult values
** Parameters: None
*********************************************************************/
Animal::Animal(){
	buy = 0;
	feed = 0;
	heal = 0;
	profit = 0;
	bonus = 0;
	age = 0;
	lifespan = 0;
	babies = 0;
	alive = true;
	name = "Animal";
}
/*********************************************************************
** Function: destructor
** Description: nothing
** Parameters: None
*********************************************************************/
Animal::~Animal(){}

/*********************************************************************
** Function: set buy
** Description: set buy value
** Parameters: int
*********************************************************************/
void Animal::set_buy(int n){
	buy = n;
}
/*********************************************************************
** Function: set feed
** Description: set feed value
** Parameters: int
*********************************************************************/
void Animal::set_feed(int n){
	feed = n;
}
/*********************************************************************
** Function: set heal
** Description: set heal value
** Parameters: int
*********************************************************************/
void Animal::set_heal(int n){
	heal = n;
}
/*********************************************************************
** Function: set profit
** Description: set profit value
** Parameters: int
*********************************************************************/
void Animal::set_profit(int n){
	profit = n;
}
/*********************************************************************
** Function: set age
** Description: set age value
** Parameters: int
*********************************************************************/
void Animal::set_age(int n){
	age = n;
}
/*********************************************************************
** Function: set lifespan
** Description: set lifespan value
** Parameters: int
*********************************************************************/
void Animal::set_lifespan(int n){
	lifespan = n;
}
/*********************************************************************
** Function: set babies
** Description: set babies value
** Parameters: int
*********************************************************************/
void Animal::set_babies(int n){
	babies = n;
}
/*********************************************************************
** Function: set alive
** Description: set alive value
** Parameters: bool
*********************************************************************/
void Animal::set_alive(bool t){
	alive = t;
}
/*********************************************************************
** Function: set name
** Description: set name value
** Parameters: string
*********************************************************************/
void Animal::set_name(string n){
	name = n;
}

/*********************************************************************
** Function: get buy
** Description: return buy
** Parameters: None
*********************************************************************/
int Animal::get_buy(){
	return buy;
}
/*********************************************************************
** Function: get feed
** Description: return feed
** Parameters: None
*********************************************************************/
int Animal::get_feed(){
	return feed;
}
/*********************************************************************
** Function: get heal
** Description: return heal
** Parameters: None
*********************************************************************/
int Animal::get_heal(){
	return heal;
}
/*********************************************************************
** Function: get profit
** Description: return profit
** Parameters: None
*********************************************************************/
int Animal::get_profit(){
	return profit;
}
/*********************************************************************
** Function: get age
** Description: return age
** Parameters: None
*********************************************************************/
int Animal::get_age(){
	return age;
}
/*********************************************************************
** Function: get lifespan
** Description: return lifespan
** Parameters: None
*********************************************************************/
int Animal::get_lifespan(){
	return lifespan;
}
/*********************************************************************
** Function: get babies
** Description: return babies
** Parameters: None
*********************************************************************/
int Animal::get_babies(){
	return babies;
}
/*********************************************************************
** Function: get alive
** Description: return alive
** Parameters: None
*********************************************************************/
bool Animal::get_alive(){
	return alive;
}
/*********************************************************************
** Function: get name
** Description: return name
** Parameters: None
*********************************************************************/
string Animal::get_name(){
	return name;
}
/*********************************************************************
** Function: operator
** Description: change the functionality of "="
** Parameters: Animal &
*********************************************************************/
Animal &Animal::operator=(const Animal &A){
	buy = A.buy;
	feed = A.feed;
	heal = A.heal;
	profit = A.profit;
	age = A.age;
	lifespan = A.lifespan;
	babies = A.babies;
	alive = A.alive;
	name = A.name;
	return *this;
}