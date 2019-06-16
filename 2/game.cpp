#include "game.h"
#define Forever for(;;)			
/*********************************************************************
** Function: constructor
** Description: set values to private members using parameters number of players and amount of money.
** Parameters: int x, int y
*********************************************************************/ 
game::game(int x, int y)
{
	num_players = x;
	players = new player[x];
	for (int i = 0; i < num_players; i++)
		players[i].set_playing_total(y);
}
/*********************************************************************
** Function: destructor
** Description: delete dynamic array
** Parameters: None
*********************************************************************/ 
game::~game()
{
	if (players != NULL)
		delete[] players;
}
/*********************************************************************
** Function: get_cards
** Description: accessor
** Parameters: None
*********************************************************************/ 
deck game::get_cards()
{
	return cards;
}
/*********************************************************************
** Function: get_player
** Description: accessor
** Parameters: int _y
*********************************************************************/ 
player game::get_player(int x)
{
	return players[x];
}
/*********************************************************************
** Function: get_dealer_CPU
** Description: accessor
** Parameters: None
*********************************************************************/ 
dealer game::get_dealer_CPU()
{
	return dealer_CPU;
}
/*********************************************************************
** Function: getNum_players
** Description: accessor function to get number of players.
** Parameters: None
*********************************************************************/ 
int game::get_num_players()
{
	return num_players;
}
/*********************************************************************
** Function: set_cards
** Description: mutator
** Parameters: deck d
*********************************************************************/ 
void game::set_cards(deck d)
{
	cards = d;
}
/*********************************************************************
** Function: set_dealer_CPU
** Description: mutator
** Parameters: dealer d
*********************************************************************/ 
void game::set_dealer_CPU(dealer d)
{
	dealer_CPU = d;
}
/*********************************************************************
** Function: set_player
** Description: mutator
** Parameters: int x, player p
*********************************************************************/ 
void game::set_player(int x, player p)
{
	players[x] = p;
}

