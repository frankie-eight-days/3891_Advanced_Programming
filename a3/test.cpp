#include "Bank.h"
#include "Money.h"
#include "Wallet.h"
#include <iostream>

using namespace std;

int main()
{
	Bank frank = Bank();
	Wallet rodney = Wallet(frank);
	Wallet andrew = Wallet(frank);	
	
	//cout << "Rodney Net Worth:" << endl;
	frank.giveStartingMoney(rodney);
	//cout << rodney.netWorth() << endl;

	//cout << "Andrew Net Worth:" << endl;
	frank.giveStartingMoney(andrew);
	//cout << andrew.netWorth() << endl;

	cout << "Andrew Net Worth: " << andrew.netWorth() << endl;
	cout << "Rodney Net Worth: " << rodney.netWorth() << endl;

	//rodney.deposit(1000);
	//cout << "Andrew pays rodney: " << andrew.transferTo(1000, rodney) << endl;;
	
	rodney.transferTo(1500, andrew);

	cout << "Andrew Net Worth: " << andrew.netWorth() << endl;
	cout << "Rodney Net Worth: " << rodney.netWorth() << endl;
	
	//andrew.displayWallet();

	//rodney.displayWallet();

	return 0;
}
