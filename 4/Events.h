/******************************************************
** Program: Game.h
** Author: Mazen Alotaibi
** Date: 05/23/2016
** Description: 
******************************************************/ 
#ifndef EVENTS_H
#define EVENTS_H


#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <cctype>
#include <ctime>
#include <cstdio>

#include "Player.h"

using namespace std;

class Events
{
protected:
	string WhoAmI;
	string Message;
	Player P;
public:
	Events();
	~Events();
	void set_Message(string m);
	virtual void Action();
	string get_Message();
	void set_WhoAmI(string w);
	string get_WhoAmI();

	Events &operator=(const Events &);
};

#endif