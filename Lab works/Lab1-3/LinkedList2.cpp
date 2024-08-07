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
struct Node* deleteBeginning(struct Node* head)
{
    struct Node* ptr=head;
    head=ptr->next;
    free(ptr);
    return head;
}
struct Node* deleteBetween(struct Node* head,int index)
{
    struct Node* p=head;
    int i=0;
    while(i<index-1){
        p=p->next;i++;
    }
    struct Node* q=p->next;
    p->next=q->next;
    free(q);
    return head;
}
struct Node* deleteEnd(struct Node* head)
{
    struct Node* p=head;
    struct Node* q=head->next;
    while(q->next!=NULL){
        p=p->next;
        q=q->next;
    } 
    p->next=NULL;
    free(q);
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
    head=deleteEnd(head);
    ListTraversal(head);
    return 0; 
}