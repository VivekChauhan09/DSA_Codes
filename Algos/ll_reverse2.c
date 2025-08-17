#include<bits/stdc++.h>
using namespace std;

typedef struct node{
    int info;
    struct node *next;
}Node;

void insert(Node **head, int val){
    Node temp = (Node)malloc(sizeof(Node));
    temp->info = val;
    temp->next = NULL;
    if((*head)==NULL){
        (*head) = temp;
    }
    else{
        Node *t = (*head);
        while(t->next!=NULL){
            t = t->next;
        }
        t->next = temp;
    }
}

Node Reverse(Node head){
    Node *prenode = NULL;
    Node *curnode = head;
    Node *nextnode = NULL;
    while(curnode!=NULL){
        nextnode = curnode->next;
        curnode->next = prenode;

        prenode = curnode;
        curnode = nextnode;
    }
    return prenode;
}

void display(Node* head){
    Node *temp = head;
    while(temp!=NULL){
        cout << temp->info << " ->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main(){
    Node *head = NULL;
    insert(&head, 10);
    insert(&head, 20);
    insert(&head, 30);
    insert(&head, 40);
    insert(&head, 50);
    cout << "Initial Linked list: ";
    display(head);
    head = Reverse(head);
    cout << "Reversed Linked list: ";
    display(head);
    return 0;
}