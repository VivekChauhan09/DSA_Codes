#include <stdio.h>
#include <stdlib.h>
#define MAX 10
struct node {
    int info;
    struct node* next;
};

typedef struct node node;

node *insert(int val,node *head) {
    node *temp;
    temp = (node*)malloc(sizeof(node));
    temp->info = val;
    
    if(head==NULL){
        head=temp;
        temp->next = NULL; 
    }
    else{
        temp->next=head;
        head=temp;  
    }
    return head;
}

void display(node *head) {
    node *temp = head;
    while (temp) {
        printf("%d ", temp->info);
        temp = temp->next;
    }
    printf("\n");
}

int delete1(node **head) {
    if ((*head) == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return -1;
    }
    node *temp = (*head);
    (*head) = (*head)->next;
    temp->next=NULL;
    int x=temp->info;
    return temp;
    free(temp);
}

int main() {
	node* head = NULL; 
    int n;
    printf("NAME : VIVEK SINGH CHAUHAN\n");
    printf("Enter 10 elements : ");
    for(int i=0;i<MAX;i++){
        scanf("%d",&n);
        head = insert(n,head);
    }
    printf("Initial list is: \n");
    display(head);

    int t= delete1(&head);
    printf("Deleted element is %d ",t);

    printf("\nAfter deleting list is : ");
    display(head);
  return 0;
}