/* Author: Sean C Mulholland
 * Date: 10/7/2014
 *
 *  This is a number guessing game for two users. User 1 will enter a secret number
 *  and user 2 will be prompted for guesses until they are right, or run out of
 *  guesses. The game will also update the user on what guess they are on, and
 *  a range of available guesses left.
 */


#include <iostream>
#include <cstdlib>

using std::cout;
using std::cin;
using std::endl;

int main() {

	cout << "----Welcome to the guessing game!----\n"
		 << "\n"
		 << "This is a two player game where one player enters\n"
		 << "A secret number, and the other player tries to guess\n"
		 << "it. The number must be a whole number between 0 and 1000000!\n"
		 << "Good luck and have fun!" << endl;

	char playAgain = 'y';		//Condition to keep the game running

	while (playAgain == 'y' || playAgain == 'Y'){	//Keeps game running

		unsigned int lowEnd = 0, 	//int to hold low end of range
			 highEnd = 1000,		//int to hold high end of range
			 playerGuess,			//gets User 2 playerGuess
			 secretNumber;			//gets User 1 Secret number

		cout << "Player 1, choose a secret number between 0 and 1000: ";
		cin >> secretNumber;

		if (secretNumber > 1000){	//Conditions to ensure number is in range.
			cout << "Sorry that number is too big. Press \"Enter\" to try again.";
			cin.ignore();
			cin.get();
			continue;
		} else if (secretNumber < 0){
			cout << "Sorry that number is too small. Press \"Enter\" to try again.";
			cin.ignore();
			cin.get();
			continue;
		}

		for(int j = 0; j <200; j++){  	//Clears screen
			cout << endl;
		}

		for (int counter = 1; counter <= 10; counter++){	//User 2 guess counter
			cout << "Player 2, guess number " << counter << " please ("
				 << lowEnd << ", " << highEnd << "): ";
			cin >> playerGuess;

			if (playerGuess == secretNumber){	//Checks if guess is correct
				cout << "YOU GOT IT AFTER " << counter << " GUESSES! Awesome!" << endl;
				break;
			} else if (playerGuess < secretNumber) {	//Checks if guess is low
				cout << "You're too low. Try again." << endl;
				if (playerGuess > lowEnd)
					lowEnd = playerGuess;
			} else {							//If not correct or low, guess is high
				cout << "You're too high. Try again." << endl;
				if (playerGuess < highEnd)
					highEnd = playerGuess;
			}

			if (counter == 10)			//Checks if user 2 is out of guesses
				cout << "Sorry, but you have no more guesses. The secret number was: "
					 << secretNumber << "." << endl;
		}

		cout << "Would you like to play again? (y/n) ";  //Prompts users to play again
		cin >> playAgain;
	}


}
