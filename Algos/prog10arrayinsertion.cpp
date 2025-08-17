#include<iostream>
using namespace std;
int main(){
    int n=0,i=0,j=0;
    cout<<"enter the number of elements : ";
    cin>>n;
    int arr[n+1];
    cout<<"enter the elements : ";
    for(i=0;i<n;i++){
        cin>>arr[i];
    }
    int key,index;
    cout<<"enter the element to insert : ";
    cin>>key;
    cout<<"enter the index where u want to enter the element : ";
    cin>>index;
    for(i=n-1;i>=index;i--){ 
        arr[i+1]=arr[i];
    }
    arr[index]=key;
    for(i=0;i<n+1;i++){
        cout<<arr[i]<<"  ";   
    }    
    return 0;
}