/* Author: Sean C Mulholland
 * Date: 10/8/2014
 *
 * This program is designed to help the user determine how to purchase
 * the maximum amount of candy bars and gumballs (with a preference for
 * candy bars) with a user input amount of tickets. The candy bars are
 * worth 10 tickets, and gumballs are worth 3.
 * The user will input the number of tickets they have, and the program
 * will output the amount of candy bars followed by gumballs.
 */

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main() {

	int numberOfTickets; 	//Gets user's tickets

	cout << "This program will help the user decide how many candy bars\n"
		 << "and gumballs they should buy with a set of tickets if the\n"
		 << "user prefers candy bars.\n"
		 << endl;		//Introduction to program

	cout << "Please type the number of tickets you have: ";
	cin >> numberOfTickets;	//Prompts user to input number of tickets

	if (numberOfTickets < 3) { 	//If user enters non-int or too few tickets

		cout << "You can't buy anything! Go win some more tickets!"
		     << endl;

	} else {	//When user has more than 3 tickets

		int numberOfCandyBars = 0,
		    numberOfGumballs = 0;
		while (numberOfTickets >= 10){
			numberOfCandyBars++;
			numberOfTickets -= 10;
		}

		while (numberOfTickets >= 3) {
			numberOfGumballs++;
			numberOfTickets -=3;
		}

		cout << "You should purchase " << numberOfCandyBars << " candy bars,"
			 << "and with the rest\nof the tickets purchase " << numberOfGumballs
			 << " gumballs."
			 << endl;	//Tells user how many of each to buy
	}



	return 0;
}


