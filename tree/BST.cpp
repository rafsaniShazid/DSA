
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Node
{
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
class traversal {
public:
    Node* node;
    traversal(Node* root = nullptr) : node(root) {}
void inOrder(Node* root){
    if(root==NULL) return;
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}
    void levelOrder(Node* root)
    {
      queue<Node*>q;
      q.push(root);
      vector<vector<int>>ans;
      vector<int> res;
      while(!q.empty()){
        int size=q.size();
        vector<int>level;
        for(int i=0;i<size;i++)
        {
            Node* node=q.front();
            q.pop();
            if(node->left!=NULL) q.push(node->left);
            if(node->right!=NULL) q.push(node->right);
            level.push_back(node->data);
        }
        // main answer
        ans.push_back(level);
      }
        for(auto it1:ans){
            for(auto it2:it1){
                cout<<it2<<" ";
            }
            cout<<endl;
        }
    }
};


Node* deleteNode(Node* root, int k)
{
    // Base case
    if (root == NULL)
        return root;
 
    // Recursive calls for ancestors of
    // node to be deleted
    if (root->data > k) {
        root->left = deleteNode(root->left, k);
        return root;
    }
    else if (root->data < k) {
        root->right = deleteNode(root->right, k);
        return root;
    }
 
    // We reach here when root is the node
    // to be deleted.
 
    // If one of the children is empty
    if (root->left == NULL) {
        Node* temp = root->right;
        delete root;
        return temp;
    }
    else if (root->right == NULL) {
        Node* temp = root->left;
        delete root;
        return temp;
    }
 
    // If both children exist
    else {
 
        Node* succParent = root;
 
        // Find successor
        Node* succ = root->right;
        while (succ->left != NULL) {
            succParent = succ;
            succ = succ->left;
        }
 
        // Delete successor.  Since successor
        // is always left child of its parent
        // we can safely make successor's right
        // right child as left of its parent.
        // If there is no succ, then assign
        // succ->right to succParent->right
        if (succParent != root)
            succParent->left = succ->right;
        else
            succParent->right = succ->right;
 
        // Copy Successor Data to root
        root->data = succ->data;
 
        // Delete Successor and return root
        delete succ;
        return root;
    }
}
Node* insertBST(Node* root,int d)
{
    if(root==NULL){
        root= new Node(d);
        return root;
    }
    if(d>root->data){
        root->right=insertBST(root->right,d);
    }
    else{
        root->left=insertBST(root->left,d);
    }
    return root;
}
Node* search(Node* root,int key){
    if(root==NULL || root->data==key) return root;
    if(root->data>key) return search(root->left,key);
    if(root->data<key) return search(root->right,key);
}
int main(){
std::ios_base::sync_with_stdio(false);
Node* root=NULL;
 root = insertBST(root, 50);
    root = insertBST(root, 30);
    root = insertBST(root, 20);
    root = insertBST(root, 40);
    root = insertBST(root, 70);
    root = insertBST(root, 60);
    traversal t(root);
    t.levelOrder(root);
    root=deleteNode(root,70);
    t.levelOrder(root);

    
    return 0;
}