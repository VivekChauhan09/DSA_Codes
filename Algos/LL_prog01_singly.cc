#include<bits/stdc++.h>
using namespace std;

struct node{
    int info;
    struct node *next;
};

typedef struct node node;

node* Insert(node *head, int val){   // Insertion of node at beginning of LL
    node *temp;
    temp = (node*)malloc(sizeof(node));
    temp->info = val;
    if(head == NULL){
        head = temp;
        temp->next = NULL;
    }
    else{
        temp->next = head;
        head = temp;
    }  
    return head;
}

node* Delete(node* head){    // Deletion of node from the beginning of LL
    if(head == NULL){
        cout << "Nothing to delete" << endl;
    }
    else{
        node* temp = head;
        head = head->next;
        temp->next = NULL;
        int t = temp->info; 
        cout << "The deleted value is: " << t;
        free(temp);
    }
    return head;
}

void Display(node* head){
    if(head == NULL){
        cout << "Empty Linked List" << endl;
    }
    else{
        node* temp = head;
        while(temp){
            cout << temp->info << " ";
            temp = temp->next;
        }
    }
}

int main(){
    node *head = NULL;
    int choice, val;
    cout << "Press 1 for insertion" << endl;   // Sasta Interface 
    cout << "Press 2 for deletion"  << endl;
    cout << "Press 3 for display"  << endl;
    cout << "Press 0 for exit" << endl;
    cin >> choice;
    while( choice ){
        switch(choice){
            case 1: cout << "Enter value to insert: ";
                    cin >> val;
                    head = Insert(head, val);
                    break;
            case 2: head = Delete(head);
                    break;
            case 3: Display(head);
                    break;
            case 0: exit(1);
            default : cout << "\nEnter a valid choice!!!" << endl;
        }
        cout << "\nPress 1 for insertion" << endl;
        cout << "Press 2 for deletion"  << endl;
        cout << "Press 3 for display"  << endl;
        cout << "Press 0 for exit" << endl;
        cin >> choice;
    }
    return 0;
}