/* Author: Sean C Mulholland
 * Date: 10/15/2014
 *
 * This program is designed to accomplish 4 things:
 *
 *    1. Accept a user input string, and output all the characters individually
 *       from string index i = 0
 *    2. Accept a user input string, and output all the characters individually
 *       from string index i = string.length() - 1
 *    3. Accept a user input string and count all the letters in the string
 *    4. Accept a multiword user input string, and count all the letters using
 *       (two versions of this are implemented to illustrate a getline()
 *       solution, and a multiword cin solution.
 */

#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main () {

	cout << "This program is designed to perform 4 functions 1 after another.\n"
		 << "The first will accept a single token input string from the user, \n"
		 << "and output the word back to the user 1 character at a time from \n"
		 << "The first letter. Press enter to continue...";
	cin.ignore();
	for (int i = 0; i < 50; i++)
		cout << endl;

	cout << "The second function is to print it back to the user 1\n"
		 << "character at a time at a time from the last letter to the first.\n"
		 << "Press enter to continue...";
	cin.ignore();
	for (int i = 0; i < 50; i++)
		cout << endl;

	cout << "The third function is to count up all the alphabetic\n"
		 << "characters in the token.\n"
		 << "Press enter to continue...";
	cin.ignore();
	for (int i = 0; i < 50; i++)
		cout << endl;

	cout << "The final function will perform twice, but will function\n"
		 << "differently on the backend. It will accept a multi-token input \n"
		 << "and count all the alphabetic characters for the user.\n"
		 << "Press enter to continue...";
	cin.ignore();
	for (int i = 0; i < 50; i++)
		cout << endl;

	string str;

	cout << "Please type your token: ";
	cin >> str;

	for (unsigned int i = 0; i < str.length(); i++)
		cout << str.at(i);
	cout << endl;

	for (int i = str.length() - 1; i >= 0; i--)
		cout << str.at(i);
	cout << endl;

	for (unsigned int i = 0, letters = 0; i < str.length(); i++) {
		if (isalpha(str.at(i)))
			letters++;
		if (i == str.length() - 1)
			cout << "This token has " << letters << " letters.";
	}
	cout << endl;

	cin.ignore(200,'\n');

	cout << "1) Please type a multi-token phrase: ";

	int totalLetters = 0;

	while (cin >> str){

		for (unsigned int i = 0, letters = 0; i < str.length(); i++){
			if (isalpha(str.at(i)))
				letters++;
		    if (i == str.length() - 1)
		    	totalLetters += letters;
		}
		if (cin.peek() == '\n') {
			break;
		}
	}
	cout << "There are " << totalLetters << " letters in that phrase." << endl;
	getline (cin, str);
	totalLetters = 0;

	cout << "2) Please type a multi-token phrase: ";
	getline(cin, str);

	for (unsigned int i = 0; i < str.length(); i++){
		if (isalpha(str.at(i)))
			totalLetters++;
	}

	cout << "There are " << totalLetters << " letters in that phrase." << endl;

	return 0;

}


