#include "Bank.h"
#include "Money.h"
#include "Wallet.h"

#include <iostream>
#include <vector>
using namespace std;

Wallet::Wallet(Bank& banker) : theBank(banker) {}

vector <Money>denominations = {500, 100, 50, 20, 10, 5, 1};

void Wallet::deposit(Money amt)
{
	// The total amount to deposit
	Money total = amt;
	
	// Loop body will decrement total, so the loop runs while it's more than 0
	// 0 Because it's an unsigned int
	while(total	>= 1)
	{
		// Loops through all the denominations possible for deposit
		for(int i = 0; i < denominations.size(); i ++)
		{
			// If the amount to deposit mod any of the denominations == 0 (AND the denomination is less than the amount to deposit)
			if(total % denominations[i] == 0 && denominations[i] <= total)
			{
				cash.push_back(denominations[i]);	// Adds the cash to the wallet
				total -= denominations[i];			// Takes away the added denomination from the total
				if(total == 0)	// When the total equals zero, break the loop
				{
					break;
				}
			}
		}
	}
}

bool Wallet::withdraw(Money amt)
{
	// Checks to see if withdraw can be done
	if(netWorth() >= amt)
	{
		// Loops through the cash vector
		for(int i = 0; i < cash.size(); i++)
		{
			// Then checks to see if the elements of cash are smaller than amount
			if(cash[i] <= amt && amt >= 1)
			{
				// If so it calls itself with the total amount minus the denomination removed
				Money taken = cash[i];
				cash.erase(cash.begin() + i);
				withdraw(amt - taken);
				// Removes the cash at it's index
				return true;
			}
		}
	}

	return false; // Returns false if net worth is less than amount to withdraw
}


bool Wallet::transferTo(Money amt, Wallet& payee)
{
	// If the person has more than the amount to pay
	if(netWorth() >= amt)
	{
		// That amount is withdrawed from their wallet
		withdraw(amt);
		// And add that to the payee's wallet
		payee.deposit(amt);
		return true;
	}
	return false;	// Else return false
}


Money Wallet::netWorth() const
{
	// Variable to contain the total cash in the wallet
	Money total = 0;
	// Loops through the cash vector
	for(Money i : cash)
	{
		// And adds it to the total
		total += i;	
	}

	return total;
}
