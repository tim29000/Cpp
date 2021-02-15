#include "Linkedlist.h"


Linkedlist::~Linkedlist() // destructor, clear all the list
{
    while(head)
    {
        tail = head->next;
        delete head;
        head = tail;
    }
}


void Linkedlist::clearList() //  same to destructor, clears list
{
    while(head)
    {
        tail = head->next;
        delete head;
        head = tail;
    }
}


Node *Linkedlist::backNode()  // returns address of the last element
{
    if(head == NULL)
    {
        cout << "Your list is empty!" << endl;
        return 0;
    }
    return tail;
}


Node *Linkedlist::frontNode()  // returns address of the first element
{
    if(head == NULL)
    {
        cout << "Your list is empty!" << endl;
        return 0;
    }
    return head;
}


void Linkedlist::pop_backNode()  // deletes last element
{
    if(head == NULL)
    {
        cout << "Your list is empty!" << endl;
    }
    else
    {
        Node *deleting_Node = tail;
        tail = tail->previous;
        tail->next = NULL;
        delete deleting_Node;
    }
}


void Linkedlist::pop_frontNode()  // deletes first element
{
     if(head == NULL)
    {
        cout << "Your list is empty!" << endl;
    }
    else
    {
        Node *deleting_Node = head;
        head = head->next;
        head->previous = NULL;
        delete deleting_Node;
    }
}


void Linkedlist::push_backNode(int x)  // adds the new node in the end of the list
{
    Node *newNode = new Node;
    newNode->next = NULL;
    newNode->value = x;
    if(head == NULL)
    {
        newNode->previous = NULL;
        head = tail = newNode;
    }
    else
    {
        newNode->previous = tail;
        tail->next = newNode;
        tail = newNode;
    }

}


void Linkedlist::push_frontNode(int x)  // adds the new node in the beginning of the list
{
    Node *newNode = new Node;
    newNode->previous = NULL;
    newNode->value = x;
    if(head == NULL)
    {
           newNode->next = NULL;
           head = tail = newNode;
    }
    else
    {
        newNode->next = head;
        head->previous = newNode;
        head = newNode;
    }
}


void Linkedlist::sortList()   //  sorting list using bubble method
{
    if(head == NULL)
    {
        cout << "Your list is empty!" << endl;
    }
    else
    {
        int n = nodeCounter();
        unsigned int i, j;
        Node *tempNode = head;
        Node *nextNode = tempNode->next;
        for(i = n-1; i > 0; i--)
        {
            for(j = 0; j < i; j++)
            {
                 if(tempNode->value > nextNode->value)
                 {
                     swapNode(tempNode, nextNode);
                 } else
                 {
                     tempNode = tempNode->next;
                 }
                 nextNode = tempNode->next;
            }
            tempNode = head;
            nextNode = tempNode->next;
        }
    }
}


unsigned int Linkedlist::nodeCounter()  // function that returns number of nodes in the list
{
    if(head == NULL)
    {
        cout << "Your list is empty!" << endl;
        return 0;
    }
    int i, counter = 0;
    Node *current = head;
    for(i = 0; current != tail; i++)
    {
        counter++;
        current = current->next;
    }
    return counter+1;
}


Linkedlist& Linkedlist::operator=(Linkedlist& myList)  // overloading of operator =
{
    Node *currentNode = myList.head;
    Node *previousNode = myList.head->previous;
        while (currentNode != NULL)
        {
            Node *newNode = new Node;
            if (this->head == NULL) {
                this->head = newNode;
            }
            newNode->value = currentNode->value;
            newNode->next = NULL;
            newNode->previous = previousNode;
            if (previousNode != NULL)
            {
                previousNode->next = newNode;
            }
            currentNode = currentNode->next;
            previousNode = newNode;
        }
    this->tail = previousNode;
    return *this;
}


Linkedlist::Linkedlist(unsigned int n)  // constructor that initializes n nodes
{
    head = NULL;
    tail = NULL;
    unsigned int i;
    int x;
    for(i = 0; i < n; i++)
    {
        cout << "\tValid node values are from 0 to " << n-1  << "!!!" <<  endl;
        cout << "Please, enter the node value : ";
        cin >> x;
        push_backNode(x);
    }
}


void Linkedlist::check()const // function that prints list from the beginning
{
    if(head == NULL)
    {
        cout << "Your list is empty!" << endl;
    }
    else
    {
        Node *printNode = head;
        while (printNode != NULL)
        {
            cout << printNode->value << " ";
            printNode = printNode->next;
        }
    }
}


void Linkedlist::rcheck()const  // function that prints list from the end
{
     if(head == NULL)
    {
        cout << "Your list is empty!" << endl;

    }
    else
    {
        Node *printNode = tail;
        while(printNode != NULL)
        {
            cout << printNode->value << " ";
            printNode = printNode->previous;
        }
    }
}


void Linkedlist::insertNode(unsigned int pos, int x) // function that inserts node after stated position
{
    if(head == NULL)
    {
        Node *newNode = new Node;
        newNode->value = x;
        newNode->next = NULL;
        newNode->previous = NULL;
        head = tail = newNode;
    }
    else if(pos > nodeCounter())
    {
        push_backNode(x);
    }
    else
    {
        unsigned int i;
        unsigned int counter = 0;
        Node *temp = head;
        for(i = 0; i < nodeCounter(); i++)
        {
           if(pos == counter)
           {
                Node *newNode = new Node;
                newNode->value = x;
                newNode->next = temp->next;
                temp->next = newNode;
                newNode->previous = temp;
                break;
            }
            temp = temp->next;
            counter++;
        }
    }
}


void Linkedlist::eraseNode(unsigned int pos)  // deletes node in the selected position
{
    if(head == NULL)
    {
        cout << "Your list is empty!";
    }
    else if(pos > nodeCounter())
    {
        pop_backNode();
    }
    else
    {
        Node *temp = head;
        unsigned int i;
        unsigned counter = 0;
        for(i = 0; i < nodeCounter(); i++)
        {
            if(pos == counter)
            {
                temp->previous->next = temp->next;
                temp->next->previous = temp->previous;
                delete temp;
                break;
            }
            counter++;
            temp = temp->next;
        }
    }
}


void swapNode(Node *tempNode, Node *nextNode) // swaps elements
{
    Node *previousNode = tempNode->previous;
    Node *nextnextNode = nextNode->next;
    tempNode->next = nextNode->next;
    nextNode->previous = previousNode;
    nextNode->next = tempNode;
    tempNode->previous = nextNode;
    if(nextnextNode != NULL)
    {
        nextnextNode->previous = tempNode;
    }
    if(previousNode != NULL)
    {
        previousNode->next = nextNode;
    }
}
