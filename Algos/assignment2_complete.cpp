#include<bits/stdc++.h>
using namespace std;

struct node{
    int coeff;
    int expo;
    struct node *next;
};

struct node *head1 = NULL;
struct node *head2 = NULL;

void insert1(string s){
    struct node *temp1 = (struct node *)malloc(sizeof(struct node));
    cout<<"string inside is "<<s;
    for(int i=0;s[i]!='\0';i++)
    {
        if(s[i]=='x')
        {
            if((s[i-1]=='+')|| i == 0){        
                temp1->coeff = 1;
                cout<<temp1->coeff;  
            }
            else{                          
                temp1->coeff = (s[i-1]-'0');
            }
            if((s[i+1]=='+')||(s[i+1]=='\0')){
                temp1->expo = 1;
            }
            else{
                temp1->expo = (s[i+1]-'0');
            }
            temp1->next = NULL;
        }
        else if(isdigit(s[i]) && (s[i+1]=='\0') && (s[i-1]=='+'))  //last integer
        {
            temp1->coeff = (s[i]-'0');
            temp1->expo = 0;

            temp1->next = NULL;
        }

        struct node *ptr = head1;
        if(head1==NULL){
            head1=temp1;
        }
        else{
            while(ptr->next!=NULL){
                ptr=ptr->next;
            }
            ptr->next=temp1;
        }
    }
}


void insert2(string s){
    struct node *temp2 = (struct node *)malloc(sizeof(struct node));
    cout<<"string inside is "<<s;
    for(int i=0;s[i]!='\0';i++)
    {
        if(s[i]=='x')
        {
            if((s[i-1]=='+')|| i == 0){        
                temp2->coeff = 1;
            }
            else{                          
                temp2->coeff = (s[i-1]-'0');
            }
            if((s[i+1]=='+')||(s[i+1]=='\0')){
                temp2->expo = 1;
            }
            else{
                temp2->expo = (s[i+1]-'0');
            }
            
        }
        else if(isdigit(s[i]) && (s[i+1]=='\0') && (s[i-1]=='+'))  //last integer
        {
            temp2->coeff = (s[i]-'0');
            temp2->expo = 0;
        }
        temp2->next = NULL;

        struct node *ptr = head2;
        if(head2==NULL){
            head2=temp2;
        }
        else{
            while(ptr->next!=NULL){
                ptr=ptr->next;
            }
            ptr->next=temp2;
        }
    }
}

void add() {
    struct node *poly1=head1;
    struct node *poly2=head2;
    while (poly1 != NULL || poly2 != NULL) {
        if (poly1 == NULL) {
            insert(&result, poly2->coeff, poly2->expo);
            poly2 = poly2->next;
        } 
        else if (poly2 == NULL) {
            insert(&result, poly1->coeff, poly1->expo);
            poly1 = poly1->next;
        } 
        else if (poly1->expo > poly2->expo) {
            insert(&result, poly1->coeff, poly1->expo);
            poly1 = poly1->next;
        } 
        else if (poly1->expo < poly2->expo) {
            insert(&result, poly2->coeff, poly2->expo);
            poly2 = poly2->next;
        } 
        else {
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

int main(){
    string str1;
    string str2;
    cout<<"enter the 1st polynomial expression : ";
    cin>>str1;
    insert1(&head1,str1);
    cout<<"enter the 2nd polynomial expression : ";
    cin>>str2;
    insert2(&head2,str2);
    add(head1,head2);
    cout<<"sum of two equTIONS IS : ";
    display(result);
    return 0;
}