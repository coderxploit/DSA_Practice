/*
# Level Order Traversal  

# Inorder Traversal -- LNR

# PreOrder Traversal -- NLR

# PostOrder Traversal -- LRN


*/

#include<iostream>
#include<queue>
using namespace std;

class Node{
    public:  
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;    
    }
};

Node* buildTree(Node* root){
    //cout<<"Enter data for Node: "<<endl;
    int data;
    cin>>data;
    root = new Node(data);

    if(data == -1){
        return NULL;
    }

    //Build Left and right subtrees 

   // cout<<"Enter data to put in left of "<<data<<endl;
    root->left = buildTree(root->left);
   // cout<<"Enter data to put in right of "<<data<<endl;
    root->right = buildTree(root->right);
    return root; 
} 


void levelOrderTraversal(Node* root){
    if(!root) 
        return;
            
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    
    while(!q.empty()) {
        
        Node* t = q.front();
        q.pop();
        if (t==NULL) {
            
            cout<<endl;
            if (q.size() > 0) {
                q.push(NULL);
            }
        } 
        else{
            
            cout<<t->data<<" ";
            if (t->left) q.push(t->left);
            if (t->right) q.push(t->right);
        }
    }    
}

void InOrder(Node* root){
    //base case
    if(root == NULL){
        return;
    }
    InOrder(root->left);
    cout<<root->data<<" ";
    InOrder(root->right);
} 

void PreOrder(Node* root){
    // base case
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    PreOrder(root->left);
    PreOrder(root->right);
}

void PostOrder(Node* root){
    // base case
    if(root == NULL){
        return;
    }
    
    PostOrder(root->left);
    PostOrder(root->right);
    cout<<root->data<<" ";
}


int main(){
    Node* root = NULL;

    //buildTree
    root = buildTree(root);
// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    levelOrderTraversal(root);

    cout<<"Inorder Traversal: "<<endl;
    InOrder(root);
    cout<<endl;
    cout<<"Preorder Traversal: "<<endl;
    PreOrder(root);
    cout<<endl;
    cout<<"Postorder Traversal: "<<endl;
    PostOrder(root);
    cout<<endl;
}