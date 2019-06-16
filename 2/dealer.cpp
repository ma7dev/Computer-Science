#include "dealer.h"

/*********************************************************************
** Function: default dealer constructor
** Description: set values to private members by default.
** Object of class Hand is created automatically.
** Parameters: None
*********************************************************************/ 
dealer::dealer()
{
	card_total=0;
}

/*********************************************************************
** Function:  copy dealer constructor
** Description: set values to private members according to values of another
** Hand object.
** Parameters: dealer &_dealer - adress of _dealer object
*********************************************************************/ 
dealer::dealer(dealer &d)
{
	card_total = d.card_total;
	d_hand = d.d_hand;
}

/*********************************************************************
** Function: dealer destructor
** Description: it has empty body because we don't have any dynamical non_standart
** variables 
** Parameters: None
*********************************************************************/ 
dealer::~dealer(){}

/*********************************************************************
** Function: getD_hand
** Description: accessor function to get Adress of Hand-object member
** variables 
** Parameters: None
*********************************************************************/ 
hand &dealer::get_d_hand()
{
	return d_hand;
}

/*********************************************************************
** Function: getCard_total
** Description: accessor function to get value of private member
** card_total 
** Parameters: None
*********************************************************************/ 
int dealer::get_card_total()
{
	return card_total;
}

/*********************************************************************
** Function: setD_hand
** Description: mutator function to add value for private member 
** Hand-object. So, increment the dynamically array of cards 
** Parameters: Card _card
*********************************************************************/ 
void dealer::set_d_hand(card c)
{
	d_hand.add_card(c);
}

/*********************************************************************
** Function: set_card_total
** Description: mutator
** Parameters: int x 
*********************************************************************/ 
void dealer::set_card_total(int x)
{
	card_total = x;
}

/*********************************************************************
** Function: cal_card_total
** Description: calculate values for all cards on one hand. 
** Parameters: None 
*********************************************************************/ 
void dealer::cal_card_total()
{
	int total = 0;
	bool a = false;
	for (int i = 0; i < d_hand.get_num_cards(); i++){
		if (d_hand.get_cards(i).get_value() == 14){
			a = true;
			continue;
		}
		total += d_hand.get_cards(i).print_value(false);
	}
	if (a){				   
		if (total < 11)		 
			total += 11;
		else
			total += 1;
	}
	card_total = total;
}