/* Author: SeanC
 * Date: Dec 1, 2014
 *
 * Library.cpp
 * 
 * File purpose: The Library class is supposed to represent a physical library.
 * When a Library object is constructed, it can hold 500 Books and 100 Patrons
 * And the date is set to a flat starting date of 0. The Library object can
 * have Book objects added, and Patron objects added as members that both
 * contain relevant information about the books and objects. The Library
 * class requires Patron.h and Book.h in order to compile.
 * 
 */                                                                          //
#include "Library.h"
#include "Patron.h"
#include "Book.h"
#include <iomanip>
#include <cstdlib>

Library::Library(){
	this->holdings.reserve(500);
	this->members.reserve(100);
	this->currentDate = 0;
}
/****************************************************************************/
//  Constructs Book object and adds it to the Library Holdings				//
//	User inputs: std::string idc	unique Book ID code						//
//				 std::string t		Book title								//
//				 std::string a		Author of Book							//
//  Function Call Arguments: None											//
//  Returns: void															//
/****************************************************************************/
void Library::addBook(){
	std::string idc, t, a;
	char yn;
	do{
		do{
			std::cout << "What is the unique ID code? ";
			std::getline(std::cin, idc);
			for(unsigned i = 0; i < this->holdings.size(); i++){
				if(idc == this->holdings[i].getIdCode()){
					std::cout << "Already in library holdings." << std::endl;
					idc = "";
				}
			}
		}while (idc == "");
		std::cout << "What is the title of the book? ";
		std::getline(std::cin, t);
		std::cout << "Who is the author of the book? ";
		std::getline(std::cin, a);
		std::cout << "ID Code: " << idc << std::endl
			 << "Title: " << t << std::endl
			 << "Author: " << a << std::endl;
		std::cout << "Is this information correct? (\'y\'/\'n\') ";
		yn = std::cin.get();
		if (std::cin.peek() != '\n'){
			std::cin.ignore(100,'\n');
		}
	} while (yn != 'y');

	Book newBook(idc, t, a);
	this->holdings.push_back(newBook);
	return;
}
/****************************************************************************/
//  Constructs Patron object and adds it to the Library members				//
//	User inputs: std::string idn	unique Patron ID number					//
//				 std::string n		Member Name								//
//  Function Call Arguments: None											//
//  Returns: void															//
/****************************************************************************/
void Library::addMember(){
	std::string idn, n;
	char yn;
	do{
		do{
			std::cout << "What is their unique ID number? ";
			std::getline(std::cin, idn);
			for(unsigned i = 0; i < this->members.size(); i++){
				if(idn == this->members[i].getIdNum()){
					std::cout << "Number already in use." << std::endl;
					idn = "";
					break;
				}
			}
		} while (idn == "");
		std::cout << "What is the patron's name? ";
		std::getline(std::cin, n);
		std::cout << "ID Number: " << idn << std::endl
			 << "Name: " << n << std::endl;
		std::cout << "Is this information correct? (\'y\'/\'n\') ";
		yn = std::cin.get();
		if (std::cin.peek() != '\n'){
			std::cin.ignore(100,'\n');
		}
	} while (yn != 'y');

	Patron newPatron(idn, n);
	this->members.push_back(newPatron);
	return;
}
/****************************************************************************/
//  "Checks" a book out by assigning values of the Book object to reflect   //
//	the checked out state.													//
//	User inputs: None														//
//  Function Call Arguments: std::string patronID	Unique Patron ID number	//
//							 std::string bookID		Unique Book ID code		//
//  Returns: void															//
/****************************************************************************/
void Library::checkOutBook(std::string patronID, std::string bookID){

	bool checkStatus;
	Patron* pPatron;		//Points to patron in members
	Book* pBook;			//Points to book in holdings
	
	if (this->members.size() == 0 || this->holdings.size() == 0){
		if (this->members.size() == 0){
			std::cout << "No library members." << std::endl;
		} else {
			std::cout << "No books in the library's holdings." << std::endl;
		}
		return;
	}

	checkStatus = this->checkMembers(patronID, pPatron);
	if (!checkStatus){
		std::cout << "Member ID not found!" << std::endl;
		return;
	}

	checkStatus = this->checkHoldings(bookID, pBook);
	if (!checkStatus){
		std::cout << "Book not found in holdings!" << std::endl;
		return;
	}
	if (pBook->getCheckedOutBy()){
		std::cout << "Book is already checked out." << std::endl;
	} else if (pBook->getRequestedBy()
		&& pBook->getRequestedBy()->getIdNum() != pPatron->getIdNum()){
		std::cout << "This book has been requested by another patron."
				  << std::endl;
	} else {
		pBook->setCheckedOutBy(pPatron);
		pBook->setDateCheckedOut(this->currentDate);
		pBook->setLocation(CHECKED_OUT);
		pBook->setRequestedBy(NULL);
		pPatron->addBook(pBook);
		std::cout << "\"" << pBook->getTitle() <<"\" checked out to "
				  << pPatron->getName() << "." << std::endl;
	}

	return;
}

