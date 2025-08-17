#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node * next;
};

void insertAthead(struct node * head,int val){
    struct node * temp;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->data=val;
    if(head==NULL){
        head=temp;
        temp->next=NULL;
    }
    else{
        temp->next=head;
        head=temp;
    }
}

void display(struct node * head){
    struct node * temp=head;
    if(temp==NULL){
        printf("Nothing to display ");
    }
    while(temp){
        printf("%d ",temp->next);
        temp=temp->next;
    }
    printf("\n");
}

int deleteAthead(struct node * head){
    struct node *temp=head;
    if(temp==NULL){
        printf("underflow");
    }
    head=head->next;
    temp->next=NULL;
    int x=temp;
    free(temp);
    return x;
}

int main(){
    struct node * head;
    insertAthead(node * head ,10);
    display(node * head);
    insertAthead(node * head ,20);
    display(struct node * head);
    insertAthead(struct node * head ,30);
    display(struct node * head);
    insertAthead(struct node * head ,40);
    display(struct node * head);
    insertAthead(struct node * head ,50);
    display(struct node * head);
    deleteAthead(struct node * head);
    display(struct node * head);
    return 0;
}