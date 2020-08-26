//============================================================================
// Name        : Dices.cpp
// Author      : Lorenzo Baldari
// Version     : 1.0
// Copyright   : //
// Description : This tool will allow the player to select a dice to play with
//============================================================================

#include <iostream>
#include <cstdlib>
using namespace std;

int DiceSelect(int &max) {		//int& is to pass a value by reference
	int dice = 0;

	std::cout
			<< "Available dices: \n (1) 4 faces \n (2) 6 faces \n (3) 12 faces\n\n Select a dice:"
			<< std::endl;

	std::cin >> dice;

	switch (dice) {
	case 1:
		max = 4;
		break;
	case 2:
		max = 6;
		break;
	case 3:
		max = 12;
		break;
	}
	return max;
}

int Roll(int &max) {
	int roll = 0;
	roll = rand() % (max - 1 + 1) + 1;
	return roll;
}

int main() {
	srand(time(0)); //rancomize seed

	system("clear");

	int roll_max = 0;

	DiceSelect(roll_max);

	system("clear");

	std::cout << "How many rolls do you want to perform? " << std::endl;

	int n = 0;

	std::cin >> n;
	n = n - 1;	//adjust size to array

	for (int i = 0; i < n; i++) {
		Roll(roll_max);
		std::cout << Roll(roll_max) << std::endl;
	}

	return 0;
}
