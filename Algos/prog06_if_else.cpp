#include<iostream>
using namespace std;
int main()
{
    cout<<endl;
    int age;
    cout<<endl<<"enter your age:";
    cin>>age;
    if(age<18){
        cout<<"you are a minor"<<endl;
    }
    else if(age>=18){
        cout<<"you cum to the party"<<endl;
    }
    else{
        cout<<"warong yinput";
    }
    return 0;
}
