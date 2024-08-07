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
    deque(Node<T>* Front=NULL,Node<T>* Head=NULL )
    {front=Front;head=Head;}
    void push_back(const T val) {
    Node<T>* newNode = new Node<T>;
    newNode->data = val;
    newNode->prev = NULL;
    newNode->next = head;
    if (head == NULL) {
        front = newNode; front->next=NULL;
    } else {
        head->prev = newNode;
    }
    head = newNode;
    }
    void display() const{
        Node<T>* p=head;
        while(p!=NULL)
        {
            cout<<p->data<<endl;
            p=p->next;
        }
    }
    void push_front(const T val){
        Node<T>* newNode = new Node<T>;
    newNode->data = val;
    newNode->next=NULL;
    if(front==NULL){head=newNode;}
    else{
        newNode->prev=front;
        front->next=newNode;
    }
    front=newNode;
    }
    void pop_front(){
        Node<T>* p= front;
        Node<T>* q= p->prev;
        delete p;
        q->next=NULL;
        front=q;       
    }
    void pop_back(){
        Node<T>* p=head->next;
        delete head;
        p->prev=NULL;
        head=p;        
    }
    bool empty() { return (head==NULL)? true:false;}
    int size() const{
        int count=0;
        Node<T>* p=head;
        while(p!=NULL)
        {   count++;
            p=p->next;
        }
        return count;
    }
    ~deque(){}
};
template<class T>
class Queue: public deque<T>{
    Node<T>* head;
    Node<T>* front;
    public:
    Queue(Node<T>* Front=NULL,Node<T>* Head=NULL )
    {front=Front;head=Head;}

    void push(const T val) {
    Node<T>* newNode = new Node<T>;
    newNode->data = val;
    newNode->prev = NULL;
    newNode->next = head;
    if (head == NULL) {
        front = newNode; front->next=NULL;
    } else {
        head->prev = newNode;
    }
    head = newNode;
    }
    void display() const{
        Node<T>* p=head;
        while(p!=NULL)
        {
            cout<<p->data<<endl;
            p=p->next;
        }
    }
    void pop(){
        Node<T>* p= front;
        Node<T>* q= p->prev;
        delete p;
        q->next=NULL;
        front=q;       
    }
    bool empty() { return (head==NULL)? true:false;}
    int size() const{
        int count=0;
        Node<T>* p=head;
        while(p!=NULL)
        {   count++;
            p=p->next;
        }
        return count;
    }
    ~Queue(){}
};

template<class T>
class Stack: public deque<T>{
    Node<T>* head;
    public:
    Stack(Node<T>* Head=NULL):head(Head){}
    void push(const T val) {
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
    void display() const{
        Node<T>* p=head;
        while(p!=NULL)
        {
            cout<<p->data<<endl;
            p=p->next;
        }
    }
    bool empty() { return (head==NULL)? true:false;}
    int size() const{
        int count=0;
        Node<T>* p=head;
        while(p!=NULL)
        {   count++;
            p=p->next;
        }
        return count;
    }
};
int main()
{
    std::ios_base::sync_with_stdio(false);
    deque<int> d;
    Queue<int> q;
    Stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.display();
    cout<<"Size: "<<s.size();
    return 0;
}