#include "book.h"



int main()
{
    cout << "Enter the number of objects in deque: ";
    int sizeOfDeque;
    cin >> sizeOfDeque;
    deque<Book> dequeOfBooks(sizeOfDeque);

    for(int i = 0; i < sizeOfDeque; ++i)
    {
        dequeOfBooks[i].FillBook();
    }

    PrintDeque(dequeOfBooks);

    for(int i = 0; i < sizeOfDeque; ++i)
        dequeOfBooks[i].ConvertPrice();


    cout << endl << "Price was changed to : " << endl << endl;

    PrintDeque(dequeOfBooks);

    dequeOfBooks[SearchBookIdByAuthor(dequeOfBooks)].DeleteInfo();

    PrintDeque(dequeOfBooks);

    return 0;

}



