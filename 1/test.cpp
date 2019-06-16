/******************************************************
** Program: run_facts.cpp
** Author: Mazen Alotaibi
** Date: 04/10/2016
** Description: This program reads from a file and sorts infos from it
** Input: s, which is the number of states, filename.txt, whihc is the name of the file that wanted to be open
** Output: sort of alpha and pop of all states and all counties, and 
******************************************************/
#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <cctype>
#include <cstdio>

using namespace std;

struct county{
	string name;
	string *b;
	int pop;
	int cities;
	float avg_income;
	float avg_house;
};
struct state{
	string name;
	county *c;
	int pop;
	int counties;
};
state * create_states(int );
void get_state_data(state *, int , int , string *);
county * create_counties(state *, int );
void get_county_data(state *, int , int , string *);
void delete_info(state *, int );
void sort_alpha_states(state *, int );
void sort_pop_states(state *, int );
void sort_alpha_counties(state *, int );
void sort_pop_counties(state *, int );
void state_pop(state *, int );
void county_pop(state *, int );
void avg_income(state *, int , float );
void avg_house(state *, int );
bool is_valid_arguments(char *[], int &, char* &);
bool is_pos_int(string );


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
/*********************************************************************
 ** Function: create_states
 ** Description: create number of states
 ** Parameters: n, which is number os states that have been entered from the user
 ** Pre-Conditions:  int
 ** Post-Conditions: returning s, which is array that will store data in it
 *********************************************************************/
state * create_states(int n)
{
	state *s;
	s=new state[n];
	return s;
}
/*********************************************************************
 ** Function: get_state_data
 ** Description: get data for each state
 ** Parameters: s, which is the state array that has all the data about the state, state_count, county_count and temp_arr, which are variables will be used to run the function
 ** Pre-Conditions: state *s, int state_count, int county_count, string *temp_arr
 ** Post-Conditions: get data from the file and save it
 *********************************************************************/
void get_state_data(state *s, int state_count, int county_count, string *temp_arr)
{
	s[state_count].name = temp_arr[0];
    s[state_count].pop = atoi(temp_arr[1].c_str());
    s[state_count].counties = (atoi(temp_arr[2].c_str()));
	s[state_count].c= create_counties(s, state_count);
}
/*********************************************************************
 ** Function: create_counties
 ** Description: create number of counties
 ** Parameters: s, which is the state array that has all the data about the state, state_count, which is number of states counted
 ** Pre-Conditions: state *s, int state_count
 ** Post-Conditions: returning s[state_count].c, which is array that will store data in it
 *********************************************************************/
county * create_counties(state *s, int state_count)
{
	s[state_count].c=new county[s[state_count].counties ];
	return s[state_count].c;
}
/*********************************************************************
 ** Function: get_county_data
 ** Description: get data for each state
 ** Parameters: s, which is the state array that has all the data about the state, state_count, county_count and temp_arr, which are variables will be used to run the function
 ** Pre-Conditions: state *s, int state_count, int county_count, string *temp_arr
 ** Post-Conditions: get data from the file and save it
 *********************************************************************/
void get_county_data(state *s, int state_count, int county_count, string *temp_arr)
{
	s[state_count-1].c[county_count].name = temp_arr[0];
	s[state_count-1].c[county_count].pop = atoi(temp_arr[1].c_str());
	s[state_count-1].c[county_count].avg_income = (float)atof(temp_arr[2].c_str());
	s[state_count-1].c[county_count].avg_house = (float)atof(temp_arr[3].c_str());
	s[state_count-1].c[county_count].cities = atoi(temp_arr[4].c_str());
	s[state_count-1].c[county_count].b=new string[s[state_count-1].c[county_count].cities];
	for(int i=0; i<s[state_count-1].c[county_count].cities; i++)
	    s[state_count-1].c[county_count].b[i]=temp_arr[5+i];
}
/*********************************************************************
 ** Function: delete_info
 ** Description: delete all the arrays that have been created to free the memory
 ** Parameters: s, which is the state array that has all the data about the state, n, which is number os states that have been entered from the user
 ** Pre-Conditions: state *s, int n
 ** Post-Conditions: free the memory
 *********************************************************************/
void delete_info(state *s, int n)
{
	for(int i=0; i<n; i++)
		for(int j=0; j<s[i].counties; j++)
			delete [] s[i].c[j].b;
	for(int i=0; i<n; i++)
		delete [] s[i].c;
	delete [] s;
}
/*********************************************************************
 ** Function: sort_alpha_states
 ** Description: to sort all the states alphabetically
 ** Parameters: s, which is the state array that has all the data about the state, n, which is number os states that have been entered from the user
 ** Pre-Conditions: state *s1, int n
 ** Post-Conditions: print all the states alphabetically
 *********************************************************************/
