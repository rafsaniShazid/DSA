// DoublyLinkedList.h

#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

template <typename T>
struct Node {
    T data;
    Node* prev;
    Node* next;
};

template <typename T>
class DoublyLinkedList {
private:
    Node<T>* head;
    Node<T>* tail;

public:
    DoublyLinkedList();
    ~DoublyLinkedList();

    void insertBegin(const T& value);
    void insertEnd(const T& value);
    void insertAtPosition(int position, const T& value);

    void deleteBegin();
    void deleteEnd();
    void deleteAtPosition(int position);
    void deleteByValue(const T& value);

    void quickSort();
    void mergeSort();

    void display() const;
};

#endif 

// DoublyLinkedList.cpp

#include "DoublyLinkedList.h"
#include <iostream>

// Constructor
template <typename T>
DoublyLinkedList<T>::DoublyLinkedList() : head(nullptr), tail(nullptr) {}

// Destructor
template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
    while (head) {
        Node<T>* temp = head;
        head = head->next;
        delete temp;
    }
}

// Insert at the beginning
template <typename T>
void DoublyLinkedList<T>::insertBegin(const T& value) {
    Node<T>* newNode = new Node<T>{value, nullptr, head};
    if (head) {
        head->prev = newNode;
    } else {
        tail = newNode;
    }
    head = newNode;
}

// Insert at the end
template <typename T>
void DoublyLinkedList<T>::insertEnd(const T& value) {
    Node<T>* newNode = new Node<T>{value, tail, nullptr};
    if (tail) {
        tail->next = newNode;
    } else {
        head = newNode;
    }
    tail = newNode;
}

// Display the list
template <typename T>
void DoublyLinkedList<T>::display() const {
    Node<T>* current = head;
    while (current) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}
template <typename T>
typename DoublyLinkedList<T>::Node<T>* merge(typename DoublyLinkedList<T>::Node<T>* left, typename DoublyLinkedList<T>::Node<T>* right) {
    if (!left) {
        return right;
    }
    if (!right) {
        return left;
    }

    typename DoublyLinkedList<T>::Node<T>* result = nullptr;

    if (left->data <= right->data) {
        result = left;
        result->next = merge(left->next, right);
        result->next->prev = result;
    } else {
        result = right;
        result->next = merge(left, right->next);
        result->next->prev = result;
    }

    return result;
}

// Merge Sort
template <typename T>
void DoublyLinkedList<T>::mergeSort() {
    if (!head || !head->next) {
        return; // Already sorted or empty list
    }

    Node<T>* middle = head;
    Node<T>* fast = head->next;

    while (fast && fast->next) {
        middle = middle->next;
        fast = fast->next->next;
    }

    Node<T>* left = head;
    Node<T>* right = middle->next;
    middle->next = nullptr;

    left = mergeSortRecursive(left);
    right = mergeSortRecursive(right);

    head = merge(left, right);
    if (head) {
        head->prev = nullptr;
        Node<T>* temp = head;
        while (temp->next) {
            temp->next->prev = temp;
            temp = temp->next;
        }
        tail = temp;
    }
}

// Utility function for recursive merge sort
template <typename T>
typename DoublyLinkedList<T>::Node<T>* DoublyLinkedList<T>::mergeSortRecursive(Node<T>* start) {
    if (!start || !start->next) {
        return start;
    }

    Node<T>* middle = start;
    Node<T>* fast = start->next;

    while (fast && fast->next) {
        middle = middle->next;
        fast = fast->next->next;
    }

    Node<T>* left = start;
    Node<T>* right = middle->next;
    middle->next = nullptr;

    left = mergeSortRecursive(left);
    right = mergeSortRecursive(right);

    return merge(left, right);
}


