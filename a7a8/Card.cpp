#include <iostream>
#include "Card.h"
#include "Player.h"
#include "CardDeck.h"

using namespace std;

Card::Card(std::string flavourText, CardDeck* deck) : text_(flavourText), myDeck_(deck) {};

std::string Card::text()
{
	return text_;
}

CardDeck* Card::myDeck()
{
	return myDeck_;
}
//////////////////////////////////////////////////////////////////////////////////////////

MoneyEffect::MoneyEffect(std::string flavourText, CardDeck* deck, int amtToUse)
									: Card(flavourText, deck), amountToUse_(amtToUse) {};
////////////////////////////////////////////////////////////////////////////////////////////
MoveEffect::MoveEffect(std::string flavourText, CardDeck* deck, unsigned int locToUse)
									: Card(flavourText, deck), locationToUse_(locToUse) {};
///////////////////////////////////////////////////////////////////////////////////////////
PayMoney::PayMoney(std::string flavourText, CardDeck* deck, int amtToUse)
									: MoneyEffect(flavourText, deck, amtToUse) {};

void PayMoney::applyEffect(Player* currentPlayer, std::vector< Player* > otherPlayers)
{
	currentPlayer->withdrawMoney(amountToUse_);	// Takes away money to the current player
}
////////////////////////////////////////////////////////////////////////////////////////////
GetMoney::GetMoney(std::string flavourText, CardDeck* deck, int amtToUse):
												MoneyEffect(flavourText, deck, amtToUse) {};

void GetMoney::applyEffect(Player* currentPlayer, std::vector< Player* > otherPlayers)
{
	currentPlayer->depositMoney(amountToUse_); // Adds money to the current player
}

/////////////////////////////////////////////////////////////////////////////////////
PayOthers::PayOthers(std::string flavourText, CardDeck* deck, int amtToUse)
									: MoneyEffect(flavourText, deck, amtToUse) {};

void PayOthers::applyEffect(Player* currentPlayer, std::vector< Player* > otherPlayers)
{
	int size = otherPlayers.size()-1;
	
	int amountTaken = currentPlayer->withdrawMoney(amountToUse_*size);
	
	for(int i = 0; i < size+1; i++)
	{
		// Adds amountToUse_ to the players bank
		// Divided by size just in case player doesn't have enough money
		otherPlayers[i]->depositMoney(amountTaken/size);
	}
}
/////////////////////////////////////////////////////////////////////////////////////
GetFromOthers::GetFromOthers(std::string flavourText, CardDeck* deck, int amtToUse)
											: MoneyEffect(flavourText, deck, amtToUse) {};

void GetFromOthers::applyEffect(Player* currentPlayer, std::vector< Player* > otherPlayers)
{
	int totalToGet = 0;	// Need variable just in case all players don't have enough money

	for(int i = 0; i < otherPlayers.size(); i++)
	{
		if(otherPlayers[i] != currentPlayer)
		{
			totalToGet += otherPlayers[i]->withdrawMoney(amountToUse_);
		}
	}

	currentPlayer->depositMoney(totalToGet);
}

///////////////////////////////////////////////////////////////////////////////////////////
PayPer::PayPer(std::string flavourText, CardDeck* deck, int amtToUseHouse, int amtToUseHotel)
				: MoneyEffect(flavourText, deck, amtToUseHouse), amtToUseForHotels_(amtToUseHotel) {};

void PayPer::applyEffect(Player* currentPlayer, std::vector< Player* > otherPlayers)
{
	int totalToPay = (currentPlayer->numHouses()*amountToUse_) + (currentPlayer->numHotels()* amtToUseForHotels_);

	currentPlayer->withdrawMoney(totalToPay);
}

////////////////////////////////////////////////////////////////////////////////////////////
GetOutOfJail::GetOutOfJail(std::string flavourText, CardDeck* myDeck)
							: Card(flavourText, myDeck) {};

void GetOutOfJail::applyEffect(Player* currentPlayer, std::vector< Player* > otherPlayers)
{
	currentPlayer->addGetOutOfJailFreeCard(this);
}

////////////////////////////////////////////////////////////////////////////////////////////
GoToJail::GoToJail(std::string flavourText, CardDeck* deck) 
							: MoveEffect(flavourText, deck, 10){};

void GoToJail::applyEffect(Player* currentPlayer, std::vector< Player* > otherPlayers)
{
	currentPlayer->setLocation(10);
	currentPlayer->setInJail(true);
}

////////////////////////////////////////////////////////////////////////////////////////////

AdvanceToSpecific::AdvanceToSpecific(std::string flavourText, CardDeck* deck, unsigned int locToUse)
									: MoveEffect(flavourText, deck, locToUse) {};

void AdvanceToSpecific::applyEffect(Player* currentPlayer, std::vector< Player* > otherPlayers)
{
	if(currentPlayer->inJail() == false)
	{
		currentPlayer->advanceToLocation(locationToUse_);
		if(currentPlayer->location() == 0)
		{
			currentPlayer->depositMoney(200);
		}
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////
AdvanceToNearest::AdvanceToNearest(std::string flavourText, CardDeck* deck, unsigned int locToUse)
											: MoveEffect(flavourText, deck, locToUse) {};

void AdvanceToNearest::applyEffect(Player* currentPlayer, std::vector< Player* > otherPlayers)
{
	int location = currentPlayer->location();
	
	if(currentPlayer->inJail() == true) { return;}

	switch(locationToUse_)
	{
		case 5:
			// I hardcoded this because I got frustrated
			if(location < 5 || location >=35)
			{
				currentPlayer->advanceToLocation(5);
			}
			if(location >= 5 && location < 15)
			{
				currentPlayer->advanceToLocation(15);
			}
			if(location >= 15 && location < 25)
			{
				currentPlayer->advanceToLocation(25);
			}
			if(location >= 25 && location < 35)
			{
				currentPlayer->advanceToLocation(35);
			}
		break;
		case 12:
			// No need for algo since there are only two cases
			if(currentPlayer->location() >= 12)
			{
				currentPlayer->advanceToLocation(28);
			}else
			{
				currentPlayer->advanceToLocation(12);
			}
		break;
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////
MoveBack::MoveBack(std::string flavourText, CardDeck* deck, unsigned int locToUse)
												: MoveEffect(flavourText, deck, locToUse) {};

void MoveBack::applyEffect(Player* currentPlayer, std::vector< Player* > otherPlayers)
{
	// If the player's location minus the location to move to is less than 0 
	// That means that the player must pass Go
	if(currentPlayer->location()-locationToUse_ == 0)
	{
		currentPlayer->depositMoney(200);
	}
	for(int i = 0; i < locationToUse_; i++)
	{
		if(currentPlayer->inJail() == false)
		{
			if(currentPlayer->location() - 1 > 40)
			{
				currentPlayer->setLocation(40);
			}
			currentPlayer->setLocation(currentPlayer->location()-1);
		}
	}
}
