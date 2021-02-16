#include "book.h"


Book::Book()
{
    setCode("");
    setAuthor("");
    setName("");
    setPrice(0);
    setCopy(0);
}



Book::Book(string Code, string Author, string Name, double Price, int Copy)
{
    setCode(Code);
    setAuthor(Author);
    setName(Name);
    setPrice(Price);
    setCopy(Copy);
}



void Book::setCode(string Code){_code = Code;}
void Book::setAuthor(string Author){_author = Author;}
void Book::setName(string Name){_name = Name;}
void Book::setPrice(double Price){_price = Price;}
void Book::setCopy(int Copy){_copy = Copy;}



string Book::getCode()const{return _code;}
string Book::getAuthor()const{return _author;}
string Book::getName()const{return _name;}
double Book::getPrice()const{return _price;}
int Book::getCopy()const{return _copy;}




void Book::FillBook()
{
    string codeFill, authorFill, nameFill;
    double priceFill;
    int copyFill;
    system("cls");
    cout << "Enter the UDK code of this book(format - XXX.XXX(X - digit): ";
    cin >> codeFill;
    this->setCode(codeFill);
    cout << "Enter the surname of Author of this book: ";
    cin >> authorFill;
    this->setAuthor(authorFill);
    cout << "Enter name of this book: ";
    cin >> nameFill;
    this->setName(nameFill);
    cout << "Enter the price of this book: ";
    cin >> priceFill;
    this->setPrice(priceFill);
    cout << "Enter the number of copies of this book: ";
    cin >> copyFill;
    this->setCopy(copyFill);
}

ostream& operator << (ostream &out, const Book b1)
{
    out << "UDK : " << b1.getCode() << endl << "Author : " << b1.getAuthor() << endl << "Name : "
    << b1.getName() << endl << "Price : " << b1.getPrice() << endl << "Copies : " << b1.getCopy() << endl << endl;
    return out;
}


void PrintDeque(deque<Book> books)
{

    int n = books.size();
    system("cls");
    for(int i = 0; i < n; ++i)
        cout << books[i];
    Sleep(5000);
}




void Book::ConvertPrice()
{
    this->setPrice(getPrice()/27.86);
}


void Book::DeleteInfo()
{

    this->setCode("");
    this->setAuthor("");
    this->setName("");
    this->setPrice(0);
    this->setCopy(0);

}


int SearchBookIdByAuthor(deque<Book> dequeToSearch)
{
    system("cls");
    cout << "Enter the name of Author whose info about whom you wanna remove: ";
    string authorName;
    cin >> authorName;
    int n = dequeToSearch.size();
    for(int i = 0; i < n; ++i)
    {
        if(authorName == dequeToSearch[i].getAuthor())
            return i;
    }
    cout << "Author whose name you had entered  haven't been found!";
    return -1;
}
