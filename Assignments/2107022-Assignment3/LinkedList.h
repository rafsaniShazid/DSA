// LinkedList.h

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include<iostream>
using namespace std;

template<typename T>
struct Node
{
    T data;
    Node* next;
    Node(const T& val): data(val), next(NULL) {}
};

template<class T>
class LinkedList{
    Node<T>* head;
public:
    LinkedList();
    ~LinkedList();
    void insertFront(const T& val);
    void insertEnd(const T& val);
    void insertAtposition(int pos, const T& val);
    bool search(const T& val) const;
    void display() const;
    int getLength() const;
};

#include "LinkedList.cpp"
#endif // LINKEDLIST_H
