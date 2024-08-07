#include<iostream>
using namespace std;
struct node
{
    int data;
    node* next;
};

class linkedList{
    node* head;
public:
    linkedList(node* Head=NULL){head=Head;}
    void insertBeginning(int val){
    node* newNode= new node;
    newNode->data=val;
    node* p= head;
    newNode->next=head;
    head=newNode;
}
void traverse(){
    node* p=head;
    while(p!=NULL){
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}
void insertEnd(int val){
    node* newNode =new node;
    node* p=head;
    while(p->next!=NULL) p=p->next;
    p->next=newNode;
    newNode->data=val;
    newNode->next=NULL;
}
void sortedInsert(int val){
    node* p=head;
    node* last =head;
    while(last->next!=NULL){last=last->next;}
    if(head->data>val) 
    {insertBeginning(val);
    return;   }
    if(last->data<=val) {insertEnd(val); return;}
    int a=head->data;
    while(!((p->next->data) > val && val >= p->data)){
        p = p->next;
        a=p->data;
    }
    node* newNode= new node;
    newNode->data=val;
    newNode->next=p->next;
    p->next=newNode;
}
};
int main(){
std::ios_base::sync_with_stdio(false);
    int arr[5]={12,15,18,22,28};
    linkedList l;
    for(int i=4;i>=0;i--){
        l.insertBeginning(arr[i]);        
    }
    // for(auto i:arr){
    //     l.insertBeginning(i);
    // }
    l.sortedInsert(29);
    l.traverse();
    
    return 0;
}