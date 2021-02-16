#ifndef BOOK_H_INCLUDED
#define BOOK_H_INCLUDED

#pragma once
#include <iostream>
#include <deque>
#include "windows.h"

using namespace std;

class Book
{
private:

   string _code;
   string _author;
   string _name;
   double _price;
   int _copy;

public:

    Book();
    Book(string Code, string Author, string Name, double Price, int Copy);

    void setCode(string Code);
    void setAuthor(string Author);
    void setName(string Name);
    void setPrice(double Price);
    void setCopy(int Copy);

    string getCode() const;
    string getAuthor()const;
    string getName()const;
    double getPrice()const;
    int getCopy()const;

    void FillBook();
    void DeleteInfo();
    void ConvertPrice();

    ~Book(){}

};


void PrintDeque(deque<Book>);

int SearchBookIdByAuthor(deque<Book>);

ostream& operator << (ostream &out, const Book b1);



#endif // BOOK_H_INCLUDED
