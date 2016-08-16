//
//  Book.h
//  examples
//
//  Created by Tim Alcon on 11/25/14.
//  Copyright (c) 2014 Tim Alcon. All rights reserved.
//

#ifndef examples_Book_h
#define examples_Book_h

#include <string>

class Patron;

enum Locale {ON_SHELF, ON_HOLD, CHECKED_OUT};

class Book
{
private:
    std::string idCode;
    std::string title;
    std::string author;
    Locale location;
    Patron* checkedOutBy;
    Patron* requestedBy;
    int dateCheckedOut;

public:
    static const int CHECK_OUT_LENGTH = 1; ///////Should be 21
    Book();
    Book(std::string idc, std::string t, std::string a);
    int getCheckOutLength() {return (dateCheckedOut + 21) ;}
    std::string getIdCode() {return idCode;}
    std::string getTitle() {return title;}
    std::string getAuthor() {return author;}
    Locale getLocation() {return location;}
    void setLocation(Locale lo);
    Patron* getCheckedOutBy() {return checkedOutBy;}
    void setCheckedOutBy(Patron* p);
    Patron* getRequestedBy() {return requestedBy;}
    void setRequestedBy(Patron* p);
    int getDateCheckedOut() {return dateCheckedOut;}
    void setDateCheckedOut(int d);
};

#endif
