/* Author: Sean C Mulholland
 * Date: 10/15/2014
 *
 * This program will compare two user input strings and return
 * if they match, character to character. It first checks the length
 * of each string and compares them, and if it passes that test
 * it will compare the components of the strings.
 *
 */

#include <iostream>
#include <string>
using namespace std;

int main() {

	string string1, string2;

	cout << "Please enter your first string: ";
	getline(cin, string1);
	cout << "Please enter your second string: ";
	getline(cin, string2);

	bool stringCheck = (string1.length() == string2.length());

	if (stringCheck){
		cout << "Checking the components...";
		for (int i = 0; i < string1.length(); i++){
			stringCheck = (string1.at(i) == string2.at(i));
			if (!stringCheck)
				break;
		}

	}

	if (stringCheck)
		cout << "These match." << endl;
	else
		cout << "These do not match." << endl;


	return 0;
}
