/* Author: Sean C Mulholland
 * Date: Oct 27, 2014
 *
 * sortFun.cpp
 * 
 * File purpose: This file will sort 3 integers passed to a function from
 * low to high. For example:
 * if sortNumbers(num1, num2, num3) where num1 = 10, num2 = 100, and num3 = 1
 *    the function rearranges to produce num1 = 1, num2 = 10, and num3 = 100
 * 
 * Inputs: 3 positive integers
 *
 * Outputs: Sorted user integers.
 */                                                                          //

#include <iostream>

using namespace std;

int getInt ();
void sortNumbers(int&, int&, int&);

int main() {

	int low, mid, high;
  cout << "This program will organize three user input integers. Please enter positive integers." << endl;
	cout << "Num 1 = ";
  low = getInt();

	cout << "Num 2 = ";
  mid = getInt();

	cout << "Num 3 = ";
  high = getInt();

	sortNumbers(low, mid, high);

	cout << endl;

	cout << "Low = " << low << endl
		 << "Mid = " << mid << endl
		 << "High = " << high << endl;

	return 0;
}

int getInt() {
  int n;		//Stores 'n'
	//Loop to validate input
	do{
		cin.clear();	//Sets state clear for repeat loops
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

void sortNumbers(int &low, int &mid, int &high){
	int tempNum;
	if (low > mid){
		tempNum = mid;
		mid = low;
		low = tempNum;
	}
	if (low > high){
		tempNum = high;
		high = low;
		low = tempNum;
	}
	if (mid > high){
		tempNum = high;
		high = mid;
		mid = tempNum;
	}
	return;
}
