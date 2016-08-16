/* Author: SeanC
 * Date: Dec 1, 2014
 *
 * Book.cpp
 * 
 * File purpose: Constructs a book object. Each book object holds a unique
 * ID code number, a title, an author, the location of the book, a pointer to
 * the patron who has checked the book out, a pointer to the patron who
 * requested the the book, and an int to represent the date the book was
 * checked out.
 */                                                                          //
#include "Book.h"

Book::Book() {
	this->idCode = "";
	this->title = "";
	this->author = "";
	this->location = ON_SHELF;
	this->checkedOutBy = NULL;
	this->requestedBy = NULL;
	this->dateCheckedOut = 0;
}
Book::Book(std::string idc, std::string t, std::string a){
	this->idCode = idc;
	this->title = t;
	this->author = a;
	this->location = ON_SHELF;
	this->checkedOutBy = NULL;
	this->requestedBy = NULL;
	this->dateCheckedOut = 0;
}

void Book::setLocation(Locale lo) {
	location = lo;
	return;
}


void Book::setCheckedOutBy(Patron* p){
	this->checkedOutBy = p;
	return;
}

void Book::setRequestedBy(Patron* p){
	this->requestedBy = p;
	return;
}

void Book::setDateCheckedOut(int d){
	this->dateCheckedOut = d;
	return;
}


