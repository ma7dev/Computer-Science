/******************************************************
** Program: Zoo.cpp
** Author: Mazen Alotaibi
** Date: 05/08/2016
** Description: This is the zoo class which has all the animals and the functionality of using them
******************************************************/ 
#include "Zoo.h"
/*********************************************************************
** Function: constructor
** Description: set defult values
** Parameters: None
*********************************************************************/
Zoo::Zoo(){
	A[0] = NULL;
	A[1] = NULL;
	A[2] = NULL;
	A[3] = NULL;
	T_num = 0;
	B_num = 0;
	P_num = 0;
	M_num = 0;
	A_num = 0;
}
/*********************************************************************
** Function: destructor
** Description: delete all the dynamic arrays
** Parameters: None
*********************************************************************/
Zoo::~Zoo(){
	if(T_num > 0)
		delete[] A[0];
	if(B_num > 0)
		delete[] A[1];	
	if(P_num > 0)
		delete[] A[2];
	if(M_num > 0)
		delete[] A[3];
}
/*********************************************************************
** Function: set buy
** Description: set buy value
** Parameters: int
*********************************************************************/
void Zoo::set_T_num(int t){
	T_num = t;
}
/*********************************************************************
** Function: set buy
** Description: set buy value
** Parameters: int
*********************************************************************/
void Zoo::set_B_num(int b){
	B_num = b;
}
/*********************************************************************
** Function: set buy
** Description: set buy value
** Parameters: int
*********************************************************************/
void Zoo::set_P_num(int p){
	P_num = p;
}
/*********************************************************************
** Function: set buy
** Description: set buy value
** Parameters: int
*********************************************************************/
void Zoo::set_M_num(int m){
	M_num = m;
}
/*********************************************************************
** Function: set buy
** Description: set buy value
** Parameters: int
*********************************************************************/
void Zoo::set_add_day(){
	for(int i=0; i<T_num; i++)
	{
		Tiger B;
		A[0][i].set_age(A[0][i].get_age() + 1);
		if(A[0][i].get_age() == 3)
		{
			cout << "Tiger: " << i + 1 << " became adult" << endl;
			A[0][i] = B;
		}
		else if(A[0][i].get_age() == A[0][i].get_lifespan())
		{
			cout << "Tiger: " << i + 1 << " is dead (Because reached lifespan)" << endl;
			A[0][i].set_alive(false);
			remove_Tiger();
		}
	}
	for(int i=0; i<B_num; i++)
	{
		Bear B;
		A[1][i].set_age(A[1][i].get_age() + 1);
		if(A[1][i].get_age() == 3)
		{
			cout << "Bear: " << i + 1 << " became adult" << endl;
			A[1][i] = B;
		}
		else if(A[1][i].get_age() == A[1][i].get_lifespan())
		{
			cout << "Bear: " << i + 1 << " is dead (Because reached lifespan)" << endl;
			A[1][i].set_alive(false);
			remove_Tiger();
		}
	}
	for(int i=0; i<P_num; i++)
	{
		Peng B;
		A[2][i].set_age(A[2][i].get_age() + 1);
		if(A[2][i].get_age() == 3)
		{
			cout << "Peng: " << i + 1 << " became adult" << endl;
			A[2][i] = B;
		}
		else if(A[2][i].get_age() == A[2][i].get_lifespan())
		{
			cout << "Peng: " << i + 1 << " is dead (Because reached lifespan)" << endl;
			A[2][i].set_alive(false);
			remove_Tiger();
		}
	}
	for(int i=0; i<M_num; i++)
	{
		Monkey M;
		A[3][i].set_age(A[3][i].get_age() + 1);
		if(A[3][i].get_age() == 3)
		{
			cout << "Monkey: " << i + 1 << " became adult" << endl;
			A[3][i] = M;
		}
		else if(A[3][i].get_age() == A[3][i].get_lifespan())
		{
			cout << "Monkey: " << i + 1 << " is dead (Because reached lifespan)" << endl;
			A[3][i].set_alive(false);
			remove_Monkey();
		}
	}
}
/*********************************************************************
** Function: set buy
** Description: set buy value
** Parameters: int
*********************************************************************/
void Zoo::set_A_num(){
	A_num = T_num + B_num + P_num + M_num;
}
/*********************************************************************
** Function: get profit
** Description: return profit
** Parameters: None
*********************************************************************/
int Zoo::get_T_num(){
	return T_num;
}
/*********************************************************************
** Function: get profit
** Description: return profit
** Parameters: None
*********************************************************************/
int Zoo::get_B_num(){
	return B_num;
}
/*********************************************************************
** Function: get profit
** Description: return profit
** Parameters: None
*********************************************************************/
int Zoo::get_P_num(){
	return P_num;
}
/*********************************************************************
** Function: get profit
** Description: return profit
** Parameters: None
*********************************************************************/
int Zoo::get_M_num(){
	return M_num;
}
/*********************************************************************
** Function: get profit
** Description: return profit
** Parameters: None
*********************************************************************/
int Zoo::get_A_num(){
	return A_num;
}
/*********************************************************************
** Function: set name
** Description: set name value
** Parameters: string
*********************************************************************/
void Zoo::set_T_die(int n){
	A[0][n].set_alive(false);
	remove_Tiger();
}
/*********************************************************************
** Function: set name
** Description: set name value
** Parameters: string
*********************************************************************/
void Zoo::set_B_die(int n){
	A[1][n].set_alive(false);
	remove_Bear();
}
/*********************************************************************
** Function: set name
** Description: set name value
** Parameters: string
*********************************************************************/
void Zoo::set_P_die(int n){
	A[2][n].set_alive(false);
	remove_Peng();
}
/*********************************************************************
** Function: set name
** Description: set name value
** Parameters: string
*********************************************************************/
void Zoo::set_M_die(int n){
	A[3][n].set_alive(false);
	remove_Peng();
}
/*********************************************************************
** Function: set name
** Description: set name value
** Parameters: string
*********************************************************************/
void Zoo::print_Tigers(){
	for(int i=0; i < T_num; i++)
	{
		cout << "            Tiger: " << i + 1 << endl;
		cout << "                  " << A[0][i].get_name()<< ", ";
		cout << A[0][i].get_age()<< ", ";
		//cout << A[0][i].get_lifespan() << ", ";
		cout << A[0][i].get_babies() << ", ";
		cout << A[0][i].get_feed() << ", ";
		cout << A[0][i].get_heal()<< ", ";
		cout << A[0][i].get_profit() << endl;
		//cout << A[0][i].get_buy();
	}
}
/*********************************************************************
** Function: set name
** Description: set name value
** Parameters: string
*********************************************************************/
void Zoo::print_Bears(){
	for(int i=0; i < B_num; i++)
	{
		cout << "            Bear: " << i + 1 << endl;
		cout << "                  " << A[1][i].get_name()<< ", ";
		cout << A[1][i].get_age()<< ", ";
		//cout << A[1][i].get_lifespan() << ", ";
		cout << A[1][i].get_babies() << ", ";
		cout << A[1][i].get_feed() << ", ";
		cout << A[1][i].get_heal()<< ", ";
		cout << A[1][i].get_profit() << endl;
		//cout << A[1][i].get_buy();
	}
}
/*********************************************************************
** Function: set name
** Description: set name value
** Parameters: string
*********************************************************************/
void Zoo::print_Pengs(){
	for(int i=0; i < P_num; i++)
	{
		cout << "            Peng: " << i + 1 << endl;
		cout << "                  " << A[2][i].get_name()<< ", ";
		cout << A[2][i].get_age()<< ", ";
		//cout << A[2][i].get_lifespan() << ", ";
		cout << A[2][i].get_babies() << ", ";
		cout << A[2][i].get_feed() << ", ";
		cout << A[2][i].get_heal()<< ", ";
		cout << A[2][i].get_profit() << endl;
		//cout << A[2][i].get_buy();
	}
}
/*********************************************************************
** Function: set name
** Description: set name value
** Parameters: string
*********************************************************************/
void Zoo::print_Monkeys(){
	for(int i=0; i < M_num; i++)
	{
		cout << "            Monkey: " << i + 1 << endl;
		cout << "                  " << A[3][i].get_name()<< ", ";
		cout << A[3][i].get_age()<< ", ";
		//cout << A[3][i].get_lifespan() << ", ";
		cout << A[3][i].get_babies() << ", ";
		cout << A[3][i].get_feed() << ", ";
		cout << A[3][i].get_heal()<< ", ";
		cout << A[3][i].get_profit() << endl;
		//cout << A[2][i].get_buy();
	}
}
/*********************************************************************
** Function: set name
** Description: set name value
** Parameters: string
*********************************************************************/
void Zoo::add_Tiger(){
	T_num++;
	if (T_num == 1)
		A[0] = new Tiger[T_num];
	else{
		Animal *temp = new Tiger[T_num - 1];
		for (int i = 0; i < T_num - 1; i++)
			temp[i] = A[0][i];
		delete[] A[0];
		A[0] = new Tiger[T_num];
		for (int i = 0; i < T_num - 1; i++)
			A[0][i] = temp[i];
		delete[] temp;
	}
}
/*********************************************************************
** Function: set name
** Description: set name value
** Parameters: string
*********************************************************************/
void Zoo::add_Bear(){
	B_num++;
	if (B_num == 1)
		A[1] = new Bear[B_num];
	else{
		Animal *temp = new Bear[B_num - 1];
		for (int i = 0; i < B_num - 1; i++)
			temp[i] = A[1][i];
		delete[] A[1];
		A[1] = new Bear[B_num];
		for (int i = 0; i < B_num - 1; i++)
			A[1][i] = temp[i];
		delete[] temp;
	}
}
/*********************************************************************
** Function: set name
** Description: set name value
** Parameters: string
*********************************************************************/
void Zoo::add_Peng(){
	P_num++;
	if (P_num == 1)
		A[2] = new Peng[P_num];
	else{
		Animal *temp = new Peng[P_num - 1];
		for (int i = 0; i < P_num - 1; i++)
			temp[i] = A[2][i];
		delete[] A[2];
		A[2] = new Peng[P_num];
		for (int i = 0; i < P_num - 1; i++)
			A[2][i] = temp[i];
		delete[] temp;
	}
}
/*********************************************************************
** Function: set name
** Description: set name value
** Parameters: string
*********************************************************************/
void Zoo::add_Monkey(){
	M_num++;
	if (M_num == 1)
		A[3] = new Monkey[M_num];
	else{
		Animal *temp = new Monkey[M_num - 1];
		for (int i = 0; i < M_num - 1; i++)
			temp[i] = A[3][i];
		delete[] A[3];
		A[3] = new Monkey[M_num];
		for (int i = 0; i < M_num - 1; i++)
			A[3][i] = temp[i];
		delete[] temp;
	}
}
/*********************************************************************
** Function: set name
** Description: set name value
** Parameters: string
*********************************************************************/
void Zoo::add_Baby_Tiger(){
	T_num++;
	if (T_num == 1){
		A[0] = new Tiger[T_num];
		A[0][T_num - 1].set_buy(0);
		A[0][T_num - 1].set_heal(2000);
		A[0][T_num - 1].set_profit(2000);
		A[0][T_num - 1].set_age(0);
		A[0][T_num - 1].set_babies(0);
		A[0][T_num - 1].set_name("Baby");
	}
	else{
		Animal *temp = new Tiger[T_num - 1];
		for (int i = 0; i < T_num - 1; i++)
			temp[i] = A[0][i];
		delete[] A[0];
		A[0] = new Tiger[T_num];
		for (int i = 0; i < T_num - 1; i++)
			A[0][i] = temp[i];
		A[0][T_num - 1].set_buy(0);
		A[0][T_num - 1].set_heal(2000);
		A[0][T_num - 1].set_profit(2000);
		A[0][T_num - 1].set_age(0);
		A[0][T_num - 1].set_babies(0);
		A[0][T_num - 1].set_name("Baby");
		delete[] temp;
	}
}
/*********************************************************************
** Function: set name
** Description: set name value
** Parameters: string
*********************************************************************/
void Zoo::add_Baby_Bear(){
	B_num++;
	if (B_num == 1){
		A[1] = new Bear[B_num];
		A[1][B_num - 1].set_buy(0);
		A[1][B_num - 1].set_heal(1200);
		A[1][B_num - 1].set_profit(1200);
		A[1][B_num - 1].set_age(0);
		A[1][B_num - 1].set_babies(0);
		A[1][B_num - 1].set_name("Baby");
	}
	else{
		Animal *temp = new Bear[B_num - 1];
		for (int i = 0; i < B_num - 1; i++)
			temp[i] = A[1][i];
		delete[] A[1];
		A[1] = new Tiger[B_num];
		for (int i = 0; i < B_num - 1; i++)
			A[1][i] = temp[i];
		A[1][B_num - 1].set_buy(0);
		A[1][B_num - 1].set_heal(1200);
		A[1][B_num - 1].set_profit(1200);
		A[1][B_num - 1].set_age(0);
		A[1][B_num - 1].set_babies(0);
		A[1][B_num - 1].set_name("Baby");
		delete[] temp;
	}
}
/*********************************************************************
** Function: set name
** Description: set name value
** Parameters: string
*********************************************************************/
void Zoo::add_Baby_Peng(){
	P_num++;
	if (P_num == 1){
		A[2] = new Peng[P_num];
		A[2][P_num - 1].set_buy(0);
		A[2][P_num - 1].set_heal(400);
		A[2][P_num - 1].set_profit(400);
		A[2][P_num - 1].set_age(0);
		A[2][P_num - 1].set_babies(0);
		A[2][P_num - 1].set_name("Baby");
	}
	else{
		Animal *temp = new Peng[P_num - 1];
		for (int i = 0; i < P_num - 1; i++)
			temp[i] = A[2][i];
		delete[] A[2];
		A[2] = new Peng[P_num];
		for (int i = 0; i < P_num - 1; i++)
			A[2][i] = temp[i];
		A[2][P_num - 1].set_buy(0);
		A[2][P_num - 1].set_heal(400);
		A[2][P_num - 1].set_profit(400);
		A[2][P_num - 1].set_age(0);
		A[2][P_num - 1].set_babies(0);
		A[2][P_num - 1].set_name("Baby");
		delete[] temp;
	}
}
/*********************************************************************
** Function: set name
** Description: set name value
** Parameters: string
*********************************************************************/
void Zoo::add_Baby_Monkey(){
	M_num++;
	if (M_num == 1){
		A[3] = new Monkey[M_num];
		A[3][M_num - 1].set_buy(0);
		A[3][M_num - 1].set_heal(500);
		A[3][M_num - 1].set_profit(500);
		A[3][M_num - 1].set_age(0);
		A[3][M_num - 1].set_babies(0);
		A[3][M_num - 1].set_name("Baby");
	}
	else{
		Animal *temp = new Monkey[M_num - 1];
		for (int i = 0; i < M_num - 1; i++)
			temp[i] = A[3][i];
		delete[] A[3];
		A[3] = new Monkey[M_num];
		for (int i = 0; i < M_num - 1; i++)
			A[3][i] = temp[i];
		A[3][M_num - 1].set_buy(0);
		A[3][M_num - 1].set_heal(500);
		A[3][M_num - 1].set_profit(500);
		A[3][M_num - 1].set_age(0);
		A[3][M_num - 1].set_babies(0);
		A[3][M_num - 1].set_name("Baby");
		delete[] temp;
	}
}
/*********************************************************************
** Function: set name
** Description: set name value
** Parameters: string
*********************************************************************/
void Zoo::remove_Tiger(){
	int x = 0, y = 0;
	for (int i = 0; i < T_num; i++)
	{
		if (A[0][i].get_alive() == true)
			x++;
	}
	Animal *temp;
	temp = new Tiger[x];
	for (int i = 0; i < T_num; i++)
	{
		if (A[0][i].get_alive() == true)
		{
			temp[y] = A[0][i];
			y++;
		}
	}
	delete[] A[0];
	T_num = x;
	A[0] = new Tiger[T_num];
	for (int i = 0; i < T_num; i++)
		A[0][i] = temp[i];
	delete[] temp;
}
/*********************************************************************
** Function: set name
** Description: set name value
** Parameters: string
*********************************************************************/
void Zoo::remove_Bear(){
	int x = 0, y = 0;
	for (int i = 0; i < B_num; i++)
	{
		if (A[1][i].get_alive() == true)
			x++;
	}
	Animal *temp;
	temp = new Bear[x];
	for (int i = 0; i < B_num; i++)
	{
		if (A[1][i].get_alive() == true)
		{
			temp[y] = A[1][i];
			y++;
		}
	}
	delete[] A[1];
	B_num = x;
	A[1] = new Bear[B_num];
	for (int i = 0; i < B_num; i++)
		A[1][i] = temp[i];
	delete[] temp;
}
/*********************************************************************
** Function: set name
** Description: set name value
** Parameters: string
*********************************************************************/
void Zoo::remove_Peng(){
	int x = 0, y = 0;
	for (int i = 0; i < P_num; i++)
	{
		if (A[2][i].get_alive() == true)
			x++;
	}
	Animal *temp;
	temp = new Peng[x];
	for (int i = 0; i < P_num; i++)
	{
		if (A[2][i].get_alive() == true)
		{
			temp[y] = A[2][i];
			y++;
		}
	}
	delete[] A[2];
	P_num = x;
	A[2] = new Peng[P_num];
	for (int i = 0; i < P_num; i++)
		A[2][i] = temp[i];
	delete[] temp;
}
/*********************************************************************
** Function: set name
** Description: set name value
** Parameters: string
*********************************************************************/
void Zoo::remove_Monkey(){
	int x = 0, y = 0;
	for (int i = 0; i < M_num; i++)
	{
		if (A[3][i].get_alive() == true)
			x++;
	}
	Animal *temp;
	temp = new Monkey[x];
	for (int i = 0; i < M_num; i++)
	{
		if (A[3][i].get_alive() == true)
		{
			temp[y] = A[3][i];
			y++;
		}
	}
	delete[] A[3];
	M_num = x;
	A[3] = new Monkey[M_num];
	for (int i = 0; i < M_num; i++)
		A[3][i] = temp[i];
	delete[] temp;
}
/*********************************************************************
** Function: set name
** Description: set name value
** Parameters: string
*********************************************************************/
Animal* Zoo::get_Animal_Tiger(){
	return A[0];
}
/*********************************************************************
** Function: set name
** Description: set name value
** Parameters: string
*********************************************************************/
Animal* Zoo::get_Animal_Bear(){
	return A[1];
}
/*********************************************************************
** Function: set name
** Description: set name value
** Parameters: string
*********************************************************************/
Animal* Zoo::get_Animal_Peng(){
	return A[2];
}
/*********************************************************************
** Function: set name
** Description: set name value
** Parameters: string
*********************************************************************/
Animal* Zoo::get_Animal_Monkey(){
	return A[3];
}
/*********************************************************************
** Function: set name
** Description: set name value
** Parameters: string
*********************************************************************/
void Zoo::set_total_profit(){
	int T_profit = 0;
	int B_profit = 0;
	int P_profit = 0;
	int M_profit = 0;

	for(int i=0; i<T_num; i++)
	{
		T_profit = T_profit + A[0][i].get_profit() + (bonus * T_num);
	}
	for(int i=0; i<B_num; i++)
	{
		B_profit = B_profit + A[1][i].get_profit();
	}
	for(int i=0; i<P_num; i++)
	{
		P_profit = P_profit + A[2][i].get_profit();
	}
	for(int i=0; i<M_num; i++)
	{
		M_profit = M_profit + A[3][i].get_profit();
	}

	total_profit = T_profit + B_profit + P_profit + M_profit;
}
/*********************************************************************
** Function: set name
** Description: set name value
** Parameters: string
*********************************************************************/
int Zoo::get_total_profit(){
	return total_profit;
}
/*********************************************************************
** Function: set name
** Description: set name value
** Parameters: string
*********************************************************************/
void Zoo::reset_total_profit(){
	total_profit = 0;
}
/*********************************************************************
** Function: set name
** Description: set name value
** Parameters: string
*********************************************************************/
void Zoo::set_total_feed(){
	int T_feed = 0;
	int B_feed = 0;
	int P_feed = 0;
	int M_feed = 0;

	for(int i=0; i<T_num; i++)
	{
		T_feed = T_feed + A[0][i].get_feed();
	}
	for(int i=0; i<B_num; i++)
	{
		B_feed = B_feed + A[1][i].get_feed();
	}
	for(int i=0; i<P_num; i++)
	{
		P_feed = P_feed + A[2][i].get_feed();
	}
	for(int i=0; i<M_num; i++)
	{
		M_feed = M_feed + A[3][i].get_feed();
	}

	total_feed = T_feed + B_feed + P_feed + M_feed;
}
/*********************************************************************
** Function: set name
** Description: set name value
** Parameters: string
*********************************************************************/
void Zoo::set_total_feed(int n){
	total_feed = n;
}
/*********************************************************************
** Function: set name
** Description: set name value
** Parameters: string
*********************************************************************/
void Zoo::reset_total_feed(){
	total_feed = 0;
}
/*********************************************************************
** Function: set name
** Description: set name value
** Parameters: string
*********************************************************************/
int Zoo::get_total_feed(){
	return total_feed;
}
/*********************************************************************
** Function: set name
** Description: set name value
** Parameters: string
*********************************************************************/
void Zoo::set_bonus(int n){
	bonus = n;
}
/*********************************************************************
** Function: set name
** Description: set name value
** Parameters: string
*********************************************************************/
int Zoo::get_bonus(){
	return bonus;
}
/*********************************************************************
** Function: set name
** Description: set name value
** Parameters: string
*********************************************************************/
void Zoo::reset_bonus(){
	bonus = 0;
}
/*********************************************************************
** Function: set name
** Description: set name value
** Parameters: string
*********************************************************************/
int Zoo::have_Tiger_Adult(){
	int adult = 0;
	for(int i=0; i<get_T_num(); i++)
		if(A[0][i].get_age() >= 3)
			adult++;
	return adult;

}
/*********************************************************************
** Function: set name
** Description: set name value
** Parameters: string
*********************************************************************/
int Zoo::have_Bear_Adult(){
	int adult = 0;
	for(int i=0; i<get_B_num(); i++)
		if(A[1][i].get_age() >= 3)
			adult++;
	return adult;

}
/*********************************************************************
** Function: set name
** Description: set name value
** Parameters: string
*********************************************************************/
int Zoo::have_Peng_Adult(){
	int adult = 0;
	for(int i=0; i<get_P_num(); i++)
		if(A[2][i].get_age() >= 3)
			adult++;
	return adult;

}
/*********************************************************************
** Function: set name
** Description: set name value
** Parameters: string
*********************************************************************/
int Zoo::have_Monkey_Adult(){
	int adult = 0;
	for(int i=0; i<get_M_num(); i++)
		if(A[3][i].get_age() >= 3)
			adult++;
	return adult;

}
Zoo &Zoo::operator=(Zoo &h){
	if ( A_num != 0)
	{
		for(int i=0; i<4; i++)
		{
			delete[] A[i];
		}
	}
	A_num = h.A_num;
	T_num = h.T_num;
	B_num = h.B_num;
	P_num = h.P_num;
	M_num = h.M_num;

	if (A_num != 0){
		A[0] = new Tiger[T_num];
		A[1] = new Bear[B_num];
		A[2] = new Peng[P_num];
		A[3] = new Peng[P_num];
		for (int i = 0; i < T_num; i++)
			A[0][i] = h.A[0][i];
		for (int i = 0; i < B_num; i++)
			A[1][i] = h.A[1][i];
		for (int i = 0; i < P_num; i++)
			A[2][i] = h.A[2][i];
		for (int i = 0; i < M_num; i++)
			A[3][i] = h.A[3][i];
	}
	return *this;
}