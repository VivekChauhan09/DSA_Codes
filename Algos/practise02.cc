/* WRITE A LINKED LIST PROGRAM TO ADD 2 POLYNOMIAL */

#include<iostream>
using namespace std;

struct node{
    int coeff;
    int expo;
    struct node * next ;
};

struct node *head = NULL;

void insert(int val1,int val2){
    struct node *temp;    //created a temp variable to store the new value
    temp=(struct node *)malloc(sizeof(struct node));  //memory allocated
    temp->coeff=val1;    //val1 is given
    temp->expo=val2;     //val2 is given
    temp->next=NULL;
    struct node *ptr=head;
    if(ptr==NULL){
        head=temp;
    }
    else{
        while(ptr->next!=NULL){
            ptr=ptr->next;
        }
        ptr->next=temp;
    }
}

void display(){
    struct node *temp=head;
    if(temp==NULL)
        cout<<"nothin to display "<<endl;
    while(temp){
        cout<<temp->coeff<<"x^"<<temp->expo<<"+";
        temp=temp->next;
    }
    cout<<endl;
}

int main(){
    int val1,val2;
    for(int i=0;i<n;i++){
    cout<<"enter the value of coefficient : ";
    cin>>val1;
    cout<<"enter the value of power : ";
    cin>>val2;
    insert(val1,val2);
    cout<<"enter the value of coefficient : ";
    cin>>val1;
    cout<<"enter the value of power : ";
    cin>>val2;
    insert(val1,val2);
    display();
    return 0;
}