void sort_alpha_states(state *s1, int n)
{
	int *index;
	index = new int[n];
	for(int i=0; i < n; i++)
	{
		index[i]=i;
	}
	for(int i=0; i < n-1; i++)
		for(int j=i+1; j < n; j++)
		{
			int temp;
			if(s1[index[i]].name > s1[index[j]].name)
			{
				temp = index[i];
				index[i] = index[j];
				index[j] = temp;

			}
		}
	cout<<endl;
	cout << "Sort States Alphabetically (A-Z):" << endl;
	for(int i=0; i < n; i++)
	{
		cout << "    " << s1[index[i]].name << '\t' << endl;
	}
	delete [] index;
}
/*********************************************************************
 ** Function: sort_pop_states
 ** Description: to sort all the states by poplulation from highest to lowest
 ** Parameters: s1, which is the state array that has all the data about the state, n, whihc is the number of states
 ** Pre-Conditions: state *s1, int n
 ** Post-Conditions: print all the states by poplulation from highest to lowest
 *********************************************************************/
void sort_pop_states(state *s1, int n)
{
	state temp;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n-1-i; j++) {
			if (s1[j].pop < s1[j+1].pop) {
				temp = s1[j];
				s1[j] = s1[j+1];
				s1[j+1] = temp;
			}
		}

	}
	cout<<endl;
	cout<<"Sort States Poplulation (Highest-Lowest):" << endl;

	for (int i = 0; i < n; i++) {
		cout << "    " << s1[i].pop << '\t' << " <= (" << s1[i].name << ")" << '\t' << endl;
	}
}
/*********************************************************************
 ** Function: sort_alpha_counties
 ** Description: to sort all the counties alphabetically
 ** Parameters: s, which is the state array that has all the data about the state, n, which is number os states that have been entered from the user
 ** Pre-Conditions: state *s1, int n
 ** Post-Conditions: print all the counties alphabetically
 *********************************************************************/
void sort_alpha_counties(state *s1, int s)
{
	int *index;
	index = new int[s1[s].counties];
	for(int i=0; i < s1[s].counties; i++)
	{
		index[i]=i;
	}
	for(int i=0; i < s1[s].counties-1; i++)
		for(int j=i+1; j < s1[s].counties; j++)
		{
			int temp;
			if(s1[s].c[index[i]].name > s1[s].c[index[j]].name)
			{
				temp = index[i];
				index[i] = index[j];
				index[j] = temp;

			}
		}
	cout<<"    Sort Counties Alphabetically (A-Z):" << endl;
	for(int i=0; i < s1[s].counties; i++)
	{
		cout << "        " << s1[s].c[index[i]].name << '\t' << endl;
	}
	delete [] index;
}
/*********************************************************************
 ** Function: sort_pop_counties
 ** Description: to sort all the counties by poplulation from highest to lowest
 ** Parameters: s1, which is the state array that has all the data about the state, n, whihc is the number of states
 ** Pre-Conditions: state *s1, int n
 ** Post-Conditions: print all the counties by poplulation from highest to lowest
 *********************************************************************/
void sort_pop_counties(state *s1, int s)
{
	county temp;
	for (int i = 0; i < s1[s].counties; i++) {
		for (int j = 0; j < s1[s].counties-1-i; j++) {
			if (s1[s].c[j].pop < s1[s].c[j+1].pop) {
				temp = s1[s].c[j];
				s1[s].c[j] = s1[s].c[j+1];
				s1[s].c[j+1] = temp;
			}
		}

	}
	cout<<"    Sort Counties Poplulation (Highest-Lowest):" << endl;

	for (int i = 0; i < s1[s].counties; i++) {
		cout << "        " << s1[s].c[i].pop << '\t' << " <= (" << s1[s].c[i].name << ")" << '\t' << endl;
	}
}
/*********************************************************************
 ** Function: state_pop
 ** Description: to print the state that has the highest population
 ** Parameters: s1, which is the state array that has all the data about the state, n, whihc is the number of states
 ** Pre-Conditions: state *s1, int n
 ** Post-Conditions: print the state that has the highest population
 *********************************************************************/
void state_pop(state *s1, int n)
{
	int temp = 0;
	state t;
	for(int i=0; i <n; i++)
	{
		if(s1[i].pop>temp)
		{
            temp=s1[i].pop;
            t.name=s1[i].name;
        }
	}
	cout << t.name << " " << temp << endl;
}
/*********************************************************************
 ** Function: county_pop
 ** Description: to print the counties that has the highest population
 ** Parameters: s1, which is the state array that has all the data about the state, n, whihc is the number of states
 ** Pre-Conditions: state *s1, int n
 ** Post-Conditions: print the counties that has the highest population
 *********************************************************************/
