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

template<class T>
LinkedList<T>::LinkedList() : head(NULL) {}

template<class T>
LinkedList<T>::~LinkedList() {
}

template<class T>
void LinkedList<T>::insertFront(const T& val) {
    Node<T>* p = new Node<T>(val);
    p->next = head;
    head = p;
}

template<class T>
void LinkedList<T>::insertEnd(const T& val) {
    Node<T>* ptr = new Node<T>(val);
    Node<T>* p = head;
    while (p->next != NULL) {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
}

template<class T>
void LinkedList<T>::insertAtposition(int pos, const T& val) {
    Node<T>* newNode = new Node<T>(val);
    Node<T>* p = head;
    for (int i = 0; i < pos - 1; i++) {
        p = p->next;
    }
    newNode->next = p->next;
    p->next = newNode;
}

template<class T>
bool LinkedList<T>::search(const T& val) const {
    Node<T>* p = head;
    while (p != NULL) {
        if (p->data == val) return true;
        p = p->next;
    }
    return false;
}

template<class T>
void LinkedList<T>::display() const {
    Node<T>* p = head;
    while (p != NULL) {
        cout << p->data << endl;
        p = p->next;
    }
}

template<class T>
int LinkedList<T>::getLength() const {
    Node<T>* p = head;
    int count = 0;
    while (p != NULL) {
        count++;
        p = p->next;
    }
    return count;
}

#endif // LINKEDLIST_H
