/* Author: Sean C Mulholland
 * Date: Nov 4, 2014
 *
 * evenOdd.cpp
 *
 * File purpose: This program will accept user input integers and store them
 * in an array (up to 100 values). It will then sum all the even integers
 * and all the odd integers and find the difference.
 *
 * Inputs: int arraySize      Number of ints for the user to enter
 *         int numToSum[i]    Contents of the array at index 'i'
 *
 * Outputs: int difference    The difference of evenTotal - oddTotal
 */                                                                          //
#include <iostream>

using namespace std;

int sumEvenMinusSumOdd(int[],int);

int main(){

   int *numToSum;	//Points to array for use
   int arraySize;	//Array size

   cout << "This program will accept user input integers, and return the "
		<< "difference in \nthe even total minus the odd total. For example "
		<< "if 3 numbers {2,2,1} are \nentered, the program will output: 3"
		<< endl;

   //Gets number of ints to input between 0 and 100
   do{
	  cout << "How many values would you like to add? ";
	  cin.clear();
	  cin >> arraySize;
	  if (cin.peek() != '\n'){
	     cin.clear();
	     cin.ignore(100,'\n');
	     cin.setstate(ios::failbit);
      }
   }while (cin.fail() || arraySize < 0);

   //Dynamic Array to hold user int's
   numToSum = new int[arraySize];

   //Gets valid user ints
   for (int i = 0; i < arraySize; i++) {
	  do{
	      cout << "What is the next number? (" << i + 1 << ") ";
	      cin.clear();
          cin >> numToSum[i];
          if (cin.peek() != '\n'){
        	  cin.clear();
        	  cin.ignore(100,'\n');
        	  cin.setstate(ios::failbit);
          }
      }while (cin.fail());

   }

   int difference = sumEvenMinusSumOdd(numToSum, arraySize);
   cout << "Difference: " << difference << endl;

   return 0;
}

/****************************************************************************/
//  Sums the even contents and odd contents of the array passed to it   	//
//  then returns the difference of the two values.							//
//	User inputs: None														//
//  Function Call Arguments: int array[]    The array holding the user ints //
//							 int totalNums	The total numbers in the array  //
//  Returns: evenTotal - oddTotal									    	//
/****************************************************************************/

int sumEvenMinusSumOdd(int array[], int totalNums) {

   //Integers to hold sum of evenTotal and oddTotal
   int evenTotal = 0, oddTotal = 0;

   //Loop to sum all even numbers and odd numbers
   for(int i = 0; i < totalNums; i++){
	   if (array[i] % 2 == 0)
		   evenTotal += array[i];
	   else
		   oddTotal += array[i];
   }
   //Returns the difference between the even total and odd total
   return (evenTotal - oddTotal);
}