void county_pop(state *s1, int n)
{
	int temp = 0;
	county t;
	for(int i=0; i <n; i++)
		for(int j=0; j<s1[i].counties; j++)
		{
			if(s1[i].c[j].pop>temp)
			{
            	temp=s1[i].c[j].pop;
            	t.name=s1[i].c[j].name;
            }
        }
        cout << t.name << " " << temp << endl;
}
/*********************************************************************
 ** Function: avg_income
 ** Description: to print the counties that have higher average income than what the user input
 ** Parameters: s1, which is the state array that has all the data about the state, n, whihc is the number of states, input, which is the amount from the user
 ** Pre-Conditions: state *s1, int n, float input
 ** Post-Conditions: print the counties that have higher average income than what the user input
 *********************************************************************/
void avg_income(state *s1, int n, float input)
{
	county *t;
	int add = 0;
	for(int i=0; i <n; i++)
		for(int j=0; j<s1[i].counties; j++)
		{
			if(s1[i].c[j].avg_income>input)
			{
            	add++;
            }
        }
    t=new county[add];
    int start =0;
    for(int i=0; i <n; i++)
		for(int j=0; j<s1[i].counties; j++)
		{
			if(s1[i].c[j].avg_income>input)
			{
            	t[start].avg_income=s1[i].c[j].avg_income;
            	t[start].name=s1[i].c[j].name;
            	start++;
            }
        }
	county temp;
	for(int i=0; i <add; i++)
		for (int j = 0; j < add-1-i; j++) {
			if (t[j].avg_income < t[j+1].avg_income) {
				temp = t[j];
				t[j] = t[j+1];
				t[j+1] = temp;
			}
		}
	cout<<endl;
	cout<<"Sort Counties with Higher than $" << input << " Average Income that is:" << endl;

	for (int i = 0; i < add; i++)
		cout << "   $"<<t[i].avg_income << '\t' << " <= (" << t[i].name << ")" << '\t' << endl;
	delete [] t;
}
/*********************************************************************
 ** Function: avg_house
 ** Description: to print the counties that has the highest aveage household
 ** Parameters: s1, which is the state array that has all the data about the state, n, whihc is the number of states
 ** Pre-Conditions: state *s1, int n
 ** Post-Conditions: print the counties that has the highest aveage household
 *********************************************************************/
void avg_house(state *s1, int s)
{
	county temp;
	for (int i = 0; i < s1[s].counties; i++) {
		for (int j = 0; j < s1[s].counties-1-i; j++) {
			if (s1[s].c[j].avg_house < s1[s].c[j+1].avg_house) {
				temp = s1[s].c[j];
				s1[s].c[j] = s1[s].c[j+1];
				s1[s].c[j+1] = temp;
			}
		}

	}
	cout<<"   Sort Counties Average Household (Highest-Lowest):" << endl;

	for (int i = 0; i < s1[s].counties; i++) {
		cout << "      $"<<s1[s].c[i].avg_house << '\t' << " <= (" << s1[s].c[i].name << ")" << '\t' << endl;
	}
}
/*********************************************************************
 ** Function: is_valid_arguments
 ** Description: to check the command-line
 ** Parameters: argv, which is the user's input when using the command-line, n, which is the number of states, cap, which is save the file name
 ** Pre-Conditions: char *argv[], int &n, char* &cap
 ** Post-Conditions: return if it true, which is a good input, or it is false, which is bad input
 *********************************************************************/
bool is_valid_arguments(char *argv[], int &n, char* &cap)
{
	int r=0;
	int f=0;
	for (int count=0; count < 5; ++count)
        {
            if (!(r > 1 || f > 1))
            {
                if(strcmp (argv[count],"-s")==0)
                { n = atoi (argv[count+1]); r = r + 1; }
                else if(strcmp (argv[count],"-f")==0)
                { cap = (argv[count+1]); f = f + 1; }
            }	
		}
	if(!(r == 1 && f == 1))
    	return false;
    else
    	return true;
}
/*********************************************************************
 ** Function: is_pos_int
 ** Description: to check if the input from the user an postive int or not
 ** Parameters:  str, which is user's input when asked
 ** Pre-Conditions: string str
 ** Post-Conditions: return if it true, which is a good input, or it is false, which is bad input
 *********************************************************************/
bool is_pos_int(string str)
{
	for(int i=0; i<str.length(); i++)
	{
		if(!(str.at(i)>='0' && str.at(i)<='9'))
			return false;
	}
	return true;
}