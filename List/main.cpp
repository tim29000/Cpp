#include "Linkedlist.h"

int main()
{
    unsigned int n;
    cout << "Enter the number of elements in the list : ";
    cin >> n;
    Linkedlist myList(n);
    Linkedlist myAnotherlist;
    cout << "Your initialized list:  ";
    myList.check();
    cout << endl;
    myList.sortList();
    cout << "Your sorted list:  ";
    myList.check();
    cout<<endl;
    cout << "Your list with deleted last Node:  " ;
    myList.pop_backNode();
    myList.check();
    cout << endl;
    cout << "Your list from tail to head:  ";
    myList.rcheck();
    cout << endl;
    cout << "Your list with deleted first node:  " ;
    myList.pop_frontNode();
    myList.check();
    cout << endl;
    cout << "Value of list's lastNode:  ";
    cout << myList.backNode()->value << endl;
    cout << endl;
    cout << "Value of list's first node:  ";
    cout << myList.frontNode()->value << endl;
    cout << endl;
    cout << "Number of Nodes:  ";
    cout << myList.nodeCounter() << endl;
    cout << "List:  ";
    myList.check();
    cout << endl;
    myList.insertNode(2, 8);
    cout << "Was inserted node = 8 after the element on second position:  ";
    myList.check();
    cout << endl << "Was deleted node on third position:  ";
    myList.eraseNode(3);
    myList.check();
    cout << endl << "Copied with overloaded operator = list:  ";
    myAnotherlist = myList;
    myAnotherlist.check();
    cout << endl;
    myList.clearList();
    cout << endl << "Cleared list:  ";
    myList.check();
    return 0;
}
