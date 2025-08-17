// SINGLEY LL BY GLOBAL DECLARATION
//INSERTION AT THE BEGINNING

#include<stdio.h>
#include<stdlib.h>
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
        head->next = NULL;
    }
    else{
        temp->next=head;
        head=temp;
    }
}

void display(){
    struct node *temp=head;
    if(temp==NULL){
        printf("Nothing to display \n");
    }
    while(temp){
        printf("%d  ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

int delete1(){
    struct node *temp=head;
    if(temp==NULL){
        printf("Underflow");
        return -1;
    }
    head=head->next;
    temp->next=NULL;
    int x=temp->data;
    free(temp);
    return(x);
}

int main(){
    int n;
    printf("Enter the number of data u want : ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int val;
        printf("Enter the value : ");
        scanf("%d",&val);
        insert(val);
    }
    display();
    printf("%d \n",delete1());
    display();
    return 1;
}