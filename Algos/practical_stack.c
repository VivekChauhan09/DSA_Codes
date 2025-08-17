#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *head=NULL;

void insert(int val){
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->data=val;
    if(head=NULL){
        head=temp;
        head->next=NULL;
    }
    else{
        temp->next=head;
        head=temp;
    }
}

int delete1(){
    if(head==NULL){
        printf("Nothing to display !!");
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
        printf("Underflow ");
        exit(1);
    }
    printf("The list made is ");
    while(temp!=NULL){
        printf("%d",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

int main(){
    insert(10);
    display();
    insert(20);
    display();
    insert(30);
    display();
    int x=delete1();
    printf("the deleted value is %d ",x);
    return 0;
}