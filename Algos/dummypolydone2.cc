#include <iostream>
#include <stdlib.h>
using namespace std;
struct node {
    int coeff;
    int expo;
    struct node* next;
};
struct node* head1 = NULL;
struct node* head2 = NULL;
struct node* result = NULL;-
void insert(struct node** head, int coeff, int expo) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->coeff = coeff;
    temp->expo = expo;
    temp->next = NULL;

    if (*head == NULL) {
        *head = temp;
    } else {
        struct node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = temp;
    }
}
void addPolynomials(struct node* poly1, struct node* poly2) {
    while (poly1 != NULL || poly2 != NULL) {
        if (poly1 == NULL) {
            insert(&result, poly2->coeff, poly2->expo);
            poly2 = poly2->next;
        } else if (poly2 == NULL) {
            insert(&result, poly1->coeff, poly1->expo);
            poly1 = poly1->next;
        } else if (poly1->expo > poly2->expo) {
            insert(&result, poly1->coeff, poly1->expo);
            poly1 = poly1->next;
        } else if (poly1->expo < poly2->expo) {
            insert(&result, poly2->coeff, poly2->expo);
            poly2 = poly2->next;
        } else {
            insert(&result, poly1->coeff + poly2->coeff, poly1->expo);
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }
}
void display(struct node* head) {
    struct node* temp = head;
    while (temp != NULL) {
        cout << temp->coeff << "x^" << temp->expo;
        if (temp->next != NULL) {
            cout << " + ";
        }
        temp = temp->next;
    }
    cout << endl;
}
int main() {
    int n1, n2;
    cout << "Enter the number of terms in the first polynomial: ";
    cin >> n1;
    cout << "Enter the terms of the first polynomial (coeff expo): ";
    for (int i = 0; i < n1; i++) {
        int coeff, expo;
        cin >> coeff >> expo;
        insert(&head1, coeff, expo);
    }
    cout << "Enter the number of terms in the second polynomial: ";
    cin >> n2;
    cout << "Enter the terms of the second polynomial (coeff expo): ";
    for (int i = 0; i < n2; i++) {
        int coeff, expo;
        cin >> coeff >> expo;
        insert(&head2, coeff, expo);
    }

    cout << "First Polynomial: ";
    display(head1);
    cout << "Second Polynomial: ";
    display(head2);

    addPolynomials(head1, head2);

    cout << "Resultant Polynomial: ";
    display(result);

    return 0;
}
