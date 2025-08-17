#include<iostream>
using namespace std;

int sum(int,int);
void g(void);  // void g() can also be used.

int main()
{
    int num1,num2;
    cout<<"enter first number : ";
    cin>>num1;
    cout<<"enter second number : ";
    cin>>num2;
    g();
    cout<<"the sum is "<<sum(num1,num2); 
    return 0;
}

int sum(int a,int b){
    int c=a+b;
    return c;
}

void g(){
    cout<<"hello\n";
}