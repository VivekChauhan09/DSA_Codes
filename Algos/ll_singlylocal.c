// SINGLEY LL BY LOCAL DECLARATION
//INSERTION AT THE BEGINNING
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

void insert(int val,struct node **head){
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->data=val;
    if(temp==NULL){
        *head=temp;
        (*head)->next=NULL;
    }
    else{
        temp->next=*head;
        *head=temp;
    }
}

void display(struct node **head){
    struct node *temp=*head;
    if(temp==NULL){
        printf("Nothing to display");
    }
    while(temp){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

int delete1(struct node **head){
    struct node *temp=*head;
    if(temp==NULL){
        printf("Underflow");
        return -1;
    }
    else{
        *head=(*head)->next;
        temp->next=NULL;
        int  x=temp->data;
        free(temp);
        return x;
    }
}

int main(){
    struct node *head=NULL;
    int n;
    printf("Enter the number of data : ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int val;
        printf("Enter the value : ");
        scanf("%d",&val);
        insert(val,&head);
        display(&head);
    }
    display(&head);
    printf("The deleted value is %d \n",delete1(&head));
    display(&head);
    return 0;
}