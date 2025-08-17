#include<bits/stdc++.h>
using namespace std;

struct node * head= NULL;

struct node{
    int data;
    struct node *next;
};

void insert(int val){
    struct node *temp=(struct node *)malloc(sizeof(struct node));
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
    if(head = NULL)
        cout<<"Nothing to display  ";
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

int main(){
    int value,n;
    cout<<"Enter the number of values to insert : ";
    cin>>n;
    cout<<"Enter the values : ";
    for(int i=0;i<n;i++){
        cin>>value;
        insert(value);
    }
    display();
    return 0;
}

