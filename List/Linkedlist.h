#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED
#include <iostream>

using namespace std;

struct Node
{
    int value;
    Node *previous;
    Node *next;
};

class Linkedlist
{
public:
    Node *head;
    Node *tail;
    Linkedlist(): head(NULL), tail(NULL){};
    ~Linkedlist();
    void clearList();
    Node *backNode();
    Node *frontNode();
    void pop_backNode();
    void pop_frontNode();
    void push_backNode(int x);
    void push_frontNode(int x);
    Linkedlist& operator=(Linkedlist& myList);
    void sortList();
    unsigned int nodeCounter();
    void check() const;
    void rcheck() const;
    void insertNode(unsigned int pos, int x);
    void eraseNode(unsigned int pos);
    explicit Linkedlist(unsigned int n);
};

void swapNode(Node *tempNode, Node *nextNode);

#endif // LINKEDLIST_H_INCLUDED
