/******************************************************
** Program: Zoo.h
** Author: Mazen Alotaibi
** Date: 05/08/2016
** Description: This is the zoo class which has all the animals and the functionality of using them
******************************************************/ 
#ifndef ZOO_H
#define ZOO_H

#include "Animal.h"
#include "Peng.h"
#include "Monkey.h"
#include "Bear.h"
#include "Tiger.h"

class Zoo
{
private:
	Animal *A[4];
	int T_num;
	int B_num;
	int P_num;
	int M_num;
	int A_num;
	int total_profit;
	int total_feed;
	int bonus;
public:
	Zoo();
	~Zoo();

	void set_T_num(int t); 
	void set_B_num(int b);
	void set_P_num(int p);
	void set_M_num(int m);
	void set_A_num();

	void print_Tigers();
	void print_Bears();
	void print_Pengs();
	void print_Monkeys();

	void set_T_die(int n);
	void set_B_die(int n);
	void set_P_die(int n);
	void set_M_die(int n);

	void set_add_day();

	void add_Tiger();
	void add_Bear();
	void add_Peng();
	void add_Monkey();

	void add_Baby_Tiger();
	void add_Baby_Bear();
	void add_Baby_Peng();
	void add_Baby_Monkey();

	int have_Tiger_Adult();
	int have_Bear_Adult();
	int have_Peng_Adult();
	int have_Monkey_Adult();

	void remove_Tiger();
	void remove_Bear();
	void remove_Peng();
	void remove_Monkey();

	Animal* get_Animal_Tiger();
	Animal* get_Animal_Bear();
	Animal* get_Animal_Peng();
	Animal* get_Animal_Monkey();

	int get_T_num();
	int get_B_num();
	int get_P_num();
	int get_M_num();
	int get_A_num();

	void set_total_profit();
	int get_total_profit();
	void reset_total_profit();

	void set_total_feed();
	void set_total_feed(int n);
	int get_total_feed();
	void reset_total_feed();

	void set_bonus(int n);
	int get_bonus();
	void reset_bonus();

	Zoo &operator=(Zoo &);
};

#endif