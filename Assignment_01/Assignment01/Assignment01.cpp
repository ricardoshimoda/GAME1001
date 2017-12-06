#include "stdafx.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>

using namespace std;

void greeting() {
	cout << "     .{{}}}}}}." << endl;
	cout << "    {{{{{}}}}}}}." << endl;
	cout << "   {{{{  {{{{{}}}}" << endl;
	cout << "  }}}}} _   _ {{{{{" << endl;
	cout << "  }}}}  6   m  }}}}" << endl;
	cout << " {{{{C    ^    {{{{" << endl;
	cout << "}}}}}}\\  '='  /}}}}}" << endl;
	cout << "{{{{{{{;.___.;}}}}}}" << endl;
	cout << "  {{{{{{)    (}}}}}}'" << endl;
	cout << "    `\"\"'\"':   :'\"'\"'`" << endl;
	cout << "         `@` " << endl;
}

void youreWinner(int number, string winner) {
	cout << "YES! the number is " << number << endl;
	cout << winner << "  you got it man!! " << endl;
	cout << endl;
	cout << "    ___________ " << endl;
	cout << "    '._==_==_=_.'" << endl;
	cout << "    .-\\:      /-." << endl;
	cout << "   | (|:.     |) |" << endl;
	cout << "    '-|:.     |-'" << endl;
	cout << "      \\::.    /" << endl;
	cout << "       '::. .'" << endl;
	cout << "         ) (" << endl;
	cout << "       _.' '._" << endl;
	cout << "      `\"\"\"\"\"\"\"`" << endl;

}

int main() {
	cout << "***************************************" << endl;
	cout << "* Welcome to the number guessing game *" << endl;
	cout << "***************************************" << endl;
	bool bye = false;
	string firstPlayerName = "";
	string secondPlayerName = "";
	srand(time(NULL));

	greeting();
	cout << "Why, hello first player - what's your name? " << endl;
	cin >> firstPlayerName;
	cout << "hummmmm... " << firstPlayerName << " Got it!" << endl;
	cout << "now lemme talk to your friend here" << endl;
	cout << endl;

	greeting();
	cout << "Hi second player - what's your name? " << endl;
	cin >> secondPlayerName;
	cout << "hummmmm... " << secondPlayerName << " Awesome - now we are almost ready to play!" << endl;

	while (!bye) {
		cout << "          _....._" << endl;
		cout << "        .`       `." << endl;
		cout << "       / ***       \\ " << endl;
		cout << "      : Calculating : " << endl;
		cout << "     :  Number from  :" << endl;
		cout << "      :   1 - 100   : " << endl;
		cout << "       \\           /  " << endl;
		cout << "        `-.,,,,,.-'   " << endl;
		cout << "         _(     )_" << endl;
		cout << "        )         (" << endl;
		cout << "       (           )" << endl;
		cout << "       `-........-`" << endl;

		string currentPlayer = "";
		int whoGoesFirst = rand() % 2;
		if (whoGoesFirst == 0) {
			currentPlayer = firstPlayerName;
		}
		else {
			currentPlayer = secondPlayerName;
		}
		int numberToBeFound = rand() % 100 + 1;
		int guess = 0;
		while (guess != numberToBeFound) {
			cout << currentPlayer << " make a guess, please" << endl;
			cin >> guess;
			if (guess != numberToBeFound) {
				if (guess < numberToBeFound) {
					cout << "The number is higher " << endl;
				}
				else if (guess > numberToBeFound) {
					cout << "The number is lower " << endl;
				}
				if (currentPlayer == firstPlayerName) {
					currentPlayer = secondPlayerName;
				}
				else {
					currentPlayer = firstPlayerName;
				}
			}
		}
		youreWinner(numberToBeFound, currentPlayer);
		cout << "Another round (Y/N)?";
		string round = "N";
		cin >> round;
		if (round == "Y") {
			bye = false;
		}
		else {
			bye = true;
		}
	}
	cout << "         /(|" << endl;
	cout << "        (  :" << endl;
	cout << "       __\\  \\  _____" << endl;
	cout << "     (____)  `|" << endl;
	cout << "    (____)|   |" << endl;
	cout << "     (____).__|" << endl;
	cout << "      (___)__.|_____" << endl;
	cout << "***************************************" << endl;
	cout << "* Thank you for playing the  guessing *" << endl;
	cout << "* game - see you around               *" << endl;
	cout << "***************************************" << endl;
}
