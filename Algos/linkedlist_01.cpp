#include<iostream>
using namespace std;

struct node {
    int data;
    struct node *next;
};

int main(){
    struct node *head;
    struct node *second;
    struct node *third;
    head = (struct node *)malloc(sizeof(struct node));
    second=(struct node *)malloc(sizeof(struct node));
    third =(struct node *)malloc(sizeof(struct node));

    head->data=11;
    head->next=second;

    head->data=22;
    head->next=third;

    head->data=33;
    head->next=NULL;

    return 0;
}