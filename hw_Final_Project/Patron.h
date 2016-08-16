//
//  Patron.h
//  examples
//
//  Created by Tim Alcon on 11/25/14.
//  Copyright (c) 2014 Tim Alcon. All rights reserved.
//

#ifndef __examples__Patron__
#define __examples__Patron__

#include "Book.h"
#include <stdio.h>
#include <vector>
#include <string>

class Book;

class Patron
{
private:
    std::string idNum;
    std::string name;
    std::vector<Book*> checkedOutBooks;
    double fineAmount;
public:
    Patron();
    Patron(std::string idn, std::string n);
    std::string getIdNum() {return idNum;}
    std::string getName() {return name;}
    std::vector<Book*> getCheckedOutBooks() {return checkedOutBooks;}
    void addBook(Book* b);
    void removeBook(Book* b);
    double getFineAmount() {return fineAmount;}
    void amendFine(double amount);
};

#endif /* defined(__examples__Patron__) */
