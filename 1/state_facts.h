/******************************************************
** Program: state_facts.h
** Author: Mazen Alotaibi
** Date: 04/10/2016
** Description: It has all the protypes to run the program
** Input: s, which is the number of states, filename.txt, whihc is the name of the file that wanted to be open
** Output: sort of alpha and pop of all states and all counties, and 
******************************************************/
// state reading from this (.h) file
#ifndef __fact__
#define __fact__ value

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
// stop reading
#endif 
