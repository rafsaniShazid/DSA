#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;
    int height;
};
Node* createNode(int key){
    Node* node= new Node;
    node->data=key;
    node->left=NULL;
    node->right=NULL;
    node->height=1;
    return node;
}
int getHeight(Node* node){
    if(node==NULL) return 0;
    return node->height;
}
int getBalance(Node* node){
    if(node==NULL) return 0;
    return getHeight(node->left)-getHeight(node->right);
}

Node* leftRotate(Node* x){
    Node* y=x->right;
    Node* T2=y->left;

    y->left=x;
    x->right=T2;
    y->height= max(getHeight(y->left),getHeight(y->right))+1;
    x->height= max(getHeight(x->left),getHeight(x->right))+1;    
    return y;
}
Node* rightRotate(Node* y){
    Node* x=y->left;
    Node* T2=x->right;

    x->right=y;
    y->left=T2;
    y->height= max(getHeight(y->left),getHeight(y->right))+1;
    x->height= max(getHeight(x->left),getHeight(x->right))+1;    
    return x;
}
Node* insert(int key,Node* node){
    if (node==NULL){
        node= createNode(key);
        return node;
    }
    if(key<node->data) node->left=insert(key,node->left);
    else if(key>node->data) node->right=insert(key,node->right);
    else return node;

    node->height= max(getHeight(node->left),getHeight(node->right))+1;
    int bf= getBalance(node);
    
    if(bf>1 && key<node->left->data) return rightRotate(node);
    else if(bf<-1 && key>node->right->data) return leftRotate(node);
    else if(bf<-1 && key<node->right->data){
        node->right=rightRotate(node->right);
        return leftRotate(node);
    }
    else if(bf>1 && key>node->left->data){
        node->left=leftRotate(node->left);
        return rightRotate(node);
    }
    else return node;
}
int main()
{
    Node *root = NULL;  
      
    /* Constructing tree given in  
    the above figure */
    root = insert( 10,root);  
    root = insert( 20,root);  
    root = insert( 30,root);  
    root = insert( 40,root);  
    root = insert( 50,root);  
    root = insert( 25,root);     
    return 0;
}