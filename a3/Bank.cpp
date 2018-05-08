#include "Bank.h"
#include "Money.h"
#include "Wallet.h"

#include <iostream>

//Bank::Bank(){}

void Bank::giveStartingMoney(Wallet& p)
{
	//Loop for the number of deneminations to give
	for(int i = 0; i < 2; i++)
	{
		//Then deposit it into the account
		p.deposit(500);
	}
	
	//The logic above applies to the next six cases as well
	for(int i = 0; i < 2; i++)
	{
		p.deposit(100);
	}
	for(int i = 0; i < 2; i++)
	{
		p.deposit(50);
	}
	for(int i = 0; i < 6; i++)
	{
		p.deposit(20);
	}
	for(int i = 0; i < 5; i++)
	{
		p.deposit(10);
	}
	for(int i = 0; i < 5; i++)
	{
		p.deposit(5);
	}
	for(int i = 0; i < 5; i++)
	{
		p.deposit(1);
	}
}
