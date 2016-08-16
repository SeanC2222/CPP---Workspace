/* Author: Sean C Mulholland
 * Date: Nov 3, 2014
 *
 * grades.cpp
 * 
 * File purpose: Takes user input grades between 0 and HIGHGRADE and displays
 * a count of each grade, as well as a histogram of the input.
 * 
 * Inputs: 	int studentGrades[]	- Holds number of each grade
 * 			int grade			- grade for each individual student
 *
 * Outputs: int studentGrades[i]- The count of each earned grade
 */                                                                          //
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>

#define HIGHGRADE 5  //Grades entered can be between 0 and HIGHGRADE

using namespace std;

void getGrades(int*);
void displayGraph(int*);

int main() {

	//Creates array to hold student grades;
	int *studentGrades;
	studentGrades = new int[HIGHGRADE + 1];
	for (int i = 0; i < HIGHGRADE + 1; i++){
		studentGrades[i] = 0;
	}

	cout << "This program will count the number of students who earned each\n"
		 << "grade between 0 and " << HIGHGRADE << ". Type \"quit\" to "
		 << "display results and exit." << endl;

	//Gets grade info (0-5) for all students
	getGrades(studentGrades);

	//Displays raw data, and histogram
	displayGraph(studentGrades);

	return 0;
}

/****************************************************************************/
//  Gets user input grades. Validates user input. If user wants to quit,   	//
//  they can type "Quit" and the input stops.								//
//	User inputs: int grades													//
//  Function Call Arguments: int studentGrades[] - Holds count of grades	//
//  Returns: None									    					//
/****************************************************************************/

void getGrades(int studentGrades[]){

	int grade;
	//Loop to enter as many valid grades as user wants.
	do{
		cout << "Please enter a grade between 0 and " << HIGHGRADE << ": ";
		char c = cin.peek();
		if (c == '\n'){
			cin.get();
			c = cin.peek();
		}

		//If input is not integer handle by
		if (!isdigit(c)){
			//Attempt to store as cstring
			char *temp;
			temp = new char[5];
			cin.getline(temp, 5);
			for(int i = 0; i < 5; i++){
				temp[i] = tolower(temp[i]);
			}
			//If storing fails, clear cin buffer
			if (cin.fail()){
				cin.clear();
				cin.ignore(100,'\n');
			}
			//If temp == quit, break from loop
			if (!strcmp(temp,"quit")){
				break;
			//Else report that input was not valid
			} else {
				cout << "Not a valid input." << endl;
			}
		//If input is an integer
		} else {
			//Store in grade
			cin >> grade;
			//If grade is outside range from 0 - HIGHGRADE
			if (grade > HIGHGRADE || grade < 0)
				cout << "Grade is outside range." << endl;
			//Else increment grade
			else
				studentGrades[grade]++;
		}
	}while(cin.good());

	return;
}

/****************************************************************************/
//  Displays user input grades. Outputs a numerical count stored in 	   	//
//  studentGraphs[], and then creates a scaleable histogram of data			//
//	User inputs: None														//
//  Function Call Arguments: int studentGrades[] - Holds count of grades	//
//  Returns: None									    					//
/****************************************************************************/
void displayGraph(int studentGrades[]){
	//Displays raw grade data
	cout << endl;
	for (int i = 0; i < HIGHGRADE + 1; i++){
		cout << "Grades of " << i << ": " << studentGrades[i] << endl;
	}
	cout << endl;

	//Displays vertical histogram of grades
	cout << "Histogram: " << endl;

	int max = 0;
	for (int i = 0; i < HIGHGRADE + 1; i++){
		if (max < studentGrades[i])
			max = studentGrades[i];
	}

	for (int i = 0; i < max; i++){
		cout << setw(3) << right << max - i << "| ";
		for (int j = 0; j < HIGHGRADE + 1; j++){
			if (studentGrades[j] >= (max - i)){
				cout << "x ";
			} else {
				cout << "  ";
			}
		}
		cout << endl;
	}

	cout << setw(4) << right <<  " -";
	for (int i = 0; i < HIGHGRADE + 1; i++){
		cout << "-" << i;
	}

	return;
}
