/* Author: Sean C Mulholland
 * Date: 10/15/2014
 *
 * This program will take a user input name with or without a middlename
 * or initial, and rearrange it to the following format and output it:
 *
 * 			Last_Name, First_Name Mid_Init.
 *
 * 		eg. Mulholland, Sean C.
 */

#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main() {

	//tempName is used to find the name length before concatenating to fullName
	string tempName, fullName = "";
	int nameCounter = 0, firstNameLength; //gets name lengths

	//Program user introduction
	cout << "This program will rearrange your name to the following "
		 << "format:\n\n\tLast_Name, First_Name Middle_Initial.\n\n"
		 << "For example:\n\n\tDoe, Jon C.\n\n"
		 << "Please enter your full name: ";

	//fullName gets user name with no whitespace and
	//firstNameLength gets the first name length
	while (cin.peek() != '\n'){
		cin >> tempName;
		if (nameCounter == 0)
			firstNameLength = tempName.length();
		fullName += tempName;
		nameCounter++;

	}
    if (tempName == fullName){
    	cout << tempName << endl;
    } else {
	//outputs Last_Name, First Name to console
	cout << static_cast<char>(toupper(tempName.at(0))) //uppercase first letter
		 << tempName.substr(1, tempName.length() - 1)	//last name
		 << ", "										//formatting
		 << static_cast<char>(toupper(fullName.at(0))) //uppercase first letter
		 << fullName.substr(1, firstNameLength - 1);	//first name

		//if there is a middle initial, output to console
		if (nameCounter > 2) {
			cout << " " << static_cast<char>(toupper(fullName.at(firstNameLength)))
		     << "." << endl;
		} else {
			cout << endl;
		}
    }
    return 0;
}
