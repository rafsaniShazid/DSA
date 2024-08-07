#include "deque.h"

template<class T>
deque<T>::deque(Node<T>* Front, Node<T>* Head)
{
    front = Front;
    head = Head;
}

template<class T>
void deque<T>::push_back(const T val)
{
    Node<T>* newNode = new Node<T>;
    newNode->data = val;
    newNode->prev = NULL;
    newNode->next = head;
    if (head == NULL) {
        front = newNode;
        front->next = NULL;
    } else {
        head->prev = newNode;
    }
    head = newNode;
}

template<class T>
void deque<T>::display() const
{
    Node<T>* p = head;
    while (p != NULL)
    {
        cout << p->data << endl;
        p = p->next;
    }
}

template<class T>
void deque<T>::push_front(const T val)
{
    Node<T>* newNode = new Node<T>;
    newNode->data = val;
    newNode->next = NULL;
    if (front == NULL) {
        head = newNode;
    } else {
        newNode->prev = front;
        front->next = newNode;
    }
    front = newNode;
}

template<class T>
void deque<T>::pop_front()
{
    Node<T>* p = front;
    Node<T>* q = p->prev;
    delete p;
    q->next = NULL;
    front = q;
}

template<class T>
void deque<T>::pop_back()
{
    Node<T>* p = head->next;
    delete head;
    p->prev = NULL;
    head = p;
}

template<class T>
bool deque<T>::empty()
{
    return (head == NULL) ? true : false;
}

template<class T>
int deque<T>::size() const
{
    int count = 0;
    Node<T>* p = head;
    while (p != NULL)
    {
        count++;
        p = p->next;
    }
    return count;
}

template<class T>
deque<T>::~deque()
{
    // Implement destructor logic if needed
}

// Implement Queue member functions
template<class T>
Queue<T>::Queue(Node<T>* Front, Node<T>* Head)
{
    front = Front;
    head = Head;
}

template<class T>
void Queue<T>::push(const T val)
{
    Node<T>* newNode = new Node<T>;
    newNode->data = val;
    newNode->prev = NULL;
    newNode->next = head;
    if (head == NULL) {
        front = newNode;
        front->next = NULL;
    } else {
        head->prev = newNode;
    }
    head = newNode;
}

template<class T>
void Queue<T>::display() const
{
    Node<T>* p = head;
    while (p != NULL)
    {
        cout << p->data << endl;
        p = p->next;
    }
}

template<class T>
void Queue<T>::pop()
{
    Node<T>* p = front;
    Node<T>* q = p->prev;
    delete p;
    q->next = NULL;
    front = q;
}

template<class T>
bool Queue<T>::empty()
{
    return (head == NULL) ? true : false;
}

template<class T>
int Queue<T>::size() const
{
    int count = 0;
    Node<T>* p = head;
    while (p != NULL)
    {
        count++;
        p = p->next;
    }
    return count;
}

template<class T>
Queue<T>::~Queue()
{
    // Implement destructor logic if needed
}

// Implement Stack member functions
template<class T>
Stack<T>::Stack(Node<T>* Head)
    : head(Head)
{
}

template<class T>
void Stack<T>::push(const T val)
{
    Node<T>* newNode = new Node<T>;
    newNode->data = val;
    newNode->prev = NULL;
    newNode->next = head;
    if (head == NULL) {
    } else {
        head->prev = newNode;
    }
    head = newNode;
}

template<class T>
void Stack<T>::display() const
{
    Node<T>* p = head;
    while (p != NULL)
    {
        cout << p->data << endl;
        p = p->next;
    }
}

template<class T>
bool Stack<T>::empty()
{
    return (head == NULL) ? true : false;
}

template<class T>
int Stack<T>::size() const
{
    int count = 0;
    Node<T>* p = head;
    while (p != NULL)
    {
        count++;
        p = p->next;
    }
    return count;
}


