#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node*next;
};

struct node *head=NULL;

void create(){
  struct node *newnode , *temp;
  newnode=(struct node*)malloc(sizeof(struct node));
  newnode->next=NULL;
  printf("enter the element:");
  scanf("%d",&newnode->data);
  if(head==NULL){
    head=newnode;
    temp=newnode;
  }
  else{
    temp->next=newnode;
    newnode->next=head;
  }
}
void display(){
    struct node *ptr,*temp;
    ptr=head;
    do{
        ptr=ptr->next;
    }
    while(ptr->next!=head);
    printf("%d",ptr->data);
    temp=head;
    // printf("%d",ptr->data);
    // ptr=ptr->next;
    do{
        printf("%d",temp->data);
        temp=temp->next;
    }
    while(temp!=ptr);
}
int main(){
    create();
    create();
    create();
    create();
    create();
    display();
}