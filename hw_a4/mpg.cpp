/* Author: Sean C. Mulholland
 * Date: Oct 21, 2014
 *
 * mpg.cpp
 * 
 * File purpose: Allows user to determine their gas mileage in miles per
 * gallon.
 * 
 * Inputs: Gas usage in liters, and miles traveled
 *
 * Outputs: Gas efficiency in miles per gallon
 */                                                                          //

#include <iostream>
#include <cstdlib>

using namespace std;

/**********************************************/
//  Solves and outputs the miles per gallon   //
//  Inputs: double liters, double miles       //
/**********************************************/
double findsMPG (double, double);

const double GperL = 0.264179; //Gallons in a liter

int main () {

	cout << "This program will find miles per liter and convert that" << endl
		 << "to miles per gallon." << endl;

	string tempString;
	bool trigger = false;
	char again;

	do {

		do {
			trigger = false;
			cout << "How many liters of gas were used? ";
			getline(cin, tempString);
			for (int i = 0, decimalCount = 0; i < tempString.length(); i++){
				if (!isdigit(tempString.at(i))){
					if (tempString.at(i) == '.'){
						decimalCount++;
					} else {
						trigger = true;
						break;
					}
				}
				if (decimalCount > 1){
					trigger = true;
				}
			}
		} while (trigger);

		double liters = atof(tempString.c_str());

		do {
			trigger = false;
			cout << "How many miles were traveled? ";
			getline(cin, tempString);
			for (int i = 0, decimalCount = 0; i < tempString.length(); i++){
				if (!isdigit(tempString.at(i))){
					if (tempString.at(i) == '.'){
						decimalCount++;
					} else {
						trigger = true;
						break;
					}
				}
				if (decimalCount > 1){
					trigger = true;
				}
			}
		} while (trigger);

		double miles = atof(tempString.c_str());

		double MPG = findsMPG(liters, miles);

		cout << "Your gas mileage is: " << MPG << " mpg." << endl;

		cout << "Compute again? (\'y\'/\'n\') ";
		again = cin.get();
		cin.ignore(300,'\n');

	} while (again == 'y');

	return 0;
}

double findsMPG(double liters, double miles){
	if (!miles){
		return 0;
	} else {
		return (miles / (liters * GperL));
	}
}



