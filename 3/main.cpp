/******************************************************
** Program: main.cpp
** Author: Mazen Alotaibi
** Date: 05/08/2016
** Description: This is the main which eveything to start  the program
******************************************************/ 
#include "Game.h"

using namespace std;
/*********************************************************************
** Function: int main
** Description: run the game
** Parameters: None
*********************************************************************/ 
int main() 
{
	cout << string(200, '\n');
	srand((unsigned)time(NULL));
	Game DZ;
	string name;

	#ifdef RULES
	cout << "The Format of Playing the Game" << endl;
	cout << "=======================================================" << endl;
	cout << "Day: #_Day" << endl;
	cout << "=======================================================" << endl;
	cout << "Generic (G): Base case, behaves normally" << endl;
	cout << "Premium (P): Twice as expensive for all animals, sickness becomes half as likely to occur." << endl;
	cout << "Cheap   (C): Half as expensive for all animals, sickness becomes twice as likely to occur" << endl;
	cout << endl << "NOTE: I will ask you again on day: #_After_3_Days" << endl << endl;
	cout << "What do you want to buy? Answer: G/P/C" << endl;
	cout << "Feeding Cost for Today: $#_Feeding_cost" << endl;
	cout << "Money: #_User's_Money" << endl;
	cout << "Animals: #_Animals" << endl;
	cout << "        Tigers:( #_Tigers )" << endl;
	cout << "            Tiger: #_Tiger" << endl;
	cout << "                    Adult/Baby, #_Age, #_Babies, $#_Feeding_cost, $#_Healing_cost, $#_Profit" << endl;
	cout << "        Bears: ( #_Bears )" << endl;
	cout << "            Bear: #_Bear" << endl;
	cout << "                    Adult/Baby, #_Age, #_Babies, $#_Feeding_cost, $#_Healing_cost, $#_Profit" << endl;
	cout << "        Pengs: ( #_Pengs )" << endl;
	cout << "            Peng: #_Peng" << endl;
	cout << "                    Adult/Baby, #_Age, #_Babies, $#_Feeding_cost, $#_Healing_cost, $#_Profit" << endl;
	cout << "        Monkeys: ( #_Monkeys )" << endl;
	cout << "            Monkey: #_Monkey" << endl;
	cout << "                    Adult/Baby, #_Age, #_Babies, $#_Feeding_cost, $#_Healing_cost, $#_Profit" << endl;
	cout << endl << endl;
	cout << "Random Event: Sickness/Baby Born/Bonus/Nothing" << endl;
	cout << "Do you want to buy? Answer:Y/anthing" << endl;
	cout << endl << endl;
	cout << "Tiger(T) = $10,000" << endl;
	cout << "Bear (B) = $5,000" << endl;
	cout << "Moneky (M) = $2,500" << endl;
	cout << "Peng (P) = $1,000 " << endl << endl;
	cout << "What do you want to buy? Answer: Y/Anthing" << endl;
	cout << "Profit for Today: #_Profit" << endl;
	cout << "Money: #_User's_Money" << endl;
	cout << "End of Day: #_Day" << endl;
	cout << "=======================================================" << endl;
	cout << endl << endl << endl << endl;
	#endif
	#ifdef FUN
	int text_count;
	string text[255];
	string line;
	ifstream file;
	file.open("secret.txt");
	while(!file.fail())
    {
    	getline(file,line);
    	text[text_count]=line;
    	text_count++;
    }
    file.close();

	cout << "Enter a name: "; cin >> name;
	cout << endl << endl;
	if(name == "Trump" || name == "trump")
	{
		int num = rand() % 10;
		cout << "Trump's quote: " << text[num] << endl << endl;
		cout << "You have donated all of your money to Mr. Trump to build the mexico wall" << endl << endl;
	
		cout << "+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+" << endl;
		cout << "|   |   |   |   |   | T | R | U | M | P |   |   | T | R | U | M | P |   |   | T | R | U | M | P |" << endl;
		cout << "+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+" << endl;
		cout << "|   |   |   |   | T | R | U | M | P |   |   | T | R | U | M | P |   |   | T | R | U | M | P |   |" << endl;
		cout << "+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+" << endl;
		cout << "|   |   |   | T | R | U | M | P |   |   | T | R | U | M | P |   |   | T | R | U | M | P |   |   |" << endl;
		cout << "+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+" << endl;
		cout << "|   |   | T | R | U | M | P |   |   | T | R | U | M | P |   |   | T | R | U | M | P |   |   |   |" << endl;
		cout << "+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+" << endl;
		cout << "|   | T | R | U | M | P |   |   | T | R | U | M | P |   |   | T | R | U | M | P |   |   |   |   |" << endl;
		cout << "+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+" << endl;
		cout << "| T | R | U | M | P |   |   | T | R | U | M | P |   |   | T | R | U | M | P |   |   |   |   |   |" << endl;
		cout << "+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+" << endl;

		DZ.set_money(0);
	}
	else if(name == "Bernie" || name == "bernie")
	{
		int num = rand() % 10 +10;
		cout << "Bernie's quote: " << text[num] << endl << endl;
		cout << "You have $10,000,000 because Mr. Bernie gave it to you as a gift" << endl << endl;
		DZ.set_money(10000000);
	}
	#endif
	DZ.start_game();

	return 0;
}