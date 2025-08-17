//STACK PROGRAM TO PUSH POP AND DISPLAY THE VALUE.(GLOBAL DECLARATION)

#include<iostream>
#define MAX 5
using namespace std;
int top=-1;

void push(int st[],int val){
    if(top>=MAX-1){
        cout<<"stack is full"<<endl;
    }
    else{
        top++;
        st[top]=val;

        //st[++top]=val; instead of writing above 2 lines we can write this also.
    }
}

int pop(int st[]){
    int temp;
    if(top==-1){
        cout<<"stack is empty"<<endl;
        return -1;
    }
    else{
        temp=st[top];
        top--;
    }
    cout<<"The poped value is "<<temp<<endl;
}

void display(int st[]){
    int i=top;
    cout<<"the stack made is ";
    while(i>=0){
        cout<<st[i]<<" ";
        i--;
    }
    cout<<endl;
}

int main(){
    int st[MAX],val,i=0;
    for(i=0;i<MAX;i++){
        cout<<"enter the value to push:";
        cin>>val;
        push(st,val);
    }
    display(st);
    pop(st);
    display(st);
    push(st,19);
    push(st,20);
    display(st);
    return 0;
}