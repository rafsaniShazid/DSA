#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node* next;
};
Node* insertBeginning(Node* head,int Data)
{
    Node* newNode= new Node;
    newNode->data=Data;
    newNode->next=head;
    head=newNode;
    return head;
}
void ListTraverse(Node* head){
    Node* p=head;
    while(p!=NULL){
        cout<<p->data<<endl;
        p=p->next;
    }
    cout<<"\n";
}
Node* sumList(Node* head1,Node* head2)
{
    Node* newList=NULL;

    int c=0;
    for(int i=3;i>=0;i--)
    {
        Node* p1=head1;
        Node* p2=head2;
        for(int j=0;j<i;j++)
        {
            p1=p1->next;
            p2=p2->next;
        }
        int a=p1->data+p2->data+c;
        if(a<10) {newList=insertBeginning(newList,a); c=0;}
        else{
            newList=insertBeginning(newList,(a-10));c=1;
        } 
    }
    if(c>0) newList=insertBeginning(newList,c);
    return newList;
}
int main()
{
    Node* head1=NULL;
    Node* head2=NULL;
    int arr1[4]={6,2,7,1};
    int arr2[4]={7,3,5,4};
    for(int i=3;i>=0;i--)
    {
        head1=insertBeginning(head1,arr1[i]);
        head2=insertBeginning(head2,arr2[i]);
    }
    ListTraverse(head1);
    ListTraverse(head2);
    Node* list=sumList(head1,head2);
    ListTraverse(list);
    return 0;
}