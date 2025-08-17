#include <iostream>
#include <string>
#define MAX 100
using namespace std;

void push(int st[], int* top, int val) {
    if ((*top) >= MAX - 1)
        cout << "ERROR: stack overflow" << endl;
    else
        st[++(*top)] = val;
}

int pop(int st[], int* top) {
    int temp;
    if ((*top) == -1) {
        cout << "ERROR: stack underflow";
        return -1;
    } 
    else {
        temp = st[*top];
        (*top)--;
    }
    return temp;
}

int evaluateExp(int b1, int b2, char ch) {
    switch (ch) {
        case '+': return b1 + b2;
        case '-': return b1 - b2;
        default: return b1;
    }
}

int main() {
    int st[MAX],top=-1,num=0,n=0;
    string s = "10+20+((40-30)-80+60)+20+18......";
    int b1,r=0,b2;
    char ch;
    for (int i = 0; i <s.length(); i++){
        if( (s[i] - '0' >= 0 && s[i] - '0' <= 9) ){
            num = num * 10 + (s[i] - '0');
        }
        else if((s[i]=='+'||s[i]=='-') || s[i]=='\0'){
            push(st,&top,num);
            num=0;
            char ch=s[i];
            if(top<=1){
                if( (s[i] - '0' >= 0 && s[i] - '0' <= 9) ){
                    num = num * 10 + (s[i] - '0');
                }
                push(st,&top,num);
                num=0;
            }
            else{
                b2=pop(st, &top);
                b1=pop(st,&top);
                r = evaluateExp(b1,b2,ch);
                push(st, &top, r);
            }
        }
    }
    cout << "Result : " << r << endl;
    return 0;
}