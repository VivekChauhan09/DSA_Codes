#include <iostream>
using namespace std;
int insertendarray(int a[],int n,int key,int capacity)
{
    if(n>=capacity)
    {
        return n;
    }
    a[n]=key;
    return (n+1);
}
int main()
{
    int a[15]={1,2,3,4,5,6};
    int capacity=sizeof(a)/sizeof(a[0]);
    int n=6;
    int key=7;
    cout<<"Before Insertion"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<a[i];
    }
    n=insertendarray(a,n,key,capacity);
    cout<<"\nAfter Insertion"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<a[i];
    }
    return 0;
}