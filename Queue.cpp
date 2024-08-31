// This queue is implemented with linked list

#include<iostream>
typedef long long ll;
#define forr(i, j, k) for(ll i = j; i < k; i++)
using namespace std;
class Node
{
public:
    int data;
    Node* next;
    Node (int val){
        this->data=val;
        this->next=nullptr;
    }
};
class queue{
    Node* Front,*rear;
public:
    queue():Front(NULL),rear(NULL){}
    bool empty(){
        if(rear==nullptr){
            return true;
        }
        else return false;
    }
    void push(int val){
        Node* new_node= new Node(val);
        if(this->empty()){
            Front=rear=new_node;
        }
        else{
            rear->next=new_node;
            rear=new_node;
        }
    }
    void pop(){
        if(this->empty()){
            cout<<"Queue Underflow\n"; return;
        }
        Node* temp= Front;
        Front=Front->next;
        if(Front==NULL) rear=NULL;
        delete temp;   
    }
    void traverse(){
        Node* q=Front;
        while(q!=NULL){
            cout<<q->data<<"\n";
            q=q->next;
        }
    }
    int front(){
        if(Front==NULL) {
            cout<<"Queue is Empty\n";
            return -1;
        }
        return Front->data;
    }
    int back(){
        if(rear==NULL){
            cout<<"Queue is Empty\n";
            return -1;
        }
        return rear->data;
    }
};
// this queue supports push,pop,front,back and empty funtion

int main(){

    return 0;
}
