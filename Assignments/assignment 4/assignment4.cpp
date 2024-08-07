#include<iostream>
using namespace std;

template<typename T>
struct Node
{
    T data;
    Node* next;
    Node* prev;
};
template<class T>
class DoublyLinkedList{
    Node<T>* head;
    Node<T>* tail;
public:
    DoublyLinkedList(Node<T>* Head=NULL,Node<T>* Tail=NULL)
    {head=Head;tail=Tail;}

    void push_back(const T val) {
    Node<T>* newNode = new Node<T>;
    newNode->data = val;
    newNode->prev = NULL;
    newNode->next = head;
    if (head == NULL) {
        tail = newNode; tail->next=NULL;
    } else {
        head->prev = newNode;
    }
    head = newNode;
    }
    void display() const{
        Node<T>* p=head;
        while(p!=NULL)
        {
            cout<<p->data<<" ";
            p=p->next;
        }
    }
    void mergeSort(){
        if(head==NULL || head->next)
    }

};
int main()
{
std::ios_base::sync_with_stdio(false);
    DoublyLinkedList<int> d;
    d.push_back(1);
    d.push_back(7);
    d.push_back(3);
    d.push_back(5);
    d.display();
    return 0;
}