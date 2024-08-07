#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* prev;
    Node* next;
};
void traverse(Node* head)
{
    Node* p=head;
    while(p!=NULL)
    {
        cout<<"Element "<<p->data<<endl;
        p=p->next;
    }
}
Node* insertFront(int val,Node* head){
    Node* p=new Node;
    p->data=val;
    p->next=head;
    p->prev=NULL;
    if(head!=NULL) head->prev=p;
    head=p;
    return head;
}
int main()
{
    // Node* n1= new Node;
    // Node* n2= new Node;
    // Node* n3= new Node;
    // n1->data=1;
    // n2->data=2;
    // n3->data=3;
    // n1->prev=NULL;
    // n1->next=n2;
    // n2->prev=n1;
    // n2->next=n3;
    // n3->prev=n2;
    // n3->next=NULL;
    int arr[5]={1,2,3,4,5};
    Node* head=NULL;
    for(int i=4;i>=0;i--){
        head=insertFront(arr[i],head);
    }
    traverse(head);
    return 0;
}