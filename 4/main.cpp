/******************************************************
** Program: main.cpp
** Author: Mazen Alotaibi
** Date: 05/23/2016
** Description: where the game runs
******************************************************/ 
#include "Game.h"
using namespace std;
/*********************************************************************
** Function: int main
** Description: game runs
** Parameters: int argc, which is size of command line, and char* argv[], which is the command line
*********************************************************************/
int main(int argc, char *argv[]){
    srand(unsigned(time(NULL)));
    cout << string(200, '\n');
    Game Board;
    Player P1;
    int arrows;
    int rows, cols;
    int r =0;
    int c=0;
    #ifdef ARW
    cout << "How many arrows? "; cin >> arrows; P1.set_num_arrows(arrows);
    Board.set_P(P1);
    #endif
    if(argc == 5)
    {
        for (int count=0; count < argc; count++)
        {
            if (!(r >1 || c > 1))
            {
                if(strcmp (argv[count],"-r") == 0){
                    rows = atoi (argv[count+1]);
                    r = r + 1; 
                }
                else if(strcmp (argv[count],"-c") == 0){
                    cols = atoi (argv[count+1]);
                    c = c + 1;
                }
            }
            else{
                cout << "You idiot, try again! (e.g. a.out -r 5 -c 5)" << endl; 
                return 0;
            }
        }
    }
    if(!(r == 1 && c == 1)){
        cout << "You idiot, try again! (e.g. a.out -r 4 -c 4)" << endl; 
        return 0;
    }
    if(!(rows >= 4 && cols >=4)){
        cout << "You idiot, try again! (Size need to be >= 4)" << endl; 
        return 0;
    }
    Board.set_R(rows, cols);
    Board.get_P_info();
    Board.set_E();
    Board.set_Escape();
    #ifdef ALL
        Board.print_whole_Grid();
    #endif
    Board.print_Grid();
    #ifdef AI
        int times = 0;
        for(int i=0; i>=0; i++)
        {
            times = times + 1;
            cout << "Number of Steps: " << times << endl;
            Board.set_Escape();
            Board.check_Around();
            Board.AI_Action();
            Board.in_Room();
            if(Board.player_Killed() == true && Board.check_if_player_won() == false){
                #ifdef ALL
                    Board.print_whole_Grid();
                #endif
                Board.print_Grid();
            }
            else if(Board.check_if_player_won() == true){
                cout << "AI have won the game!!!!" << endl;
                cout << endl;
                Board.player_statues(true);
                break;
            }
            else{
                cout << "AI have lost the game! Idiot" << endl;
                cout << endl;
                Board.player_statues(false);
                break;
            }
        }
        return 0;
    #endif
    for(int i=0; i>=0;i++)
    {
        Board.check_Around();
        Board.move();
        Board.in_Room();
        if(Board.player_Killed() == true && Board.check_if_player_won() == false){
            Board.set_Escape();
            #ifdef ALL
                Board.print_whole_Grid();
            #endif
            Board.print_Grid();
        }
        else if(Board.check_if_player_won() == true){
            cout << "You have won the game!!!!" << endl;
            cout << endl;
            Board.player_statues(true);
            break;
        }
        else{
            cout << "You have lost the game! Idiot" << endl;
            cout << endl;
            Board.player_statues(false);
            break;
        }
    }
    return 0;
}