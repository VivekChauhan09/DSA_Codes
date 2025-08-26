#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node * next;
};

void insertAtHead(struct node *head,int val){
    struct node * temp =(struct node *)malloc(sizeof(struct node));
    temp->data=val;
    temp->next=(head);
    (head)=temp;
}

void insertAtBtw(struct node* head, int val, int key) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = val;

    struct node* ptr = head;
    while (ptr != NULL && ptr->data != key) {
        ptr = ptr->next;
    }
    if (ptr == NULL) {
        printf("Key not found in the list\n");
        free(temp);
        return;
    }
    temp->next = ptr->next;
    ptr->next = temp;
}

void insertAtEnd(struct node* head, int val) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    struct node* ptr = head;
    temp->data = val;
    temp->next = NULL;

    if (head == NULL) {
        head = temp;
        return;
    }
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }

    ptr->next = temp;
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

void deleteFirst(struct node* head) {
    if (head == NULL) {
        printf("List is empty, nothing to delete\n");
        return;
    }
    struct node* temp = head;
    head = (head)->next;
    free(temp);
}

void deleteLast(struct node* head) {
    if (head == NULL) {
        printf("List is empty, nothing to delete\n");
        return;
    }
    if ((head)->next == NULL) {
        free(head);
        head = NULL;
        return;
    }
    struct node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

void deleteAtIndex(struct node* head, int index) {
    if (*head == NULL) {
        printf("List is empty, nothing to delete\n");
        return;
    }
    struct node* temp = head;
    if (index == 0) {
        head = temp->next;
        free(temp);
        return;
    }
    int i = 0;
    while (temp != NULL && i < index - 1) {
        temp = temp->next;
        i++;
    }
    if (temp == NULL || temp->next == NULL) {
        printf("Index out of range\n");
        return;
    }
    struc#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node * next;
};

void insertAtHead(struct node **head,int val){
    struct node * temp =(struct node *)malloc(sizeof(struct node));
    temp->data=val;
    temp->next=(*head);
    (*head)=temp;
}

void insertAtBtw(struct node* head, int val, int key) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = val;

    struct node* ptr = head;
    while (ptr != NULL && ptr->data != key) {
        ptr = ptr->next;
    }
    if (ptr == NULL) {
        printf("Key not found in the list\n");
        free(temp);
        return;
    }
    temp->next = ptr->next;
    ptr->next = temp;
}

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

