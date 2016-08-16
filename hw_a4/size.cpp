/* Author: SeanC
 * Date: Oct 21, 2014
 *
 * size.cpp
 * 
 * File purpose: This program will compute clothing sizes for the user.
 *    hat size = (weight in pounds / height in inches) * 2.9
 *    jacket size = (height * weight) / 288 + 1/8 * every 10 years over 30
 *    waist in inches = weight / 5.7 + .1 for every 2 years over 28
 *
 * Inputs:
 *    double height (inches), double weight (lbs), double age (years)
 * Outputs: 
 *   hat size, jacket size, waist in inches
 */                                                                          //
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

void hatSize (double, double);
void jacketSize (double, double, double);
void waistSize (double, double);
void changeVariable (double&, string);

int main () {

	double height, weight, age;
	int choice = 1;
	bool trigger;
	string tempString;

	cout << "This program can be used to estimate clothing size.";

	changeVariable(height, "height");
	changeVariable(weight, "weight");
	changeVariable(age, "age");

	do {
		for (int i = 0; i < 125; i++) {cout << endl;}
		cout << "What would you like to change? " << endl
			 << "1. Hat Size " << endl
			 << "2. Jacket Size " << endl
			 << "3. Waist Size " << endl
			 << "4. Change Your Information" << endl
			 << "5. Exit" << endl;

		cout << "What size would you like? ";
		cin >> choice;
		cin.ignore(200, '\n');

		switch (choice) {

			case 1:
				hatSize(height, weight);
				break;
			case 2:
				jacketSize(height, weight, age);
				break;
			case 3:
				waistSize(weight, age);
				break;
			case 4:
				for (int i = 0; i < 125; i++) {cout << endl;}
				cout << "What would you like to change? " << endl
				     << "1. height " << endl
				     << "2. weight " << endl
				     << "3. age " << endl
				     << "4. none " << endl;
				do{
					trigger = false;
					cout << "Type the number of your choice: ";
					getline(cin, tempString);
					for (int i = 0; i < tempString.length(); i++){
						if (!isdigit(tempString.at(i))){
							trigger = true;
							break;
							}
						}
				}while (trigger);

				int subChoice;
				subChoice = atoi(tempString.c_str());

				switch (subChoice){
					case 1:
						changeVariable(height, "height");
						break;
					case 2:
						changeVariable(weight, "weight");
						break;
					case 3:
						changeVariable(age, "age");
						break;
					case 4:
						break;
				}
				break;

			case 5:
				choice = 0;
				break;
		}

	} while (choice);
}

void hatSize (double height, double weight){
	cout << "Your hat size is: " << ((weight / height) * 2.9) << endl;
	cout << "Press enter..." << endl;
	cin.ignore(100,'\n');
	return;
};
void jacketSize (double height, double weight, double age){
	if (age > 30){
		age = static_cast<int>((age-30) / 10);
	} else {
		age = 0;
	}
	cout << "Your jacket is: " << ((height * weight) / 288 + age * (1.0/8.0)) << endl;
	cout << "Press enter..." << endl;
	cin.ignore(100,'\n');
	return;
};
void waistSize (double weight, double age){
	if (age > 28){
		age = static_cast<int>((age - 28.0) / 2.0);
	} else{
		age = 0;
	}
	cout << "Your waist size is: " << ((weight / 5.7) + age * 0.1) << endl;
	cout << "Press enter..." << endl;
	cin.ignore(100,'\n');
	return;
};
void changeVariable (double& varHWA, string varName) {
	cout << "What is your new " << varName << "? ";
	cin >> varHWA;
	if(cin.fail()) {
		cin.clear();
		cin.ignore(100,'\n');
	}
	cout << "Press enter..." << endl;
	cin.ignore(100,'\n');
	return;
};