/*********************************************************************
** Function: set_num_players
** Description: mutator
** Parameters: int x
*********************************************************************/ 
void game::set_num_players(int x)
{
	num_players = x;
}
/*********************************************************************
** Function: redo
** Description: restart game
** Parameters: None
*********************************************************************/ 
void game::redo()
{
	int *index = new int[num_players];
	for (int i = 0; i < num_players; i++)
		index[i] = players[i].get_playing_total();
	delete[] players;
	players = new player[num_players];
	for (int i = 0; i < num_players; i++)
		players[i].set_playing_total(index[i]);
	delete[] index;
	delete[] dealer_CPU.get_d_hand().get_cards_pointer();
	dealer_CPU.set_card_total(0);
	dealer_CPU.get_d_hand().set_num_cards(0);
}
/*********************************************************************
** Function: remove_players
** Description: deletes from dynamically array 'players' and move players who have money to the beginning
** Parameters: None
*********************************************************************/ 
void game::remove_players()
{
	int x = 0, y = 0;
	for (int i = 0; i < num_players; i++)
	{
		if (players[i].get_playing_total() >= 1)
			x++;
	}
	player *temp = new player[x];
	for (int i = 0; i < num_players; i++)
	{
		if (players[i].get_playing_total() >= 1)
		{
			temp[y] = players[i];
			y++;
		}
	}
	delete[] players;
	num_players = x;
	players = new player[num_players];
	for (int i = 0; i < num_players; i++)
		players[i] = temp[i];
	delete[] temp;
}
/*********************************************************************
** Function: is_pos_int
** Description: is it an integer bigger or equal to zero
** Parameters: string str
*********************************************************************/
bool game::is_pos_int(string str)
{
	for(int i=0; i<str.length(); i++)
	{
		if(!(str.at(i)>='0' && str.at(i)<='9'))
			return false;
	}
	return true;
}
/*********************************************************************
** Function: is_in_range
** Description: less or equal to the right amount to bet
** Parameters: string str, int x
*********************************************************************/
bool game::is_in_range(string str, int x)
{
	int change = atoi(str.c_str());
	if(!(change <= x))
		return false;
	return true;
}
/*********************************************************************
** Function: start_game
** Description: where magic happens
** Parameters: None
*********************************************************************/
void game::start_game()
{
	bool restart = false;
	Forever
	{
		cards.shuffle();
		if (restart)
			redo();
		for (int i = 0; i < num_players; i++)
		{
			string input_check;
			cout << "Player: " << i + 1 << " ( $" << players[i].get_playing_total() << " )"<< endl;
			cout << "How much do you want to bet? $";
			Forever
			{
				cin >> input_check;
				if (!(is_pos_int(input_check)))
				{
					cout << "You Idiot, Try Again! (Enter an Integer)" << endl;
					cout << "How much do you want to bet? $";
				}
				else if (!(is_in_range(input_check, players[i].get_playing_total())))
				{
					cout << "You Idiot, Try Again! (Bet is larger than what you have, idiot)" << endl;
					cout << "How much do you want to bet? $";
				}
				else
				{
					int bet = atoi(input_check.c_str());
					players[i].set_bet(bet);
					break;
				}
			}
			cout << endl;
		}
		cout << string(200, '\n');
		for (int i = 0; i < num_players; i++)
		{	
			cout << "Player: " << i + 1 << endl;
			players[i].set_p_hand(cards.get_top_card());
			players[i].set_p_hand(cards.get_top_card());
			players[i].get_p_hand().print_cards(false);
			players[i].cal_card_total(true);
			cout << "Total card value: " << players[i].get_card_total() << endl << endl;
		}
		
		
		cout << endl << "Dealer:" << endl;
		dealer_CPU.set_d_hand(cards.get_top_card());
		dealer_CPU.set_d_hand(cards.get_top_card());
		dealer_CPU.get_d_hand().print_cards(true);
		cout << "==================================" << endl;
		cout << endl << endl << endl;
		for (int i = 0; i < num_players; i++)
		{
			cout << "Player: " << i + 1 << endl;
			Forever
			{
				cout << "card total --- " << players[i].get_card_total() << endl;
				if (players[i].get_card_total() > 20)
					break;
				cout << endl;
				cout << "Do you want to hit or not (Y-yes)? ";
				char choice;
				cin >> choice;
				if (toupper(choice) == 'Y')
				{
					players[i].set_p_hand(cards.get_top_card());
					players[i].get_p_hand().get_cards(players[i].get_p_hand().get_num_cards() - 1).print_card();
					if (players[i].get_p_hand().get_cards(players[i].get_p_hand().get_num_cards() - 1).get_value() == 14)
					{
						char BoS;
						cout << endl;
						cout << "Do you want to make Ace big (Y-yes)? ";
						cin >> BoS;
						if (toupper(BoS) == 'Y')
							players[i].cal_card_total(true);
						else 
							players[i].cal_card_total(false);
					}
					else
						players[i].cal_card_total(false);
				}
				else
					break;
			}
			cout << endl;
		}
		cout << endl << "Dealer:" << endl;
		dealer_CPU.cal_card_total();
		Forever
		{
			if (dealer_CPU.get_card_total() < 17)
			{
				dealer_CPU.set_d_hand(cards.get_top_card());
				dealer_CPU.cal_card_total();
			}
			else
				break;
		}
		dealer_CPU.get_d_hand().print_cards(false);
		cout << "Total card --- " << dealer_CPU.get_card_total() << endl;
		if (dealer_CPU.get_card_total() > 21)
		{
			for (int i = 0; i < num_players; i++)
			{
				if (players[i].get_card_total() < 21)
				{
					players[i].set_playing_total(players[i].get_playing_total() + players[i].get_bet());
					players[i].set_bet(0);
				}
				else if (players[i].get_card_total() == 21)
				{
					players[i].set_playing_total(players[i].get_playing_total() + (int)(1.5 * players[i].get_bet()));
					players[i].set_bet(0);
				}
				else
				{
					players[i].set_playing_total(players[i].get_playing_total() - players[i].get_bet());
					players[i].set_bet(0);
				}
			}
		}
		else
		{
			for (int i = 0; i < num_players; i++)
			{
				if (players[i].get_card_total() < dealer_CPU.get_card_total()){
					players[i].set_playing_total(players[i].get_playing_total() - players[i].get_bet());
					players[i].set_bet(0);
				}
				else if (players[i].get_card_total() > dealer_CPU.get_card_total() && players[i].get_card_total() < 21)
				{
					players[i].set_playing_total(players[i].get_playing_total() + players[i].get_bet());
					players[i].set_bet(0);
				}
				else if (players[i].get_card_total() > dealer_CPU.get_card_total() && players[i].get_card_total() == 21)
				{
					players[i].set_playing_total(players[i].get_playing_total() + (int)(1.5 * players[i].get_bet()));
					players[i].set_bet(0);
				}
				else if (players[i].get_card_total() == dealer_CPU.get_card_total())
					players[i].set_bet(0);
				else if (players[i].get_card_total() > 21)
				{
					players[i].set_playing_total(players[i].get_playing_total() - players[i].get_bet());
					players[i].set_bet(0);
				}
			}
		}
		cout << "==================================" << endl;
		for (int i = 0; i < num_players; i++)
			cout << "Player: " << i + 1 << " ( $" << players[i].get_playing_total() << " )"<< endl;
		cout << "==================================" << endl;

		
		remove_players();
		restart = true;

		if (num_players == 1)
		{
			cout << endl;
			cout << "Do you want to finish the game (Y-yes)? ";
			char check;
			cin >> check;
			if (toupper(check) == 'Y')
			{
				cout << string(200, '\n');
				break;
			}
		}
		else if (num_players == 0)
		{
			cout << string(200, '\n');
			cout << "FIND SOMETHING ELSE TO PLAY" << endl;
			break;
		}
	}
}