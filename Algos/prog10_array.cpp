#include<iostream>
using namespace std;
int main()
{
    int n,i;
    cout<<endl;
    cout<<"enter the nummer of data:";
    cin>>n;
    int marks[n];
    cout<<"enter the marks"<<endl;
    for(i=0;i<n;i++){
        cin>>marks[i];
    }
    cout<<"displaying the entered marks:";
    for(i=0;i<n;i++){
        cout<<marks[i]<<"  ";
    }
    cout<<endl;
    return 0;
}