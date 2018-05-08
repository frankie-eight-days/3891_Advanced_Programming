#include "Bank.h"
#include "Dice.h"
#include "Player.h"
#include "Game.h"

#include <vector>
#include <iostream>

using namespace std;

Game* Game::Create(unsigned int numPlayers)
{	
	// Creates a game object and pointer on the heap
	Game* g = new Game();

	// Adds the bank and dice object to the game object
	g->theBank = Bank();
	g->theDice = Dice();
	
	// Variable to hold the token of the player
	Player::Token tok; 

	// Loops through the number of players
	for(int i = 0; i < numPlayers; i++)
	{
		// A different token is assigened depending on what number the player is
		switch(i)
		{
			case 0:
				tok = Player::Token::Dog;
			break;
			case 1:
				tok = Player::Token::Boot;
			break;
			case 2:
				tok = Player::Token::Wheelbarrow;
			break;
			case 3:
				tok = Player::Token::Car;
			break;
			case 4:
				tok = Player::Token::Thimble;
			break;
			case 5:
				tok = Player::Token::Battleship;
			break;
			case 6:
				tok = Player::Token::TopHat;
			break;
			case 7:								// Pre said the most players could be eight
				tok = Player::Token::Iron;
			break;

		}
		// Adds the player to the game object while calling the constructor
		// using the values declared above
		g->addPlayer(new Player(tok, g));
	}	
	// Then distributes the money to the players
	//g->theBank.distributeStartMoney(g->players);

	if(not g || numPlayers < 2) // If there is nothing in g OR there is only one player
		return nullptr;		// control flow fails
	return g;
}

void Game::gameOver()
{
	// Temp save the size of the player vector
	int size = players.size();
	// Loop through the player vector
	for(int i = 0; i < size; i++)
	{
		delete players[i];		// Free the memory
		players[i] = nullptr;	// Get rid of the hanging pointer
	}
	for(int i = 0; i < size; i++)
	{
		cout << size << endl;
		players.erase(players.begin());
	}
}

void Game::addPlayer(Player* p)
{
	players.push_back(p);
}

std::vector<Player*>& Game::getPlayers()
{
	return players;
}

Bank* Game::getBank()
{
	return &theBank;
}

Dice* Game::getDice()
{
	return &theDice;
}
