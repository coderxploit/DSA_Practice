#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int d){
        this->data = d;
        this->next = NULL;
    }
};


void InsertatTail(int data, Node* &head){
    Node* new_node = new Node(data);
    Node *tail = head;
    while(tail->next != NULL){
        tail = tail->next;
    }
    tail->next = new_node;
}

void printList(Node* &head){
    Node * temp = head;
    while(temp!= NULL){
        cout<<temp->data<<" ";
        temp = temp-> next;
    }
}

node* ReverseLLIterative(Node* &head){
    Node* prev = NULL;
    Node* curr = head;
    Node* forward = NULL;
    while(curr!=NULL){
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}

Node* ReversaLLRecursive(Node* head){
    // basecase
    if(head == NULL || head -> next == NULL){
        return head;
    }
    Node* revHead = ReversaLLRecursive(head->next);
    head->next->next = head;
    head->next = NULL;
    return revHead;
}

int main(){
    Node *head = new Node(0);
    InsertatTail(5, head);
    InsertatTail(7, head);
    InsertatTail(9, head);
    InsertatTail(12, head);
    InsertatTail(15, head);
    
    //Node* rev = ReverseLLIterative(head);
    Node* rev = ReversaLLRecursive(head);
    printList(rev);
}