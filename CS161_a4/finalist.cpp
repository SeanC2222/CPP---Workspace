/* Author: SeanC
 * Date: Oct 21, 2014
 *
 * finalist.cpp
 * 
 * File purpose: This program is used for selecting 4 winners from a pool of
 * 25.
 * 
 * Inputs: none
 *
 * Outputs: 4 winners numbers
 */                                                                          //

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {

	srand(time(NULL));

	cout << "This program will pick 4 winners from a group of 25."<< endl;
	cout << "Press enter to continue..." << endl;
	cin.ignore();

	int winners[4] = {0};

	int numWinners = 0;
	srand(time(NULL));

	while (numWinners < 4){

		bool alreadyPicked = false;

		int winner = rand() % 25 + 1;

		for (int i = 0; i < 4; i++){
			if (winner == winners[i]){
				alreadyPicked = true;
			}
		}

		if (!alreadyPicked){
			winners[numWinners] = winner;
			numWinners++;
		}


	}

	cout << "Numbers: ";
	for (int i = 0; i < 4; i++){
		cout << winners[i] << " ";
	}
	cout << "are the winners!!!" << endl;

	return 0;
}


