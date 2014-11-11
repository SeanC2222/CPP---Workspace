/* Author: Sean C. Mulholland
 * Date: Oct 21, 2014
 *
 * randFun.cpp
 * 
 * File purpose: To operate as a random number generator for the user
 * 
 * Inputs: The user will input a lower limit(minValue) and an upper limit
 * (maxValue).
 *
 * Outputs: _RANDOM generates a random number between the limits to be output.
 */                                                                          //

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

/**********************************************/
//  Generates a random number between input   //
//  user integers.                            //
//  Inputs: int min, int max                  //
/**********************************************/
void _RANDOM(int, int);

/**********************************************/
//  Checks if user input is an integer.       //
//  Inputs: None                              //
/**********************************************/
int _intChecker(); //Checks if input is integer

int main () {
	char again;
	int minValue, maxValue;
	cout << "This program will generate a number between two input integers.";
	cout << endl;

	do{
		cout << "Minimum Value: " << endl;
		minValue = _intChecker();
		cout << "Maximum Value: " << endl;
		maxValue = _intChecker();
		if (maxValue < minValue){
			int temp = minValue;
			minValue = maxValue;
			maxValue = temp;
		}
		_RANDOM(minValue, maxValue);
		cout << "Start over? (\'y\'/\'n\') ";
		again = tolower(cin.get());
		cin.ignore(300,'\n');

	}while (again == 'y');

	return 0;
}

int _intChecker(){

	bool trigger = false;
	string tempInt;

	do{
		cout << "Please input an integer: ";
		getline(cin, tempInt);
		for (int i = 0; i < tempInt.length(); i++){
			if (!isdigit(tempInt.at(i))){
				trigger = true;
				break;
			} else {
				trigger = false;
			}
		}

	}while(trigger);
	return (atoi(tempInt.c_str()));
}

void _RANDOM (int min, int max){

	char again;
	srand(time(NULL));
	do{
		cout << "Your range is " << min << "-" << max << endl;
		if (min == max){
			cout << "Your random number is: " << min << endl;
	} else {
		cout << "Your random number is: " << (rand()%(max-min+1) + min) << endl;
	}
	cout << "Would you like another between these limits? (\'y\'/\'n\')";
    again = tolower(cin.get());
    cin.ignore(300, '\n');
	}while (again == 'y');
	return;

}
