#include "stdafx.h"

#include "Constants.h"
#include "Philosophers.h"
#include "Player.h"

#include <string>
#include <iostream>
#include <conio.h>

using namespace std;

char ParlourMenu() 
{
	int* playerRepertoire = GetPlayerRepertoire();
	char playerChoice = '/0';
	cout << "Welcome to the Parlour - use our space to voice your quote and earn IQ Points." << endl;
	while (!DOOMSDAY)
	{
		if (!DetectEmptyRepertoire()) 
		{
			cout << "Please select one of the quotes available for you or exit to go back to the shop: " << endl;
			QuoteParlourMenu(playerRepertoire);
		}
		else 
		{
			cout << "Now, without any quotes left, you can:" << endl;
		}
		cout << "S. To go back to the shop and replenish your quotes." << endl;
		cout << "X. To exit the game." << endl;
		cout << "> ";
		playerChoice = _getch();
		system("CLS");
		if (playerChoice == 'X' || playerChoice == 'x') {
			return 'X';
		}
		if (playerChoice == 'S' || playerChoice == 's') {
			return 'S';
		}
		if(playerChoice > '0' && playerChoice <= '9')
		{
			int quoteIndex = playerChoice - '1';
			double quoteResult = PrintQuote(quoteIndex, playerRepertoire);

			AddIQ(quoteResult);
		}
		else 
		{
			cout << "You chose " << playerChoice << " - this is not a valid choice in our options. " << endl;
			double lostIQ = LosesErrorIQ();
			cout << "As a result you lost " << lostIQ << " IQ Points" << endl;
			if (!CheckPlayerIQ())
				return 'X';
			else
				cout << "Now you still have " << GetPlayerIQ() << " points. " << endl;
		}
	}
	return playerChoice;
}

void QuoteShopMenu()
{
}
