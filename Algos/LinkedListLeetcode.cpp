#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node* insertAtHead(struct node *head, int val) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = val;
    temp->next = head;
    return temp;  // return new head
}

struct node* insertAtBtw(struct node* head, int val, int key) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = val;

    struct node* ptr = head;
    while (ptr != NULL && ptr->data != key) {
        ptr = ptr->next;
    }
    if (ptr == NULL) {
        printf("Key not found in the list\n");
        free(temp);
        return head;  // no change
    }
    temp->next = ptr->next;
    ptr->next = temp;
    return head;
}

struct node* insertAtEnd(struct node* head, int val) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = val;
    temp->next = NULL;

    if (head == NULL) {
        return temp;
    }
    struct node* ptr = head;z
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }
    ptr->next = temp;
    return head;
}

void display(struct node* head) {
    if (head == NULL) {
        printf("Nothing to display\n");
        return;
    }
    struct node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

struct node* deleteFirst(struct node* head) {
    if (head == NULL) {
        printf("List is empty, nothing to delete\n");
        return NULL;
    }
    struct node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

struct node* deleteLast(struct node* head) {
    if (head == NULL) {
        printf("List is empty, nothing to delete\n");
        return NULL;
    }
    if (head->next == NULL) {
        free(head);
        return NULL;
    }
    struct node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    return head;
}

struct node* deleteAtIndex(struct node* head, int index) {
    if (head == NULL) {
        printf("List is empty, nothing to delete\n");
        return NULL;
    }
    if (index == 0) {
        struct node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    struct node* temp = head;
    int i = 0;
    while (temp != NULL && i < index - 1) {
        temp = temp->next;
        i++;
    }
    if (temp == NULL || temp->next == NULL) {
        printf("Index out of range\n");
        return head;
    }
    struct node* nextNode = temp->next->next;
    free(temp->next);
    temp->next = nextNode;
    return head;
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
                head = insertAtHead(head, val);
                break;
            case 2:
                printf("Enter the value to insert: ");
                scanf("%d", &val);
                printf("Enter the value after which you want to insert that value: ");
                scanf("%d", &key);
                head = insertAtBtw(head, val, key);
                break;
            case 3:
                printf("Enter the value to insert at end: ");
                scanf("%d", &val);
                head = insertAtEnd(head, val);
                break;
            case 4:
                head = deleteFirst(head);
                break;
            case 5:
                head = deleteLast(head);
                break;
            case 6:
                printf("Enter the index to delete: ");
                scanf("%d", &index);
                head = deleteAtIndex(head, index);
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




// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr != nullptr) {
            ListNode* next = curr->next; // save next
            curr->next = prev;           // reverse link
            prev = curr;                 // move prev ahead
            curr = next;                 // move curr ahead
        }

        return prev; // new head
    }
};


//Using recursion
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // Base case: if head is NULL or only one node
        if (head == nullptr || head->next == nullptr) 
            return head;

        // Reverse the rest of the list
        ListNode* newHead = reverseList(head->next);

        // Put current node at the end
        head->next->next = head;
        head->next = nullptr;

        return newHead;
    }
};



//                                  Leetcode 160
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *l1 = headA;
        ListNode *l2 = headB;
        while(l1!=l2){
            if(l1){
                l1=l1->next;
            }
            else
                l1=headB;
            
            if(l2){
                l2=l2->next;
            }
            else
                l2=headA;
        }
        return l1;
    }
};