/****************************************************************************/
//  Private member function that checks the members vector for a matching   //
//	patron ID code, and returns true if the member is found. It also adjusts//
//	a pointer to point to that member in the members vector.				//
//	User inputs: None														//
//  Function Call Arguments: std::string patronID	Unique Patron ID number	//
//							 Patron*& pPatron		Points to member with	//
//														patronID number		//
//  Returns: true 	if member is found										//
//			 false 	if member is not found									//
/****************************************************************************/
bool Library::checkMembers(std::string patronID, Patron*& pPatron){
	for (unsigned i = 0; i < this->members.size(); i++){
		if (patronID == this->members[i].getIdNum()){
			pPatron = &this->members[i];
			break;
		} else if (i == this->members.size() - 1){
			patronID = "";
			return false;
		}
	}
	return true;
}
/****************************************************************************/
//  Private member function that checks the holdings vector for a matching  //
//	Book ID code, and returns true if the Book is found. It also adjusts	//
//	a pointer to point to that book in the holdings vector.					//
//	User inputs: None														//
//  Function Call Arguments: std::string bookID	Unique Book ID code			//
//							 Book*& pBook		Points to Book with			//
//														bookID code			//
//  Returns: true 	if Book is found										//
//			 false 	if Book is not found									//
/****************************************************************************/
bool Library::checkHoldings(std::string bookID, Book*& pBook){
	for (unsigned i = 0; i < this->holdings.size(); i++){
		if (bookID == this->holdings[i].getIdCode()){
			pBook = &this->holdings[i];
			break;
		} else if (i == this->holdings.size() - 1){
			bookID = "";
			return false;
		}
	}
	return true;
}
/****************************************************************************/
//  "Returns" a book out by assigning values of the Book object to reflect  //
//	the returned state. If the book is requested it is placed on hold		//
//	User inputs: None														//
//  Function Call Arguments: std::string bookID		Unique Book ID code		//
//  Returns: void															//
/****************************************************************************/
void Library::returnBook(std::string bookID){
	bool checkStatus;
	Book* pBook;

	checkStatus = this->checkHoldings(bookID, pBook);
	if (checkStatus && pBook->getCheckedOutBy()){
		pBook->getCheckedOutBy()->removeBook(pBook);
		pBook->setCheckedOutBy(NULL);
		pBook->setDateCheckedOut(0);		//Set checkedOutDate to 0
		if(pBook->getRequestedBy()){		//Sets book back on shelf
			pBook->setLocation(ON_HOLD);
		} else {
			pBook->setLocation(ON_SHELF);
		}
	} else if (checkStatus){
		std::cout << "This book has not been checked out yet." << std::endl;
	} else {
		std::cout << "Book not found in holdings!" << std::endl;
	}
	return;
}
/****************************************************************************/
//  "Requests" a book out by assigning values of the Book object to reflect //
//	the requested state. 													//
//	User inputs: None														//
//  Function Call Arguments: std::string patronID	Unique patron ID number	//
//  Returns: void															//
/****************************************************************************/
void Library::requestBook(std::string patronID, std::string bookID){
	bool checkStatus;
	Book* pBook;
	Patron* pPatron;

	checkStatus = this->checkHoldings(bookID, pBook);
	if (checkStatus){
		checkStatus = this->checkMembers(patronID, pPatron);
	} else {
		std::cout << "Book not found in holdings!" << std::endl;
		return;
	}

	if (checkStatus){
		pBook->setRequestedBy(pPatron);
		if (pBook->getLocation() == ON_SHELF)
			pBook->setLocation(ON_HOLD);
	} else {
		std::cout << "Member ID not found!" << std::endl;
		return;
	}
	std::cout << pBook->getTitle() << " now on hold for "
			  << pPatron->getName() << std::endl;
	return;
}
/****************************************************************************/
//  Increases the date of the current library object. Updates fines for		//
//	members as well.
//	User inputs: None														//
//  Function Call Arguments: None											//
//  Returns: void															//
/****************************************************************************/
void Library::incrementCurrentDate(){
	this->currentDate++;
	this->updateFines();
	return;
}
/****************************************************************************/
//  Pays fines accrued by patron. If the patron over pays, outputs change.	//
//	User inputs: None														//
//  Function Call Arguments: std::string patronID	Unique patron ID number	//
//							 double payment			Amount patron pays with	//
//  Returns: void															//
/****************************************************************************/
void Library::payFine(std::string patronID, double payment){
	bool checkStatus;
	Patron* pPatron;
	checkStatus = this->checkMembers(patronID, pPatron);

	if (checkStatus){
		if (payment <= pPatron->getFineAmount() && payment > 0){
			pPatron->amendFine(-payment);
		} else if (payment > pPatron->getFineAmount()){
			payment -= pPatron->getFineAmount();
			pPatron->amendFine(-pPatron->getFineAmount());
			std::cout << std::setprecision(2) << std::fixed;
			std::cout << "Change due: $" << payment << std::endl;
		} else {
			std::cout << "Can't pay a negative amount!" << std::endl;
		}
	} else {
		std::cout << "Member ID not found!" << std::endl;
	}
	return;
}
/****************************************************************************/
//  Displays information about member including: ID number, name, books		//
//	currently checked out, and current fines.								//
//	User inputs: None														//
//  Function Call Arguments: std::string patronID	Unique patron ID number	//
//  Returns: void															//
/****************************************************************************/
void Library::viewPatronInfo(std::string patronID){

	bool checkStatus;			//True if patron is a member
	Patron* pPatron;			//Points to patron with patronID

	//True if patron is a member, false if patron is not a member
	checkStatus = this->checkMembers(patronID, pPatron);
	//If patron is a member, list patron information: ID num, Name, Current
	//books, and fines
	if (checkStatus){
		std::cout << "Patron information for ID number " << pPatron->getIdNum()
				  << std::endl;
		std::cout << "Name: " << pPatron->getName() << std::endl;
		std::cout << "Current Checked Out Books: " << std::endl;
		for(unsigned i = 0; i < pPatron->getCheckedOutBooks().size(); i++){
			std::cout << pPatron->getCheckedOutBooks().at(i)->getIdCode()
					  << " \""
					  << pPatron->getCheckedOutBooks().at(i)->getTitle()
					  << "\" by "
					  << pPatron->getCheckedOutBooks().at(i)->getAuthor()
					  << std::endl;
		}
		std::cout << std::setprecision(2) << std::fixed;
		std::cout << "Current fine(s): $" << pPatron->getFineAmount()
				  << std::endl;
	} else {
		std::cout << "Member ID not found!" << std::endl;
	}
}
/****************************************************************************/
//  Displays information about Book including: ID number, title, author		//
//	location, and when its due back.										//
//	User inputs: None														//
//  Function Call Arguments: std::string bookID		Unique book ID code		//
//  Returns: void															//
/****************************************************************************/
void Library::viewBookInfo(std::string bookID) {
	bool checkStatus;	//true if book is in library holdings
	Book* pBook;		//Points to book equal to bookID
	
	//True if book is in holdings, false if book is not in holdings
	checkStatus = this->checkHoldings(bookID, pBook);
	//If in holdings, list book information: ID num, title, author, location, 
		//if requested list who requested it
		//if checked out list who checked it out and it's due date
	if (checkStatus){
		std::cout << "Book information for " << bookID << std::endl;
		std::cout << "Title: \"" << pBook->getTitle() << "\"\n"
				  << "Author: " << pBook->getAuthor() << std::endl;
		std::cout << "Book location: ";
			switch(pBook->getLocation()){
				case 0:
					std::cout << "On shelf." << std::endl;
					break;
				case 1:
					std::cout << "On hold." << std::endl;
					break;
				case 2:
					std::cout << "Checked out by " 
					  		  << pBook->getCheckedOutBy()->getName() << std::endl;
					std::cout << "Due back in " 
							  << (pBook->getDateCheckedOut() + pBook->CHECK_OUT_LENGTH) - this->currentDate
							  << " days." << std::endl;
					break;
			}
		//If book has a pointer to who it's requested by 
			//getRequested by returns Patron*
		if (pBook->getRequestedBy()){
			std::cout << "Currently on hold for " << pBook->getRequestedBy()->getName() << std::endl;
		}
		
	//If book is not in holdings
	} else {
		std::cout << "Book not found in holdings!" << std::endl;
	}
	return;
}
/****************************************************************************/
//  Updates the fines for each member. The loops count the overdue books	//
//	and then adds the total overdue books times the daily fine amount.		//
//	User inputs: None														//
//  Function Call Arguments: None											//
//  Returns: void															//
/****************************************************************************/
void Library::updateFines(){
	int overdueBookCount;
	for (unsigned i = 0; i < this->members.size(); i++){
		overdueBookCount = 0;
		if (this->members[i].getCheckedOutBooks().size() > 0){
			for (unsigned j = 0; j < members[i].getCheckedOutBooks().size(); j++){
				if (members[i].getCheckedOutBooks().at(j)->getDateCheckedOut() < this->currentDate - Book::CHECK_OUT_LENGTH){
					overdueBookCount++;
				}
			}
			this->members[i].amendFine(overdueBookCount * Library::DAILY_FINE);
		}
	}
	return;
}

