/******************************************************
** Program: Game.cpp
** Author: Mazen Alotaibi
** Date: 05/23/2016
** Description: where all the fuctions that needed to run the game
******************************************************/ 
#include "Game.h"
#define Forever for(;;)
/*********************************************************************
** Function: Game
** Description: constructor, to set up the class when creating
** Parameters: NONE
*********************************************************************/
Game::Game(){
	R = NULL;
	rows = 0;
	cols = 0;
	num_Events = 0;
	r_p = 0;
	c_p = 0;
	r_e = 0;
	c_e = 0;
	r_w = 0;
	c_w = 0;
	times = 0;
}
/*********************************************************************
** Function: ~Game
** Description: destructor, to delete the class when the end of the game
** Parameters: NONE
*********************************************************************/
Game::~Game(){
	for(int i = 0; i < num_Events; i++){
			delete [] E[i];

		}
	delete[] E;
	for(int i = 0; i < rows; i++){
			delete [] R[i];

		}
	delete[] R;
}
/*********************************************************************
** Function: void set_R
** Description: to create the rooms
** Parameters: int rows and int cols
*********************************************************************/
void Game::set_R(int rows, int cols){
	this->rows = rows;
	this->cols = cols;
	R = new Room*[rows];
	for(int i=0; i<rows; i++){
		R[i] = new Room[cols];
	}
}
/*********************************************************************
** Function: void set_P
** Description: to set up the player
** Parameters: Player x
*********************************************************************/
void Game::set_P(Player x){
	P = x;
}
/*********************************************************************
** Function: void get_P_info
** Description: to display player's information
** Parameters: NONE
*********************************************************************/
void Game::get_P_info(){
	cout << "+---------PLAYER-CARD------------+" << endl;
	if(P.get_is_alive() == true)
		cout << "PLayer: Alive" << endl;
	else
		cout << "Player: Dead" << endl;
	cout << "Arrows: " << P.get_num_arrows() << endl;
	if(P.get_has_gold() == true)
		cout << "Gold: Contained" << endl;
	else
		cout << "Gold: Missing" << endl;
	if(P.get_wumpus_killed() == true)
		cout << "Wumpus: Dead" << endl;
	else
		cout << "Wumpus: Alive" << endl;
	cout << "+--------------------------------+" << endl;
}
/*********************************************************************
** Function: void set_E
** Description: to create the number of 
** Parameters: string
*********************************************************************/
void Game::set_E(){
	int y =0;
	int x = (rows+cols)/2;
	num_Events = 3 + x;
	E = new Events*[num_Events];
	E[0] = new Gold[1];
	E[1] = new Wumpus[1];
	E[2] = new Escape[1];
	for(int i=0; i<x; i++){
		if(i == y && 3+i < num_Events){
			E[i+3] = new Bats[1];
			y=y+2;
		}
		else if(i == y-1 && 3+i < num_Events){
			E[i+3] = new Pit[1];
		}
	}
	for(int i=0; i<num_Events;i++)
	{
		for(int j=0; j>=0; j++){
			int r = rand() % rows;
			int c = rand() % cols;
			if(!(R[r][c].get_has_Event() == true)){
				if(i == 2){
					r_p = r;
					c_p = c;
					r_e = r;
					c_e = c;
					R[r_e][c_e].set_Event(E[i]);
				}
				else if(i == 1){
					r_w = r;
					c_w = c;
					R[r_w][c_w].set_Event(E[i]);
				}
				else{
					R[r][c].set_Event(E[i]);
				}
				break;
			}
		}	
	}
}
/*********************************************************************
** Function: set name
** Description: set name value
** Parameters: string
*********************************************************************/
void Game::wumpus_awake(){
	R[r_w][c_w].set_has_Event(false);
	for(int i=0; i>=0; i++){
		int r = rand() % rows;
		int c = rand() % cols;
		if(!(R[r][c].get_has_Event() == true)){
			r_w = r;
			c_w = c;
			R[r_w][c_w].set_Event(E[1]);
			break;
		}
	}

}
/*********************************************************************
** Function: void move
** Description: it asks the user if it wants to move, shoot, print players info, others
** Parameters: NONE
*********************************************************************/
void Game::move(){
	times++;
	string move;
	for(int i=0;i>=0;i++){
		cout << "     DIRECTIONS        ACTIONS   " << endl;
		cout << "   +----------------------------+" << endl; //Y PRINT THE NUMEBR OF STEPS IT TOOK ME
		cout << "   |    [N]              (Y)    |" << endl; //B CHEAT CODE
		cout << "   | [W]   [E]        (X)   (B) |" << endl; //X shoot
		cout << "   |    [S]              (A)    |" << endl; //A show player info
		cout << "   +----------------------------+" << endl;
		cout << "Enter an Input: ";
		cin >> move;
		if(move == "N"){
			int test = r_p;
			if(!(test - 1 < 0)){
				r_p--;
				break;
			}
			else
				cout << "You can't move to that postion, Idiot" << endl;
		}
		else if(move == "E"){
			int test = c_p;
			if(!(test + 1 == cols)){
				c_p++;
				break;
			}
			else
				cout << "You can't move to that postion, Idiot" << endl;
		}
		else if(move == "W"){
			int test = c_p;
			if(!(test - 1 < 0)){
				c_p--;
				break;
			}
			else
				cout << "You can't move to that postion, Idiot" << endl;
		}
		else if(move == "S"){
			int test = r_p;
			if(!(test + 1 == rows)){
				r_p++;
				break;
			}
			else
				cout << "You can't move to that postion, Idiot" << endl;
		}
		else if(move == "Y"){
            cout << "Number of Steps: " << times << endl;
            break;
		}
		else if(move == "X"){
			if(!(P.get_num_arrows() == 0)){
				cout << "You have chosen to shoot" << endl;
				cout << "which direction? ";cin >> move;
				if(move == "N"){
					int test = r_p;
					if(test - 3 < 0){
						if(test - 1 >= 0){
							if(R[r_p-1][c_p].get_W() == "Wumpus"){
								R[r_p-1][c_p].set_has_Event(false);
								P.set_wumpus_killed(true);
								P.lossing_arrows();
							}
						}
						if(test - 2 >= 0){
							if(R[r_p-2][c_p].get_W() == "Wumpus"){
								R[r_p-2][c_p].set_has_Event(false);
								P.set_wumpus_killed(true);
								P.lossing_arrows();
							}
						}
						if(test - 3 >= 0){
							if(R[r_p-3][c_p].get_W() == "Wumpus"){
								R[r_p-3][c_p].set_has_Event(false);
								P.set_wumpus_killed(true);
								P.lossing_arrows();
							}
						}
						else{
							cout << "BUFFF!!" << endl;
							cout << "Miss shot, your arrow is stuck on the wall" << endl;
							P.lossing_arrows();
							int x = rand() % 100;
							if(x < 75)
								wumpus_awake();
							if(r_p == r_w && c_p == c_w)
								P.set_is_alive(false);
						}
					}
					else{
						if(R[r_p-1][c_p].get_W() == "Wumpus"){
							R[r_p-1][c_p].set_has_Event(false);
							P.set_wumpus_killed(true);
							P.lossing_arrows();
						}
						else if(R[r_p-2][c_p].get_W() == "Wumpus"){
							R[r_p-2][c_p].set_has_Event(false);
							P.set_wumpus_killed(true);
							P.lossing_arrows();
						}
						else if(R[r_p-3][c_p].get_W() == "Wumpus"){
							R[r_p-3][c_p].set_has_Event(false);
							P.set_wumpus_killed(true);
							P.lossing_arrows();
						}
						else{
							cout << "Miss shot, your arrow is on the floor" << endl;
							P.lossing_arrows();
							int x = rand() % 100;
							if(x < 75)
								wumpus_awake();
							if(r_p == r_w && c_p == c_w)
								P.set_is_alive(false);
						}
					}
					break;
				}
				else if(move == "E"){
					int test = c_p;
					if(test + 3 >= cols){
						if(test + 1 < cols){
							if(R[r_p][c_p+1].get_W() == "Wumpus"){
								R[r_p][c_p+1].set_has_Event(false);
								P.set_wumpus_killed(true);
								P.lossing_arrows();
							}
						}
						if(test + 2 < cols){
							if(R[r_p][c_p+2].get_W() == "Wumpus"){
								R[r_p][c_p+2].set_has_Event(false);
								P.set_wumpus_killed(true);
								P.lossing_arrows();
							}
						}
						if(test + 3 < cols){
							if(R[r_p][c_p+3].get_W() == "Wumpus"){
								R[r_p][c_p+3].set_has_Event(false);
								P.set_wumpus_killed(true);
								P.lossing_arrows();
							}
						}
						else{
							cout << "BUFFF!!" << endl;
							cout << "Miss shot, your arrow is stuck on the wall" << endl;
							P.lossing_arrows();
							int x = rand() % 100;
							if(x < 75)
								wumpus_awake();
						}
						if(r_p == r_w && c_p == c_w)
							P.set_is_alive(false);
					}
					else{
						if(R[r_p][c_p+1].get_W() == "Wumpus"){
							R[r_p][c_p+1].set_has_Event(false);
							P.set_wumpus_killed(true);
							P.lossing_arrows();
						}
						else if(R[r_p][c_p+2].get_W() == "Wumpus"){
							R[r_p][c_p+2].set_has_Event(false);
							P.set_wumpus_killed(true);
							P.lossing_arrows();
						}
						else if(R[r_p][c_p+3].get_W() == "Wumpus"){
							R[r_p][c_p+3].set_has_Event(false);
							P.set_wumpus_killed(true);
							P.lossing_arrows();
						}
						else{
							cout << "Miss shot, your arrow is on the floor" << endl;
							P.lossing_arrows();
							int x = rand() % 100;
							if(x < 75)
								wumpus_awake();
							if(r_p == r_w && c_p == c_w)
								P.set_is_alive(false);
						}
					}
					break;
				}
				else if(move == "W"){
					int test = c_p;
					if(test - 3 < 0){
						if(test -1 >= 0){
							if(R[r_p][c_p-1].get_W() == "Wumpus"){
								R[r_p][c_p-1].set_has_Event(false);
								P.set_wumpus_killed(true);
								P.lossing_arrows();
							}
						}
						if(test -2 >= 0){
							if(R[r_p][c_p-2].get_W() == "Wumpus"){
								R[r_p][c_p-2].set_has_Event(false);
								P.set_wumpus_killed(true);
								P.lossing_arrows();
							}
						}
						if(test - 3 >=0){
							if(R[r_p][c_p-3].get_W() == "Wumpus"){
								R[r_p][c_p-3].set_has_Event(false);
								P.set_wumpus_killed(true);
								P.lossing_arrows();
							}
						}
						else{
							cout << "BUFFF!!" << endl;
							cout << "Miss shot, your arrow is stuck on the wall" << endl;
							P.lossing_arrows();
							int x = rand() % 100;
							if(x < 75)
								wumpus_awake();
							if(r_p == r_w && c_p == c_w)
								P.set_is_alive(false);
						}
					}
					else{
						if(R[r_p][c_p-1].get_W() == "Wumpus"){
							R[r_p][c_p-1].set_has_Event(false);
							P.set_wumpus_killed(true);
							P.lossing_arrows();
						}
						else if(R[r_p][c_p-2].get_W() == "Wumpus"){
							R[r_p][c_p-2].set_has_Event(false);
							P.set_wumpus_killed(true);
							P.lossing_arrows();
						}
						else if(R[r_p][c_p-3].get_W() == "Wumpus"){
							R[r_p][c_p-3].set_has_Event(false);
							P.set_wumpus_killed(true);
							P.lossing_arrows();
						}
						else{
							cout << "Miss shot, your arrow is on the floor" << endl;
							P.lossing_arrows();
							int x = rand() % 100;
							if(x < 75)
								wumpus_awake();
							if(r_p == r_w && c_p == c_w)
								P.set_is_alive(false);
						}
					}
					break;
				}
				else if(move == "S"){
					int test = r_p;
					if(test + 3 >= rows){
						if(test + 1 < rows){
							if(R[r_p+1][c_p].get_W() == "Wumpus"){
								R[r_p+1][c_p].set_has_Event(false);
								P.set_wumpus_killed(true);
								P.lossing_arrows();
							}
						}
						if(test +2 < rows){
							if(R[r_p+2][c_p].get_W() == "Wumpus"){
								R[r_p+2][c_p].set_has_Event(false);
								P.set_wumpus_killed(true);
								P.lossing_arrows();
							}
						}
						if(test + 3 < rows){
							if(R[r_p+3][c_p].get_W() == "Wumpus"){
								R[r_p+3][c_p].set_has_Event(false);
								P.set_wumpus_killed(true);
								P.lossing_arrows();
							}
						}
						else{
							cout << "BUFFF!!" << endl;
							cout << "Miss shot, your arrow is stuck on the wall" << endl;
							P.lossing_arrows();
							int x = rand() % 100;
							if(x < 75)
								wumpus_awake();
							if(r_p == r_w && c_p == c_w)
								P.set_is_alive(false);
						}
					}
					else{
						if(R[r_p+1][c_p].get_W() == "Wumpus"){
							R[r_p+1][c_p].set_has_Event(false);
							P.set_wumpus_killed(true);
							P.lossing_arrows();
						}
						else if(R[r_p+2][c_p].get_W() == "Wumpus"){
							R[r_p+2][c_p].set_has_Event(false);
							P.set_wumpus_killed(true);
							P.lossing_arrows();
						}
						else if(R[r_p+3][c_p].get_W() == "Wumpus"){
							R[r_p+3][c_p].set_has_Event(false);
							P.set_wumpus_killed(true);
							P.lossing_arrows();
						}
						else{
							cout << "Miss shot, your arrow is on the floor" << endl;
							P.lossing_arrows();
							int x = rand() % 100;
							if(x < 75)
								wumpus_awake();
							if(r_p == r_w && c_p == c_w)
								P.set_is_alive(false);
						}
					}
					break;
				}
				else
					cout << "You can't shoot, Idiot" << endl;
			}
			else
				cout << "You don't have any arrows, Idiot" << endl;
		}
		else if(move == "B"){
			cout << "B....."; cin >> move;
			if(move == "A"){
				cout << "BA...."; cin >> move;
				if(move == "N"){
					cout << "BAN..."; cin >> move;
					if(move == "A"){
						cout << "BANA.."; cin >> move;
						if(move == "N"){
							cout << "BANAN."; cin >> move;
							if(move == "A"){
								cout << "BANANA!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
								print_whole_Grid();
								break;
							}
						}
					}
				}
			}
		}
		else if(move == "A"){
			get_P_info();
			break;
		}
		else
			cout << "You Idiot, Try Again" << endl;
	}
}
/*********************************************************************
** Function: void set_Escape
** Description: it will setup escape when the user is alive, has the gold, and killed the wumpus
** Parameters: NONE
*********************************************************************/
void Game::set_Escape(){
	if(P.get_has_gold() == true && P.get_wumpus_killed() == true && P.get_is_alive() == true)
		R[r_e][c_e].set_has_Event(true);
	else
		R[r_e][c_e].set_has_Event(false);
}
/*********************************************************************
** Function: bool player_killed
** Description: to check if player is alive or not
** Parameters: NONE
*********************************************************************/
bool Game::player_Killed(){
	if(P.get_is_alive() == true)
		return true;
	else
		return false;
}
/*********************************************************************
** Function: void check_around
** Description: this fuction works when the player is in a postition and it will reads everything around it
** Parameters: NONE
*********************************************************************/
void Game::check_Around(){
	int i = 0;
	cout << endl;
	cout << "+------------MESSAGES------------+" << endl;
	if(r_p + 1 < rows){
		if(R[r_p+1][c_p].get_has_Event() == true){
			cout << "| " << R[r_p+1][c_p].get_M() << '\t' << " |" << endl;
			i++;
		}
	}
	if(r_p + 1 < rows && c_p + 1 < cols){
		if(R[r_p+1][c_p+1].get_has_Event() == true){
			cout << "| " << R[r_p+1][c_p+1].get_M() << '\t' << " |" << endl;
			i++;
		}
	}
	if(r_p + 1 < rows && c_p - 1 >= 0){
		if(R[r_p+1][c_p-1].get_has_Event() == true){
			cout << "| " << R[r_p+1][c_p-1].get_M() << '\t' << " |" << endl;
			i++;
		}
	}
	if(r_p - 1 >= 0){
		if(R[r_p-1][c_p].get_has_Event() == true){
			cout << "| " << R[r_p-1][c_p].get_M() << '\t' << " |" << endl;
			i++;
		}
	}
	if(r_p - 1 >= 0 && c_p + 1 < cols){
		if(R[r_p-1][c_p+1].get_has_Event() == true){
			cout << "| " << R[r_p-1][c_p+1].get_M() << '\t' << " |" << endl;
			i++;
		}
	}
	if(r_p - 1 >= 0 && c_p -1 >= 0){
		if(R[r_p-1][c_p-1].get_has_Event() == true){
			cout << "| " << R[r_p-1][c_p-1].get_M() << '\t' << " |" << endl;
			i++;
		}
	}
	if(c_p + 1 < cols){
		if(R[r_p][c_p+1].get_has_Event() == true){
			cout << "| " << R[r_p][c_p+1].get_M() << '\t' << " |" << endl;
			i++;
		}
	}
	if(c_p - 1 >= 0){
		if(R[r_p][c_p-1].get_has_Event() == true){
			cout << "| " << R[r_p][c_p-1].get_M() << '\t' << " |" << endl;
			i++;
		}
	}
	if(i == 0)
	cout << "|                                |" << endl; 
	cout << "+--------------------------------+" << endl;
	cout << endl;
}
/*********************************************************************
** Function: void in_Room
** Description: make the action when the player inside a room that has an event
** Parameters: NONE
*********************************************************************/
void Game::in_Room(){
	if(R[r_p][c_p].get_has_Event() == true){
        if(R[r_p][c_p].get_W() == "Wumpus"){
        	R[r_p][c_p].Action();
        	P.set_is_alive(false);
        }
        else if(R[r_p][c_p].get_W() == "Pit"){
        	R[r_p][c_p].Action();
        	P.set_is_alive(false);
        }
        else if(R[r_p][c_p].get_W() == "Bats"){
        	R[r_p][c_p].Action();
			int r = rand() % rows;
			int c = rand() % cols;
			r_p = r;
			c_p = c;
			in_Room();
        }
        else if(R[r_p][c_p].get_W() == "Gold"){
        	R[r_p][c_p].Action();
        	P.set_has_gold(true);
        	R[r_p][c_p].set_has_Event(false);
        }
        else if(R[r_p][c_p].get_W() == "Escape"){
        	R[r_p][c_p].Action();
        }
	}
}
/*********************************************************************
** Function: void print_whole_Grid
** Description: to print the grid with all the events
** Parameters: NONE
*********************************************************************/
void Game::print_whole_Grid(){
	cout << "    ";
    for(int i=0;i<cols;i++)
        cout << "___ ";
    cout << endl;
    for(int i=0;i<rows;i++)
    {
    	cout << "   |";
        for(int j=0;j<cols;j++)
        {
            if(R[i][j].get_has_Event() == true){
            	if(R[i][j].get_W() == "Wumpus")
            		cout << "_W_|";
                else if(R[i][j].get_W() == "Pit")
            		cout << "_P_|";
            	else if(R[i][j].get_W() == "Bats")
            		cout << "_B_|";
            	else if(R[i][j].get_W() == "Gold")
            		cout << "_G_|";
            	else if(R[i][j].get_W() == "Escape")
            		cout << "_E_|";
            }
            else if(i == r_p && j == c_p)
            	cout << "_@_|";
            else
               	cout << "___|";
            if(j==(cols-1))
                cout << endl;
        }
    }
    cout << endl;    
}
/*********************************************************************
** Function: void print_Grid
** Description: to print the grid with all the events hidden
** Parameters: NONE
*********************************************************************/
void Game::print_Grid(){
	cout << "    ";
    for(int i=0;i<cols;i++)
        cout << "___ ";
    cout << endl;
    for(int i=0;i<rows;i++)
    {
    	cout << "   |";
        for(int j=0;j<cols;j++)
        {
			if(i == r_p && j == c_p)
            	cout << "_@_|";
            else
               	cout << "___|";
            if(j==(cols-1))
                cout << endl;
        }
    }
    cout << endl;    
}
/*********************************************************************
** Function: bool check_if_player_won
** Description: it checks if the player is alive, killed the wumpus, has the gold and escaped the maze
** Parameters: NONE
*********************************************************************/
bool Game::check_if_player_won(){
	if(P.get_wumpus_killed() == true && P.get_is_alive() == true && P.get_has_gold() == true && r_p == r_e && c_p == c_e)
		return true;
	else
		return false;
}
/*********************************************************************
** Function: int AI_Action
** Description: Here where all the magic happens
** Parameters: NONE
*********************************************************************/
int Game::AI_Action(){
	int r = r_p;
	int c = c_p;
	int N =-1, S=-1, E=-1, W=-1;
	if(r_p + 1 < rows){
		if(R[r_p+1][c_p].get_has_Event() == true){
			if(R[r_p+1][c_p].get_W() == "Gold"){
				r_p++;
				return 0;
			}
			else if(R[r_p+1][c_p].get_W() == "Wumpus"){
				R[r_p+1][c_p].set_has_Event(false);
				P.set_wumpus_killed(true);
				P.lossing_arrows();
				r_p++;
				return 0;
			}
			else if(R[r_p+1][c_p].get_W() == "Escape"){
				r_p++;
				return 0;
			}
			else
				S = 1;
		}
		else
			S = 0;
	}
	if(r_p - 1 >= 0 && r == r_p && c == c_p){
		if(R[r_p-1][c_p].get_has_Event() == true){
			if(R[r_p-1][c_p].get_W() == "Gold"){
				r_p--;
				return 0;
			}
			else if(R[r_p-1][c_p].get_W() == "Wumpus"){
				R[r_p-1][c_p].set_has_Event(false);
				P.set_wumpus_killed(true);
				P.lossing_arrows();
				r_p--;
				return 0;
			}
			else if(R[r_p-1][c_p].get_W() == "Escape"){
				r_p--;
				return 0;
			}
			else
				N = 1;
		}
		else
			N = 0;
	}
	if(c_p + 1 < cols && r == r_p && c == c_p){
		if(R[r_p][c_p+1].get_has_Event() == true){
			if(R[r_p][c_p+1].get_W() == "Gold"){
				c_p++;
				return 0;
			}
			else if(R[r_p][c_p+1].get_W() == "Wumpus"){
				R[r_p][c_p+1].set_has_Event(false);
				P.set_wumpus_killed(true);
				P.lossing_arrows();
				c_p++;
				return 0;
			}
			else if(R[r_p][c_p+1].get_W() == "Escape"){
				c_p++;
				return 0;
			}
			else
				E = 1;
		}
		else
			E =0;
	}
	if(c_p - 1 >= 0 && r == r_p && c == c_p){
		if(R[r_p][c_p-1].get_has_Event() == true){
			if(R[r_p][c_p-1].get_W() == "Gold"){
				c_p--;
				return 0;
			}
			else if(R[r_p][c_p-1].get_W() == "Wumpus"){
				R[r_p][c_p-1].set_has_Event(false);
				P.set_wumpus_killed(true);
				P.lossing_arrows();
				c_p--;
				return 0;
			}
			else if(R[r_p][c_p-1].get_W() == "Escape"){
				c_p--;
				return 0;
			}
			else
				W = 1;
		}
		else
			W = 0;
	}
	for(int i=0; i>=0; i++){
		int random = rand() %4;
		if( E == 0 && random == 0){
			c_p++;
			return 0;
		}
		else if(S==0 && random == 1){
			r_p++;
			return 0;
		}
		else if(N==0 && random == 2){
			r_p--;
			return 0;
		}
		else if(W==0 && random == 3){
			c_p--;
			return 0;
		}
	}
	return 0;
}
/*********************************************************************
** Function: void player_statues
** Description: just read a random message from a file if the player won or lose
** Parameters: bool s
*********************************************************************/
void Game::player_statues(bool s){
	int text_count;
	string text[255];
	string line;
	ifstream file;

	file.open("quotes.txt");
	while(!file.fail())
    {
    	getline(file,line);
    	text[text_count]=line;
    	text_count++;
    }
    file.close();

    if(s == true){
    	int num = rand() % 5+5;
		cout << text[num] << endl << endl;
    }
    else{
    	int num = rand() % 5;
		cout << text[num] << endl << endl;
    }
}