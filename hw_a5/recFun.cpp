/* Author: Sean C Mulholland
 * Date: Oct 27, 2014
 *
 * recFun.cpp
 * 
 * File purpose: This program uses recursion to to produce a Fibonacci
 * number at degree 'n'
 * 
 * Inputs: User inputs 'n'
 *
 * Outputs: Fibonacci numbers up to 'n'
 */                                                                          //

#include <iostream>
#include <string>

using namespace std;

int _Fibonacci(int);
int userPrompt();

int main () {

	char again;

	//Loop to generate as many Fibonacci numbers as the user wants
	do{
		unsigned int n = userPrompt(); 	//Calls prompt, gets 'n'th degree

		int fibNum = _Fibonacci(n); //Generates fibNum at 'n'th degree

		cout << "Your Fibonacci number at degree " << n << " is: "
			 << fibNum << endl;

		cout << "Would you like another? (\'y\'/\'n\') ";
		again = tolower(cin.get());
		cin.ignore(100,'\n');

	} while (again == 'y');

	return 0;
}

/**********************************************/
//  Recursively generates Fib. num's          //
//  Inputs: int n							  //
//  Outputs:                                  //
//  Returns 0 if n = 0 (i.e. call (n-2) = 0)  //
//  Returns 1 if n = 1 (i.e. call (n-1) = 1)  //
/**********************************************/
int _Fibonacci(int n){

	if (n > 1){

		return (_Fibonacci(n-1) + _Fibonacci(n-2));
	} else if (n == 0) {
		return 0;
	} else if (n == 1) {
		return 1;
	}
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
		cout << "Which Fibonacci number would you like? ";
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


