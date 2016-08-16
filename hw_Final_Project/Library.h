//
//  Library.h
//  examples
//
//  Created by Tim Alcon on 11/25/14.
//  Copyright (c) 2014 Tim Alcon. All rights reserved.
//

#ifndef __examples__Library__
#define __examples__Library__

#include <vector>
#include <iostream>

class Patron;
class Book;

class Library
{
private:
    std::vector<Book> holdings;
    std::vector<Patron> members;
    int currentDate;
    bool checkMembers(std::string patronID, Patron*& pPatron);
    bool checkHoldings(std::string bookID, Book*& pBook);
    void updateFines();

public:
    static const double DAILY_FINE = 0.1;
    Library();
    void addBook();
    void addMember();
    void checkOutBook(std::string patronID, std::string bookID);
    void returnBook(std::string bookID);
    void requestBook(std::string patronID, std::string bookID);
    void incrementCurrentDate();
    void payFine(std::string patronID, double payment);
    void viewPatronInfo(std::string patronID);
    void viewBookInfo(std::string bookID);
    int getCurrentDate() {return currentDate;}
};

#endif /* defined(__examples__Library__) */
