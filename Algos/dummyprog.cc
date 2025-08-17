/* WRITE A LINKED LIST PROGRAM TO ADD 2 POLYNOMIAL */

#include<bits/stdc++.h>
using namespace std;

struct node{
    int coeff;
    int expo;
    struct node * next ;
};

struct node *head = NULL;

void insert1(string val1){
    char ch1;
    int num;
    struct node *temp;                                 //created a temp variable to store the new value
    temp=(struct node *)malloc(sizeof(struct node));  //memory allocated
    for(int i=0;i<val1.length();i++){     
        
        if(((val1[i]-'0'>= 0 || val1[i]-'0'<= 9) && val1[i+1]=='x')){
            temp->coeff=(val1[i]-'0');
            cout<<temp->coeff<<endl;
            i+=2;
        }
        if((val1[i]-'0'>= 0 || val1[i]-'0'<= 9) && val1[i-1]=='x'){
            temp->expo=(val1[i]-'0');
            cout<<temp->expo<<endl;
            i+=1;
        }
        temp->next=NULL; 
        struct node *ptr = head;
        if(ptr==NULL){
            cout<<"ptr is null "<<endl;
            head=temp;
        }   
        else{
            cout<<"inserting value ptr not null"<<endl;
            while(ptr->next!=NULL){
                ptr=ptr->next;
            }
            ptr->next=temp;
        }   
    }
}

void display(){
    struct node *temp=head;
    if(temp==NULL)
        cout<<"nothin to display "<<endl;
    while(temp){
        cout<<temp->coeff<<"x^"<<temp->expo<<" + ";
        temp=temp->next;
    }
    cout<<endl;
}

int main(){
    string val1,val2;
    cout<<"enter the string 1 : ";
    cin>>val1;
    insert1(val1);
    display();
    return 0;
}