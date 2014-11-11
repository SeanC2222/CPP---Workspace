/* Author: SeanC
 * Date: Nov 3, 2014
 *
 * wordShift.cpp
 * 
 * File purpose: Accept a user input string and allow the user to shift the
 * string left or right by an user input magnitude, or reverse the string.
 * User can choose when to quit.
 * 
 * Inputs: 	char *userString	User input string to manipulate
 * 			char *pChoice		Command input (switch condition)
 * 			int *index			Command choice magnitude
 *
 * Outputs: char *userString	User input string during/after manipulations
 */                                                                          //

#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>

using namespace std;

void getUserString(char*);
void displayMenu();
void getChoice(char*, int*);

void reverse(char*);
void shiftRight(char*, int*);
void shiftLeft(char*, int*);

int main(){

	char *pChoice, *userString;
	pChoice = new char;
	userString = new char[300];
	int *index;
	index = new int;
	*index = 0;

	int counter = 0;	//displayMenuCondtion

	cout << "This program will manipulate a word or sentence by shifting the\n"
		 << "left, right, or reversing them. It will prompt you for your\n"
		 << "word or sentence, and then ask you how you want to manipulate it."
		 << endl;

	//Gets *userString value
	getUserString(userString);

	//Repeatedly manipulates *userString
	do{
		if (counter % 5 == 0){	//calls displayMenu every 5 commands
			for (int i = 0; i < 100; i++){
				cout << endl;
			}
			displayMenu();
			counter = 0;
		}
		//Updates user on their current *userString state
		cout << endl
			 << "Your word is: " << userString << endl
			 << "Your command: ";
		getChoice(pChoice, index);
		counter++;
		//*pChoice determines which manipulation to call, else error
		switch(*pChoice){
			case 'L':
				shiftLeft(userString, index);
				break;
			case 'R':
				shiftRight(userString, index);
				break;
			case 'r':
				reverse(userString);
				break;
			case 'Q':
				break;
			default:
				cout << endl;
				cout << "Entry not valid, please try again." << endl;
		}
	}while (*pChoice != 'Q');

	return 0;
}

/****************************************************************************/
//  Gets userString value. Under 300 characters								//
//	User inputs: char userString[]											//
//  Function Call Arguments: char *userString	Points to userString on heap//
//  Returns: None									    					//
/****************************************************************************/
void getUserString(char *userString){

	for (int i = 0; i < 300; i++){
		userString[i] = '\0';
	}
	do{
		cout << "Please enter your word or sentence: ";
		cin.getline(userString, 300);

	}while (strlen(userString) == 1);
	return;
}

/****************************************************************************/
//  Displays command choices for user										//
//	User inputs: char userString[]											//
//  Function Call Arguments: None											//
//  Returns: None									    					//
/****************************************************************************/
void displayMenu(){
	cout << endl;
	cout << "What would you like to do?\n"
		 << "Commands:\n"
		 << " R# - Shifts all characters right by index #\n"
		 << " L# - Shifts all characters left by index #\n"
		 << " rev - Reverses the order of all characters\n"
		 << " quit - Ends program and outputs final word/sentence\n"
		 << endl;
	return;
}

