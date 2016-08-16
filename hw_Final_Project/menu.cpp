/* Author: SeanC
 * Date: Dec 1, 2014
 *
 * menu.cpp
 * 
 * File purpose: 
 * 
 * Inputs:
 *
 * Outputs: 
 */                                                                          //
#include <iostream>
#include <string>
#include "Library.h"
#include "Book.h"
#include "Patron.h"

using namespace std;

void displayMenu();
void clearBuffer();
int getChoice();

void checkOutBook(Library&);

int main(){

	Library myLib;
	int iChoice;
	char cChoice;
	string temp1, temp2;
	double tempDouble;

	do{
		displayMenu();
		iChoice = getChoice();
		switch (iChoice){
			case 0:				//Quit
				break;
			case 1:				//Add a book
				myLib.addBook();
				break;
			case 2:				//Add a member
				myLib.addMember();
				break;
			case 3:				//Check out a Book
				checkOutBook(myLib);
				cin.get();
				break;
			case 4:				//Return a Book
				std::cout << "What is the ID code of the book? ";
				std::getline(std::cin, temp1);
				myLib.returnBook(temp1);
				cin.get();
				break;
			case 5:				//Request a Book
				cout << "What is the member's ID number? ";
				getline(cin, temp1);
				cout << "What is the ID code of the book? ";
				getline(cin, temp2);
				myLib.requestBook(temp1,temp2);
				cin.get();
				break;
			case 6:				//Pay a Fine
				cout << "What is the member's ID number? ";
				getline(cin, temp1);
				cout << "How much would they like to pay? ";
				cin >> tempDouble;
				cin.get();
				myLib.payFine(temp1,tempDouble);
				cin.get();
				break;
			case 7:				//Increment Date
				cout << "Current Date: " << myLib.getCurrentDate() << endl;
				cout << "Would you like to increment? (\'y\'/\'n\') ";
				cin >> cChoice;
				clearBuffer();
				if (cChoice == 'y')
					myLib.incrementCurrentDate();
				else
					cout << "Date not incremented." << endl;
				cin.get();
				break;
			case 8:				//View Member Information
				cout << "What is the member's ID number? ";
				getline(cin,temp1);
				myLib.viewPatronInfo(temp1);
				cin.get();
				break;
			case 9:				//View Book Information
				cout << "What is the book's ID code? ";
				getline(cin,temp1);
				myLib.viewBookInfo(temp1);
				cin.get();
				break;
		}

	}while (iChoice > 0 && iChoice <= 9);
	return 0;
}

void displayMenu() {
	for (int i = 0; i < 100; i++){
		cout << endl;
	}
	cout << "Welcome to the LocalLibray System!" << endl;
	cout << "\n"
		 << "1) Add a Book\n"
		 << "2) Add a Member\n"
		 << "3) Check Out a Book\n"
		 << "4) Return a Book\n"
		 << "5) Request a Book for a Member\n"
		 << "6) Pay a Fine\n"
		 << "7) View/Increment the Date\n"
		 << "8) View a Member's Information\n"
		 << "9) View a Book's Information\n"
		 << "0) Quit\n"
		 << endl;

	return;
}

void clearBuffer() {
	cin.clear();
	if (cin.peek() > 0){
		cin.ignore(100,'\n');
	}
	return;
}

int getChoice() {
	int c; 		//userChoice;
	//Gets user's choice 0-9
	do{
		cout << "What would you like to do?";
		cin >> c;
		if (cin.fail() || cin.peek() != '\n'){
			clearBuffer();
			c = -1;
		}
		if (c < 0 || c > 9){
			cout << "Make a choice from 0 to 9." << endl;
		}
		cin.get();
	}while (c < 0 || c > 9);

	return c;
}

void checkOutBook(Library& myLib){
	string idn, idc;
	cout << "What is the member's ID number? ";
	getline(cin,idn);
	cout << "What is the book's ID code? ";
	getline(cin,idc);
	myLib.checkOutBook(idn,idc);
	return;
}
