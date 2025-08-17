#include<iostream>
using namespace std;

struct node{
    int info;
    struct node *next;
}

typedef struct node node;
node *head = NULL;

void insert(int v){
    node *temp;
    temp = (node *)malloc(sizeof(node));
    temp->info=v;
    if(head==NULL){
        head=temp;
        head->next=NULL;
    }
    else{
        temp->next=head;
        head=temp;
    }
}

void display(){
    node *temp=head;
    while (temp){
        cout<<temp->info;
        temp=temp->next;
    }
    cout<<endl;
}

int delete(){
    if(head==NULL)
        cout<<"underflow";
        return -1;
}
int main(){

}