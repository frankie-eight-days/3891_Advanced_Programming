#include "CardDeck.h"
#include "Card.h"

#include <iostream>

using namespace std;

int main()
{
	CardDeck chance = CardDeck("Chance");
	cout << "Deck Name: " << chance.getName() << endl;

	Card pay = Card(Card::CardType::PayMoney, "Pay Money", &chance, 100, 0);
	cout << "Pay Text: " << pay.getText() << endl;
	cout << "Pay Deck: " << pay.getDeck() << endl;
	cout << "Pay Effect: " << pay.getEffect() << endl;

	cout << endl << endl << endl;

	Card get = Card(Card::CardType::GetMoney, "Get Dat Guap", &chance, 100, 0);
	Card go = Card(Card::CardType::AdvanceTo, "Brotha gotta go to jail", &chance, 0, 22);

	chance.addCardToDeck(&pay);
	chance.addCardToDeck(&get);
	chance.addCardToDeck(&go);
	
	for(int i = 0; i < 5; i++)
	{
		//chance.displayDeck();
		chance.shuffle();
		//chance.displayDeck();
	}

	cout << endl << endl << endl << endl;

	//chance.displayDeck();
	for(int i = 0; i < 4; i++)
	{
		chance.draw();
		//chance.displayDeck();
	}
	

	cout << endl << endl;
	cout << "SHUFFLE WHILE THEY'RE IN DISCARD PILE" << endl;
	chance.shuffle();
	//chance.displayDeck();

	return 0;
}
