/* Author: SeanC
 * Date: Nov 3, 2014
 *
 * arrayAdd.cpp
 * 
 * File purpose: To add the contents of two user generated arrays. The arrays
 * (first, and second) will both be of user chosen size, arraySize and will
 * sum together using pointer arithmetic into third.
 * 
 * Inputs:	int arraySize		The size of arrays first, second and third
 * 			int *first			The first array of user integers to add
 * 			int *second			The second array of user integers to add
 * 			int *third			The "sum array" (holds sum of first and second)
 *
 * Outputs: int *third			The "sum array" is output one index at a time
 */                                                                          //
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void arrayAddition(int*, int*, int*, int);
void displayResults(int*, int);

int main() {

	int *first, *second, *third, arraySize;
	//Input validation of arraySize
	do{
		cin.clear();
		cout << "How many numbers in each set would you like to add? ";
		if(cin >> arraySize){
			if (cin.peek() != '\n'){
				cin.ignore(100,'\n');
				cin.setstate(ios::failbit);
			}
		} else {
			cin.clear();
			cin.ignore(100,'\n');
			cin.setstate(ios::failbit);
		}
	}while (cin.fail());
	//Create 3 equally sized arrays on the heap
	first = new int[arraySize];
	second = new int[arraySize];
	third = new int[arraySize];
	//Gets values for first
	for (int i = 0; i < arraySize; i++){
		cout << "What value would you like to store at element " << i
		     << " in your first array? ";
		//Input Validation for first
		do{
			cin.clear();
			if(cin >> *(first + i)){
				if (cin.peek() != '\n'){
					cin.ignore(100,'\n');
					cin.setstate(ios::failbit);
				}
			} else {
				cin.clear();
				cin.ignore(100,'\n');
				cin.setstate(ios::failbit);
			}
		}while(cin.fail());
	}
	//Gets values for second
	for (int i = 0; i < arraySize; i++){
		cout << "What value would you like to store at element " << i
		     << " in your second array? ";
		//Input Validation for second
		do{
			cin.clear();
			if(cin >> *(second + i)){
				if (cin.peek() != '\n'){
					cin.ignore(100,'\n');
					cin.setstate(ios::failbit);
				}
			} else {
				cin.clear();
				cin.ignore(100,'\n');
				cin.setstate(ios::failbit);
			}
		}while(cin.fail());
	}
	//Adds arrays, and displays results
	arrayAddition(first, second, third, arraySize);
	displayResults(third, arraySize);
	return 0;
}

/****************************************************************************/
//  Sums the equivalent indices of first and second and stores sum in third	//
//	User inputs: None														//
//  Function Call Arguments: 												//
//			int first[]		First array of integer values					//
//			int second[]	Second array of integer values					//
//			int third[]		The "sum array", stores sum of first + second   //
//			int arraySize	Size of arrays being added by user				//
//  Returns: None									    					//
/****************************************************************************/
void arrayAddition(int first[], int second[], int third[], int arraySize){

	for (int i = 0; i < arraySize; i++){
		*(third + i) = *(first + i) + *(second + i);
	}
	return;
}

/****************************************************************************/
//  Displays the sum of first and second by outputting third				//
//	User inputs: None														//
//  Function Call Arguments: 												//
//			int third[]		The "sum array", stores sum of first + second   //
//			int arraySize	Size of arrays being added by user				//
//  Returns: None									    					//
/****************************************************************************/
void displayResults(int third[], int arraySize){

	cout << "Your final values are: " << endl;
	cout << "sum = [";
	for(int i = 0; i < arraySize; i++){
		if (i == arraySize - 1){
			cout << *(third + i) << "]" << endl;
		} else {
			cout << *(third + i) << ", ";
		}
	}

	return;
}

