#include "player.h"

/*********************************************************************
** Function: player
** Description: default constructor
** Parameters: None
*********************************************************************/ 
player::player()
{
	playing_total = 0;
	card_total = 0;
	bet = 0;
}

/*********************************************************************
** Function: player
** Description: copy constructor
** Parameters: player &p
*********************************************************************/ 
player::player(player &p)
{
	playing_total = p.playing_total;
	card_total = p.card_total;
	bet = p.bet;
	p_hand = p.p_hand;
}

/*********************************************************************
** Function: player
** Description: destructor
** Parameters: None
*********************************************************************/ 
player::~player(){}

/*********************************************************************
** Function: get_p_hand
** Description: accessor
** Parameters: None
*********************************************************************/ 
hand &player::get_p_hand()
{
	return p_hand;
}

/*********************************************************************
** Function: get_playing_total
** Description: accessor
** Parameters: None
*********************************************************************/ 
int player::get_playing_total()
{
	return playing_total;
}

/*********************************************************************
** Function: get_card_total
** Description: accessor
** Parameters: None
*********************************************************************/ 
int player::get_card_total()
{
	return card_total;
}
/*********************************************************************
** Function: get_bet
** Description: accessor
** Parameters: None
*********************************************************************/ 
int player::get_bet()
{
	return bet;
}
/*********************************************************************
** Function: set_p_hand
** Description: mutator
** Parameters: card c
*********************************************************************/ 
void player::set_p_hand(card c)
{ 
	p_hand.add_card(c);
}

/*********************************************************************
** Function: set_playing_total
** Description: mutator
** Parameters: int x
*********************************************************************/ 
void player::set_playing_total(int x)
{
	playing_total = x;
}

/*********************************************************************
** Function: set_card_total
** Description: mutator
** Parameters: int x
*********************************************************************/ 
void player::set_card_total(int x)
{
	card_total = x;
}

/*********************************************************************
** Function: set_bet
** Description: mutator
** Parameters: int x
*********************************************************************/ 
void player::set_bet(int x)
{
	bet = x;
}

/*********************************************************************
** Function: cal_card_total
** Description: calculate summary BlackJacks values for all cards on one hand. 
** Parameters: bool a
*********************************************************************/ 
void player::cal_card_total(bool a)
{
	card_total = p_hand.cal(a);
}

/*********************************************************************
** Function: operator=
** Description: overloading operator assignment 
** Parameters: player &p
*********************************************************************/ 
player &player::operator=(player &p)
{
	playing_total = p.playing_total;
	card_total = p.card_total;
	bet = p.bet;
	p_hand = p.p_hand;
	return *this;
}
