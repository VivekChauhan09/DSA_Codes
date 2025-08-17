#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

void insert(struct node **head,int val){
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->data=val;
    temp->next=NULL;
    struct node * ptr=(*head);
    if(*head==NULL){
        *head=temp;
        return;
    }
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    ptr->next=temp;

}

int subs(struct node *l1,struct node *l2,int n1,int n2){
    if(l1==NULL && l2==NULL)
        return 0;
    else{
        int numA=0,numB=0;
        struct node * temp=l1;
        while(temp!=NULL){
            numA=numA*10+temp->data;
            temp=temp->next;
        }

        temp=l2;
        while(temp!=NULL){
            numB=numB*10+temp->data;
            temp=temp->next;
        }
        return numA-numB;
    }

}

void display(struct node* head) {
    struct node* temp = head;
    if (temp == NULL) {
        printf("Nothing to display\n");
        return;
    }
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    struct node *l1=NULL;
    struct node *l2=NULL;
    int n1,n2,val;
    printf("Enter the number of data to insert in LL 1: ");
    scanf("%d",&n1);
    for(int i=0;i<n1;i++){
        printf("Enter the value : ");
        scanf("%d",&val);
        insert(&l1,val);
    }
    printf("Enter the number of data to insert in LL 2: ");
    scanf("%d",&n2);
    for(int i=0;i<n2;i++){
        printf("Enter the value : ");
        scanf("%d",&val);
        insert(&l2,val);
    }
    display(l1);
    display(l2);
    printf("the differefnce is %d ",subs(l1,l2,n1,n2));
    return 0;

}