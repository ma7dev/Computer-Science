/******************************************************
** Program: run_facts.cpp
** Author: Mazen Alotaibi
** Date: 04/10/2016
** Description: This program reads from a file and sorts infos from it
** Input: s, which is the number of states, filename.txt, whihc is the name of the file that wanted to be open
** Output: sort of alpha and pop of all states and all counties, and 
******************************************************/
#include "state_facts.h" // use this (.h) file
using namespace std;
int main(int argc, char *argv[])
{
	int n;
	string input_check;
	float input;
	string restart;
	ifstream file;
	string line;
	string text[255];
	char* cap;
	string ask_states;
	int text_count = 0;
	if(argc == 5 && is_valid_arguments(argv, n, cap))
	{
		n = atoi(argv[2]);
		file.open(argv[4]);
		if(!(file.fail()))
		{
			state *s;
			do{
				s = create_states(n);
				 text_count = 0;
				while(!file.fail())
    			{
    				getline(file,line);
    				text[text_count]=line;
    				text_count++;
    			}
    			int state_count = 0;
				int county_count = 0;
				int number=0;
    			for(int i=0; i<text_count-1; i++)
    			{
    				string temp_arr[20];
    	   			int last_space = 0;
      				int word_count = 0;
		      		for (int j = 0; j < text[i].size(); j++) {
		        		if (text[i][j] == ' ') {
		          			temp_arr[word_count] = text[i].substr(last_space, j - last_space);
		          			word_count++;
		          			last_space = j + 1;
		        		}	
		      		}
			        temp_arr[word_count] = text[i].substr(last_space, last_space);
			        word_count++;
			        if (word_count == 3 && !(number == n))
			        {
						get_state_data(s, state_count, county_count, temp_arr);
						create_counties(s, state_count);
						state_count++;
						number++;
						county_count=0;
					}
			        else if (word_count > 3)
			        {
			       		get_county_data(s, state_count, county_count, temp_arr);
			       	    county_count++;
			       	}
			       	else if(number == n)
			       		break;
		      	}
				sort_alpha_states(s, n);
				sort_pop_states(s, n);
				for(int i=0; i<n; i++)
				{
					cout<<endl;
					cout << "State: " << s[i].name << endl;
					sort_alpha_counties(s, i);
					cout<<endl;
					sort_pop_counties(s, i);
				}
				cout<<endl;
				cout << "Highest Poplulation (State): ";
				state_pop(s, n);
				cout << "Highest Poplulation (County): ";
				county_pop(s, n);
				cout<<endl;
				for(int z=0; z>=0; z++)
				{
					cout << "Enter a Specific Amount?" << endl;
					cin >> input_check;
					if(!(is_pos_int(input_check)))
					{
						cout << "You Idiot, Try Again! (Enter an Integer)" << endl;
					}
					else
						break;		
				}
				input = atof(input_check.c_str());
				cout<<endl;
				avg_income(s, n, input);
				for (int i = 0; i < n; i++)
				{
					cout<<endl;
					cout << "State: " << s[i].name << endl;
					avg_house(s, i);
				}
				cout<<endl;
				cout << "Do You Want to Restart? (Yes-y)" << endl;
				cin >> restart;
				if(restart == "y")
				{
					for(int i=0; i>=0; i++)
					{
						cout << "How Many States? (+#)" << endl;
						cin >> ask_states;
						if(!(is_pos_int(ask_states)))
						{
							cout << "You Idiot, Try Again! (Enter an Integer)" << endl;
						}
						else
							break;		
					}
					n = atoi(ask_states.c_str());
					int baby=0;
					file.close();
					do{
						cout << "Enter File-Name? (filename.txt)" << endl;
						cin >> cap;
						file.open(cap);
						if(!(file))
						{
							cout << "You Idiot, Try Again! (Enter a Valid File-Name)" << endl;
							baby++;
						}
						else
						{
							baby=0;
							continue;
						}
					}while(baby  > 0);
				}
				else
					cout << "I will Miss You, Bye Bye  </3 .." << endl; 
			}while(restart == "y");
			delete_info(s, n);
		}
		else
			cout << "You Idiot, Try Again! (File doesn't Exits)" << endl;
		file.close();
	}
	else
		cout << "You Idiot, Try Again! (e.g. a.out -s 5 -f filename.txt)" << endl;
	return 0;
}