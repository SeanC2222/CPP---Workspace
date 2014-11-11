/* Author: Sean C Mulholland
 * Date: Oct 27, 2014
 *
 * refFun.cpp
 * 
 * File purpose: To compare two user input strings using a function call
 * and passing the strings by reference.
 * 
 * Inputs: userString1, userString2
 *
 * Outputs: Whether the strings match or not
 */                                                                          //

#include <iostream>
#include <string>
using namespace std;

/**********************************************/
//  This checks whether two strings passed by //
//  reference are equal char to char          //
//  Inputs: string &userString1,              //
//          string &userString2               //
/**********************************************/
bool stringChecker(string&, string&);

int main() {

	string userString1;
	string userString2;

	cout << "This program compares two user input strings to see if they "
		 << "match. " << endl;
	cout << "Type string 1: ";
	getline(cin, userString1);
	cout << "Type string 2: ";
	getline(cin, userString2);

	if(stringChecker(userString1, userString2)){
		cout << "They match!" << endl;
	} else {
		cout << "Not a match." << endl;
	}
	return 0;
}

bool stringChecker(string &userString1, string &userString2){

	if (userString1.length() != userString2.length()){
		return false;
	} else {
		for (int i = 0; i < userString1.length(); i++){
			if (userString1.at(i) != userString2.at(i)){
				return false;
			}
		}
	}
	return true;
}



