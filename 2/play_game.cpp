/*********************************************************************
** Program Filename: BlackJack
** Author: Mazen Alotaibi
** Date: 04/23/2016
** Description:
   This program fully realize in console famous game BlackJack
** Input:
   use must input number of players and amount of money in each players
   at the start of game. Also user inputs: bet for each players, choice
   what value will have Ace(1 or 11) in each situation. User checks to 
   continue game, when only one player is left or exit. 
   User checks a staying or recipienting new card for each players too.
** Output:
   In console are displayed all cards on each hands, score after each 
   game, temporal scores after each 'iteration'.
*********************************************************************/

#include "game.h"
#include <cstdlib>

int main()
{
	cout << string(200, '\n');
	srand((unsigned)time(NULL));
	string check_input;
	int x;
	int y = 2000;
	int wrong = 0;
	while(wrong == 0)
	{
		for(int i=0; i>=0; i++)
		{
			int again=0;
			cout << "How many players? ";
			cin >> check_input;
			for(int i=0; i<check_input.length(); i++)
			{
				if(!(check_input.at(i)>='0' && check_input.at(i)<='9'))
					again++;
			}
			if(again == 0)
				break;
			else
				cout << "You Idiot, Try Again! (Enter an Integer)" << endl;
		}
		x = atoi(check_input.c_str());
		if(!(x > 10 || x == 0))
			break;
		else
			cout << "You Idiot, Try Again! ( 0 < Number of Players < 11)" << endl;
	}
	cout << endl << endl;
	game show_time(x, y);
	show_time.start_game();
	return 0;
}