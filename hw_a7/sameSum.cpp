/* Author: SeanC
 * Date: Nov 11, 2014
 *
 * sameSum.cpp
 * 
 * File purpose: This program checks if an array's contents have the same sum
 * across each row, down each columns, and across each major diagonal.
 *
 * The user enters the size of the array (dimensions ixi) they want to check,
 * and then enters the contents of each row. After the array is filled
 * the program checks the sums, and returns true if the sums are all equal
 * and false if they are not equal.
 * 
 * Inputs:	int arraySize		User input size of array to check
 * 			int userArray[i][j]	User array that holds input values
 *
 * Outputs: bool sumsEqual		Returns true if all sums are equal, false if no
 */                                                                          //

#include <iostream>
#include <iomanip>

using namespace std;

int **getArray(int**, int*);
int getArraySize();
void populateArray(int**, int*);

bool checkArray(int**, int*);
bool checkRowsAndColumns(int**, int*, int*);
bool checkDiagonals(int**, int*, int);

int main() {

	cout << "This program will check the contents of an user generated\n"
		 << "integer array to see if each row, each column, and each major\n"
		 << "diagonal sums to the same value." << endl;

	int **userArray;

	int *arraySize;
	arraySize = new int;

	userArray = getArray(userArray, arraySize);

	if(checkArray(userArray, arraySize)){
		cout << "The sums are all equal!" << endl;
	} else {
		cout << "The sums are not the same." << endl;
	}

	return 0;
}

/****************************************************************************/
//  Calls getArraySize to get array size, and calls populateArray to 		//
//	input data. Returns userArray to main()									//
//	User inputs: None														//
//  Function Call Arguments: int **userArray	user input array			//
//							 int *arraySize		user input array dimension	//
//  Returns: userArray								    					//
/****************************************************************************/
int **getArray(int **userArray, int *arraySize){

	*arraySize = getArraySize();
	userArray = new int*[*arraySize];
	for (int i = 0; i < *arraySize; i++)
		*(userArray + i) = new int[*arraySize];

	populateArray(userArray, arraySize);

	return userArray;
}

/****************************************************************************/
//  Prompts user for arraySize until valid size is chosen. Value is returned//
//	User inputs: int tempArraySize	Value to be tested for validity			//
//  Function Call Arguments: None											//
//							 												//
//  Returns: int tempArraySize		arraySize		    					//
/****************************************************************************/
int getArraySize(){

	int tempArraySize = 0;
	do {
		cout << "How big would you like your array? ";
		if(cin >> tempArraySize){
			if (cin.peek()!= '\n'){
				tempArraySize = 0;
				cin.ignore(100,'\n');
			}
		} else {
				cin.clear();
				cin.ignore(100,'\n');
		}
	} while (tempArraySize <= 0);
	cout << endl;
	return tempArraySize;
}
/****************************************************************************/
//  Prompts user for arraySize until valid size is chosen. Value is returned//
//	User inputs: int userArray[][]	Holds values in to be checked for sums	//
//  Function Call Arguments: int userArray[][]	Holds values to be checked	//
//							 int *arraySize		size of user array			//
//  Returns: None									    					//
/****************************************************************************/
void populateArray(int **userArray, int *arraySize){
	char again;
	do{
		//Gets values to store at each index
		for (int i = 0; i < *arraySize; i++){

			int j = 0;
			while (j < *arraySize){
				cout << "Please enter an integer for [" << i << "][" << j << "]: ";
				if(cin >> userArray[i][j]){
					cin.ignore(100,'\n');
					j++;
					continue;
				} else {
					cin.clear();
					cin.ignore(100,'\n');
					cout << "Improper input.\n";
				}
			}
		}
		cout << endl;
		//Displays array for confirmation
		cout << "Your array: " << endl;
		for (int i = 0; i < *arraySize; i++){
			cout << "[";
			for (int j = 0; j < *arraySize; j++){
				cout << setw(3) << userArray[i][j];
				if (j == *arraySize -1){
					cout << "]";
				} else {
					cout << ", ";
				}
			}
			cout << endl;
		}
		cout << "Are you happy with your array? (\'y\'/\'n\') ";
		cin >> again;
	}while (tolower(again) == 'n');
	cout << endl;
	return;
}

/****************************************************************************/
//  Checks whether userArray has same sums in columns/rows/diagonals		//
//	User inputs: None														//
//  Function Call Arguments: int userArray[][]	Holds values to be checked	//
//							 int *arraySize		size of user array			//
//  Returns: bool of whether the sums are all the same    					//
/****************************************************************************/
bool checkArray(int **userArray, int *arraySize){
	int *holdSum;
	holdSum = new int;
	return (   checkRowsAndColumns(userArray, arraySize, holdSum)
			&& checkDiagonals(userArray, arraySize, *holdSum));
}
/****************************************************************************/
//  Checks whether userArray has same sums in columns/rows					//
//	User inputs: None														//
//  Function Call Arguments: int userArray[][]	Holds values to be checked	//
//							 int *arraySize		size of user array			//
//							 int *holdSum		holds value used to 		//
//												  check all sums			//
//  Returns: bool of whether the sums are all the same    					//
/****************************************************************************/
bool checkRowsAndColumns(int **userArray, int *arraySize, int *holdSum){
	//Checks rows & columns at the same time
	for (int i = 0; i < *arraySize; i++){
		int  sum1 = 0, sum2 = 0;
		for (int j = 0; j < *arraySize; j++){
			sum1 += userArray[i][j];
			sum2 += userArray[j][i];
		}

		if (i == 0){
			*holdSum = sum1;
		} else {
			if (*holdSum != sum1 || *holdSum != sum2)
				return false;
		}
	}
	return true;
}
/****************************************************************************/
//  Checks whether userArray has same sums in diagonals						//
//	User inputs: None														//
//  Function Call Arguments: int userArray[][]	Holds values to be checked	//
//							 int *arraySize		size of user array			//
//							 int holdSum		holds value used to 		//
//												  check all sums			//
//  Returns: bool of whether the sums are all the same    					//
/****************************************************************************/
bool checkDiagonals(int **userArray, int *arraySize, int holdSum){
	//Checks Diagonal from [0][0] to [i][i]
	int sum = 0;
	for (int i = 0, j = 0; i < *arraySize; i++, j++){
		sum += userArray[i][j];
	}
	if (holdSum != sum)
		return false;

	//Checks Diagonal from [i][0] to [0][i]
	sum = 0;
	for (int i = *arraySize - 1, j = 0; i >= 0; i--, j++){
		sum += userArray[i][j];
	}
	if (holdSum != sum)
		return false;
	return true;
}


