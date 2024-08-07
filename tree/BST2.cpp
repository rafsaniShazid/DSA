#include<iostream>
using namespace std;
class Node{
public:
    int data;
    Node* left;
    Node* right;
    Node(int d){
        data=d;
        left=NULL;
        right=NULL;
    }
};
Node* insert(Node* root,int d){
    if(root==NULL){
        root= new Node(d);
        return root;
    }
    if(d<root->data){
        root->left=insert(root->left,d);
    }
    if(d>root->data){
        root->right=insert(root->right,d);
    }
    return root;
}
void inorder(Node* root){
    if(root==NULL) return;
    else{
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}
void preorder(Node* root){
    if(root==NULL) return;
    else{
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(Node* root){
    if(root==NULL) return;
    else{
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
    }
}
Node* minValueNode(Node* root){
    Node* current =root;
    while(current && current->left==NULL){
        current=current->left;
    }
    return current;
}
Node* deleteNode(Node* root,int key){
    if(root==NULL) return root;
    if(key<root->data){
        root->left=deleteNode(root->left,key);
    }
    else if(key>root->data){
        root->right=deleteNode(root->right,key);
    }
    else{
        if(root->left==NULL){
            Node* temp=root->right;
            delete root;
            return temp;
        }      
        else if(root->right==NULL){
            Node* temp= root->left;
            delete root;
            return temp;
        }
        Node* temp=minValueNode(root->right);
        root->data=temp->data;
        root->right=deleteNode(root->right,temp->data);
        return root;
    }
}
int main(){
std::ios_base::sync_with_stdio(false);
    Node* root=NULL;
    root=insert(root,25);
    insert(root,15);
    insert(root,13);
    insert(root,24);
    insert(root,89);
    cout<<"\nPrinting inorder\n";
    inorder(root);
    cout<<"\nPrinting preorder\n";
    preorder(root);
    cout<<"\nPrinting postorder\n";
    postorder(root);
    cout<<"\nAfter deletion\n";
    root=deleteNode(root,13);   
    root=deleteNode(root,15);   
    inorder(root);
    return 0;
}