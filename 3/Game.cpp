/******************************************************
** Program: Game.cpp
** Author: Mazen Alotaibi
** Date: 05/08/2016
** Description: This is the game class which has all the zoo and the functionality of using them
******************************************************/ 
#include "Game.h"
#define Forever for(;;)
/*********************************************************************
** Function: set name
** Description: set name value
** Parameters: string
*********************************************************************/
Game::Game(){
	money = 100000;
	day = 1;
	feeding_kind = 0;
}
/*********************************************************************
** Function: set name
** Description: set name value
** Parameters: string
*********************************************************************/
Game::~Game(){}
/*********************************************************************
** Function: set name
** Description: set name value
** Parameters: string
*********************************************************************/
void Game::set_money(int n){
	money = n;
}
/*********************************************************************
** Function: set name
** Description: set name value
** Parameters: string
*********************************************************************/
void Game::set_day_add(){
	day = day + 1;
}
/*********************************************************************
** Function: set name
** Description: set name value
** Parameters: string
*********************************************************************/
int Game::get_day(){
	return day;
}
/*********************************************************************
** Function: set name
** Description: set name value
** Parameters: string
*********************************************************************/
int Game::get_money(){
	return money;
}
/*********************************************************************
** Function: set name
** Description: set name value
** Parameters: string
*********************************************************************/
void Game::set_feeding_kind(int n){
	feeding_kind = n;
}
/*********************************************************************
** Function: set name
** Description: set name value
** Parameters: string
*********************************************************************/
int Game::get_feeding_kind(){
	return feeding_kind;
}
/*********************************************************************
** Function: set name
** Description: set name value
** Parameters: string
*********************************************************************/
void Game::set_losses(int n){
	money = money - n;
}
/*********************************************************************
** Function: set name
** Description: set name value
** Parameters: string
*********************************************************************/
bool Game::is_pos_int(string str)
{
	for(int i=0; i<str.length(); i++)
	{
		if(!(str.at(i)>='0' && str.at(i)<='9'))
			return false;
	}
	return true;
}
/*********************************************************************
** Function: set name
** Description: set name value
** Parameters: string
*********************************************************************/
bool Game::is_in_range(string str, int x)
{
	int change = atoi(str.c_str());
	if(!(change <= x))
		return false;
	return true;
}
/*********************************************************************
** Function: set name
** Description: set name value
** Parameters: string
*********************************************************************/
void Game::random_event(int n){
	int text_count;
	string text[255];
	string line;
	ifstream file;

	file.open("bonus.txt");
	while(!file.fail())
    {
    	getline(file,line);
    	text[text_count]=line;
    	text_count++;
    }
    file.close();

	cout << "Random Event: ";
	if(n == 0)
	{
		int ran = rand() % 100;
		if(ran >= 0 && ran < 30)
		{
			if(z.get_A_num() !=0){
				cout << "Sickness" << endl;
				random_die();
			}
			else
				cout << "Nothing" << endl;
		}
		else if(ran >= 30 && ran < 60)
		{
			int num = rand() % 5;
			int bonus = rand() % 250 + 250;
			cout << text[num] << endl << endl;
			cout << "Extra Money ( $" << bonus << " )" << endl;
			z.set_bonus(bonus);
		}
		else if(ran >= 60 && ran < 90)
		{
			int random = rand() % 4;
			if(random == 0)
			{
				if(z.have_Tiger_Adult() !=0){
					z.add_Baby_Tiger();
					cout << "You have a baby! " << endl;
				}
				else
					cout << "Nothing" << endl;
			}
			else if(random == 1){
				if(z.have_Bear_Adult() !=0){
					z.add_Baby_Bear();
					z.add_Baby_Bear();
					cout << "You have a baby! " << endl;
				}
				else
					cout << "Nothing" << endl;
			}
			else if(random == 2){
				if(z.have_Peng_Adult() !=0){
					z.add_Baby_Peng();
					z.add_Baby_Peng();
					z.add_Baby_Peng();
					cout << "You have a baby! " << endl;
				}
				else
					cout << "Nothing" << endl;
			}
			else if(random == 3){
				if(z.have_Monkey_Adult() !=0){
					z.add_Baby_Monkey();
					z.add_Baby_Monkey();
					z.add_Baby_Monkey();
					z.add_Baby_Monkey();
					z.add_Baby_Monkey();
					cout << "You have a baby! " << endl;
				}
				else
					cout << "Nothing" << endl;
			}				
		}
		else
			cout << "Nothing" << endl;
	}
	else if(n == 1)
	{
		int ran = rand() % 100;
		if(ran >= 0 && ran < 30)
		{
			if(z.get_A_num() !=0){
				cout << "Sickness" << endl;
				random_die();
			}
			else
				cout << "Nothing" << endl;
		}
		else if(ran >= 30 && ran < 60)
		{
			int num = rand() % 5;
			int bonus = rand() % 250 + 250;
			cout << text[num] << endl << endl;
			cout << "Extra Money ( $" << bonus << " )" << endl;
			z.set_bonus(bonus);
		}
		else if(ran >= 60 && ran < 90)
		{
			int random = rand() % 4;
			if(random == 0)
			{
				if(z.have_Tiger_Adult() !=0){
					z.add_Baby_Tiger();
					cout << "You have a baby! " << endl;
				}
				else
					cout << "Nothing" << endl;
			}
			else if(random == 1){
				if(z.have_Bear_Adult() !=0){
					z.add_Baby_Bear();
					z.add_Baby_Bear();
					cout << "You have a baby! " << endl;
				}
				else
					cout << "Nothing" << endl;
			}
			else if(random == 2){
				if(z.have_Peng_Adult() !=0){
					z.add_Baby_Peng();
					z.add_Baby_Peng();
					z.add_Baby_Peng();
					cout << "You have a baby! " << endl;
				}
				else
					cout << "Nothing" << endl;
			}
			else if(random == 3){
				if(z.have_Monkey_Adult() !=0){
					z.add_Baby_Monkey();
					z.add_Baby_Monkey();
					z.add_Baby_Monkey();
					z.add_Baby_Monkey();
					z.add_Baby_Monkey();
					cout << "You have a baby! " << endl;
				}
				else
					cout << "Nothing" << endl;
			}					
		}
		else
			cout << "Nothing" << endl;
	}
	else if(n == 2)
	{
		int ran = rand() % 100;
		if(ran >= 0 && ran < 30)
		{
			if(z.get_A_num() !=0){
				cout << "Sickness" << endl;
				random_die();
			}
			else
				cout << "Nothing" << endl;
		}
		else if(ran >= 30 && ran < 60)
		{
			int num = rand() % 5;
			int bonus = rand() % 250 + 250;
			cout << text[num] << endl << endl;
			cout << "Extra Money ( $" << bonus << " )" << endl;
			z.set_bonus(bonus);
		}
		else if(ran >= 60 && ran < 90)
		{
			int random = rand() % 4;
			if(random == 0)
			{
				if(z.have_Tiger_Adult() !=0){
					z.add_Baby_Tiger();
					cout << "You have a baby! " << endl;
				}
				else
					cout << "Nothing" << endl;
			}
			else if(random == 1){
				if(z.have_Bear_Adult() !=0){
					z.add_Baby_Bear();
					z.add_Baby_Bear();
					cout << "You have a baby! " << endl;
				}
				else
					cout << "Nothing" << endl;
			}
			else if(random == 2){
				if(z.have_Peng_Adult() !=0){
					z.add_Baby_Peng();
					z.add_Baby_Peng();
					z.add_Baby_Peng();
					cout << "You have a baby! " << endl;
				}
				else
					cout << "Nothing" << endl;
			}
			else if(random == 3){
				if(z.have_Monkey_Adult() !=0){
					z.add_Baby_Monkey();
					z.add_Baby_Monkey();
					z.add_Baby_Monkey();
					z.add_Baby_Monkey();
					z.add_Baby_Monkey();
					cout << "You have a baby! " << endl;
				}
				else
					cout << "Nothing" << endl;
			}					
		}
		else
			cout << "Nothing" << endl;
	}
}
/*********************************************************************
** Function: set name
** Description: set name value
** Parameters: string
*********************************************************************/
void Game::random_die(){
	int ran = rand() % 4;
	if( ran == 0){
		if(z.get_T_num() != 0){
			int ranT = rand() % z.get_T_num();
			z.set_T_die(ranT);
			cout << "Died: Tiger " << ranT + 1 << endl;
		}
		else
			cout << "There aren't any casualties" << endl;
	}
	else if( ran == 1){
		if(z.get_B_num() != 0){
			int ranB = rand() % z.get_B_num();
			z.set_B_die(ranB);
			cout << "Died: Bear " << ranB + 1 << endl;
		}
		else
			cout << "There aren't any casualties" << endl;
	}
	else if( ran == 2){
		if(z.get_P_num() != 0){
			int ranP = rand() % z.get_P_num();
			z.set_P_die(ranP);
			cout << "Died: Peng " << ranP + 1 << endl;
		}
		else
			cout << "There aren't any casualties" << endl;
	}
	else if( ran == 3){
		if(z.get_M_num() != 0){
			int ranM = rand() % z.get_M_num();
			z.set_M_die(ranM);
			cout << "Died: Monkey " << ranM + 1 << endl;
		}
		else
			cout << "There aren't any casualties" << endl;
	}
}
/*********************************************************************
** Function: set name
** Description: set name value
** Parameters: string
*********************************************************************/
void Game::start_game()
{
	int trace = 1;
	float feeding_cost = 1;
	string buy;
	string choice;
	if(money != 0)
	{
		cout << "=======================================================" << endl;
		Forever
		{
			cout << "Day: " << day << endl;
			cout << "=======================================================" << endl;
			if(day == trace){
				trace = day + 3;
				for(int j=0; j>=0; j++){
					cout << endl << endl;
					cout << "Generic (G): Base case, behaves normally" << endl;
					cout << "Premium (P): Twice as expensive for all animals, sickness becomes half as likely to occur." << endl;
					cout << "Cheap   (C): Half as expensive for all animals, sickness becomes twice as likely to occur" << endl;
					cout << endl << "NOTE: I will ask you again on day: " << trace << endl << endl;
					cout << "What do you want to buy? "; cin >> choice;
					if(choice == "G"){
						set_feeding_kind(0);
						feeding_cost = 1;
						break;
					}
					else if(choice == "P"){
						set_feeding_kind(1);
						feeding_cost = 2;
						break;
					}
					else if(choice == "C"){
						set_feeding_kind(2);
						feeding_cost = 0.5;
						break;
					}
					else
						cout << "You need to choose" << endl;
				}
			}
			if(z.get_A_num() != 0)
			{
				z.set_total_feed();
				z.set_total_feed(feeding_cost * z.get_total_feed());
				cout << "Feeding Cost for Today: $" << z.get_total_feed() << endl;
				if(get_money() >= z.get_total_feed())
					set_money( get_money() - z.get_total_feed() );
				else{
					cout << "You don't have enough food to feed your animals" << endl;
					cout << "All of them will die" << endl;
					for(int i=0; i<z.get_T_num(); i++)
						z.set_T_die(i);
					for(int i=0; i<z.get_B_num(); i++)
						z.set_B_die(i);
					for(int i=0; i<z.get_P_num(); i++)
						z.set_P_die(i);
					for(int i=0; i<z.get_M_num(); i++)
						z.set_M_die(i);
				}
				z.reset_total_feed();
			}
			cout << "Money: $" << get_money() << endl;
			cout << "Animals: " << z.get_A_num() << endl;

			cout << endl << endl;

			cout << "        Tigers:( " << z.get_T_num() << " )" << endl;
			z.print_Tigers();
			cout << endl;
			cout << "        Bear:  ( " << z.get_B_num() << " )" << endl;
			z.print_Bears();
			cout << endl;
			cout << "        Peng:  ( " << z.get_P_num() << " )" << endl;
			z.print_Pengs();
			cout << endl;
			cout << "        Monkey:( " << z.get_M_num() << " )" << endl;
			z.print_Monkeys();
			cout << endl;

			random_event(get_feeding_kind());
			cout << endl;
			if(get_money() >= 1000)
			{
				for(int j=0; j>=0; j++){
					cout << "Do you want to buy? "; cin >> buy;
					if(z.get_A_num() == 0 && buy != "Y")
						cout << "You don't have animals, so you need to buy" << endl;
					else if(z.get_A_num() != 0 && buy != "Y")
						break;
					else{
						if(buy == "Y")
						{
							for(int i=0; i>=0; i++){
								if(get_money() >= 1000)
								{
									cout << endl << endl;
									cout << "Tiger(T) = $10,000" << endl;
									cout << "Bear (B) = $5,000" << endl;
									cout << "Moneky (M) = $2,500" << endl;
									cout << "Peng (P) = $1,000 " << endl << endl;
									cout << "What do you want to buy? "; cin >> choice;
									if(choice == "T")
									{
										if(get_money() >= 10000){
											set_losses(10000);
											cout << "Money: $" << get_money() << endl;
											z.add_Tiger();
											cout << "Tigers: " << z.get_T_num() << endl;
											cout << "Do you want to buy again (Yes = Y)? "; cin >> buy;
											if(buy != "Y")
												break;
										}
										else
											cout << "You don't have money to buy a Tiger" << endl;
									}
									else if(choice == "B")
									{
										if(get_money() >= 5000){
											set_losses(5000);
											cout << "Money: $" << get_money() << endl;
											z.add_Bear();
											cout << "Bears: " <<  z.get_B_num() << endl;
											cout << "Do you want to buy again (Yes = Y)? "; cin >> buy;
											if(buy != "Y")
												break;
										}
										else
											cout << "You don't have money to buy a Bear" << endl;
									}
									else if(choice == "P")
									{
										if(get_money() >= 1000){
											set_losses(1000);
											cout << "Money: $" << get_money() << endl;
											z.add_Peng();
											cout << "Pengs: " << z.get_P_num() << endl;
											cout << "Do you want to buy again (Yes = Y)? "; cin >> buy;
											if(buy != "Y")
												break;
										}
										else
											cout << "You don't have money to buy a Peng" << endl;
									}
									else if(choice == "M")
									{
										if(get_money() >= 2500){
											set_losses(2500);
											cout << "Money: $" << get_money() << endl;
											z.add_Monkey();
											cout << "Monkeys: " <<  z.get_M_num() << endl;
											cout << "Do you want to buy again (Yes = Y)? "; cin >> buy;
											if(buy != "Y")
												break;
										}
										else
											cout << "You don't have money to buy a Monkey" << endl;
									}
									else
										cout << "You need to choice" << endl;
								}
								else{
									cout << endl << endl;
									cout << "You don't have enough money to buy anything" << endl;
									cout << "You have lost and will quit the game" << endl;
									cout << endl << endl;
									break;

								}
							}
						}
						break;
					}
				}
			}
			else
			{
				cout << endl << endl;
				cout << "You don't have enough money to buy anything" << endl;
				cout << "You have lost and will quit the game" << endl;
				cout << endl << endl;
				break;
			}
			if(get_money() < 1000)
			{
				break;
			}
			z.set_A_num();
			cout << "Animals: " << z.get_A_num() << endl;

			cout << endl << endl;

			cout << "        Tigers:( " << z.get_T_num() << " )" << endl;
			z.print_Tigers();
			cout << endl;
			cout << "        Bear:( " << z.get_B_num() << " )" << endl;
			z.print_Bears();
			cout << endl;
			cout << "        Peng:( " << z.get_P_num() << " )" << endl;
			z.print_Pengs();
			cout << endl;
			cout << "        Monkey:( " << z.get_M_num() << " )" << endl;
			z.print_Monkeys();
			cout << endl;

			cout << endl << endl;
			if(z.get_A_num() != 0)
			{
				z.set_total_profit();
				cout << "Profit for Today: " << z.get_total_profit() << endl;
				set_money( get_money() + z.get_total_profit() );
				z.reset_total_profit();
				cout << "Money: " << get_money() << endl;
				cout << endl << endl;
			}
			cout << "End of Day: " << day << endl;
			day++;
			z.set_add_day();
			cout << "=======================================================" << endl;
		}
	}
	else
	{
		cout << endl << endl;
		cout << "You don't have enough money to buy anything" << endl;
		cout << "You have lost and will quit the game" << endl;
		cout << endl << endl;
	}
}