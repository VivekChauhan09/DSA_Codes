#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node * next;
};

void Traversal(struct node * head){
    struct node * ptr=head;
    do{
        printf("Element is %d \n",ptr->data);
        ptr=ptr->next;
    }while(ptr!=head);
}

struct node * InsertAtFirst(struct node * head,int val){
    struct node * ptr =(struct node *)malloc(sizeof(struct node));
    ptr->data=val;
    struct node *p=head;
    if (head == NULL) {
        ptr->next = ptr; // Point to itself if it's the first element
    } 
    else {
        while (p->next != head) { //checking if p points the last value 
            p = p->next;
        }
        p->next = ptr;
        ptr->next = head;
    }
    head=ptr;
    return head;
}

int main(){
    struct node * head=NULL;
    int n,val;
    printf("Enter the number of values you want to enter : ");
    scanf("%d",&n);
    
    for(int i=0;i<n;i++){
        printf("Enter the value:");
        scanf("%d",&val);
        head=InsertAtFirst(head,val);
    }
    Traversal(head);
    return 0;
}