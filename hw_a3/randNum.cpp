/* Author: Sean C Mulholland
 * Date: 10/15/2014
 *
 * This program will ask the user for how many random numbers they would
 * like and then output a table of random numbers between 1 and 1000.
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <sstream>
#include <ctime>

using namespace std;

int main() {

	unsigned int numbers = 0;
	string sNumbers;

	srand(time(NULL));

	do {
	cout << "How many random numbers between 1 and 1000 would you like? ";

		getline(cin, sNumbers);

		for (int i = 0; i < sNumbers.length(); i++){
			if (!isdigit(sNumbers[i])){
				cout << "Please enter a positive whole number.\n" ;
				break;
			}
			if (i == sNumbers.length() -1)
				stringstream(sNumbers) >> numbers;
		}
	} while (numbers <= 0);


	for (int i = 1; i <= numbers; i++){
		cout << "~------~\n"
			 << "|" << setw(6) << right << rand() % 1000 + 1 << "|\n";
	}
	cout << "~------~\n";



}
