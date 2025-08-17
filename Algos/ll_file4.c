#include <stdio.h>
#include <stdlib.h>
#define MAX 6
struct node {
    int info;
    struct node* next;
};
typedef struct node node;
node *head = NULL; 
void insert(int v) {
    node *temp;
    temp = (node*)malloc(sizeof(node));
    temp->info = v;
    if(head==NULL){
        head=temp;
        head->next=NULL;
    }
    else{
        temp->next = head; 
        head = temp; 
    }
}
void display() {
    node *temp = head;
    while (temp) {
        printf("%d ", temp->info);
        temp = temp->next;
    }
}
int delete1() {
    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }
    node* temp = head;
    head = head->next;
    temp->next=NULL;
    printf("Deleted item is: %d\n", temp->info);
    free(temp);
    return x;
}

int main() {
    int n;
    printf("NAME: ANSHU PANDEY\n");
    printf("Enter values in linklist : ");
    for(int i=0;i<MAX;i++){
        scanf("%d",&n);
        insert(n);
    }
    printf("LinkedList element is: "); 
    display();
    printf("\nEnter no.of elements to delete : ");
    scanf("%d",&n); 
    for(int i=0;i<n;i++){
        delete1();
    }
    printf("After deleting list is : ");    
    display();
    return 0;
}
