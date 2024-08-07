// Creation,insertion
#include<iostream>
using namespace std;
struct Node
{
    int data;
    struct Node* next;
};
void ListTraversal(struct Node* ptr)
{
    while(ptr!=NULL){
        cout<<"Element "<<ptr->data<<endl;
        ptr=ptr->next;
    }
}
struct Node* insertBeginning(struct Node* head,int Data)
{
    struct Node* ptr= new (struct Node);
    ptr->next=head;
    ptr->data=Data;
    return ptr;
}
struct Node* insertEnd(struct Node* head,int Data){
    struct Node* ptr= new (struct Node);
    struct Node* p= head;
    while(p->next!=NULL){
        p=p->next;
    }
    ptr->next=NULL;
    p->next=ptr;
    ptr->data=Data;
    return head;
}
struct Node* insertBetween(struct Node* head,int data,int index){
    struct Node* ptr= new (struct Node);
    struct Node* p=head;
    int i=0;
    while(i!=index-1){
        i++;
        p=p->next;
    }
    ptr->next=p->next;
    p->next=ptr;
    ptr->data=data;
    return head;    
}
struct Node* insertNext
(struct Node* head,struct Node* prevNode,int data)
{
    struct Node* ptr= new(struct Node);
    ptr->data=data;
    ptr->next=prevNode->next;
    prevNode->next=ptr;
    return head;
}
int main()
{
    struct Node* head= new(struct Node);
    struct Node* second= new(struct Node);
    struct Node* third= new(struct Node);
    head->data=1;
    head->next=second;
    second->data=2;
    second->next=third;
    third->data=3;
    third->next=NULL;
    ListTraversal(head);
    head=insertNext(head,head,34);
    ListTraversal(head);
    return 0;
}