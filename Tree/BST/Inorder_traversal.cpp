#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;


    node(int d){
        this -> data = d;
        this -> left = NULL;
        this -> right = NULL; 
    }
};

node *buildTree(node* root){
    int data;
    cout<<"Enter data: "<<endl;
    cin>>data;
    root = new node(data);

    if(data == -1){
        return NULL; //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    }

    cout<<"Enter data for inserting in left"<<data<<endl;
    root->left = buildTree(root->left);
    cout<<"Enter data for inserting in right"<<data<<endl;
    root->right = buildTree(root->right);
    return root;
}

void levelOrderTraversal(node *root){
    queue<node*>q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node* temp = q.front();
        
        q.pop();

        if(temp==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }

        else{
        cout<<temp->data<<" ";
        if(temp ->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
    }
    }
}

int main(){
    node *root = NULL;

    root = buildTree(root);

    levelOrderTraversal(root);
    return 0;
}