#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node * next;
};

struct node * head =NULL;

void insert(int val){
    struct node * temp;
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
    struct node * temp=head;
    if(temp==NULL){
        printf("Nothing to delete");
    }
    while(temp){
        head=head->next;
        temp->next=NULL;
        int x=temp->data;
        free(temp);
        return x;
    }
}

void display(){
    struct node * temp=head;
    while(temp){
        printf("%d ",temp->data);
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
    delete1();
    display();
    return 0;

}