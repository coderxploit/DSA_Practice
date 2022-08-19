#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

void InsertatHead(int data, Node* &head){
    Node* new_node = new Node(data);
    new_node -> next = head;
    head = new_node;
}

void InsertatTail(int data, Node* &head){
    Node* new_node = new Node(data);
    Node *tail = head;
    while(tail->next != NULL){
        tail = tail->next;
    }
    tail->next = new_node;
}

void InsertatPosition(int data, int position, Node* &head){
    if(position == 1){
        InsertatHead(data, head);
        return;
    }
    Node* new_node = new Node(data);
    int count = 1;
    Node* temp = head;
    while(count < position-1){
        temp = temp->next;
        count++;
    }
    if(temp->next == NULL){
        InsertatTail(data, head);
        return;
    }
    new_node->next= temp->next;
    temp->next = new_node;

}

void DeleteNode(int position, Node* head){
    int count = 1;
    Node* curr = head;
    if(position == 1){
        head = head->next;
        delete(curr);
        return;
    }
    Node* prev = NULL;
    while(count<=position-1){
        prev = curr;
        curr = curr->next;
        count++;
    }
    prev->next = curr->next;
    delete(curr);

    
}

void printList(Node* &head){
    Node * temp = head;
    while(temp!= NULL){
        cout<<temp->data<<" ";
        temp = temp-> next;
    }
}

int main(){
    Node *head = new Node(5);
    InsertatHead(10, head);
    InsertatTail(0, head);
    InsertatPosition(2, 4, head);
    InsertatPosition(1, 5 , head);
    printList(head);
    DeleteNode(2, head);
    cout<<"\n";
    printList(head);
    DeleteNode(1, head);
    cout<<"\n";
    printList(head);
}