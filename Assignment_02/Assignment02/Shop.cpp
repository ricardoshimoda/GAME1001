#include "stdafx.h"

#include "Constants.h"
#include "Philosophers.h"
#include "Shop.h"
#include "Player.h"

#include <string>
#include <iostream>
#include <conio.h>

using namespace std;

void Intro() {
	cout << "Hello! Welcome to Philosopher's United." << endl;
	cout << "Here you have the oportunity to, using your current IQ, select a series of quotes to empower your life." << endl;
	cout << "After selecting your set of quotes, please, join us in the adjacent room where we can have some earl grey tea and "
		<< "you can use your quotes. Upon using them successfully, you will earn extra wits, enabling you to get a new set of quotations. " << endl;
	cout << "Be careful, however - every time you make one of the following mistakes:" << endl;
	cout << "- Choose an unexisting activity" << endl;
	cout << "- Choose to go to the parlour without any quotes in your inventory" << endl;
	cout << "Your wits will receive a blow. If this reaches a point where you will no longer be able to engage in our game "
		<< "of quoting we will ask you to leave our shop." << endl;
	cout << endl;
}

char ShopMenu()
{
	bool validEntry = false;
	char playerChoice = '\0';
	do 
	{
		cout << "Tell me, how can I help you?" << endl;
		cout << "Please type:" << endl;
		cout << "A - to acquire a new quote from our roster of philosophers." << endl;
		cout << "P - to join our friends in the parlour and use your quotes." << endl;
		cout << "C - to check your current IQ and quote inventory." << endl;
		cout << "X - to exit the game." << endl << "> ";
		playerChoice = _getch();
		system("CLS");
		if (playerChoice != 'A' && playerChoice != 'a' &&
			playerChoice != 'P' && playerChoice != 'p' &&
			playerChoice != 'C' && playerChoice != 'c' &&
			playerChoice != 'X' && playerChoice != 'x')
		{
			cout << "You chose " << playerChoice << " - this is not a valid choice in our options. " << endl;
			double lostIQ = LosesErrorIQ();
			cout << "As a result you lost " << lostIQ << " IQPoints" << endl;
			if (!CheckPlayerIQ())
				return 'X';
			else
				cout << "Now you still have " << GetPlayerIQ() << " points. " << endl;
		}
		if (playerChoice == 'A' || playerChoice == 'a') 
		{
			ShopQuotes();
		}
		if (playerChoice == 'P' || playerChoice == 'p') {
			if (DetectEmptyRepertoire()) {
				cout << "You chose to go to the Parlour without any quotes to say. " << endl;
				double lostIQ = LosesErrorIQ();
				cout << "As a result you lost " << lostIQ << " IQ points. " << endl;
				if (!CheckPlayerIQ())
					return 'X';
				else
					cout << "Now you still have " << GetPlayerIQ() << " points. " << endl;
			}
			else {
				return 'P';
			}
		}
		if (playerChoice == 'C' || playerChoice == 'c')
		{
			PrintPlayerStatus();
		}
		if (playerChoice == 'X' || playerChoice == 'x') 
		{
			return 'X';
		}

	} while (!validEntry);

	return playerChoice;
}
