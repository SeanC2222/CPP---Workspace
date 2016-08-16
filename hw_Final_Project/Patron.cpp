/* Author: SeanC
 * Date: Dec 1, 2014
 *
 * Patron.cpp
 * 
 * File purpose: Constructs a patron object that contains a unique patron
 * number, a name, a fine amount associated with that patron, and a vector of
 * pointers to books checked out by the patron.
 */                                                                          //

#include "Patron.h"

Patron::Patron(){
	this->idNum = "";
	this->name = "";
	this->fineAmount = 0.0;
	this->checkedOutBooks.reserve(100);
}

Patron::Patron(std::string idn, std::string n){
	this->idNum = idn;
	this->name = n;
	this->fineAmount = 0.0;
	this->checkedOutBooks.reserve(100);
}
/****************************************************************************/
//  Inserts book pointer into patron's checked out book vector				//
//	User inputs: None														//
//  Function Call Arguments: Book* b	Points to a book in Library Holdings//
//  Returns: void															//
/****************************************************************************/
void Patron::addBook(Book* b){
	checkedOutBooks.push_back(b);
	return;
}
/****************************************************************************/
//  Removes book pointer froms patron's checked out book vector				//
//	User inputs: None														//
//  Function Call Arguments: Book* b	Points to a book in Library Holdings//
//  Returns: void															//
/****************************************************************************/
void Patron::removeBook(Book* b){
	for (unsigned i = 0; i < checkedOutBooks.size(); i++){
		if (b->getIdCode() == checkedOutBooks[i]->getIdCode()){
			checkedOutBooks.erase(checkedOutBooks.begin() + i);
		}
	}
	return;
}
/****************************************************************************/
//  Amends the patrons fine amount by amount passed.						//
//	User inputs: None														//
//  Function Call Arguments: double amount	Amount to change the fine by	//
//  Returns: void															//
/****************************************************************************/
void Patron::amendFine(double amount){
	this->fineAmount += amount;
	return;
}


