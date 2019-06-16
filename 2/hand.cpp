#include "hand.h"
/*********************************************************************
** Function: default constructor
** Description: set values
** Parameters: None
*********************************************************************/ 
hand::hand()
{
	num_cards = 0;
	cards = NULL;
}
/*********************************************************************
** Function: destructor
** Description: delete the dynamic array
** Parameters: None
*********************************************************************/ 
hand::~hand()
{
	if (cards != NULL)
		delete[] cards;
}
/*********************************************************************
** Function: get_cards
** Description: accessor
** Parameters: int x
*********************************************************************/ 
card hand::get_cards(int x)
{
	return cards[x];
}
/*********************************************************************
** Function: get_cards_pointer
** Description: accessor
** Parameters: None
*********************************************************************/ 
card *hand::get_cards_pointer()
{
	return cards;
}
/*********************************************************************
** Function: get_num_cards
** Description: accessor 
** Parameters: None
*********************************************************************/ 
int hand::get_num_cards()
{
	return num_cards;
}

/*********************************************************************
** Function: setcards
** Description: mutator
** Parameters: int x, card c
*********************************************************************/ 
void hand::set_cards(int x, card c)
{
	cards[x] = c;
}

/*********************************************************************
** Function: set_num_cards
** Description: mutator
** Parameters: int x
*********************************************************************/ 
void hand::set_num_cards(int x)
{
	num_cards = x;
}

/*********************************************************************
** Function: add_card
** Description: add one card on hand
** Parameters: card c
*********************************************************************/ 
void hand::add_card(card c)
{
	num_cards++;
	if (num_cards == 1){
		cards = new card[num_cards];
		cards[num_cards - 1] = c;
	}
	else{
		card *temp = new card[num_cards - 1];
		for (int i = 0; i < num_cards - 1; i++)
			temp[i] = cards[i];
		delete[] cards;
		cards = new card[num_cards];
		for (int i = 0; i < num_cards - 1; i++)
			cards[i] = temp[i];
		cards[num_cards - 1] = c;
		delete[] temp;
	}
}

/*********************************************************************
** Function: print_cards
** Description: display all cards
** Parameters: bool h
*********************************************************************/ 
void hand::print_cards(bool h)
{
	if (!h){
		for (int i = 0; i < num_cards; i++)
			cards[i].print_card();
	}
	else {
		cout << "card: * **" << endl;
		for (int i = 1; i < num_cards; i++)
			cards[i].print_card();
	}
}

/*********************************************************************
** Function: cal
** Description: function to calculate BlackJacks's summary value of all cards.
** Parameters: bool a
*********************************************************************/ 
int hand::cal(bool a)
{
	int total = 0;
	for (int i = 0; i < num_cards; i++){
		total += cards[i].print_value(a);
	}
	return total;
}

/*********************************************************************
** Function: operator=
** Description: overloading operator assignment 
** Parameters: hand &h
*********************************************************************/ 
hand &hand::operator=(hand &h)
{
	if (num_cards != 0)
		delete[] cards;
	num_cards = h.num_cards;
	if (num_cards != 0){
		cards = new card[num_cards];
		for (int i = 0; i < num_cards; i++)
			cards[i] = h.cards[i];
	}
	return *this;
}