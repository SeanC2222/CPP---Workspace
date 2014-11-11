/* Author: SeanC
 * Date: Nov 3, 2014
 *
 * randFun2.cpp
 * 
 * File purpose: This program generates a random number between user input
 * *min and *max values. main() calls getRandom and stores the random variable
 * on the heap in val.
 * 
 * Inputs:	int *min	Minimum value of random number range
 * 			int *max	Maximum value of random number range
 * 			int *val	Randomly generated number between limits
 * 			char again	Repeat condition for getRandom
 *
 * Outputs: int *val	Randomly generated number between limits
 */                                                                          //
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void getRandom (int*, int*, int*);

int main() {

	srand(time(NULL));

	char again;

	int *min, *max, *val;
	min = new int;
	max = new int;
	val = new int;
	//Input validation for *min
	do{
		cin.clear();
		cout << "What is the minimum value of your range? ";
		cin >> *min;
		if (cin.peek() != '\n'){
			cin.ignore(100,'\n');
			cin.setstate(ios::failbit);
		}
	}while (cin.fail());
	//Input validation for *max
	do{
		cin.clear();
		cout << "What is the maximum value of your range? ";
		cin >> *max;
		if (cin.peek() != '\n'){
			cin.ignore(100,'\n');
			cin.setstate(ios::failbit);
		}
	}while (cin.fail());
	//Generates calls getRandom as much as user wants
	do{
		getRandom(min, max, val);
		cout << "Your random value is: " << *val << endl;
		cout << "Would you like another random from " << *min << " to " << *max
			 << "? (\'y\'/\'n\')";
		cin.get();
		again = tolower(cin.get());
	}while (again == 'y');

	return 0;
}

/****************************************************************************/
//  Pulls random number between *min and *max stores as int in val			//
//	User inputs: None														//
//  Function Call Arguments: 												//
//			int *min		Minimum value of random number range			//
//			int *max		Maximum value of random number range			//
//			int *val		Randomly generated number between range limits  //
//  Returns: None									    					//
/****************************************************************************/
void getRandom (int *min, int *max, int *val){

	*val = rand () % (*max - *min + 1) + *min;
	return;
}
