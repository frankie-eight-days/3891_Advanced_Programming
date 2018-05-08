#include <iostream>
#include<string>

#include "Player.h"
#include "Game.h"

using namespace std;

Player::Player(Token t, Game* theGame) : tok(t), myGame(theGame), money(*(theGame->getBank()))
{
	location = 0;	// Sets the location to be zero initially (Go)
};

Player::Token Player::getToken()
{
	return tok;	// Returns the token type of the player
}

unsigned int Player::getLocation()
{
	return location;
}

void Player::setLocation(unsigned int loc)
{
	location = loc;	// Sets the location of the player to the place specified.
}

Wallet* Player::getWallet()
{
	return &money;
}

Game* Player::getGame()
{
	return myGame;
}

std::ostream& operator<<(std::ostream& os, const Player::Token t)
{
	string name;	// Holds what will be returned
	
	// Compares the token types passed to it
	switch(t)
	{
		case Player::Token::Dog:
			name = "Dog";
			break;
		case Player::Token::Boot:
			name = "Boot";
			break;
		case Player::Token::Wheelbarrow:
			name = "Wheelbarrow";
			break;
		case Player::Token::Car:
			name = "Car";
			break;
		case Player::Token::Thimble:
			name = "Thimble";
			break;
		case Player::Token::Battleship:
			name = "Battleship";
			break;
		case Player::Token::TopHat:
			name = "TopHat";
			break;
		case Player::Token::Iron:
			name = "Iron";
			break;
		case Player::Token::HorseRider:
			name = "HorseRider";
			break;
		case Player::Token::Cannon:
			name = "Cannon";
			break;
	}

	os << name << "\t";		// Writes to the output stream
	return os;			// Then returns it
}