/****************************************************************************/
//  Gets user command choice and magnitude									//
//	User inputs: string choice		Gets user command & magnitude			//
//  Function Call Arguments: char *pChoice	Points to user's command choice	//
//							 int *index		Holds command magnitude			//
//  Returns: None									    					//
/****************************************************************************/
void getChoice(char *pChoice, int *index){

	string choice;
	//Stores user command & magnitude in choice
	cin >> choice;
	//If extra characters left over, ignore them
	if(cin.peek() != '\n'){
		cin.ignore(100, '\n');
	}
	//Changes all case to lower
	for (int i = 0; i < choice.length(); i++){
		choice[i] = tolower(choice[i]);
	}
	//If command is "rev" store 'r' to call reverse()
	if (choice == "rev"){
		*pChoice = 'r';
		return;
	}
	//If command is "quit" store 'Q' to break out of command loop
	if(choice == "quit"){
		*pChoice = 'Q';
		return;
	}
	//If command is alpha at index 0, store letter at pChoice
	if(isalpha(choice.at(0))){
		*pChoice = toupper(choice.at(0));
	//Else pChoice gets default and index = 0;
	} else {
		*pChoice = 'd';	//'d' for default return
		*index = 0;
		return;
	}
	//After command has been parsed, parse magnitude of command
	choice = choice.substr(1,choice.length());
	//If choice contains non-integers, pChoice gets default and
	//index gets 0
	for (int i = 0; i < choice.length(); i++){
		if(!isdigit(choice.at(i))){
			*pChoice = 'd';
			*index = 0;
			return;
		}
	}
	//Store choice at index
	*index = atoi(choice.c_str());
	return;
}
/****************************************************************************/
//  Reverses userString (called str[])										//
//	User inputs: None														//
//  Function Call Arguments: char str[]		Alias for userString			//
//  Returns: None									    					//
/****************************************************************************/
void reverse(char str[]){

	char *rts;
	rts = new char[strlen(str)];

	for(int i = 0; i < strlen(str); i++){
		rts[i] = str[strlen(str) - 1 - i];
	}

	for(int i = 0; i <strlen(str); i++){
		str[i] = rts[i];
	}
	str[strlen(str)] = '\0';

	delete[] rts;

	return;
}

/****************************************************************************/
//  Shifts contents of userString right by magnitude *index.				//
//	User inputs: None														//
//  Function Call Arguments: char str[]		Alias for userString			//
//							 int *index		Points to magnitude of command	//
//  Returns: None									    					//
/****************************************************************************/
void shiftRight(char str[], int *index){
	//Can only shift right by magnitude < strlen(str)
	*index %= strlen(str);
	//Temporary string to hold overflow values
	char *tempString;
	tempString = new char[*index + 1];
	//Initializes tempString to NULL Terminator
	for(int i = 0; i <= *index; i++){
		tempString[i] = '\0';
	}
	//tempString gets excess characters of str (str[i + *index] > strlen(str))
	for(int i = 0; strlen(str) - *index + i < strlen(str) ; i++){
		tempString[i] = str[strlen(str) - *index + i];
	}
	//strlen(str) - 1 = last character in string (null terminator left intact)
	//strlen(str) - 1 - (*index + i) = Starts at (last char of string - *index)
	//Moves non-overflow characters to the right (excluding null term)
	for(int i = 0; *index + i < strlen(str); i++){
		str[strlen(str) - 1 - i] = str[strlen(str) - 1 - (*index + i)];
	}
	//Overflow characters are inserted at beginning of string
	for (int i = 0; i < *index; i++){
		str[i] = tempString[i];
	}
	//Ensures null terminator is in place
	str[strlen(str)] = '\0';
	//Deconstructs tempString
	delete[] tempString;
	return;
}
/****************************************************************************/
//  Shifts contents of userString left by magnitude *index.					//
//	User inputs: None														//
//  Function Call Arguments: char str[]		Alias for userString			//
//							 int *index		Points to magnitude of command	//
//  Returns: None									    					//
/****************************************************************************/
void shiftLeft(char str[], int *index){
	//Temporary string to hold overflow values
	char *tempString;
	tempString = new char[*index + 1];
	for(int i = 0; i <= *index; i++){
		tempString[i] = '\0';
	}
	//Can only shift left by magnitudes < strlen(str)
	*index %= strlen(str);
	//Stores overflow characters in tempString
	for(int i = 0; i < *index; i++){
		tempString[i] = str[i];
	}
	//Moves non-overflow characters to the left (excluding null term)
	for (int i = 0; i + *index <= strlen(str); i++){
		str[i] = str[*index + i];
	}
	//Concatenates tempString at end of str
	strcat(str,tempString);
	//Deconstructs tempString
	delete[] tempString;
	return;
}
