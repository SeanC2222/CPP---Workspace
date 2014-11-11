/* Author: Sean C Mulholland
 * Date: Oct 27, 2014
 *
 * randFun.cpp
 * 
 * File purpose: Acts like a random number generator using a function
 * call.
 * Function template used:
 *    void rand_int(const int &min, const int &max, int &val)
 * 
 * Inputs: None.
 *
 * Outputs: Random number stored in val between min and max constants.
 */                                                                          //

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

/**********************************************/
//  Generates random number between min & max //
//  and stores the value in val by reference  //
//  Inputs: int &min, int &max, int &val      //
/**********************************************/
void rand_int(const int&, const int&, int&);

const int MIN = 1;
const int MAX = 100;

int main() {

	srand(time(NULL));

	int val;
	char again;

	cout << "This program will output a random number between 1 and 100.\n"
		 << "Press enter to begin..." << endl;
	cin.ignore(100,'\n');

	do{
		rand_int(MIN, MAX, val);
		cout <<  val << "!!!" << endl;
		cout << "Would you like another random? (\'y\'/\'n\') ";
		again = tolower(cin.get());
		cin.ignore(100,'\n');
	} while (again == 'y');

	return 0;
}

void rand_int(const int &min, const int &max, int &val) {
	val = rand() % (max - min + 1) + min;
	return;
}

