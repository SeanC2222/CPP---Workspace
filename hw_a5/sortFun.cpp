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
 * Inputs: none
 *
 * Outputs: 3 randomly generated numbers in order
 */                                                                          //

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void sortNumbers(int&, int&, int&);

int main() {

	srand(time(NULL));

	int low, mid, high;

	low = rand() % (100) + 1;
	mid = rand() % (100) + 1;
	high = rand() % (100) + 1;

	cout << "Num 1 = " << low << endl
	     << "Num 2 = " << mid << endl
	     << "Num 3 = " << high << endl;

	sortNumbers(low, mid, high);

	cout << endl;

	cout << "Low = " << low << endl
		 << "Mid = " << mid << endl
		 << "High = " << high << endl;

	return 0;
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
