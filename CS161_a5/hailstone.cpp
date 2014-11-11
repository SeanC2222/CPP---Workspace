/* Author: Sean C Mulholland
 * Date: Oct 27, 2014
 *
 * hailstone.cpp
 * 
 * File purpose: To count the number of steps to reach one in a hailstone
 * sequence from a user input integer. A hailstone sequence takes a given
 * integer and divides by two if its even, or multiplies by three and adds
 * one if it's odd.
 * 
 * Inputs: unsigned int n (must be positive)
 *
 * Outputs: 
 */                                                                          //
#include <iostream>
using namespace std;

int userPrompt();
int hailstone(int, int);

int main() {

	cout << "This program computes the number of steps in a hailstone"
		 << "sequence\n for the user. A hailstone sequence starts with a"
		 << "given integer and if that integer\n is even divides by two"
		 << "and if that integer is odd it multiplies by 3 and adds 1."
		 << endl;
	cout << "This program will count the steps it takes for a sequence to"
		 << "reach\n the number one."
		 << endl;
	char again;

	do{
		unsigned int n = userPrompt();
		int steps = 0;
		steps = hailstone(n, steps);
		cout << "It took " << steps << " steps to reach 1." << endl;
		cout << "Try a new integer? (\'y\'/\'n\') ";
		again = tolower(cin.get());
		cin.ignore(100,'\n');
	}while (again == 'y');
	return 0;
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
		cout << "What number would you like to check? ";
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

int hailstone (int n, int steps){
	if (n == 1){
		return steps;
	} else if (n % 2 == 0){
		return hailstone(n / 2, ++steps);
	} else {
		return hailstone((n*3)+1, ++steps);
	}
	return 0;
}

