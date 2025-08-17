#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
# define MAX 100
struct node{
    int power;
    int coff;
    struct node *next;
};
typedef struct node node;

void display(node *list3){
    node *temp = list3;
    printf("The sum is:\n");
    while(temp)
    {
        printf("%dx%d+",temp->coff,temp->power);
        temp = temp->next;
    }
}

void insertAtList1(node **list1, int coff, int power) {
    node* temp = (node*)malloc(sizeof(node));
    if (temp == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    temp->coff = coff;
    temp->power = power;
    temp->next = NULL;
    if (*list1 == NULL) {
        *list1 = temp;
    } 
    else {
        node* current = *list1;
        while (current->next != NULL) 
        {
            current = current->next;
        }
        current->next = temp;
    }
}

void insertAtList2(node **list2, int coff, int power) {
    node* temp = (node*)malloc(sizeof(node));
    if (temp == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    temp->coff = coff;
    temp->power = power;
    temp->next = NULL;
    if (*list2 == NULL) {
        *list2 = temp;
    } 
    else {
        node* current = *list2;
        while (current->next != NULL) 
        {
            current = current->next;
        }
        current->next = temp;
    }
}

node* mergeTwoLists(node* list1,node* list2)
{
    node* result = NULL;
    node *prev = NULL;
    while (list1 != NULL && list2 != NULL)
    {
        node newnode = (node)malloc(sizeof(node));
        if(prev==NULL){
            result = newnode;
        }
        else{
            prev->next = newnode;
        }
        if(list1->power == list2->power)
        {
            newnode->coff = list1->coff + list2->coff;
            newnode->power = list1->power;  
            list1 = list1->next;
            list2 = list2->next;
            newnode->next = NULL;
            prev = newnode;
        }
        else if(list1->power > list2->power){
            newnode->coff = list1->coff;
            newnode->power = list1->power;
            list1 = list1->next;
            newnode->next = NULL;
            prev = newnode;
        }
        else if(list2->power > list1->power){
            newnode->coff = list2->coff;
            newnode->power = list2->power;
            list2 = list2->next;
            newnode->next = NULL;
            prev = newnode;
        }
    }
    while(list1!=NULL)
    {
        node newnode = (node)malloc(sizeof(node));
        prev->next = newnode;
        newnode->coff = list1->coff;
        newnode->power = list1->power;
        list1 = list1->next;
        newnode->next = NULL;
        prev = newnode;
    }
    while(list2!=NULL)
    {
        node newnode = (node)malloc(sizeof(node));
        prev->next = newnode;
        newnode->coff = list2->coff;
        newnode->power = list2->power;
        list2 = list2->next;
        newnode->next = NULL;
        prev = newnode;
    }
    
    return result;
}

int main()
{
    char equation1[MAX],equation2[MAX];
    node *list1 = NULL;
    node *list2 = NULL;
    int i,coff,power;
    printf("Enter the 1st equation: ");
    scanf("%s",equation1);
    for(i = 0;equation1[i]!='\0';i++)
    {
        if(equation1[i]=='x')
        {
            if(equation1[i-1]=='+'||i == 0){
                coff = 1;
            }
            else{
                coff = equation1[i-1]-'0';
            }
            if(equation1[i+1]=='+'||equation1[i+1]=='\0'){
                power = 1;
            }
            else{
                power = equation1[i+1]-'0';
            }
            insertAtList1(&list1,coff,power);
        }
        else if(isdigit(equation1[i]) && equation1[i+1]=='\0' && equation1[i-1]=='+')
        {
            coff = equation1[i]-'0';
            power = 0;
            insertAtList1(&list1,coff,power);
        }
    }
    printf("Enter the 2nd equation: ");
    scanf("%s",equation2);
    for(i = 0;equation2[i]!='\0';i++)
    {
        if(equation2[i]=='x')
        {
            if(equation2[i-1]=='+'||i == 0){
                coff = 1;
            }
            else{
                coff = equation2[i-1]-'0';
            }
            if(equation2[i+1]=='+'||equation2[i+1]=='\0'){
                power = 1;
            }
            else{
                power = equation2[i+1]-'0';
            }
            insertAtList2(&list2,coff,power);
        }
        else if(isdigit(equation2[i]) && equation2[i+1]=='\0' && equation2[i-1]=='+')
        {
            coff = equation2[i]-'0';
            power = 0;
            insertAtList2(&list2,coff,power);
        }
    }
    node *list3 = mergeTwoLists(list1,list2);
    display(list3);
    return 0;
}