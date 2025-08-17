#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node *next;
};

struct node *head=NULL;

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

int delete1(){
    if (head==NULL){
        cout<<"underflow"<<endl;
        exit(1);
    }
    struct node *temp=head;
    head=head->next;
    temp->next=NULL;
    int x=temp->data;
    free(temp);
    return x;
}

void display(){
    struct node *temp=head;
    if(temp==NULL){
        cout<<"nothin to display"<<endl;
        exit(1);
    }
    while(temp){
        cout<<temp->data<<"  ";
        temp=temp->next;
    }
    cout<<endl;
}

int main(){
    int n,val;
    printf("enter the number : ");
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        printf("enter the element : ");
        scanf("%d",&val);
    }
    display();
    int x;
    cout<<"the deleted element is "<<x<<endl;
    display();
    return 0;
}