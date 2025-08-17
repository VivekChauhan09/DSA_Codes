#include<iostream>
#define MAX 100
using namespace std;

void push(int st[],int *top,int val) {
    if(*top>=MAX-1) {
        cout<<"stack is full"<<endl;
    }
    else{
        st[++(*top)]=val;
    }
}

int pop(int st[],int *top) {
    if(*top==-1) {
        cout<<"Stack is empty"<<endl;
        return -1;
    }
    else {
        int val=st[*top];
        (*top)--;
        return val;
    }
}

void display(int st[], int top) {
    for(int i=top;i>=0;i--) {
        cout<<st[i]<<" ";
    }
}
 
int isEmpty(int top) {
    if(top==-1) {
        return 1;
    }
    else 
        return 0;
}

int main() {
    int flag=1;
    int st[MAX],top=-1;
    string exp;
    cout<<"enter the bracket expression : ";
    cin>>exp;
    char ch;
    for(int i=0;i<exp.length();i++) {
        ch= exp[i];
        if(ch=='(') {
            push(st,&top,0);
        }
        else if(ch==')') {
            if(!isEmpty(top)) {
                pop(st,&top);
            }
            else{ 
                flag=0;
                break;
            }
        }
    }
    if(!isEmpty(top)) {
        flag=0;
    }

    if(flag==0) {
        cout<<"Unbalanced!!"<<endl;
    }
    else {
    cout<<"Balanced!!"<<endl;
    }
    return 0;
}
