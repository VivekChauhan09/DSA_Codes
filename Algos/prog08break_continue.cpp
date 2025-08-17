#include<iostream>
using namespace std;
int main()
{
    int n,i=0;
    cout<<"enter the value of n:";
    cin>>n;
    for(i=0;i<20;i++){
        if(i==n){
            continue;//use break also
        }
        else{
            cout<<i<<"  ";
        }
    }
    return 0;
}