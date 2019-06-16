#include "card.h"

/*********************************************************************
** Function: card
** Description: default constructor
** Parameters: None
*********************************************************************/ 
card::card()
{
	value = 0;
	suit = "";
}

/*********************************************************************
** Function: card
** Description: constructor
** Parameters: int x, string y
*********************************************************************/ 
card::card(int x, string y)
{
	value = x;
	suit = y;
}

/*********************************************************************
** Function: card
** Description: destructor
** Parameters: None
*********************************************************************/ 
card::~card(){}

/*********************************************************************
** Function: get_value
** Description: accessor
** Parameters: None
*********************************************************************/ 
int card::get_value()
{
	return value;
}

/*********************************************************************
** Function: get_suit
** Description: accessor
** Parameters: None
*********************************************************************/ 
string card::get_suit()
{
	return suit;
}

/*********************************************************************
** Function: set_value
** Description: mutator
** Parameters: int x
*********************************************************************/ 
void card::set_value(int x)
{
	value = x;
}

/*********************************************************************
** Function: set_suit
** Description: mutator
** Parameters: string y
*********************************************************************/ 
void card::set_suit(string y)
{
	suit = y;
}

/*********************************************************************
** Function: print_card
** Description: display card
** Parameters: None
*********************************************************************/ 
void card::print_card(){
	if(value < 11)
		cout << "card: " << suit << "\t" << value << endl;
	else if(value == 11)
		cout << "card: " << suit << "\t" << "J" << endl;
	else if(value == 12)
		cout << "card: " << suit << "\t" << "Q" << endl;
	else if(value == 13)
		cout << "card: " << suit << "\t" << "K" << endl;
	else if(value == 14)
		cout << "card: " << suit << "\t" << "A" << endl;

}

/*********************************************************************
** Function: print_value
** Description: find a value of card according the BlackJack rules
** Parameters: bool a
*********************************************************************/ 
int card::print_value(bool bigAce){
	if (value > 10 && value < 14)
		return 10;
	else if (value == 14){
		if (bigAce)
			return 11;
		else
			return 1;
	}
	else
		return value;
}

/*********************************************************************
** Function: operator=
** Description: overloading operator assignment 
** Parameters: const card &c
*********************************************************************/ 
card &card::operator=(const card &c){
	value = c.value;
	suit = c.suit;
	return *this;
}
