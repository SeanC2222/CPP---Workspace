/* Author: Sean Mulholland
 * Date: 10/3/14
 * 
 * This program accepts a user input integer, stores it in echoNumber, and  
 * outputs the value back to the user.
 *
 * Input: signed int echoNumber
 * Output: echoNumber
 *
 */

#include <iostream>

using namespace std;

int main() {

	signed int echoNumber; //signed int to store both positive and negative

	cout << "Please enter an integer: ";
	cin >> echoNumber; //stores user input as signed int echoNumber


	cout << "Your number is: " << echoNumber << endl; //outputs echoNumber back to user


	return 0;
}





