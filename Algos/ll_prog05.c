#include<stdio.h>
#include<stdlib.h>
#define MAX 10
struct node {
    int info;
    struct node *next;
};

typedef struct node node;

node* insert(node **f,node **r,int v) {
    node* temp = (node*)malloc(sizeof(node));
    if(temp==NULL){
        printf("Underflow");
        return NULL;   
	}
    temp->info=v;
    temp->next=NULL;
        if(*f==NULL){
            *f=temp;
            *r=temp;
        }
        else{
            (*r)->next = temp;
            (*r)=temp;
        }
        return temp;
}

int delete1(node **f,node **r){
    if(*f==NULL){
        printf("Underflow");
        return -1;        
	}
    else if((*f)->next==NULL){
        int t=(*f)->info;
        *f=NULL;
        *r=NULL;
        return t;
    }
    else{
        int t=(*f)->info;
        node *temp=(*f)->next;
        (*f)->next=NULL;
        *f=temp;
        return t;
    }
}

void display(node **f,node **r){
    int i;
    node (*ptr)=(*f);
    while(ptr!=NULL){
        printf("%d ",ptr->info);
        ptr=ptr->next;
    }
    printf("\n");
}

 int main(){
    struct node* front=NULL,*rear=NULL;
    int n;
    printf("Enter 10 values :\n ");
    for(int i=0;i<MAX;i++){
        scanf("%d",&n);
        insert(&front,&rear,n);
    }
    printf("Content in queue is: ");
    display(&front,&rear);

    delete1(&front,&rear);
    printf("After deletion : ");
    display(&front,&rear);
    return 0;
}
