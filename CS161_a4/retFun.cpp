/* Author: Sean C. Mulholland
 * Date: Oct 21, 2014
 *
 * retFun.cpp
 * 
 * File purpose: This program accepts two strings and returns whether they
 * have the same contents or not.
 * 
 * Inputs: Two strings (userString1, userString2): Contents of each compared
 *
 * Outputs: Whether or not (userString1 == userString2)
 */                                                                          //

#include <iostream>
#include <string>
using namespace std;

/**********************************************/
//  userStringChecker is passed two strings to//
//  compare and returns true if strings are   //
//  both equal to one another.                //
/**********************************************/

bool userStringChecker(string uS1, string uS2);

int main() {

	string userString1,
		   userString2;

	cout << "Please enter two strings to be compared." << endl;
	cout << "String 1: ";
	getline(cin, userString1);

	cout << "String 2: ";
	getline(cin, userString2);

	if(userStringChecker(userString1, userString2)) {
		cout << "These strings are equal." << endl;
	} else {
		cout << "These strings are not equal." << endl;
	}

	return 0;
}

bool userStringChecker(string uS1, string uS2) {

	if (uS1.length() == uS2.length()){
		for(int i = 0; i < uS1.length(); i++){
			if (uS1.at(i) != uS2.at(i)){
				return false;
			}
		}
		return true;
	} else {
		return false;
	}
}
