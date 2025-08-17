#include<iostream>
using namespace std;

void push(int st[],int *top,int val,int MAX){
    if((*top)>=MAX-1){
        cout<<"stack is full"<<endl;
    }
    else{
        st[++(*top)]=val;
    }
}

int pop(int st[],int *top){  
    int temp;
    if((*top)==-1){
        cout<<"stack is empty"<<endl;
        return -1;
    }
    else{
        temp=st[*top];
        (*top)--;
    }
    cout<<"the poped value is "<<temp<<endl;
}

void display(int st[],int *top){
    int i;
    i = *top ;
    while(i>=0){
        cout<<st[i]<<" ";
        i--;
    }
    cout<<endl;
}

int main(){
    int MAX,val,top=-1,i=0;
    cout<<"Enter the number of value you want : ";
    cin>>MAX;
    int st[MAX];
    for(i=0;i<MAX;i++){
        cout<<"Enter the value:";
        cin>>val;
        push(st,&top,val,MAX);
    }
    display(st,&top);
    pop(st,&top);
    display(st,&top);
    return 0;
}