#include "stdafx.h"

#include "Constants.h"
#include "Philosophers.h"
#include "Player.h"

#include <iostream>
#include <stdlib.h>

using namespace std;

double playerIQ;
int playerRepertoire[NUM_QUOTES];

void InitPlayer() 
{
	playerIQ = START_IQ;
	for (int i = 0; i < NUM_QUOTES; i++) {
		playerRepertoire[i] = 0;
	}
}

int* GetPlayerRepertoire() 
{
	return playerRepertoire;
}

double LosesErrorIQ() 
{
	double lostIQ = rand() % 5 + 1;
	playerIQ = playerIQ - lostIQ;
	return lostIQ;
}

void AddIQ(double usageIQ)
{
	playerIQ = playerIQ + usageIQ;
}


double GetPlayerIQ() 
{
	return playerIQ;
}

bool DetectEmptyRepertoire()
{
	for (int i = 0; i < NUM_QUOTES; i++)
		if (playerRepertoire[i] > 0)
			return false;
	return true;
}

bool CheckPlayerIQ() {
	double currentPlayerIQ = GetPlayerIQ();
	double cheapestQuote = GetCheapestQuote();
	bool emptyRepertoire = DetectEmptyRepertoire();
	if (currentPlayerIQ < 0 || (currentPlayerIQ < cheapestQuote && emptyRepertoire))
	{
		cout << "This means that you have reached an IQ of " << currentPlayerIQ
			<< " which is less than the minimum required to play this game " << endl;
		cout << "I am sorry but I have to let you go... good luck and see you in the future. " << endl;
		return false;
	}
	return true;
}

void PrintPlayerStatus() 
{
	cout << "Currently you have " << playerIQ << " IQ points " << endl;
	if(DetectEmptyRepertoire())
	{
		cout << "Currently your repertoire is empty " << endl 
			 << "Remember that you can only go to the parlour "
 			 << "if you have at least one quote." << endl;
	}
	else {
		cout << "You have quotes from the following philosopher(s):" << endl;
		for (int i = 0; i < NUM_QUOTES; i++)
		{
			if (playerRepertoire[i] > 0) {
				PrintQuoteAuthor(i);
			}
		}
		cout << endl;
	}
}

void AddQuoteToRepertoire(int quoteIndex, int uses) {
	playerRepertoire[quoteIndex] = uses;
}