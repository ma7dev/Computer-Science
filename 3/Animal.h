/******************************************************
** Program: Animal.h
** Author: Mazen Alotaibi
** Date: 05/08/2016
** Description: This is the animal class that has all the details to be an animal
******************************************************/ 
#ifndef ANIMAL_H
#define ANIMAL_H


#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <cctype>
#include <ctime>
#include <cstdio>

using namespace std;

class Animal
{
protected:
	int buy;
	int feed;
	int bonus;
	int heal;
	int profit;
	int age;
	int lifespan;
	int babies;
	bool alive;
	string name;

public:
	Animal();
	~Animal();
	
	void set_buy(int n);
	void set_feed(int n);
	void set_heal(int n);
	void set_profit(int n);
	void set_age(int n);
	void set_lifespan(int n);
	void set_babies(int n);
	void set_alive(bool t);
	void set_name(string n);

	int get_buy();
	int get_feed();
	int get_heal();
	int get_profit();
	int get_age();
	int get_lifespan();
	int get_babies();
	bool get_alive();
	string get_name();

	Animal &operator=(const Animal &);
};

#endif