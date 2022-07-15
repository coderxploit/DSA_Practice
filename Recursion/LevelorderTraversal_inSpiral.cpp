#include<iostream>
#include <bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;

    node(int d){
        this->data = d;
        this->left=NULL;
        this->right=NULL;
    }

};


//Inserting new node in tree
node* newnode(node* root){
    int data;
    cout<<"Enter data for node: "<<endl;
    cin>>data;
    root = new node(data);

    if(data == -1){
        return NULL;
    }

    cout<<"Enter data for inserting in left"<<data<<endl;
    root->left = newnode(root->left);
    cout<<"Enter data for inserting in right"<<data<<endl;
    root->right = newnode(root->right);
    return root;
}
/*
int height(node *root){
    if(root == NULL){
        return 0;
    }
    int left = height(root->left);
    int right = height(root->right);
    return 1+max(left,right);
}

void printcurrentLevel(node* root, int level){
    if(root == NULL){
        return;
    }
    if(level == 1){
        cout<<root->data<<endl;
    }
    else if (level > 1&& level%2 == 0) {
        printcurrentLevel(root->left, level - 1);
        printcurrentLevel(root->right, level - 1);
    }
    else if (level > 1 && level%2 != 0) {
        printcurrentLevel(root->right, level - 1);
        printcurrentLevel(root->left, level - 1);  
    }
    
}
void printLevelOrder(node* root){
    int h = height(root);
    for(int i = 1; i<=h;i++){
        printcurrentLevel(root,i);
    }
}
*/
vector<int> printLevelOrder(node *root)
{ 
  vector<int>ans;
  vector<int> rows;
  if(root == NULL) {
      return ans;
  }
  
  bool leftToRight = false;
  queue<node*>q;
  q.push(root);

  while(q.size() > 0) {
      int sizeOfQueue = q.size();
      for(int i=0; i<sizeOfQueue; i++) {
          node *temp = q.front();

         rows.push_back(temp->data);
          
          if(temp->left != NULL) {
              q.push(temp->left);
          }
          if(temp->right != NULL) {
              q.push(temp->right);
          }
          
        q.pop();
          
      }
      
      if(leftToRight==true){
         for(auto i=rows.begin(); i!=rows.end(); i++)
              ans.push_back(*i);
      }
   else{
              reverse(rows.begin(), rows.end());
              for(auto i=rows.begin(); i!=rows.end(); i++)
              ans.push_back(*i);
          }
   rows.clear();
          
   leftToRight=!leftToRight;
  }
  return ans;
  
}


int main(){
    node *root = NULL;
    root = newnode(root); //1 2 7 -1 -1 6 -1 -1 3 5 -1 -1 4 -1 -1 
    
    cout<<"Spiral level order traversal"<<endl;
    vector<int> ans = printLevelOrder(root);
    for(auto x: ans){
        cout<<x<<endl;
    }
    return 0;
}