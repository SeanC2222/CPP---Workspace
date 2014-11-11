/* Author: Sean C Mulholland
 * Date: Nov 4, 2014
 *
 * evenOdd.cpp
 *
 * File purpose: This program accepts a user string and then will scramble
 * the characters randomly as many times as the user wants.
 *
 * Inputs: char *str1		Dynamically Allocated array for original string
 *         char *str2	    Dynamically Allocated array for mixed string
 *         char again		Repeat condition for stringMixer
 *
 * Outputs: char *str2		Mixed string stored on heap
 */                                                                          //
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;

void stringMixer(char*,char*);

int main() {

	srand(time(NULL));
	char again;

	char *str1, *str2;

	str1 = new char[150];
	cout << "This program will scramble the letters in a phrase for you.\n"
		 << "Please enter your phrase: ";
	cin.getline(str1,150);

	str2 = new char[strlen(str1)];

	//Mixes string as often as user wants
	do{

		stringMixer(str1,str2);

		cout << "\nWould you like your word scrambled again? (\'y\'/\'n\') ";
		again = tolower(cin.get());
		cin.ignore();

	}while (again == 'y');

	return 0;
}

/****************************************************************************/
//  Pulls random positions of str1 to store in str2 until all positions   	//
//  have been pulled. str2 contains the mixed string						//
//	User inputs: None														//
//  Function Call Arguments: char str1[]    Stores original string			//
//							 char str2[]	Stores mixed string				//
//  Returns: None									    					//
/****************************************************************************/
void stringMixer (char str1[], char str2[]){

	int index = 0, tempRand;
	bool isNewLetter;

	//Creates array with contents equal to string length of str1 because
	//str1[strlen(str1)] is out of usable index of characters.
	int *usedLetters;
	usedLetters = new int[strlen(str1)];
	for (int i = 0; i < strlen(str1); i++){
		*(usedLetters + i ) = strlen(str1);
	}
	//Pulls positions for str1, checks if it's been pulled before, and
	//stores the position if the letter is unique, or discards number if
	//number has been pulled before.
	while (index < strlen(str1)){
		isNewLetter = false;	//Trigger if letter has been used before
		tempRand = rand() % strlen(str1);	//Random position of str1

		for (int i = 0; i <= index; i++){
			if (tempRand == usedLetters[i]){ //If position has been pulled
				isNewLetter = false;		 //Letter is not new
				break;
			} else {
				isNewLetter = true;		     //Else letter is new
			}
		}

		if (isNewLetter){					 //If letter is new
			usedLetters[index] = tempRand;	 //Store the position
			str2[index] = str1[tempRand];	 //Store the letter in str2
			index++;						 //Increment storage index
		}
	}

	cout << "\nYour string: " << setw(strlen(str1+1)) << str1 << endl;
	cout << "\nYour scrambled string: " << setw(strlen(str1)+1) << str2 << endl;
	delete(usedLetters);	//Deconstructs *usedLetters
	return;
}
