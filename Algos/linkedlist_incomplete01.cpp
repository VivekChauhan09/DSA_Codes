#include<iostream>
using namespace std;

struct node{
    int data;
    struct node * next ;
};

struct node *head = NULL;

void insert(int val){
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->data=val;
    if(head==NULL){
        head=temp;
        head->next=NULL;
    }
    else{
        temp->next=head;
        head=temp;
    }
}

void display(){
    struct node *temp=head;
    if(temp==NULL)
        cout<<"nothin to display "<<endl;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int delete1(){
    if(head==NULL){
        cout<<"underflow";
        return -1;
    }
    struct node *temp=head;
    head=head->next;
    temp->next=NULL;
    int x=temp->data;
    free(temp);
    return x;
}

int main(){
    int n;
    insert(10);
    display();
    insert(20);
    display();
    insert(30);
    display();
    int del;
    del=delete1();
    cout<<"The deleted value is "<<del<<endl;
    display();
    return 0;
}