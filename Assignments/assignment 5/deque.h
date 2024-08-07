// deque.h

#ifndef DEQUE_H
#define DEQUE_H

#include<iostream>
using namespace std;

template<class T>
class Node
{
public:
    T data;
    Node* next;
    Node* prev;
};

template<class T>
class deque
{
    Node<T>* head;
    Node<T>* front;

public:
    deque(Node<T>* Front = NULL, Node<T>* Head = NULL);
    void push_back(const T val);
    void display() const;
    void push_front(const T val);
    void pop_front();
    void pop_back();
    bool empty();
    int size() const;
    ~deque();
};

template<class T>
class Queue : public deque<T>
{
    Node<T>* head;
    Node<T>* front;

public:
    Queue(Node<T>* Front = NULL, Node<T>* Head = NULL);
    void push(const T val);
    void display() const;
    void pop();
    bool empty();
    int size() const;
    ~Queue();
};

template<class T>
class Stack : public deque<T>
{
    Node<T>* head;

public:
    Stack(Node<T>* Head = NULL);
    void push(const T val);
    void display() const;
    bool empty();
    int size() const;
};

#endif // DEQUE_H
