// Assignment02.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"

#include "Constants.h"
#include "Philosophers.h"
#include "Player.h"
#include "Shop.h"
#include "Parlour.h"

#include <string>
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;


int main()
{
	srand((unsigned int)time(NULL));

	InitPlayer();
	Intro();
	while (!DOOMSDAY)
	{
		while (!DOOMSDAY)
		{
			char userAnswer = ShopMenu();
			if (userAnswer == 'X')
			{
				cout << "Goodbye!" << endl;
				system("pause");
				return 0;
			}
			break;

		}
		while (!DOOMSDAY)
		{
			char userAnswer = ParlourMenu();
			if (userAnswer == 'X')
			{
				cout << "Goodbye!" << endl;
				system("pause");
				return 0;
			}
			break;
		}
	}
	return 0;
}

