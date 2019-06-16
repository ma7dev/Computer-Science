#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

class card
{
private:
	int value;
	string suit;
public:
	card();
	card(int, string);
	~card();

	int get_value();
	int print_value(bool);
	
	string get_suit();

	void set_value(int);
	void set_suit(string);
	void print_card();

	card &operator=(const card &);
};

#endif
