#include<iostream>
#define MAX 10
#include<string>
using namespace std;

void push(int st[], int *top, int val){
    if((*top)>=MAX-1){
        cout<<"ERROR:stack overflow"<<endl;
    }
    else{
        (*top)++;
        st[(*top)]=val;
    }
}

int pop(int st[],int *top){
    int temp;
    if((*top)==-1){
        cout<<"ERROR:stack underflow"<<endl;
        return -1;
    }
    else{
        temp=st[*top];
        (*top)--;
        return temp;
    }
}

void display(int st[],int top){
    int i;
    for (i=top;i>=0;i++){
        cout<<st[i]<<" ";
    }
}

int isEmpty(int top){
    if(top==-1)
        return 1;
    else
        return 0;
}

int main(){
    int st[MAX],top=-1,val,i=0;
    string s;
    cout<<"enter the string expression : ";
    cin>>s;
    char ch;
    for(i=0;s[i]!='\0';i++) {
        if(s[i]=='(') {
            push(st,&top,0);
        }
        else if(s[i]==')') {
            if(isEmpty(top)){
                cout<<"unbalanced"<<endl;
                return 0;
            }
            pop(st,&top);
        }
    }
    if(isEmpty(top)){
        cout<<"balanced"<<endl;
        return 1;
    }
    else{
        cout<<"unbalanced"<<endl;
        return 0;
    }
    display(st,top);
}