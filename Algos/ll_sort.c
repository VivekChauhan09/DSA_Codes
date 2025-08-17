#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node * next;
};

void insertAtEnd(struct node** head, int val) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    struct node* ptr = *head;
    temp->data = val;
    temp->next = NULL;

    if (*head == NULL) {
        *head = temp;
        return;
    }
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }

    ptr->next = temp;
}

void sort(struct node **head){
    struct node *ptr,*cptr;
    ptr=(*head);
    while(ptr->next!=NULL){
        cptr=ptr->next;
        while(cptr!=NULL){
            if(ptr->data>cptr->data){
                int temp=ptr->data;
                ptr->data=cptr->data;
                cptr->data=temp;
            }
            cptr=cptr->next;
        }
        ptr=ptr->next;
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

int main() {
    struct node* head = NULL;
    int val,n;
    printf("Enter the number of values to insert : ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("Enter the value to insert at end: ");
        scanf("%d", &val);
        insertAtEnd(&head, val);
    }
    display(head);
    sort(&head);
    display(head);

    return 0;
}