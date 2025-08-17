#include <iostream>
#define MAX 10000000
#include <string>
using namespace std;

void push(int st[],int *top,int val) {
    if(*top>=MAX-1) {
        cout<<"ERROR:stack is full"<<endl;
    }
    else{
        st[++(*top)]=val;
    }
}

int pop(int st[],int *top) {
    if(*top==-1) {
        cout<<"Error:Stack is empty"<<endl;
        return -1;
    }
    else {
        int temp=st[*top];
        (*top)--;
        return temp;
    }
}

int main() {
    int st[MAX],top=-1,res=0;
    string s ;
    cout << "enter the expression to calculate : ";
    cin >> s;
    char ch;
    int num = 0;

    for (int i=0;i<s.length();i++) {
        push(st,&top,s[i])
        if (isdigit(ch)) {

            num = num * 10 + (ch - '0');
        } 
        else if (ch == '+') {
            res = res + num;
            num = 0;
        }
        else if (ch == '-') {
            res = res - num;
            num = 0;
        }
    }
    cout << "Total : " << res << endl;
    return 0;
}
