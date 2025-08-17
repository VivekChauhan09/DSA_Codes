#include<stdio.h>
#define MAX 10
void push(int st[],int val,int *top){
    if(*top>=MAX-1){
        printf("stack is overflow");
    }
    else{
        st[++(*top)]=val;
    }
}
int pop(int st[],int *top){
    if(*top==-1){
        printf("Stack is empty");
        int temp=-1;
        return -1;
    }
    else{
        int temp=st[*top];
        (*top)--;
        return temp;
    }
}
void display(){
	printf("NAME : VIVEK SINGH CHAUHAN \n");
	printf("SECTION : A2 \n");
	printf("ROLL NO : 73 \n");
}
int main(){
    int top=-1;
    int n;
    int st[MAX];
    display();
    printf("Enter %d values : ",MAX);
    for(int i=0;i<MAX;i++) {
        scanf("%d",&n);
        push(st,n,&top);
    }
    printf("Popped values: \n");
    for(int i=0;i<MAX;i++){
        printf("%d ",pop(st,&top));
    }
}
