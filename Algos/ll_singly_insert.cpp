#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

void insertAtHead(struct node ** head,int val){
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

void insertAtBtw(int val,int key){
    struct node * temp;
    struct node *ptr=head;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->data=val;
    while(ptr->data!=key){
        ptr=ptr->next;
    }
    temp->next=ptr->next;
    ptr->next=temp;
}

void insertAtEnd(int val){
    struct node * temp;
    struct node * ptr=head;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->data=val;
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    ptr->next=temp;
    temp->next=NULL;
}


void display(){
    struct node *temp = head;
    if(head==NULL){
        printf("Nothing to display");
    }
    while(temp){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

int main(){
    struct node * head=NULL;
    int val,choice,ch;
    printf("Enter your choice \n ");
    printf("1 Insert at head \n ");
    printf("2 Insert at between \n ");
    printf("3 Insert at End \n ");
    printf("4 display \n ");
    printf("0 Exit \n ");
    scanf("%d",&ch);
    while(ch)
    {
        switch(ch)
        {
            case 1:
            {
                int val;
                printf("Enter the value to insert at beginning: ");
                scanf("%d",&val);
                insertAtHead(&head,val);
                break;
            }
            case 2:{
                int val,key;
                printf("Enter the value to insert at between : ");
                scanf("%d",&val);
                printf("Enter the value after which you want to insert that value : ");
                scanf("%d",&key);
                insertAtBtw(&head,val,key);
                break;
            }
            case 3:{
                int val;
                printf("Enter the value to insert at End : ");
                scanf("%d",&val);
                insertAtEnd(&head,val);
                break;
            }
            case 4:{
                display();
                break;
            }
            case 0:{
                printf("Program terminated ");
                return 0;
            }
            default:
                printf("Invalid");
        }
        printf("Enter your choice : ");
        scanf("%d",&ch);
    }
    return 0;
}