#include <iostream>
#include "Dice.h"
#include <time.h>

using namespace std;

Dice::Dice() : d1(1), d2(2) {};	// Sets the dice values to two different ones so no doubles at start

unsigned int Dice::roll()
{
	// Creates random numbers between 1 and 5
	d1 = rand() % 6 + 1;
	d2 = rand() % 6 + 1; 

	//cout << " D1: " << d1 << " D2: " << d2 << " ";

	return d1+d2;
}

bool Dice::isDoubles() const
{
	// Check to see if one dice rolled the same value as the other
	if(d1 == d2)
	{
		return true;
	}else
	{
		return false;
	}
}
