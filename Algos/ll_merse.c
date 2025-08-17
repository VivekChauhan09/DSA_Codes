#include<iostream>
using namespace std;

struct node{
    int data;
    struct node * next;
};

void insert(struct node **head,int val){
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->data=val;
    temp->next=NULL;
    if((*head)==NULL){
        (*head)=temp;
        return;
    }
    else{
        struct node *ptr=(*head);
        while(ptr->next!=NULL){
            ptr=ptr->next;
        }
        ptr->next=temp;
    }
}

void display(struct node *head){
    struct node * temp=head;
    if(head==NULL){
        printf("Nothing to display");
    }
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

void merge(struct node *a,struct node *b,struct node **s){
    while(a!=NULL && b!=NULL){
        insert(s,a->data);
        a=a->next;
        insert(s,b->data);
        b=b->next;
    }
    while(a!=NULL){
        insert(s,a->data);
        a=a->next;
    }
    while(b!=NULL){
        insert(s,b->data);
        b=b->next;
    }
}


int main(){
    struct node* a = NULL;
    struct node* b = NULL;
    struct node* s = NULL;
    int val,n;

    printf("Enter the number of values to insert in a : ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("Enter the value to insert at end: ");
        scanf("%d", &val);
        insert(&a, val);
    }

    printf("Enter the number of values to insert in b : ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("Enter the value to insert at end: ");
        scanf("%d", &val);
        insert(&b, val);
    }

    display(a);
    display(b);

    merge(a,b,&s);
    display(s);
    return 0;

}