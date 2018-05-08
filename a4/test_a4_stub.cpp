// A4 test file
#include <iostream>
#include "Card.h"
#include "CardDeck.h"
#include <string>
#include <vector>
using namespace std;

//! Returns true if sequences not equal, based on comparing card effects
bool sequencesNotEqual(vector<Card*>& s1, vector<Card*>& s2)
{
    if (s1.size() == s2.size())
    {
        for (int i = 0; i < s1.size(); i++)
        {
            if (s1[i]->getEffect() != s2[i]->getEffect())
            {
                // Found a mismatch
                return true;
            }
        }
    }
    else
    {
        return true;
    }
    return false; // if we get here, must be equal
} 

int main()
{


    

    // Set up a small deck to test.
    CardDeck cc("Community Chest");
    Card a(Card::CardType::PayMoney, "Pay tax to bank", &cc, 100, 0);
    Card b(Card::CardType::GetMoney, "You won the lottery!", &cc, 1000, 0);
    Card c(Card::CardType::AdvanceTo, "Advance to location 7", &cc, 0, 7);
    cc.addCardToDeck(&a);
    cc.addCardToDeck(&b);
    cc.addCardToDeck(&c);
    string aEff = a.getEffect();
    string bEff = b.getEffect();
    string cEff = c.getEffect();

    // Tests 0--4 check basic methods about cards (eg. their effect strings, their deck, their flavour text, and the deck knowing its name...

    // Tests 5--9 test shuffle and draw in various combinations, eg. shuffle then draw all cards and make sure they are different, keep drawing and see if you automatically refshuffle, reshuffling with some still in draw pile and see if you draw all cards and they are unique, then last test shuffles and draws 3 cards from deck 5 times, recording the order the cards are drawn in vectors, and uses the sequencesNotEqual() function defined above to make sure cards are drawn in a different order.
    cc.shuffle();
    Card* d1 = cc.draw();
    Card* d2 = cc.draw();
    Card* d3 = cc.draw();
    // tests...

    
    return 0;    
}

