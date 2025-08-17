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
        
        ch1=val1[i];

        if(val1[0]=='x'){
            temp->coeff=1;
            temp->expo=0;
            i++;
        }                                   
        else if(((val1[i]-'0'>= 0 || val1[i]-'0'<= 9) && val1[i+1]=='x')){
            temp->coeff=(ch1-'0');
        }
        else if(val1[i-1]='+'){
            temp->coeff=ch1;
            temp->expo=0;
        }

        if((val1[i]-'0'>= 0 || val1[i]-'0'<= 9) && val[i-1]=='x') ){
            ch1=s[i]-'0';
            temp->expo=ch1;
        }
        elseif()
        temp->next=NULL;       
    }
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
        cout<<temp->coeff<<"x^"<<temp->expo<<" + ";
        temp=temp->next;
    }
    cout<<endl;
}

void addPolynomials(struct node* poly1, struct node* poly2) {
    while (poly1 != NULL || poly2 != NULL) {
        if (poly1 == NULL) {
            poly2 = poly2->next;
        } else if (poly2 == NULL) {
            
            poly1 = poly1->next;
        } else if (poly1->expo > poly2->expo) {
           
            poly1 = poly1->next;
        } else if (poly1->expo < poly2->expo) {
           
            poly2 = poly2->next;
        } else {
            
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }
}


int main(){
    for(int i=0;i<3;i++){
        string val1,val2;
        cout<<"enter the string 1 : ";
        cin>>val1;
        cout<<"enter the string 2 : ";
        cin>>val2;
        insert1(val1);
        insert2(val2);
    }
    display();
    return 0;
}



/*
first  take a string input
then make a head pointer
then make a temp pointer to add value
then make a ptr pointer to access the end value
then insert the values at the end
now the values are added
make a function to add the values 
make another function to insert values
*/