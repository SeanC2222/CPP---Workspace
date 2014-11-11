/* Author: Sean C Mulholland
 * Date: 10/15/2014
 *
 * This program will ask the user for the minimum and maximum value of
 * a range of numbers that they would like the possibility to be generated.
 * The program then validates the input numbers are integers,
 * and outputs a random number between minValue and maxValue.
 *
 */


#include <iostream> //cin, cout, endl
#include <cstdlib>  //rand(), srand()
#include <string>   //string
#include <sstream>  //stringstream() --Used in input validation
#include <ctime>    //time()

using namespace std;

//Gets valid user integers
int intChecker ();

int main() {

	srand(time(NULL));	//Seeds random differently every program execution

	cout << "This program will generate a random number between two user\n"
		 << "input positive integers." << endl;

	//Gets minValue and maxValue of range from user
	cout << "Enter the minimum value for the random int range: ";
	int minValue = intChecker();
	cout << "Enter the maximum value for the random int range: ";
	int maxValue = intChecker();

	//Absolute value of range magnitude
	int range = abs(maxValue - minValue);

	//Swaps variables if minValue > maxValue
	if (minValue > maxValue) {
		int hold;
		hold = minValue;
		minValue = maxValue;
		maxValue = hold;
	}

	//Checks to prevent divide by zero errors. If Range = 0,
	//_Random = minValue = maxValue
	int _RANDOM;
	if (range > 0)
		_RANDOM = rand() % range + minValue;
	else
		_RANDOM = minValue;

	//Outputs random number within range
	cout << "Random Number between " << minValue
	     << " and " << maxValue << " is "
	     << _RANDOM << endl;

	return 0;
}

int intChecker () {

	unsigned int i = 0;
	string checkString;

	getline(cin, checkString);

	while (i < checkString.length()){

		if (!isdigit(checkString[i])) {
		   cout << "Not a positive integer please try again: ";
		   i = 0;
		   getline(cin, checkString);
		} else {
			i++;
		}
	}
	stringstream(checkString) >> i;

	return i;

}
