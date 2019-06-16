#include "deck.h"

/*********************************************************************
** Function: deck 
** Description: default constructor
** Parameters: None
*********************************************************************/ 
deck::deck()
{
	num_cards = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 2; j < 15; j++)
		{
			cards[num_cards].set_value(j);
			switch (i)
			{
				case 0:
				{
				    cards[num_cards].set_suit("♣");
				    break;
				}
				case 1:
				{
					cards[num_cards].set_suit("♦");
					break;
				}
				case 2:
				{
					cards[num_cards].set_suit("♥");
					break;
				}
				default:
				{
					cards[num_cards].set_suit("♠");
					break;
				}
			}
			num_cards++;
		}
	}
}


/*********************************************************************
** Function: deck
** Description: destructor
** Parameters: None
*********************************************************************/ 
deck::~deck(){}

/*********************************************************************
** Function: get_cards
** Description: accessor
** Parameters: int x
*********************************************************************/ 
card deck::get_cards(int x)
{
	return cards[x];
}

/*********************************************************************
** Function: get_num_cards
** Description: accessor
** Parameters: None
*********************************************************************/ 
int deck::get_num_cards()
{
	return num_cards;
}


/*********************************************************************
** Function: setCards
** Description: mutator function to set a card according to it's 
** position in array.
** Parameters: int position, Card card
*********************************************************************/ 
void deck::set_cards(int x, card c)
{
	cards[x] = c;
}

/*********************************************************************
** Function: set_num_cards
** Description: mutator
** Parameters: int x
*********************************************************************/ 
void deck::set_num_cards(int x)
{
	num_cards = x;
}


/*********************************************************************
** Function: shuffle
** Description: shuffle all cards in the deck
** Parameters: None
*********************************************************************/ 
void deck::shuffle()
{
	for (size_t i = 0; i < 52; i++) 
		swap(cards[i], cards[rand() % 52]);
}

/*********************************************************************
** Function: get_top_card
** Description: create new deck when the current deck is empty if not then loss one card each draw
** Parameters: None
*********************************************************************/ 
card &deck::get_top_card()
{
	if (num_cards == 0)
	{
		cout << "+------------------------------------+" << endl;
		cout << "| NEW DECK OF CARDS HAS BEEN CREATED |" << endl;
		cout << "+------------------------------------+" << endl;
		shuffle();
		num_cards = 51;
		return cards[0];
	}
	num_cards--;
	return cards[52 - num_cards - 1];
}
