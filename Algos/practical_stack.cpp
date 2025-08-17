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
    temp->next=val;
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
    }
    printf("The list made is ");
    while(temp){
        printf("%d",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

int main(){
    int num,val,x;
    printf("Enter the number of data to input : ");
    scanf("%d",&num);
    for(int i=0 ; i<num ; i++){
        printf("Enter the element to insert : ");
        scanf("%d",&val);
        insert(val);
    }
    display();
    x=delete1();
    printf("The deleted element is ",x);
    printf("The new list is ");
    display();
    return 0;

}