void deleteFirst(struct node** head) {
    if (*head == NULL) {
        printf("List is empty, nothing to delete\n");
        return;
    }
    struct node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

void deleteLast(struct node** head) {
    if (*head == NULL) {
        printf("List is empty, nothing to delete\n");
        return;
    }
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }
    struct node* temp = *head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

void deleteAtIndex(struct node** head, int index) {
    if (*head == NULL) {
        printf("List is empty, nothing to delete\n");
        return;
    }
    struct node* temp = *head;
    if (index == 0) {
        *head = temp->next;
        free(temp);
        return;
    }
    int i = 0;
    while (temp != NULL && i < index - 1) {
        temp = temp->next;
        i++;
    }
    if (temp == NULL || temp->next == NULL) {
        printf("Index out of range\n");
        return;
    }
    struct node* nextNode = temp->next->next;
    free(temp->next);
    temp->next = nextNode;
}

int main() {
    struct node* head = NULL;
    int choice, val, key, index;

    do {
        printf("\nEnter your choice:\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert in between\n");
        printf("3. Insert at end\n");
        printf("4. Delete at first\n");
        printf("5. Delete at last\n");
        printf("6. Delete at index\n");
        printf("7. Display\n");
        printf("0. Exit\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert at beginning: ");
                scanf("%d", &val);
                insertAtHead(&head, val);
                break;
            case 2:
                printf("Enter the value to insert: ");
                scanf("%d", &val);
                printf("Enter the value after which you want to insert that value: ");
                scanf("%d", &key);
                insertAtBtw(head, val, key);
                break;
            case 3:
                printf("Enter the value to insert at end: ");
                scanf("%d", &val);
                insertAtEnd(&head, val);
                break;
            case 4:#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node * next;
};

void insertAtHead(struct node **head,int val){
    struct node * temp =(struct node *)malloc(sizeof(struct node));
    temp->data=val;
    temp->next=(*head);
    (*head)=temp;
}

void insertAtBtw(struct node* head, int val, int key) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = val;

    struct node* ptr = head;
    while (ptr != NULL && ptr->data != key) {
        ptr = ptr->next;
    }
    if (ptr == NULL) {
        printf("Key not found in the list\n");
        free(temp);
        return;
    }
    temp->next = ptr->next;
    ptr->next = temp;
}

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

void deleteFirst(struct node** head) {
    if (*head == NULL) {
        printf("List is empty, nothing to delete\n");
        return;
    }
    struct node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

void deleteLast(struct node** head) {
    if (*head == NULL) {
        printf("List is empty, nothing to delete\n");
        return;
    }
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }
    struct node* temp = *head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

void deleteAtIndex(struct node** head, int index) {
    if (*head == NULL) {
        printf("List is empty, nothing to delete\n");
        return;
    }
    struct node* temp = *head;
    if (index == 0) {
        *head = temp->next;
        free(temp);
        return;
    }
    int i = 0;
    while (temp != NULL && i < index - 1) {
        temp = temp->next;
        i++;
    }
    if (temp == NULL || temp->next == NULL) {
        printf("Index out of range\n");
        return;
    }
    struct node* nextNode = temp->next->next;
    free(temp->next);
    temp->next = nextNode;
}

int main() {
    struct node* head = NULL;
    int choice, val, key, index;

    do {
        printf("\nEnter your choice:\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert in between\n");
        printf("3. Insert at end\n");
        printf("4. Delete at first\n");
        printf("5. Delete at last\n");
        printf("6. Delete at index\n");
        printf("7. Display\n");
        printf("0. Exit\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert at beginning: ");
                scanf("%d", &val);
                insertAtHead(&head, val);
                break;
            case 2:
                printf("Enter the value to insert: ");
                scanf("%d", &val);
                printf("Enter the value after which you want to insert that value: ");
                scanf("%d", &key);
                insertAtBtw(head, val, key);
                break;
            case 3:
                printf("Enter the value to insert at end: ");
                scanf("%d", &val);
                insertAtEnd(&head, val);
                break;
            case 4:
                deleteFirst(&head);
                break;
            case 5:
                deleteLast(&head);
                break;
            case 6:
                printf("Enter the index to delete: ");
                scanf("%d", &index);
                deleteAtIndex(&head, index);
                break;
            case 7:
                display(head);
                break;
            case 0:
                printf("Program terminated.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 0);

    return 0;
}
                deleteFirst(&head);
                break;
            case 5:
                deleteLast(&head);
                break;
            case 6:
                printf("Enter the index to delete: ");
                scanf("%d", &index);
                deleteAtIndex(&head, index);
                break;
            case 7:
                display(head);
                break;
            case 0:
                printf("Program terminated.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 0);

    return 0;
}t node* nextNode = temp->next->next;
    free(temp->next);
    temp->next = nextNode;
}

int main() {
    struct node* head = NULL;
    int choice, val, key, index;

    do {
        printf("\nEnter your choice:\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert in between\n");
        printf("3. Insert at end\n");
        printf("4. Delete at first\n");
        printf("5. Delete at last\n");
        printf("6. Delete at index\n");
        printf("7. Display\n");
        printf("0. Exit\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert at beginning: ");
                scanf("%d", &val);
                insertAtHead(&head, val);
                break;
            case 2:
                printf("Enter the value to insert: ");
                scanf("%d", &val);
                printf("Enter the value after which you want to insert that value: ");
                scanf("%d", &key);
                insertAtBtw(head, val, key);
                break;
            case 3:
                printf("Enter the value to insert at end: ");
                scanf("%d", &val);
                insertAtEnd(&head, val);
                break;
            case 4:
                deleteFirst(&head);
                break;
            case 5:
                deleteLast(&head);
                break;
            case 6:
                printf("Enter the index to delete: ");
                scanf("%d", &index);
                deleteAtIndex(&head, index);
                break;
            case 7:
                display(head);
                break;
            case 0:
                printf("Program terminated.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 0);

    return 0;
}