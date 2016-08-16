/* Author: Sean C Mulholland
 * Date: Oct 27, 2014
 *
 * recConvert.cpp
 * 
 * File purpose: This program will convert binary to decimal and decimal
 * to binary at the users choice from a menu. They can enter whatever
 * positive decimal or positive binary they want to be converted.
 * 
 * Inputs: int menuChoice, int decToBin, string binToDec
 *
 * Outputs: string binary (converted binary), int decimal (converted decimal)
 */                                                                          //
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int displayMenu();
int userPrompt();
string userPromptBin();

string decToBin(int, string);

int binToDec(string, int exp = 0);


int main(){
	int menuChoice, decimal;
	string binary = "";

	do{

		menuChoice = displayMenu();

		switch (menuChoice){
			case 1:
				cout << "Please enter a positive integer to convert to binary: ";
				decimal = userPrompt();
				binary = decToBin(decimal, "");
				cout << "Your binary is: " << binary << endl;
				cout << "Press enter to continue..." << endl;
				cin.get();

				break;
			case 2:
				cout << "Please enter a positive binary to convert to decimal: ";
				binary = userPromptBin();
				decimal = binToDec(binary);
				cout << "Your decimal is: " << decimal << endl;
				cout << "Press enter to continue..." << endl;
				cin.get();

				break;
			case 3:;
		}
	}while (menuChoice !=3);

	return 0;
}

/**********************************************/
//  Converts a decimal integer to a string    //
//  in binary form. Removes powers of 2, and  //
//  recursively builds a string of '1's and   //
//  '0's 									  //
//  Returns: string finalBin (binary form)    //
/**********************************************/
string decToBin(int dec, string finalBin){

	if (dec == 0){			//Checks if decimal has reached limit value
		return "0";				//returns 0 if limit value is 0
	} else if (dec == 1){	//Checks if decimal has reached limit value
		return "1";				//returns 1 if limit value is 1
	} else {
		//Recursive calls based on binary conditions.
		if (dec % 2 == 0){
			finalBin += decToBin(dec / 2, finalBin);
			finalBin += "0";	//Concatenates "0" to the end of finalBin
		} else {
			finalBin += decToBin((dec - 1) / 2, finalBin);
			finalBin += "1";	//Concatenates "1" to the end of finalBin
		}
	}
	return finalBin;
}

/**********************************************/
//  Converts a binary string (bin) to it's    //
//  decimal form as an integer. Recursively   //
//  checks from last string index to first    //
//  and adds appropriate power of 2 to total  //
//  Returns: int dec (final decimal value)    //
/**********************************************/
int binToDec(string bin, int exp){

	int dec = 0;	//Holds temporary values and final returned decimal
	//
	if (bin.length() > 1){

		if(bin.at(bin.length() - 1) == '1'){
			dec += static_cast<int>(pow(2.0, exp));
			dec += binToDec(bin.substr(0,bin.length()-1), ++exp);
		} else {
			dec += binToDec(bin.substr(0,bin.length()-1), ++exp);
		}

	} else {
		if (bin.at(0) == '1'){
			return static_cast<int>(pow(2.0,exp));
		} else {
			return 0;
		}
	}
	return dec;
}


/**********************************************/
//  Displays menu for user to choose from     //
//  getChoice calls userPrompt for valid input//
//  displayMenu() validates user input before //
//  returning getChoice.                      //
//  Outputs:                                  //
//  Menu to console							  //
//  Returns: getChoice to main() to menuChoice//
/**********************************************/
int displayMenu(){
	unsigned short getChoice;
	cout << "This program converts from decimal to binary, or binary to\n"
		 << "decimal.\n"
		 << endl;
	do {
	cout << "1) Decimal to Binary\n"
		 << "2) Binary to Decimal\n"
		 << "3) Exit the program"
		 << endl;

	cout << "Which choice would you like? ";

	getChoice = userPrompt();
	cout << getChoice << endl;
	} while (getChoice != 1 &&
			 getChoice != 2 &&
			 getChoice != 3);

	return getChoice;
}


/**********************************************/
//  Repeatedly prompts user for valid input   //
//  for 'n', ignores negative's and non-digits//
//  Outputs:                                  //
//  Returns 'n' if 'n' is a positive int      //
/**********************************************/
int userPrompt() {
	unsigned int n;		//Stores 'n'
	//Loop to validate input
	do{
		cin.clear();	//Sets state clear for repeat loops
		if (isdigit(cin.peek())){			//Ensures first char is digit
			cin >> n;						//Stores digit as int
			if (cin.peek() != '\n'){		//if cin has other characters
				cin.ignore(100, '\n');		//   clear the buffer
				cin.setstate(ios::failbit); //Set ios::failbit
			}
		} else {						//If first char != digit
			cin.ignore(100,'\n');		//   Clear the buffer
			cin.setstate(ios::failbit); //   Set ios::failbit
		}
	}while (cin.fail());
	cin.ignore(100,'\n');				//Clears buffer
	return n;							//Returns positive int 'n'
}

/**********************************************/
//  Repeatedly prompts user for valid input   //
//  for bin, all characters must be '1' or '0'//
//  Outputs:                                  //
//  Returns bin if bin is binary              //
/**********************************************/
string userPromptBin() {
	string bin;
	do{
		cin.clear();
		getline(cin,bin);
		for(int i = 0; i < bin.length(); i++){
			if (!(bin.at(i) == '1' || bin.at(i) == '0')){
				cin.setstate(ios::failbit);
			}
		}
	}while (cin.fail());
	return bin;
}
