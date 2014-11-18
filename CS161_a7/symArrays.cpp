#include <iostream>
#include <cstdlib>
#include <cstring>

#define SIZE 3

using namespace std;

bool checkArguments(int, char*[]);
void buildJagArray(char*[], int*[], int, int);
void checkArray(int*[],bool*, int, int);
void displayResults(bool*);

int main(int argc, char* argv[]){
   

	bool *isSymmetric; //delete and create function to call instead

	isSymmetric = new bool [SIZE];
    //If arguments are consistent
	if (checkArguments(argc, argv)){

		int **jagArray;
		jagArray = new int* [SIZE];
		for (int i = 1; i <= SIZE; i++){
			int arraySize = atoi(*(argv + i));
			buildJagArray(argv, jagArray, arraySize, i);
			checkArray(jagArray, isSymmetric, arraySize, i);
			delete[] *(jagArray + i-1);

		}
		delete[] jagArray;

		displayResults(isSymmetric);
		delete[] isSymmetric;
	}


	return 0;
}
/****************************************************************************/
//  Checks arguments in main call. If valid, returns true to run program	//
//	Else returns false to cancel out of program								//
//	User inputs: None														//
//  Function Call Arguments: int argc		number of arguments in main call//
//							 char* argv[]	array of pointers to main 		//
//											   arguments in program call	//
//  Returns: bool true/false	if arguments are valid    					//
/****************************************************************************/
bool checkArguments(int argc, char* argv[]){

	if (argc != SIZE + 1){
		cout << "Needs " << SIZE << " integer arguments." << endl;
		return 0;
	}
	//For all the arguments 1 - SIZE (pre-processor definition)
	for (int i = 1; i <= SIZE; i++){

		//Checks to see if arguments are digits
		unsigned int j = 0;
		while (j < strlen(argv[i])){
			//If is not a digit, stop counting
			if (!isdigit(argv[i][j])){
				break;
			} else {
				j++;
			}
		}
		//If program doesn't count up all the arguments arguments are false
		if (j != strlen(argv[i])){
			cout << "Needs " << SIZE << " integer arguments." << endl;
			return false;
		}
	}
	return true;
}

/****************************************************************************/
//  Builds the array from program call arguments. User inputs the values in //
//	the form of a single row of arraySize integers.							//
//	User inputs: int* jagArray[]	Created & holds user input values		//
//  Function Call Arguments: char* argv[]	array of pointers to main 		//
//											   arguments in program call	//
//							 int* jagArray[]User generated jagged array		//
//							 int arraySize	Size of single row of array		//
//							 int i			which row of jagArray to be made//
//  Returns: None									    					//
/****************************************************************************/
void buildJagArray(char* argv[], int* jagArray[], int arraySize, int i){
	//Create array of user size;
	jagArray[i - 1] = new int[arraySize]; //i-1 for shifting to 0 base

	cout << endl;
	cout << "Enter " << arraySize << " integers for array " << i << ": ";

	//Buffer to hold user input, and pointer (scanner) to parse input
	char *buffer, *scanner, *end;
	buffer = new char[100];
	scanner = buffer;
	for (int j = 0; j < 100; j++){
		buffer[j] = '\0';
	}
	//Gets user input
	cin.getline(buffer, 100);

	//Counts number of integers
	int inputCounter = 0;

	//Scans length of buffer
	while (scanner <= (buffer + (strlen(buffer)-1))){
		//Ignores whitespace
		if (isspace(*scanner)){
			scanner++;
		//If there is non whitespace character
		} else {
			//If the character is a digit at scanner
			if (isdigit(*scanner)){
				end = scanner;
				//Increment end until no longer a digit
				while (isdigit(*end)){
					end++;
					//If end points to a new space or end of buffer store
					//   integer pointed to by scanner, move scanner to end
					//   and increment inputCounter
					if (isspace(*end) || end == (buffer + strlen(buffer))){
						jagArray[i-1][inputCounter] = atoi(scanner);
						scanner = end;
						inputCounter++;
					} else if (!isdigit(*end)){
						scanner = end;
						break;
					} else {
						continue;
					}
				}
				scanner = end;
			//If character is not a digit, false input
			} else {
				break;
			}
		}

	}

	//If number of integers isn't = to specified array size, false input
	if (inputCounter != arraySize){
		cout << "Invalid input." << endl;
		buildJagArray(argv, jagArray, arraySize, i);
	}

	return;
}

/****************************************************************************/
//  Checks if each input row is a symmetric array.							//
//	User inputs: None														//
//  Function Call Arguments: int* jagArray[]User generated jagged array		//
//							 bool* isSymmetric	Holds if each array is		//
//												  is symmetric				//
//							 int arraySize	Size of single row of array		//
//							 int i			which row of jagArray to be made//
//  Returns: None									    					//
/****************************************************************************/
void checkArray(int* jagArray[],bool* isSymmetric, int arraySize, int i){

	for (int index = 0, eindex = arraySize - 1; index < arraySize; index++, eindex--){
		isSymmetric[i-1] = (jagArray[i-1][index] == jagArray[i-1][eindex]);
		if (!isSymmetric[i-1] || index == eindex){
			break;
		}
	}
	return;
}
/****************************************************************************/
//  Displays results based on value stored in isSymmetric					//
//	User inputs: None														//
//  Function Call Arguments: bool* isSymmetric	Holds if each array is		//
//												  is symmetric				//
//  Returns: None									    					//
/****************************************************************************/
void displayResults (bool* isSymmetric){
	cout << endl;
	for (int i = 1; i <= SIZE; i++){
		if (isSymmetric[i-1]){
			cout << "Array " << i << " is symmetrical." << endl;
		} else {
			cout << "Array " << i << " is not symmetrical." << endl;
		}
	}
	return;
}
