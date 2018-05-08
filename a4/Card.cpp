#include "Card.h"
#include "CardDeck.h"
#include <iostream>
#include <string>

using namespace std;

// Card constructor... excuse the spacing.
Card::Card(CardType ct, std::string text, CardDeck* own,
         unsigned int amt, unsigned int dest) : myDeck(own), mytype(ct), flavourText(text), moneyAmount(amt), destination(dest) {}

std::string Card::getEffect() const
{
	string effect1 = "You gotta pay da piper big man, dis much: ";
	string effect2 = "Ayyy this-ah man is dah big winnah, you get: ";
	string effect3 = "BRAH, you gotta go mane, you gotta get out, get to here: ";

	// Switch the type that it's passed
	switch(mytype)
	{	
		// Depending on what type is passed in it will return it's effect
		case Card::CardType::PayMoney:
			return effect1.append(to_string(moneyAmount));
			break;
		case Card::CardType::GetMoney:
			return  effect2.append(to_string(moneyAmount));;
			break;
		case Card::CardType::AdvanceTo:
			return effect3.append(to_string(destination));;
			break;
	}
}

CardDeck* Card::getDeck() const
{
	// returns the pointer pointing to the deck the card is in.
	return myDeck;
}

std::string Card::getText() const
{
	// returns the flavour text set
	return flavourText;
}
