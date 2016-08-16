/* Author: SeanC
 * Date: Oct 21, 2014
 *
 * secretWord.cpp
 * 
 * File purpose: A secret word game where user 1 enters a secret word
 * and player 2 guesses 1 letter at a time.
 * 
 * Inputs: secretWord, letterGuesses
 *
 * Outputs: Updates on the secret word guesses.
 */                                                                          //
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

void _GAMEBODY(string, string&);
bool _letterCheckerCLB(char&, string&);
char _letterCheckerSW(char, string, string&);
bool _winCheck(string, string&);


int main() {

	bool trigger = false;
	char again = 'y';

	cout << "Welcome to the guessing game!" << endl
		 << "User 1 will enter a secret word (no spaces, numbers, or other"
		 << " characters) up to 20 letters." << endl;
	cout << "User 2 will have 10 guesses to figure out the word." << endl;
	do{
		string secretWord = "";
		string clb = "";

		do{
			trigger = false;
			cout << "User 1, enter your secret word: ";
			getline(cin, secretWord);
			for (int i = 0; i < secretWord.length(); i++){
				if (!isalpha(secretWord.at(i))){
					trigger = true;
					break;
				}
			}
		}while(trigger);
		for(int i = 0; i < 100; i++) {cout << endl;}


		_GAMEBODY(secretWord, clb);
		cout << "Play again? (\'y\'/\'n\') ";
		cin.ignore();
		again = cin.get();

	}while (tolower(again) == 'y');
	return 0;
}

void _GAMEBODY (string secretWord, string& clb){
	bool CLB, winCheck;
	char guess;

	for (int guesses = 1; guesses <= 10 ; guesses++){
		//for(int i = 0; i < 100; i++) {cout << endl;}

		do{
			cout << "User 2, enter guess #" << guesses << ": ";
			guess = cin.get();
			cout << endl;
			CLB = _letterCheckerCLB(guess, clb);
		} while (CLB);
		guess = _letterCheckerSW(guess, secretWord, clb);
		cout << "Correct Letters so Far: " << clb << endl;

		for (int i = 0; i < secretWord.length(); i++){
			bool star = false;
			for (int j = 0; j < clb.length(); j++){
				if (tolower(secretWord.at(i)) == tolower(clb.at(j))){
					cout << secretWord.at(i);
					star = true;
				}
				if (j == clb.length()-1 && !star){
					cout << "*";
					star = false;
				}
			}

		}
		cout << endl;
		cin.ignore(100,'\n');

		winCheck = _winCheck(secretWord, clb);
		if (winCheck){
			cout << "User 2 wins!" << endl;
			break;
		}
	}
}

bool _letterCheckerCLB(char& guess, string& clb){

	bool inCLB = false;


	for (int i = 0; i < clb.length(); i++){
		if (tolower(guess) == tolower(clb.at(i))){
			cout << "You already guessed this letter!" << endl;
			return true;
		}
	}
	return inCLB;

}
char _letterCheckerSW(char guess, string secretWord, string& clb){

	for (int i = 0; i < secretWord.length(); i++){
		if (tolower(guess) == tolower(secretWord.at(i))){
			clb += guess;
			return guess;
		}
	}
	return '0';
}

bool _winCheck(string secretWord, string& clb){
	bool check;

	for (int i = 0; i < secretWord.length(); i++){

		check = false;
		for (int j = 0; j < clb.length(); j++){
			if (tolower(secretWord.at(i)) == tolower(clb.at(j))){
				check = true;
				break;
			}
		}
		if (!check)
			return false;
	}
	if (check)
		return true;
}

