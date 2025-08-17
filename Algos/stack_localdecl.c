#include<stdio.h>

void push(int st[],int *top,int val,int MAX){
    if((*top)>=MAX-1){
        printf("stack is full");
    }
    else{
        st[++(*top)]=val;
    }
}

int pop(int st[],int *top){  
    int temp;
    if((*top)==-1){
        printf("stack is empty");
        return -1;
    }
    else{
        temp=st[*top];
        (*top)--;
    }
    return temp;
}

void display1(){
	printf("NAME : VIVEK SINGH CHAUHAN \n");
	printf("SECTION : A2 \n");
	printf("ROLL NO : 73 \n");
    printf("\n");
}

void display(int st[],int *top){
    int i;
    i = *top ;
    printf("Stack is ");
    while(i>=0){
        printf("%d ",st[i]);
        i--;
    }
    printf("\n");
}

int main(){
    int MAX,val,top=-1,i=0;
    display1();
    printf("Enter the number of value you want : ");
    scanf("%d",&MAX);
    int st[MAX];
    printf("Enter the value : ");
    for(i=0;i<MAX;i++){
        scanf("%d",&val);
        push(st,&top,val,MAX);
    }
    display(st,&top);
    printf("The poped value is %d \n",pop(st,&top));
    display(st,&top);
    return 0;
}