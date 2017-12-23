#include "stdafx.h"

#include "Constants.h"
#include "Philosophers.h"
#include "Player.h"

#include <string>
#include <iostream>
#include <conio.h>

using namespace std;

string author[NUM_QUOTES] = {
	"Anne Frank",
	"Heraclitus",
	"H. Jackson Brown Jr.",
	"Plato",
	"Robert H. Schuller",
	"Thomas Jefferson",
	"Desmond Tutu",
	"Aristotle",
	"George Bernard Shaw"
};
string quote[NUM_QUOTES] = {
	"Whoever is happy will make others happy too.",
	"There is nothing permanent except change.",
	"The best preparation for tomorrow is doing your best today.",
	"Wise men speak because they have something to say; Fools because they have to say something.",
	"Problems are not stop signs, they are guidelines.",
	"Honesty is the first chapter in the book of wisdom.",
	"You don't choose your family. They are God's gift to you as you are to them.",
	"It is during our darkest moments that we must focus to see the light.",
	"Life isn't about finding yourself. Life is about creating yourself."
};
string quotePraise[NUM_QUOTES] = {
	"Heartwarming!",
	"Well said.",
	"Let's us not waste any time!",
	"Terrific!",
	"A toast to this.",
	"Nice!",
	"Thanks!",
	"Jolly good!",
	"Bravo!"
};
double requiredIQ[NUM_QUOTES] = {
	80, 90, 110, 120, 130, 150, 170, 180, 200
};
double rewardIQ[NUM_QUOTES] = {
	5.5, 7.5, 9.3, 9.5, 15, 20, 31.2, 33 , 90
};
int reuse[NUM_QUOTES] = {
	1, 3, 2, 5, 2, 2, 1, 3, 1 
};

double GetCheapestQuote() 
{
	return requiredIQ[0];
}
void PrintQuoteAuthor(int selectedAuthorIndex) 
{
	cout << "- " << author[selectedAuthorIndex] << endl;
}

char ShopQuotes() 
{
	bool validEntry = false;
	char playerChoice = 'N';
	do {
		double currentPlayerIQ = GetPlayerIQ();
		int* playerRepertoire = GetPlayerRepertoire();
		bool emptyRepertoire = DetectEmptyRepertoire();
		cout << "This is our finest shop of quotes" << endl;
		cout << "Remember the following rules:" << endl;
		cout << "- Quote availability is defined according to your IQ (" << currentPlayerIQ << ")" << endl;
		cout << "- You can only get one quote at a time" << endl;
		cout << "- Each quote can only be used a specific number of times in the parlour." << endl;
		cout << "- After using up all your quotes you can either come back to restock in quotes or exit the game." << endl;
		cout << "Please make your selection according to the available quotes in the shop." << endl;
		QuoteShopMenu(currentPlayerIQ, playerRepertoire);
		cout << "M - Exit to main menu" << endl << "> ";
		playerChoice = _getch();
		system("CLS");
		if (playerChoice == 'M' || playerChoice == 'm')
		{
			return 'M';
		}
		else if (playerChoice > '0' && playerChoice <= '9') 
		{
			int quoteIndex = playerChoice - '1';
			if (playerRepertoire[quoteIndex] >= reuse[quoteIndex])
			{
				cout << "This fine quote by " << author[quoteIndex] << " is already part of your quotes." << endl;
				cout << "Please select another quote from our shop or go to the parlour to use your quotes." << endl << endl;
			}
			else if (requiredIQ[quoteIndex] > currentPlayerIQ) 
			{
				cout << "This fine quote by " << author[quoteIndex] << " is beyond your current capacity." << endl;
				cout << "Please select another quote from our shop ";
				if (!emptyRepertoire) 
				{
					cout << "or go to the parlour to use your quotes";
				}
				cout << "." << endl << endl;
			}
			else
			{
				cout << "Congratulations on adding this quote from "<< author[quoteIndex] << " to your collection. I hope you make good use of it. " << endl << endl;
				AddQuoteToRepertoire(quoteIndex, reuse[quoteIndex]);
			}
		}
		else
		{
			cout << "You chose " << playerChoice << " - this is not a valid choice in our options. " << endl;
			double lostIQ = LosesErrorIQ();
			cout << "As a result you lost " << lostIQ << " IQPoints" << endl;
			if (!CheckPlayerIQ())
				return 'X';
			else
				cout << "Now you still have " << GetPlayerIQ() << " points. " << endl;
		}
		
	} while (!validEntry);

	return playerChoice;

}

void QuoteShopMenu(double currentPlayerIQ, int* playerRepertoire)
{
	for (int quoteIndex = 0; quoteIndex < NUM_QUOTES; quoteIndex++)
	{
		cout << (quoteIndex + 1) << " - " << author[quoteIndex] << " - Required IQ Points: "
			<< requiredIQ[quoteIndex];
		if (currentPlayerIQ < requiredIQ[quoteIndex])
		{
			cout << " (Not Available - insufficient IQ) ";
		}
		else if (playerRepertoire[quoteIndex] > 0) {
			cout << " (Not Available - quote already added) ";
		}

		cout << endl;
	}
}
void QuoteParlourMenu(int* playerRepertoire)
{
	for (int quoteIndex = 0; quoteIndex < NUM_QUOTES; quoteIndex++)
	{
		if (playerRepertoire[quoteIndex] > 0)
		{
			cout << (quoteIndex + 1) << " - " << author[quoteIndex] << "(number of usages left: " << playerRepertoire[quoteIndex] << ")" << endl;
		}
	}
}



double PrintQuote(int desiredQuote, int* repertoire) {
	if (repertoire[desiredQuote] <= 0) {
		double lostIQ = rand() % (int)rewardIQ[desiredQuote];
		cout << "You gasp for air and you want the words to get out but you end up blurting out:" << endl;
		cout << "- BRRRRLLLLLLLLL" << endl;
		cout << "Everyone looks amusedly at you. You don't have that quote in your repertoire and, despite prevous warning, you tried to use it." << endl;
		cout << "For that you lose "<< lostIQ << " IQ points. Sorry, that's the way life is." << endl;
		return (-1)*lostIQ;
	}
	repertoire[desiredQuote]--;
	cout << " - '" << quote[desiredQuote] << "'" << endl
		<< " as originally said by " << author[desiredQuote] << endl;
	cout << "With that you impressed them all and you won " << rewardIQ[desiredQuote] 
		<< " IQ Points to use in our shop, if you desire to do so." << endl;
	return rewardIQ[desiredQuote];
};
